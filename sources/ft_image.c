#include "../includes/fdf"

int create_image(t_image *image)
{
    if (!(image->ptr = mlx_new_image(args.mlx_ptr, args.win_x, args.win_y))
        return (-1);
    if (!(image->img = mlx_get_data_addr(image->ptr,
        &(image->bpp), &(image->size_line), &(image->endian))))
        return (-1);
    return (0);
}

int create_window(t_args *args)
{
    args.mlx_ptr = mlx_init();
    if (!(args.win_ptr = mlx_new_window(args.mlx_ptr, 
        args.win_x, args.win_y, "mlx 42")))
        return (-1);
    return (0);
}