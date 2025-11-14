#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface.h"

void initialising_array(state *status) {
    for(int a=0;a<24;a++) {
        for(int b=0;b<24;b++) {
            (status->board)[a][b]=empty;
        }
    }
}

void display(state *status) {
    printf("\n");

    printf("        ‖");
    for(int a=0;a<87;a++) {printf(" ");}
    printf("‖\n");

    printf("      ");
    printf("%c ‖ %c ",'A','B');
    for(int a=2;a<23;a++) {
        printf("  %c ",'A'+a);
    }
    printf("‖ %c\n",'X');

    printf("        ‖");
    for(int a=0;a<87;a++) {printf(" ");}
    printf("‖\n");

    printf("   1  ");
    printf("  ‖ %c ",(status->board)[0][1]);
    for(int a=2;a<23;a++) {
        printf("  %c ",(status->board)[0][a]);
    }
    printf("‖    1\n");

    printf("--------+");
    for(int a=1;a<88;a++) {
        printf("-");
    }
    printf("+--------");
    printf("\n");



    for(int a=1;a<23;a++) {
        printf("  %2d  %c ‖ ",a+1,(status->board)[a][0]);
        for(int b=1;b<22;b++) {
            printf("%c   ",(status->board)[a][b]);
        }
        printf("%c ‖ ",(status->board)[a][22]);
        printf("%c",(status->board)[a][23]);
        printf("  %d\n",a+1);
        if(a<22) {
            printf("        ‖");
            for(int b=0;b<87;b++) {printf(" ");}
            printf("‖\n");
        }
        else {
            printf("--------+");
            for(int b=0;b<87;b++) {printf("-");}
            printf("+--------\n");     
        }
    }

    printf("  24  ");
    printf("  ‖ %c ",(status->board)[23][1]);
    for(int a=2;a<23;a++) {
        printf("  %c ",(status->board)[23][a]);
    }
    printf("‖    24\n");

    printf("        ‖");
    for(int a=0;a<87;a++) {printf(" ");}
    printf("‖   \n");

    printf("      ");
    printf("%c ‖ %c ",'A','B');
    for(int a=2;a<23;a++) {
        printf("  %c ",'A'+a);
    }
    printf("‖ %c\n",'X');

    printf("        ‖");
    for(int a=0;a<87;a++) {printf(" ");}
    printf("‖\n");

}

void scan_move_player1(state *status,char name_player1[]) {
    char str[4];
    printf("Play %s (O): ",name_player1);
    scanf("%s",str);

    recheck:
    while(str[0]<'A' || str[0]>'X' || atoi(str+1)>24 || atoi(str+1)<1 || 
    (str[0]=='A' && (atoi(str+1)==1 || atoi(str+1)==24)) || (str[0]=='X' && (atoi(str+1)==1 || atoi(str+1)==24))) {
        printf("Incorrect move. Please re-enter your move again: ");
        scanf("%s",str);
    }
    int row=(int)(str[0]-'A');
    int col=atoi(str+1)-1;

    if ((status->board)[col][row]!='.') {
        printf("Box is not empty, Please re-enter your move again: ");
        scanf("%s",str);
        goto recheck;
    }

    (status->board)[col][row]=p1_peg;
}


void scan_move_player2(state *status,char name_player2[]) {
    char str[4];
    printf("Play %s (X): ",name_player2);
    scanf("%s",str);

    recheck:
    while(str[0]<'A' || str[0]>'X' || atoi(str+1)>24 || atoi(str+1)<1 || 
    (str[0]=='A' && (atoi(str+1)==1 || atoi(str+1)==24)) || (str[0]=='X' && (atoi(str+1)==1 || atoi(str+1)==24))) {
        printf("Incorrect move. Please re-enter your move again: ");
        scanf("%s",str);
    }
    int row=(int)(str[0]-'A');
    int col=atoi(str+1)-1;

    if ((status->board)[col][row]!=empty) {
        printf("Box is not empty, Please re-enter your move again: ");
        scanf("%s",str);
        goto recheck;
    }

    (status->board)[col][row]=p2_peg;
}