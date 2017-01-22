#pragma once

#define SIZE 10
#define BLANK '*'
#define FLAG  'F'
#define MINE -1
#define SELECTION 'n'
#define NOTSELECTION 'u'

enum ARROWKEY
{
	ENTER = 13,
	ARROW_UP = 256 + 72,
	ARROW_DOWN = 256 + 80,
	ARROW_LEFT = 256 + 75,
	ARROW_RIGHT = 256 + 77,
};
enum STATE
{
	WIN = 1,
	LOSE = -1,
	DO_AGAIN = 0,
	EXIT = 2
};

enum NUMBEROFMINES
{
	HARD = 15,
	MEDIUM = 10,
	EASY= 5

};

enum ACTION
{
	INIT = 0,
	SELECT = 100,
	FLAGMINE = 200,
	RESET = 300,
	EXITGAME = 400,
	ARROW=500
};
//display functions
void SelectColour(int k);
void WelcomeScreen();
int SelectLevel();
void Win();
void Lose();
void CursorPosition(int, int);
void RevealSlot(char chInterfaceMatrix[][SIZE][2], int i, int j);
int PlayAgainScreen();
void EnterToStart(void);

int GetInput(void);
