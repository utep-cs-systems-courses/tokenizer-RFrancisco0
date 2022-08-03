#include <stdio.h>
#include "tokenizer.h"
#include <stdlib.h>
#include "history.h"
//#include "color.h"
#define MAX 300


int str_length(char *str);//to have a track of the string length
int main()
{
  char input[MAX];
  char **token;
  List *hist = init_history(); /*initialize history*/
  puts("Welcome!");
  while (1) { // Infinite while loop
    fputs("Select any option (Tokenize = t, History = h, Index = i) or 'q' to quit\n> ", stdout);
    fflush(stdout);/* stdout only flushes automatically on \n */
    int c,ind, tempo;
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)     /* terminate on end-of-file */
      goto done;
    switch (c) {
    case 't':
      puts("You selected Tokenizer");
      puts("please enter an string");
      scanf("%d",&input);
      fgets(input, MAX, stdin);
      printf("string entered %s\n", input);
      token = tokenize(input);
      printf("the tokenized string is\n");
      print_tokens(token); /*print our tokens*/
      // printf("freeing tokens\n");
      // free_tokens(token);
      printf("adding to history\n");
      add_history(hist, copy_str(input, str_length(input)));
      break;
    case 'h':
      puts("You selected history:");
      print_history(hist);
      break;
    case 'i':
      puts("You selected index:");
      // print_history(hist);
      puts("enter the index number");
      scanf("%d",&tempo);
      //int e = tempo;
      //char *histStr = get_history(hist, tempo);/*get specific history at index*/
      //printf("%s\n", histStr);
      int index = (int)(input[tempo]);
      char *histStr = get_history(hist, tempo);/*get specific history at index*/
      printf("item at index %d %s\n",tempo, histStr);
      break;
    case 'q':
      puts("Bye!");
      free_tokens(token);
      goto done; /* terminate */
    case '\n':
      break;
    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
  }

  
 done: // To exit from program
  return 0;
}
int str_length(char *input)
{
  int count = 0;
  while(*input != '\0'){
    count++;
    input++;
  }
  return count;
}
