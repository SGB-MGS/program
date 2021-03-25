#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
void* fun1(void* arg)
{
    int a;
    char* name1=(char*)arg;
    for(a=0;a<50;a++)
    {
        printf("%s:%d	",name1,a);
    }
}
void* fun2(void* arg)
{
    int a;
    char* name1=(char*)arg;
    for(a=0;a<50;a++)
    {
        printf("%s:%d	",name1,a);
    }
}
void main(void)
{
    pthread_t th1;
    pthread_t th2;
    pthread_create(&th1,0,fun1,"th1");
    pthread_create(&th2,0,fun2,"th2");
    pthread_join(th1,0);
    pthread_join(th2,0);
}
