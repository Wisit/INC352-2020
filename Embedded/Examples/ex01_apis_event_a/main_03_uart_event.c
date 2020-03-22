#include "os.h"

// EX3-- UART Event (signaling).

// Callback funtion of the Uart1 byte received event.
void UART_RX_Callback(void *event) {
    LED_Inv(LED_ID_0);
}


int main(void)
{
    OS_Init();

    // Subscribe to the Uart1 byte received event.
    OS_Uart1SetRxCallback( UART_RX_Callback );

    OS_Start();
}
