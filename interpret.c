#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Checks to see if input is a valid register and which register we want
int regChecker(char* input){
   // ax = 1, bx = 2, cx = 3, dx = 4
   int output = 0;
   if((strcmp(input, "ax")  == 0)){
       output = 1;
   }
   else if(strcmp(input, "bx")  == 0){
       output = 2;
   }
   else if(strcmp(input, "cx")  == 0){
       output = 3;
   }
   else if(strcmp(input, "dx")  == 0){
       output = 4;
   }
   return output;
}


// Checks for different types of assembly instructions
int readChecker(char* input){
   int output = 0;
   if((strcmp(input, "read")  == 0)){
       output = 1;
   }
   return output;
}

int printChecker(char* input){
   int output = 0;
   if((strcmp(input, "print")  == 0)){
       output = 1;
   }
   return output;
}

int movChecker(char* input){
   int output = 0;
   if((strcmp(input, "mov")  == 0)){
       output = 1;
   }
   return output;
}
int addChecker(char* input){
   int output = 0;
   if((strcmp(input, "add")  == 0)){
       output = 1;
   }
   return output;
}
int subChecker(char* input){
   int output = 0;
   if((strcmp(input, "sub")  == 0)){
       output = 1;
   }
   return output;
}
int mulChecker(char* input){
   int output = 0;
   if((strcmp(input, "mul")  == 0)){
       output = 1;
   }
   return output;
}
int divChecker(char* input){
   int output = 0;
   if((strcmp(input, "div")  == 0)){
       output = 1;
   }
   return output;
}


int jumpChecker(char* input){
   // jmp = 1, je = 2, jne = 3, jg = 4, jge = 5, jl = 6, jle = 7
   int output = 0;
   if((strcmp(input, "jmp")  == 0)){
       output = 1;
   }
   else if(strcmp(input, "je")  == 0){
       output = 2;
   }
   else if(strcmp(input, "jne")  == 0){
       output = 3;
   }
   else if(strcmp(input, "jg")  == 0){
       output = 4;
   }
   else if(strcmp(input, "jge")  == 0){
       output = 5;
   }
   else if(strcmp(input, "jl")  == 0){
       output = 6;
   }
   else if(strcmp(input, "jle")  == 0){
       output = 7;
   }
   return output;
}



// Moving Data
void* movFunc(int input, int* output){
   *output = input;
	return NULL;
}


// Arithemtic Operators
void* addFunc(int input, int *output){
   *output = input + *output;
	return NULL;
}

void* subFunc(int input, int *output){
   *output = *output - input;
	return NULL;
}

void* mulFunc(int input, int *output){
   *output = input * (*output);
	return NULL;
}

void* divFunc(int input, int *output){
   *output = input / (*output);
	return NULL;
}




