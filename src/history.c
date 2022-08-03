#include <stdio.h>
#include <stdlib.h>
#include "history.h"
//#include "color.h"


List* init_history()
{
  List* list=(List*)malloc(sizeof(List*)*300);
  return list;
}


void add_history(List *list, char *str)
{
  Item* additem=(Item*)malloc(sizeof(Item));
  additem->str=str;
  if(list->root==NULL)
    {
      additem->id=1;
      list->root=additem;
    }
  else
    {
      Item* historyitem = list->root;
      additem->id=1;
      while(historyitem->next!=NULL){
	additem->id++;
	historyitem=historyitem->next;
      }
      historyitem->next=additem;
      additem->id++;
    }
}


/*char* get_history(List* list, int id)
{
  Item* actualNode=list->root;
  if(actualNode == NULL)
    return "Empty";
  while(actualNode != NULL){
    if(actualNode->id==id)
      return actualNode->str;
    actualNode = actualNode->next;
  }
  return "no id";
}*/


char* get_history(List* list, int id)
{
  Item *actualNode =list->root;
  if(actualNode == NULL)
    return"empty history";
  while(actualNode != NULL){
    if(actualNode->id==id)
      return actualNode->str;
    actualNode = actualNode->next;
  }
  return "no such id";
}


/*{
  int count, data= 0;
  Item* temp2 = list->root;

  if (temp2 == NULL)
    {
      printf("\n Error : List empty to search for data");
      return "empty";
    }
  printf("\n Enter value to search : ");
  scanf("%d", &data);
  while (temp2 != NULL)
    {
      if (temp2->id == data)
	{
	  printf("\n Data found in %d position", count + 1);
	  printf("\n");
	  return"id position";
	}
      else
	{
	  temp2 = temp2->next;
	}

      count++;
    }
  printf("\n Error : %d not found in list", data);
  printf("\n");
  }*/



void print_history(List *list)
{
  Item* root = list->root;
  while (root != NULL)
    {
      printf("id = %d string:%s", root->id, root->str);
      root = root->next;
    }
}


/*{
  while(list->root!=NULL)
    {
      printf("History ID:%d, Name:%s\n", list->root->id,list->root->str);
      list->root=list->root->next;
    }
    }*/


void free_history(List *list)
{
  free(list);
}


