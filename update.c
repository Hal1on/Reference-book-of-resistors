#include "my.h"
void insert1(DblLinkedList *list, size_t index) {
    resistor *elm = NULL;
    resistor *ins = NULL;
    elm = getNth(list, index);
    if (elm == NULL) {
        exit(5);
    }
    ins = (resistor*) malloc(sizeof(resistor));
    printf("Resistor %d:\n", index+1);
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
}

void deleteNth1(DblLinkedList *list, size_t index) {
    resistor *elm = NULL;

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
    index--;
    insert1(list, index);

}

void update(DblLinkedList *list, char* fileName) {
	int n = 0;
	printf("Enter number:");
	scanf("%d", &n);
	deleteNth1(list, n);
    save(list, fileName);
}
