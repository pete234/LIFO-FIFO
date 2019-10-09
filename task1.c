#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#define N 100

struct element *pHead;
struct element *pTail;

int main() {
    
    pHead = NULL;
    pTail = NULL;
    
    for(int i = 0; i < N;i++) {
        int *ptr = (int*) malloc(sizeof(int));
        *ptr = i;
        addLast((void *) ptr, &pHead, &pTail);
    }
    
    fprintf(stdout, "FIFO:\n");
    
    int k = 0;

    while(pHead)
    {
        void *value = removeFirst(&pHead, &pTail);
        fprintf(stdout, "Element %d = %d\n",++k, *((int*) value));
        free(value);
    }

    for(int i = 0; i < N; i++) {
        int *ptr = (int*) malloc(sizeof(int)); //Created so it can be casted to a Void pointer
        *ptr = i;
        addFirst((void *) ptr, &pHead, &pTail);
    }

    k = 0; // Reinstalised to 0 as it is being used for the second loop

    fprintf(stdout, "LIFO:\n");

    while(pHead)
    {
        void *value = removeFirst(&pHead, &pTail);
        fprintf(stdout, "Element %d = %d\n",++k, *((int*) value));
        free(value);
    }
}