int main(int argc, char* argv[])
{
	int i = 0, n = 0;

	// registers
	int ax = 0, bx = 0, cx = 0, dx = 0;
	
	char lineInput[30], lineInput2[30];
	char input[30], input2[30], input3[30], input4[30];
	int constIn = 0;

	char array[100][30];	
	
	// Opens assembly file 
	FILE* ptr = fopen(argv[1], "r");

	// Error Check
	if(ptr == NULL){
		printf("File isn't found\n");
		return 0;
	}

	while(fgets(lineInput2, 30, ptr) != NULL){
		strcpy(array[i], lineInput2);
		i+=1;
		n+=1;
	}
	
	i = 0;

	// Main Loop Which checks each command line argument
	while(i < n){
	
	strcpy(lineInput, array[i]);
	
	sscanf(lineInput, "%s", input);

	if(readChecker(input) == 1){
		sscanf(lineInput, "%s %s", input, input2);
		int check1 = regChecker(input2);
		if(check1 == 1){
			scanf("%d", &ax);
		}
		else if(check1 == 2){
			scanf("%d", &bx);
		}
		else if(check1 == 3){
			scanf("%d", &cx);
		}
		else if(check1 == 4){
			scanf("%d", &dx);
		}
		
		
	}
	else if(movChecker(input) == 1){
		sscanf(lineInput, "%s %s", input, input2);
		int check1 = regChecker(input2);
		// Checks if first argument is register or constant
		if(check1 == 0){
			constIn = atoi(input2);	
		}
		else if(check1 == 1){
			constIn = ax;
		}
		else if(check1 == 2){
			constIn = bx;
		}
		else if(check1 == 3){
			constIn = cx;
		}
		else if(check1 == 4){
			constIn = dx;	
		}
		
		
		sscanf(lineInput, "%s %s %s", input, input2, input3);

		// Second Input and Mov Function
		int check2 = regChecker(input3);
		if(check2 == 1){
			movFunc(constIn, &ax);	
		}
		else if(check2 == 2){
			movFunc(constIn, &bx);	
		}
		else if(check2 == 3){
			movFunc(constIn, &cx);	
		}
		else if(check2 == 4){
			movFunc(constIn, &dx);	
		}
		else{
			printf("The second argument (y) needs to be a register\n");	
		}
		
		
		
		
	}
	else if(addChecker(input) == 1){
		sscanf(lineInput, "%s %s", input, input2);
		int check1 = regChecker(input2);
		// Checks if first argument is register or constant
		if(check1 == 0){
			constIn = atoi(input2);	
		}
		else if(check1 == 1){
			constIn = ax;
		}
		else if(check1 == 2){
			constIn = bx;
		}
		else if(check1 == 3){
			constIn = cx;
		}
		else if(check1 == 4){
			constIn = dx;	
		}
		
		
		sscanf(lineInput, "%s %s %s", input, input2, input3);

		// Second Input and Add Function
		int check2 = regChecker(input3);
		if(check2 == 1){
			addFunc(constIn, &ax);	
		}
		else if(check2 == 2){
			addFunc(constIn, &bx);	
		}
		else if(check2 == 3){
			addFunc(constIn, &cx);	
		}
		else if(check2 == 4){
			addFunc(constIn, &dx);	
		}
		else if(check2 == 0){
			int output = atoi(input3);
			addFunc(constIn, &output);	
		}
		else{
			printf("There is an error in printing\n");
		}
		
	}
	else if(subChecker(input) == 1){
		sscanf(lineInput, "%s %s", input, input2);
		int check1 = regChecker(input2);
		// Checks if first argument is register or constant
		if(check1 == 0){
			constIn = atoi(input2);	
		}
		else if(check1 == 1){
			constIn = ax;
		}
		else if(check1 == 2){
			constIn = bx;
		}
		else if(check1 == 3){
			constIn = cx;
		}
		else if(check1 == 4){
			constIn = dx;	
		}
		
		
		sscanf(lineInput, "%s %s %s", input, input2, input3);

		// Second Input and Sub Function
		int check2 = regChecker(input3);
		if(check2 == 1){
			subFunc(constIn, &ax);	
		}
		else if(check2 == 2){
			subFunc(constIn, &bx);	
		}
		else if(check2 == 3){
			subFunc(constIn, &cx);	
		}
		else if(check2 == 4){
			subFunc(constIn, &dx);	
		}
		else if(check2 == 0){
			int output = atoi(input3);
			subFunc(constIn, &output);	
		}
		else{
			printf("There is an error in printing\n");
		}
		
	}
	else if(mulChecker(input) == 1){
		sscanf(lineInput, "%s %s", input, input2);
		int check1 = regChecker(input2);
		// Checks if first argument is register or constant
		if(check1 == 0){
			constIn = atoi(input2);	
		}
		else if(check1 == 1){
			constIn = ax;
		}
		else if(check1 == 2){
			constIn = bx;
		}
		else if(check1 == 3){
			constIn = cx;
		}
		else if(check1 == 4){
			constIn = dx;	
		}
		
		
		sscanf(lineInput, "%s %s %s", input, input2, input3);

		// Second Input and Mul Function
		int check2 = regChecker(input3);
		if(check2 == 1){
			mulFunc(constIn, &ax);	
		}
		else if(check2 == 2){
			mulFunc(constIn, &bx);	
		}
		else if(check2 == 3){
			mulFunc(constIn, &cx);	
		}
		else if(check2 == 4){
			mulFunc(constIn, &dx);	
		}
		else if(check2 == 0){
			int output = atoi(input3);
			mulFunc(constIn, &output);	
		}
		else{
			printf("There is an error in printing\n");
		}		
		
	}
	else if(divChecker(input) == 1){
		sscanf(lineInput, "%s %s", input, input2);
		int check1 = regChecker(input2);
		// Checks if first argument is register or constant
		if(check1 == 0){
			constIn = atoi(input2);	
		}
		else if(check1 == 1){
			constIn = ax;
		}
		else if(check1 == 2){
			constIn = bx;
		}
		else if(check1 == 3){
			constIn = cx;
		}
		else if(check1 == 4){
			constIn = dx;	
		}
		
		
		sscanf(lineInput, "%s %s %s", input, input2, input3);

		// Second Input and Div Function
		int check2 = regChecker(input3);
		if(check2 == 1){
			divFunc(constIn, &ax);	
		}
		else if(check2 == 2){
			divFunc(constIn, &bx);	
		}
		else if(check2 == 3){
			divFunc(constIn, &cx);	
		}
		else if(check2 == 4){
			divFunc(constIn, &dx);	
		}
		else if(check2 == 0){
			int output = atoi(input3);
			divFunc(constIn, &output);	
		}
		else{
			printf("There is an error in printing\n");
		}
		
	}
	else if(printChecker(input) == 1){
		sscanf(lineInput, "%s %s", input, input2);
		int checker = regChecker(input2);
		if(checker == 1){
			printf("%d\n", ax);	
		}
		else if(checker == 2){
			printf("%d\n", bx);
		}
		else if(checker == 3){
			printf("%d\n", cx);
		}
		else if(checker == 4){
			printf("%d\n", dx);
		}
		else if(checker == 0){
			int output = atoi(input2);
			printf("%d\n", output);
		}
		else{
			printf("There is an error in printing\n");
		}
	}
	
	else if(jumpChecker(input) != 0){
		// jmp = 1, je = 2, jne = 3, jg = 4, jge = 5, jl = 6, jle = 7
		int checker = jumpChecker(input);
		//jmp instruction
		if(checker == 1){
			sscanf(lineInput, "%s %s", input, input2);
			int val = atoi(input2);
			if(val <= n){
				i = val - 1;
			}
			else{
				printf("Jump location is invalid\n");
			}
		}
		//je instruction
		else if(checker == 2){
			sscanf(lineInput, "%s %s %s %s", input, input2, input3, input4);
			int x, y;
			int registerCheck = regChecker(input3);
			int registerCheck2 = regChecker(input4);
			
			// Checks to see if x value is a constant or register
			if(registerCheck == 0){
				x = atoi(input3);
			}
			else if(registerCheck == 1){
				x = ax;
			}
			else if(registerCheck == 2){
				x = bx;
			}
			else if(registerCheck == 3){
				x = cx;
			}
			else if(registerCheck == 4){
				x = dx;
			}
			
			// Checks to see if y value is a constant or register
			if(registerCheck2 == 0){
				y = atoi(input4);
			}
			else if(registerCheck2 == 1){
				y = ax;				
			}
			else if(registerCheck2 == 2){
				y = bx;	
			}
			else if(registerCheck2 == 3){
				y = cx;	
			}
			else if(registerCheck2 == 4){
				y = dx;	
			}

				// Comparison check 
				if(x == y){
					int val = atoi(input2);
					if(val <= n){
						i = val - 1;
					}
					else{
						printf("Jump location is invalid\n");
					}
				}	
		}
		//jne instruction
		else if(checker == 3){
			sscanf(lineInput, "%s %s %s %s", input, input2, input3, input4);
			int x, y;
			int registerCheck = regChecker(input3);
			int registerCheck2 = regChecker(input4);
			
			// Checks to see if x value is a constant or register
			if(registerCheck == 0){
				x = atoi(input3);
			}
			else if(registerCheck == 1){
				x = ax;
			}
			else if(registerCheck == 2){
				x = bx;
			}
			else if(registerCheck == 3){
				x = cx;
			}
			else if(registerCheck == 4){
				x = dx;
			}
			
			// Checks to see if y value is a constant or register
			if(registerCheck2 == 0){
				y = atoi(input4);
			}
			else if(registerCheck2 == 1){
				y = ax;				
			}
			else if(registerCheck2 == 2){
				y = bx;	
			}
			else if(registerCheck2 == 3){
				y = cx;	
			}
			else if(registerCheck2 == 4){
				y = dx;	
			}

				// Comparison check 
				if(x != y){
					int val = atoi(input2);
					if(val <= n){
						i = val - 1;
					}
					else{
						printf("Jump location is invalid\n");
					}
				}	
		}
		//jg instruction
		else if(checker == 4){
			sscanf(lineInput, "%s %s %s %s", input, input2, input3, input4);
			int x, y;
			int registerCheck = regChecker(input3);
			int registerCheck2 = regChecker(input4);
			
			// Checks to see if x value is a constant or register
			if(registerCheck == 0){
				x = atoi(input3);
			}
			else if(registerCheck == 1){
				x = ax;
			}
			else if(registerCheck == 2){
				x = bx;
			}
			else if(registerCheck == 3){
				x = cx;
			}
			else if(registerCheck == 4){
				x = dx;
			}
			
			// Checks to see if y value is a constant or register
			if(registerCheck2 == 0){
				y = atoi(input4);
			}
			else if(registerCheck2 == 1){
				y = ax;				
			}
			else if(registerCheck2 == 2){
				y = bx;	
			}
			else if(registerCheck2 == 3){
				y = cx;	
			}
			else if(registerCheck2 == 4){
				y = dx;	
			}

				// Comparison check 
				if(x > y){
					int val = atoi(input2);
					if(val <= n){
						i = val - 1;
					}
					else{
						printf("Jump location is invalid\n");
					}
				}	
		}
		//jge instruction
		else if(checker == 5){
			sscanf(lineInput, "%s %s %s %s", input, input2, input3, input4);
			int x, y;
			int registerCheck = regChecker(input3);
			int registerCheck2 = regChecker(input4);
			
			// Checks to see if x value is a constant or register
			if(registerCheck == 0){
				x = atoi(input3);
			}
			else if(registerCheck == 1){
				x = ax;
			}
			else if(registerCheck == 2){
				x = bx;
			}
			else if(registerCheck == 3){
				x = cx;
			}
			else if(registerCheck == 4){
				x = dx;
			}
			
			// Checks to see if y value is a constant or register
			if(registerCheck2 == 0){
				y = atoi(input4);
			}
			else if(registerCheck2 == 1){
				y = ax;				
			}
			else if(registerCheck2 == 2){
				y = bx;	
			}
			else if(registerCheck2 == 3){
				y = cx;	
			}
			else if(registerCheck2 == 4){
				y = dx;	
			}

				// Comparison check 
				if(x >= y){
					int val = atoi(input2);
					if(val <= n){
						i = val - 1;
					}
					else{
						printf("Jump location is invalid\n");
					}
				}	
		}
		//jl instruction
		else if(checker == 6){
			sscanf(lineInput, "%s %s %s %s", input, input2, input3, input4);
			int x, y;
			int registerCheck = regChecker(input3);
			int registerCheck2 = regChecker(input4);
			
			// Checks to see if x value is a constant or register
			if(registerCheck == 0){
				x = atoi(input3);
			}
			else if(registerCheck == 1){
				x = ax;
			}
			else if(registerCheck == 2){
				x = bx;
			}
			else if(registerCheck == 3){
				x = cx;
			}
			else if(registerCheck == 4){
				x = dx;
			}
			
			// Checks to see if y value is a constant or register
			if(registerCheck2 == 0){
				y = atoi(input4);
			}
			else if(registerCheck2 == 1){
				y = ax;				
			}
			else if(registerCheck2 == 2){
				y = bx;	
			}
			else if(registerCheck2 == 3){
				y = cx;	
			}
			else if(registerCheck2 == 4){
				y = dx;	
			}

				// Comparison check 
				if(x < y){
					int val = atoi(input2);
					if(val <= n){
						i = val - 1;
					}
					else{
						printf("Jump location is invalid\n");
					}
				}	
		}
		//jle instruction
		else if(checker == 7){
			sscanf(lineInput, "%s %s %s %s", input, input2, input3, input4);
			int x, y;
			int registerCheck = regChecker(input3);
			int registerCheck2 = regChecker(input4);
			
			// Checks to see if x value is a constant or register
			if(registerCheck == 0){
				x = atoi(input3);
			}
			else if(registerCheck == 1){
				x = ax;
			}
			else if(registerCheck == 2){
				x = bx;
			}
			else if(registerCheck == 3){
				x = cx;
			}
			else if(registerCheck == 4){
				x = dx;
			}
			
			// Checks to see if y value is a constant or register
			if(registerCheck2 == 0){
				y = atoi(input4);
			}
			else if(registerCheck2 == 1){
				y = ax;				
			}
			else if(registerCheck2 == 2){
				y = bx;	
			}
			else if(registerCheck2 == 3){
				y = cx;	
			}
			else if(registerCheck2 == 4){
				y = dx;	
			}

				// Comparison check 
				if(x <= y){
					int val = atoi(input2);
					if(val <= n){
						i = val - 1;
					}
					else{
						printf("Jump location is invalid\n");
					}
					
				}	
		}
		
	
	}



	// Clears input values
	memset(input, 0, strlen(input));
	memset(input, 0, strlen(input2));
	memset(input, 0, strlen(input3));
	memset(input, 0, strlen(input4));
	i+=1;
	}



	fclose(ptr);
	return 0;

}
