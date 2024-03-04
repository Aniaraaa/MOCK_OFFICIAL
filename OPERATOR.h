#include "RETURN_TOTAL_GUESS.h"


#define PR_MENU printf("PRESS 'start' to start game , 'end' to exit program, 'list' to show score \n");
#define PR_START printf("PRESS 'yes' to play with new user , 'no' to exit to main menu\n");
#define PR_ENTER_NAME printf("PLEASE ENTER USER NAME\n");

int count = -1;
struct User player[100];

void array_sort(struct User temp[])
{
    for( int i = 0 ; i <= count ; ++i)
    {
        for(int j = 0 ; j < count - i ; ++j)
        {
            if(temp[j].lucky_ratio > temp[j + 1].lucky_ratio)
            {
                printf("SWAP\n");
                swap(&temp[j] ,&temp[j + 1]);
            }
        }
    }
}

void print_list()
{
    if(count == -1)
    {
        printf("NO PLAYER ADDED\n");
    }
    
    struct User temp[count + 1];
    for(int i = 0 ; i <= count; ++i)
    {
        temp[i] = player[i];
    }
    array_sort(temp);
    for(int i = 0 ; i <= count; ++i)
    {
        printf("___________\n");
        printf("NAME: %s\n",temp[i].name);
        printf("RATIO: %.2f\n",temp[i].lucky_ratio);
    }
}

void start_operator()
{
    char option[10];
    while (1)
    {
        PR_START

        scanf(" %[^\n]",option);
        if (strcmp(option,"yes") == 0)
        {
            ++count;
            PR_ENTER_NAME
            char name[20];
            scanf("%s",name);

            strcpy(player[count].name,name);
            int random = generate_number();
            player[count].lucky_ratio = (float)(6 - guess_number(random))/6;
            return;
        }
        else if (strcmp(option,"no") == 0)
        {
            return;
        }
        else
        {
            printf("INVALID_INSTRUCTION\n");
            continue;
        }
    }
}

void menu_operator()
{
    // TODO      Create Menu for user:
    // TODO       START GAME + END GAME + SCORE SHOW
    // TODO       START GAME -> Enter user name -> Play game
    // TODO       END GAME   -> Exit Program
    // TODO       SCORE SHOW -> Show list of user guest ratio from low to high
    char option[10];
    while (1)
    {
        PR_MENU

        scanf(" %[^\n]",option);
        if (strcmp(option,"start") == 0)
        {
            start_operator();
        }
        else if ((strcmp(option,"end") == 0))
        {
            return;
        }
        else if(strcmp(option,"list") == 0)
        {
            print_list();
        }
        else
        {
            printf("INVALID_INSTRUCTION\n");
            continue;
        }
    }
}
