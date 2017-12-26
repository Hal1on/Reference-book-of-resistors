#include "my.h"
void sortedInsert1(resistor** head_ref, resistor* new_node) {
    resistor* current;
    if (*head_ref == NULL || strcmp((*head_ref)->name, new_node->name) >= 0) {
        new_node -> next = *head_ref;
        *head_ref = new_node;
    } else {
        current = *head_ref;
        while (current -> next!=NULL && strcmp(current->next->name, new_node->name) < 0) {
            current = current -> next;
        }
        new_node -> next = current->next;
        current -> next = new_node;
    }
}
void sortedInsert2(resistor** head_ref, resistor* new_node) {
    resistor* current;
    if (*head_ref == NULL || (*head_ref)->power >= new_node->power) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        current = *head_ref;
        while (current->next!=NULL && current->next -> power > new_node->power) {
            current = current -> next;
        }
        new_node -> next = current->next;
        current -> next = new_node;
    }
}
    void sortedInsert3(resistor** head_ref, resistor* new_node) {
    resistor* current;
    
    if (*head_ref == NULL || (*head_ref)->power <= new_node->power) {
        new_node -> next = *head_ref;
        *head_ref = new_node;
    } else {
       
        current = *head_ref;
        while (current->next!=NULL && current->next->power > new_node->power) {
            current = current->next;
        }
        new_node -> next = current->next;
        current -> next = new_node;
    }
}
void SortA(DblLinkedList *list, char* fileName) {
     resistor *head_ref = list->head;
   
    resistor *sorted = NULL;

   
    resistor *current = head_ref;
    while (current != NULL) {
       
        resistor *next = current->next;
        sortedInsert1(&sorted, current);

       
        current = next;
    }

 
    head_ref = sorted;
    save(list, fileName);
}
void SortB(DblLinkedList *list, char* fileName){
  resistor *head_ref = list->head;
   
    resistor *sorted = NULL;

   
    resistor *current = head_ref;
    while (current != NULL) {
        resistor *next = current->next;


     
        sortedInsert2(&sorted, current);

       
        current = next;
    }

    head_ref = sorted;
    save(list, fileName);

}
void SortC(DblLinkedList *list, char* fileName){
  resistor *head_ref = list->head;
    resistor *sorted = NULL;

    resistor *current = head_ref;
    while (current != NULL) {
        resistor *next = current->next;


        sortedInsert3(&sorted, current);

        current = next;
    }

    head_ref = sorted;
    save(list, fileName);

}


void insertionSort(DblLinkedList *list, char* fileName) {
    int choice = 0;

    while(1) {
        printf("1.Sort by name\n2.Sort by resistance (ascending)\n3.Sort by resistance (descending)\n");
        while(scanf("%d", &choice) != 1) {
            printf("Must be non-negative integer!\n");
            while(getchar() != '/n') continue;
        }
        if(choice < 1 || choice > 3){
            printf("The number can't be less than 1 and greater than 2\n");
            continue;
        }
        break;
    }
    switch(choice) {
            case 1: {
                SortA(list, fileName);
                break;
            } case 2: {
                SortB(list, fileName);
                break;

            } case 3: {
                SortC(list, fileName);
                break;
            }
    }
}

