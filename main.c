#include <gb/gb.h>
#include <gb/cgb.h>
#include <stdint.h>
#include "boy.h"

unsigned char gradient[] =
{
  0xE3,0x1F,0xE3,0x1F,0xE3,0x1F,0xE3,0x1F,
  0xE3,0x1F,0xE3,0x1F,0xE3,0x1F,0xE3,0x1F
};

#define RGB_COLOR1	RGB(16,  0,  0)
#define RGB_COLOR2	RGB( 23,  18, 5)
#define RGB_COLOR3	RGB(31,  28, 20)


UWORD spritePalette[] = {
  0, RGB_COLOR1, RGB_COLOR2, RGB_COLOR3
};

int player_x = 75;
int player_y = 75;

void process_input()
{
		uint8_t joydata = joypad(); // Read once per frame and cache the result

		if (joydata & J_RIGHT) // If RIGHT is pressed
		{
			player_x++;
		}
		
		if (joydata & J_LEFT)  // If LEFT is pressed
		{
			player_x--;
		}
		
		if (joydata & J_UP)  // If UP is pressed
		{ 
			player_y--;
		}
		
		if (joydata & J_DOWN)  // If DOWN is pressed
		{ 
			player_y++;
		}

}

void move_sprites()
{
	move_sprite(0, player_x, player_y);
	move_sprite(1, player_x + 8, player_y);
}

void main(void)
{
	SPRITES_8x16;
	set_sprite_data(0, 8, BoySprite);
	set_sprite_palette(0, 1, spritePalette);
	set_sprite_tile(0, 0);
	move_sprite(0, player_x, player_y);
	set_sprite_tile(1, 2);
	move_sprite(1, player_x + 8, player_y);
	SHOW_SPRITES;

	while(1){
		process_input();
		move_sprites();
		wait_vbl_done();
	}
}
