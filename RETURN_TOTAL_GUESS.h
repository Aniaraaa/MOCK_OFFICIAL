#include "DATA.h"

#define TRUE 1
#define QUANTITY_OF_RANDOM_NUMBER 4
#define NUMBER_OF_ROUND 10


// TODO       INPUT OF THIS HEADER IS "RANDOM NUMBER"
// TODO       OUT PUT IS "TOTAL OF GUESS"

void check_random_number(int guess_number, struct Random_number random_number[])
{
    for (int i = 0; i < QUANTITY_OF_RANDOM_NUMBER; ++i)
    {
        if (random_number[i].check == TRUE)
        {
            continue;
        }
        else if (guess_number == random_number[i].number)
        {
            random_number[i].check = TRUE;
            return;
        }
        else
            ;
    }
}
void reveal_random_number(struct Random_number random_number[])
{
    for (int i = 0; i < QUANTITY_OF_RANDOM_NUMBER; ++i)
    {
        if (random_number[i].check == TRUE)
        {
            printf("%d ", random_number[i].number);
        }
        else
        {
            printf("- ");
        }
    }
    printf("\n");
}

int check_win(struct Random_number random_number[])
{
    int check = 0;
    for (int i = 0; i < QUANTITY_OF_RANDOM_NUMBER; ++i)
    {
        if (random_number[i].check == TRUE)
        {
            ++check;
        }
    }
    if (check == QUANTITY_OF_RANDOM_NUMBER)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void separate_number_save_to_array(struct Random_number array[], int random_number)
{
    for (int i = 0; i < QUANTITY_OF_RANDOM_NUMBER; ++i)
    {
        array[QUANTITY_OF_RANDOM_NUMBER - i - 1].number = random_number % 10;
        random_number /= 10;
    }
}

int guess_number(int random_number)
{
    struct Random_number array[QUANTITY_OF_RANDOM_NUMBER];
    separate_number_save_to_array(array, random_number);
    int total_guess = 0;

    for (int i = 0; i < NUMBER_OF_ROUND; ++i)
    {
        int guess_number;
        printf("(TOTAL GUESS: %d (LIMIT 10) ENTER NUMBER:\n", total_guess);
        while (1)
        {
            scanf(" %d", &guess_number);
            if (guess_number >= 0 && guess_number <= 9)
            {
                break;
            }
            else
            {
                printf("MUST >= 0 AND <= 9\n");
                continue;
            }
        }
        check_random_number(guess_number, array);
        reveal_random_number(array);
        ++total_guess;
        if(total_guess > 9)
        {
            return 6;
        }
        else if (check_win(array) == 1)
        {
            return total_guess - 4;
        }
        else
        {
            continue;
        }
    }
    return 0; // DID NOT GUESS A TRUE NUMBER
}