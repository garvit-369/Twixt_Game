#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "toss.h"
#include "interface.h"

int main() {

    printf("\nWelcome To TwixT Game:-\n");
    printf("Note: Please ensure you read all the instructions provided in TwixT_Game/README.md\n\n");

    printf("--- Player Info ---\n");
    char name1[101],name2[101];
    printf("Enter name of Player 1: ");
    fgets(name1,100,stdin);
    name1[strcspn(name1,"\n")] = 0;
    printf("Enter name of Player 2: ");
    fgets(name2,100,stdin);
    name2[strcspn(name2,"\n")] = 0;

    while(strcmp(name1,name2)==0) {
        printf("Name of Player 1 and Player 2 can't be same.\n");
        printf("Re-enter name of Player 2: ");
        fgets(name2,100,stdin);
        name2[strcspn(name2,"\n")] = 0;
    }
    printf("-----------------------------------------------------------------------------------------------------------\n\n");

    printf("--- Coin Toss ---\n");
    toss(name1,name2);
    printf("-----------------------------------------------------------------------------------------------------------\n\n");


    printf("The board is set, the pieces are still... let the contest of wits begin!\n");
    printf("Get ready, %s!\n",name1);
    printf("Prepare yourself, %s!\n",name2);
    printf("-----------------------------------------------------------------------------------------------------------\n\n");
    
    char arr[24][25];
    initialising_array(arr);

    while(1) {
        printf("--- Current Status ---\n");
        display(arr);
        printf("*%s needs to touch both single stranded line.\n*%s needs to touch both double stranded line.\n",name1,name2);
        printf("Please use Ctrl+C to exit, since Game Logic is not ready.\n");            //To remove
        scan_move_player1(arr,name1);
        printf("-----------------------------------------------------------------------------------------------------------\n\n");

        //GAME LOGIC CHECK

        printf("--- Current Status ---\n");
        display(arr);
        printf("*%s needs to touch both single stranded line.\n*%s needs to touch both double stranded line.\n",name1,name2);
        printf("Please use Ctrl+C to exit, since Game Logic is not ready.\n");            //To remove
        scan_move_player2(arr,name2);
        printf("-----------------------------------------------------------------------------------------------------------\n\n");

        //GAME LOGIC CHECK
    }
    
    return 0;
}