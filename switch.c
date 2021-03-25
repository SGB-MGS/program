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
        printf("关");
    }
    else
    {
        if(1==signal)
        {
            digitalWrite(green,HIGH);
            digitalWrite(red,LOW);
            printf("开");
        }
    }
}

void main()
{
    init();
    while(1)
    {
        if(0==digitalRead(switch))
        {
            delay(10);
            if(0==digitalRead(switch))
            {
                led(0);
            }
        }
        else
        {
            if(1==digitalRead(switch))
            {
                delay(10);
                if(1==digitalRead(switch))
                {
                    led(1);
                }
            }
        }
    }
}