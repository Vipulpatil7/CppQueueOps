#include <stdio.h>

#define REVERSE_16(n) ((unsigned int) ((((n) & 0x00FF)<<8) | \
                                        ((n) & 0xFF00)>>8))

#define REVERSE_32(n) ((unsigned int) ((((n) & 0x000000FF) << 24) | \
                                       (((n) & 0x0000FF00) << 8) | \
                                       (((n) & 0x00FF0000) >> 8) | \
                                       (((n) & 0xFF000000) >> 24)))                                        

void main(void)
{
    int a = 0x1234;
    int b = 0x12345678;
    char c = 0;
    printf("%x\n", a);
    c=a;
    printf("%x\n", c);
    a= REVERSE_16(a);
    c=a;
    printf("%x\n", c);
    printf("%x\n", a);

    printf("\n%x\n", b);
    c=b;
    printf("%x\n", c);
    b= REVERSE_32(b);
    c=b;
    printf("%x\n", c);
    printf("%x", b);
}