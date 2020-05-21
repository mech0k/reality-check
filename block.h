#include "lcd.h"
#include "color.h"

#define BLOCK_SIZE 16
#define GRID_HEIGHT (LCDWIDTH / BLOCK_SIZE)
#define GRID_WIDTH (LCDHEIGHT / BLOCK_SIZE)

typedef enum {
    p = GREEN,
    w = RED_1,
    b = BLACK,
    mv = ORANGE_1,
    inf = BURLYWOOD_1,
    res = ROSY_BROWN_2,
    tel = CYAN_2
} block_type;

typedef struct{
    block_type type;
    int8_t x;
    int8_t y;
} block;

void display_block(uint16_t x, uint16_t y, uint16_t color);
void display_part(uint16_t x, uint16_t y, uint16_t arr[BLOCK_SIZE][BLOCK_SIZE]);

void draw_block(block b);
void clear_block(block b);

void clear_area();
