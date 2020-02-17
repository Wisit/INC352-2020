#include "os.h"


float counter = 0.0;

void Worker1(void *p) {
   LED_Inv(LED_ID_0);
   char buff[32];
   sprintf(buff, "Counter: %.3f\r\n", counter);
   Uart1_AsyncWriteString(buff);
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
