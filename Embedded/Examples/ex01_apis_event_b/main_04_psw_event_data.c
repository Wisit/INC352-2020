#include "os.h"

// Switch
// Event-Data, Callback


// Switch PSW<id> callback function
void PSWx_Callback(void *event) {
   
   // Unpack the received event
   event_t  *evt = (event_t *)event;
   switch_t *psw = evt->sender;

   // Get the switch id
   int id = psw->id; // 0, 1, 2, 3

   // Toggle the LED<id>
   LED_Inv(id); 
}


int main(void)
{
   OS_Init();

   // Subscribe to all switches
   /*
   int id;
   for( id=0; i<4; i++) {
      OS_SwitchSetCallback(PSW_ID_2, PSWx_Callback);
   }
   */

   // Subscribe to all switches
   int id;
   for( id=PSW_ID_0; id<=PSW_ID_3; id++) {
      OS_SwitchSetCallback(id, PSWx_Callback);
   }

   OS_Start();
}
