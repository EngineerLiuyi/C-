#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void exiting(void){
    printf("    Exiting the process!\n");
}

void childexiting(void){
    printf("    Exiting the child process!\n");
}

int main()
{
    pid_t pid, pid_wait;
    int status;
    time_t when;

    int fd[2];
    char *buf = "Exit command!";
    char cmd[64];

    if(pipe(fd) != 0)
    {
        perror("Fail to create pipe!\n");
        exit(-1);
    }

    pid = fork();
    if (pid == -1)
    {
        fprintf(stderr, "Fail to create process!\n");
        exit(-1);
    }
    else if (pid == 0)
    {
        time(&when);
        printf("Child process! %s\n", ctime(&when));
        close(fd[1]);
        printf("wait command from parent!\n");
        atexit(childexiting);
        while(1){
            read(fd[0], cmd, 64);
            int cond = 1;
            cmd[strlen(buf)] = '\0';
            if (cond = strcmp(buf, cmd) == 0)
            {
                time(&when);
                printf("DATA From Parent: %s %s\n", cmd, ctime(&when));
                close(fd[0]);
                exit(0);
            }
        }

    }
    else {
        time(&when);
        printf("Parent process! Child process ID: %d %s\n", pid, ctime(&when));
        close(fd[0]);
        sleep(2); //在我的Ubuntu上面不起作用
        write(fd[1], buf, strlen(buf));
        close(fd[1]);
        pid_wait = waitpid(pid, &status, 0); //改写这里可以处理多种子进程情况
        printf("Child process %d returned!\n", pid_wait);
        atexit(exiting);
    }

    return 0;
}

