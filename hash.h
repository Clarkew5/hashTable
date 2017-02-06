#ifndef HASH
#define HASH
#include <stdlib.h>
#include <stdio.h>

struct Entry{
    char *key;
    char *value;
    struct Entry *next
};

struct Entry **createHash(int size);
int destroyHash(Entry **hash);
int insertEntry(char *key, char *value);
int deleteEntry(char *key);
char *lookUp(char *key);

#endif
