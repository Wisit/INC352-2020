#include "os.h"

// Basic APIs (Application Programming Interfaces)

int main(void)
{
    OS_Init();
    //----START------------------------
    // Code

    LED_On(LED_ID_0);   // Turn on LED0

    LED_Off(LED_ID_3);  // Turn off LED3

    LED_Inv(LED_ID_2);  // Toggle LED2

    // Three lines above can be replaced by the lines below.
    LED0_On();          // Turn on LED0
    LED3_Off();          // Turn off LED3
    LED2_Inv();         // Toggle LED2

    //----END-------------------------
    OS_Start();
}
