
/*
Created by: GREG WOO
Program: Generates one year's calendar to standard output

Takes as argument the number of characters for each day,
and the day of the week that starts the year.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// This method prints a line with \ as the first and last char
// and - for the rest
int linePrinter(char *argv[]) {

  int daySize = atoi(argv[1]);
  int firstDay = atoi(argv[2]);
  int lineSymbols = (daySize + 3 ) * 7 + 1;

  for(int i = 0; i < lineSymbols; i++ ) {

    if((i == 0) || (i == lineSymbols - 1)){

      printf("|");

    } else {

      printf("-");

    }
  }

  printf("\n");
  return 0;
}

// This method prints a line first. Then \ for the first and last char
// then spaces then the month's name
// finally we print a line again

int monthPrinter(char *monthText, char *argv[]) {

  linePrinter(argv);
  int daySize = atoi(argv[1]);
  int firstDay = atoi(argv[2]);
  int lineSymbols = (daySize + 3 ) * 7 + 1;


  int sizeOfMonthText = strlen(monthText);

  int numberSpaces = (lineSymbols - sizeOfMonthText - 2) / 2 ;
  float unevenChecker = (lineSymbols - sizeOfMonthText - 2) / 2.00 ;
  int unevenSpaces = numberSpaces + 1;

  // Here we check if the number of spaces on either side of the month's name is equal.
  // if statement to know if the number of spaces on each side is different
  if(unevenChecker > numberSpaces) {

    int counter = 0;

    for(int i = 0; i < lineSymbols; i++) {

      if((i == 0) || (i == lineSymbols - 1)){

        printf("|");

      } else if ( (i >= unevenSpaces) && (i < lineSymbols - numberSpaces - 2) ){

        char monthChar = monthText[counter];
        printf("%c", monthChar);
        counter++;

      } else {

        printf(" ");

      }
    }

    printf("\n");
    linePrinter(argv);

    // else statement if number of spaces on each side is equal

  } else {

    int counter = 0;

    for(int i = 0; i < lineSymbols; i++) {

      if((i == 0) || (i == lineSymbols - 1)){

        printf("|");

      } else if ( (i > numberSpaces) && (i < lineSymbols - numberSpaces - 1) ){

        char monthChar = monthText[counter];
        printf("%c", monthChar);
        counter++;

      } else {

        printf(" ");

      }
    }

    printf("\n");
    linePrinter(argv);
  }

  return 0;
}

// This method prints the day's names
// and returns the number of characters it printed
int daySizePrinter(char *dayText, int daySize) {

  printf(" ");
  int counter = 0;

  // Here we print the day's name
  for (int i = 0; i < daySize ; i++) {

    if(dayText[i]) {
      char dayChar = dayText[i];
      printf("%c", dayChar);
      counter ++;
    }
  }

  // Here we print the spaces after the day's name
  int lineSymbols = (daySize + 3) * 7 + 1;
  int spacesLeft = ((lineSymbols - 8) / 7) - 1 - counter;

  for (int i = 0; i < spacesLeft ; i++) {

    printf(" ");

  }

  printf("|");

  return spacesLeft + 2 + counter;
}


// This method uses the previous method (daySizePrinter)
// in order to print the entire line of days
int dayPrinter(char *argv[]) {

  char days[][100] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

  int daySize = atoi(argv[1]);
  int firstDay = atoi(argv[2]);
  int lineSymbols = (daySize + 3 ) * 7 + 1;

  int counter = 0;

  for(int i = 0; i <= lineSymbols + 1; i++ ) {

    if(i == 0){

      printf("|");

    } else {

      int printCounter = daySizePrinter(days[counter], daySize );
      counter ++;
      i = i + printCounter;

    }
  }

  printf("\n");
  return 0;
}

// This method prints the day numbers
int numberPrinter(char *argv[], int day ) {

  int daySize = atoi(argv[1]);
  int firstDay = atoi(argv[2]);
  int lineSymbols = (daySize + 3 ) * 7 + 1;

  // We first print a line using the linePrinter function
  linePrinter(argv);

  int dayCounter = 1;
  int tempCounter = 0;
  int firstDayMatch = 1;

  printf("|");

  // This while loop is here to make sure the integer day is never
  // bigger than 7
  while( day > 7) {

    day = day - 7;
  }

  // This while loop creates spaces before day 1
  while(firstDayMatch != day) {
    printf("   ");
    int spaceCounter = ((lineSymbols - 8) / 7 ) - 3;
    for (int k = 0; k < spaceCounter; k++) {

      printf(" ");

    }
    printf("|");
    firstDayMatch ++;
    tempCounter ++;

  }

  // This while loop prints the 30 days
  while ( dayCounter <= 30 ) {

    printf(" ");
    printf("%d", dayCounter);
    tempCounter ++;

    // If the day only has 1 digit, we print an additional space after it
    if (dayCounter < 10) {

      int spaceCounter = ((lineSymbols - 8) / 7 ) - 2;
      for (int k = 0; k < spaceCounter; k++) {

        printf(" ");
      }


    } else {

      int spaceCounter = ((lineSymbols - 8) / 7 ) - 3;
      for (int k = 0; k < spaceCounter; k++) {

        printf(" ");
      }

    }

    printf("|");

    // This creates a new row of days when the limit is reached
    if ((tempCounter % 7 == 0) && (dayCounter != 30)) {
      printf("\n");
      printf("|");

    }
    dayCounter ++;

  }

  // This while loop creates blank cases after the 30th day
  while (tempCounter % 7 != 0) {
    printf("   ");
    int spaceCounter = ((lineSymbols - 8) / 7 ) - 3;
    for (int k = 0; k < spaceCounter; k++) {

      printf(" ");

    }
    printf("|");

    tempCounter++;

  }
  printf("\n");



  return 0;

}


///////////////////////////////////////

int main( int argc, char *argv[]) {

  // Check if the number of arguments is correct
  if (argc != 3) {

    printf("Error: you need to enter 2 arguments\n");
    exit(-1);

  }


  char months[][13] = {"January","February", "March","April", "May", "June", "July", "August", "September", "October", "November", "December"};
  int daySize = atoi(argv[1]);
  int firstDay = atoi(argv[2]);
  int counter = firstDay;


  // First we check that the arguments are valid
  if ( daySize < 2) {

    printf("ERROR: Cannot print days smaller than size 2 \n");
    exit(1);


  } else if ((firstDay > 7) || (firstDay < 1) ) {

    printf("ERROR: The first day of the week must be between 1 and 7\n");
    exit(1);


  }

  // We then use a for loop to print (in order) the month, then the days of the week
  // then finally the day numbers
  for(int i = 0; i < 12; i++ ){

    monthPrinter( months[i], argv);
    dayPrinter(argv);
    numberPrinter(argv, counter);
    //numberPrinter(argv, counter);
    counter = counter + 2;

    // When we reach the end of the calendar, we print an additional line
    if (i == 11) {
      linePrinter(argv);

    }
  }

  return 0;
}
