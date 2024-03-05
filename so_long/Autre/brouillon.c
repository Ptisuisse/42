
https://reactive.so/mappingt/42-a-comprehensive-guide-to-so_long

https://www.freecodecamp.org/news/flood-fill-algorithm-explained-with-examples/

floodfill



		printf("ERROR %d :\nAt [%d, %d] [ASCII]%d is not available\n", (mapping->nbr_err += 1), x, y, mapping->map[y][x]);
				printf("ERROR %d :\nMAP NOT CLOSE at [%d, %d]\n", (mapping->nbr_err += 1), x, y);

	y = 1;
	while (y < count_line - 1)
	{
		x = 0;
		while (mapping->map[y][x])
		{
			if (mapping->map[y][x] == 'P')
				mapping->p++;
			if (mapping->map[y][x] == 'C')
				mapping->c++;
			if (mapping->map[y][x] == 'E')
				mapping->e++;
			if (mapping->map[y][x] != 'P' && mapping->map[y][x] != 'C' && mapping->map[y][x] != 'E' && mapping->map[y][x] != '1' && mapping->map[y][x] != '0')
				return (printf("%d is not available", map[y][x]));
			x++;
		}
		y++;
	}
	if ((mapping->e != 1) || (mapping->c < 1) || (mapping->p != 1))
	 	return printf("ERROR1\n");
}