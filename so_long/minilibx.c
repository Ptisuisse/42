#include "../MacroLibX/includes/mlx.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	init_map(t_map *mapping);

int main(void)
{
    t_map *mapping;

    mapping = malloc(sizeof(t_map));
    if (mapping == NULL)
        return 0;
    init_map(mapping);
    void* mlx = mlx_init();
    void* win = mlx_new_window(mlx, 1000, 500, "Hello world!");

    int img_width;
    int img_height;
    void* img ;
    mapping->y_P = 0;
    mapping->x_P = 0;
    while(mapping->tmp_map[mapping->y_P])
    {
        mapping->x_P = 0;
        while (mapping->map[mapping->y_P][mapping->x_P])
        {
            if(mapping->map[mapping->y_P][mapping->x_P] == '1')
            {
                img = mlx_png_file_to_image(mlx, "/nfs/homes/lvan-slu/Documents/42_git/so_long/bg_cloud7.png", &img_width, &img_height);
                mlx_put_image_to_window(mlx, win, img, (mapping->x_P * 64),(mapping->y_P * 64)); // displays the image at x,y = 42,4
            }
            // if(mapping->map[mapping->y_P][mapping->x_P] == '0')
            // {
            //     img = mlx_png_file_to_image(mlx, "/nfs/homes/lvan-slu/Documents/42_git/so_long/test.png", &img_width, &img_height);
            //     mlx_put_image_to_window(mlx, win, img, (mapping->x_P * 32),(mapping->y_P * 32)); // displays the image at x,y = 42,4
            // }
            if(mapping->map[mapping->y_P][mapping->x_P] == 'P')
            {
                img = mlx_png_file_to_image(mlx, "/nfs/homes/lvan-slu/Documents/42_git/so_long/aviator.png", &img_width, &img_height);
                mlx_put_image_to_window(mlx, win, img, (mapping->x_P * 64),(mapping->y_P * 64)); // displays the image at x,y = 42,4   
            }
            // if(mapping->map[mapping->y_P][mapping->x_P] == 'C')
            // {
            //     img = mlx_png_file_to_image(mlx, "/nfs/homes/lvan-slu/Documents/42_git/so_long/spr_m_aviator1", &img_width, &img_height);
            //     mlx_put_image_to_window(mlx, win, img, (mapping->x_P * 32),(mapping->y_P * 32)); // displays the image at x,y = 42,4   
            // }
            // if(mapping->map[mapping->y_P][mapping->x_P] == 'E')
            // {
            //     img = mlx_png_file_to_image(mlx, "/nfs/homes/lvan-slu/Documents/42_git/so_long/spr_m_aviator1", &img_width, &img_height);
            //     mlx_put_image_to_window(mlx, win, img, (mapping->x_P * 32),(mapping->y_P * 32)); // displays the image at x,y = 42,4   
            // }
            mapping->x_P++;
        }
        mapping->y_P++;
    }

    mlx_loop(mlx);

    // do not forget to destroy the image, otherwise the MacroLibX will yell at you !
    mlx_destroy_image(mlx, img);
    mlx_destroy_window(mlx, win);
    mlx_destroy_display(mlx);
}
