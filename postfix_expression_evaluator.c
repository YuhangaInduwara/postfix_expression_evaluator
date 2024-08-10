#include<stdio.h> // calling standerd input output header files
#include<stdlib.h> // calling standerd libraries header files
#define MAX 100 // define the MAX variable with value 100
int top = -1; // initialize top with value -1
char stack_reg[MAX]; // initialize the register as stack_reg[MAX] (MAX = 100)

/* isFull function for check the overflow condition */
int isFull() {
	if(top == MAX -1)
		return 1;
	else
		return 0;
}

/* isEmpty function for check the underflow condition */
int isEmpty() {
	if(top == -1)
		return 1;
	else
		return 0;
}

/* push function for push or Load(LD) elements to the stack_reg{MAX} */
void push(char data) {
	if(top == MAX -1) { // checks the overflow condition
		printf("Register is full!\n");
		exit(1);
	}
	top = top + 1; // increment top by one
	stack_reg[top] = data; // assign the data value to the tos 
}

/* pop function for delete and return the top most element in the stack_reg[MAX] */
char pop() {
	char value;
	if(top == -1) { // checks the underflow condition
		printf("\nInvalid postfix ststement!\n");
		exit(1);
	}
	value = stack_reg[top]; // assign the top value of the stack to value 
	top = top - 1; // decrement the top by one
	return value; // return the value
}

/* peek function for return the top most element in the stack_reg[MAX] without deleting it*/
char peek() {
	if(isEmpty()) { // checks the underflow condition
		printf("\nInvalid postfix ststement!\n");
		exit(1);
	}
	return stack_reg[top]; // return the top value of the stack
}


int main() {
	char arr[MAX], TEMP = 1, temp; // initializing an array for get inputs, TEMP for TEMP1/TEMP2/.. veriables, temp for store poped values
	int i, n; // initializing i for for loops and n for store currnt i value

	printf("Enter the postfix expression : "); // print "Enter the postfix expression : "
	/* get the input from the user */
	for(i = 0; i < MAX; i++) {
		scanf("%c", &arr[i]);
		/*escape if user press enter */
		if(arr[i] == 10) {
			break;
		}
	}
	printf("\n"); // print a new line
	n = i; // store the current i value (after escaping from the for loop)

	for(i = 0; i < n; i++) {
		if((arr[i] > 64 && arr[i] < 91) || (arr[i] > 96 && arr[i] < 123) || (arr[i] > 47 && arr[i] < 58) ) { // check for non arithmetic characters
			push(arr[i]); // push non arithmetic characters to the stack_reg[]
		} else if(arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/') { // check for arithmetic characters
			temp = pop(); // if arithmatic character detected alling the pop funtion and store the return value in temp 
			/* check the top most value of the stack */
			if(peek() > 0 && peek() < 9) { // if it is a number prints LD and TEMP with the corresponding number
				printf("LD  TEMP%d\n", peek());
			} else { // if it is not a number print LD and the top most value
				printf("LD  %c\n", peek());
			}
			
			// checking the type of the aritmetic character
			if(arr[i] == '+') {
				/* check the temp value for numeric or not */
				if(temp > 0 && temp < 9) { // if it is a number prints AD and TEMP with the corresponding number
					printf("AD  TEMP%d\n", temp);
				} else { // if it is not a number prints AD and temp value
					printf("AD  %c\n", temp);
				}
			} else if(arr[i] == '-') { 
				/* check the temp value for numeric or not */
				if(temp > 0 && temp < 9) { // if it is a number prints SB and TEMP with the corresponding number
					printf("SB  TEMP%d\n", temp);
				} else { // if it is not a number prints SB and temp value
					printf("SB  %c\n", temp);
				}
			} else if(arr[i] == '*') { 
				/* check the temp value for numeric or not */
				if(temp > 0 && temp < 9) { // if it is a number prints ML and TEMP with the corresponding number
					printf("ML  TEMP%d\n", temp);
				} else { // if it is not a number prints ML and temp value
					printf("ML  %c\n", temp);
				}
			} else if(arr[i] == '/') { 
				/* check the temp value for numeric or not */
				if(temp > 0 && temp < 9) { // if it is a number prints DV and TEMP with the corresponding number
					printf("DV  TEMP%d\n", temp);
				} else { // if it is not a number prints DV and temp value
					printf("DV  %c\n", temp);
				}
			}

			pop(); // call pop function
			push(TEMP); // push the TEMP value (TEMP1, TEMP2 ...) to the stack
			printf("ST  TEMP%d\n", TEMP); // print the current TEMP value (TEMP1, TEMP2 ...)
			TEMP++; // increment the TEMP value by one
		}
	}
	
	/* check for final stack not empty and print invalid statement*/
	if(top > 0){
		printf("\nInvalid postfix ststement!\n");
	}
}




