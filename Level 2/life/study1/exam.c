#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	//check input
	if (ac != 4)
		return 1;

	int		width = atoi(av[1]);
	int		height = atoi(av[2]);
	int		iterations = atoi(av[3]);

	if (width < 0 || height < 0 || iterations < 0)
		return 1;
	char	c;
	int		grid[2][height + 2][width + 2];
	int		x = 1, y = 1;
	int		pen = 0;

	//allocate 2 2d array using 3 pointer
	for (int k = 0; k < 2; k++)
		for (int i = 0; i < height + 2; i++)
			for (int j = 0; j < width + 2; j++)
				grid[k][i][j] = 0;

	//parse input. use read
	while (read(0, &c, 1) > 0)
	{
		if (c == 'w' && y > 1)
			y--;
		else if (c == 's' && y < height)
			y++;
		else if (c == 'a' && x > 1)
			x--;
		else if (c == 'd' && x < width)
			x++;
		else if (c == 'x')
			pen = !pen;
		if (pen)
			grid[0][y][x] = 1;
	}
	//game of life simulation
	for (int it = 0; it < iterations; it++)
	{
		int cur = it % 2;
		int next = (it + 1) % 2;
		for (int i = 1; i <= height; i++)
		{
			for (int j = 1; j <= width; j++)
			{
				int n = 0;
				for (int dy = -1; dy <= 1; dy++)
					for (int dx = -1; dx <= 1; dx++)
						if (dy != 0 || dx != 0)
							n += grid[cur][i + dy][j + dx];
				if (grid[cur][i][j] == 1)
					grid[next][i][j] = (n == 2 || n == 3);
				else
					grid[next][i][j] = (n == 3);
			}
		}
	}
	//print result
	int final = iterations % 2;
	for(int i = 1; i <= height; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			if (grid[final][i][j])
				putchar('O');
			else
				putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}