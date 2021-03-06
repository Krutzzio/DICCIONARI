#include <stdio.h>
#include <string.h>

#include "word_info.h"

void create_word_info(WordInfo* wi, char* word, char* definition, char pos) {
    strcpy(wi->word, word);
    strcpy(wi->definition, definition);
    wi->pos = pos;
}

char* get_word(WordInfo* wi) {
    return &(wi->word);
}

void print_word_info(WordInfo wi) {
        printf("-> %s (%c): %s\n",wi.word, wi.pos, wi.definition);
       
}