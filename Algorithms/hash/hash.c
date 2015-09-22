#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define HASHSIZE 10

typedef struct {
    int * array;

} hashTable;


//输入的key 不可以为负值
int getHashKey(int key) {
    int index = key % HASHSIZE;

    if(index < 0 || index >= HASHSIZE) {
        fprintf(stderr, "[getHashKey] index error");
    }
    return index;
}

int hashInit(hashTable *h){
    h->array = (int *)malloc(sizeof(int)*HASHSIZE);
    if(NULL == h->array) {
        fprintf(stderr, "[hashInit] malloc failed\n");
        return FALSE;
    }
    memset(h->array, 0, sizeof(int)*HASHSIZE);
    return TRUE;
}

int addHash(hashTable *h, int key, int value){
    int index = getHashKey(key);
    *(h->array + index) = value;
    return value;
}

// 如果不存在该key 则返回0
int findHash(hashTable *h, int key){
    int index = getHashKey(key);
    return *(h->array + index);
}

int deleteHash(hashTable *h, int key){
    int index = getHashKey(key);
    *(h->array + index) = 0;
    return TRUE;
}

int main() {
    hashTable ht;
    asserthashInit(&ht);
    addHash(&ht, 816, 620);
    int v = findHash(&ht, 816);
    printf("%d\n", v);
}
