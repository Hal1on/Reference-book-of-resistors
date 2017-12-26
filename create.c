#include "my.h"
DblLinkedList* createDblLinkedList() {
	DblLinkedList *tmp = (DblLinkedList*) malloc(sizeof(DblLinkedList));
	tmp -> size = 0;
	tmp -> head = tmp -> tail = NULL;
	return tmp;
}
