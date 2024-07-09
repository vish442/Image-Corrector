#define _CRT_SECURE_NO_WARNINGS													//Using this suppresses fscan errors
#include<stdio.h>
#include<stdlib.h>
#include"functions.h"

#define num_rows 128															//defining num_rows as a constant value ie size of image
#define num_columms 256															//defining num_columms as a constant value ie size of image
#define max_depth 3																//defining max_depth as a constant value , used for three dimensions
// Define the image write array file as an integer
int ImagewriteArray[num_rows][num_columms][max_depth];
int ImagewriteArray2[num_rows][num_columms][max_depth];

// Declare pointer files
FILE * GreenRead = NULL;														//Pointer file: image01.green 
FILE * RedRead = NULL;															//Pointer file: image01.red 
FILE * BlueRead = NULL;															//Pointer file: image01.blue 
FILE * ImageArrayFinal = NULL;													//Pointer file: image01.ppm
FILE * GreenRead2 = NULL;														//Pointer file: green.txt
FILE * RedRead2 = NULL;															//Pointer file: red.txt
FILE * BlueRead2 = NULL;														//Pointer file: blue.txt
FILE * ImageArrayFinal2 = NULL;													//Pointer file: FinalImage2.ppm 
// Declare pointer files to be used to see if the required files are in the directory
FILE* GreenRead3=NULL;
FILE* GreenRead4=NULL;
FILE* RedRead3=NULL;
FILE* RedRead4=NULL;
FILE* BlueRead3=NULL;
FILE* BlueRead4=NULL;
 //int*ImageArrayFinal2;	
//Defining variables as integers//
	int columms;
	int rows;
	int ReadRedArray[num_rows][num_columms];
	int ReadGreenArray[num_rows][num_columms];
	int ReadBlueArray[num_rows][num_columms];
	int ReadRedArray2[num_rows][num_columms];
	int ReadGreenArray2[num_rows][num_columms];
	int ReadBlueArray2[num_rows][num_columms];
	int ReadRedShiftArray[num_rows][num_columms];
	int ReadBlueShiftArray[num_rows][num_columms];
	int crop;
	// valueset is the conditional placeholder,creates an array of zeros ready to be written on
	int valueset = 0;
	int*Mred;														// Allociating memory for red file
	int*Mgreen;														// Allociating memory for green file
	int*Mblue;														// Allociating memory for blue file
	int*Mred2;														// Allociating memory for red file 
	int*Mgreen2;
	int*Mblue2;
	int*Mred2rotate;
	int*Mgreen2rotate;
	int*Mblue2rotate;
	int*Mblue4;
	int*Mred4;
	int*Mgreen4;

	
	//Memory alloication for a red read pointer file
	int RedMemory(void)

