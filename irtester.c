#include <stdio.h>
#include <wiringPi.h>
#include "ifttt.h"

int main(int argc, char *argv[])
{
 /* int i;*/
  wiringPiSetup () ;
  pinMode(0, INPUT);
  pinMode(1, OUTPUT); /*blue or green*/
  pinMode(2, OUTPUT); /*red*/
  while(1) {
    printf("Waiting for reset\n");
    while(digitalRead(0) == 1);    
    digitalWrite (1, HIGH); delay (500);
    printf("Blue led is already on before the user waved hand and after\n");
    printf("Waiting for event\n");
    while(digitalRead(0) == 0);
    digitalWrite (2, HIGH); delay (1000);
    printf("Alarm\n");
    ifttt("http://red.eecs.yorku.ca:8080/trigger/event/with/key/Abdul2", "Lab04", "motion detector", "Led turned high");
    digitalWrite (2, LOW);
    printf("Red Led turns off after a delay\n");
  }

  /*NOTREACHED*/
  return 0 ;
}
