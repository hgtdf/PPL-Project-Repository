#include <stdio.h>
#include <stdlib.h>

int i = 0;

typedef enum states{
	q0, q1, q2, q3, q4, q5, q6, q7
}state;

struct transition {
	state src_state;
	char reqChar;
	state dest_state;
};

struct transition transition_table [] = {
	{q0, '+', q2},
	{q0, '-', q3},
	{q0, '*', q4},
	{q0, '/', q5},
	{q0, '%', q6},
	{q0, '^', q7}
};

int lookup_dest (state srcstate, char currchar){
    if (transition_table[i].src_state == srcstate && transition_table[i].reqChar == currchar){
        return transition_table[i].dest_state;
    }
    else{
        i++;
        lookup_dest (srcstate, currchar);
    }
    
}