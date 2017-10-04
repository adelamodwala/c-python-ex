#include <Python.h>
#include <strings.h>

static PyObject * spam_system(PyObject *self, PyObject *args) {
	const char *command;
	int sts;

	if(!PyArg_ParseTuple(args, "s", &command)) {
		return NULL;
	}
	sts = system(command);
	return Py_BuildValue("i", sts);
}

static PyObject * spam_length(PyObject *self, PyObject *args) {
	const char *command;
	size_t result;

	if(!PyArg_ParseTuple(args, "s", &command)) {
		return NULL;
	}
	result = strlen(command);
	return Py_BuildValue("i", result);
}

static PyObject * spam_hello(PyObject *self, PyObject *args) {
	const char * input;
	// Capture the input
	if(!PyArg_ParseTuple(args, "s", &input)) {
		return NULL;
	}

	// Set up the result string
	const size_t result_size = 7 + strlen(input);
	char result[result_size];
	result[0] = '\0';
	strncat(result, "Hello ", result_size);

	// Perform the result logic
	strncat(result, input, result_size);
	return Py_BuildValue("s", result);
}

static PyMethodDef SpamMethods[] = {
	// ... add more here if needed
	{"system", spam_system, METH_VARARGS, "Execute a shell command."},
	{"length", spam_length, METH_VARARGS, "Give length."},
	{"hello", spam_hello, METH_VARARGS, "Say hello."},
	{NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC initspam(void) {
	(void) Py_InitModule("spam", SpamMethods);
}

int main(int argc, char *argv[]) {
	/* Pass argv[0] to the Python interpreter */
	Py_SetProgramName(argv[0]);

	/* Initialize the Python interpreter.  Required. */
  Py_Initialize();

	/* Add a static module */
	initspam();
}
