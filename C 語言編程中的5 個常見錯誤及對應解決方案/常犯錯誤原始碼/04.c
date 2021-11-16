#include <stdio.h>
#include <stdlib.h>
//4、重複釋放記憶體/內存
int main()
{
  int *array;
  puts("malloc an array ...");
  array = malloc(sizeof(int) * 5);
  if (array) {
    puts("malloc succeeded");
    puts("Free the array...");
    free(array);
  }
  puts("Free the array...");
  free(array);
  puts("Ok");
}