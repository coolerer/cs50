// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <strings.h>
#include <stdint.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
void free_node(node *a);
// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
int sum=0;
// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int a=hash(word);
    node *tmp=table[a];



    while(true){
        // printf("%s","l");
        if(tmp==NULL){

            return false;
        }
            // printf("%s",table[a]->word);

            if(strcasecmp(tmp->word,word)==0){
            // break;
            return true;}
            tmp=tmp->next;
        }

    // TODO
    return false;


}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    string word=malloc(LENGTH + 1);
    // printf("%s","aa");
    FILE *d = fopen(dictionary, "r");
    // strcmp(fscanf(d,"%s",word),"EOF");
    // int c=fscanf(d,"%s",word);


    while (fscanf(d,"%s",word) == 1){
        node *n=malloc(sizeof(node));
        int a=hash(word);
        strcpy(n->word,word);
        if(table[a]==NULL){
            n->next=NULL;
            table[a]=n;
        }else{
            n->next=table[a];
            table[a]=n;
        }
        sum++;
        // table[a]->next=n;
        // n->next=NULL;

    }

    // free(n);

    fclose(d);
    free(word);
    // TODO
    return true;
}




// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{



    // TODO
    return sum;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // node *tmp=table[a];
    for(int i=0;i<=N;i++){
        free_node(table[i]);
    }






    // TODO
    return true;
}
void free_node(node *a){
     if(a==NULL){
            return;
        }
    free_node(a->next);
    free(a);
}
