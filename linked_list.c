#include <stdlib.h>
#include <string.h>

#include "commons.h"
#include "linked_list.h"

void init_list(LinkedList* l) {
    l->start = NULL;
    l->finish = NULL;
    l->num_elements = 0;
}
//Funcio igual que l'anterior
void clear_list(LinkedList* l) {
    l->start = NULL;
    l->finish = NULL;
    l->num_elements = 0;
}

void insert_into_list(LinkedList* l, WordInfo wi) {
    //creem node auxiliar
    Node* aux;
    
    //encapsulem la informació
    if(encapsulate_info(&aux,l,wi)){
        //configurem la llista
        if(l->num_elements == 0){
            l->start = aux;
            l->finish = aux;
            l->start->next = NULL;
            l->start->prev = NULL;
            l->num_elements++;
        }else{
            aux->prev = l->finish;
            aux->next = NULL;
            l->finish->next = aux;
            l->finish = aux;
            l->num_elements++;
        
        }
        printf("\nNode creat correctament\n");
    }else{
        printf("\nError encapsulament\n");
    }

}
int encapsulate_info(Node** nod, LinkedList* list,WordInfo wi) {
    //guardamos la info
   
    int ret = TRUE;
    Node* node ;
    //solicitamos espacio
    node = (Node*) malloc(sizeof (Node));
    //copiamos info a la lista
    if (node != NULL) {
        strcpy(node->data.definition,wi.definition);
        node->data.pos = wi.pos;
        strcpy(node->data.word, wi.word);
    } else {
        ret = FALSE;
    }
        
    
    *nod = node;

    return (ret);
}

WordInfo* find_first_in_list(LinkedList* l, char* word) {
    
    
    return &(l->start->data);
}

int delete_from_list(LinkedList* l, char* word) {
    Node* aux = l->start;
    int cmp = strcmp(aux->data.word, word);
    if(cmp == 0){
        l->start = l->start->next;
        while(aux != NULL && cmp != 0){
            aux = aux->next;    
        }
        aux
    }
    return ERROR;
}

void print_list(LinkedList* l) {
    
Node* aux = l->start;
    if(l->num_elements != 0 ){
        while(aux != NULL){
            printf("--NODE--\nnom: %s\ndef: %s\ncat.gram: %c\n  ||  \n",aux->data.word,aux->data.definition,aux->data.pos);
            aux = aux->next;
        }
    }else{
        printf("--No hi ha elements--\n");
    }
}
