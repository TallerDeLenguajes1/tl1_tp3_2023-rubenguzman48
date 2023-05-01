#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char *p;
    p = (char *) malloc(sizeof(char) *11);
    strcpy(p,"Hola mundo");
    printf("%s",p);

    return 0;
}