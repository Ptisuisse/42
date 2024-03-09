#include "../../MacroLibX/includes/mlx.h"
#include "so_long.h"

int keyhook(int key, void *mlx)
{
    if(key == 41)
        mlx_loop_end(mlx);
    return (0);
}

void    ft_move_up(t_map *mapping)
{
    return ;
}
void    ft_mlx_sprites(t_map *mapping)
{
    mapping->y = 0;
    while(mapping->tmp_map[mapping->y])
    {
        mapping->x = 0;
        while (mapping->map[mapping->y][mapping->x])
        {
            if(mapping->map[mapping->y][mapping->x] == '1')
            {
                mapping->img = mlx_png_file_to_image(mapping->mlx, "/nfs/homes/lvan-slu/Documents/42_git/so_long/sprites/bg_cloud7.png", &mapping->img_width, &mapping->img_height);
                mlx_put_image_to_window(mapping->mlx, mapping->win, mapping->img, (mapping->x * 64),(mapping->y * 64));
            }
            if(mapping->map[mapping->y][mapping->x] == 'P')
            {
                mapping->img = mlx_png_file_to_image(mapping->mlx, "/nfs/homes/lvan-slu/Documents/42_git/so_long/sprites/aviator.png", &mapping->img_width, &mapping->img_height);
                mlx_put_image_to_window(mapping->mlx, mapping->win, mapping->img, (mapping->x * 64),(mapping->y * 64));
            }
            mapping->x++;
        }
        mapping->y++;
    }
}

void    ft_sizeof_window(t_map *mapping)
{
    mapping->win_x = 0;
    mapping->win_y = 0;

    while (mapping->map[mapping->win_y])
    {
        mapping->win_x = 0;
        while (mapping->map[mapping->win_y][mapping->win_x])
            mapping->win_x++;
        mapping->win_y++;
    }
}

int mlx_event(void *mlx, void *win, mlx_event_type2 event, int (*f)(int, void*), t_map *mapping)
{
    event = 41;
    return 0;
}

int ft_mlx_init(t_map *mapping)
{
    mapping->mlx = mlx_init();
    ft_sizeof_window(mapping);
    mapping->win = mlx_new_window(mapping->mlx, (mapping->win_x * 64), (mapping->win_y * 64), "So_long");
    ft_mlx_sprites(mapping);
    mlx_event(mapping->mlx, mapping->win, MLX_KEYDOWN2, keyhook, mapping); 
    mlx_loop(mapping->mlx);
    mlx_destroy_image(mapping->mlx, mapping->img);
    mlx_destroy_window(mapping->mlx, mapping->win);
    mlx_destroy_display(mapping->mlx);
}
