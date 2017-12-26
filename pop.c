#include "my.h"
void pop(resistor **head) {
	resistor* prev = NULL;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    (*head) = (*head) -> next;
    free(prev);
}
