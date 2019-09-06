#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <string.h>
#include "stdio.h"
#include <iostream>

#include "main.h"

	// 9. Structuries
    // structure declarations
	struct Books
	{
		char title[50];
		char auhtor[50];
		char subject[100];
		int book_id;
	};
    // 10. Enum
	enum Number
	{
		zero ,       // Fild
		one,
		two,
		three,
		four = 1<<4
	};

	enum PCA9685_MODE1_MASK
	{
		PCA9685_MODE1_RESTART = 1 << 7, // Reset PWM
		PCA9685_MODE1_EXTCLK  = 1 << 6, // Use extern clock
		PCA9685_MODE1_AI      = 1 << 5, // Auto-increment mode
		PCA9685_MODE1_SLEEP   = 1 << 4, // Turn on SLEEP MODE
		PCA9685_MODE1_SUB1    = 1 << 3, // Allow answering at add-on address 1
		PCA9685_MODE1_SUB2    = 1 << 2, // Allow answering at add-on address 2
		PCA9685_MODE1_SUB3    = 1 << 1, // Allow answering at add-on address 3
		PCA9685_MODE1_ALLCALL = 1 << 0, // Allorw answering at add-on address 4
	};
	


int main ()
{   
	//////////////////////////////////// Local variabble /////////////////////////////////////////////////////
	// 1. This function takes lengh arrey and pointer on first element.
	int str[8] = { 1,2,3,4,5,6,7,8 };
	int lengh_str = ((sizeof(str))-1)/sizeof(int);
	// 2. Qwestions !!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
	int str_two_dim[3][5] =
	{
		{ 1,2,3,4,5 },
		{ 6,7,8,9,10 },
		{ 11,12,13,14,15}
	};
	// 3. Passing pointer in function and modifier	
	int rows = 3;
	int clos = 5;
	int val = 111;
	int *pval = &val;					// Create pointer on value "val" 
    // 4. Pass arrey in function
	int str_123[5] = { 1,2,3,4,5 };
	int lengh_str_123 = (sizeof(str_123)/sizeof(int))-1;
	int *pstr_123;
	pstr_123 = str_123;
	int i = 0;
	// 7. Pass pointer of arrey and change it in function, and return
	int arrey_for_rand[5]={1,2,3,4,5};
	int lengh_arrey_for_rand=(sizeof(arrey_for_rand)/sizeof(int));

	

	 

	printf( "==============START==============\n\r"); 
    // 1. This function takes lengh arrey and pointer on first element.
	print_arrey (&lengh_str, str);	
	// 2. Qwestions !!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
    //two_dimensional_arrays ((int *)str_two_dim, &rows, &cols);          
    // 3. Passing pointer in function and modifier															 
	pointers_func(pval);												  
	printf("Value after modifier %d\n\r\n\r", val);
    // 4. Pass arrey in function
	printf("Pass arrey in function\n\r");
	for (i = 0; i <= lengh_str_123; i++)							// Print arrey before
	{
		pstr_123[i] = pstr_123[i] + 100;
		printf("%d\n\r", pstr_123[i]);
	}
	pass_arrey_in_func(lengh_str_123, pstr_123);					//Pass arrey in function
	printf("After function\n\r");
	for (i = 0; i <= lengh_str_123; i++)							// Print arrey after
	{
		printf("%d \n\r", pstr_123[i]);
	}
    // 5. Pointer arithmetic, Transmit pointer of arrey in function and work with pointer.
	printf("incrementing pointers\n\r");
	inctementing_pointer(lengh_str_123, pstr_123);
	// 6. Return simple value from function
	int f = 1111;
	int * pf;
	pf = &f;
	int res = 0;
	res=function_1(pf);
	printf("Return value from function %d \n\r", res);
	// 7. Pass pointer of arrey and change it in function, and return
	res=get_rand(&lengh_arrey_for_rand, arrey_for_rand);
	for(i=0; i<lengh_arrey_for_rand; i++)
	{
		printf("Element of arrey AFTER: %d : %d \n\r", i, arrey_for_rand[i]);
	}
	// 8. Strings
	string_func();
	// 9. Structures
 	printf("WORK WITH STRUCTURES<<<<<<<<<<\n\r");
	struct Books Book1;  // Create variabble Book1 from Books
	struct Books Book2;  // Create variabble Book2 from Books
	// Write data in elemets of structure
	strcpy_s(Book1.title, "C programing");
	strcpy_s(Book1.auhtor, "Nuha Ali");
	Book1.book_id=12345;
    // Print elements of structure
	printf("%s \n\r", Book1.title );
	printf("%s \n\r", Book1.auhtor );
	printf("%d \n\r", Book1.book_id );
    // Pass Book1 structure in function and change it incaide function
	structuries(Book1); 
	// Print elements of structure after changed in function
	printf("%s \n\r", Book1.title );
	printf("%s \n\r", Book1.auhtor );
	printf("%d \n\r", Book1.book_id );
	// POINTER TO STRUCTURES
    //struct Books *struct_pointer;		// Define pointer for structure
    //struct_pointer=&Book1;              // Save address in pointer veriabble
    structure(&Book1);					// Pass address structure in function
    // print structure after function
    printf("%s \n\r", Book1.title );
	printf("%s \n\r", Book1.auhtor );
	printf("%d \n\r", Book1.book_id );
	// How use typedef with structure???
    
	// 10. Enum
    printf("%d \n\r", zero );
	printf("%d \n\r", one );
	printf("%d \n\r", two );
	printf("%d \n\r", four );
  


	printf( "==============STOP==============\n\r"); 
	system("pause");
	return 0;
}



