////////////////////////////////////////////////////////////////////////
//
// File           : p2-support.h
// Description    : Header file for project2
// Author         : Khuong Nguyen
// Date           : 3/15/2023
// Notes          : 

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
// Description  : This function creates an array in the database
//                then initalializes each array elemet with the data
//                in the given file
// Inputs       : a pointer to DataBase struct
// Output       : none
void initialize(dataBase_ptr);

// Function     : create_record
// Description  : Create record of employee from file lines
// Inputs       : Employee's information such as ID, name, email, salary, hire date
//                and the DataBase struct
// Outputs      : none
void create_record(char[idSIZE], char[nameSIZE], char[nameSIZE], char[emailSIZE], double, date, struct DataBase*);

// Function     : print_title 
// Description  : Print title for employee's records
// Inputs       : 
// Outputs      : 
void print_title();

// Function     : display_menu
// Description  : Display interactive menu interface for program
// Inputs       : 
// Outputs      : 
void display_menu(dataBase_ptr);

// other function headers here
// Function     : 
// Description  : 
// Inputs       : 
// Outputs      : 
int compare_ID(const void*, const void*);

int compare_date(const void*, const void*);
// Function     : sort_ID
// Description  : Sort employees by ID from low - high
// Inputs       : 
// Outputs      : 
void sort_ID(dataBase_ptr);

// Function     : sort_date
// Description  : Sort employees by hire date from earliest - latest
// Inputs       : 
// Outputs      : 
void sort_date(dataBase_ptr);

// Function     : display_employees
// Description  : Display employees as ordered in the DataBase
// Inputs       : 
// Outputs      : 
void display_employees(dataBase_ptr);

// Function     : 
// Description  : 
// Inputs       : 
// Outputs      : 
void print_row(employee*, int);

// Function     : search_ID
// Description  : Search and display employee with given ID,
//                display message if employee does not exist
// Inputs       : 
// Outputs      : 
void search_ID(dataBase_ptr);

// Function     : search_last
// Description  : Search and partially display multiple employees by last name,
//                or display complete match to given string
// Inputs       : 
// Outputs      : 
void search_last(dataBase_ptr);

// Function     : delete_employee
// Description  : Delete a record matching given ID 
//                , print if no match found
// Inputs       : 
// Outputs      : 
void delete_employee(dataBase_ptr);

// Function     : save 
// Description  : Save DataBase to another file named "database_updated"
// Inputs       : 
// Outputs      : 
void save(dataBase_ptr);

#endif // To prevent double inclusion of header
