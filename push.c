#include "my.h"
void makeNewDataDirectory(DblLinkedList *list, char* fileName) {
	int stop = 2;
	int i = 0;
	//
	int k, j;
	if(list->head != NULL) {
		while(1) {
			printf("You already have a database! Are you sure you want to overwrite it? \n1. remove database\n2. Continue add");
			while(scanf("%d", &k) != 1)
			{
				printf("Вводимое число должно быть целочисленным!\n");
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
				printf("Вводимое число не может быть меньше 1 и больше 2!\n");
				continue;
			}
		}
	}//
	pushBack(list, fileName);
}

