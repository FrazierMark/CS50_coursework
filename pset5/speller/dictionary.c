
// Implements a dictionary's functionality
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table (an array of node pointers)
node *table[N];

int size_count = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int code = hash(word);          //passes word into hash function, returns code for table

    node *cursor = table[code];        //creates temp point that points at first element of table

    while (cursor != NULL)
    {
        if (strcasecmp(cursor -> word, word) == 0)  //compares passed-in word to word saved in first node
        {
            return true;                            //if same, returns true
        }
        cursor = cursor -> next;                //advances to next node
    }

    return false;
}



// Hashes word to a number
unsigned int hash(const char *str)              //sources sited: djb2 hash function.c,
{
    unsigned int value = 5381;
    int c;
    while ((c = tolower(
                    *str++)))               //Will iterate through the char word, passing the ascii value to c, while it doesn't run in to  /0
    {
        value = ((value << 5) + value) + c;    //hash * 33 + c
    }
    return value % N;
}



// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *dict_ptr = fopen(dictionary, "r");
    if (dict_ptr == NULL)
    {
        printf("Unable to open file: %s\n", dictionary);
        return false;
    }

    // initialize table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char temp_word[LENGTH + 1];

    //scanning dictionary 1 word at a time
    while (fscanf(dict_ptr, "%s\n", temp_word) != EOF)
    {
        //creating node, address of node is stored in *n
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        strcpy(n -> word, temp_word);   //copying scanned word from source (temp_word) into destination (char array)

        int code = hash(temp_word);     //hashes word and returns a key code

        if (table[code] == NULL)
        {
            n -> next = NULL;           //"next" field of new node will now be null (not pointing to anything)
            table[code] = n;            //table[code] will now point to the new node
        }
        else                            //if table[code] already points to a node...
        {
            n -> next = table[code];    //update "next" field (of new node) to point to whever table[code] was pointing to.
            table[code] = n;            //update table[code] to point to the new node
        }

        size_count ++;                  //keeps count on words saved in nodes
    }
    fclose(dict_ptr);

    return true;
}



// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return size_count;
}



// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)     //iterates through hash table
    {
        node *cursor = table[i];    //creates pointer to first node
        while (cursor != 0)
        {
            node *free_ptr = cursor;   //creates another pointer
            cursor = cursor -> next;   //advances the first pointer

            free(free_ptr);            //free the node pointed to by free_ptr
        }

        table[i] = NULL;
    }
    return true;
}
