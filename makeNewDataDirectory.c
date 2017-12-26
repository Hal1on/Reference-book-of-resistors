#include "my.h"
void makeNewDataDirectory(DblLinkedList *list, char* fileName) {
	int k;
	if(list->head != NULL) {
		while(1) {
			printf("You already have a database! Are you sure you want to overwrite it? \n1. remove database\n2. Continue add");
			while(scanf("%d", &k) != 1)
			{
				printf("Must be non-negative integer!\n");
				while(getchar() != '/n') continue;
			}
			if(k == 1)
			{
				removeList(&list, fileName);
				break;
			}
			else if(k == 2){ break; }
			else
			{
				printf("The number can't be less than 1 and greater than 2\n");
				continue;
			}
		}
	}
	pushBack(list, fileName);
}

