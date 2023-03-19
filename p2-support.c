#define _GNU_SOURCE		//strcasestr is a nonstandard GNU extension, 
//we need this line while serching for matching last name
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "p2-support.h"



void create_record (char ID[idSIZE], char first[nameSIZE], char last[nameSIZE], char email[emailSIZE], double salary, date hire_date, dataBase_ptr db)// specify parameters. Clues are in the initalize function.
{
  // Set index to current total of employees
  int i = db->total;
  employee *db_index = &(db->emp[i]); // Pointer to memory location after most recently added employee
  employee add; // Employee that will be added to DataBase

  // Copy given information into employee struct
  strcpy(add.ID, ID);
  strcpy(add.first_name, first);
  strcpy(add.last_name, last);
  strcpy(add.email, email);
  add.salary = salary;
  add.hire_date = hire_date;
  
  // Copy add struct to employee array
  *db_index = add;
  db->total = ++i; // Increase total amount of employees
}


void print_title ()// you can keep this fuction or remove if needed
{
  printf ("No. ID    Name          Email        Salary     Hire Date\n");
  printf ("--- ----- ------------- ------------ ---------- --/--/----\n");
}


//fix save function. Save array into file database_updated in the same format withthe 
//database file.
void save (dataBase_ptr db)// this function is for saving the database into a text file
{
  FILE *dbfu;
  dbfu = fopen ("database_updated", "w");//open an Std IO file to write into
  if (dbfu == NULL)
  {
    printf ("File cannot be created");
    return;
  }
  for (int i = 0; i < db->total; i++)
  {
      fprintf (dbfu, "bro"); //add format specifiers here, db->emp[i].ID,
	      //add other members);

  }

  fclose (dbfu);//close file after writing
  return;

}


void sort_ID(dataBase_ptr db) {
  printf("Test");
}


void sort_date(dataBase_ptr db) {

}


void display_employees(dataBase_ptr db) {
  employee *ptr;
  date current_date;
  int i;
  char dollar = '$';
  print_title();
  for (i = 0; i < db->total; i++) {
    ptr = &(db->emp[i]);
    current_date = ptr->hire_date;
    char full_name[40];
    strcpy(full_name, ptr->first_name);
    strcat(full_name, " ");
    strcat(full_name, ptr->last_name);
    printf("%-3d %5s %-13.13s %-12.12s %-1c%9.2f %02d/%02d/%d\n", i, ptr->ID, full_name, ptr->email, dollar, ptr->salary, current_date.month, current_date.day, current_date.year);
  } 
}


void search_ID(dataBase_ptr db) {

}


void search_last(dataBase_ptr db) {

}


void delete_employee(dataBase_ptr db) {

}


void display_menu (struct DataBase *db)
{
  int input = 0;
  while (input != 8)
  {
    puts
      ("\n**************************************************************");
    printf
      (  "********** Employee Database - Total Employees: %03d **********\n", db->total);
    puts
      ("**************************************************************\n");
    puts ("Choose one of the menu options below:");
    puts ("1. Sort by ID");
    puts ("2. Sort by Hire Date");
    puts ("3. Display all employees");
    puts ("4. Search employees by ID");
    puts ("5. Search employees by Last Name");
    puts ("6. Delete employee by ID");
    puts ("7. Save");
    puts ("8. Exit");

    scanf ("%d", &input);

    switch (input)
    {
      case 1:
        //call the function you defined for sorting by ID
        sort_ID(db);
        break;
      case 2:
        //call the function you defined for sorting by Hire Date
        sort_date(db);
        break;
      case 3:
        //call the function you defined for displaying employees
        display_employees(db);
        break;
      case 4:
        //call the function you defined for searching employees by ID
        search_ID(db);
        break;
      case 5:
        //call the function you defined for searching employees by Last Name
        search_last(db);
        break;
      case 6:
        //call the function you defined for deleting employee by ID
        delete_employee(db);
        break;
      case 7:
        save (db);
        break;
      case 8:
        //free all allocated memory
        free(db->emp);
        db->emp = NULL;
        free(db);
        db = NULL;
        printf("Bye!\n");
        break;
    }
  }

}
