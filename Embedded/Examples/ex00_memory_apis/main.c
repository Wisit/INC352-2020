#include "os.h"

int main(void)
{
    OS_Init();

    int x = 123;

    float y = 8.135898;

    // 1. address (memory location) 
    // 2. value (content in that location)
    // 3. size (number of bytes of that variable)

    char buff[32];
    // value
    sprintf(buff, "value:   %i\r\n", x);
    Uart1_AsyncWriteString(buff);
    // addr
    sprintf(buff, "address: 0x%X\r\n", &x); // x: abcdef, X: ABCDEF
    Uart1_AsyncWriteString(buff);
    // size
    sprintf(buff, "size:    %i\r\n", sizeof(x));
    Uart1_AsyncWriteString(buff);


    // y

    sprintf(buff, "value:   %f\r\n", y);
    Uart1_AsyncWriteString(buff);
    // addr
    sprintf(buff, "address: 0x%X\r\n", &y); // x: abcdef, X: ABCDEF
    Uart1_AsyncWriteString(buff);
    // size
    sprintf(buff, "size:    %i\r\n", sizeof(y));
    Uart1_AsyncWriteString(buff);

    OS_Start();
}
