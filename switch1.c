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
    if(0==signal)
    {
        digitalWrite(green,LOW);
        digitalWrite(red,HIGH);
    }
    else
    {
        if(1==signal)
        {
            digitalWrite(green,HIGH);
            digitalWrite(red,LOW);
        }
        else
        {
            printf("error");
        }
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
        }
    }
}