#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
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
int	main(int ar,string c[])
{
    if(ar==2)
    {
        int k=atoi(c[1]);
    printf("plaintext: ");
  string a=get_string();
  //int k=get_int()%26;
  printf("ciphertext: ");
  for(int i=0;i<strlen(a);i++)
  {
      printf("%c",calc(a[i],k));
  }
  
  printf("\n");return 0;}
else
{
printf("Usage: ./caesar k\n");
return 1;}}