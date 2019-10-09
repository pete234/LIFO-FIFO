#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

struct element *initialise() {
    struct element *elem;

    if(!(elem = (struct element *) malloc(sizeof(struct element)))) {
        fprintf(stderr, "Error: Unable to allocate node memory");
        return 0;
    }
    
    elem->pData = elem->pNext = NULL;
    
    return elem;
}

void addLast(void * oTemp, struct element ** pHead, struct element ** pTail) {
    
    struct element *elem = initialise();
    
    if(*pTail)
        (*pTail)->pNext = elem;

    if(!*pHead) 
        *pHead = elem;
    
    *pTail = elem;
    
    elem->pData = oTemp;
    elem->pNext = NULL;
    
}

void addFirst(void * oTemp, struct element ** pHead, struct element ** pTail) {
    
    struct element *elem = initialise();
    
    if(*pHead) 
        elem->pNext = *pHead;

    else
        elem->pNext = NULL;
    
    if(!*pTail) 
        *pTail = elem;
    *pHead = elem;
    
    elem->pData = oTemp;
    
}

void * removeFirst(struct element ** pHead, struct element ** pTail) {
    
    if(!*pHead) {
        fprintf(stderr, "Error: No Head");
        return 0;
    }
    
    struct element *elem;
    
    elem = *pHead;
    
    *pHead = (*pHead)->pNext;
    
    if(!*pHead)
        *pTail = NULL;

    void *data = elem->pData; 
    free(elem);
    
    return data;
}