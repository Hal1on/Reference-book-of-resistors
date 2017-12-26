#include "my.h"
void load(DblLinkedList *list, char* fileName){
    double N_prov, size;
    long long N, i;
	FILE *in = fopen(fileName, "rb");
	int countOfScanneredSymbols = 0;
	fseek(in, 0, SEEK_END);
	size = ftell(in);
	fseek(in, 0, SEEK_SET);
	N_prov = size/sizeof(resistor);
	N = N_prov;
	if(((double)N) != N_prov) {
        fclose(in);
        system("clear");
        printf("Data on file are not correct inputted!\n");
        return;
    }
    if (N == 0) {
        fclose(in);
        system("clear");
        printf("File is empty!\n");
        return;
    }
	for(int i = 1; i <= N; i++) {
        resistor *tmp = (resistor*) malloc(sizeof(resistor));
        fread(tmp, sizeof(resistor), 1, in);
        if (tmp == NULL) {
			break;
		}

		tmp -> next = list -> head;
        tmp -> prev = NULL;

        if (list -> head) {
            list -> head->prev = tmp;
        }
        list -> head = tmp;

        if (list -> tail == NULL) {
            list -> tail = tmp;
        }
        list -> size++;

    }

    fclose(in);
}
