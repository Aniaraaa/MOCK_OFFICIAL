
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



struct Random_number
{
    int number;
    int check;
};

struct User
{
    char name[20];
    float ratio;
};

int generate_number()
{
    srand(time(NULL));
    int result = rand() % 9000;
    return result;
}

void swap(struct User *a, struct User *b)
{
    struct User temp = *a;
    *a = *b;
    *b = temp;
}