{

	 Mred=(int*)malloc((num_rows*num_columms)*sizeof(int));			//The memory allocated is depends on the values of num rows and columms, depends on how much each integer worth

	 if(Mred == NULL)													// If memory allocation fails then the code will fail to run

 
	{

		 printf("\nNot enough memory. Program will now close.\n");

		 return 1;
 
	}
	 else {															
		 return 0;
	 }
}
	//Memory alloication for a green read pointer file
	int GreenMemory(void)
	{
		Mgreen=(int*)malloc((num_rows*num_columms)*sizeof(int));		//The memory allocated is depends on the values of num rows and columms, depends on how much each integer worth
		if (Mgreen==NULL)												// If memory alloication fails then the code will fail to run
		{
			printf("\nNot enough memory.Program will now close.\n");

			return 1;
		}
		else 
			{return 0;
		}
	}


	//Memory alloication for a blue read pointer file
	int BlueMemory(void)
	{
		Mblue=(int*)malloc((num_rows*num_columms)*sizeof(int));			//The memory allocated is depends on the values of num rows and columms, depends on how much each integer worth
		if (Mblue==NULL)													// If memory alloication fails then the code will fail to run
		{
			printf("\nNot enough memory.Program will now close.\n");

			return 1;
		}
		else
		{return 0;
		}
	}

	

	//Memory alloication for a blue read2 pointer file
	int BlueMemory2(void)
		{
		Mblue2=(int*)malloc((num_rows*num_columms)*sizeof(int));		//The memory allocated is depends on the values of num rows and columms, depends on how much each integer worth
		if (Mblue2==NULL)												// If memory alloication fails then the code will fail to run
		{
			printf("\nNot enough memory.Program will now close.\n");

			return 1;
		}
		else {return 0;
		}

	}
	//Memory alloication for a red read2 pointer file
	int RedMemory2(void)
	{
		Mred2=(int*)malloc((num_rows*num_columms)*sizeof(int));			//The memory allocated is depends on the values of num rows and columms, depends on how much each integer worth
		if (Mred2==NULL)													// If memory alloication fails then the code will fail to run
		{
			printf("\nNot enough memory.Program will now close.\n");

			return 1;
		}
		else {return 0;
		}
	}

	//Memory alloication for a green read2 pointer file
	int GreenMemory2(void)
	{
		Mgreen2=(int*)malloc((num_rows*num_columms)*sizeof(int));		//The memory allocated is depends on the values of num rows and columms, depends on how much each integer worth
		if (Mgreen2==NULL)												// If memory alloication fails then the code will fail to run
		{
			printf("\nNot enough memory.Program will now close.\n");

			return 1;
		}
		else{return 0;
		}
	}

	//Memory alloication for a green read2 pointer file
	int GreenMemory3(void)
	{
		Mgreen2rotate=(int*)malloc((num_rows*num_columms)*sizeof(int));		//The memory allocated is depends on the values of num rows and columms, depends on how much each integer worth
		if (Mgreen2rotate==NULL)												// If memory alloication fails then the code will fail to run
		{
			printf("\nNot enough memory.Program will now close.\n");

			return 1;
		}
		else{return 0;
		}
	}

	//Memory alloication for a green read2 pointer file
	int RedMemory3(void)
	{
		Mred2rotate=(int*)malloc((num_rows*num_columms)*sizeof(int));		//The memory allocated is depends on the values of num rows and columms, depends on how much each integer worth
		if (Mred2rotate==NULL)												// If memory alloication fails then the code will fail to run
		{
			printf("\nNot enough memory.Program will now close.\n");

			return 1;
		}
		else{return 0;
		}
	}

	//Memory alloication for a green read2 pointer file
	int BlueMemory3(void)
	{
		Mblue2rotate=(int*)malloc((num_rows*num_columms)*sizeof(int));		//The memory allocated is depends on the values of num rows and columms, depends on how much each integer worth
		if (Mblue2rotate==NULL)												// If memory alloication fails then the code will fail to run
		{
			printf("\nNot enough memory.Program will now close.\n");

			return 1;
		}
		else{return 0;
		}
	}


	int BlueMemory4(void)
	{
		Mblue4=(int*)malloc((num_rows*num_columms)*sizeof(int));			//The memory allocated is depends on the values of num rows and columms, depends on how much each integer worth
		if (Mblue4==NULL)													// If memory alloication fails then the code will fail to run
		{
			printf("\nNot enough memory.Program will now close.\n");

			return 1;
		}
		else
		{return 0;
		}
	}

	int RedMemory4(void)
	{
		Mred4=(int*)malloc((num_rows*num_columms)*sizeof(int));			//The memory allocated is depends on the values of num rows and columms, depends on how much each integer worth
		if (Mred4==NULL)													// If memory alloication fails then the code will fail to run
		{
			printf("\nNot enough memory.Program will now close.\n");

			return 1;
		}
		else
		{return 0;
		}
	}

	int GreenMemory4(void)
	{
		Mgreen4=(int*)malloc((num_rows*num_columms)*sizeof(int));			//The memory allocated is depends on the values of num rows and columms, depends on how much each integer worth
		if (Mgreen4==NULL)													// If memory alloication fails then the code will fail to run
		{
			printf("\nNot enough memory.Program will now close.\n");

			return 1;
		}
		else
		{return 0;
		}
	}
	//Reading the image file of the red file 
void Redfile()																		//A loop created for opening and reading the red file to be placed in the main function
{
	RedRead = fopen("image01.red", "r");											//Opening and reading the red file
	RedMemory();																	//Embedded memory loop

	//Creating a nested loop where are rows and columms are included of the red file
	for (rows = 0; rows < num_rows; rows++)											// Rows are read from the first value all the to the last in increments of 1
	{
		for (columms = 0; columms < num_columms; columms++)							// columms are read from the first value all the to the last in increments of 1
		{
			// Reading and Inputing data from the red file 
			fscanf(RedRead, "%d", &*Mred);
			ReadRedArray[rows][columms] = *Mred;


		}

	}
}
	


