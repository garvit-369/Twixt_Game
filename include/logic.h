#ifndef LOGIC_H
#define LOGIC_H

#include "structs.h"

int recursion(int dp[][24],links link_board[][24],int player,int i,int j);
int win_check(state *status, int player);
int circling_way(int x1, int y1, int x2, int y2, int x3, int y3);
int feasibility(int x1, int y1, int x2, int y2, cordinate *link_present);
void link_check(state *status,cordinate link[],int *count,int x,int y);



#endif