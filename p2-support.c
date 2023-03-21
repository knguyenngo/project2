#define _GNU_SOURCE		//strcasestr is a nonstandard GNU extension, 
//we need this line while serching for matching last name
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "p2-support.h"

void create_record (char ID[idSIZE], char first[nameSIZE], char last[nameSIZE], char email[emailSIZE], double salary, date hire_date, dataBase_ptr db) {
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

void print_title () {
  printf ("No. ID    Name          Email        Salary     Hire Date\n");
  printf ("--- ----- ------------- ------------ ---------- --/--/----\n");
}


// Helper functions


int compare_ID(const void* emp_a, const void* emp_b) {
  // const void* allow function to take in pointer of any type
  const employee* emp1 = (const employee*)emp_a;
  const employee* emp2 = (const employee*)emp_b;
  // strcmp function compare the 2 char arrays containing the IDs
  return strcmp(emp1->ID, emp2->ID);
}

int compare_date(const void* emp_a, const void* emp_b) {
  const employee* emp1 = (const employee*)emp_a;
  const employee* emp2 = (const employee*)emp_b;
  // Compare the hire dates of the employees
  if (emp1->hire_date.year != emp2->hire_date.year) { // Compare year
        return emp1->hire_date.year - emp2->hire_date.year;
    } else if (emp1->hire_date.month != emp2->hire_date.month) { // If year is equal compare month
        return emp1->hire_date.month - emp2->hire_date.month;
    } else {
        return emp1->hire_date.day - emp2->hire_date.day; // If year and month is equal, compare day
    }
}

void print_row(employee *ptr, int i) {
    char dollar = '$';
    char full_name[20];
    // concatenates first and last name
    strcpy(full_name, ptr->first_name);
    strcat(full_name, " ");
    strcat(full_name, ptr->last_name);
    // print and format employee's information
    printf("%-3d %5s %-13.13s %-12.12s %-1c%9.2f %02d/%02d/%d\n", i, ptr->ID, full_name, ptr->email, dollar, ptr->salary, ptr->hire_date.month, ptr->hire_date.day, ptr->hire_date.year);
}


// Menu options


void save (dataBase_ptr db) {
  FILE *dbfu;
  employee *ptr;
  dbfu = fopen ("database_updated", "w");//open an Std IO file to write into
  if (dbfu == NULL)
  {
    printf ("File cannot be created");
    return;
  }
  for (int i = 0; i < db->total; i++)
  {   
      ptr = &(db->emp[i]);
      fprintf (dbfu, "%s %s %s %s %.2f %02d/%02d/%d\n", ptr->ID, ptr->first_name, ptr->last_name, ptr->email, ptr->salary, ptr->hire_date.month, ptr->hire_date.day, ptr->hire_date.year); 
  }
  fclose (dbfu);//close file after writing
  return;
}

void sort_ID(dataBase_ptr db) {
  // qsort function sorts array with the specifications provided by helper function compare_ID
  qsort(db->emp, db->total, sizeof(employee), compare_ID);
}

void sort_date(dataBase_ptr db) {
  // qsort function sorts array with specifications provided by compare_date
  qsort(db->emp, db->total, sizeof(employee), compare_date);
}

void display_employees(dataBase_ptr db) {
  employee *ptr; // pointer to employee array in database
  int i;
  print_title();
  for (i = 0; i < db->total; i++) {
    ptr = &(db->emp[i]); // pointer to current employee in array 
    print_row(ptr, i); // print employee's information
  } 
}

void search_ID(dataBase_ptr db) {
  employee *ptr;
  int input, convert, i;
  printf("Enter the ID you are searching for\n");
  scanf("%d", &input);
  // Searches DataBase with given ID
  for (i = 0; i < db->total; i++) {
    ptr = &(db->emp[i]);
    convert = atoi(ptr->ID); // Convert ID char array into int
    if (convert == input) { // If ID is equal to input then print employee
      print_title();
      print_row(ptr, i);
      return; // End function
    }
  }
  printf("No match found"); // If loop finish then no match was found
}

void search_last(dataBase_ptr db) {
  printf("Test");
}

void delete_employee(dataBase_ptr db) {
  employee *ptr; // pointer to array of employees 
  employee *next; // pointer to element right of current pointer
  int input, convert, i, j;
  printf("Enter the ID you are searching for\n");
  scanf("%d", &input);
  // Searches DataBase with given ID
  for (i = 0; i < db->total; i++) {
    ptr = &(db->emp[i]);
    convert = atoi(ptr->ID); // Convert ID char array into int
    if (convert == input) { // If ID is equal then delete employee
      printf("The following employee is deleted:\n");
      print_title();
      print_row(ptr, i);
      // Shift elements in array to the left
      for (j = i+1; j < db->total; j++) { 
        next = &(db->emp[j]);
        *ptr = *next;
        ptr = next; // Move ptr to next position in array
      }
      // Decreases total employees in database
      db->total--;
      return;
    }
  }
  printf("No match found");
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