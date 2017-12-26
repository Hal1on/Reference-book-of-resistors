#include "my.h"
/* function to swap data of two nodes a and b*/
void swap(resistor *a, resistor *b) {
    float temp = a -> power;
    a -> power = b -> power;
    b -> power = temp;

    double temp1 = a -> admission;
    a -> admission = b -> admission;
    b -> admission = temp1;

    int temp2 = a -> resistance;
    a -> resistance = b -> resistance;
    b -> resistance = temp2;

    char tmp[40];
    strcpy(tmp, a -> name);
    strcpy(a -> name,b -> name);
    strcpy(b -> name,tmp);
}
