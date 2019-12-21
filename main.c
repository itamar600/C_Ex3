# include <stdio.h>
# include "txt_find.h"
#include <string.h>

# define LINE 256
# define WORD 30

int main(){
    char searchString[WORD] = "";
    char space[LINE][WORD];
    char option;
    getwords(searchString);
    scanf("%c", &option);
    getLine(space[0]);
    
    switch(option){
        case 'a':
        print_lines(searchString);
        break;
        case 'b':
        print_similar_words(searchString);
        break;
        default:
        printf("incorrect option\n");
    }

    return 0;
}