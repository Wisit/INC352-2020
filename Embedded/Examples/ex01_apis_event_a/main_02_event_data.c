#include "os.h"

// EX2--Event and Callbacks


void PSWx_Callback(void *event) {
    
    // Unpacking the received event
    event_t  *evt = (event_t *)event;
    switch_t *psw = evt->sender;

    // Take the sender id, the switch id.
    int id = psw->id;

    // Toggle the LED specified by the id.
    LED_Inv(id);
}

int main(void)
{
    OS_Init();

    // Subscribe to all switches


    // Example 1
    // OS_SwitchSetCallback(PSW_ID_0, PSWx_Callback);
    // OS_SwitchSetCallback(1, PSWx_Callback);
    // OS_SwitchSetCallback(2, PSWx_Callback);
    // OS_SwitchSetCallback(3, PSWx_Callback);

    // Example 2
    // int i;
    // for( i = 0; i < 4; i++ ) 
    // {
    //     OS_SwitchSetCallback(i, PSWx_Callback);
    // }


    // Example 3
    int i;
    for( i = PSW_ID_0; i <= PSW_ID_3; i++ ) 
    {
        OS_SwitchSetCallback(i, PSWx_Callback);
    }

    OS_Start();
}
