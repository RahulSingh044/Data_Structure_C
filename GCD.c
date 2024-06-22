#include <stdio.h>

int GCD( int x, int y) {
     if(x>y) {
         if(x%y == 0) {
             return y;
         }
         GCD(y,x%y);
     }
     else {
        GCD(y,x);
     }
}

int main() {
   int val = GCD(980,9000);
   printf("The GCD is %d",val);
}
