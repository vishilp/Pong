#include "utilities.cpp"
#include <windows.h>


bool game_running = true;

struct Render_state
{
	int height, width;
	void* memory;
	BITMAPINFO buffer_bitmap_info; //bitmap of pixels
};

Render_state render;

#include "renderer.cpp"

LRESULT CALLBACK Window_callback(HWND unnamedParam1,UINT unnamedParam2,WPARAM unnamedParam3,LPARAM unnamedParam4) //callback function to process windows' messages
{
	LRESULT result = 0;
	switch (unnamedParam2)
	{
		case WM_CLOSE:
		case WM_DESTROY:
		{
			game_running = false;
		}
		break;
		case WM_SIZE:
		{
			RECT rect;
			GetClientRect(unnamedParam1, &rect);
			render.width = rect.right - rect.left;
			render.height = rect.bottom - rect.top;

			//buffer size is number of pixels *size of pixel
			int size = render.height * render.width * sizeof(unsigned int);
			if (render.memory)
			{
				VirtualFree(render.memory, 0, MEM_RELEASE);
			}
			render.memory = VirtualAlloc(0, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE); //like malloc

			render.buffer_bitmap_info.bmiHeader.biSize = sizeof(render.buffer_bitmap_info.bmiHeader);
			render.buffer_bitmap_info.bmiHeader.biWidth = render.width;
			render.buffer_bitmap_info.bmiHeader.biHeight = render.height;
			render.buffer_bitmap_info.bmiHeader.biPlanes = 1;
			render.buffer_bitmap_info.bmiHeader.biBitCount = 32;
			render.buffer_bitmap_info.bmiHeader.biCompression = BI_RGB;

		}break;
		default:
		{
			result = DefWindowProc(unnamedParam1, unnamedParam2, unnamedParam3, unnamedParam4);
		}

	}
	return result;
}

//to create Window, create window class, register class, and then create window

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) //entry point for windows applications rather than console
{
	// Creating the window class
	WNDCLASS window_class = {};
	window_class.style = CS_HREDRAW | CS_VREDRAW; //redraws window if size is changed
	window_class.lpszClassName = L"Game Window";
	window_class.lpfnWndProc = Window_callback; //windowproc


	//Register Class
	RegisterClass(&window_class);

	HWND window= CreateWindow(window_class.lpszClassName, L"Pong Game", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, 0, 0, hInstance, 0);
	HDC hdc = GetDC(window);


	while (game_running)
	{

		//handle the input from the window
		MSG message;
		while (PeekMessage(&message, window, 0 ,0, PM_REMOVE)) { //Peekmessage checks for any messages and copies the data into the MSG struct
			TranslateMessage(&message);
			DispatchMessage(&message); //basically calls our callback function
		}

		//simulate the game
		background_render();
		clear_screen(0xff5500);
		draw_rect(50, 50, 200, 500, 0x00ff22);
		//render the bitmap onto the window
		StretchDIBits(hdc, 0, 0, render.width, render.height, 0, 0, render.width, render.height, render.memory, &render.buffer_bitmap_info, DIB_RGB_COLORS, SRCCOPY);

	}
}