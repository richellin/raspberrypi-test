#include <stdio.h>
#include <wiringPi.h>

#define SW 1 // BCM_GPIO 18

#define LED1 4 // BCM_GPIO 23
#define LED2 5 // BCM_GPIO 24

int main (void)
{
  if (wiringPiSetup() == -1)
  return 1 ;

  pinMode(SW, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  for(;;)
  {
    digitalWrite(LED1, 0); // Off
    digitalWrite(LED2, 0); // Off

    if(digitalRead(SW) == 0)
    {
      digitalWrite(LED1, 1); // On
      digitalWrite(LED2, 1); // On
      delay(1000) ; // mS
    }
  }
  return 0 ;
}
