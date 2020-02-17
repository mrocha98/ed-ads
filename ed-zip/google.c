#include <stdio.h>

int main(void){
    int x, y;
    x = 2;
    y = 5;
    if (y > 8){
        y = y * 2;
    } else {
        x = x * 2;
    }
    printf ("%d\n", x + y);
    system ("pause");
}
