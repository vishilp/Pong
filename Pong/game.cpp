void simulate_game(Input* input)
{
	clear_screen(0xff5500);
	if (input->keyboard[BUTTON_UP].pressed== true)
		draw_rect_temp(0, 0, 100, 100, 0x00ff22);
	draw_rect(300, 100, 0.2, 0.2, 0x00ff22);
}