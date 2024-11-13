int player_yposition= 100;

void simulate_game(Input* input, int height)
{
	
	clear_screen(0xff5500);
	if (input->keyboard[BUTTON_UP].pressed == true)
	{
		player_yposition += 1;
	}
	if (input->keyboard[BUTTON_DOWN].pressed == true)
	{
		player_yposition -= 1;
	}
	draw_rect(300, player_yposition, 0.2, 0.2, 0x00ff22);
}