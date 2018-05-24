#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sort.h"
#include "word_info.h"
#include "linked_list.h"

void sort(WordInfo* toSort, int size){ 
  int i, j;
    char value[100];
    for(i = 0; i < size; i++){
        j = i;
       
        while(j > 0 && strcmp(toSort[j].word, toSort[j-1].word)< 0){
            
            printf("\nSwap de %s a %s\n",toSort[j-1].word,toSort[j].word);
                //value = toSort[j];
                strcpy(value,toSort[j].word);
                //toSort[j] = toSort[j-1];
                strcpy(toSort[j].word,toSort[j-1].word);
                //toSort[j-1] = value;
                strcpy(toSort[j-1].word,value);
                j--;
                
        }
    
    }  
}