#include "os.h"

// Switch
// Event, Event-Data, Callback


// Switch PSW0 callback function
void PSW0_Callback(void *event) {
   LED_Inv(LED_ID_0); 
}

/*
void PSW1_Callback(void *event) {
   LED_Inv(LED_ID_1); 
}

void PSW2_Callback(void *event) {
   LED_Inv(LED_ID_2); 
}

void PSW3_Callback(void *event) {
   LED_Inv(LED_ID_3); 
}
*/

int main(void)
{
    OS_Init();
    

    // - Subscribe
    // - Add event listenner
    // - Add callback, Set callback

    // Set callback or subscribe to the PSW0
    OS_SwitchSetCallback(PSW_ID_0, PSW0_Callback);
    
    /*
    OS_SwitchSetCallback(PSW_ID_1, PSW1_Callback);
    OS_SwitchSetCallback(PSW_ID_2, PSW2_Callback);
    OS_SwitchSetCallback(PSW_ID_3, PSW3_Callback);
    */

    OS_Start();
}
