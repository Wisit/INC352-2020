

#include "os.h"

int main(void)
{

    OS_Init();

    
    LED_On(LED_ID_1);
    LED_On(LED_ID_2);

    //Uart1_WriteString("Name: Santi Nuratch\r\n");
    //Uart1_WriteString("ID:   12345678\r\n");


    // ['A']['S'][][][][][][]    []
    char buff[32];
    char i1 = -80; // ['9']['8']

    sprintf(buff, "addr:  %X\r\n", &i1);
    Uart1_WriteString(buff);
    sprintf(buff, "value: %i\r\n", i1);
    Uart1_WriteString(buff);
    sprintf(buff, "size:  %i\r\n", sizeof(i1));
    Uart1_WriteString(buff);

    

    OS_Start();
}

// ecc-pic24-cli -build
