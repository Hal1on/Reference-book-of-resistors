#include "my.h"

void save(DblLinkedList *list, char* fileName){

  FILE *out = fopen(fileName,"wb");
  resistor* tmp = list->head;
  while (tmp) {
    fwrite(tmp, sizeof(resistor), 1, out);
    tmp = tmp->next;
    printf("Serialization was succsess!\n");
  }
    fclose(out);
}
