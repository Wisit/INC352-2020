#include "os.h"

// UART, Serial port, 
// Event, Callback


// Callback function of UART1
void Uart1_Callback(void * event) {
   LED_Inv(LED_ID_3);
}

int main(void)
{
   OS_Init();

   // Subscribe (add callback) to the UART1 (byte recrive)
   OS_Uart1SetRxCallback(Uart1_Callback);
  
   OS_Start();
}
