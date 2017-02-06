#include "hash.h"

struct Hash *createHash(size_t size){
    struct Hash *hash = malloc(sizeof(struct Hash));
    if (hash == NULL)
        return NULL;
    hash->size = 0;
    hash->entries = calloc(size, sizeof(struct Entry*));    
    return hash;
}

/*int destroyHash(size_t size, struct Hash *hash){
    Entry *p = NULL;
    for (size_t i = 0; i < size; i++){
        p = *(hash->entries + i);
        while (p != NULL){
            free(p->)
        }
    }
    return 0;
}*/

int hashFunction(char *key, struct Hash *hash){
    unsigned int index = 0;
    uint64_t stringbit = 0L;
    while(*key != '\0'){
        stringbit |= *key;
        key++;
        stringbit <<= 8;
    }
    index = stringbit % hash->size;
    return index;
}

int insertEntry(char *key, char *value, struct Hash *hash){
    int index = hashFunction(key, hash);
    struct Entry *p = *(hash->entries + index);
    if(p == NULL){ //no collision
        p = malloc(sizeof(struct Entry));
        p->key = key;
        p->value = value;
        p->next = NULL;
    }
    else{ //yes collision
        while(p != NULL)
            p = p->next;
        p = malloc(sizeof(struct Entry));
        p->key = key;
        p->value = value;
        p->next = NULL;
    }
    return 0;
}

int deleteEntry(char *key);

char *lookUp(char *key);
