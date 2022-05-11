#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    printf("Welcome to Govisetha lottery !\n\n");

    //user enter their own selection of numbers
    int selectedNumbers[7];
    for(int i = 0; i<7; i++){
    printf("Type a number: \n");
    scanf(" %d", &selectedNumbers[i]);
    }

    //sorting the user's array

    int temp1 = 0;

    //Calculate length of user's array selectedNumbers
    int length1 = sizeof(selectedNumbers)/sizeof(selectedNumbers[0]);

    //Displaying elements of user's original array
    printf("\nElements of user's original array: \n");
    for (int i = 0; i < length1; i++) {
        printf("%d ", selectedNumbers[i]);
    }

    //Sort the user's array in ascending order
    for (int i = 0; i < length1; i++) {
        for (int j = i+1; j < length1; j++) {
           if(selectedNumbers[i] > selectedNumbers[j]) {
               temp1 = selectedNumbers[i];
               selectedNumbers[i] = selectedNumbers[j];
               selectedNumbers[j] = temp1;
           }
        }
    }

    printf("\n");

    //Displaying elements of user's array after sorting
    printf("\nUser's array sorted in ascending order: \n");
    for (int i = 0; i < length1; i++) {
        printf("%d ", selectedNumbers[i]);
    }

    //Executing the lottery engine to select winning numbers
    int winningNumbers[7];
    srand(time(0));

    for(int i = 0; i<7; i++){
        winningNumbers[i]=rand()%17;
    }

    //sorting the winning array

    int temp = 0;

    //Calculate length of winning array arr
    int length = sizeof(winningNumbers)/sizeof(winningNumbers[0]);

    //Displaying elements of original array
    printf("\n\nOriginal winning array: \n");
    for (int i = 0; i < length; i++) {
        printf("%d ", winningNumbers[i]);
    }

    //Sort the array in ascending order
    for (int i = 0; i < length; i++) {
        for (int j = i+1; j < length; j++) {
           if(winningNumbers[i] > winningNumbers[j]) {
               temp = winningNumbers[i];
               winningNumbers[i] = winningNumbers[j];
               winningNumbers[j] = temp;
           }
        }
    }

    printf("\n");

    //Displaying elements of array after sorting
    printf("\nWinning array sorted in ascending order: \n");
    for (int i = 0; i < length; i++) {
        printf("%d ", winningNumbers[i]);
    }


    //Selecting matching numbers
    int matchingNumbers[]={0,0,0,0,0,0,0};
    for (int i = 0; i < length; i++) {
        for (int j=0; j<length; j++){
            if(winningNumbers[i]==selectedNumbers[j]){
                matchingNumbers[i]=winningNumbers[i];
            }
        }
    }
    //Displaying matching numbers
    int len = sizeof(matchingNumbers)/sizeof(matchingNumbers[0]);
    printf("\n\nMatched numbers: ");
    for(int i=0; i< len; i++){
        if(matchingNumbers[i]!=0){
        printf(" %d ", matchingNumbers[i]);
        }
    }
    printf(" \n ");

    //save to txt

        char *filename = "Results.txt";

        // open the file for writing
        FILE *fp = fopen(filename, "w");
        if (fp == NULL)
        {
            printf("Error opening the file %s", filename);
            return -1;
        }
        // write to the text file
        fprintf(fp, "Draw sorted: ");
        for (int i = 0; i < 7; i++){
            fprintf(fp, " %d ", winningNumbers[i]);
        }

        fprintf(fp, "\n");

        fprintf(fp, "User’s sorted: ");
        for (int i = 0; i < 7; i++){
            fprintf(fp, " %d ", selectedNumbers[i]);
        }

        fprintf(fp, "\n");

        fprintf(fp, "Matching numbers: ");
        for (int i = 0; i < 7; i++){
            if(matchingNumbers[i]!=0)
            fprintf(fp, " %d ", matchingNumbers[i]);
        }
        // close the file
        fclose(fp);

        return 0;
    }
