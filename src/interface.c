#include "interface.h"

void initialising_board(state *status) {
    for(int a=0;a<24;a++) {
        for(int b=0;b<24;b++) {
            (status->board)[a][b]=empty;
        }
    }
    for(int i=0;i<24;i++) {
        for(int j=0;j<24;j++) {
            status->a[i][j].count=0;
        }
    }
    for(int i=0;i<24;i++) {
        for(int j=0;j<24;j++) {
            status->b[i][j].count=0;
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

void scan_move(state *status,char name[],int *x,int *y) {
    char str[6];
    printf("Play %s (%c): ",name,status->player==p1?'O':'X');
    scanf("%4s",str);
    while ((getchar())!='\n');

    recheck:
    while(str[0]<'A' || str[0]>'X' || atoi(str+1)>24 || atoi(str+1)<1 || 
    (str[0]=='A' && (atoi(str+1)==1 || atoi(str+1)==24)) || (str[0]=='X' && (atoi(str+1)==1 || atoi(str+1)==24))) {
        printf("Incorrect move. Please enter your move again: ");
        scanf("%s",str);
        while ((getchar())!='\n');
    }
    int col=(int)(str[0]-'A');
    int row=atoi(str+1)-1;
    if ((status->board)[row][col]!='.') {
        printf("Box is not empty, Please enter your move again: ");
        scanf("%s",str);
        while ((getchar())!='\n');
        goto recheck;
    }
    if((status->player==p1) && (col==0 || col==23)) {
        printf("Can't plant your peg to opponents area, Please enter your move again: ");
        scanf("%s",str);
        while ((getchar())!='\n');
        goto recheck;
    }
    if((status->player==p2) && (row==0 || row==23)) {
        printf("Can't plant your peg to opponents area, Please enter your move again: ");
        scanf("%s",str);
        while ((getchar())!='\n');
        goto recheck;
    }

    (status->board)[row][col]=(box_value)(status->player);
    *x=col;
    *y=row;
}