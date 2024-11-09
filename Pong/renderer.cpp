

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

void draw_rect_temp(int x0, int y0, int x1, int y1, unsigned int color) //original draw_rect, but 0,0 is bottom left of screen
{
	for (int y = y0; y < y1; y++)
	{
		unsigned int* pixel = (unsigned int*)render.memory +x0 + y * render.width;
		for (int x = x0; x < x1; x++)
			*pixel++ = color;
	}
}

void draw_rect(int x0, int y0, float width, float height, unsigned int color) //where 0,0 would be the middle of the screen
{
	//could add checks to make sure rectangle is inside bounds, but will do later
	x0 = (x0 + render.width / 2);
	int xleft = x0 - (render.width)*width/2;
	int xright = x0 + (render.width) * width / 2;
	
	y0 = (y0 + render.height / 2);
	int yleft = y0 - (render.height) * height / 2;
	int yright = y0 + (render.height) * height / 2;
	
	for (int y = yleft; y < yright; y++)
	{
		unsigned int* pixel = (unsigned int*)render.memory + xleft+ y * render.width;
		for (int x = xleft; x < xright; x++)
			*pixel++ = color;
	}
}
