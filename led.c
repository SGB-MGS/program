#define green 0
#define red 1
void led(int signal)
{
    switch(signal)
    {
        case 0:digitalWrite(red,HIGH);digitalWrite(green,LOW);break;
        case 1:digitalWrite(green,HIGH);digitalWrite(red,LOW);break;
        default:printf("error");
    }
}