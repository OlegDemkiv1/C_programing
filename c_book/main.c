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
	// 
	typedef struct
	{
		int x;
		int y;
		int z;
	} my_test_struct;

    // 10. Enum  // Create type 
	typedef enum test_enum
	{
		zero,
		one,
		two,
		three,
        four
	};

	typedef enum test_enum_1 {
		First =1,
		Second = 1<<1,     // Set 2 bit in 1
		Third = 1<<2,
		Fourth = 1<<3,
		Fifth = 1<<4
	};

	// 11. Bit fileds
	struct packed_stuct {
		char			f1 : 8;
		int				f2 : 3;
		unsigned int	f3 : 16;	
	}bit_filds;

	// 12. UNION
	union Data {
		int i;
		float f;
		char str[30];
	}data;
    
	// 13. BITS FIELDS
	struct {
		unsigned int value_1 : 4;
		unsigned int value_2 : 1;
		unsigned int value_3 : 2;
		unsigned int value_4 : 1;
		unsigned int value_5 : 1;
		unsigned int value_6 : 1;
	}status;

	
	


	int main()
	{
		//////////////////////////////////// Local variabble /////////////////////////////////////////////////////
		// 1. This function takes lengh arrey and pointer on first element.
		int str[8] = { 1,2,3,4,5,6,7,8 };
		int lengh_str = ((sizeof(str)) - 1) / sizeof(int);
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
		int lengh_str_123 = (sizeof(str_123) / sizeof(int)) - 1;
		int *pstr_123;
		pstr_123 = str_123;
		int i = 0;
		// 7. Pass pointer of arrey and change it in function, and return
		int arrey_for_rand[5] = { 1,2,3,4,5 };
		int lengh_arrey_for_rand = (sizeof(arrey_for_rand) / sizeof(int));






		printf("==============START==============\n\r");
		// 1. This function takes lengh arrey and pointer on first element.
		print_arrey(&lengh_str, str);
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
		res = function_1(pf);
		printf("Return value from function %d \n\r", res);
		// 7. Pass pointer of arrey and change it in function, and return
		res = get_rand(&lengh_arrey_for_rand, arrey_for_rand);
		for (i = 0; i < lengh_arrey_for_rand; i++)
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
		Book1.book_id = 12345;
		// Print elements of structure
		printf("%s \n\r", Book1.title);
		printf("%s \n\r", Book1.auhtor);
		printf("%d \n\r", Book1.book_id);
		// Pass Book1 structure in function and change it incaide function
		structuries(Book1);
		// Print elements of structure after changed in function
		printf("%s \n\r", Book1.title);
		printf("%s \n\r", Book1.auhtor);
		printf("%d \n\r", Book1.book_id);
		// POINTER TO STRUCTURES
		//struct Books *struct_pointer;		// Define pointer for structure
		//struct_pointer=&Book1;              // Save address in pointer veriabble
		structure(&Book1);					// Pass address structure in function
		// print structure after function
		printf("%s \n\r", Book1.title);
		printf("%s \n\r", Book1.auhtor);
		printf("%d \n\r", Book1.book_id);
		// How use typedef with structure???
		// TYPEDEF in struct
		my_test_struct jjj;
		jjj.x = 111;

		//.x= 111;
	//printf(my_test_struct)

	// 10. Enum and typedef
	// enum приймає одне із перерахованих значень.
		test_enum numbers;					    // Ctrate variable numbers of enum 
		numbers = two;                          // Appropriation 
		printf("%d <<<<<<<\n\r", numbers);

		test_enum_1 numb;
		
	    printf("Fild ENUM: %d\n\r ", First);
		printf("Fild ENUM: %d\n\r ", Second);
		printf("Fild ENUM: %d\n\r ", Third);
		printf("Fild ENUM: %d\n\r ", Fourth);

		// 11. Bit fileds
		bit_filds.f2 = 4;
		printf("BIT FILD: %d\n\r ", bit_filds.f2);

		// 12. UNION
		data.i = 1000;
		printf("data.i: %d\n\r", data.i);
		printf("UNION size: %d\n\r ", sizeof(data));

		// 13. BITS FIELDS
		// Fill some fild of bits fildes
		status.value_1 = 15;         // becouse 4 byts = 0b1111  =16-1 
		status.value_2 = 1;
		status.value_3 = 3;

	    printf("FILD OF UNION value: %d\n\r ", status.value_1);
		printf("FILD OF UNION value: %d\n\r ", status.value_2);
		printf("FILD OF UNION value: %d\n\r ", status.value_3);

		printf("UNION size: %d\n\r ", sizeof(status));    // Whay  4???

		// 14. TYPEDEF

		// 15. input and output
		//input_output();

		// 16. I_O_Files
		printf("WORK WITH FILE\n");
		i_o_files();
		calcul_char_in_file();
		printf("END WORK WITH FILE\n");

		// 17. Preprocessors






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
void input_output(void)
{
	// getchar and putchar functions
	printf("press 'q' for exit from loop ");
	while (getchar() != 'q')
	{ 
		getchar();
	}
	char str_100[] = "qwerty qwertyuiop";
	int size = sizeof(str_100);
	for (int i = 0; i <= size; i++)				// Print all char simbol
	{
		if (str_100[i] == '\0')					// if end of string
		{
			break;
		}
		putchar(str_100[i]);					// Print char
	}

	printf("\n\r");

	// puts and gets functions
	char str[100];
	memset(str, 0, sizeof(str));
	printf("Enter a value :\n\r");
	gets_s(str);
	printf("You enter: ");
	puts(str);
	printf("\n\r");

}
void i_o_files(void)
{
	printf("WORK WITH FILE\n");

	FILE *fp;
	errno_t err;
	if ((err = fopen_s(&fp, "File.txt", "w")) != 0)							// Open ore create txt file
	{
		printf("File was not opened\n");
		while (1);
	}
	else
	{
		fprintf(fp, "Date: %s, Time: %s \n", __DATE__, __TIME__);			// Write data in file
		fprintf(fp, "TEST WRITE IN FILE 2\n");
		fprintf(fp, "TEST WRITE IN FILE 3\n");
		fclose(fp);															//Close file

		// Open exsisting file
		if ((err = fopen_s(&fp, "File.txt", "r")) != 0)						// Open ore create txt file
		{
			printf("File was not opened\n");
			while (1);
		}
		else
		{
			printf("OPEN FILE SECOND TIME\n");
			// Copy string on buffer and print it on screen
			char reading_buf[100];											// buffer for save readed data
			int how_many_read = 100;
			fgets(reading_buf, how_many_read, (FILE *)fp);
			printf("Copy line from file...\n");
			printf("%s", reading_buf);			

			fclose(fp);	
		}
	}
}

void calcul_char_in_file(void)
{
	FILE *fp;
	errno_t err;
	if ((err = fopen_s(&fp, "File.txt", "w")) != 0)							// Open ore create txt file
	{
		printf("File was not opened\n");
		while (1);
	}
	else
	{
		// Write somesing in file
		fprintf(fp, "TEST WRITE IN FILE 1\n");
		fprintf(fp, "TEST WRITE IN FILE 2\n");
		fclose(fp);


		if ((err = fopen_s(&fp, "File.txt", "r")) != 0)							// Open ore create txt file
		{
			printf("File was not opened\n");
			while (1);
		}

		else
		{
			// Calculate how many lines in file    
			printf("Open file for calcul how many symbols\n");
			int number_of_simbols = 0;
			int ch = 0;
			do {
				ch = fgetc(fp);													// Read one char simbol
				number_of_simbols++;
				printf("%c", ch);
			} while (ch != EOF);
			printf("%d \n", number_of_simbols);

			fclose(fp);
		}
	}
}

