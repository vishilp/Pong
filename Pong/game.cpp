float player_yposition= 0.f;

void simulate_game(Input* input, int height, int width)
{
	
	background_render();
	if (input->keyboard[BUTTON_UP].pressed == true)
	{
		int topcap = height / 2 - (0.09 * height);
		if (player_yposition+0.9 < topcap) 
			player_yposition +=0.9;
	}
	if (input->keyboard[BUTTON_DOWN].pressed == true)
	{
		int bottomcap = height / 2 - (0.09 * height);
		if (player_yposition - 0.9 > -bottomcap)
			player_yposition -= 0.9;
	}
	draw_rect(width/2-50, player_yposition, 0.03, 0.17, 0xFFFFFF);//right rect
	draw_rect(-width/2 + 50, 0, 0.03, 0.17, 0xFFFFFF);//left rect
}