#include "../MLX42/include/MLX42/MLX42.h"
#include <_types/_uint32_t.h>
#include <string.h>
#include <stdio.h>

/** mlx_t *mlx; */
/** mlx_texture_t *wall; */

/** void resize_hook(int32_t width, int32_t height, void *param) */
/** { */
/**     (void)param; */
/**     mlx_image_t *image; */
/**  */
/**     image = param; */
/**     mlx_delete_image(mlx, image); */
/**     mlx_image_t *new_image = mlx_new_image(mlx, width, height); */
/**     memset(new_image->pixels, 128, new_image->width * new_image->height * sizeof(int)); */
/**  */
/**     mlx_image_to_window(mlx, new_image, 0, 0); */
/**  */
/** } */
#define IMG_SIZE 300
uint32_t to_le(uint32_t color)
{
	unsigned char bytes[4];
	uint32_t ret;

	bytes[0] = (unsigned char)((color >> 24) & 0xff);
	bytes[1] = (unsigned char)((color >> 16) & 0xff);
	bytes[2] = (unsigned char)((color >> 8) & 0xff);
	bytes[3] = (unsigned char)((color >> 0) & 0xff);

	ret = ((uint32_t)bytes[0] << 0) |
			((uint32_t)bytes[1] << 8) |
			((uint32_t)bytes[2] << 16) |
			((uint32_t)bytes[3] << 24);
	return (ret);
}

int main(void)
{
	mlx_t *mlx;
	mlx_texture_t *wall;
	mlx = mlx_init(1024, 1024, "test", true);
	mlx_image_t *image;
	/** uint32_t xy[2]; */
	/** uint32_t wh[2]; */
	/** xy[0] = 0; */
	/** xy[1] = 0; */
	/** wh[0] = 624; */
	/** wh[1] = 624; */
	image = mlx_new_image(mlx, IMG_SIZE, IMG_SIZE );
	/** memset(image->pixels, 255, image->width * image->height * sizeof(int)); */
	wall = mlx_load_png("./enemy2.png");
	/** mlx_draw_texture(image, wall, 0, 0); */
	/** mlx_image_to_window(mlx, image, 0, 0); */
	/** printf("%d\n", *(uint32_t *)(wall->pixels)); */
	/** uint8_t bpp = wall->bytes_per_pixel; */
	uint32_t width = wall->width;
	uint32_t height = wall->height;
    /**  */
	printf("%d %d\n", width, height);
	/** uint32_t color = *(uint32_t *)(wall->pixels); */
	/** printf("%x\n", to_le(color)); */


	for (int y = 0; y < IMG_SIZE; y++)
	{
		for (int x = 0; x < IMG_SIZE; x++)
		{
			int p_x = x / IMG_SIZE * width;
			int p_y = y / IMG_SIZE * height;
			uint32_t color = *((uint32_t *)wall->pixels + (p_y * height  + p_x));
			uint32_t new_color = to_le(color);
			/** if (new_color & 0xff == 0) */
			/**     continue; */
			mlx_put_pixel(image, x, y, new_color);
		}
	}
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
