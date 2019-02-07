/*
CRETED BY:  
          Kevin Alejandro Ruvalcaba Perez    A01652241
          Jorge Germán Reyes García          A01336637
          Yair Yolotl Pimentel Vanegas       A01652823 


*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct node {
    int age;
    char * name;
    struct node *next;
};
typedef struct node node_t;

//add a node ot the list 
void add(int age, char *name, node_t **theList) {
  node_t *newS = (node_t *) malloc(sizeof(node_t));
  newS -> age = age;
  newS -> name = name; 
  newS -> next = NULL;
  if(*theList == NULL){
    *theList = newS;
  }
  else{
    node_t *temp = *theList;
    while(temp-> next != NULL){
      temp = temp-> next;
    }
    temp->next = newS;
  }
}
//metodo para imprimir los elementos de la lista encadenada
void print(node_t *pointerToList) {
  node_t *temp = pointerToList;
  printf("[ ");
  while(temp !=NULL){
    printf(" %d , %s  -->", temp->age, temp->name);
    temp = temp->next;
  }
  printf(" ]\n");
}

//Añadir un nodo al inicio de la lista
void addFirst(int age, char* name, node_t** theList){
  
  if(*theList == NULL){
    add(age, name, &(*theList));
  }else{
    node_t* newS = (node_t*)malloc(sizeof(node_t));

    newS ->age = age;
    newS ->name = name;
    newS ->next = *theList;

    *theList = newS;

  }

}

//Metodo para conseguir el tamaño de la lista
int getSize(node_t* pointerToList){
  node_t* temp = pointerToList;
  int counter = 0;
  while(temp != NULL){
    counter = counter +1;
    
    temp = temp->next;
  }

  return counter;

}

//Metodo para conseguir un nodo de la lista con la posicion
node_t *getItem(int position, node_t** list){
  int counter = 1;
  node_t* current = NULL; 
  if(position > getSize(*list)){
    printf("Position is bigger than size");
    return current;
  }else{
    current = *list;
    while(*list != NULL){
      while(counter != position){
        current = current->next;
        counter = counter +1;
      }
      //printf("Item at %dth position: %d, %s \n", position,current->age, current->name);
      return current;
    }
  }
}


//Liberar la memoria de la lista
void clearList(node_t **theList){
  if(*theList == NULL)return;
  node_t *temp = *theList;
  node_t *holder;

  while(temp != NULL){
    holder = temp;
    temp = temp->next;
    free(holder);
  }

  *theList = NULL;

}

//Remueve el primer nodo de la lista
void removeFirst(node_t **theList){
  if(*theList != NULL){
    node_t *temp = *theList;
    *theList = temp->next;
    free(temp);
  }
}
//Remueve el ultimo nodo de la lista
void removeLast(node_t **theList){
  if(*theList == NULL)return;
  node_t *temp = *theList;
  if(temp->next == NULL){
    removeFirst(&(*theList));
    return;
  }
  while(temp->next->next != NULL){
    temp = temp->next; 
  }
  node_t *holder = temp->next;
  temp->next = NULL;
  free(holder);

}
//Remueve el nodo dada la posicion
void removeInPos(int pos, node_t **theList){
  if(pos < 1)return;
  if(pos == 1){
    removeFirst(&(*theList));
    return;
  }
  int counter = 2;
  node_t *prev = *theList;
  node_t *temp = prev->next;
  node_t *next = temp->next;
  while(counter != pos){
    prev = prev->next;
    temp = temp->next;
    if(temp == NULL)return;
    next = next -> next;
    counter++;
  }
  prev->next = next;
  free(temp);
}


int main(void) {
  node_t * list = NULL;
  printf("=========================== \n");
  printf("THIS IS A TEST FOR ADDING AND ITERATING OVER THE LIST\n");
  print(list);
  add(5, "bono", &list);
  add(10,"pepe", &list);
  print(list);
  removeFirst(&list);
  print(list);
  removeFirst(&list);
  print(list);
  removeFirst(&list);
  print(list);
  printf("=========================== \n");
  printf("THIS IS A TEST FOR ADDING ELEMENTS AT THE START OF THE LIST\n");
  print(list);
  addFirst(5, "bono", &list);
  print(list);
  addFirst(10,"pepe", &list);
  print(list);
  removeFirst(&list);
  removeFirst(&list);
  printf("=========================== \n");
  printf("THIS IS A TEST FOR REMOVING THE LAST ITEM OF THE LIST \n");
  add(5, "bono", &list);
  add(10,"pepe", &list);
  print(list);
  removeLast(&list);
  print(list);
  removeLast(&list);
  print(list);
  removeLast(&list);
  print(list);
  printf("=========================== \n");
  printf("THIS IS A TEST FOR REMOVING THE FIRST ITEM OF THE LIST \n");
  add(5, "bono", &list);
  add(10,"pepe", &list);
  print(list);
  removeFirst(&list);
  print(list);
  removeFirst(&list);
  print(list);
  removeFirst(&list);
  print(list);
  printf("=========================== \n");
  printf("THIS IS A TEST FOR REMOVING AN SPECIFIC ITEM OF THE LIST \n");
  add(5, "bono", &list);
  add(10,"pepe", &list);
  add(320,"gonzalo", &list);
  add(1111, "Marcos", &list);
  removeInPos(-1, &list);
  removeInPos(6, &list);
  print(list);
  removeInPos(3, &list);
  print(list);
  removeInPos(1, &list);
  print(list);
  removeInPos(2, &list);
  print(list);
  removeInPos(1, &list);
  print(list);
  printf("=========================== \n");
  printf("THIS IS A TEST FOR GETTING THE SIZE OF THE LIST \n");
  add(5, "bono", &list);
  add(10,"pepe", &list);
  add(320,"gonzalo", &list);
  add(1111, "Marcos", &list);
  print(list);
  printf("The size of the list is: %d\n", getSize(list));
  printf("=========================== \n");
  printf("THIS IS A TEST FOR GETTING AN ELEMENT OF THE LIST \n");
  print(list);
  node_t *temp = getItem(2, &list);
  printf("The info of the element in position %d is name: %s , age: %d\n", 2, temp->name, temp->age);

  printf("=========================== \n");
  printf("THIS IS A TEST FOR CLEARING THE LIST THE LIST \n");
  print(list);
  clearList(&list);
  print(list);
  clearList(&list);
  print(list);

  return 0;
}