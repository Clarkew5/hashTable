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

    return hash;
}

int destroyHash(struct Hash *hash){
    struct Entry *p;
    struct Entry *pPrev;
    for (size_t i = 0; i < hash->size; i++){
        pPrev = *(hash->entries + i);
        if (pPrev == NULL){
            free(pPrev);
            continue;
        }
        p = pPrev->next;
        while (p != NULL){
            free(pPrev);
            pPrev = p;
            p = p->next;
        }
        free(pPrev);
        free(p);
    }
    free(hash->entries);
    free(hash);
    return 0;
}

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

    if (p == NULL){//no collision
        p = malloc(sizeof(struct Entry));
        p->key = key;
        p->value = value;
        p->next = NULL;
        (*(hash->entries + index)) = p;
    }
    else{//collision
        while(p->next != NULL){
            if (strcmp(p->key, key) == 0){
                printf("Key already exists. Nothing changed.\n");
                return 1;
            }
            p = p->next;
        }
        if (strcmp(p->key, key) == 0){
            printf("Key already exists. Nothing changed.\n");
            return 1;
        }
        p->next = malloc(sizeof(struct Entry));
        p = p->next;
        p->key = key;
        p->value = value;
    }
    return 0;
}

int deleteEntry(char *key, struct Hash *hash){
    int index = hashFunction(key, hash);
    struct Entry *p = *(hash->entries + index);
    if (p == NULL){ //no value at index
        printf("No entry by that key\n");
        return 1;
    }
    else if (strcmp(p->key, key) == 0){//no colission
        *(hash->entries + index) = p->next;
        free(p);
        return 0;
    }
    else{ //collision
        struct Entry *pPrev = *(hash->entries + index);
        p = p->next;
        while (p != NULL){
            if (strcmp(p->key, key) == 0){
                pPrev->next = p->next;
                free(p);
                return 0;
            }
            p = p->next;
        }
    }
    printf("No entry by that key\n");
    return 0;
}

char *lookUp(char *key, struct Hash *hash){
    int index = hashFunction(key, hash);
    struct Entry *p = *(hash->entries + index);
    if (p == NULL) //no value at index
        return "No entry by that key\n";
    else if (strcmp(p->key, key) == 0)//no colission
        return p->value;
    else{ //collision
        while (p != NULL){
            if (strcmp(p->key, key) == 0)
                return p->value;
            p = p->next;
        }
    }
    return "No entry by that key\n";
}

int printTable(struct Hash *hash){
    for (int i = 0; i < hash->size; i++){
        struct Entry *p = *(hash->entries + i);
        while(p != NULL){
            printf("[%s]:[%s]->", p->key, p->value);
            p = p->next;
        }
        printf("No Entry\n");
    }
    return 0;
}
