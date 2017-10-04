#include <Python.h>
#include <strings.h>
#include <stdio.h>
// #include "log_consumer.h"

/**
	log_consumer.c
**/
#define FORMAT_PREFIX "Bellowa "
char * format_input(const char * input) {

	// Get the size of the resulting formatted output
  const size_t result_size = 1 + strlen(FORMAT_PREFIX) + strlen(input);

  // Initialize the result char array on the heap
	// TODO - Memory fragmentation will occur. Use memory pools.
  char * result = malloc(result_size * sizeof(char));
  result[0] = '\0';
  strncat(result, FORMAT_PREFIX, result_size);

  //Perform the result logic
  strncat(result, input, result_size);

  return result;
}

int push(const char * input) {
	// TODO - This method must populate a buffer that consumers can consume from.
	// This will require usage of a semaphore to ensure only a limited number
	// of consumers can access the buffer at a time

	// Get the formatted input
	char * formatted_result = format_input(input);

	// Perform action
	printf("Logging input: %s\n", formatted_result);

	// Clean up
	// TODO - Memory fragmentation will occur. Use memory pools.
	free(formatted_result);

	return 0;
}


/**
	log_consumer_module.c
**/
static PyObject * handle_push(PyObject *self, PyObject *args) {
	const char * input;
	// Capture the input
	if(!PyArg_ParseTuple(args, "s", &input)) {
		return NULL;
	}

	int result = push(input);
	return Py_BuildValue("i", result);
}

static PyMethodDef LogConsumerMethods[] = {
	// ... add more here if needed
	{"push", handle_push, METH_VARARGS, "Push a message."},
	{NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC initlog_consumer(void) {
	(void) Py_InitModule("log_consumer", LogConsumerMethods);
}

int main(int argc, char *argv[]) {
	/* Pass argv[0] to the Python interpreter */
	Py_SetProgramName(argv[0]);

	/* Initialize the Python interpreter.  Required. */
  Py_Initialize();

	/* Add a static module */
	initlog_consumer();
}
