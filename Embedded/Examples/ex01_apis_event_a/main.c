#include "os.h"

// EX4-- UART Event Data and kyboard.

// Check this: http://www.asciitable.com/

// Callback funtion of the Uart1 byte received event.
void UART_RX_Callback(void *event) {

    // Unpack the received event
    uart_event_t *evt = (uart_event_t *)event;
    data_t uart_data = evt->data;

    // Get data (key)
    char key = uart_data.buffer[0];


    // Check the received byte (character)
    char buff[32];
    sprintf(buff, "Key: %c\r\n", key);
    Uart1_AsyncWriteString(buff);


    // Control the LEDs by keyboard.
    // if(key == '0') {
    //     LED_Inv(LED_ID_0);
    // }
    // else if(key == '1') {
    //     LED_Inv(LED_ID_1);
    // }
    // else if(key == '2') {
    //     LED_Inv(LED_ID_2);
    // }
    // else if(key == '3') {
    //     LED_Inv(LED_ID_3);
    // }


    // Check this: http://www.asciitable.com/
    // key: '0' => 0x30 - 0x30 = 0 
    // key: '1' => 0x31 - 0x30 = 1
    // key: '2' => 0x32 - 0x30 = 2
    // key: '3' => 0x33 - 0x30 = 3


    if(key >= '0' && key <='3') {
        int id = key - 0x30;

        LED_Inv(id);
    }
    else {
        Uart1_AsyncWriteString("Command error!\r\n");  
    }



    
}


int main(void)
{
    OS_Init();

    // Subscribe to the Uart1 byte received event.
    OS_Uart1SetRxCallback( UART_RX_Callback );

    OS_Start();
}
