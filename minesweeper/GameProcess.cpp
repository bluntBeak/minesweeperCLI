// A Minesweeper Clone made in the C programming language that uses the Command Line Interface.
// Made for the ID 1100 CS module.
// Team Members: Harsh Yadav, Libin N. George, Anish M. M., Jude K. Anil, Adrian McDonald Tariang.
// Initial Code written on :- 5th November 2015,
// Finallized on the 14th of November, 2015.
// Final Review done on the 16th of November, 2015.

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"Header.h"

typedef struct Coordinate  //structure to store user input 
{
	int x, y;
	char action;
} coord;

//function declarations
int DetermineLevel(void);
void PrintResult(int);
void GenerateMinePosition(int, int[], int[]);
void GenerateField(int, int[][SIZE]);
void UpdateField(int[][SIZE]);
int ProcessInput(coord, int[][SIZE], char[][SIZE], int);
coord RecieveInput(void);
int GenerateRandomNo(void);


//display functions
int ShowSurrouding(coord, int[][SIZE], char[][SIZE]);
void DisplayMatrix2(int[][SIZE]);
void DisplayMatrix(char[][SIZE]);




int g_maxNoOfFlags = 0; //global variable declaration

void main()
{
	int nLevel = 0;
	int nMinefield[SIZE][SIZE];     //reference matrix or actual minefield
	char chInterfaceMatrix[SIZE][SIZE]; //the matrix seen by the user
	int nFlag; //stores end result of each user input ,win ,lose ,do again
	int i, j;
	coord input;   
	int chPlayAgain; 
	
	WelcomeScreen();

	do {
		input.action = 'i';  //call to initialize static variables in case of chPlayAgain
		nFlag = ProcessInput(input, nMinefield, chInterfaceMatrix, nLevel);

		nLevel = DetermineLevel();

		GenerateField(nLevel, nMinefield);  //Minefield is generated

		for (i = 0; i < SIZE; i++) //initialize chInterface Matrix 
		{
			for (j = 0; j < SIZE; j++)
			{
				chInterfaceMatrix[i][j] = BLANK;
			}
		}

		do                       //user input loop
		{
			system("cls");
			DisplayMatrix(chInterfaceMatrix);
			input = RecieveInput();
			nFlag = ProcessInput(input, nMinefield, chInterfaceMatrix, nLevel);
		} while (nFlag == DO_AGAIN);
		
		system("cls");
		
		printf("\n\n\n");
		DisplayMatrix2(nMinefield);  //shows the uncovered matrix 
		printf("\n\n\n");
		_getch();
		system("cls");
		
		PrintResult(nFlag);
		
		do                      
		{
			chPlayAgain = PlayAgainScreen();
		} while (!(chPlayAgain == 1 || chPlayAgain == 2));  //to prevent invalid exit from main function    
	} while (chPlayAgain == 1);
}

//displays the slot in colour   
void RevealSlot(char chInterfaceMatrix[][SIZE], int i, int j)
{
	if (chInterfaceMatrix[i][j] == '*')   
	{
		SelectColour(240);
		printf("%c", chInterfaceMatrix[i][j]);
		SelectColour(31);
	}
	else
	{
		if (chInterfaceMatrix[i][j] == 'F')
		{
			SelectColour(156);
			printf("%c", chInterfaceMatrix[i][j]);
			SelectColour(31);
		}
		else
		{
			SelectColour(208);
			printf("%c", chInterfaceMatrix[i][j]);
			SelectColour(31);
		}
	}
}

//function to process Level choice
int DetermineLevel()
{
	int nChoice;

	while (1) //loop to ensure correct user entry
	{
		system("cls");
		
		nChoice = SelectLevel();
		
		switch (nChoice)
		{
		case 1:
		{
			g_maxNoOfFlags = 8;
			return EASY;
		}
		break;

		case 2:
		{
			g_maxNoOfFlags = 14;
			return MEDIUM;
		}
		break;
		case 3:
		{
			g_maxNoOfFlags = 20;
			return HARD;
		}
		break;

		default:printf("\n INVALID LEVEL CHOICE !");
			continue;
		}
	}


}

//function to generate the Minefield
void GenerateField(int nNoOfMines, int nMinefield[][SIZE])
{
	int nMineRow[50];
	int nMineColumn[50];
	int i, j;

	
	//initializing array elements to 0
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			nMinefield[i][j] = 0;
		}
	}

	GenerateMinePosition(nNoOfMines, nMineRow, nMineColumn); //generates mine co-ordinates 

	for (i = 0; i < nNoOfMines; i++)
	{
		nMinefield[nMineRow[i]][nMineColumn[i]] = MINE;
	}

	UpdateField(nMinefield); //to update the Minefield to display the number of mines surronding a slot
}

