#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	//check parsing
	if (ac != 4)
		return 1;
	//take info
	int		width = atoi(av[1]);
	int		height = atoi(av[2]);
	int		iterations = atoi(av[3]);
	char	c;
	int		pen = 0;
	int		grid[2][height + 2][width + 2];

	//memory alloc
	for(int k = 0; k < 2; k++)
		for (int i = 0; i < height + 2; i++)
			for (int j = 0; j < width + 2; j++)
				grid[k][i][j] = 0;
	//read
	int x = 1, y = 1;
	while (read(0, &c, 1) > 0)
	{
		if (c == 'w' && y > 1)
			y--;
		if (c == 's' && y < height)
			y++;
		if (c == 'a' && x > 1)
			x--;
		if (c == 'd' && x < width)
			x++;
		if (c == 'x')
			pen = !pen;
		if (pen)
			grid[0][y][x] = 1; 
	}
	//Game of Life simulation. iterate 2 maps
	for (int it = 0; it < iterations; it++)
	{
		int curr = it % 2;
		int next = (it + 1) % 2;
		//iterate the map. and check surrounding take n
		for(int i = 1; i <= height; i++)
		{
			for (int j = 1; j <= width; j++)
			{
				int n = 0;
				for (int dy = -1; dy <= 1; dy++)
					for (int dx = -1; dx <= 1; dx++)
						if (dy != 0 || dx != 0)
							n += grid[curr][i + dy][j + dx];
				//count the n to make next map. GOL simulation
				if (grid[curr][i][j])
					grid[next][i][j] = (n == 2 || n == 3);
				else
					grid[next][i][j] = (n == 3);
			}
		}
	}
	//print the final map
	int final = iterations % 2;
	{
		for (int i = 1; i <= height; i++)
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
	}
	return 0;
}