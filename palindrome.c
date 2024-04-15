#include <stdio.h>
#include<string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
   char str[100],rev_str[100];
   scanf("%s",str);
   strcpy(rev_str, str);
    int length = strlen(str);
    
    for(int i=0;i<(length/2);i++)
    {
        if(str[i]!= str[length-i-1])
        {
            printf("Not palindrome");
        }
    }
    
    return 0;
}