void Greenfile()																	//A loop created for opening and reading the green file to be placed in the main function
{
	//Reading the image file of the green file
	GreenRead = fopen("image01.green", "r");										//Opening and reading the green file
	GreenMemory();																	//Embedded memory loop
	//Creating a nested loop where are rows and columms are included of the green file
	for (rows = 0; rows < num_rows; rows++)											// Rows are read from the first value all the to the last in increments of 1
	{
		for (columms = 0; columms < num_columms; columms++)							// columms are read from the first value all the to the last in increments of 1
		{
			// Reading and Inputing data from the green file 
			fscanf(GreenRead, "%d", &*Mgreen);
			ReadGreenArray[rows][columms] = *Mgreen;

		}
	}
}
	


void Bluefile()																		//A loop created for opening and reading the blue file to be placed in the main loop
{
//Reading the image file of the blue file
	BlueRead = fopen("image01.blue", "r");											//Opening and reading the blue file
	BlueMemory();																	//Embedded memory loop
	//Creating a nested loop where are rows and columms are included of the blue file
	for (rows = 0; rows < num_rows; rows++)											// Rows are read from the first value all the to the last in increments of 1
	{
		for (columms = 0; columms < num_columms; columms++)							// Columms are read from the first value all the to the last in increments of 1
		{
			// Reading and Inputing data from the blue file 
			fscanf(BlueRead, "%d", &*Mblue);
			ReadBlueArray[rows][columms] = *Mblue;

		}

	}
}
	
void FinalImage()																	//A loop created for creating a file and joining the data from red,green,blue files to be placed in the main function
{
	// Creating the final image file 
	ImageArrayFinal = fopen("Image01.ppm", "w");									//Creating a file ready to be write on hense "w" writing mode
	// Formatting the final image file to a ppm file format
	fprintf(ImageArrayFinal, "P3\n%d %d\n255\n", num_columms, num_rows);			
	
	// Creating a nested for loop where all data from the all 3 colours
	for (rows = 0; rows < num_rows; rows++)											// Rows are read from the first value in increments of 1
	{
		for (columms = 0; columms < num_columms; columms++)							//Columms are read from the first value in increaments of 1
		{ 
			// Putting the red values in the third dimension of the final image array
			ImagewriteArray[rows][columms][0]=ReadRedArray[rows][columms];
			fprintf(ImageArrayFinal, "%d ", ImagewriteArray[rows][columms][0]);
			
			 // Putting the green values in the third dimension of the final image array
			ImagewriteArray[rows][columms][1]=ReadGreenArray[rows][columms];
			fprintf(ImageArrayFinal, "%d ", ImagewriteArray[rows][columms][1]);
			
			 // Putting the blue values in the third dimension of the final image array
			ImagewriteArray[rows][columms][2]=ReadBlueArray[rows][columms];
			fprintf(ImageArrayFinal, "%d ", ImagewriteArray[rows][columms][2]);
			
			}
		// Spacing the data inputed in
		fprintf(ImageArrayFinal, "\n");
	}
}


	






void redtxt()																						//A loop created for the red text file to be place in the main function
{
	RedRead2 = fopen("red.txt", "r");																//Opening the red text file and reading the data from it
	RedMemory2();																					//Embedded memory loop
	//Creating a nested loop where are rows and columms are included of the red file
	for (rows = 0; rows < num_rows; rows++)															// Rows are read from the first value all the to the last in increments of 1
	{
		for (columms = 0; columms < num_columms; columms++)											// Columms are read from the first value all the to the last in increments of 1
		{
			// Reading and Inputing data from the red text file 
			fscanf(RedRead2, "%d", &*Mred2);
			ReadRedArray2[rows][columms] = *Mred2;
			ReadRedShiftArray[rows][columms] = ReadRedArray2[rows - 11][columms - 11];				//Here the red part of the image is being shifted 11 places from the last value of the array 
		}

	}
	//Creating an nested loop where the first 11 rows of the array is 0 ie cropping the image
		for(rows=0; rows <11; rows++)																//A for loop where the first 11 values from row of the red array are being identified
		
	{
				for(columms=0;columms< num_columms;columms++)										
				{
				ReadRedShiftArray[rows][columms] = crop;											//The first 11 values from the rows side are changed to 0
				}
	}
	
	//Creating an nested loop where the first 11 columms of the array is 0 ie cropping the image
	for(rows=0; rows< num_rows; rows++)
	{
				for(columms=0;columms< 11;columms++)												//A for loop where the first 11 values from columms side 
				{
				ReadRedShiftArray[rows][columms] = crop;
				}
	}
}
	

