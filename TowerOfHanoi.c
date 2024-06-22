#include <stdio.h>

void tow( int n, char source, char desti, char aux) {
     if(n==1) {
         printf("disk is moved from tower %c to tower %c",source, desti);
         return;
     }
     tow(n-1,source,aux,desti);
     printf("\ndisk %d is moved from tower %c to tower %c\n", n,source, desti);
     tow(n-1,aux,source,desti);
}

int main() {
   int n;
   scanf("%d",&n);
   tow(n,'A','B','C');
}
