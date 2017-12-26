#include "my.h"

void listnode_swap(resistor * a, resistor * b) {

    float temp = a->power;
    a->power = b->power;
    b->power = temp;

    double temp1 = a->admission;
    a->admission = b->admission;
    b->admission = temp1;

    int temp2 = a->resistance;
    a->resistance = b->resistance;
    b->resistance = temp2;

    char tmp[40];
    strcpy(tmp, a->name);
    strcpy(a->name,b->name);
    strcpy(b->name,tmp);
}
void listnode_qsortName(resistor * left, resistor * right) {
    if ( left == right ) return;
    else if ( left->next == right ) {
        if ( strcmp(left->name, right->name) > 0)
        listnode_swap(left, right);
    }
    else {
        resistor * last = left;
        resistor * current = left;

        do {
            current = current->next;

            if ( strcmp(current->name, left->name) < 0) {
                last = last->next;
                listnode_swap(last, current);
            }

        } while ( current != right );

        listnode_swap(left, last);

        listnode_qsortName(left, last);
        if ( last != right )
            listnode_qsortName(last->next, right);
    }
}
void listnode_qsortPower(resistor * left, resistor * right) {
    if ( left == right )
        return;
    else if ( left->next == right ) {
        if ( left->power > right->power )
            listnode_swap(left, right);
    }
    else {
        resistor * last = left;
        resistor * current = left;

        do {
            current = current->next;

            if ( current->power < left->power ) {
                last = last->next;
                listnode_swap(last, current);
            }

        } while ( current != right );

        listnode_swap(left, last);

        listnode_qsortPower(left, last);
        if ( last != right )
            listnode_qsortPower(last->next, right);
    }
}
void listnode_qsortResistance(resistor * left, resistor * right) {
    if ( left == right )
        return;
    else if ( left->next == right ) {
        if ( left->resistance > right->resistance )
            listnode_swap(left, right);
    }
    else {
        resistor * last = left;
        resistor * current = left;

        do {
            current = current->next;

            if ( current->resistance < left->resistance ) {
                last = last->next;
                listnode_swap(last, current);
            }

        } while ( current != right );

        listnode_swap(left, last);

        listnode_qsortResistance(left, last);
        if ( last != right )
            listnode_qsortResistance(last->next, right);
    }
}
void listnode_qsortAdmission(resistor * left, resistor * right) {
    if ( left == right )
        return;
    else if ( left->next == right ) {
        if ( left->admission > right->admission )
            listnode_swap(left, right);
    }
    else {
        resistor * last = left;
        resistor * current = left;

        do {
            current = current->next;

            if ( current->admission < left->admission ) {
                last = last->next;
                listnode_swap(last, current);
            }

        } while ( current != right );

        listnode_swap(left, last);

        listnode_qsortAdmission(left, last);
        if ( last != right )
            listnode_qsortAdmission(last->next, right);
    }
}

void quicksort(resistor * left, resistor * right) {
    int choice = 0;

     while(1) {
        printf("What do you want to sort?\n");
        printf("1.Name\n2.Power\n3.Resistance\n4.Admission\n");
        while(scanf("%d", &choice) != 1) {
            printf("Must be non-negative integer!\n");
            while(getchar() != '/n') continue;
        }
        if(choice < 1 || choice > 4){
            printf("The number can't be less than 1 and greater than 2\n");
            continue;
        }
        break;
    }
    switch(choice){
        case 1: {
            if ( left == right ) return;
            else if ( left->next == right ) {
                if (strcmp(left->name, right->name) > 0)
                listnode_swap(left, right);
            } else {
                resistor * last = left;
                resistor * current = left;
                do {
                    current = current->next;
                    if (strcmp(left->name, right->name) < 0) {
                        last = last->next;
                        listnode_swap(last, current);
                    }

                } while ( current != right );
                listnode_swap(left, last);
                listnode_qsortName(left, last);
                if ( last != right )
                    listnode_qsortName(last->next, right);
            }
            break;
        }
        case 2:{
            if ( left == right ) return;
            else if ( left->next == right ) {
            if ( left->power > right->power )
                listnode_swap(left, right);
            } else {
                resistor * last = left;
                resistor * current = left;
                do {
                    current = current->next;
                    if ( current->power < left->power ) {
                        last = last->next;
                        listnode_swap(last, current);
                    }

                } while ( current != right );
                    listnode_swap(left, last);
                listnode_qsortPower(left, last);
                if ( last != right )
                    listnode_qsortPower(last->next, right);
            }break;
        }
        case 3: {
            if ( left == right ) return;
            else if ( left->next == right ) {
            if ( left->resistance > right->resistance )
                listnode_swap(left, right);
            } else {
                resistor * last = left;
                resistor * current = left;
                do {
                    current = current->next;
                    if ( current->resistance < left->resistance ) {
                        last = last->next;
                        listnode_swap(last, current);
                    }

                } while ( current != right );
                    listnode_swap(left, last);
                    listnode_qsortResistance(left, last);
                    if ( last != right )
                        listnode_qsortResistance(last->next, right);
            }break;
        }
        case 4: {
          if ( left == right ) return;
          else if ( left->next == right ) {
            if ( left->admission > right->admission )
                listnode_swap(left, right);
        } else {
            resistor * last = left;
            resistor * current = left;
            do {
                current = current->next;
                if ( current->admission < left->admission ) {
                    last = last->next;
                    listnode_swap(last, current);
                }
            } while ( current != right );
                listnode_swap(left, last);
            listnode_qsortAdmission(left, last);
            if ( last != right )
                listnode_qsortAdmission(last->next, right);
        }break;
        }
    }
}
