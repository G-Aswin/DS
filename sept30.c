#include <stdio.h>
#include <string.h>

int strlength(const char a[])
{
    int i = 0;
    while(a[i] != '\0')
        i++;

    return i;
}


int main()
{
    char str[20] = "india";
    struct emp 
    {
        int eid;
        char name[20];
    }E;
    printf("\nInbuilt length of str  = %d\n", strlen(str));
    // printf("\nOur funct length of str  = %d\n", strlength(str));

}   