// function to generate random mine positions
void GenerateMinePosition(int nNoOfMines, int nMineRow[], int nMineColumn[])
{
	int i, j;
	int nRandomNumber[50];
	printf("                                Loading...\n                               ");

	for (i = 0; i < nNoOfMines; i++)
	{
		printf("\b\b\b\b\b\b"); 
		nRandomNumber[i]= GenerateRandomNo();
		nMineRow[i] = nRandomNumber[i] / 10;        // stores x co-ordinates of the mines
		nMineColumn[i] = nRandomNumber[i] % 10;     //stores y co-ordinates of the mines
		printf("**%.2f%%",((float)i/nNoOfMines)*100);
		for (j = 0; j < i; j++)
		{												// corrects if similar coordinates occur
			while (nRandomNumber[i] == nRandomNumber[j])
			{
				nRandomNumber[i] = GenerateRandomNo();
				nMineRow[i] = nRandomNumber[i] / 10;        
				nMineColumn[i] = nRandomNumber[i] % 10;
				j = 0;
			}

		}
	}


}

//function to update the Minefield to display the number of mines surronding a slot
void UpdateField(int nMinefield[][SIZE])
{
	int i, j, k, l;         //loop variables

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (nMinefield[i][j] == - 1)
			{
				for (k = (i - 1); k <= (i + 1); k++)
				{
					for (l = (j - 1); l <= (j + 1); l++)
					{
						if ((nMinefield[k][l] != MINE) &&(k >= 0) &&(k < SIZE) &&(l >= 0) &&(l < SIZE))
						{
							++nMinefield[k][l];
						}
					}
				}
			}
		}

	}
}

// function stores input from the user
coord RecieveInput(void)
{
	coord input;

	int nRetry;
	do {
		nRetry = 0;

		printf("\n\n ENTER THE ACTION \ns for select\nf for flag \nr for reset flag\ne for exit from current game");
		
		do
		{
			input.action = _getch();
		} while (!(input.action == 's' || input.action == 'f' || input.action == 'r' || input.action == 'e'));

		if (input.action == 'e')
		{
			break;
		}

		printf("\n ENTER THE ROW NUMBER ---> ");
		scanf_s("%d", &input.x);
		input.x--;
		printf("\n ENTER THE COLUMN NUMBER ---> ");
		scanf_s("%d", &input.y);
		input.y--;

		//row and column varies from 0 to SIZE-1
		if ((input.x > SIZE - 1) ||(input.y > SIZE - 1) ||(input.x < 0) ||(input.y < 0))
		{
			printf("\n WRONG INPUT! ");
			nRetry = 1;
		}
	} while (nRetry == 1);

	return input;
}