// 1. This function takes lengh arrey and pointer on first element.
void print_arrey(int *lengh_str, int *str)
{
	int i = 0;

	printf("Lengh str %d\n\r", *lengh_str);	
	for (i=0; i<= *lengh_str; i++)
	{
		printf("element %d str = %d \n\r", i, str[i]);   // Whay str[i] not *str[i]  ???
	}
	printf("END\n\r");
	
}

// 2. Qwestions !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void two_dimensional_arrays(int *str_two_dim, int *rows, int *cols)
{
	int x = 0;
	int y = 0;
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 5; y++)
		{
			//printf("%d \n\r",  str_two_dim[x][y]);
		}
	}
}

// 3. Passing pointer in function and modifier
void pointers_func(int *pval)
{
	printf("Value in function %d \n\r", *pval);
	*pval = *pval + 10;
	printf("Value in function %d \n\r", *pval);
}

// 4. Pass arrey in function
void pass_arrey_in_func(int lengh_str_123, int *pstr_123)
{
	int i = 0;
	printf("In function\n\r");
	for (i=0; i<= lengh_str_123; i++)
	{
		pstr_123[i] = pstr_123[i] - 100;
		printf("%d \n\r", pstr_123[i]);
	}

}
// 5. Pointer arithmetic, Transmit pointer of arrey in function and work with pointer.
void inctementing_pointer(int lengh_str_123, int *pstr_123)
{
	int i = 0;
	for (i=0; i<= lengh_str_123; i++)
	{
		printf("Element:%d value: %d \n\r", i, *pstr_123);			// Print value using pointer
		printf("Element:%d value: %d \n\r", i, pstr_123);			// Print address element of array
		pstr_123++;													// Incremein pointer 
	}
}
// 6. Return simple value from function
int function_1(int *pf)
{
	int g = 2222;
	int res = 0;
	res = g + *pf;

	return res;
}
// 7. Pass pointer of arrey and change it in function, and return
int get_rand(int *lengh_arrey_for_rand,  int *arrey_for_rand)
{
    int i=0;
	// Print receive data
	printf("lengh arrey:%d\n", *lengh_arrey_for_rand);
	for(i=0; i<*lengh_arrey_for_rand; i++)
	{
		printf("Element of arrey BEFORE: %d : %d \n\r", i, arrey_for_rand[i]);
	}
	 
	// set the seed 
	srand((unsigned)time(NULL));
	// Change and print random numbers
	for (i = 0; i<*lengh_arrey_for_rand; ++i) 
	{
		arrey_for_rand[i] = rand();
		printf("RANDOM NUMBER:%d\n", arrey_for_rand[i]);
	}
	return 1;
}
// 8. Strings
void string_func(void)
{
	char greating[6] = {'h','e','l','l','o','\0'};
	printf("%s\n\r", greating);
	
	char str_1[10]=  "test";
	char str_2[] = "tyui";
	char res_string[15]="";
	// Using main function for work with string.
	// strcpy function
	strcpy_s(str_1, str_2);				// Copy str_2 in res_string
	printf("%s \n\r",str_1);
}
// 9. Structuries
void structuries(struct Books book)
{
    strcpy_s(book.title, "SSSSSSSS");
	strcpy_s(book.auhtor, "SSSSSSSS");
	book.book_id=1111111;

	printf("%s \n\r", book.title );
	printf("%s \n\r", book.auhtor );
	printf("%d \n\r", book.book_id );
}
void structure(struct Books *book)
{
	strcpy_s(book->title, "work with pointers");	
	strcpy_s(book->auhtor, "work with pointers");
	book->book_id=1111111;	

    printf("%s \n\r", book->title );
	printf("%s \n\r", book->auhtor );
	printf("%d \n\r", book->book_id );
}