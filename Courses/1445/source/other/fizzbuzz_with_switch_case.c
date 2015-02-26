#include <stdio.h>
//#include <stdbool.h>
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Fizzbuzz with switch case
*/
void main(void){
int i;
//int j=0;
    for (i=0; i<10 ; i++){
//        printf("Hi ");
        switch (i){
        
        case (1):
            printf("One %d, AH AH AH!\n",i);
            break;
        case (2):
            printf("Two %d, AH AH AH!\n",i);
            break;
        case (3):
            printf("Three %d, AH AH AH!\n",i);
            break;
        case (4):
            printf("Four %d, AH AH AH!\n",i);
            break;
        case (5):
            printf("Five %d, AH AH AH!\n",i);
            break;
        case (6):
            printf("Six %d, AH AH AH!\n",i);
            break;
        case (7):
            printf("Seven %d, AH AH AH!\n",i);
            break;
        case (8):
            printf("Eight %d, AH AH AH!\n",i);
            break;
        default:
            printf("%d, AH AH AH!\n",i);
        
        }
        
    }
}

// */






/*
int main() {
    char color = 0;  //initialize our variable
    printf("Please choose a color(1: red,2: green,3: blue):\n");    //print a message to stdout
    scanf("%c", &color);                //wait for the user to answer
 
    switch (color) {                    //choose the correct response based upon the value of the variable "color"
        case '1':
        case 'r':
        case 'R':
            printf("you chose %c red color\n",color);
            break;
        case '2':
        case 'g':
        case 'G':
            printf("you chose %c green color\n",color);
            break;
        case '3':
        case 'b':
        case 'B':
            printf("you chose %c blue color\n",color);
            break;
        case '0':
            printf("you chose 0 color\t%c\n",color);
        default:
            printf("you did not choose any color\t%c\n",color);
    }
    return 0;
}
*/
