#include "my.h"

int cycle = 1;
int i = 1;
int main(int argc, char *argv[]) {
	char fileName[24];//name of database
	DblLinkedList *list = createDblLinkedList();
	if (argc == 1) {
        printf("Enter the filename with database: ");
        scanf("%s", fileName);
        while(getchar() != '\n') continue;
        load(list, fileName);
    } else if(argc > 2) {
           printf("Error!\n");
		    return 0;
	} else {
        strcpy(fileName, argv[1]);
        load(list, fileName);
	}
	while(cycle == 1) {    //start
        int a1 = 124;
        int a2 = 45;
        int mainNumber = 0;	//choice number of menu
        for(int i = 0; i < 56; i++)printf("%c",a2);printf("\n");
            printf("%c                    Reference resistor:               %c\n",a1,a1);
            printf("%c                                                      %c\n",a1,a1);
            printf("%c  1  - Make new data directory                        %c\n",a1,a1);
            printf("%c  2  - Print all                                      %c\n",a1,a1);
            printf("%c  3  - Append resistor                                %c\n",a1,a1);
            printf("%c  4  - Insert resistor                                %c\n",a1,a1);
            printf("%c  5  - Delete from data base                          %c\n",a1,a1);
            printf("%c  6  - Update some resistor                           %c\n",a1,a1);
            printf("%c  7  - Sorting a bubble over a field of a string type %c\n",a1,a1);
            printf("%c  8  - InsertionSort on a num and str field           %c\n",a1,a1);
            printf("%c  9  - Quick sort by any field                        %c\n",a1,a1);
            printf("%c  10 - Selection sort to an num (in the certain order)%c\n",a1,a1);
            printf("%c  11 - ShellSort an a numeric field (in any order).   %c\n",a1,a1);
            printf("%c  12 - Compression                                    %c\n",a1,a1);
            printf("%c  13 - Decompression                                  %c\n",a1,a1);
            printf("%c  0  - Exit                                           %c\n",a1,a1);

            for(int i = 0; i < 54; i++)printf("%c",a2);printf("\n");
            scanf("%d", &mainNumber);	//scan value for menu
            switch(mainNumber) {	 	//Enter menu
                case 1: {
                    makeNewDataDirectory(list, fileName);
                    break;
                } case 2: {				//print All
                    printDblLinkedList(list, fileName);           //с закрытым ключем
                    break;
                } case 3: {
                    pushBack(list, fileName);//add Resistor
                    break;
                } case 4: {
                    insert(list, fileName); //add Resistor n after Resistor n-1
                    break;
                } case 5: {
                    deleteNth(list, fileName); //delete some resistor
                    break;
                } case 6: {
                    update(list, fileName); //update some resistor
                    break;
                } case 7: {
                    bubbleSort(list, fileName); //realize bubble sort
                    break;
                } case 8: {
                    insertionSort(list, fileName);
                    break;
                } case 9 :{
                    quicksort(list->head, list -> tail);
                    break;
                } case 10 :{
                    sort1(list, fileName);
                    break;
                } case 11: {
                    ShellSort(list, fileName);
                    break;
                } case 12: {
                    compression(list);
                    break;
                } case 13: {
                   list->head = decompression(list);
                    break;
                } case 14: {
                    break;
                }   case 0: {
				//exit from menu change value of a variable "cycle" to 0;
                    cycle = 0;
                    break;
                } default: {
                    printf("Error!\n\n");//print an error,when input from keyboard are not correctly;
                    break;
                }
            }
    }
	return 0;
}
