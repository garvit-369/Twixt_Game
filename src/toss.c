#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "toss.h"

void toss(char name1[], char name2[]) {

    int choice=-1,result=-1;
    printf("%s, will call the toss.\n",name1);
    printf("Enter 0 for Heads or 1 for Tails: ");
    scanf("%d",&choice);
    while (getchar() != '\n'); 
    while (choice!=0 && choice!=1) {
        printf("Invalid choice. Please enter 0 for Heads or 1 for Tails: ");
        while (getchar() != '\n'); 
        scanf("%d",&choice);
    }
    printf("\nFlipping the coin...\n");

    srand(time(NULL)); 
    result = rand() % 2; 

    if (result==0) printf("The coin landed on... Heads!\n\n");
    else printf("The coin landed on... Tails!\n\n");

    if(choice==result) {
        printf("%s wins the toss and will play first!\n", name1);
    }
    else {
        printf("%s wins the toss and will play first!\n", name2);
        char tmp[101];
        strncpy(tmp,name1,100);
        strncpy(name1,name2,100);
        strncpy(name2,tmp,100);
    }
}