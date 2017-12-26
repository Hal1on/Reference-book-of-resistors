#include "my.h"
resistor* getNth(DblLinkedList *list, size_t index) {
	resistor *tmp = list->head;
    size_t i = 0;

    while (tmp && i < index) {
        tmp = tmp->next;
        i++;
    }

    return tmp;
}
