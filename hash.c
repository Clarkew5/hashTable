#include "hash.h"

struct Hash *createHash(size_t size){
    struct Hash *hash = malloc(sizeof(struct Hash));
    if (hash == NULL)
        return NULL;
    hash->size = size;
    hash->entries = calloc(size, sizeof(struct Entry*));
    if (hash->entries == NULL){
        printf("Calloc failed. No memory for hash.\n");
        return NULL;
    }

    for(int i = 0; i < size; i++){
        (*(hash->entries + i)) = malloc(sizeof(struct Entry));
        (*(hash->entries + i))->key = NULL;
        (*(hash->entries + i))->value = NULL;
        (*(hash->entries + i))->next = NULL;
    }

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

    if (p->key == NULL){ //no collision
        p->key = key;
        p->value = value;
        p->next = NULL;
    }
    else{//yes collision move to end of an linked list
        while(p->next != NULL)
            p = p->next;
        p->next = malloc(sizeof(struct Entry));
        if (p->next == NULL)
           return 1;
        p = p->next;
        p->key = key;
        p->value = value;
        p->next = NULL;
    }

    return 0;
}

int deleteEntry(char *key);

char *lookUp(char *key);

int printTable(struct Hash *hash){
    for (int i = 0; i < hash->size; i++){
        struct Entry *p = *(hash->entries + i);
        while(p != NULL){
            printf("%s: %s ->", p->key, p->value);
            p = p->next;
        }
        printf("No Entry\n");
    }
    return 0;
}
