#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_USER_NAME_SIZE 20

struct Random_number
{
    int number;
    int check;
};

struct User
{
    char name[20]; // NAME OF USER
    float ratio;   // LUCKY RATIO OF USER
    int number;    // NUMBER OF USER IN FILE
};

// TODO NAME CHECK FUCNTION
int is_valid_name(const char *name)
{
    if (!isalpha(name[0]))
    {
        printf("NUMBER DETECTED\n");
        return 0;
    }

    else if (strchr(name, ' ') != NULL)
    {
        printf("CANT CONTAIN SPACE IN NAME\n");
        return 0;
    }

    else if (strlen(name) > MAX_USER_NAME_SIZE)
    {
        printf("NAME CANT NOT LARGER THAN 20");
        return 0;
    }
    else
    {
        return 1;
    }
}
// TODO GENERATE RANDOM NUMBER FUCNTION
int generate_number()
{
    srand(time(NULL));
    int result = (rand() % 9000) + 1000;
    return result;
}
// DELETE SWAP IN DATA
// ADD FILE_HANDLE TO PROGRAM
