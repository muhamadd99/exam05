//parsing
//what to check
//3 parameter: weight height and no of iterations

//print
//wasd for movement
//xx for pen

//iterate and gol simulation
//gol simulation
//allocate memory by allocating border line too
//using check around


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac != 4)
		return 1;

	int	width = atoi(av[1]);
	int	height = atoi(av[2]);
	int	iterations = atoi(av[3]);

	if (width < 0 || height < 0 || iterations < 0)
		return 1;

	int x = 1 , y = 1;
	int pen = 0;
	int	grid[2][height + 2][width + 2]; //3d grid
	char c;
	//fill with 0 for borders & map itself
	for(int k = 0; k < 2; k++)
		for (int i = 0; i < height + 2; i++)
			for (int j = 0; j < width + 2; j++)
				grid[k][i][j] = 0;

	//check the input from read
	while (read(0, &c, 1) > 0)
	{
		if (c == 'w' && y > 1)
			y--;
		else if (c == 's' && y < height)
			y++;
		else if (c == 'd' && x < width)
			x++;
		else if (c == 'a' && x > 1)
			x--;
		else if (c == 'x')
			pen = !pen;
		if (pen)
			grid[0][y][x] = 1;
	}
	//gol simulation handling
	//one iterator to iterate current. one for next
	//another dydx concept (iterator) concept to check surrounding marking
	//
	//declare current
	//declare next
	for(int it = 0; it < iterations; it++)
	{
		int curr = it % 2;
		int	next = (it + 1) % 2;
		for (int i = 1; i <= height; i++)
		{
			for (int j = 1; j <= width; j++)
			{
				int n = 0;
				for (int dy = -1; dy <= 1; dy++)
				{
					for (int dx = -1; dx <= 1; dx++)
					{
						if (dx != 0 || dy != 0)
							n += grid[curr][i + dy][j + dx]; 
					}
				}
				//the rule of if cell alive, only need 2/3 surrounding to be alive
				//the rule of if cell dead, need 3 surrounding to be alive
				if (grid[curr][i][j] == 1)
					grid[next][i][j] = (n == 2 || n == 3);
				else
					grid[next][i][j] = (n == 3);
			}
		}
	}
	//print the results
	int final = iterations % 2;
	for (int i = 1; i <= height; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			if (grid[final][i][j])
				putchar('0');
			else
				putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}