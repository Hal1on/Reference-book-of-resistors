#include "my.h"


void bubbleSort(DblLinkedList *list, char* fileName) {
    int swapped, i;
    resistor *courrent;
    resistor *nextLeft = NULL;

    if (courrent == NULL) return;

    do {
        swapped = 0;
        courrent = list -> head;

        while (courrent->next != nextLeft) {
            if (strcmp(courrent->name, courrent->next->name) > 0) {
            	swap(courrent,courrent->next);
                swapped = 1;
            }
            courrent = courrent -> next;
        }

        nextLeft = courrent;

    } while (swapped);
    save(list, fileName);
}

