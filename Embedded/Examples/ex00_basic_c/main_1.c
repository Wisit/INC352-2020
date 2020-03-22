

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
    int i1 = 98; // ['9']['8']

    sprintf(buff, "My i1 = %d\r\n", i1);
    Uart1_WriteString(buff);

    float f1 = 1.23654878125485134514231551315643;
    sprintf(buff, "My f1 = %f\r\n", f1);
    Uart1_WriteString(buff);

    double d1 = 1.23654878125485134514231551315643;
    sprintf(buff, "My d1 = %f\r\n", d1);
    Uart1_WriteString(buff);

    OS_Start();
}

// ecc-pic24-cli -build