void greentxt()																						//A loop created for the green text file to be place in the main loop

{
	//Reading the image file of the green file
	GreenRead2 = fopen("green.txt", "r");
	GreenMemory2();																					//Embedded memory loop
	//Creating a nested loop where are rows and columms are included of the green file
	for (rows = num_rows; rows > 0; rows--)															//The array is read backwards instead of forwards, this creates the effect of the green image being rotated 180 degrees
	{
		for (columms=num_columms; columms > 0; columms--)
		{
		
			// Reading and Inputing data from the green file 
			fscanf(GreenRead2, "%d", &*Mgreen2);
			ReadGreenArray2[rows][columms] = *Mgreen2;

		}
			
	}	
		

	// Cropping the images

		//Creating an nested loop where the first 11 rows of the array is 0 ie cropping the image
	for(rows=0; rows <11; rows++)																	//The first 11 values of from the rows side of the array values are changed to 0
		
	{
				for(columms=0;columms< num_columms;columms++)
				{
				ReadGreenArray2[rows][columms] = crop;												
				}
	}
			
	//Creating an nested loop where the first 11 columms of the array is 0 ie cropping the image
	for(rows=0; rows <num_rows; rows++)
		
	{
				for(columms=0;columms< 11;columms++)												//The first 11 values of from the columms side of the array values are changed to 0
				{
				ReadGreenArray2[rows][columms] = crop;
				}
	}



}

void bluetxt()																						//A loop created for the blue text to be placed in the main function
{
	//Reading the image file of the blue file
	BlueRead2 = fopen("blue.txt", "r");
	BlueMemory2();
	//Creating a nested loop where are rows and columms are included of the blue file
	for (rows = 0; rows < num_rows; rows++)															// Rows are read from the first value all the to the last in increments of 1
	{
		for (columms = 0; columms < num_columms; columms++)											// Columms are read from the first value all the to the last in increments of 1
		{
			// Reading and Inputing data from the blue file 
			fscanf(BlueRead2, "%d", &*Mblue2);
			ReadBlueArray2[rows][columms] = *Mblue2;
			ReadBlueShiftArray[rows][columms] = ReadBlueArray2[rows - 11][columms - 11];			// The blue part of the image is shifted by 11 places
		}

	}


		//Creating an nested loop where the first 11 rows of the array is 0 ie cropping the image

	for(rows=0; rows <11; rows++)																	//The first 11 values from the rows side are changed to 0 value
		
	{
				for(columms=0;columms< num_columms;columms++)
				{
				ReadBlueShiftArray[rows][columms] = crop;
				
				
				}
	}
	
		//Creating an nested loop where the first 11 columms of the array is 0 ie cropping the image

	for(rows=0; rows <num_rows; rows++)
		
	{
				for(columms=0;columms< 11;columms++)												//The first 11 values from the columms side are changed to 0 value
				{
				ReadBlueShiftArray[rows][columms] = crop;											
				}
	}

}

void finalimage2()																					//The finalimage2 loop to be placed in the main function
{
	
	// Creating the final image file 
	ImageArrayFinal2 = fopen("Image02.ppm", "w");												//Opening an file to be written on
	// Formatting the final image file to a ppm file format
	fprintf(ImageArrayFinal2, "P3\n%d %d\n255\n", num_columms, num_rows);							

	// Creating a nested for loop where all data from the all 3 colours
	for (rows = 0; rows < num_rows; rows++)
	{
		for (columms = 0; columms < num_columms; columms++)
		{
			// Putting the red values in the third dimension of the final image array
			ImagewriteArray2[rows][columms][0] = ReadRedShiftArray[rows][columms];
			fprintf(ImageArrayFinal2, "%d ", ImagewriteArray2[rows][columms][0]);

			// Putting the green values in the third dimension of the final image array
			ImagewriteArray2[rows][columms][1] = ReadGreenArray2[rows][columms];
			fprintf(ImageArrayFinal2, "%d ", ImagewriteArray2[rows][columms][1]);

			// Putting the blue values in the third dimension of the final image array
			ImagewriteArray2[rows][columms][2] = ReadBlueShiftArray[rows][columms];
			fprintf(ImageArrayFinal2, "%d ", ImagewriteArray2[rows][columms][2]);

		}
		// Spacing the data inputed in
		fprintf(ImageArrayFinal2, "\n");
	}
	
	


}

