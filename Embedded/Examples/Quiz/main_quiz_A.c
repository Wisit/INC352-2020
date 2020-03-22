/*
Instructions:
  1) Make the LED0 blink 0.5Hz 
     (1 point)

  2) Print the message liks this:
     Counter: 0.000...
     Counter: 1.111
     Counter: 2.222
     ...
     every one second. 
     (2 points)

  3) When the switch PSW3 is pressed,
     the LED3 will be toggled.
     (2 points)
*/


#include "os.h"


// Counter used to print
float counter = 0.0000;

void Worker1(void *p) {

   LED_Inv(LED_ID_0); // ON: 1s, OFF: 1s -> 2sec -> 1/2sec -> 0.5Hz

   // Pint a formatted string
   char buff[32];
   sprintf(buff, "Counter: %.3f\r\n", counter); // %.3f: x.xxx
   Uart1_AsyncWriteString(buff);
   // Next value
   counter += 1.111;
}

void PSW3_Callback(void *p) {
   LED_Inv(LED_ID_3);  
}

int main(void)
{
    OS_Init();

    OS_TimerCreate("Timer1",  1000, 1, Worker1); 
    OS_SwitchSetCallback(PSW_ID_3, PSW3_Callback);
  
    OS_Start();
}
