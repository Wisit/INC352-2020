

#include "os.h"

// 2 Hz

void Controller(void *param) {
    LED_Inv(LED_ID_0);
}


int main(void)
{
    OS_Init();

    long   x = 1234;
    double y = 3.4567;

    char buff[64];
    sprintf(buff, "var-x, size: %d, addr: 0x%d, value: %ld\r\n", sizeof(x), &x, x);
    Uart1_WriteString(buff);

    sprintf(buff, "var-y, size: %d, addr: 0x%d, value: %f\r\n", sizeof(y), &y, y);
    Uart1_WriteString(buff);


    OS_TimerCreate("Timer", 200, 1, Controller);

    OS_Start();
}

// ecc-pic24-cli -build
