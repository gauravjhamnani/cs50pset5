/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */

    bool search(int value, int values[], int n)
{
    int low_index=0;
    int hi_index=n-1;
    if(n<0)
        return false;
    while(low_index<=hi_index)
    {
        int middle=low_index+(hi_index-low_index)/2;
        if(value==values[middle])
            return true;
        if(value>values[middle])
        {
            low_index=middle+1;
        }
        else 
        {
            hi_index=middle-1;
        }
        
    }
    return false;
}


/**
 * Sorts array of n values.
 */

    void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    //BUBBLE SORT
    for(int i=0;i<n-1;i++)
    {
        for(int j=1;j<n-i;j++)
        {
            if(values[j]<values[j-1])
            {
                int temp=values[j];
                values[j]=values[j-1];
                values[j-1]=temp;
                
            }
        }
    }
    return;

}
