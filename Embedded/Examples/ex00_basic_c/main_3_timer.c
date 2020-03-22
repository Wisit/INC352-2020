

#include "os.h"

void Controller(void *param) {
    //
    // Toggle LED2
    //
    // LED2_Inv() or LED2_Toggle() or LED_Inv(LED_ID_2) or 
    // LED_Inv(LED_ID_2) or LED_Toggle(LED_ID_2)

    LED_Inv(LED_ID_2);
    
    //LED2_Inv();
}

int main(void)
{
    OS_Init();

    // _____|______|_______|______|
    OS_TimerCreate(
        "Cat",                  // Name
        200,                    // Time (mS)
        TIMER_MODE_CONTINUEOUS, // Mode
        Controller              // Function (callback)
    );

    OS_Start();
}

// ecc-pic24-cli -build
