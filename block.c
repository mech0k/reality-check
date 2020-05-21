#include "block.h"
#include <stdio.h>

void clear_area(){
    rectangle clear = {0,GRID_WIDTH*BLOCK_SIZE,0,GRID_HEIGHT*BLOCK_SIZE};
    fill_rectangle(clear,BLACK);
}

void display_block(uint16_t x, uint16_t y, uint16_t color){
    rectangle shape = {x,x+BLOCK_SIZE-1,y,y+BLOCK_SIZE-1};
    fill_rectangle(shape,color);
}

void display_part(uint16_t x, uint16_t y, uint16_t arr[BLOCK_SIZE][BLOCK_SIZE]){
    for(uint16_t i = y; i < y+BLOCK_SIZE; i++){
        for(uint16_t j = x; j < x+BLOCK_SIZE; j++){
            rectangle r = {j,j,i,i};
            fill_rectangle(r,arr[i-y][j-x]);
        }
    }
}

void draw_block(block p){
    display_block(p.x*BLOCK_SIZE, p.y*BLOCK_SIZE, p.type);
}
 
void clear_block(block p){
    display_block(p.x*BLOCK_SIZE, p.y*BLOCK_SIZE, b);
}
