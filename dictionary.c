// Implements a dictionary's functionality
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "dictionary.h"
#include <ctype.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

//function structures
void libera(node c, node t);
int counter(node bucket);
int isEmpty( node * list );

// Number of buckets in hash table
const unsigned int N = 5715;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    const char *str = word;
    int j = 0;
    while(str[j]) {
        putchar (toupper(str[j]));
        j++;
    }
    unsigned int location = hash(str);
    node cursor = *table[location];
    int boolean;
    for (int i = 0; i < N; i++)
    {
        int isNull = isEmpty(table[i]);
        if(isNull == 1)
        {
            return false;
        }
        boolean = strcasecmp(str, cursor.word);
        if (boolean == 0)
        {
            return true;
        }
        else
        {
            cursor = *cursor.next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word) //Uses additive hash
{
    const char *str = word;
    int j = 0;
    while(str[j]) {
        putchar (toupper(str[j]));
        j++;
    }
    int len = strlen(str);
    int h;
    for (int i = 0; i < len; i++)
    {
        h = h + str[i];
    }
    if (h > N)
    {
        return N;
    }
    return h;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // initialise word
    char word[LENGTH+1];
    // open dictionary
    FILE *dicptr = fopen(dictionary, "r");
    if(dicptr == NULL)
    {
        printf("Couldn't open dictionary");
        return false;
    }
    // iterate through dictionary words
    while (fscanf(dicptr, "%s", word) != EOF)
    {
        // make a new word.
        node *new_node = malloc(sizeof(node));
        // check for error assigning memory
        if (new_node == NULL)
        {
            unload();
            return false;
        }
        else
        {
            // copy word into node
            strcpy(new_node->word, word);
            // use hash function to determine which bucket (linked list) to insert word into
            int n = hash(new_node->word);
            // insert into list
            new_node->next = table[n];
            table[n] = new_node;
        }
    }
    // close dictionary
    fclose(dicptr);
    return true;
}
// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    int count = 0;
    for(int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            count = count + counter(*table[i]);
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node cursor;
    node tmp;
    for (int i = 0; i < N; i++)
    {
        cursor = *table[i];
        tmp = cursor;
        libera(cursor, tmp);
    }
    return true;
}

int counter(node bucket)
{
    int c = 0;
    if (bucket.next != NULL)
    {
        c = c + counter(*bucket.next);
    }
    return c++;
}

void libera(node c, node t)
{
    int isNull = isEmpty(&c);
    if(isNull == 1)
    {
        return;
    }
    else
    {
        c = *c.next;
        free(&t);
        t = c;
        libera(c, t);
    }
}

int isEmpty( node * list )
 {
   if( !list )
      return 1;
   return 0;
 }