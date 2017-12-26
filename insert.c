#include "my.h"

void insert(DblLinkedList *list, char *fileName) {
    int index;
	resistor *elm = NULL;
    resistor *ins = NULL;
    printf("Enter the index of element:");
    scanf("%d", &index);
    elm = getNth(list, index);
    if (elm == NULL) {
        exit(5);
    }
    ins = (resistor*) malloc(sizeof(resistor));
    printf("Resistor %d:\n", index);
    printf("resistance: ");
    scanf("%d", &ins->resistance);
    printf("name: ");
    scanf("%s", &ins->name);
    printf("addmission: ");
    scanf("%lf", &ins->admission);
    printf("power: ");
    scanf("%f", &ins->power);
    ins->prev = elm;
    ins->next = elm->next;
    if (elm->next) {
        elm->next->prev = ins;
    }
    elm->next = ins;

    if (!elm->prev) {
        list->head = elm;
    }
    if (!elm->next) {
        list->tail = elm;
    }

    list->size++;
    save(list, fileName);
}



