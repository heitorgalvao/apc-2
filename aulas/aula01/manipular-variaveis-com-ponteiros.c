

#include <stdio.h>

int main() {

  int i = 5;
  int *p;
  p = &i;
  printf("&p: %p (p: %p)\n", &p, p);
  printf("&i: %p  (i: %d)\n", &i, i);
  // leitura de i através de ponteiro
  printf("p: %p (*p: %d)\n", p, *p);
  // escrita em i através de ponteiro
  *p = 7;
  printf("&i: %p  (i: %d)\n", &i, i);
  // leitura de i através de ponteiro
  printf("p: %p (*p: %d)\n", p, *p);
}
