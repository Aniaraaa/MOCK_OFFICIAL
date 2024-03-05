#include "DATA.h"

// ! FILE HANDLE
// ! ONLY NEED FILE PATH TO PRINT USER 
//!  ONLY NEED FILE PATH TO GET USER

char *path = "C:/Users/Aniara/Desktop/MOCK_OFFICIAL/SAVE.txt";

#define MAX_USER_PRINT 5

int is_file_empty();

struct User user[100]; // ARRAY OF STRUCT USER TO READ FILE , ADD USER TO ARRAY FOR SORT FROM HIGH TO LOW

//*############################################################
//! -----------------FUCNTION TO GET USER----------------------
//*############################################################
// NOTE* add Array of struct User and number of all user to use
// NOTE* RETURN a Array struct User full of all user in file

void get_all_user_from_file_to_array(struct User temp[], int last_number) // Temp is temporary array to store User, last_number is total user in File
{
    FILE *file = fopen(path, "r"); // ! Mở file text và mở ở chế độ read.

    if (file == NULL)
    {
        printf("NO SUCH FILE\n");
        return;
    }
    for (int i = 0; i < last_number; ++i)
    {
        fscanf(file, "%s %f %d", temp[i].name, &temp[i].ratio, &temp[i].number);
    }
    fclose(file);
}


//*############################################################
//! --------------FUCNTION TO GET LAST NUMBER------------------
//*############################################################
// Note this fucntion to get last number of file , or number of all user in file
// TODO --- FUCNTION TO RETURN "NUMBER" OF LAST USER IN FILE.---
int get_last_number_from_file()
{
    FILE *file = fopen(path, "r"); // ! Mở file text và mở ở chế độ read.
    struct User user;              // ! Tạo User để lưu giá trị lấy từ File.

    if (file == NULL)
    {
        printf("FISRT USER\n");
        return 0;
    }
    else if(is_file_empty() == 1)
    {
        return 0;
    }
    else;

    int last_number; // ! Lấy giá trị cuối cùng từ file
                     // TODO Giá trị lấy về để tạo mảng lưu giá trị từ file

    while (fscanf(file, "%s %f %d", user.name, &user.ratio, &user.number) == 3)
    {
        last_number = user.number;
    }
    fclose(file);
    return last_number + 1; // ! Giá trị cuối cùng trong file.
}

//*############################################################
//! --------------FUCNTION TO ADD USER TO FILE-----------------
//*############################################################
// NOTE FUNCTION TO ADD USER TO FILE , WITH "APPEND" MODE (ADD MORE , NOT DELETE PREVIOUS USER).
// NOTE Input is struct User with infomation

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
// Note Clear all user which save to file

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

// ! SORT ELEMENT FUCNTION
void selection_sort(struct User arr[],int last_number)
{
    for(int i = 0; i < last_number - 1 ; ++i)
    {
        float min = arr[i].ratio;
        for(int j = i + 1; j < last_number; ++j)
        {
            if(arr[j].ratio < min)
            {
                struct User temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
//*############################################################
//! ---------------SORT AND PRINT LIST FUCNTION----------------
//*############################################################
void print_player_with_sort(int last_number)
{
    struct User temp[last_number];
    get_all_user_from_file_to_array(temp,last_number);
    selection_sort(temp,last_number);
    int top_five = 5;
    if(last_number > 5)
    {
        top_five = last_number - top_five;
    }
    else
    {
        top_five = 0;
    }
    for(int i = last_number - 1; i >=  top_five ; --i)
    {
        printf("__________\n");
        printf("NAME :%s\n", temp[i].name);
        printf("RATIO:%.2f\n", temp[i].ratio);
        printf("----------\n");
    }
}

//*############################################################
//! ------------------CHECK IF FILE IS EMPTY-------------------
//*############################################################

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