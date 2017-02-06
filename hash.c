#incude "hash.h"

struct Entry **createHash(int size);

int destroyHash(Entry **hash);

int insertEntry(char *key, char *value);

int deleteEntry(char *key);

char *lookUp(char *key);