void redtxtrotate()																						//A loop created for the red text file to be place in the main function
{
	RedRead2 = fopen("red.txt", "r");																//Opening the red text file and reading the data from it
	RedMemory3();																					//Embedded memory loop
	//Creating a nested loop where are rows and columms are included of the red file
	for (rows = num_rows; rows > 0; rows--)															// Rows are read from the first value all the to the last in increments of 1
	{
		for (columms =num_columms; columms > 0; columms--)											// Columms are read from the first value all the to the last in increments of 1
		{
			// Reading and Inputing data from the red text file 
			fscanf(RedRead2, "%d", &*Mred2rotate);
			ReadRedArray2[rows][columms] = *Mred2rotate;
			ReadRedShiftArray[rows][columms] = ReadRedArray2[rows][columms];				//Here the red part of the image is being shifted 11 places from the last value of the array 
		}

	}
}
void bluetxtrotate()																						//A loop created for the blue text to be placed in the main function
{
	//Reading the image file of the blue file
	BlueRead2 = fopen("blue.txt", "r");
	BlueMemory3();
	//Creating a nested loop where are rows and columms are included of the blue file
	for (rows = num_rows; rows > 0; rows--)																// Rows are read from the first value all the to the last in increments of 1
	{
		for (columms =num_columms; columms > 0; columms--)											// Columms are read from the first value all the to the last in increments of 1
		{
			// Reading and Inputing data from the blue file 
			fscanf(BlueRead2, "%d", &*Mblue2rotate);
			ReadBlueArray2[rows][columms] = *Mblue2rotate;
			ReadBlueShiftArray[rows][columms] = ReadBlueArray2[rows ][columms ];			// The blue part of the image is shifted by 11 places
		}

	}
}
	
	void greentxtrotate()																						//A loop created for the blue text to be placed in the main function
{
	//Reading the image file of the blue file
	GreenRead2 = fopen("blue.txt", "r");
	GreenMemory3();
	//Creating a nested loop where are rows and columms are included of the blue file
	for (rows = num_rows; rows > 0; rows--)																// Rows are read from the first value all the to the last in increments of 1
	{
		for (columms =num_columms; columms > 0; columms--)											// Columms are read from the first value all the to the last in increments of 1
		{
			// Reading and Inputing data from the blue file 
			fscanf(GreenRead2, "%d", &*Mgreen2rotate);
			ReadGreenArray2[rows][columms] = *Mgreen2rotate;
																									
		}
	}
	}


	void Redfile2()																		//A loop created for opening and reading the red file to be placed in the main function
{
	RedRead = fopen("image01.red", "r");											//Opening and reading the red file
	RedMemory4();																	//Embedded memory loop

	//Creating a nested loop where are rows and columms are included of the red file
	for (rows = num_rows; rows >0; rows--)											// Rows are read from the first value all the to the last in increments of 1
	{
		for (columms =num_columms; columms > 0; columms--)							// columms are read from the first value all the to the last in increments of 1
		{
			// Reading and Inputing data from the red file 
			fscanf(RedRead, "%d", &*Mred4);
			ReadRedArray[rows][columms] = *Mred4;


		}

	}
}
	void Greenfile2()																	//A loop created for opening and reading the green file to be placed in the main function
{
	//Reading the image file of the green file
	GreenRead = fopen("image01.green", "r");										//Opening and reading the green file
	GreenMemory4();																	//Embedded memory loop
	//Creating a nested loop where are rows and columms are included of the green file
	for (rows = num_rows; rows >0; rows--)											// Rows are read from the first value all the to the last in increments of 1
	{
		for (columms =num_columms; columms > 0; columms--)						// columms are read from the first value all the to the last in increments of 1
		{
			// Reading and Inputing data from the green file 
			fscanf(GreenRead, "%d", &*Mgreen4);
			ReadGreenArray[rows][columms] = *Mgreen4;

		}
	}
}



	void Bluefile2()																		//A loop created for opening and reading the blue file to be placed in the main loop
{
//Reading the image file of the blue file
	BlueRead = fopen("image01.blue", "r");											//Opening and reading the blue file
	BlueMemory4();																	//Embedded memory loop
	//Creating a nested loop where are rows and columms are included of the blue file
	for (rows = num_rows; rows >0; rows--)											// Rows are read from the first value all the to the last in increments of 1
	{
		for (columms =num_columms; columms > 0; columms--)						// Columms are read from the first value all the to the last in increments of 1
		{
			// Reading and Inputing data from the blue file 
			fscanf(BlueRead, "%d", &*Mblue4);
			ReadBlueArray[rows][columms] = *Mblue4;

		}

	}
}


	//If statements followed if else if to check the required files are in the directory
	int checkgreen()
	{
		if (GreenRead3 = fopen("image01.green", "r"))				//Checks using pointer file to see if file in directory
		{ 
		printf("Green file exist!\n");							//Comments that the file exist
		fclose(GreenRead3);										//Closes the file so the pointer in the function.c file can use the file
		}
		else if(GreenRead3==NULL)									//Else if statement if the file is not found then user is adviced to put the missing file in the directory
		{
		printf("Please put green file in directory and run program again\n"); //If file is not found the program will close and the user will be asked to put files into the directory
        return 1;
		}
	}


	//If statements followed if else if to check the required files are in the directory
	int checkblue()
	{
	if(BlueRead3=fopen("image01.blue","r"))						//Checks using pointer file to see if file in directory
	{
		printf("Blue file exist!\n");							//Comments that the file exist
		fclose(BlueRead3);										//Closes the file so the pointer in the function.c file can use the file
	}
	else if(BlueRead3==NULL)									//Else if statement if the file is not found then user is adviced to put the missing
	{
		printf("Please put blue file in directory and run program again\n"); //If file is not found the program will close and the user will be asked to put files into the directory
		return 1;
	}
	}
	
	//If statements followed if else if to check the required files are in the directory
	int checkred()
	{
	if(RedRead3=fopen("image01.red","r"))						//Checks using pointer file to see if file in directory
	{
		printf("Red file exist!\n");							//Comments that the file exist
		fclose(RedRead3);										//Closes the file so the pointer in the function.c file can use the file
	}
	else if(RedRead3==NULL)										//Else if statement if the file is not found then user is adviced to put the missing
	{
		printf("Please put red file in directory and run program again\n"); //If file is not found the program will close and the user will be asked to put files into the directory
		return 1;
	}
	}

	int checkgreen2()
	{
	if (GreenRead4 =fopen("green.txt","r"))						//Checks using pointer file to see if file in directory
	{	
		printf("Green file text exist!\n");						//Comments that the file exist
		fclose(GreenRead4);										//Closes the file so the pointer in the function.c file can use the file
	}
	else if(GreenRead4==NULL)									//Else if statement if the file is not found then user is adviced to put the missing			
	{
		printf("Please put green text file in directory and run program again\n"); //If file is not found the program will close and the user will be asked to put files into the directory
		return 1;
	}
	}

	int checkblue2()
	{
	if(BlueRead4=fopen("blue.txt","r"))							//Checks using pointer file to see if file in directory
	{
		printf("Blue file text exist!\n");						//Comments that the file exist
		fclose(BlueRead4);										//Closes the file so the pointer in the function.c file can use the file
	}
	else if(BlueRead4==NULL)									//Else if statement if the file is not found then user is adviced to put the missing
	{
		printf("Please put blue text file in directory and run program again\n"); //If file is not found the program will close and the user will be asked to put files into the directory
		return 1;
	}
	}

	int checkred2()
	{	
		if(RedRead4=fopen("red.txt","r"))							//Checks using pointer file to see if file in directory
					{
						printf("Red file text exist!\n");						//Comments that the file exist
						fclose(RedRead4);										//Closes the file so the pointer in the function.c file can use the file
					}
					else if(RedRead4==NULL)										//Else if statement if the file is not found then user is adviced to put the missing
					{
						printf("Please put red text file in directory and run program again\n"); //If file is not found the program will close and the user will be asked to put files into the directory
					return 1;
	}
	}				
					