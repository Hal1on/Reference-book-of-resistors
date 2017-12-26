#include "my.h"
void fastRandom(DblLinkedList *list, char* fileName) {
	int i = 0;
		while(i<15){
			i++;
			resistor *tmp = (resistor*) malloc(sizeof(resistor));
			if (tmp == NULL) {
	        exit(3);
			}
			strcpy (tmp->name, "rezizstor");
			tmp->admission = rand() % 100;
			tmp->power = rand() % 1000;
			tmp->resistance = rand() % 10000;
			tmp->next = NULL;
			tmp->prev = list->tail;
			if (list->tail) {
				list->tail->next = tmp;
			}
			list->tail = tmp;

			if (list->head == NULL) {
	        list->head = tmp;
			}
			list->size++;
			save(list, fileName);
			printf("\n");
		}
}
