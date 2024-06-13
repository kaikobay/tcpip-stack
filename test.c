#include <stdio.h>

int main(void) {
  char   array[] = {1, 2, 3, 4, 5};
  char*  ptr = &array[2];
  char*  ptr2 = array + 2;
  short* ptr3 = (short*)array + 2;
}