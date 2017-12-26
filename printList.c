#include "my.h"
void printDblLinkedList(DblLinkedList *list, char* fileName) {
	read(list, fileName);
	int a1 = 124;
	int a2 = 45;
	int i = 0;
 	resistor *tmp = list->head;
    if(tmp == NULL) printf("Database is empty\n");
	printf("%c",a1);for(int a = 0; a < 103; a++)printf("%c",a2);printf("%c\n",a1);
	printf("%c\t№\t%c\tName\t%c\tPower(Vt)\t%c\tResistance(hOm)\t%c\tAdmission(%)\t%c\n",a1,a1,a1,a1,a1,a1,a1);
	printf("%c",a1);for(int a = 0; a < 103; a++)printf("%c",a2);printf("%c\n",a1);

	while (tmp) {
        printf("|%-15d",i++);
        printf("|%-15s",tmp->name);
        printf("|%-23f",tmp->power );
        printf("|%-23d",tmp->resistance);
        printf("|%-23lf|",tmp->admission);
        printf("\n%c",a1);for(int a = 0; a < 103; a++)printf("%c",a2);printf("%c\n",a1);
        tmp = tmp->next;
    }
    printf("\n\n");
}
