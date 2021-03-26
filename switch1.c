#include<stdio.h>
#include<wiringPi.h>
#define green 0
#define red 1
#define switch 2
void init()
{
    wiringPiSetup();
    pinMode(green,OUTPUT);
    pinMode(red,OUTPUT);
       pinMode(switch,INPUT);
}
void led(int signal)
{
    switch(signal)
    {
        case 0:digitalWrite(red,HIGH);digitalWrite(green,LOW);break;
        case 1:digitalWrite(green,HIGH);digitalWrite(red,LOW);break;
        default:printf("error");
    }
}

void main(void)
{
    init();
    while(1)
    {
        switch(digitalRead(switch))
        {
            case 0:led(0);printf("挡\n");break;
            case 1:led(1);printf("不挡\n");break;
            default:printf("error");
        }
    }
}