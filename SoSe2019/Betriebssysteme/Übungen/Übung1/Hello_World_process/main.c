#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//char global[] = {"defaultMessage"};

int main()
{
    pid_t pid;

    pid = fork();

    if(pid < 0){
        fprintf(stderr, "Fork failed");
        return 1;
    }else if(pid == 0){

        printf("Hello world!\n I'm the child!\n");
        int i;
        for(i = 0; i < 100; i ++){
            sleep(1);
            printf("c: %d \n", i);
            fflush(stdout);
        }
        printf("\n");

  //      strcpy(global, "Hallo Papa");
    }else{

        int i;
        for(i = 0; i < 100; i ++){
            sleep(1);
            printf("p: %d \n", i);
            fflush(stdout);
        }

    /*
        printf("Hello world!\n I'm the parent!\n");
        wait(NULL);
        printf("child finished");

        wait(NULL);
        printf("%s", global);
    */
    }
    return 0;
}
