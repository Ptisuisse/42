
https://reactive.so/mappingt/42-a-comprehensive-guide-to-so_long

https://www.freecodecamp.org/news/flood-fill-algorithm-explained-with-examples/

floodfill

	41 == echap
    26 = w
    22 = s
    4 = a
    7 = d
     82 = up
    80 = left
    81 =down
    79 = right
    9 = f

    //if ((key == 26) || (key == 82))
    // if ((key == 22 || key == 81))
    //     ft_move_down();
    // if ((key == 4 || key == 80))
    //     ft_move_left();
    // if ((key == 7 || key == 79))
    //     ft_move_right();



	//ft_mlx_init(mapping);
	// free_map(mapping->map);
	// free_map(mapping->tmp_map);
	// free(mapping);

	            // if(mapping->map[mapping->y_P][mapping->x_P] == 'C')
            // {
            //     img = mlx_png_file_to_image(mlx, "/nfs/homes/lvan-slu/Documents/42_git/so_long/spr_m_aviator1", &img_width, &img_height);
            //     mlx_put_image_to_window(mlx, win, img, (mapping->x_P * 32),(mapping->y_P * 32));  
            // }
            // if(mapping->map[mapping->y_P][mapping->x_P] == 'E')
            // {
            //     img = mlx_png_file_to_image(mlx, "/nfs/homes/lvan-slu/Documents/42_git/so_long/spr_m_aviator1", &img_width, &img_height);
            //     mlx_put_image_to_window(mlx, win, img, (mapping->x_P * 32),(mapping->y_P * 32));
            // }

			            // if(mapping->map[mapping->y_P][mapping->x_P] == '0')
            // {
            //     img = mlx_png_file_to_image(mlx, "/nfs/homes/lvan-slu/Documents/42_git/so_long/test.png", &img_width, &img_height);
            //     mlx_put_image_to_window(mlx, win, img, (mapping->x_P * 32),(mapping->y_P * 32));
            // }

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