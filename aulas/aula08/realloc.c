#include <stdio.h>
#include <stdlib.h>

int main (){
    int *p = (int*) malloc(2* sizeof(int));
    p[0] = 10;
    p[1] = 20;

    int *q = (int*) realloc(ptr, 3* sizeof(int));
    q[2] = 30;

    int i;
    for( i=0; i<3; i++)
        printf("%d", q[i]);
    return 0;
}