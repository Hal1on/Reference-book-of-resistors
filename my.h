#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
typedef struct resistor {
	char name[40];
	float power;
	int resistance;
	double admission;
	struct resistor *next;
	struct resistor *prev;
} resistor;
typedef struct _DblLinkedList {
	size_t size;
	resistor *head;
	resistor *tail;
}DblLinkedList;
resistor* decompression(DblLinkedList *list);
void compression(DblLinkedList *list);
void pushBack(DblLinkedList *list, char* fileName);
void load(DblLinkedList *list, char* fileName);
void sort1(DblLinkedList *list, char* fileName);
resistor* selectionSort(resistor *head);
void ShellSort(DblLinkedList *list, char* fileName);
void save(DblLinkedList *list, char* fileName);
void deleteNth1(DblLinkedList *list, size_t index);
void update(DblLinkedList *list, char* fileName);
resistor* getNth(DblLinkedList *list, size_t index);
int pointer_compare(void *location1, void *location2);
void bubbleSort(DblLinkedList *list, char* fileName);
void insertionSort(DblLinkedList *list, char* fileName);
void* popFront(DblLinkedList *list);
void makeNewDataDirectory(DblLinkedList *list, char* fileName);
DblLinkedList* createDblLinkedList();
void removeList(DblLinkedList **list, char* fileName);
void insert(DblLinkedList *list, char *fileName);
void deleteNth(DblLinkedList *list, char* fileName);
void pop(resistor **head);
void printDblLinkedList(DblLinkedList *list, char* fileName);
void fastRandom(DblLinkedList *list, char* fileName);
void quicksort(resistor * left, resistor * right);
void swap(resistor *a, resistor *b);
void remove1(resistor *head);
