#include "os.h"

int main(void)
{
    OS_Init();

    int x = 1000;

    // 1. address (memory location) 
    // 2. value (content in that location)
    // 3. size (number of bytes of that variable)

    // Type* to string conversion using sprintf()
    char buffer[32];               // [][][][][][][][]
    sprintf(buffer, "x = %i\r\n", x); // [x][=][2][3][4][5][][]
    // [x][x][x][=][1][2][3][4]['\0']
    Uart1_AsyncWriteString(buffer);


    char buf[40];// [][][]
    buf[0] = 'C';
    buf[1] = 'A';
    buf[2] = 'T';
    buf[3] = '\0'; // Null terminator: '\0', 0, NULL 
    buf[4] = 'D';
    buf[5] = 'O';
    buf[6] = 'G';
    Uart1_AsyncWriteString(buf);


    //Uart1_AsyncWriteString("Hello");
    

    OS_Start();
}
