#include <strings.h>
#include "log_consumer.h"

void consume(const char * input) {
  
}

char * format_input(const char * input) {
  char prefix = "Hello ";
  const size_t result_size = 1 + strlen(prefix) + strlen(input);

  // Initialize the result char array on the heap
  char * result[result_size];
  result[0] = '\0';
  strncat(result, prefix, result_size);

  // Perform the result logic
  strncat(result, input, result_size);

  return result;
}
