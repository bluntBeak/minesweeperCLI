

#include <stdio.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <conio.h>
#include"Header.h"

//get arrowkey input
int GetInput(void)
{
	int ch = _getch();

	if (ch == 0 || ch == 224)
		ch = 256 + _getch();
	return ch;
}
// transfer cursor from origin to  desired location
void CursorPosition(int x, int y)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cor;
	cor.X = 10+x; 
	cor.Y = 10+y;
	SetConsoleCursorPosition(hConsole, cor);
}

//gives colour to text
void SelectColour(int k)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k);
}

//Function that greets the user to the game.
void WelcomeScreen(void)
{
	int i = 0;

	while (1)
	{
		
		i++;

		system("cls");

		int nLagg = 1000;

		//system("COLOR 1F");

		CursorPosition(0,0);
					
		printf("       /'\\_/`\\  __                                                                           \n");
		CursorPosition(0,1);
		printf("      /\\      \\/\\_\\    ___      __    ____  __  __  __     __     __   _____      __   _ __  \n");
		CursorPosition(0,2);
		printf("      \\ \\ \\__\\ \\/\\ \\ /' _ `\\  /'__`\\ /',__\\/\\ \\/\\ \\/\\ \\  /'__`\\ /'__`\\/\\ '__`\\  /'__`\\/\\`'__\\\n");
		CursorPosition(0,3);
		printf("       \\ \\ \\_/\\ \\ \\ \\/\\ \\/\\ \\/\\  __//\\__, `\\ \\ \\_/ \\_/ \\/\\  __//\\  __/\\ \\ \\L\\ \\/\\  __/\\ \\ \\/ \n");
		CursorPosition(0,4);
		printf("        \\ \\_\\\\ \\_\\ \\_\\ \\_\\ \\_\\ \\____\\/\\____/\\ \\___x___/'\\ \\____\\ \\____\\\\ \\ ,__/\\ \\____\\\\ \\_\\ \n");
		CursorPosition(0,5);
		printf("         \\/_/ \\/_/\\/_/\\/_/\\/_/\\/____/\\/___/  \\/__//__/   \\/____/\\/____/ \\ \\ \\/  \\/____/ \\/_/ \n");
		CursorPosition(0,6);
		printf("                                                                         \\ \\_\\               \n");
		CursorPosition(0,7);
		printf("                                                                          \\/_/               \n");
		CursorPosition(0,8);
		printf("                                     ____     __     ______     \n");
		CursorPosition(0,9);
		printf("                                    /\\  _`\\  /\\ \\   /\\__  _\\    \n");
		CursorPosition(0,10);
		printf("                                    \\ \\ \\/\\_\\\\ \\ \\  \\/_/\\ \\/    \n");
		CursorPosition(0,11);
		printf("                                     \\ \\ \\/_/_\\ \\ \\  __\\ \\ \\    \n");
		CursorPosition(0,12);
		printf("                                      \\ \\ \\L\\ \\\\ \\ \\L\\ \\\\_\\ \\__ \n");
		CursorPosition(0,13);
		printf("                                       \\ \\____/ \\ \\____//\\_____\\\n");
		CursorPosition(0,14);
		printf("                                        \\/___/   \\/___/ \\/_____/\n");
		
#ifdef _WIN32
			
			Sleep(nLagg);            //time delay
#else
			usleep(nLagg * 10000);
#endif
			system("cls");

#ifdef _WIN32
			Sleep(nLagg / 8);
#else
			usleep(nLagg * 10000);
#endif
			
			if (i==3)  //exit loop condition based on number of times the screen blinks
			{
				EnterToStart();
				break;
			}
	}
}

