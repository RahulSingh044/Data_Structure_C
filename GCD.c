#include <stdio.h>

int GCD( int x, int y) {
    if(y == 0) {
        return x;
    } else {
        GCD(y,x%y);
    }
}

int main() {
   int val = GCD(980,9000);
   printf("The GCD is %d",val);
}
