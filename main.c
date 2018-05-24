#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include "file_utils.h"
#include "main.h"

int main(int argc, char *argv[]) {

    int x = 0;
    printf("\t--DICCIONARIO--\n");


    while (x != -1) {
        printf("Seleccione la opcion que desee realizar:\n"); //Menu del diccionario
        printf("1-Agregar palabras al diccionario\n2-Busqueda de palabra\n"
                "3-Imprimir el diccionario\n(-1)-Salir del prgrama\n");
        scanf("%d", &x);

        switch (x) {
            case 1:

                printf("Loading file info...\n");
                WordInfo info_list[MAX_LINES];
                int info_size = read_info_file(INFO_FILE_PATH, info_list);
                printf("File info loaded!\n");
                sort(&info_list, info_size);
                HashTable dict;
                init_table(&dict);

                int i;
                for (i = 0; i < info_size; i++) {

                    if (!exists_word(&dict, info_list[i].word)) {
                        print_word_info(info_list[i]);

                        insert_word_info(&dict, info_list[i]);
                    }
                }
                printf("Dictionary loaded!\n");
                break;

            case 2:
                printf("\nSearch from query list\n\n");
                char* query_list[MAX_LINES];
                int query_size = read_query_file(QUERY_FILE_PATH, query_list);

                int j;
                for (j = 0; j < query_size; j++) {
                    printf("%s\n", query_list[j]);
                    WordInfo* wi = find_word(&dict, query_list[j]);
                    if (wi == NULL) {
                        printf("XX %s (Not found!)\n", query_list[j]);
                    } else {
                        print_word_info(*wi);
                    }
                }
                break;

            case 3:
                printf("\nPrint sorted dictionary data\n\n");
                print_sorted_word_info(&dict);

                printf("\nDone!\n");

                break;
            default:
                x = ERROR;
                break;


        }
    }

}