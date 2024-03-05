#include "DATA.h"

#define TRUE 1
#define NUMBER_OF_GUESS_NUM 4
#define NUMBER_OF_ROUND 10


// TODO       INPUT OF THIS HEADER IS "RANDOM NUMBER"
// TODO       OUT PUT IS "TOTAL OF GUESS"

//*############################################################
//! --------------CHECK WITH RANDOM NUMBER -----------------
//*############################################################

void check_random_number(struct Random_number random_number[], int guess_number[])  // * ADD guess_number to compare with random_number 
                                                                                    //! MOD
{
    for (int i = 0; i < NUMBER_OF_GUESS_NUM; ++i)
    {
        if (random_number[i].check == TRUE)
        {
            continue;
        }
        else if (guess_number[i] == random_number[i].number)
        {
            random_number[i].check = TRUE;
        }
        else;
    }
}

//*############################################################
//! -----------------REVEAL RANDOM NUMBER --------------------
//*############################################################

void reveal_random_number(struct Random_number random_number[])
{
    for (int i = 0; i < NUMBER_OF_GUESS_NUM; ++i)
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

//*############################################################
//! -------------------CHECK IF USER WIN ----------------------
//*############################################################

int check_win(struct Random_number random_number[])
{
    int check = 0;
    for (int i = 0; i < NUMBER_OF_GUESS_NUM; ++i)
    {
        if (random_number[i].check == TRUE)
        {
            ++check;
        }
    }
    if (check == NUMBER_OF_GUESS_NUM)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//*############################################################
//! ------------TO SEPARATE NUMBER SAVE TO ARRAY--------------
//*############################################################

// TODO FUCNTION 1
void separate_number_save_to_array_RANDOM(struct Random_number array[], int random_number)
{
    for (int i = 0; i < NUMBER_OF_GUESS_NUM; ++i)
    {
        array[NUMBER_OF_GUESS_NUM - i - 1].number = random_number % 10;
        random_number /= 10;
    }
}
// TODO FUCNTION 2
void separate_number_save_to_array_GUESS(int array[], int guess_number)
{
    for (int i = 0; i < NUMBER_OF_GUESS_NUM; ++i)
    {
        array[NUMBER_OF_GUESS_NUM - i - 1] = guess_number % 10;
        guess_number /= 10;
    }
}

//*############################################################
//! -------------------RUN GUESS NUMBER -----------------------
//*############################################################

/*
* This fucntion use to open guess operator , which user can input guess number
* then this fucntion going to compare with random random number, with any guess 
* number is similar with random_number , then reveal random_number , if all random
* _number is reveal , this fucntion return lucky_ratio, end fucntion.
*/
float run_guess(int random_number)
{
    struct Random_number random_num_array[NUMBER_OF_GUESS_NUM];

    separate_number_save_to_array_RANDOM(random_num_array, random_number);
    int total_guess = 10;
    for (int i = 0; i < NUMBER_OF_ROUND; ++i)
    {
        int guess_number;
        int guess_num_array[NUMBER_OF_GUESS_NUM]; //!mod
    
        printf("(TOTAL GUESS: %d (LIMIT 10) ENTER NUMBER:\n", total_guess);
        while (1)
        {
            scanf(" %d", &guess_number);
            if (guess_number >= 1000 && guess_number <= 9999) //! mod
            {
                separate_number_save_to_array_GUESS(guess_num_array,guess_number);
                break;
            }
            else
            {
                printf("MUST >= 1000 AND <= 9999\n"); //! MOD
                continue;
            }
        }
        check_random_number( random_num_array, guess_num_array);
        reveal_random_number(random_num_array);
        
        if (check_win(random_num_array) == 1)
        {
            return (float)total_guess/10;
        }
        else
        {
            --total_guess;
            continue;
        }
    }
    return 0.00; // DID NOT GUESS A TRUE NUMBER
}

// ADD comment , add fucntion to separate guess number , fix fucntion guess_number , change name of guess_number, fix fucntion genrate_number in DATA.h
// Fix File operator.h , 
