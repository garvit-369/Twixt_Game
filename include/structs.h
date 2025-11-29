#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum box_value {
    p1_peg='O',
    p2_peg='X',
    empty='.'
} box_value;

typedef enum person {
    p1='O',
    p2='X'
} person;

typedef struct links {
    int count;
    int arr[8][2];
} links;

typedef struct cordinate{
    int x1;
    int y1;
    int x2;
    int y2;
} cordinate;

typedef struct state {
    person player;
    box_value board[24][24];
    links a[24][24];
    links b[24][24];
} state;





#endif