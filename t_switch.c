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
	if(digitalRead(bu)==1) 
	{
		led(0);
	}
	if(digitalRead(bu)==0) 
	{
		led(1);
	}

    }
}