//Function that asks the user to start the game.
void EnterToStart(void) 
{
	int ch;

	CursorPosition(0, -10);
	printf("       /'\\_/`\\  __                                                                           \n");
	CursorPosition(0, -9);
	printf("      /\\      \\/\\_\\    ___      __    ____  __  __  __     __     __   _____      __   _ __  \n");
	CursorPosition(0, -8);
	printf("      \\ \\ \\__\\ \\/\\ \\ /' _ `\\  /'__`\\ /',__\\/\\ \\/\\ \\/\\ \\  /'__`\\ /'__`\\/\\ '__`\\  /'__`\\/\\`'__\\\n");
	CursorPosition(0, -7);
	printf("       \\ \\ \\_/\\ \\ \\ \\/\\ \\/\\ \\/\\  __//\\__, `\\ \\ \\_/ \\_/ \\/\\  __//\\  __/\\ \\ \\L\\ \\/\\  __/\\ \\ \\/ \n");
	CursorPosition(0, -6);
	printf("        \\ \\_\\\\ \\_\\ \\_\\ \\_\\ \\_\\ \\____\\/\\____/\\ \\___x___/'\\ \\____\\ \\____\\\\ \\ ,__/\\ \\____\\\\ \\_\\ \n");
	CursorPosition(0, -5);
	printf("         \\/_/ \\/_/\\/_/\\/_/\\/_/\\/____/\\/___/  \\/__//__/   \\/____/\\/____/ \\ \\ \\/  \\/____/ \\/_/ \n");
	CursorPosition(0, -4);
	printf("                                                                         \\ \\_\\               \n");
	CursorPosition(0, -3);
	printf("                                                                          \\/_/               \n");
	CursorPosition(0, -2);
	printf("                                     ____     __     ______     \n");
	CursorPosition(0, -1);
	printf("                                    /\\  _`\\  /\\ \\   /\\__  _\\    \n");
	CursorPosition(0, 0);
	printf("                                    \\ \\ \\/\\_\\\\ \\ \\  \\/_/\\ \\/    \n");
	CursorPosition(0, 1);
	printf("                                     \\ \\ \\/_/_\\ \\ \\  __\\ \\ \\    \n");
	CursorPosition(0, 2);
	printf("                                      \\ \\ \\L\\ \\\\ \\ \\L\\ \\\\_\\ \\__ \n");
	CursorPosition(0, 3);
	printf("                                       \\ \\____/ \\ \\____//\\_____\\\n");
	CursorPosition(0, 4);
	printf("                                        \\/___/   \\/___/ \\/_____/\n");
	CursorPosition(0, 5);
	printf("           ______                           _______         __                __         \n");
	CursorPosition(0, 6);
	printf("          |   __ \\.----.-----.-----.-----. |    ___|.-----.|  |_.-----.----. |  |_.-----.\n");
	CursorPosition(0, 7);
	printf("          |    __/|   _|  -__|__ --|__ --| |    ___||     ||   _|  -__|   _| |   _|  _  |\n");
	CursorPosition(0, 8);
	printf("          |___|   |__| |_____|_____|_____| |_______||__|__||____|_____|__|   |____|_____|\n");
	CursorPosition(0, 9);
	printf("                                                                                         \n");
	CursorPosition(0, 10);
	printf("                 _______ __               __     _______                        __ \n");
	CursorPosition(0, 11);
	printf("                |     __|  |_.---.-.----.|  |_  |     __|.---.-.--------.-----.|  |\n");
	CursorPosition(0, 12);
	printf("                |__     |   _|  _  |   _||   _| |    |  ||  _  |        |  -__||__|\n");
	CursorPosition(0, 13);
	printf("                |_______|____|___._|__|  |____| |_______||___._|__|__|__|_____||__|\n");
	CursorPosition(0, 14);
	printf("                                                                                   \n");

	do 
	{
		ch = _getch();

	} while (ch != ENTER); //exit When enter key is pressed
}

