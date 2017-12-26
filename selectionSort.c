#include "my.h"
void swapNodes(resistor** head_ref, resistor* currX, resistor* currY, resistor* prevY) {

    *head_ref = currY;
    prevY->next = currX;
    resistor* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}


resistor* selectionSort1(resistor *head) {
    if (head->next == NULL)
        return head;
    resistor* min = head;
    resistor* beforeMin = NULL;
    resistor* ptr;
    for (ptr = head; ptr->next != NULL; ptr = ptr->next) {

        if (ptr->next->power < min->power) {
            min = ptr->next;
            beforeMin = ptr;
        }
    }
    if (min != head)
        swapNodes(&head, head, min, beforeMin);

    head->next = selectionSort1(head->next);

    return head;
}resistor* selectionSort2(resistor *head) {
   
    if (head->next == NULL)
        return head;

    resistor* min = head;

    resistor* beforeMin = NULL;
    resistor* ptr;

    for (ptr = head; ptr->next != NULL; ptr = ptr->next) {
        if (ptr->next->power > min->power) {
            min = ptr->next;
            beforeMin = ptr;
        }
    }

    
    if (min != head)
        swapNodes(&head, head, min, beforeMin);

    head->next = selectionSort2(head->next);

    return head;
}


void sort1(DblLinkedList *list, char* fileName) {
 int choice = 0;
 resistor *head_ref = list->head;
   
    if ((head_ref) == NULL)
        return;
     while(1) {
        printf("1.Sorts in ascending order\n2.Sorts in descending order!\n");
        while(scanf("%d", &choice) != 1) {
            printf("Must be non-negative integer!\n");
            while(getchar() != '/n') continue;
        }
        if(choice < 1 || choice > 2){
            printf("The number can't be less than 1 and greater than 2\n");
            continue;
        }
        break;
    }

    switch(choice) {
        case 1: {
            head_ref = selectionSort1(head_ref);
            break;
        }
        case 2: {
            head_ref = selectionSort2(head_ref);

        }
    }



}
