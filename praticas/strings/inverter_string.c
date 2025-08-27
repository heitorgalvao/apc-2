#include <stdio.h>
#include <string.h>
    int main (){
        char string [] = "hello world";
        char *p1 = string;
        char *p2 = string + strlen(string) - 1;
        char t;
            while(p1<p2){
                t = *p1;
                *p1 = *p2;
                *p2 = t;
                p1 ++;
                p2--;
    }
     printf("A string invertida e: %s\n", string);

    return 0;
}