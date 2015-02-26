#include <stdio.h>
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
We're playing with loops
*/
void main(void){
int i;
    for (i=0; i<100 ; i++){
//        printf("Hi ");
        if(i%3==0){printf("Fizz");}
        if(i%5==0){printf("Buzz");}
        else  printf("%d",i);
        printf("\n");
        }
printf("Done.\n");
}
