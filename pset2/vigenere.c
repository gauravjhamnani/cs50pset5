#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
char calc(char a,int k)
{
    if('a'<=a && a<'z')
    {
    for(int i=0;i<k;i++)
    {
        if(a<'z')a++;
        else
        a='a';
    }
        return a;
    }
    else if('A'<=a && a<'Z')
    {
        for(int i=0;i<k;i++)
    {
        if(a<'Z')a++;
        else
        a='A';
    }
    return a;
    }
    else
    return a;
    
}
void pro(string text,string key)
{
    int a[strlen(key)];
    for(int i=0;i<strlen(key);i++)
    {
        if('a'<=key[i] && key[i]<='z')
        {
            a[i]=key[i]-97;
        }
        else
        a[i]=key[i]-65;
    }int i=0;
    int count=0;
    printf("ciphertext: ");
    while(i<strlen(text))
    {
        if(('a'<=text[i] && text[i]<='z') || ('A'<=text[i]  && text[i]<='Z'))
        
        {
            //printf("count :%d ",count);
            printf("%c",calc(text[i],a[count]));
        count=(count+1)%(strlen(key));
        }
        else
        printf("%c",text[i]);
        
        
        i++;
    }
}
int main(int argn,string argv[])
{
    int count=0;
    string s;
    if(argn==2 )
    {
        for(int i=0;i<strlen(argv[1]);i++)
        {
            if(('a'<=argv[1][i] && argv[1][i]<='z') || ('A'<=argv[1][i]  && argv[1][i]<='Z'))
            count++;
        }
        if(count!=strlen(argv[1]))
        {
            printf("Error");
        return 1;
        }
        else
        {
            printf("plaintext: ");
            s=get_string();
            pro(s,argv[1]);
            printf("\n");
            return 0;
        }
    }
    else
    {
        printf("error");
        return 1;
    }
}
    
