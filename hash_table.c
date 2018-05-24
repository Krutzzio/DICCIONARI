#include <stdio.h>
#include <stdlib.h>

#include "hash_table.h"
#include "sort.h"

int hash_function(char* word) {
    int num = word[0] - 'a';
    return num;
}

void init_table(HashTable* table) {
    
    for (int i = 0; i < N; i++) {
        init_list(&table->list[i]);
        table->size = 0;
    }
}

void clear_table(HashTable* table) {
    for (int i = 0; i < N; i++) {
        clear_list(&table->list[i]);
        table->size = 0;
    }
}

int size(HashTable* table) {
    return &(table->size);
}

bool insert_word_info(HashTable* table, WordInfo wi) {
    int HashNum = hash_function(wi.word);
    int count ;
    
   
    insert_into_list(&table->list[HashNum], wi);
    
    if (exists_word(table, wi.word)) { 
        
        return TRUE;
    } else {
        
        return FALSE;
    }
}

bool exists_word(HashTable* table, char* word) {
    int HashNum = hash_function(word);
    Node* aux = table->list[HashNum].start;
    
    while (aux != NULL) {
        int comp = strcmp(word, aux->data.word);
        if (comp == 0) {
            
            return TRUE;
        }
        aux = aux->next;
    }

    return FALSE;
}

bool delete_word(HashTable* table, char* word) {
    return FALSE;
}

WordInfo* find_word(HashTable* table, char* word) {
    int HashNum = hash_function(word);
    Node* aux = table->list[HashNum].start;
    while (aux != NULL) {
        int comp = strcmp(word, aux->data.word);
        if (comp == 0) {
            return &(aux->data);
        }
        aux = aux->next;
    }
}

void print_sorted_word_info(HashTable* table) {
    char c;
    for (int i = 0; i < N; i++) {
        c = 97 + i;
        printf("List %d :'%c'\n", i, c);
        print_list(&table->list[i]);
    }
}