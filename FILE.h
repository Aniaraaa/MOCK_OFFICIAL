#include "DATA.h"

char *path = "C:/Users/Aniara/Desktop/MOCK_OFFICIAL/SAVE.txt";

#define MAX_USER_PRINT 5

int is_file_empty();

//*############################################################
//! -----------------FUCNTION TO GET USER----------------------
//*############################################################

/* 
* This fucntion featured a function to get all user
* from save file and put it in a array of User. This
* array use to store all user high-score for print
*/ 

void get_all_user_from_file_to_array(struct User temp[], int last_number) // Temp is array to store User, last_number is total user in save file
{
    FILE *file = fopen(path, "r"); // OPEN FILE IN READ MODE

    if (file == NULL) // CHECK IF FILE IS AVALABLE
    {
        printf("NO SUCH FILE\n");
        return;
    }

    for (int i = 0; i < last_number; ++i) // SWEEP THROUGH OUT A SAVE FILE AND GET USER , PUT USER TO ARRAY
    {
        fscanf(file, "%s %f %d", temp[i].name, &temp[i].ratio, &temp[i].number);
    }
    fclose(file);
}


//*############################################################
//! --------------FUCNTION TO GET LAST NUMBER------------------
//*############################################################

/* 
* This fucntion featured a fucntion to get a number of total user
* from save file and return that number.
*/ 

int get_last_number_from_file()
{
    FILE *file = fopen(path, "r"); // ! OPEN FILE IN READ MODE
    struct User user;             

    if (file == NULL) // CHECK IF FILE IS AVALABLE
    {
        printf("FISRT USER\n"); // IF TRUE RETURN 0
        return 0;
    }
    else if(is_file_empty() == 1) // CHECK IF FILE IS EMPTY
    {
        return 0; // IF EMPTY, RETURN 0
    }
    else;

    int last_number; // TO SAVE LAST NUMBER OF FILE

/*
A LOOP BELOW IS USE TO SWEEP THROUGH A FILE , TO CHECK NUMBER OF EACH User IN FILE 
AND GET NUMBER OF  LAST User IN FILE , STORE IT IN last_number 
*/
    while (fscanf(file, "%s %f %d", user.name, &user.ratio, &user.number) == 3)
    {
        last_number = user.number;
    }
    fclose(file);
    return last_number + 1; // A FINAL USER NUMBER IS RETURN
}

//*############################################################
//! --------------FUCNTION TO ADD USER TO FILE-----------------
//*############################################################

/*
* THIS FUCNTION IS FEATURE A FUCNTION TO PUT A SELECTED USER
* AND PUT IT INTO FILE, THAT USER IS PERNAMENTLY STORE IN FILE
* input of this fucntion is a User.
*/

void write_user_to_file(struct User user) // * AGRUMENT IS USER.
{
    FILE *file = fopen(path, "a");

    if (file == NULL)
    {
        printf("NO SUCH FILE\n");
        return;
    }

    fprintf(file, "%s %.2f %d", user.name, user.ratio, user.number);
    fclose(file);
}

//*############################################################
//! -------------------INPUT USER TO FILE---------------------
//*############################################################

/* 
* This fucntion featured a function to inform a User
* with it name number of User , lucky ratio then
* put User to file
*/ 

void input_user_to_file(char name[] , float ratio) //* FUNCTION TO TYPE AND SAVE USER TO STRUCT "TEMP"
{
    struct User new_user;
    strcpy(new_user.name,name);
    new_user.number = get_last_number_from_file();
    new_user.ratio = ratio;
    write_user_to_file(new_user);
}

//*############################################################
//! ---------------FUCNTION TO CLEAR FILE---------------------
//*############################################################

/* 
* This fucntion featured a function delete all User from save file
*/ 

void clear_file()
{
    FILE *file = fopen(path, "w");
    if (file != NULL)
    {
        fclose(file);
    }
    else
    {
        printf("CANT OPEN FILE\n");
    }
}

//*############################################################
//! -------FUCNTION TO GET USER TO FILE AND SORT TOP 5---------
//*############################################################
/* 
* This fucntion featured a function to sort all User from
* input array of User , sorting a highest ratio user to
* lowest ratio user
*/ 

void selection_sort(struct User arr[], int last_number)
{
    for(int i = 0; i < last_number - 1; ++i)
    {
        float min = arr[i].ratio;
        int min_index = i; 
        for(int j = i + 1; j < last_number; ++j)
        {
            if(arr[j].ratio < min)
            {
                min = arr[j].ratio;
                min_index = j; 
            }
        }
        if(min_index != i)
        {
            struct User temp = arr[min_index];
            arr[min_index] = arr[i];
            arr[i] = temp;
        }
    }
}

//*############################################################
//! ---------------SORT AND PRINT LIST FUCNTION----------------
//*############################################################

/* 
* This fucntion featured a function to print out top 5 user after
* sorting 
*/ 

void print_player_with_sort(int last_number)
{
    struct User temp[last_number];
    get_all_user_from_file_to_array(temp,last_number);
    selection_sort(temp,last_number);
    int top_five;
    if(last_number > 5)
    {
        top_five = last_number - 5;
    }
    else
    {
        top_five = 0;
    }
    int j = 1;
    for(int i = last_number - 1; i >= top_five; --i)
    {
        printf("|TOP %d: %.2f %s|\t",j,temp[i].ratio,temp[i].name);
        ++j;
    }
    printf("\n");

}

//*############################################################
//! ------------------CHECK IF FILE IS EMPTY-------------------
//*############################################################

/* 
* This fucntion featured a function to check if save file is avalable.
*/ 

int is_file_empty()
{
    FILE *file = fopen(path, "r");
    if (file == NULL)
    {
        printf("Khong the mo file.\n");
        return -1;
    }

    fseek(file, 0, SEEK_END);

    long size = ftell(file);

    fclose(file);
    return size == 0 ? 1 : 0; //! return '1' if empty.
}