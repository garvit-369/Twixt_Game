#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface.h"

void initialising_array(char arr[][25]) {
    for(int a=0;a<24;a++) {
        strcpy(arr[a],"........................");
    }
}

void display(char arr[][25]) {
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

    printf("  1   ");
    printf("%c ‖ %c ",arr[0][0],arr[0][1]);
    for(int a=2;a<23;a++) {
        printf("  %c ",arr[0][a]);
    }
    printf("‖ %c   1\n",arr[0][23]);

    printf("--------+");
    for(int a=1;a<88;a++) {
        printf("-");
    }
    printf("+--------");
    printf("\n");



    for(int a=1;a<23;a++) {
        if(a>8) printf("  %d  %c ‖ ",a+1,arr[a][0]);
        if(a<=8) printf("  %d   %c ‖ ",a+1,arr[a][0]);
        for(int b=1;b<22;b++) {
            printf("%c   ",arr[a][b]);
        }
        printf("%c ‖ ",arr[a][22]);
        printf("%c",arr[a][23]);
        if(a>8) printf("  %d\n",a+1);
        if(a<=8) printf("   %d\n",a+1);
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
    printf("%c ‖ %c ",arr[23][0],arr[23][1]);
    for(int a=2;a<23;a++) {
        printf("  %c ",arr[23][a]);
    }
    printf("‖ %c  24\n",arr[23][23]);

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


void scan_move_player1(char arr[][25],char name_player1[]) {
    char str[4];
    printf("Play %s: ",name_player1);
    scanf("%s",str);

    recheck:
    while(str[0]<'A' || str[0]>'X' || atoi(str+1)>24 || atoi(str+1)<1) {
        printf("Incorrect move. Please re-enter your move again: ");
        scanf("%s",str);
    }
    int row=(int)(str[0]-'A');
    int col=atoi(str+1)-1;

    if (arr[col][row]!='.') {
        printf("Box is not empty, Please re-enter your move again: ");
        scanf("%s",str);
        goto recheck;
    }

    arr[col][row]='O';
}


void scan_move_player2(char arr[][25],char name_player2[]) {
    char str[4];
    printf("Play %s: ",name_player2);
    scanf("%s",str);

    recheck:
    while(str[0]<'A' || str[0]>'X' || atoi(str+1)>24 || atoi(str+1)<1) {
        printf("Incorrect move. Please re-enter your move again: ");
        scanf("%s",str);
    }
    int row=(int)(str[0]-'A');
    int col=atoi(str+1)-1;

    if (arr[col][row]!='.') {
        printf("Box is not empty, Please re-enter your move again: ");
        scanf("%s",str);
        goto recheck;
    }

    arr[col][row]='X';
}