////////////////////////////////////////////////////////////////////////
//
// File           : p2-support.h
// Description    : Header file for project2
// Author         : Khuong Nguyen
// Date           : 3/15/2023
// Notes          : Added 5 helper functions: compare_ID, compare_date, print_row, request_ID, search_matches 
//                  Current bugs: search for last name function need to print_title only when matches are found
//                  Possible vulnerability to memory smashing, or buffer overflows
//                  Recheck if strcat + strcpy is properly used

#ifndef P2Header // To prevent double inclusion of header
#define P2Header // To prevent double inclusion of header

#include <stdio.h>
#define byID 1
#define byNAME 2
#define dbSIZE 100
#define idSIZE 6
#define nameSIZE 10
#define emailSIZE 20

typedef struct date // do not modify
{
  int day;
  int month;
  int year;
} date;

typedef struct Employee
{
  char ID[idSIZE];
  char first_name[nameSIZE];
  char last_name[nameSIZE];
  char email[emailSIZE];
  double salary;
  date hire_date;
} employee, *employee_ptr;

typedef struct DataBase
{
  // a pointer to first element of employee array
  employee *emp;
  // number of employees in database
  int total;
} *dataBase_ptr;

// Functional Prototypes

// Function     : initialize
// Description  : this function creates an array in the database
//                then initalializes each array elemet with the data
//                in the given file
// Inputs       : a pointer to DataBase struct
// Output       : none
void initialize(dataBase_ptr);

// Function     : create_record
// Description  : create record of employee from file lines
// Inputs       : employee's information such as ID, name, email, salary, hire date
//                and the DataBase struct
// Outputs      : none
void create_record(char[idSIZE], char[nameSIZE], char[nameSIZE], char[emailSIZE], double, date, struct DataBase*);

// Function     : print_title 
// Description  : print title for employee's records
// Inputs       : none 
// Outputs      : none
void print_title();

// Function     : display_menu
// Description  : display interactive menu interface for program
// Inputs       : pointer to DataBase struct
// Outputs      : none
void display_menu(dataBase_ptr);

// Function     : compare_ID
// Description  : compare the IDs of two employees
// Inputs       : two void pointers
// Outputs      : integer
int compare_ID(const void*, const void*);

// Function     : compare_date
// Description  : compare the hire dates of two employees
// Inputs       : two void pointers
// Outputs      : integer
int compare_date(const void*, const void*);

// Function     : print_row
// Description  : prints employee's information according to specific format row
// Inputs       : pointer to employee, and position of employee in array
// Outputs      : none
void print_row(employee*, int);

// Function     : search_matches 
// Description  : search for employee's last name base on length of given input so match is always found at beginning of string
// Inputs       : two char pointers, one for employee's last name, and one for given input
// Outputs      : a char pointer to match in employee's last name
char* search_matches(const char*, const char*);

// Function     : request_ID
// Description  : request input from user
// Inputs       : pointer to integer
// Outputs      : none
void request_ID(int*);

// Function     : sort_ID
// Description  : Sort employees by ID from low - high
// Inputs       : a pointer to DataBase struct
// Outputs      : none
void sort_ID(dataBase_ptr);

// Function     : sort_date
// Description  : Sort employees by hire date from earliest - latest
// Inputs       : a pointer to DataBase struct
// Outputs      : none
void sort_date(dataBase_ptr);

// Function     : display_employees
// Description  : Display employees as ordered in the DataBase
// Inputs       : a pointer to DataBase struct
// Outputs      : none
void display_employees(dataBase_ptr);

// Function     : search_ID
// Description  : Search and display employee with given ID,
//                display message if employee does not exist
// Inputs       : a pointer to DataBase struct
// Outputs      : none
void search_ID(dataBase_ptr);

// Function     : search_last
// Description  : Search and partially display multiple employees by last name,
//                or display complete match to given string
// Inputs       : a pointer to DataBase struct
// Outputs      : none
void search_last(dataBase_ptr);

// Function     : delete_employee
// Description  : Delete a record matching given ID 
//                , print if no match found
// Inputs       : a pointer to DataBase struct
// Outputs      : none
void delete_employee(dataBase_ptr);

// Function     : save 
// Description  : Save DataBase to another file named "database_updated"
// Inputs       : a pointer to DataBase struct
// Outputs      : none
void save(dataBase_ptr);

#endif // To prevent double inclusion of header
