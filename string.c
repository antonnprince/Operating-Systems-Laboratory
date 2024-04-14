#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int fd[2];
    pid_t p;
    int i,n,sum;
    char str[100];
    
    pipe(fd);
    
    p=fork();
    
    if(p>0){
        close(fd[0]);
        printf("Enter string\n");
        scanf("%s",str);
        write(fd[1],&str,sizeof(str));
        wait(NULL);
        
    }
    else
    {
         close(fd[1]);
        sleep(5);
        char ans[100];
        read(fd[0],&ans,sizeof(ans));
        printf("String is: %s",ans);
       
    }
    
}
