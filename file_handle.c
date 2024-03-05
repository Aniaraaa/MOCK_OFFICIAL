#include <stdio.h>


// ! FILE HANDLE
// ! ONLY NEED FILE PATH TO PRINT USER 
//!  ONLY NEED FILE PATH TO GET USER

char *path = "C:/Users/Aniara/Desktop/MOCK_OFFICIAL/file_handle.txt";
#define MAX_USER_PRINT 5

//! STANDARD STRUCT , DID'NT CHANGE
struct User
{
    char name[20]; // NAME OF USER
    float ratio;   // LUCKY RATIO OF USER
    int number;    // NUMBER OF USER IN FILE
};

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
        printf("NO SUCH FILE\n");
        return -1;
    }

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

    fprintf(file, "%s %f %d", user.name, user.ratio, user.number);
    fclose(file);
}

//*############################################################
//! --------------Kind of TESTING -----------------
//*############################################################

void type_user() //* FUNCTION TO TYPE AND SAVE USER TO STRUCT "TEMP"
{
    struct User temp;
    scanf("%s", temp.name);
    scanf("%f", &temp.ratio);
    scanf("%d", &temp.number);
    write_user_to_file(temp);
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
// ! PRINT LIST FUCNTION
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
        printf("%s\n", temp[i].name);
        printf("%.2f\n", temp[i].ratio);
    }
}

// TEST MAIN
int main()
{
   /* int n = get_last_number_from_file();
    struct User array[n];
    get_all_user_from_file_to_array(array, n);
    for (int i = 0; i < n; ++i)
    {
        printf("%d\n", array[i].number);
        printf("%s\n", array[i].name);
        printf("%.2f\n", array[i].ratio);
    }
    */
// TODO ADD more user
/*
int choice;
while(1)
{
    scanf(" %d",&choice);
    if(choice == 1)
    {
        type_user();
    }
    else
    {
        break;
    }
}
*/
// TODO Clear File
/*
clear_file();
    return 0;
*/
int n = get_last_number_from_file();
print_player_with_sort(n);

return 0;
}