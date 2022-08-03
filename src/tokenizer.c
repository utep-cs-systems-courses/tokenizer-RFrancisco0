#include <stdio.h>
#include "tokenizer.h"
#include <stdlib.h>
//#include "color.h"


int space_char(char c){
  if(c==' '|| c == '\t' || c == '\n'){
    // printf("some space \n");
    return 1;
  }
  return 0;
}


int non_space_char(char c){
  if(c!=' '&& c!= '\t' && c!='\n'){
    // printf("no space \n");
    return 1;
  }
  return 0;
}


char *word_start(char *str)
{
  while(space_char(*str)){
    str++;
  }
  return str;
}


char *word_terminator(char *word)
{
  while(non_space_char(*word)){
    word++;
  }
  return word;
}

int count_words(char *str)
{
  int i,words=0;//using i as a temporary counter
  for(i=0;str[i];i++)
    {
      if(str[i]==32)
	words++;
    }
  if(i>0)
    words++;

  return words;
}


char *copy_str(char *inStr, short len)
{
  char *copy_str=(char*)malloc(sizeof(char)*(len+1));
  int i=0;
  while(i<len){
    copy_str[i]=inStr[i];
    i++;
  }
  copy_str[len]='\0';
  return copy_str;
}


char **tokenize(char *str)
{
  int arrlength = count_words(str);/*countthe number of words in a single string*/
  char **char_array;
  char_array = (char**)malloc(sizeof(char*) * (arrlength + 1));/*allocate memory for a string-malloc will be needed*/
  int i = 0;

  while(i < arrlength){
    str = word_start(str);
    int sizedif = word_terminator(str) - str;
    char_array[i] = copy_str(str,sizedif);
    str = word_terminator(str);
    i++;
  }
  char_array[i] = NULL;/*last part of the array NULL*/
  return char_array;
}


void print_tokens(char **tokens)
{
  int i;
  for(i = 0; tokens[i] != NULL; i++){

    printf("%s\n", tokens[i]);
    //printf("\033[0m");
  }
}


void free_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i] != NULL){
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
