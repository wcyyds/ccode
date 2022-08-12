#include<stdio.h>
#include<string.h>
int main(){
    char dsada[] = "leetcode";
    char *s;
    s = &dsada;
    int n = strlen(*s);
    printf("%d", n);
}