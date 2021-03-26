#include<stdio.h>
#include<wiringPi.h>
#include<sys/time.h>
#define echo 0
#define trig 1
void init()
{
	wiringPiSetup();
	pinMode(echo,INPUT);
	pinMode(trig,OUTPUT);
}
float test()
{
	float dis;
	struct timeval ta1,ta2;
	float t1,t2;
	digitalWrite(trig,LOW);
	delayMicroseconds(2);
	degitalWrite(trig,HIGH);
	delayMicroseconds(10);
	while(digitalRead(echo)==1)gettimeofday(&ta1,0);
	while(digitalRead(echo)==0)gettimeofday(&ta2,0);
	t1=ta1.tv_sec*100000+ta1.tv_usec;
	t2=ta2.tv_sec*100000+ta2.tv_usec;
	dis=(t2-t1)/1000000*340/2;
	return dis;
}
void main()
{
	init();
	while(1)
	{
		printf("%f m\n",test());	
		delay(300);
	}
}
