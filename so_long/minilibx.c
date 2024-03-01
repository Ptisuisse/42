#include "MacroLibX/includes/mlx.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void    count(int fd);

int main(void)
{
    void* mlx = mlx_init();
    void* win = mlx_new_window(mlx, 400, 400, "Hello world!");

    int img_width;
    int img_height;
    void* img = mlx_png_file_to_image(mlx, "/nfs/homes/lvan-slu/Documents/42_git/so_long/MacroLibX/res/logo.png", &img_width, &img_height);

    mlx_put_image_to_window(mlx, win, img, 0, 0); // displays the image at x,y = 42,42
    void* img2 = mlx_png_file_to_image(mlx, "/nfs/homes/lvan-slu/Documents/42_git/so_long/MacroLibX/res/logo.png", &img_width, &img_height);

    mlx_put_image_to_window(mlx, win, img2, 50, 50); // displays the image at x,y = 42,42

    mlx_loop(mlx);
    int fd;
    fd = open("map.ber", O_RDONLY);
    count(fd);
    close(fd);

    // do not forget to destroy the image, otherwise the MacroLibX will yell at you !
    mlx_destroy_image(mlx, img);
    mlx_destroy_window(mlx, win);
    mlx_destroy_display(mlx);
}
