

#include "os.h"

// 2 Hz

void Controller(void *param) {
    LED_Inv(LED_ID_2);
}

void Action(void *x) {
    LED0_Inv();  
}

int main(void)
{
    OS_Init();
    
    OS_TimerCreate("Timer", 200, TIMER_MODE_CONTINUEOUS, Controller);

    OS_SwitchSetCallback(PSW_ID_0, Action);

    OS_Start();
}

// ecc-pic24-cli -build
