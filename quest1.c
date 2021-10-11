// Código de implementação de uma lista ligada dinâmica(estrutura de dados "first in, first out")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura que armazenar a informação (INT) e o onteiro do próximo endereço da lista [caso seja o último da fila, endereço é NULL]
typedef struct element_list{
    int data;
    struct element_list *next_element;

}element;


/*
Lista de funções que operam na lista:
put: acrescenta um novo elemento no final da lista
get: imprime o dado da posição solicita
list: imprime a lista completa 
remove_element: remove o elemento da posição solicitada
clear: remove todos os elementos da lista
first: imprime o primeiro elemento da lista
last: imprime o últiimp elemento da lista
*/

void put(element *list_exist, int new_data){

    while (list_exist->next_element != NULL){
        list_exist = list_exist->next_element;
    }

    list_exist->next_element = (element*)malloc(sizeof(element));
    list_exist->next_element->data = new_data;
    list_exist->next_element->next_element = NULL;
    
}

void get(element *list_exist, int pos){
    int i;

    for (i=0; i!=pos; i++){
        list_exist = list_exist->next_element;
    }

    printf("%d\n", list_exist->data);

}

void list(element *list_exist){    
    element *print_element;
    print_element = list_exist->next_element;//Pula o elemento zero da lista

    while (print_element != NULL){
        printf("%d ",print_element->data);
        print_element = print_element->next_element;
    }
    printf("\n");
}

void remove_element(element *list_exist, int pos){
    int i;
    element *will_remove;

    for (i=0; i!=pos-1; i++){//Lógica: queremos obter o elemento anterior ao que iremos remover
        list_exist = list_exist->next_element;
    }
    will_remove = list_exist->next_element;

    list_exist->next_element = will_remove->next_element;

    free(will_remove);
}


void clear(element *list_exist){

    if (list_exist->next_element!=NULL){
        clear(list_exist->next_element);
    }
    free(list_exist);
}

void first(element *list_exist){

    printf("%d\n", list_exist->next_element->data);

}

void last(element *list_exist){
    
    while (list_exist->next_element != NULL){
        list_exist = list_exist->next_element;
    }
    printf("%d\n", list_exist->data);
}

//Responsável por interpretar as entradas do programa
void parsing(char* input, element *list_exist){
  char* parsing_string;

  parsing_string = strtok(input," ");

  if(strncmp(parsing_string, "get", 3) == 0) get(list_exist, atoi(strtok(NULL," ")));

  else if(strncmp(parsing_string, "put", 3) == 0) put(list_exist, atoi(strtok(NULL," ")));
 
  else if(strncmp(parsing_string, "list", 4) == 0) list(list_exist);

  else if(strncmp(parsing_string, "remove", 6) == 0) remove_element(list_exist, atoi(strtok(NULL," ")));

  else if(strncmp(parsing_string, "clear", 5) == 0) clear(list_exist);

  else if(strncmp(parsing_string, "first", 5) == 0) first(list_exist);

  else if(strncmp(parsing_string, "last", 4) == 0) last(list_exist);

  else printf("Erro\n");
}

int main(int argc, char *argv[]){
    char input[201];

    //Esta lista terá um elemento zero para ter manter a referência do início da lista
    element *list=(element*)malloc(sizeof(element_list));
    list->data = -1;
    list->next_element = NULL;

    while (1){
        
        printf ("prompt> ");
        if (fgets(input, 200, stdin)==NULL){
            printf("An error ocurred.\n");
            break;
        }

        if (strncmp(input, "exit\n", 5)==0){
            printf("Leaving. Good bye.\n");
            break;
        }

        parsing(input, list);
        }

    return EXIT_SUCCESS;
}