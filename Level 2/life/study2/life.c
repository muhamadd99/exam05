#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
	//input checking 
	if (ac != 4)
		return 1;
	//input parsing, memory allocation , read line
	int		width = atoi(av[1]);
	int		height = atoi(av[2]);
	int		iterations = atoi(av[3]);
	char	c;
	int		pen = 0;
	int		grid[2][height + 2][width + 2];

	for (int k = 0; k < 2; k++)
		for (int i = 0; i < height + 2; i++)
			for (int j = 0; j < width + 2; j++)
				grid[k][i][j] = 0;
	int x = 1, y = 1;
	while (read(0, &c , 1) > 0)
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
	//two iterator for current and next
	for (int it = 0; it < iterations; it++)
	{
		int curr = it % 2;
		int next = (it + 1) % 2;
		for (int i = 1; i <= height; i++)
		{
			for (int j = 1; j <= width; j++)
			{
				//iterate coordinate and check surrounding
				int n = 0;
				for (int dx = -1; dx <= 1; dx++)
				{
					for (int dy = -1; dy <= 1; dy++)
						if (dy != 0 || dx != 0)
							n += grid[curr][i + dy][j + dx];
				}
				//outside check surrounding loop, check for next GOL simulation. 
				if (grid[curr][i][j])
					grid[next][i][j] = (n == 2 || n == 3);
				else
					grid[next][i][j] = (n == 3);
			}
		}
	}
	//who is final print result
	int	final = iterations % 2;
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
