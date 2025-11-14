#ifndef INTERFACE_H
#define INTERFACE_H

typedef enum box_value {
    p1_peg='O',
    p2_peg='X',
    empty='.'
} box_value;

typedef enum person {
    p1,
    p2
} person;

typedef struct state {
    person player;
    box_value board[24][24];
} state;

void initialising_array(state *status);
void display(state *status);
void scan_move_player1(state *status,char name_player1[]);
void scan_move_player2(state *status,char name_player2[]);


#endif