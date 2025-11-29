#ifndef INTERFACE_H
#define INTERFACE_H

#include "structs.h"

void initialising_board(state *status);
void display(state *status);
void scan_move(state *status,char name[],int *x,int *y);


#endif