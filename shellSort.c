#include "my.h"

void ShellSort(DblLinkedList *list, char* fileName) {
int choice = 0;
 resistor *head_ref = list->head;
    // if list is empty
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
             if(list->head) {
        int step=0;
        int lenght=0;
        resistor *p = list->head;
        while(p) {
            lenght++;
            p=p->next;
        }
        while(2*(3*step+1) <= lenght) step=3*step+1;
        for(step; step>0 ;step/=3)
            for(int i=step;i>0;i--)
                for(int j=step-i; j<lenght; j+=step) {
                    p=list->head;
                    int k;
                    for(k=0;k<j;k++) p=p->next;
                    resistor* c=p;
                    int temp=k+step;
                    while(c) {
                        for(k;k<temp;)
                            if(c) {
                                k++;
                                c=c->next;
                            }
                            else break;
                            if(c)
                                if(p->resistance>c->resistance) {
                                    int t=p->resistance;
                                    p->resistance=c->resistance;
                                    c->resistance=t;
                                }
                                temp+=step;
                    }
                }
    }
    save(list, fileName);
    break;
}

         case 2: {
             if(list->head) {
        int step=0;
        int lenght=0;
        resistor *p = list->head;
        while(p) {
            lenght++;
            p=p->next;
        }
        while(2*(3*step+1) <= lenght) step=3*step+1;
        for(step; step>0 ;step/=3)
            for(int i=step;i>0;i--)
                for(int j=step-i; j<lenght; j+=step) {
                    p=list->head;
                    int k;
                    for(k=0;k<j;k++) p=p->next;
                    resistor* c=p;
                    int temp=k+step;
                    while(c) {
                        for(k;k<temp;)
                            if(c) {
                                k++;
                                c=c->next;
                            }
                            else break;
                            if(c)
                                if(p->resistance < c->resistance) {
                                    int t=p->resistance;
                                    p->resistance=c->resistance;
                                    c->resistance=t;
                                }
                                temp+=step;
                    }
                }
    }
    save(list, fileName);
    break;
}
}
}

