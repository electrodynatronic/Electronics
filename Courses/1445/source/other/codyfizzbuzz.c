#include<stdio.h>

int main()
{
int i;
for (i = 0; i <= 100; i++)
    {
    if(i%3==0){
        printf("Fizz");
        if(i%5==0)
            printf("Buzz");}
    else if(i%5==0)
        printf("Buzz");
    else {printf ("%d", i ) ;}
    printf("\n");
    }
return 0;
}
