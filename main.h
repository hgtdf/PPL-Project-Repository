#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool find_dest(state srcstate, char currchar){
    if (srcstate == transition_table[i].src_state && currchar == transition_table[i].reqChar){
		return true;
	}
	else if (i == 7){ // 7 refers to transition table size
		return false;
	}else
		i++;
		find_dest(srcstate, currchar);
}

int get_dest(){
	int tobereturned = transition_table[i].dest_state;
	i = 0;
	return tobereturned;
}

void accept (){
}

void printcontents(char *c, int counter){
    for (int i = 0; i < counter; i++) {
      printf("%c", c[i]);
      }
}

char openfile (char *pplfile){
    int counter = 0;
	char* chpt;
    char ch;
    FILE* fp;

      fp = fopen(pplfile, "r");
      if (fp == NULL) {
    		printf("Can't open file\n");
    	}

      	while ((ch = fgetc(fp)) != EOF) {
        counter++;
    	}
      
		rewind(fp);

    	chpt = malloc(counter * sizeof(char));

    	fread(chpt, counter * sizeof(char), 1, fp);

    	printcontents(chpt, counter);

      fclose(fp);
      free(chpt);
}

int transition (state currstate, char currchar){
	if (find_dest(currstate, currchar) == true){
		currstate = get_dest();
		printf("Current state is: q%d\n", currstate);
		return currstate;
	}else{
		return -1;
	}
}