#include <stdio.h>
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
We're playing with loops
*/
void main(void){
// mod a
//    for (int i=0; i<10 ; i++)
//        printf("Hello %d.\n",i);
// mod b
//    for (int i=0; i<10 ; ++i)
//        printf("Hello %d.\n",i);
// mod c
    for (int i=0; i<10 ; i=i+1)
        printf("Hello %d.\n",i);
// mod d
//    for (int i=0; i<10 ; i+=1)
//        printf("Hello %d.\n",i);
}
