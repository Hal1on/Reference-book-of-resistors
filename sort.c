#include "my.h"
int TypeOfSort() {
    int type = 0;
    printf("Choice type of Sort");
    while(scanf("%d", type) != 1) {
         printf("Incorrect value!\n");
            while(getchar() != '\n')continue;
            continue;
    }
    while(type < 1 || type > 4) {
        printf("Incorrect value!\n");
            while(getchar() != '\n')continue;
            continue;
    }
    return type;
}
void* typeOfData(DblLinkedList *list) {
    void* data = 0;
    int type = 0;
    printf("Choice type of Data for sorting");
    printf("1.name\n2.power\n3.resistance\n4.admission\n");
    while(scanf("%d", type) != 1) {
         printf("Incorrect value!\n");
            while(getchar() != '\n')continue;
            continue;
    }
    while(type < 1 || type > 4) {
        printf("Incorrect value!\n");
            while(getchar() != '\n')continue;
            continue;
    }

}

void startSort(DblLinkedList *list, char* fileName){
//    int type = typeOfSort();
    //void* data = typeOfData(list);

}
