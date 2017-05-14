/**
 * Implements a dictionary's functionality.
 */
 //#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define SIZE 1000000
#include <stdbool.h>

#include "dictionary.h"


typedef struct node
{
    char word[LENGTH+1];
    struct node* next;
}
node;

node* hashtable[SIZE] = {NULL};

// create hash function
int hash (const char* word)
{
    int hash = 0;
    int n;
    for (int i = 0; word[i] != '\0'; i++)
    {
        // alphabet case
        if(isalpha(word[i]))
            n = word [i] - 'a' + 1;
        
        // comma case
        else
            n = 27;
            
        hash = ((hash << 3) + n) % SIZE;
    }
    return hash;    
}


int dictionarySize = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // TODO
    FILE* file = fopen(dictionary, "r");
    if (file == NULL)
        return false;
    
    // create an array for word to be stored in
    char word[LENGTH+1];
    
    // scan through the file, loading each word into the hash table
    while (fscanf(file, "%s\n", word)!= EOF)
    {
        // increment dictionary size
        dictionarySize++;
        
        // allocate memory for new word 
        node* newWord = malloc(sizeof(node));
        
        // put word in the new node
        strcpy(newWord->word, word);
        
        // find what index of the array the word should go in
        int index = hash(word);
        
        // if hashtable is empty at index, insert
        if (hashtable[index] == NULL)
        {
            hashtable[index] = newWord;
            newWord->next = NULL;
        }
        
        // if hashtable is not empty at index, append
        else
        {
            newWord->next = hashtable[index];
            hashtable[index] = newWord;
        }      
    }
    
    // close file
    fclose(file);
    
    // return true if successful 
    return true;
    //return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
