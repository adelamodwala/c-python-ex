// #include <strings.h>
#include <stdio.h>
#include <string.h>
// #define FORMAT_PREFIX "Bellowa "
#define BUFFER_POOL_SIZE 4
#define BUFFER_POOL_CELL_SIZE 50

int main() {

  char my_pool[BUFFER_POOL_SIZE * BUFFER_POOL_CELL_SIZE];
  char * my_pool_p = &my_pool[0];
  printf("my_pool location: %d\n", &my_pool);
  printf("my_pool size: %d\n", sizeof(my_pool));

  // Clear out buffer
  for(int i = 0; i < (BUFFER_POOL_SIZE * BUFFER_POOL_CELL_SIZE); ++i) {
    my_pool[i] = '0';
  }

  char * str = "I am much more than five chars";
  strncpy(my_pool, str, BUFFER_POOL_CELL_SIZE);
  printf("my_pool value: %s\n", my_pool);

  char * cell2 = my_pool_p + (2 * BUFFER_POOL_CELL_SIZE);
  // printf("cell2 location: %d\n", &cell2);
  strncpy(cell2, "The plutarchy", BUFFER_POOL_CELL_SIZE);
  printf("cell2 value: %s\n", cell2);
  // cell2[0] = 'C';
  // for(int i = 0; i <  BUFFER_POOL_CELL_SIZE; ++i) {
  //   cell2[i] = str[i];
  // }

  printf("my_pool value: %s\n", my_pool);
  printf("my_pool[050] value: %s\n", my_pool_p + 50);
  printf("my_pool[100] value: %s\n", my_pool_p + 100);
  printf("my_pool[150] value: %s\n", my_pool_p + 150);
  // printf("%d\n", sizeof(my_pool[44]));
  // printf("%s\n", cell);

  return 0;
}
