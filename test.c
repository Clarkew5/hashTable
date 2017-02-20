#include "hash.h"

int main(void){
    printf("making hash\n");
    struct Hash *hash = createHash(7);
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
    
    printf("added entries\n");

    printTable(hash);

    return 0;
}
