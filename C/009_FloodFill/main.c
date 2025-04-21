#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct MyObject {
    //data in this struct will be change according to exercise
    size_t row;
    size_t column;
} Object;

typedef struct MyNode {
    Object* obj;
    struct MyNode* next;
} Node;

struct MyQueue {
    size_t size;
    Node* head;
    Node* tail;
};

typedef struct MyQueue Queue;

static Queue* InitQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->size = 0;
    newQueue->head = NULL;
    newQueue->tail = NULL;
    return newQueue;
}

void Qpush(Queue* s, Object* obj) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->obj = obj;
    newNode->next = NULL;
    if (s->size == 0) {
        s->head = newNode;
        s->tail = s->head;
    }
    else {
        s->tail->next = newNode;
        s->tail = newNode;
    }
    s->size += 1;
}

void Qpop(Queue* s) {
    Node *temp = NULL;
    if (s->head->next != NULL) {
        temp = s->head;
        s->head = temp->next;
    }
    else { //end
        temp = s->head;
        s->head = NULL;
        s->tail = NULL;
    }
    free(temp);
    s->size -= 1;
}

static Object* Qtop(Queue* s) {
    return s->head->obj;
}

bool checkPosition(int row, int column, size_t rowSize, size_t columnSize) {
    if (row < 0) return false;
    if (column < 0) return false;
    if (row >= rowSize) return false;
    if (column >= columnSize) return false;
    return true;
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    size_t i = 0, j = 0, z = 0;
    int **result;
    int rowDelta[4] = {0, -1, 0, 1};
    int colDelta[4] = {-1, 0, 1, 0};
    bool* filled = (bool*)malloc((*imageColSize)*imageSize*sizeof(bool));
    memset(filled, 0, (*imageColSize)*imageSize*sizeof(bool));

    *returnSize = imageSize;
    *returnColumnSizes = (int*)malloc(imageSize*sizeof(int));
    for (i=0; i<imageSize; i++) {
        *((*returnColumnSizes)+i) = imageColSize[i];
    }

    result = (int**)malloc((*returnSize)*sizeof(int*));
    for (i=0; i<imageSize; i++) {
        result[i] = (int*)malloc((*(*returnColumnSizes))*sizeof(int));
        for (j=0; j<(*imageColSize); j++) {
            *(*(result+i)+j) = *(*(image+i)+j);
        }
    }

    Queue* myQueue = InitQueue();

    Object* obj = (Object*)malloc(sizeof(Object));
    obj->row = sr;
    obj->column = sc;
    Qpush(myQueue, obj);

    while (myQueue->size != 0) {
        i = Qtop(myQueue)->row;
        j = Qtop(myQueue)->column;
        result[i][j] = color;
        filled[i*(*imageColSize)+j] = true; //a[i][j] to 1D array => a[i*cols+j] 
        for (z=0; z<4; z++) {
            if (checkPosition(i+rowDelta[z], j+colDelta[z], imageSize, (*imageColSize))) {
                if (filled[(i+rowDelta[z])*(*imageColSize)+(j+colDelta[z])] == false) {
                    if (image[i][j] == image[i+rowDelta[z]][j+colDelta[z]]) {
                        Object* obj = (Object*)malloc(sizeof(Object));
                        obj->row = i+rowDelta[z];
                        obj->column = j+colDelta[z];
                        Qpush(myQueue, obj);
                    }
                }
            }
        }
        free(Qtop(myQueue));
        Qpop(myQueue);
    }
    free(filled);
    return result;
}

void printImage(int** image, int imageSize, int* imageColSize) {
    size_t i=0,j=0;
    //size_t imageRowSize = imageSize/(*imageColSize);
    for (i=0; i<imageSize; i++) {
        for (j=0; j<(*imageColSize); j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[3][3] = {{1,1,1}, {1,1,0}, {1,0,1}};
    size_t i=0,j=0;
    int size = 3;
    int** ptr;
    int* colSize;
    int returnSize;

    ptr = (int**)malloc(3*sizeof(int*));
    for (i=0; i<3; i++) {
        *(ptr+i) = (int*)malloc(size*sizeof(int));
        for (j=0; j<size; j++) {
            *(*(ptr+i)+j) = a[i][j];
        }
    }

    ptr = floodFill(ptr, size, &size, 1, 1, 2, &returnSize, &colSize);

    printImage(ptr, returnSize, colSize);

    free(colSize);
    free(ptr);

    return 0;
}