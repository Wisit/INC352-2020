

#include "os.h"

// 2 Hz

void Controller(void *param) {
    //LED_Inv(LED_ID_2);
}

void Action(void *para) {

    event_t  *evt = (event_t *)para;
    switch_t *psw = evt->sender;

    int id = psw->id;

    LED_Inv(id);  
}

int main(void)
{
    OS_Init();
    OS_TimerCreate("Timer", 200, TIMER_MODE_CONTINUEOUS, Controller);
    
    int i;
    for(i=0; i<4; i++) {
        OS_SwitchSetCallback(i, Action);
    }
    
    
    OS_Start();
}

// ecc-pic24-cli -build
