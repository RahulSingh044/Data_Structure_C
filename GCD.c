#include <stdio.h>

// Eculiad Distance
int EUCGCD( int n1, int n2) {
    while(n1 != n2) {
     if(n1 > n2) {
         n1 -= n2;
     }
     else
      n2-=n1;
    }
    return n1;
}

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



