#include "block.h"

typedef struct {
    volatile uint16_t grid[GRID_HEIGHT][GRID_WIDTH];
    block wall;
    block box;
    block info;
    block res;
    block tel;
    block players[3];
    block old_players[3];
    uint8_t displayed_msg;
    uint8_t num_players;
} level;

void load_level(level * l, uint8_t lvl);
void redraw(level * l);
void clear_g(uint16_t g[GRID_HEIGHT][GRID_WIDTH]);
void display_lvl_msg(level * l, uint8_t lvl);
void cabin_form(level * l, uint8_t x, uint8_t y);
