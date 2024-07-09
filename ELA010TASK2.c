/*%----------------------------------------------------% 
% Code for 13ELA010 coursework 2 PPM Image % 
% Vishal Patel B325449  
% Start date : 25 Feb 2014 % 
% last modified : 21 Mar 2014 % 
%----------------------------------------------------% */


#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functions.h"

// Declare pointer files to be used to see if the required files are in the directory


// Create string of 100 characters for names
char firstname[100];
char surname[100];

																		
int choice;																		//Making the choice varible an integer to be used in a switch statement
char filename[100];
char str1[10];
char str2[10];
char str3[10];
char str4[10];
char str5[10];
char YesNo[5];																	//Making the YesNo variable a character to used in a if statement
char *imag1="image01.ppm";
char *imag2="image02.ppm";
char R[5]="red";
char G[10]="green";
char B[5]="blue";
int main(void)																	//Main function where User interface will run

{
	// User is required to enter some details
	printf("Hello and welcome to PPM image corrector \n");						
	printf("Please enter your first name:");
	scanf("%s", &firstname);													
	printf("Please enter your last name:");
	scanf("%s", &surname);

	printf("Hello %s %s and welcome to the PPM image corrector\n", firstname, surname );
	printf("%s have you put all the red,blue,green files\nin the programming directory?(Y/N)\n: ", firstname, surname);
	scanf("%s", &YesNo);
	
	//Using the if statement to see if the user has the required files
 if((strcmp(YesNo, "Y")==0) || (strcmp(YesNo, "y")==0))
	{
	
		printf("What do you want to do? Please choose an option.\n");			//Options the program allows the user to do 
		printf("1. View first image(rugby players)\n");
		printf("2. View second image(chemistry student)\n");
		printf("3. View both images\n");
		printf("4. Close Program\n");
		printf("5. Enter filename to open\n");
		printf("6. Use image editor(to see incorrect rotated images of Image02)\n");
		printf("7. Use image editor(to see incorrect rotated images of Image01)\n");
		do
		{
			printf("Enter Your choice: ");										//Using an integer to make a choice 
			scanf("%d", &choice);
			switch(choice)														// The switch function allows the user to do choose a number of options
			{
				//Case 1 creates the image01.ppm image
			case (1): 
					checkgreen();
					checkblue();
					checkred();
					//Runs the loop created in functions.c file 
					

					Redfile();
					
					Greenfile();
					
					Bluefile();
					

					FinalImage();
					
					//Confirm to the user the that the files been created
					printf("File created please look in program directory\n");
					getchar();
					return(0);
					break;														//Break function makes sure only one case executes
			
					//Case 2 creates the file of the chemistry student
			case (2):
					checkred2();
					checkblue2();
					checkgreen2();
					//Running file loops(functions) 

					redtxt();		

					greentxt();
					
					bluetxt();

					finalimage2();
					printf("File created please look in program directory\n");	//The user is told that the file has been created succesfully
		
					break;
			//Case 3 creates both file
			case (3):
				checkblue();
				checkblue2();
				checkred2();
				checkred();
				checkgreen2();
				checkgreen();

				// Runs code for both images
					
					redtxt();
					
					greentxt();
					bluetxt();
					finalimage2();
					
					Redfile();
				
					Greenfile();
					
					Bluefile();
					FinalImage();
					getchar();
					printf("Both Files created please look in program directory\n"); //tells user both file been successfully created
					break;
			
			//Case 4 is if the user wishes to terminate the program
			case (4):
				printf("Closing program\n"); 
					exit(1);
					//the exit(1) closes down the program
						
			case (5):

				printf("Enter a filename (image01 or image02):");
				scanf("%s" , filename);
				sprintf(str1,"%s"".red" , filename);
				sprintf(str2,"%s"".blue" , filename);
				sprintf(str3, "%s"".green" , filename);
				printf("You have chosen the files:\n %s\n %s\n %s\n" , str1, str2, str3);
				sprintf(str4, "%s.ppm" , filename);
				printf("Do you wish to open %s?(Y/N)" , str4);
				scanf("%s", &YesNo);
				if((strcmp(YesNo, "Y")==0) || (strcmp(YesNo, "y")==0))				//Uses the strcmp to recognise user imput
				{
					if(strcmp(str4,imag1)==0)										//Uses the strcmp to recognise user imput
					{
					Redfile();
					Greenfile();
					Bluefile();
					FinalImage();
					printf("File created please look in program directory\n");
					return 0;}

					else if(strcmp(str4,imag2)==0)
					{ redtxt();
					greentxt();
					bluetxt();
					finalimage2();
					printf("File created please look in program directory\n");
					return 0;}
				}

					
				
				{
				return 0;}
				break;
				case (6):
				printf("What part of the image02 do you wish to rotate? (type in red,blue or green)");
				scanf("%s",str5);
			if (strcmp(str5,R)==0)
			{
			redtxtrotate();
			greentxt();
			bluetxt();
			finalimage2();
			printf("File created");
			return 0;
			}
			if(strcmp(str5,G)==0)
			{
			greentxtrotate();
			redtxt();
			bluetxt();
			finalimage2();
			printf("File created");
			return 0;
			}

			if(strcmp(str5,B)==0)
			{
			bluetxtrotate();
			redtxt();
			greentxt();
			finalimage2();
			printf("File created");
			return 0;
			}
			

			break;
			case(7):
			printf("What part of the image01 do you wish to rotate? (type in red,blue or green)");
			scanf("%s",str5);
			if (strcmp(str5,R)==0)
				{
				Redfile2();
				Greenfile();
				Bluefile();
				FinalImage();
				printf("File created");
				return 0;
			}
			if(strcmp(str5,G)==0)
				{
				Greenfile2();	
				Redfile();
				Bluefile();
				FinalImage();
				printf("File created");
				return 0;
			}

			if(strcmp(str5,B)==0)
				{
				Bluefile2();
				Redfile();
				Greenfile();
				FinalImage();
				printf("File created");
				return 0;
			}
			

			break;
			
			//Default is where if the user inputs an unusable integer
			default: printf("\n%d is not a vaild choice.\n",choice);				//This allows the user to attempt again a suitable integer 
					printf("Try Again.\n");											//Advices the user to try again and put an integer that is suitable
					break;
}	
			
			
			}		while((choice<1)||(choice>7));									//This makes sure that the default function runs correctly
					{return 1;														//Any value entered by the user that not 1,2,3,4 the program will tell the user to enter another number
				}

				
	
					


}
	else if((strcmp(YesNo, "N")==0) || (strcmp(YesNo, "n")==0))
										//The else if statement is used here if the user doesnt have the required files
				{
					
				checkblue();
				checkblue2();
				checkred2();
				checkred();
				checkgreen2();
				checkgreen();
					

					//When all files have been checked and verified the switch function operates, and leads the user to the same option as before if had said yes

}
					printf("What do you want to do? Please choose an option.\n");//Repeat of the same switch statement, after scanning the files
		printf("1. View first image(rugby players)\n");
		printf("2. View second image(chemistry student)\n");
		printf("3. View both images\n");
		printf("4. Close Program\n");
		printf("5. Enter filename to open\n");
		printf("6. Use image editor(to see incorrect rotated images of Image02)\n");
		printf("7. Use image editor(to see incorrect rotated images of Image01)\n");
		do
		{
			printf("Enter Your choice: ");
			scanf("%d", &choice);
			switch(choice)
			{
			case (1):
					Redfile();
					Greenfile();
					Bluefile();
					
					FinalImage();
					printf("File created please look in program directory\n");
					getchar();
					return(0);
					break;
			
			case (2):
					redtxt();
					greentxt();
					bluetxt();
					finalimage2();
					printf("File created please look in program directory\n");
					getchar();
					break;
			
			case (3):
				redtxt();
				greentxt();
				bluetxt();
				finalimage2();

				Redfile();
					Greenfile();
					Bluefile();
					FinalImage();
					getchar();
					printf("Both Files created please look in program directory\n");
					break;
			case (4):
				printf("Closing program\n");
					exit(1);

			case (5):

				printf("Enter a filename(image01 or image02):");
				scanf("%s" , filename);
				sprintf(str1,"%s"".red" , filename);
				sprintf(str2,"%s"".blue" , filename);
				sprintf(str3, "%s"".green" , filename);
				printf("You have chosen the files:\n %s\n %s\n %s\n" , str1, str2, str3);
				sprintf(str4, "%s.ppm" , filename);
				printf("Do you wish to open %s?(Y/N)" , str4);
				scanf("%s", &YesNo);
				if((strcmp(YesNo, "Y")==0) || (strcmp(YesNo, "y")==0))				//Uses the strcmp to recognise user imput
				{
					if(strcmp(str4,imag1)==0)										//Uses the strcmp to recognise user imput
					{
					Redfile();
					Greenfile();
					Bluefile();
					FinalImage();
					printf("File created please look in program directory\n");
					return 0;}

					else if(strcmp(str4,imag2)==0)
					{ redtxt();
					greentxt();
					bluetxt();
					finalimage2();
					printf("File created please look in program directory\n");
					return 0;}
				}

					
				
				{
				return 0;}
				break;

			case (6):
				printf("What part of the image02 do you wish to rotate? (type in red,blue or green)");
				scanf("%s",str5);
			if (strcmp(str5,R)==0)
			{
			redtxtrotate();
			greentxt();
			bluetxt();
			finalimage2();
			printf("File created\n");
			return 0;
			}
			if(strcmp(str5,G)==0)
			{
			greentxtrotate();
			redtxt();
			bluetxt();
			finalimage2();
			printf("File created\n");
			return 0;
			}

			if(strcmp(str5,B)==0)
			{
			bluetxtrotate();
			redtxt();
			greentxt();
			finalimage2();
			printf("File created\n");
			return 0;
			}
			case(7):
			printf("What part of the image01 do you wish to rotate? (type in red,blue or green)");
			scanf("%s",str5);
			if (strcmp(str5,R)==0)
				{
				Redfile2();
				Greenfile();
				Bluefile();
				FinalImage();
				printf("File created\n");
				return 0;
			}
			if(strcmp(str5,G)==0)
				{
				Greenfile2();	
				Redfile();
				Bluefile();
				FinalImage();
				printf("File created\n");
				return 0;
			}

			if(strcmp(str5,B)==0)
				{
				Bluefile2();
				Redfile();
				Greenfile();
				FinalImage();
				printf("File created\n");
				return 0;
			}
			

			break;

			
			default: printf("\n%d is not a vaild choice.\n",choice);
					printf("Try Again.\n");
					break;
}	
			
			
			}		while((choice<1)||(choice>7));
					{return 0;
				}

}
    




















	
	
				
 
	
	

	
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		