#include <stdio.h>
/*
Counting with functons
counts with for loops placed into funtion
Cody Atkinson
March 3, 2015
*/
void count_to_20(void){        //beginning of definition
int i ;
for(i=20;i<=30;i++){
	printf("%d",i);

printf(" ");}
printf("\n");


}			                      	//end of definition

void count_from_30(void){
int i;
for(i=30;i>=10;i-=1){
	printf("%d",i);

printf(" ");}
printf("\n");

}

void main(void){                //beginning of main
count_to_20();
count_from_30();

}			                         //end of main
