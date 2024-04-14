#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int fd[2];
    pid_t p;
    int i,n,sum;
    
    pipe(fd);
    
    p=fork();
    
    if(p>0){
        
        printf("Enter the size of array: ");
        scanf("%d",&n);
        write(fd[1],&n,sizeof(n));
        printf("Enter elements\n");
        int numbers[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",&numbers[i]);
        }
        write(fd[1],&numbers,sizeof(numbers));
        wait(NULL);
        int ans;
        read(fd[0],&ans,sizeof(int));
        printf("The sum is %d",ans);
    }
    else
    {
        sleep(8);
        read(fd[0], &n,sizeof(int));
        int arr[n];
        read(fd[0],&arr,n*sizeof(int));
        for(i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        write(fd[1],&sum,sizeof(int));
        close(fd[1])
    }
    
}
