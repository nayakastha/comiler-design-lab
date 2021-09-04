// Write a C program that will behave as a deterministic finite automata which accepts strings of odd number 0s and even number of 1s.
// The program should take a string as input and print whether the string is accepted or rejected.

// There are 4 states q0, q1, q2, q3 where q0 is the initial state and q3 is the final state.
// The transition table of the above DFA is as follows:
//Current state	Final state
//               0  	1
//        q0	q3	   q1
//        q1	q2	   q0
//        q2	q1	   q3
//        q3	q0	   q2

// Example Output:

// Input String: 1101010101
// Output:
// The string is rejected

// Input String: 010101010
// Output:
// The string is accepted


#include <string.h>
#include <stdio.h>



// Function to check whether the given
// string is accepted by DFA or not
void checkValidDFA(char* s)
{
	
	int initial_state = 0;
    int final_state;
	int previous_state = 0;

	
	for (int i = 0; i < strlen(s); i++) {
		
		if ((s[i] == '1'
			&& previous_state == 1)
			|| (s[i] == '0'
				&& previous_state == 3)) {
			final_state = 0;
		}
		else if ((s[i] == '0'
				&& previous_state == 2)
				|| (s[i] == '1'
					&& previous_state == 0)) {
			final_state = 1;
		}
		else if ((s[i] == '0'
				&& previous_state == 1)
				|| (s[i] == '1'
					&& previous_state == 3)) {
			final_state = 2;
		}
		else if ((s[i] == '0'
				&& previous_state == 0)
				|| (s[i] == '1'
					&& previous_state == 2)) {
			final_state = 3;
		}

		
		previous_state = final_state;
	}

	
	if (final_state == 3) {
        printf("\nThis string is accepted");
		
	}	
	else {
		 printf("\nThis string is rejected");
	}
}


int main()
{
    char str[100];  
    printf("\nEnter the string to be tested-  ");
    scanf("%[^\n]s",str);
    	
	checkValidDFA(str);
 

	return 0;
}
