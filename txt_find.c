# include <stdio.h>
# include "txt_find.h"
# include <string.h>

# define LINE 256
# define WORD 36
# define SUMLINES 250

int getLine(char s[]){
    char c;
    int num = 0;
    while(scanf("%c", &c) != EOF && c != '\n'){
        s[num]=c;
        num++;
    }
    return num;
}

int getwords(char w[]){
    char c;
    int num = -1;
    while(scanf("%c",&c) != EOF){
        num++;
        if( c != '\n' && c!= '\t' && c != ' ' && c != '\r'){
         w[num]=c;
        } 
        else return num;
    }
    return num;
}
int substring(char *str1, char *str2){
    if(strstr(str1,str2)!= NULL) return 1;
    return 0;
}

void print_lines(char *str){
    char lineFromDoc[SUMLINES][LINE];
    int i=0;
    while(getLine(lineFromDoc[i])){
        if(substring(lineFromDoc[i], str))
            printf("%s\n", lineFromDoc[i]);
        ++i;
    }
}

int similar(char *s, char *t, int n){
    int indext=0;
    int sizes=0;
    int sizet=0;
    int indexs=0;
    while(s[sizes]!='\0'){ sizes++;}
    while(t[sizet]!='\0'){sizet++;}
    if(sizes-sizet!=n){
        return 0;
    }
    while(indext<sizet && indexs<sizes){
        if (t[indext]==s[indexs]){
            ++indext;
        }  
        ++indexs;
    }
    if(indext==sizet)
        return 1;
    return 0;
}
void print_similar_words(char *str){
    char w[(LINE*SUMLINES)/WORD][WORD];
    int i=0;
    while(getwords(w[i])!=-1){
        if(similar(w[i],str,1)) printf("%s\n", w[i]);
        else if(similar(w[i],str,0)) printf("%s\n", w[i]);
        ++i;
    }  
}