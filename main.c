#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Perso{
    char name[20];
    int lvl;
    struct Perso* previous;
    struct Perso* next;
};

void ajouterElement(struct Perso** list, char name[20],int lvl){
    struct Perso *tmp = malloc(sizeof(struct Perso));
    if(tmp == NULL){exit(0);}
    strcpy(tmp->name,name);
    tmp->lvl = lvl;

    if(*list == NULL){
        tmp->next = NULL;
        tmp->previous =NULL;
    }
    else{
        (*list)->next = tmp;
        tmp->previous = *list;
    }
    *list = tmp;
}
void SuppElement(struct Perso *List, char name[20]){
    while(List->previous != NULL){
        List = List->previous;
        if(strcmp(List->name, name) == 0){
            (List->next)->previous = List->previous;
            (List->previous)->next = List->next;
            
        }
    }
}
void afficherList(struct Perso* i){
    while(i != NULL){
        printf("%s - %d - %p||%p   (%p)\n",i->name,i->lvl,i->previous,i->next,i);
        i = i->previous;
    }
}

int main(){
    struct Perso *first = NULL;

    ajouterElement(&first,"tic1",32);
    ajouterElement(&first,"tic2",32);
    ajouterElement(&first,"tic3",32);
    ajouterElement(&first,"tic3",32);
    ajouterElement(&first,"tic4",32);
    ajouterElement(&first,"tic5",32);
    ajouterElement(&first,"tic6",32);
    ajouterElement(&first,"tic7",32);
    afficherList(first);

 
    
    printf("\n");
    SuppElement(first,"tic3");
    afficherList(first);
    
    return 0;
}
