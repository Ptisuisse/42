
// void    count_line(int fd)
// {
//     int line;
//     char   *str;

//     line = 0;
//     while((str = get_next_line(fd)) != NULL)
//     {
//         printf("%s", str);
//         line++;
//     }
//     printf("%d", line);
// }

// int    check_map(int fd)
// {
//     int x;
//     int y;
//     char    *str;

//     y = 0;
//     while((*str[x] = get_next_line(fd)) != NULL)
//     {
//         y++;
//         x = 0;
//         while(str[x] != '\n')
//         {
//             if ((y == 5) || (y == 1))
//             {
//                 while (str[x] == '1')
//                     x++;
//                 if (str[x] == '0')
//                     return (printf("ERROR\n"));
//                 break;
//             }
//             x++;
//         }
//         if ((str[0] != '1') || (str[x - 1] != '1'))
//             return (printf("ERROR\n"));
//         printf("%s", str);
//     }
//     return (1);
// }

liste : 
[]->[]->[]->[] 

void    create_tab(int fd)
{
    char    **map;
	char	*line;
    char    c;
    int j;

    j = 0;
    c = '\n';
    while(1)
    {
		map = ft_split(get_next_line(fd), c, j);
        if (map == NULL)
            break ;
        j++;
    }
    //check_map(map, i);
}

https://reactive.so/post/42-a-comprehensive-guide-to-so_long

floodfill