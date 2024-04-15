#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
    int i=0;
    int fileIn=open("input.txt",O_RDONLY);
    int fileOut=open("output.txt",O_WRONLY);
   // int start = lseek(fileIn,0,SEEK_CUR);
    
    int end = lseek(fileIn,0,SEEK_END);
    lseek(fileIn,0,SEEK_SET);
    
    char inputdata[100];
    char outputdata[100];
    
    read(fileIn, inputdata, end);
    for(int i=0;i<end;i++)
    {
        outputdata[i]=inputdata[i];
    }
    write(fileOut, outputdata, end);
    return 0;
}
