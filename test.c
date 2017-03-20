#include "hash.h"

int main(void){
    printf("making hash\n");
    struct Hash *hash = createHash(3);
    printf("made hash\n");

    printf("adding enteries\n");
    
    //twitch user thebossreturns
    insertEntry("parse", "to read data", hash);
    insertEntry("sleep", "to not be awake haha", hash);
    insertEntry("run", "walk really really fast", hash);
    
    //twitch user brookebyte
    insertEntry("muggle", "non magical being", hash);
    insertEntry("leer", "spanish to read", hash);
    insertEntry("escuchar", "spanis to listen", hash);
    
    insertEntry("muggle", "someone who doesn't know what geocaching is", hash);

    printf("added entries\n");

    printTable(hash);
    printf("\n%s: %s\n", "leer", lookUp("leer", hash));
    printf("%s: %s\n", "run", lookUp("run", hash));
    printf("%s: %s\n", "sleep", lookUp("sleep", hash));
    printf("%s: %s\n", "sadness", lookUp("sadness", hash));

    deleteEntry("leer", hash);
    deleteEntry("run", hash);
    printf("\n");
    printTable(hash);
    destroyHash(hash);
    return 0;
}
