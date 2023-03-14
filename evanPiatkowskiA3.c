#include "givenA3.h"

// case 1
void readFromFile(char filewithMedals[30], int country[COUNTRIES][MEDALCAT], char countryNames[COUNTRIES][100])
{
    FILE *fptr = fopen(filewithMedals, "r");
    for (int i = 0; i < COUNTRIES; i++)
        fscanf(fptr, "%s %d %d %d", countryNames[i], &country[i][0], &country[i][1], &country[i][2]);
    fclose(fptr);
}

// case 2
void findTotalPerCountry (int country [COUNTRIES] [MEDALCAT], int totalAllCountries [COUNTRIES]){
    for(int i = 0; i<COUNTRIES; i++)
    {
        totalAllCountries[i] = 0;
        for(int x = 0;x<MEDALCAT;x++)
            totalAllCountries[i]+=country[i][x];
    }
};

// case 3
int findTotalPerMedal (int country [COUNTRIES][MEDALCAT], int totalAllMedals [MEDALCAT], int * whichMedal){
    for(int i=0;i<COUNTRIES;i++)
    {
        totalAllMedals[0]=totalAllMedals[0]+country[i][0];
        totalAllMedals[1]=totalAllMedals[1]+country[i][1];
        totalAllMedals[2]=totalAllMedals[2]+country[i][2];
    }
    
};

// case 4
void hHistogram (char countryNames [COUNTRIES][MAX_LENGTH_CNAME], int totalMedals[COUNTRIES]){
    for(int count=0;count<COUNTRIES;count++)
    {
        if(strlen(countryNames[count])>=8)
        {
            printf("%s\t:",countryNames[count]);
        }
        else
        {
            printf("%s\t\t:",countryNames[count]);
        }
        for(int count2=0;count2<totalMedals[count];count2++)
        {
            printf("*");

        }
        printf("(%d)",totalMedals[count]);
        printf("\n");
    }
};

// case 5
int searchCountry (char countryName [MAX_LENGTH_CNAME], char countryNames [COUNTRIES][MAX_LENGTH_CNAME], int totalAllCountries [COUNTRIES]){
    for(int i = 0; i < COUNTRIES; i++)
    {
        if(strcmp(countryName, countryNames[i]) == 0)
            return totalAllCountries[i];
    }
    return -1;
};

// case 6
void rankTopThreeByTotal (int totalMedals[COUNTRIES], char countryNames [COUNTRIES][MAX_LENGTH_CNAME]){
    for(int count = 0; count < COUNTRIES; count++){
        int max = count; 
        for(int cPos = count + 1; cPos < COUNTRIES; cPos++)
        {
            if(totalMedals[cPos]> totalMedals[max])
            {
                max = cPos;
            }
            int hold = totalMedals[count];
            totalMedals[count] = totalMedals[max];
            totalMedals[max] = hold;

            char holdString[100];
            strcpy(holdString, countryNames[count]);
            strcpy(countryNames[count], countryNames[max]);
            strcpy(countryNames[max], holdString);
        }
            //print the top 3
            printf("\n");
            printf("Rank top 3 countries based on gold medals: \n");
            for(int p = 0;p<3;p++){
            printf("%s, (%d) \n", countryNames[count], totalMedals[max]);
        } 
    }
};

// case 7
void rankTopThreeByMedal (int country [COUNTRIES] [MEDALCAT], char countryNames [COUNTRIES][MAX_LENGTH_CNAME]){
    int maxOne = 0;
    int maxTwo = 0;
    int maxThree = 0;
    int indexOne;
    int indexTwo;
    int indexThree;

    printf("Rank Top Three by gold medals won\n");

    for(int i = 0; i < COUNTRIES; i++){
        if(country[i][0] > maxOne){
            maxOne = country[i][0];
            indexOne = i;
        }
        if(country[i][0] > maxTwo && country[i][0] < maxOne){
            maxTwo = country[i][0];
            indexTwo = i;
        }
        if(country[i][0] > maxThree && country[i][0] < maxTwo){
            maxThree = country[i][0];
            indexThree = i;
        }
    }
    printf("%s: (%d)\n", countryNames[indexOne], maxOne);
    printf("%s: (%d)\n", countryNames[indexTwo], maxTwo);
    printf("%s: (%d)\n", countryNames[indexThree], maxThree);
};

// case 8
int findAllWithNoXMedals (int country [COUNTRIES] [MEDALCAT], int indexMedal, int indexOfCountries [COUNTRIES]){

};

// case 9
int findAllWithOnlyXMedals (int country [COUNTRIES][MEDALCAT], int indexMedal, int indexOfCountries [COUNTRIES]){

};

// case 10
int findCountryIndexWithMinOrMaxLength (int minOrMax, char countryNames [COUNTRIES][MAX_LENGTH_CNAME]){
    int resultIdx = 0;
    for (int i = 1; i < COUNTRIES; i++)
    {
        if (minOrMax == 1)
        {
    
            if (strlen(countryNames[i]) < strlen(countryNames[resultIdx]))
                
                resultIdx = i;
        }
        else if (minOrMax == 2)
        {
      
            if (strlen(countryNames[i]) > strlen(countryNames[resultIdx]))
               
                resultIdx = i;
        }
    }

    return resultIdx;
};
