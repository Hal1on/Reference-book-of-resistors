#include "my.h"

void remove1(resistor *head){

resistor *prev, *current;

prev=head;

while(prev!=NULL){

current=prev->next;

free(prev);

prev=current;

}

return;

}
