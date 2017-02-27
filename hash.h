#ifndef HASH
#define HASH
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

struct Hash{
    size_t size;
    struct Entry **entries;
};

struct Entry{
    char *key;
    char *value;
    struct Entry *next;
};

struct Hash *createHash(size_t size);
int destroyHash(struct Hash *hash);
int insertEntry(char *key, char *value, struct Hash *hash);
int deleteEntry(char *key, struct Hash *hash);
char *lookUp(char *key, struct Hash *hash);
int printTable(struct Hash *hash);

#endif
