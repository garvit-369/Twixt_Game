#include "toss.h"
#include "interface.h"
#include "logic.h"
#include "structs.h"

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
    printf("Press Enter to continue....");
    getchar();
    printf("-----------------------------------------------------------------------------------------------------------\n\n");
    



    state *status=malloc(sizeof(state));
    initialising_board(status);

    int count=0;
    cordinate link[600]={0};

    memset(link,-1,sizeof(link));
    int x,y;
    for(int a=0;;a=(a+1)%2) {
        printf("--- Current Status ---\n");
        status->player=(a==0)?p1:p2;
        char *name=(a==0)?name1:name2;

        display(status);
        printf("*%s needs to touch both single stranded line.\n*%s needs to touch both double stranded line.\n",name1,name2);
        scan_move(status,name,&x,&y);

        link_check(status,link,&count,x,y);
        
        int dum=win_check(status,a);
        if(dum==1) {
            printf("%s WON the game!!!\n\n",name);
            printf("-----------------------------------------------------------------------------------------------------------\n\n");
            break;
        }
        printf("-----------------------------------------------------------------------------------------------------------\n\n");
    }
    

    free(status);
    return 0;
}