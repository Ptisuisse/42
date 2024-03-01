#include "MacroLibX/includes/mlx.h"

int main(void)
{
    void* mlx = mlx_init();
    void* win = mlx_new_window(mlx, 400, 400, "Hello world!");

    mlx_pixel_put(mlx, win, 10, 10, 0xFFFF0000); // draws a red pixel at x,y = 10,10

    mlx_loop(mlx);

    mlx_destroy_window(mlx, win);
    mlx_destroy_display(mlx);
}