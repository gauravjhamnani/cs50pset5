/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
    //Takes Command line arguments no. of arguments in argc and array of arguments as string in argv
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    //atoi converts string argument into integer argument which we are in need of
    int n = atoi(argv[1]);

    //calls srand function which seeds random numbers to be generated and seed is our second command line argument argument.This is only done when we provide a seed argument otherwise null is given as argument   
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    else
    {
        srand48((long) time(NULL));
    }

    //prints and generates n random numbers using drand.drand returns decimal value between 0 and 1 which when multiplied by limit gives us the desired range  
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
