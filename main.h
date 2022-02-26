#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

int i=0;


typedef enum states{
	q0, q1, q2, q3, q4, q5, q6, q7, q8
}state;

struct transition {
	state src_state;
	char reqChar;
	state dest_state;
};

struct transition transition_table [] = {
	{q0, '+', q2}, // 0
	{q0, '-', q3}, // 1
	{q0, '*', q4}, // ...
	{q0, '/', q5},
	{q0, '%', q6},
	{q0, '^', q7},
	{q2, '+', q8},
};

bool find_dest(state srcstate, char currchar){//checks if specified transition is present in transitions_table[]
    printf("ako si find dest, tinawag mo ako ang laman ng i ko ngayon ay %d hinahanap ko si srcstate: %d, at si currchar: %c\n", i, srcstate, currchar);
	if (srcstate == transition_table[i].src_state && currchar == transition_table[i].reqChar){
		return true;
	}
	else if (i == 6){ // The number here, refers to transition_table[] size
		i=0;
		return false;
	}else
		i++;
		find_dest(srcstate, currchar);
}

void accept (char lexeme[], int buffcount){
	int i;
	for (i=0; i<buffcount; i++){
		printf("%c", lexeme[i]);
	}
	printf("\n");
}

void reset (int *buffcount, state *currstate){
	*currstate = q0;
	*buffcount = 0;
}

int get_dest(){	//gets the dest_state of the specified transition
	int tobereturned = transition_table[i].dest_state;
	i = 0;
	return tobereturned;
}

int transition (state currstate, char currchar){ //function for transitioning states into another state
	if (find_dest(currstate, currchar) == true){
		currstate = get_dest();
		return currstate;
	}else{
		return 1;
	}
}

int checkfile (char *plfile){ // check for file's filetype
    char extn[] = ".simp";
    int len1 = strlen(plfile);
    int len2 = strlen(extn);
    int found = 0;
    
    if(len1 >= len2) {
        for(int s1=0, s2=0; s1<len1; s1++) {
            do {
                if(plfile[s1] == extn[s2]) {
                    if(++found == len2) return 1;
                    s1++;
                    s2++;
                }
                else {
                s1 -= found; 
                found = 0; 
                s2 = 0;
                }
            } while(found);
        }
        printf("File extension not recognized.\n");
        exit(1);
    }
    else {
        printf("File invalid.");
        exit(1);
    }
}