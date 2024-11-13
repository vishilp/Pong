float player_yposition= 100.f;

void simulate_game(Input* input, int height, int width)
{
	
	background_render();
	if (input->keyboard[BUTTON_UP].pressed == true)
	{
		if (player_yposition+0.9 < height-500) 
			player_yposition +=0.9;
	}
	if (input->keyboard[BUTTON_DOWN].pressed == true)
	{
		player_yposition -= 0.9;
	}
	draw_rect(width/2-50, player_yposition, 0.05, 0.2, 0xFFFFFF);//right rect
	draw_rect(-width/2 + 50, 0, 0.05, 0.2, 0xFFFFFF);//left rect
}