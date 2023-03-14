/************************piatkowskiEvanA3.c**************
Student Name: Evan Piatkowski             Email Id: epiatkow
Due Date: November 26 Course Name: CIS 1300
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity. 2) I
have completed the Computing with Integrity Tutorial on Moodle; and 3) I have
achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and
all material that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for
this course.
********************************************************/

/*********************************************************
Compiling the program
The program should be compiled using the following flags: -std=c99 -Wall
compiling:
gcc -std=c99 -Wall piatkowskiEvanA3.c piatkowskiEvanA3Main.c
Running: ./a.out
*********************************************************/ 



#include "givenA3.h"
#include "myFunctions.c"

int main (int argc, char * argv[]) {

    int choice;
    int medalCount;
    int max;
    int whichMedal = 0;
    int country [COUNTRIES][MEDALCAT];
    int totalAllCountries[COUNTRIES];
    int totalMedals[COUNTRIES];
    int totalAllMedals[MEDALCAT] = {0};
    int indexOfCountries [COUNTRIES];
    int minOrMax;

    char medal[50];
    char countryName[100];
    char countryNames [COUNTRIES][MAX_LENGTH_CNAME];
    
    readFromFile(argv[1], country, countryNames);
    findTotalPerCountry(country,totalAllCountries);

    do {
        printf ("\nHere is the menu \n\n");
        printf ("1. Display all country names read from file and the total number of medals won by each\n");
        printf ("2.    Function 2 - Find total number of medals won by each country\n");
        printf ("3.    Function 3 - Finds total number of medals in each category (Gold, Silver, Bronze)\n");
        printf ("4.    Function 4 - Display horizontal histogram\n");
        printf ("5.    Function 5 - Search for a country and return the total number of medals won by it\n");
        printf ("6.    Function 6 - Rank and display top three countries in order of total medals won\n");
        printf ("7.    Function 7 - Rank and display top three countries in order of total gold medals won\n");
        printf ("8.    Function 8 - Find and display all countries that won no X medals, given X as either Gold, Silver or Bronze\n");
        printf ("9.    Function 9 - Find and display all countries that won ONLY X medals, given X as either Gold, Silver or Bronze\n");
        printf ("10.   Function 10 - Find and display name of the country that has minimum or maximum length among all countries read in option 1\n");
        printf ("12.    Exit\n");
        printf ("Enter your choice: ");
        scanf ("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\n");
                for(int i = 0; i < COUNTRIES; i ++){
                    printf("Country: %s, Gold = %d, Silver = %d, Bronze = %d\n", countryNames[i], country[i][0], country[i][1], country[i][2]);
                }
                printf("\n");
                break;

            case 2:
                printf("\n");
                for(int i = 0; i < COUNTRIES; i++){
                    printf("Country: %s = %d\n", countryNames[i], totalAllCountries[i]);
                }
                printf("\n");
                break;

            case 3:
                findTotalPerMedal (country,totalAllMedals,&whichMedal);
                printf ("Medal = Gold, Total = %d\n",totalAllMedals[0]); // 35
                printf ("Medal = Silver, Total = %d\n",totalAllMedals[1]); // 27
                printf ("Medal = Bronze, Total = %d\n",totalAllMedals[2]); // 28
                break;

            case 4: 
                printf("\n");
                for (int i = 0; i < COUNTRIES; i++){
                    totalMedals[i] = totalAllCountries[i];
                }
                hHistogram(countryNames, totalMedals);
                printf("\n");
                break;

            case 5:
                printf("Searching for which country? ");
                scanf("%s", countryName);
                medalCount = searchCountry(countryName, countryNames, totalAllCountries);
                if (medalCount >=0){
                printf("Country: %s has %d medals", countryName,medalCount);
                }else{
                    printf("Country does not exist in the list!");
                }
                break;

            case 6:
                rankTopThreeByTotal(totalMedals, countryNames);
                break;

            case 7:
                    rankTopThreeByMedal(country, countryNames);
                    break;

            case 10:
                printf("Do you want min (enter 1) or max (enter 2)? ");
                scanf("%d",&minOrMax);

                switch(minOrMax){
                    case 1:
                        printf("The Country name with minumum length = %s",countryNames[findCountryIndexWithMinOrMaxLength(minOrMax,countryNames)]);
                        break;
                    case 2:
                        printf("The Country name with maximum length = %s",countryNames[findCountryIndexWithMinOrMaxLength(minOrMax,countryNames)]);
                        break;
                } 
            break;
            default: printf ("That is an invalid choice\n");
        }
        
    } while (choice != 12);
    
    
   return 0;
}

