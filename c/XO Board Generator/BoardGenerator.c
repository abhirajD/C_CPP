#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char grid[100][100];

int main()
{
	srand(time(NULL));
	//Increase Randomness
	rand();
	rand();
	rand();
	int i,j;
	int N = 20;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			grid[i][j] = '1';

/*	---Wall Generation---
 * 	Wall directions: (No diagonal walls)
 * 		2
 * 		^
 * 		|
 * 		|
 *     -1 <---     ---> 1
 *		|
 *		|
 *		v
 *		-2
*/

	int wallX,wallY,wallLength;
	int keyXRed, keyYRed;
	//Make numberofWalls random.(between 0 and N-3 probably.)
	int numberOfWalls=(rand()%(N-3)),wallDirection;

	for(i=0;i<numberOfWalls;i++)
	{
		wallX = (rand()%N) + 1;
		wallY = (rand()%N) + 1;
		wallLength = (rand()%(N-1));
		if(wallLength >= N-3) wallLength -= 2;
		wallDirection = -(rand()%2 + 1);
		//wallX = 0;
		//wallY = 2;
		//wallLength = 5;
		//wallDirection = 1;
		switch(wallDirection)
		{
			case 1:
				for(j=0;j<wallLength;j++)
					if(wallY + j < N) grid[wallX][wallY+j] = 'W'; else break;
				break;
			case -1:
				for(j=0;j<wallLength;j++)
					if(wallY - j >= 0) grid[wallX][wallY-j] = 'W'; else break;
				break;
			case 2:
				for(j=0;j<wallLength;j++)
					if(wallX - j >= 0) grid[wallX-j][wallY] = 'W'; else break;
				break;
			case -2:
				for(j=0;j<wallLength;j++)
					if(wallX + 1 < N) grid[wallX+j][wallY] = 'W'; else break;
				break;
		}
	}

	// The red key is to the left part of the board and the Blue key to the right part.
	do{keyXRed = (rand()%((int)(N/2))) + 1, keyYRed = (rand()%((int)(N/2))) + 1;}
	while(keyXRed != keyYRed);

	//You could use transpose of the prior position for the next key. if b == [i][j] , u could sy r == [j][i]
	//int keyXBlue = (rand()%((int)(N/2)-1)) + N/2 -1, keyYBlue = (rand()%((int)(N/2)-1))+N/2-1;

	grid[keyXRed][keyYRed] = 'R';
	grid[(N - keyYRed - 1)][(N - keyXRed - 1)] = 'B';
	//grid[keyXBlue][keyYBlue] = 'B';

	// C denotes the center of the board.
	grid[N/2][N/2] = 'C';

	for(i=0;i<N;i++) {
		for(j=0;j<N;j++)
		{
		    if(grid[i][j] != '1')
		    printf("%c",grid[i][j]);
		    else
		    printf(".");
		}
		printf("\n");
	}
	return 0;
}
