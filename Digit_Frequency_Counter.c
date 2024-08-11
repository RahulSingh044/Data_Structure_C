#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

int main() {

    /* The input string containing characters and digits. */
    char c[] = "a163vc8e8n9m40c8";    

    /* Calculate the length of the string. */
    int length = strlen(c);

    /* Initialize an array to store the frequency of digits (0-9).
       The index of the array corresponds to the digit, and the value at each index represents the frequency of that digit. */
    int frequency[10] = {0};

    /* Loop through each character in the string. */
    for(int i=0; i<length; i++) {

        /* Check if the current character is a digit. */
        if(isdigit(c[i])){

            /* Convert the character digit to an integer.
               For example, if c[i] is '3', '3' - '0' gives the integer 3. */
            int x = c[i] - '0';

            /* Increment the frequency of the corresponding digit. */
            frequency[x]++;
        }
    }

    /* Print the frequency of each digit from 0 to 9. */
    for(int i=0; i<10; i++){
        printf("%d ", frequency[i]);
    }
}
