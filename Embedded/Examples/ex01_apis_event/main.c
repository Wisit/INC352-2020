#include "os.h"

// UART, Serial port, 
// Event, Callback


// Callback function of UART1
void Uart1_Callback(void * event) {

   // Unpack the received event
   uart_event_t *uart_event = (uart_event_t *)event;
   data_t uart_data = uart_event->data;; // structure of data

   // Get a byte data from the event
   char c = uart_data.buffer[0];    // array of bytes


   // Based ion the " American Standard Code for Information Interchange."
   // http://www.asciitable.com/
   
   // '0' = 0x30  ==>  0x30 - 0x30 = 0
   // '1' = 0x31  ==>  0x31 - 0x30 = 1
   // '2' = 0x32  ==>  0x32 - 0x30 = 2
   // '3' = 0x33  ==>  0x33 - 0x30 = 3
    

   if(c >= '0' && c <= '3') {
      char buff[32];
      sprintf(buff, "Toggle LED<%c>\r\n", c);
      UART1_AsyncWriteString(buff);

      LED_Inv(c-0x30); 
   }

   //
   /*
   if(c == '0') {
      LED_Inv(LED_ID_0);
   }
   else if(c == '1') {
      LED_Inv(LED_ID_1);
   }
   else if(c == '2') {
      LED_Inv(LED_ID_2);
   }
   else if(c == '3') {
      LED_Inv(LED_ID_3);
   }
   */

}

int main(void)
{
   OS_Init();

   // Subscribe (add callback) to the UART1 (byte recrive)
   OS_Uart1SetRxCallback(Uart1_Callback);
  
   OS_Start();
}
