#include "../includes/cub3d.h"
#include <stdint.h>

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

