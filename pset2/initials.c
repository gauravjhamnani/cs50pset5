#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
    string a=get_string();
    printf("%c",toupper(a[0]));
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]==' ')
        printf("%c",toupper(a[i+1]));
    }
    printf("\n");
    return 0;
}