#include "main.h"

int main (){
	char currchar = '^';
	state currstate = q0;

	printf("my current state is q%d\n", currstate);
	currstate = lookup_dest(currstate, currchar);
	printf("my current state is q%d", currstate);
}