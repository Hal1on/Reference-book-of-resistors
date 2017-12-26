#include "my.h"
void deleteNth(DblLinkedList *list, char* fileName) {
    resistor *elm = NULL;
    int index = 0;

    printf("Enter the index of element:");
    scanf("%d", &index);
    elm = getNth(list, index);
    if (elm == NULL) {
        exit(5);
    }
    if (elm->prev) {
        elm->prev->next = elm->next;
    }
    if (elm->next) {
        elm->next->prev = elm->prev;
    }


    if (!elm->prev) {
        list->head = elm->next;
    }
    if (!elm->next) {
        list->tail = elm->prev;
    }

    free(elm);
    list->size--;
    save(list, fileName);
}
