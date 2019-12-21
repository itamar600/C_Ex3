#include <stdio.h>

 void shift_element(int* arr, int i) {
     int index;
     for(index=i-1; index>=0; --index)
         *(arr+(index+1))=*(arr+index);   
 }

 void insertion_sort(int* arr , int len) {
     int lastSubValue,indexSub,key;
     for(lastSubValue=1; lastSubValue<len; ++lastSubValue){
         key=*(arr+lastSubValue);
         indexSub=lastSubValue-1;
         while(key<*(arr+indexSub) && indexSub>-1){
                 --indexSub;
             }
         if(indexSub!=lastSubValue-1){
             shift_element( (arr+indexSub+1), lastSubValue-indexSub-1);
             *(arr+indexSub+1)=key;
         }
     }
 }
