#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



char* decToBinary(int x)
{
    // char* to store binary number
    char* binaryNum = malloc(sizeof(char) * 16);

    // remainder for binary array
    int remainder = 0;

    // counter for array
    int i = sizeof(char) * 16;


    while (x != 0) {
        // storing remainder in binary array
        remainder = x % 2;

        binaryNum[--i] = remainder + '0';

        x /= 2;
    }

    // If the number is less than 16 characters long
    // We need to fill the rest of them with zeroes
    if(i > 0){
        while(i >= 0){
            binaryNum[--i] = '0';
        }
    }
    binaryNum[16] = '\0';
    return binaryNum;

}



// get binary digit at index n for the decimal integer x
char get(int x, int n){
    char* binX = decToBinary(x);
    char output;
    int realN = 15 - n;
    output = binX[realN];
    // reverse iterate or subtract n from size and return index of binary char
    return output;
}

void isPalindrome(int x){
    int i = 0;
    int length = 15;

    while(length > i){
        if(get(x, i++) != get(x, length--)){
            printf("Not-Palindrome \n");
            return;
        }
    }
    printf("Is-Palindrome \n");

}


void main(int argc, char *argv[]) {

//    int x = atoi(argv[1]);
    int x = atoi("65");
    //int x = 65535;

    //char* output = decToBinary(x);
    //printf("Input Number: %d \n", x);
    //printf("Binary Representation: %s \n", output);

    isPalindrome(x);


}

