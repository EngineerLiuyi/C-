#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    key_t key = 0x90;
    /*
    if(key = ftok("write",24)==-1)
        printf("ERROR!");
    */
    int shmid;
    char *ptr;

    shmid = shmget(key, 1024, SHM_W|SHM_R|IPC_EXCL);

    if (shmid == -1)
        perror("create share memory");

    ptr = (char*)shmat(shmid, 0, 0);
    if (ptr == (void*)-1)
        perror("get share memory");

    printf("string in share memory: %s\n", ptr);
    shmdt(ptr);

    return 0;
}

