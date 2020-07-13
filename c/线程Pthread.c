//gcc filename.c -lpthread

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void* thread_func(void *arg)
{
    int *val = arg;
    printf("Hello from thread function");
    if(arg != NULL)
        //while(1)
            printf("argument set: %d\n", *val);
}

int main()
{
    pthread_t tid;
    int t_arg = 100;

    if(pthread_create(&tid, NULL, thread_func, &t_arg))
        perror("Fail to create thread");
    //sleep(1);
    printf ("Main thread!\n");

    if (pthread_join(tid, NULL)) { // 等待tid 线程结束
        perror("wait mid thread error!");
        return 0;
    }

    //pthread_cancel(tid);

    return 0;
}

