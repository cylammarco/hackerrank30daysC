#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int n;
    scanf("%i", &n);

    
    /* copied from https://stackoverflow.com/questions/4384359/quick-way-to-implement-dictionary-in-c */
    
    struct nlist { /* table entry: */
        struct nlist *next; /* next entry in chain */
        char *name; /* defined name */
        long int *defn; /* replacement text */
    };

    #define HASHSIZE 101
    static struct nlist *hashtab[HASHSIZE]; /* pointer table */

    /* hash: form hash value for string s */
    unsigned hash(char *s)
    {
        unsigned hashval;
        for (hashval = 0; *s != '\0'; s++)
          hashval = *s + 31 * hashval;
        return hashval % HASHSIZE;
    }

    /* lookup: look for s in hashtab */
    struct nlist *lookup(char *s)
    {
        struct nlist *np;
        for (np = hashtab[hash(s)]; np != NULL; np = np->next)
            if (strcmp(s, np->name) == 0)
              return np; /* found */
        return NULL; /* not found */
    }

    char *strdup(char *);
    long int *strdupli(long int *);

    /* install: put (name, defn) in hashtab */
    struct nlist *install(char *name, long int *defn)
    {
        struct nlist *np;
        unsigned hashval;
        if ((np = lookup(name)) == NULL) { /* not found */
            np = (struct nlist *) malloc(sizeof(*np));
            if (np == NULL || (np->name = strdup(name)) == NULL)
              return NULL;
            hashval = hash(name);
            np->next = hashtab[hashval];
            hashtab[hashval] = np;
        } else /* already there */
            free((void *) np->defn); /*free previous defn */
        if ((np->defn = strdupli(defn)) == NULL)
           return NULL;
        return np;
    }
    
    /* copied up to here */    
    
    for (int i=0; i<n; ++i) {
        char firstname[1000];
        long int idnumber;
        
        scanf("%s %li\n", firstname, &idnumber);   
        install(firstname, &idnumber);
    }


     for (int i=0; i<n; ++i) {
        char query[1000];
        scanf("%s\n", query);
        long int output = lookup(query);
        printf("%s=%li\n", query, output);
         
    }
   
    return 0;
}
