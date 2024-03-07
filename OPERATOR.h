#include "RETURN_TOTAL_GUESS.h"


#define PR_MENU printf("PRESS \n'start' to start game , \n'end' to exit program, \n'list' to show score, \n'delete' to delete all save user \n");
#define PR_START printf("PRESS 'yes' to play with new user , 'no' to exit to main menu\n");
#define PR_ENTER_NAME printf("PLEASE ENTER USER NAME\n");
#define PR_INVALID printf("INVALID INSTRUCTION\n");
#define PR_EMPTY_FILE printf("NO USER FOUND\n");
#define PR_DELETE printf("ALL USER REMOVED\n");

//*############################################################
//! ----------------FUCNTION START OPERATOR--------------------
//*############################################################

/* 
* This fucntion featured a choice for user just after 
* user start game from main menu . User can choose "YES"
* to begin play game or "NO" to go back to main menu
*/ 

void start_operator()
{
    char option[10];
    while (1)
    {
        PR_START
        scanf(" %[^\n]",option);

        if (strcmp(option,"yes") == 0)
        {
            PR_ENTER_NAME
            char name[20];
            while(1)
            {
                scanf(" %[^\n]",name);
                if(is_valid_name(name) == 0)
                {
                    continue;
                }
                else if(is_valid_name(name) == 1)
                {
                    break;
                }
                else;
            }
            int random = generate_number();
            float ratio =  run_guess(random);
            input_user_to_file(name,ratio);
            return;
        }
        else if (strcmp(option,"no") == 0)
        {
            return;
        }
        else
        {
            PR_INVALID
            continue;
        }
    }
}

//*############################################################
//! ----------------MAIN MENU OPERATOR--------------------
//*############################################################

/* 
* This fucntion featured a choice for user in begin of program
* In main menu user has 4 option to choose , enter :
* 'list' for print top 5 user score
* 'start' for begin to play game
* 'end' to exit program completely
* 'delete' to remove all user score
*/ 


void menu_operator()
{
    char option[10];
    while (1)
    {
        PR_MENU

        scanf(" %s",option);
        if (strcmp(option,"start") == 0)
        {
            start_operator();
        }
        else if ((strcmp(option,"end") == 0))
        {
            printf("END PROGRAM \a");
            return;
        }
        else if(strcmp(option,"list") == 0)
        {
            if(is_file_empty() == 1)
            {
                PR_EMPTY_FILE
            }
            else
            {
            int number = get_last_number_from_file();
            print_player_with_sort(number);
            }
        }
        else if(strcmp(option, "delete") == 0)
        {
            clear_file();
            PR_DELETE
        }
        else
        {
            PR_INVALID
            continue;
        }
    }
}

// DELETE ARRAY OF USER , EXCHANGE WITH FILE_HANDLE
// DELETE ARRAY SORT AND PRINT_LIST() FUNCTION
// Fix type
// ADD Check_valid_name_input from user
// DECORATE LITLE BIT
// add fucntion check empty file