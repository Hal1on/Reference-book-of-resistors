resistor: deleteNth.o selectionSort.o bubbleSort.o getNth.o pop.o shellSort.o compare.o insert.o printList.o someRandomFunction.o insertionSort.o  pushBack.o swap.o main.o push.o update.o qsort.o create.o read.o write.o

	gcc deleteNth.o selectionSort.o bubbleSort.o getNth.o pop.o shellSort.o compare.o insert.o printList.o someRandomFunction.o insertionSort.o  pushBack.o swap.o main.o push.o update.o qsort.o create.o read.o write.o -o resistor
deleteNth.o: deleteNth.c my.h 
	gcc -c deleteNth.c
selectionSort.o: selectionSort.c my.h
	gcc -c selectionSort.c
bubbleSort.o: bubbleSort.c my.h
	gcc -c bubbleSort.c
getNth.o: getNth.c my.h
	gcc -c getNth.c
pop.o: pop.c my.h
	gcc -c pop.c
shellSort.o: shellSort.c my.h
	gcc -c shellSort.c
compare.o: compare.c my.h
	gcc -c compare.c
insert.o: insert.c my.h
	gcc -c insert.c
printList.o: printList.c my.h
	gcc -c printList.c
someRandomFunction.o: someRandomFunction.c my.h
	gcc -c someRandomFunction.c
insertionSort.o: insertionSort.c my.h
	gcc -c insertionSort.c
pushBack.o: pushBack.c my.h
	gcc -c pushBack.c
swap.o: swap.c my.h
	gcc -c swap.c
main.o: main.c my.h
	gcc -c main.c
push.o: push.c my.h
	gcc -c push.c
update.o: update.c my.h
	gcc -c update.c
qsort.o: qsort.c my.h
	gcc -c qsort.c 
create.o: create.c my.h
	gcc -c create.c
read.o: read.c my.h
	gcc -c read.c
write.o: write.c my.h
	gcc -c write.c




