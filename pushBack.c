#include "my.h"

void pushBack(DblLinkedList *list, char* fileName) {
 	int stop = 2;
	while(stop == 2){
		resistor *tmp = (resistor*) malloc(sizeof(resistor));
		if (tmp == NULL) {
			break;
		}
		printf("Resistor %d:\n",list->size);
		printf("resistance: ");
		while (scanf("%d", &tmp->resistance) != 1) {
            printf("Incorrect value!\n");
            while(getchar() != '\n')continue;
            continue;
		}
		printf("name: ");
		while (scanf("%s",&tmp->name) != 1) {
            printf("Incorrect value!\n");
            while(getchar() != '\n')continue;
            continue;
		}
		printf("addmission: ");
		while (scanf("%lf", &tmp->admission) != 1) {
            printf("Incorrect value!\n");
            while(getchar() != '\n')continue;
            continue;
		}
		printf("power: ");
		while (scanf("%f", &tmp->power) != 1) {
            printf("Incorrect value!\n");
            while(getchar() != '\n')continue;
            continue;
		}
		tmp->next = NULL;
		tmp->prev = list->tail;
		if (list->tail) {
			list->tail->next = tmp;
		}
		list->tail = tmp;

		if (list->head == NULL) {
        list -> head = tmp;
		}
		list->size++;
		save(list, fileName);
		while(1) {
			printf("Do you want to stop ?(1-y, 2-n)");
			scanf("%d", &stop);
			while(getchar() != '\n'){
				continue;
			}
			if(stop==1 || stop==2){
				break;
			}else{
				printf("Wrong!\n");
				continue;
			}
		}
		printf("\n");
	}
}
