void background_render()
{
	unsigned int* pixel = (unsigned int*)render.memory;
	for (int y = 0; y < render.height; y++)
		for (int x = 0; x < render.width; x++)
			*pixel++ = y * x;
}

void clear_screen(unsigned int color)
{
	unsigned int* pixel = (unsigned int*)render.memory;
	for (int y = 0; y < render.height; y++)
		for (int x = 0; x < render.width; x++)
			*pixel++ = color;
}

void draw_rect(int x0, int y0, int x1, int y1, unsigned int color) //where 0,0 would be the middle of the screen
{
	for (int y = y0; y < y1; y++)
	{
		unsigned int* pixel = (unsigned int*)render.memory +x0 + y * render.width;
		for (int x = x0; x < x1; x++)
			*pixel++ = color;
	}
}
