#include "mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
typedef struct  s_param
{
    void    *mlx_ptr;
    void    *win_ptr;
}               t_param;
void    print_p(void *mlx_ptr, void *win_ptr, int x, int y, int color, int size)
{
    int     size_y;
    int     size_x;
    int     x_temp;
    size_y = (size + y) * 2;
    size_x = size + x;
    while (y <= size_y/6)
    {
        x_temp = x;
        while (x_temp++ <= size_x)
            mlx_pixel_put(mlx_ptr, win_ptr, x_temp, y, color);
        y++;
    }
    while (y <= size_y/3 + size_y/8)
    {
        x_temp = x;
        while (x_temp++ <= size_x)
        {
            if (x_temp <= size_x/5 + size_x/10)
                mlx_pixel_put(mlx_ptr, win_ptr, x_temp, y, color);
            else if (x_temp >= (size_x/2 + size_x/4 + size_x/15))
                mlx_pixel_put(mlx_ptr, win_ptr, x_temp, y, color);
        }
        y++;
    }
    while (y <= size_y/2 + size_y/13)
    {
        x_temp = x;
        while (x_temp++ <= size_x)
            mlx_pixel_put(mlx_ptr, win_ptr, x_temp, y, color);
        y++;
    }
    while (y <= size_y)
    {
        x_temp = x;
        while (x_temp++ <= size_x/5 + size_x/10)
                mlx_pixel_put(mlx_ptr, win_ptr, x_temp, y, color);
        y++;
    }
}
void    map_color(void *mlx_ptr, void *win_ptr, int color)
{
    int     x;
    int     y;
    y = 0;
    while (y <= 1000)
    {
        x = 0;
        while (x <= 1000)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
            x++;
        }
        y++;
    }
}
int     deal_key(int key, t_param *param)
{
    static int  i = 1;
    //if (key == 35)
    //    print_p(param->mlx_ptr, param->win_ptr, 10, 10, 0xffffff, 100);
    if (key == 53)
    {
        mlx_destroy_window(param->mlx_ptr, param->win_ptr);
        free(param);
        param = NULL;
        exit(0);
    }
    else if (key == 51)
    {
        mlx_clear_window(param->mlx_ptr, param->win_ptr);
        i = 1;
    }
    else if (key == 0)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "a" );
    else if (key == 11)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "b" );
    else if (key == 8)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "c" );
    else if (key == 2)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "d" );
    else if (key == 14)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "e" );
    else if (key == 3)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "f" );
    else if (key == 5)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "g" );
    else if (key == 4)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "h" );
    else if (key == 34)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "i" );
    else if (key == 38)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "j" );
    else if (key == 40)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "k" );
    else if (key == 37)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "l" );
    else if (key == 46)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "m" );
    else if (key == 45)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "n" );
    else if (key == 31)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "o" );
    else if (key == 35)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "p" );
    else if (key == 12)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "q" );
    else if (key == 15)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "r" );
    else if (key == 1)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "s" );
    else if (key == 17)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "t" );
    else if (key == 32)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "u" );
    else if (key == 9)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "v" );
    else if (key == 13)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "w" );
    else if (key == 7)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "x" );
    else if (key == 16)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "y" );
    else if (key == 6)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "z" );
    else if (key == 49)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, " " );
    else if (key == 18)
        mlx_string_put (param->mlx_ptr, param->win_ptr, (i = i + 10), 1, 0xffffff, "!" );
    return (0);
}
int     deal_mouse(int mouse, int x, int y, t_param *param)
{
    void    *img;
//    char    *data;
//    int     bpp;
//    int     sizeline;
//    int     endian;
//    int     pixel_nbr;
//    pixel_nbr = 0;
    if (mouse == 1)
    {
        //if (!(img = mlx_new_image(param->mlx_ptr, 10, 10)))
        //        printf("new image failled !\n");
        //data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
        img = mlx_new_image(param->mlx_ptr, 10, 10);
        //data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
        //printf("%d, %d, %d\n", bpp, sizeline, endian);
        //while (pixel_nbr < 190000)
        //{
        //    data[pixel_nbr] = 100;
        //    pixel_nbr++;
        //}
        mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, img, x, y);
        //mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, img, x, y);
    }
    else if (mouse == 2)
        mlx_string_put (param->mlx_ptr, param->win_ptr, x, y, 0xffffff, "Click gauche" );
    else if (mouse == 4)
        mlx_string_put (param->mlx_ptr, param->win_ptr, x, y, 0xffffff, "ZOOM" );
    else if (mouse == 5)
        mlx_string_put (param->mlx_ptr, param->win_ptr, x, y, 0xffffff, "DEZOOM" );
    else if (mouse == 3)
        map_color(param->mlx_ptr, param->win_ptr, 255);
    return (0);
}
int     main(void)
{
    t_param *param;
    param = (t_param*)malloc(sizeof(t_param));
    if (!(param->mlx_ptr = mlx_init()))
        return (0);
    param->win_ptr = mlx_new_window(param->mlx_ptr, 1000, 1000, "test mlx");
    mlx_mouse_hook(param->win_ptr, deal_mouse, param);
    mlx_key_hook(param->win_ptr, deal_key, param);
    mlx_loop(param->mlx_ptr);
    return(0);
}