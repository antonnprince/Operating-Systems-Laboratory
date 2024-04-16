#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    char input[40];
    char output[40];
    int flag=0;
    
    printf("Enter main string\n");
    scanf("%s",&input);
    printf("Enter substring to extract\n");
    scanf("%s",&output);
    
    if(strlen(output)>strlen(input))
    printf("Error");
    
    int l=strlen(output);
    
    for(int i=0;i<strlen(input);i++)
    {
        for(int j=0;j<strlen(output);j++)
        {
            if(input[i]==output[j])
            {
                int n=1;
                
                while(n!=l)
                {
                    if(input[i]==output[j])
                    {
                        i++;
                        j++;
                        n++;
                        if(n==l)
                        {
                            flag=1;
                        }
                    }
                    else
                    break;
                }
            }
        }
    }
    
    if(flag==1)
    printf("\nSubstring extracted");
    else
    printf("Substring not extracted");

    return 0;
}
