#include <stdio.h>
#include "sort.h"

#define arraySize 50
int main(){
    int arr[arraySize];
    for(int i=0; i<arraySize; ++i){
        printf("insert number %d\n", i);
        if(scanf("%d", (arr+i)) != 1){
            printf("insert again\n");
            --i;
        }
    }
     insertion_sort(arr , arraySize);
     for(int i=0; i<arraySize-1; ++i){
         printf("%d,", *(arr+i));
     }
     printf("%d\n", *(arr+arraySize-1));
     return 0;
}