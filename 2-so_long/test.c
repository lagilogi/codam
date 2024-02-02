#include <stdio.h>
#include <stdlib.h>

typedef struct s_array {
	char **grid;
	int	w_count;
} t_array;

void	recursive(t_array *array, int x, int y)
{
	if (array->grid[y][x] == '-')
	{
		// array->w_count++;
		return;
	}
	if (array->grid[y][x] == '1')
		return;
	else
	{
		array->w_count++;
		array->grid[y][x] = '-';
	}
	recursive(array, x, y+1);
	recursive(array, x, y-1);
	recursive(array, x+1, y);
	recursive(array, x-1, y);
}

void	print_array(t_array *array)
{
	int	x = 0;
	int	y = 0;
	int	max = 7;
	while (y < max)
	{
		while (x < max)
		{
			printf("%c", array->grid[y][x]);
			x++;
		}
		x = 0;
		y++;
		printf("\n");
	}
}

void	array_maker(t_array *array)
{
	int	x = 0;
	int	y = 0;
	int	max = 7;
	array->grid = malloc(max * sizeof(char *));
	while (y < max)
	{
		array->grid[y] = malloc(max * sizeof(char));
		y++;
	}
	y = 0;
	while (y < max)
	{
		while (x < max)
		{
			if (y == 0 || y == max-1)
				array->grid[y][x] = '1';
			else if (x == 0 || x == max-1 || x == 4)
				array->grid[y][x] = '1';
			else
				array->grid[y][x] = '0';
			x++;
		}
		x = 0;
		y++;
	}
}

int main()
{
	t_array array;
	array.w_count = 0;

	array_maker(&array);
	print_array(&array);
	recursive(&array, 2, 2);

	printf("\n\nNew array:\n");
	print_array(&array);
	printf("\nAmount of W's: %d", array.w_count);

	return 0;
}