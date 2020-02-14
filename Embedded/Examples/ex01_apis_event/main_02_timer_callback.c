#include "os.h"

// Software timer and callback function

// Callback function of the timer.
void timer_callback(void *event) {
    LED_Inv(LED_ID_0);
}

// Callback function of 1-short timer
void callback(void * evt) {
    UART1_AsyncWriteString("Printed in callback\r\n");
}


int main(void)
{
    OS_Init();

    // Create a timer
    OS_TimerCreate(
            "t1",   // Name
            100,    // Time (ms)
            1,      // Mode, 1: continuous, 0: 1-short
            timer_callback // c-function
        );

    // Create another timer, a 1-short timer
    OS_TimerCreate("1-short", 500, 0, callback);

    OS_Start();
}