// function to process the user input
int ProcessInput(coord input, int nMinefield[][SIZE], char chInterfaceMatrix[][SIZE], int nNoOfMines)
{
	static int nFlagCounter = 0; //keeps track of the number of flags placed by the user
	static char chFlagMatrix[SIZE][SIZE]; //keeps track of flagged positions
	static int noOfSelections = 0; //records no of selections(mine absent) made
	int nState = 0;

	if (input.action == 's')   //selction pathways
	{
		if (chInterfaceMatrix[input.x][input.y] == BLANK)
		{
			if (nMinefield[input.x][input.y] == MINE)//checks if user input is a flag or not  
			{
				chInterfaceMatrix[input.x][input.y] = '!'; //! stands for mine as shown to the user 
				nState = LOSE;
			}

			else
			{
				noOfSelections++;
				chInterfaceMatrix[input.x][input.y] = (char)(48 + nMinefield[input.x][input.y]);
				if (nMinefield[input.x][input.y] == 0)
				{
					noOfSelections = noOfSelections + ShowSurrouding(input,nMinefield,chInterfaceMatrix);
				}
				
				if (noOfSelections ==(SIZE*SIZE - nNoOfMines))
				{
					nState = WIN;
				}
				else
				{
					nState = DO_AGAIN;
				}
			}
		}

		else
			nState = DO_AGAIN;
	}

	else if (input.action == 'f')  //flag pathways
	{
		if (nFlagCounter == g_maxNoOfFlags)
		{
			printf("too many flags\n");
			nState = DO_AGAIN;
		}

		else if (chInterfaceMatrix[input.x][input.y] == BLANK)  //to check whether the slot has been selected or not
		{
			chFlagMatrix[input.x][input.y] = FLAG;
			nFlagCounter++;
			chInterfaceMatrix[input.x][input.y] = FLAG;
			printf("%d\n", nFlagCounter);
			if (nFlagCounter == nNoOfMines)   //to check whether if all the mines and nothing but the mines are flagged 
			{
				int i, j;
				int nCounter = 0;

				for (i = 0; i < SIZE; i++)
				{
					for (j = 0; j < SIZE; j++)
					{
						if (chFlagMatrix[i][j] == FLAG && nMinefield[i][j] == MINE)
						{
							nCounter++;
						}

					}
				}
				if (nCounter == nNoOfMines)
				{
					nState = WIN;
				}
				else
				{
					nState = DO_AGAIN;
				}
			}
			return nState;
		}

		else
		{
			nState = DO_AGAIN;
			printf("CANNOT PLACE FLAG THERE\n"); //error condition
		}
	}

	else if (input.action == 'r') // flag reset pathway
	{
		if (chFlagMatrix[input.x][input.y] == FLAG) //to check whether it has been flagged or not yet
		{
			chInterfaceMatrix[input.x][input.y] = BLANK;
			nFlagCounter--;
			chFlagMatrix[input.x][input.y] = BLANK;
			nState = DO_AGAIN;
		}
		else
		{
			printf("NO FLAG TO RESET\n");
			nState = DO_AGAIN;
		}
	}
	else if (input.action == 'i')  //static variables initialization pathway
	{
		nFlagCounter = 0;
		noOfSelections = 0;

		int i, j;
		for (i = 0; i < SIZE; i++)
		{
			for (j = 0; j < SIZE; j++)
			{
				chFlagMatrix[i][j] = BLANK;
			}
		}
		nState = DO_AGAIN;
	}
	else if (input.action == 'e')
	{
		nState = EXIT;
	}
	else
	{
		nState = DO_AGAIN;
	}
	return nState;
}

// displays the user interface field 
void DisplayMatrix(char chInterfaceMatrix[][SIZE])
{
	int i, j;

	printf("\t ");
	for (i = 0; i < SIZE; i++)  //diplays column number
	{
		printf("\t%d", i+1);
	}
	printf("\n");
	printf("\n");

	for (i = 0; i < SIZE; i++)
	{
		printf("\t%d", i+1);   //displays row number
		for (j = 0; j < SIZE; j++)
		{
			if (j!=0)
			{
				SelectColour(240);
				printf("\t");
				SelectColour(31);
				RevealSlot(chInterfaceMatrix, i, j);
			}
			else
			{
				SelectColour(31);
				printf("\t");
				RevealSlot(chInterfaceMatrix, i, j);
			}
		}
		printf("\n");
	}
}

//diplays solution matrix
void DisplayMatrix2(int nMineField[][SIZE])
{
	int i, j;

	printf("\t ");
	for (i = 0; i < SIZE; i++)
	{
		printf("\t%d", i);
	}
	printf("\n");
	printf("\n");

	for (i = 0; i < SIZE; i++)
	{
		printf("\t%d", i);
		for (j = 0; j < SIZE; j++)
		{
			printf("\t%d", nMineField[i][j]);
		}
		printf("\n");
		printf("\n");
	}
	printf("    PRESS ENTER TO CONTINUE....");
	return;
}

//function to print final result 
void PrintResult(int nFlag)
{
	if (nFlag == WIN)
	{
		Win();
	}
	else if (nFlag == LOSE)
	{
		Lose();
	}
	return;
}

//generates random numbers
int GenerateRandomNo(void)
{

	time_t t;
	

	//initializes the GenerateMinePosition number generator
	srand((unsigned)time(&t));
	return rand() % 100;
}
int ShowSurrouding(coord input, int nMinefield[][SIZE], char chInterfaceMatrix[][SIZE])
{
	int nNoOfSelections=0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (((input.x) - 1 + i)<10 && ((input.x) - 1 + i)>=0 && ((input.y) - 1 + j)<10 && ((input.y) - 1 + j)>=0)
			{
				if (chInterfaceMatrix[(input.x) - 1 + i][(input.y) - 1 + j] == '*')
				{
					nNoOfSelections++;
					chInterfaceMatrix[(input.x) - 1 + i][(input.y) - 1 + j] = (char)(48 + nMinefield[(input.x) - 1 + i][(input.y) - 1 + j]);
					if (nMinefield[(input.x) - 1 + i][(input.y) - 1 + j] == 0)
					{
						nNoOfSelections += ShowSurrouding(input, nMinefield, chInterfaceMatrix);
					}
				}
			}
			

		}
	}
		
	return nNoOfSelections;
}
