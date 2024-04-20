#include <stdio.h>
#include <string.h>

void tong (int a, int b){
    printf("Tong %d va %d: %d\n", a, b, a+b);
}

int main() {

  void *ptr;

  ptr = &tong;

  ((void (*)(int, int))ptr)(8, 9);
   return 0;
}
