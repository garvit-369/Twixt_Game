#include "logic.h"

int recursion(int dp[][24],links link_board[][24],int player,int i,int j) {
    if(player==0 && i==23) return 1;
    if(player==1 && j==23) return 1;

    if(dp[i][j]!=0) return (dp[i][j]==1)?1:0;
    dp[i][j]=2;
    
    for(int a=0;a<(link_board[i][j].count);a++) {
        if(i==link_board[i][j].arr[a][0] && j==link_board[i][j].arr[a][1]) continue;
        int dum=recursion(dp,link_board,player,link_board[i][j].arr[a][0],link_board[i][j].arr[a][1]);
        if(dum==1) {dp[i][j]=1;return 1;}
    }

    dp[i][j]=-1;
    return -1;
}


int win_check(state *status, int player) {
    int dp[24][24]={0};

    if(player==0) {
        for(int a=0;a<24;a++) {
            int dum=recursion(dp,status->a,player,0,a);
            if(dum==1) {dp[0][a]=1;return 1;}
        }
    }

    else if(player==1) {
        for(int a=0;a<24;a++) {
            int dum=recursion(dp,status->b,player,a,0);
            if(dum==1) {dp[a][23]=1;return 1;}
        }
    }
    return -1;
}

int circling_way(int x1, int y1, int x2, int y2, int x3, int y3) {
    int val=(y2-y1)*(x3-x2)-(x2-x1)*(y3-y2);
    if (val==0) return 0;
    return (val>0)?1:2;
}


int feasibility(int x1, int y1, int x2, int y2, cordinate *link_present) {
    int o1 = circling_way(x1, y1, x2, y2, link_present->x1, link_present->y1);
    int o2 = circling_way(x1, y1, x2, y2, link_present->x2, link_present->y2);
    int o3 = circling_way(link_present->x1, link_present->y1, link_present->x2, link_present->y2, x1, y1);
    int o4 = circling_way(link_present->x1, link_present->y1, link_present->x2, link_present->y2, x2, y2);

    if (o1 != o2 && o3 != o4) return 0;
    return 1;
}

void link_check(state *status,cordinate link[],int *count,int x,int y) {
    int a1[8]={-2,-1,-2,+1,+2,+1,+2,-1};
    int a2[8]={-1,-2,+1,-2,+1,+2,-1,+2};

    int neighx,neighy;
    int flag=0;
    for(int a=0;a<8;a++) {
        neighx=x+a1[a];
        neighy=y+a2[a];

        if (neighx<0 || neighx>23 || neighy<0 || neighy>23) continue;
        if(status->board[neighy][neighx]!=(box_value)(status->player)) continue;

        int dum=1;
        for(int b=0;b<(*count);b++) {
            cordinate existing=link[b];
            
            if ((x==existing.x1 && y==existing.y1) ||
                (x==existing.x2 && y==existing.y2) ||
                (neighx==existing.x1 && neighy==existing.y1) ||
                (neighx==existing.x2 && neighy==existing.y2)) {
                continue;
            }
            dum=feasibility(x,y,neighx,neighy,link+b);
            if(dum==0) break;
        }
        
        if (dum==1) {
            flag=1;
            link[*count]=(cordinate){x,y,neighx,neighy};
            *count=(*count)+1;

            if(status->player==p1) {
                int val1=(int)(status->a[y][x]).count;
                (status->a[y][x]).arr[val1][0]=neighy;
                (status->a[y][x]).arr[val1][1]=neighx;
                (status->a[y][x]).count++;

                int val2=(int)(status->a[neighy][neighx]).count;
                (status->a[neighy][neighx]).arr[val2][0]=y;
                (status->a[neighy][neighx]).arr[val2][1]=x;
                (status->a[neighy][neighx]).count++;
            }
            else if(status->player==p2) {
                int val1=(int)(status->b[y][x]).count;
                (status->b[y][x]).arr[val1][0]=neighy;
                (status->b[y][x]).arr[val1][1]=neighx;
                (status->b[y][x]).count++;

                int val2=(int)(status->b[neighy][neighx]).count;
                (status->b[neighy][neighx]).arr[val2][0]=y;
                (status->b[neighy][neighx]).arr[val2][1]=x;
                (status->b[neighy][neighx]).count++;
            }
            printf("Link created between %c%d and %c%d\n",x+'A',y+1,neighx+'A',neighy+1);
        }
    }
    if(flag==1) {
        printf("Press Enter to continue....");
        getchar();
    }
}