//A level selection function with user input. return an interger
// returns 1 for Easy, 2 for Medium and 3 for Hard
int SelectLevel(void)
{
	int nChoice = 0;  //stores arrow key input
	int nCurrent = 1;  //stores the level to be returned

	do
	{
		system("cls");
		printf("  _____ ______ _      ______ _____ _______   _      ________      ________ _      \n");
		printf(" / ____|  ____| |    |  ____/ ____|__   __| | |    |  ____\\ \\    / /  ____| |     \n");
		printf("| (___ | |__  | |    | |__ | |       | |    | |    | |__   \\ \\  / /| |__  | |     \n");
		printf(" \\___ \\|  __| | |    |  __|| |       | |    | |    |  __|   \\ \\/ / |  __| | |     \n");
		printf(" ____) | |____| |____| |___| |____   | |    | |____| |____   \\  /  | |____| |____ \n");
		printf("|_____/|______|______|______\\_____|  |_|    |______|______|   \\/   |______|______|\n");
		printf("                                      \n");

		if (nCurrent == 1) 
		{
			SelectColour(206);
			CursorPosition(-10, -3);
			printf(" _______ _______ _______ ___ ___ \n");
			printf("|    ___|   _   |     __|   |   |\n");
			printf("|    ___|       |__     |\\     / \n");
			printf("|_______|___|___|_______| |___|  \n");
			printf("                                 \n");
			SelectColour(15);
			printf(" _______ _______ _____ _______ _______ _______ \n");
			printf("|   |   |    ___|     \\_     _|   |   |   |   |\n");
			printf("|       |    ___|  --  ||   |_|   |   |       |\n");
			printf("|__|_|__|_______|_____/_______|_______|__|_|__|\n");
			printf("                                               \n");
			printf(" _______ _______ ______ _____  \n");
			printf("|   |   |   _   |   __ \\     \\ \n");
			printf("|       |       |      <  --  |\n");
			printf("|___|___|___|___|___|__|_____/ \n");
		}
		else if (nCurrent == 2) 
		{
			CursorPosition(-10, -3);
			printf(" _______ _______ _______ ___ ___ \n");
			printf("|    ___|   _   |     __|   |   |\n");
			printf("|    ___|       |__     |\\     / \n");
			printf("|_______|___|___|_______| |___|  \n");
			printf("                                 \n");
			SelectColour(206);
			printf(" _______ _______ _____ _______ _______ _______ \n");
			printf("|   |   |    ___|     \\_     _|   |   |   |   |\n");
			printf("|       |    ___|  --  ||   |_|   |   |       |\n");
			printf("|__|_|__|_______|_____/_______|_______|__|_|__|\n");
			printf("                                               \n");
			SelectColour(15);
			printf(" _______ _______ ______ _____  \n");
			printf("|   |   |   _   |   __ \\     \\ \n");
			printf("|       |       |      <  --  |\n");
			printf("|___|___|___|___|___|__|_____/ \n");
		}
		else if (nCurrent == 3)
		{
			CursorPosition(-10, -3);
			printf(" _______ _______ _______ ___ ___ \n");
			printf("|    ___|   _   |     __|   |   |\n");
			printf("|    ___|       |__     |\\     / \n");
			printf("|_______|___|___|_______| |___|  \n");
			printf("                                 \n");
			printf(" _______ _______ _____ _______ _______ _______ \n");
			printf("|   |   |    ___|     \\_     _|   |   |   |   |\n");
			printf("|       |    ___|  --  ||   |_|   |   |       |\n");
			printf("|__|_|__|_______|_____/_______|_______|__|_|__|\n");
			printf("                                               \n");
			SelectColour(206);
			printf(" _______ _______ ______ _____  \n");
			printf("|   |   |   _   |   __ \\     \\ \n");
			printf("|       |       |      <  --  |\n");
			printf("|___|___|___|___|___|__|_____/ \n");
			SelectColour(15);
		}
		nChoice = GetInput();
			//Code to move space up
			if (nChoice == ARROW_UP)
			{
				nCurrent = nCurrent - 1;
				
				if (nCurrent == 0)
				{
					nCurrent = 3;
				}
			}
			else if (nChoice == ARROW_DOWN)
			{
				nCurrent = nCurrent + 1;
			
				if (nCurrent == 4)
				{
					nCurrent = 1;
				}
			}
	} while (nChoice != ENTER);

	return nCurrent;
}

