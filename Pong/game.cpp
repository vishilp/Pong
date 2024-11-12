int player_yposition= 100;

void simulate_game(Input* input)
{
	clear_screen(0xff5500);
	if (input->keyboard[BUTTON_UP].pressed == true)
	{
		player_yposition += 20;
		input->keyboard[BUTTON_UP].pressed = false;
	}
	draw_rect(300, player_yposition, 0.2, 0.2, 0x00ff22);
}