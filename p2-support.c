#define _GNU_SOURCE		//strcasestr is a nonstandard GNU extension, 
//we need this line while serching for matching last name
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "p2-support.h"



void create_record ()// specify parameters. Clues are in the initalize function.
{
  //define function. Clues are in the initalize function
  //do not forget to increase total number of employees in the database
}


void print_title ()// you can keep this fuction or remove if needed
{
  printf ("No. ID    Name          Email        Salary     Hire Date\n");
  printf ("--- ----- ------------- ------------ ---------- --/--/----\n");

}


//fix save function. Save arraya into file database_updated in the same format withthe 
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
      fprintf (dbfu,//add format specifiers here, db->emp[i].ID,
	      //add other members);

  }

  fclose (dbfu);//close file after writing
  return;

}

void display_menu (struct DataBase *db)
{
  int input = 0;
  while (input != 8)
  {
    puts
      ("\n**************************************************************");
    printf
      (  "********** Employee Database - Total Employees: %03d **********\n",
      );//you need to fix this line so that total employees in the database is printed
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
        break;
      case 2:
        //call the function you defined for sorting by Hire Date
        break;
      case 3:
        //call the function you defined for displaying employees
        break;
      case 4:
        //call the function you defined for searching employees by ID
        break;
      case 5:
        //call the function you defined for searching employees by Last Name
        break;
      case 6:
        //call the function you defined for deleting employee by ID
        break;
      case 7:
        save (db);
        break;
      case 8:
        //free all allocated memory
        printf("Bye!\n");
        break;

    }
  }

}