// prints the you win! screen
void Win(void)
{
	system("cls");
	
	int nLagg = 30;
	
	printf("                                                                                       \n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("                   YYYYYYY       YYYYYYY     OOOOOOOOO     UUUUUUUU     UUUUUUUU\n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("                   Y:::::Y       Y:::::Y   OO:::::::::OO   U::::::U     U::::::U\n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("                   Y:::::Y       Y:::::Y OO:::::::::::::OO U::::::U     U::::::U\n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("                   Y::::::Y     Y::::::YO:::::::OOO:::::::OUU:::::U     U:::::UU\n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("                   YYY:::::Y   Y:::::YYYO::::::O   O::::::O U:::::U     U:::::U \n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("                      Y:::::Y Y:::::Y   O:::::O     O:::::O U:::::D     D:::::U \n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("                       Y:::::Y:::::Y    O:::::O     O:::::O U:::::D     D:::::U \n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("                        Y:::::::::Y     O:::::O     O:::::O U:::::D     D:::::U \n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("                         Y:::::::Y      O:::::O     O:::::O U:::::D     D:::::U \n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("                          Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U \n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("                          Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U \n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("                          Y:::::Y       O::::::O   O::::::O U::::::U   U::::::U \n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("                          Y:::::Y       O:::::::OOO:::::::O U:::::::UUU:::::::U \n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("                       YYYY:::::YYYY     OO:::::::::::::OO   UU:::::::::::::UU  \n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("                       Y:::::::::::Y       OO:::::::::OO       UU:::::::::UU    \n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("                       YYYYYYYYYYYYY         OOOOOOOOO           UUUUUUUUU          \n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("                                                                                 \n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("    WWWWWWWW                           WWWWWWWWIIIIIIIIIINNNNNNNN        NNNNNNNN      !!!  !!! \n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("    W::::::W                           W::::::WI::::::::IN:::::::N       N::::::N     !!:!!!!:!!\n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("    W::::::W                           W::::::WI::::::::IN::::::::N      N::::::N     !:::!!:::!\n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("    W::::::W                           W::::::WII::::::IIN:::::::::N     N::::::N     !:::!!:::!\n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("     W:::::W           WWWWW           W:::::W   I::::I  N::::::::::N    N::::::N     !:::!!:::!\n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("      W:::::W         W:::::W         W:::::W    I::::I  N:::::::::::N   N::::::N     !:::!!:::!\n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("       W:::::W       W:::::::W       W:::::W     I::::I  N:::::::N::::N  N::::::N     !:::!!:::!\n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("        W:::::W     W:::::::::W     W:::::W      I::::I  N::::::N N::::N N::::::N     !:::!!:::!\n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("         W:::::W   W:::::W:::::W   W:::::W       I::::I  N::::::N  N::::N:::::::N     !:::!!:::!\n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("          W:::::W W:::::W W:::::W W:::::W        I::::I  N::::::N   N:::::::::::N     !:::!!:::!\n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("           W:::::W:::::W   W:::::W:::::W         I::::I  N::::::N    N::::::::::N     !!:!!!!:!!\n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("            W:::::::::W     W:::::::::W          I::::I  N::::::N     N:::::::::N      !!!  !!! \n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("             W:::::::W       W:::::::W         II::::::IIN::::::N      N::::::::N               \n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("              W:::::W         W:::::W          I::::::::IN::::::N       N:::::::N      !!!  !!! \n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("               W:::W           W:::W           I::::::::IN::::::N        N::::::N     !!:!!!!:!!\n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	printf("                WWW             WWW            IIIIIIIIIINNNNNNNN         NNNNNNN      !!!  !!! \n");
#ifdef _WIN32
	Sleep(nLagg);
#else
	usleep(nLagg * 100);
#endif
	
	//printf("\n\nPress any key --> ");
	system("pause");
	system("cls");
	

}

//prints you lose! screen
void Lose(void)
{
	int i = 0;
	do 
	{
		system("cls");
		
		int nLagg = 30;
		
		printf("              	        __     ______  _    _   _      ____   _____ ______ \n");
		printf("                        \\ \\   / / __ \\| |  | | | |    / __ \\ / ____|  ____|\n");
		printf("                         \\ \\_/ / |  | | |  | | | |   | |  | | (___ | |__   \n");
		printf("                          \\   /| |  | | |  | | | |   | |  | |\\___ \\|  __|  \n");
		printf("                           | | | |__| | |__| | | |___| |__| |____) | |____ \n");
		printf("                          |_|  \\____/ \\____/  |______\\____/|_____/|______|\n");
	
		i++;
#ifdef _WIN32
		Sleep(nLagg);
#else
		usleep(nLagg * 100);
#endif
	} while (i < 3);
}

//Function that asks the user if they would like to continue.
// returns 1 for yes and 2 for a no.
int PlayAgainScreen(void)
{
	//system("cls");
	int i = 0;
	int nChoice = 0;
	int nCurrent = 1;

	do
	{
		CursorPosition(-10,-3);
		printf("\nDO YOU WANT TO PLAY AGAIN ?\n");
		
		if (nCurrent == 1) 
		{
			CursorPosition(-10, -1);
			SelectColour(206);
			printf(" ___ ___ _______ _______ \n");
			printf("|   |   |    ___|     __|\n");
			printf(" \\     /|    ___|__     |\n");
			printf("  |___| |_______|_______|\n");
			printf("\n");
		
			SelectColour(15);
			printf(" _______ _______ \n");
			printf("|    |  |       |\n");
			printf("|       |   -   |\n");
			printf("|__|____|_______|\n");
			printf("\n");
		}
		
		else
		{
			printf(" ___ ___ _______ _______ \n");
			printf("|   |   |    ___|     __|\n");
			printf(" \\     /|    ___|__     |\n");
			printf("  |___| |_______|_______|\n");
			printf("\n");
			CursorPosition(-10, 4);
			SelectColour(206);

			printf(" _______ _______ \n");
			printf("|    |  |       |\n");
			printf("|       |   -   |\n");
			printf("|__|____|_______|\n");
			printf("\n");
			SelectColour(15);
		}

		nChoice = GetInput();
		//Code to move space up
		if (nChoice == ARROW_UP) 
		{
			nCurrent = nCurrent - 1;
			if (nCurrent == 0)
			{
				nCurrent = 2;
			}
		}
		else
		{
			if (nChoice == ARROW_DOWN)
			{
				nCurrent = nCurrent + 1;

				if (nCurrent == 3)
				{
					nCurrent = 1;
				}
			}
		}
	} while (nChoice != ENTER);

	return nCurrent;
}