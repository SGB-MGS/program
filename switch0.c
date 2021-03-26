#include<stdio.h>
#include<wiringPi.h>
#define green 0
#define red 1
#define bu 2
void init()
{
    wiringPiSetup();
    pinMode(green,OUTPUT);
    pinMode(red,OUTPUT);
    pinMode(bu,INPUT);
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

void main()
{
    init();
    while(1)
    {
        if(0==digitalRead(bu))
        {
            delay(10);
            if(0==digitalRead(bu))
            {
                led(0);
                printf("关");
            }
        }
        else
        {
            if(1==digitalRead(bu))
            {
                delay(10);
                if(1==digitalRead(bu))
                {
                    led(1);
                    printf("开");
                }
            }
        }
    }
}