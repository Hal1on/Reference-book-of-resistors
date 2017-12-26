#include "my.h"
void removeList(DblLinkedList **list, char* fileName) {
    resistor *tmp = (*list)->head;
    resistor *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) == createDblLinkedList();
}
