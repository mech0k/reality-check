#include "level.h"

void redraw(level * l){
    for(uint16_t i = 0; i < GRID_HEIGHT; i++){
        for(uint16_t j = 0; j < GRID_WIDTH; j++){
            if(l->grid[i][j] == w) {
                l->wall.x = j;
                l->wall.y = i;
                draw_block(l->wall);
            }
            if(l->grid[i][j] == mv) {
                l->box.x = j;
                l->box.y = i;
                draw_block(l->box);
            }
            // info is the next level portal
            if(l->grid[i][j] == inf) {
                l->info.x = j;
                l->info.y = i;
                draw_block(l->info);
            }
            if(l->grid[i][j] == res) {
                l->res.x = j;
                l->res.y = i;
                draw_block(l->res);
            }
            if(l->grid[i][j] == tel) {
                l->tel.x = j;
                l->tel.y = i;
                draw_block(l->tel);
            }
        }
    }
}

void display_lvl_msg(level * l, uint8_t lvl){
    if(!l->displayed_msg){
        switch(lvl){
            case 0:
                display_string_xy("Level 0", 16,160);
                display_string_xy("You are trapped in a multidimensional world!", 16,170);
                display_string_xy("Try escaping by going through the bright portal!", 16,180);
                display_string_xy("Instructions:", 16,200);
                display_string_xy("Use arrows to move, center button to restart.", 16,210);
                break;
            case 1:
                display_string_xy("Level 1", 16,160);
                display_string_xy("You just moved through a dimension!", 16,170);
                display_string_xy("Instructions:", 16,190);
                display_string_xy("You can push the orange boxes around.", 16,200);
                display_string_xy("The portal doesn't like boxes!", 16,210);
                break;
            case 2:
                display_string_xy("Level 2", 16,160);
                display_string_xy("Same place but different reality!", 16,170);
                display_string_xy("Instructions:", 16,190);
                display_string_xy("Blue blocks are teleports, get a feel for them!", 16,200);
                display_string_xy("If a teleport block is blocked xD, it doesn't work!", 16,210);
                break;
            case 3:
                display_string_xy("Level 3", 16,160);
                display_string_xy("There seems to be no escape from here.", 16,170);
                display_string_xy("Instructions:", 16,190);
                display_string_xy("Purple blocks kill. Avoid them.", 16,200);
                display_string_xy("You can always erase them with an orange block!", 16,210);
                break;
            case 4:
                display_string_xy("Level 4", 16,160);
                display_string_xy("Progress, this seems to be a different room!", 16,170);
                display_string_xy("You moved through space in all the dimensions.", 16,180);
                break;
            case 5:
                display_string_xy("Level 5", 16,160);
                display_string_xy("What a mess!", 16,170);
                display_string_xy("Instructions:", 16,190);
                display_string_xy("Don't be a daltonist.", 16,200);
                break;
            case 6:
                display_string_xy("Level 6", 16,160);
                display_string_xy("Your consciousness is split between two dimensions.", 16,170);
                display_string_xy("Stay sane! You have a rational mind after all.", 16,180);
                display_string_xy("Instructions:", 16,200);
                display_string_xy("Go through the portals at the same time.", 16,210);
                break;
            case 7:
                display_string_xy("Level 7", 16,160);
                display_string_xy("Another iteration.", 16,170);
                display_string_xy("Your mind might be be split between", 16,180);
                display_string_xy("two realities forever.", 16,190);
                break;
            case 8:
                display_string_xy("Level 8", 16,160);
                display_string_xy("Impossible movement.", 16,170);
                display_string_xy("Instructions:", 16,190);
                display_string_xy("Trust me it's possible, just very hard.", 16,200);
                break;
            case 9:
                display_string_xy("Level 9", 16,160);
                display_string_xy("ImpossibleR movement.", 16,170);
                display_string_xy("Instructions:", 16,190);
                display_string_xy("Trust me again, it's way possibleR.", 16,200);
                break;
            case 10:
                display_string_xy("Level 10", 128,160);
                break;
        }
        l->displayed_msg = 1;
    }
}

void cabin_form(level * l, uint8_t y, uint8_t x){
    uint8_t i;
    for(i = 1; i < 8; i++){
        l->grid[i+y][0+x] = w;
        l->grid[i+y][6+x] = w;
    }
    for(i = 0; i < 7; i++){
        l->grid[1+y][i+x] = w;
        l->grid[7+y][i+x] = w;
    }
}

void load_level(level * l, uint8_t lvl){
    uint8_t i;
    l->wall.type = w;
    l->box.type = mv;
    l->info.type = inf;
    l->res.type = res;
    l->tel.type = tel;
    clear_g(l->grid); 
    switch(lvl){
        case 0:
            l->num_players = 1;
            l->players[0].type = p;
            l->players[0].x = 3;
            l->players[0].y = 6;
            l->old_players[0].type = p;
            l->old_players[0].x = 3;
            l->old_players[0].y = 6;

            cabin_form(l, 1, 1);
            l->grid[1][3] = w;
            l->grid[1][4] = w;
            l->grid[1][5] = w;
            l->grid[2][4] = inf;
            break;
        case 1:
            l->num_players = 1;
            l->players[0].type = p;
            l->players[0].x = 3;
            l->players[0].y = 6;
            l->old_players[0].type = p;
            l->old_players[0].x = 3;
            l->old_players[0].y = 6;

            cabin_form(l, 1, 1);
            l->grid[1][3] = w;
            l->grid[1][4] = w;
            l->grid[1][5] = w;
            l->grid[2][4] = inf;

            l->grid[3][4] = mv;
            l->grid[5][5] = mv;
            break;
        case 2:
            l->num_players = 1;
            
            l->players[0].type = p;
            l->players[0].x = 4;
            l->players[0].y = 7;
            l->old_players[0].type = p;
            l->old_players[0].x = 4;
            l->old_players[0].y = 7;

            cabin_form(l, 1, 1);
            l->grid[1][3] = w;
            l->grid[1][4] = w;
            l->grid[1][5] = w;
            l->grid[2][4] = inf;

            l->grid[4][2] = w;
            l->grid[4][3] = w;
            l->grid[4][4] = w;
            l->grid[4][5] = tel;
            l->grid[4][6] = w;

            l->grid[6][5] = mv;
            l->grid[6][2] = tel;
            break;
        case 3:
            l->num_players = 1;
            
            l->players[0].type = p;
            l->players[0].x = 4;
            l->players[0].y = 7;
            l->old_players[0].type = p;
            l->old_players[0].x = 4;
            l->old_players[0].y = 7;

            cabin_form(l, 1, 1);
            l->grid[1][3] = w;
            l->grid[1][4] = w;
            l->grid[1][5] = w;
            l->grid[2][4] = inf;
            l->grid[3][4] = res;

            l->grid[6][3] = mv;
            break;
        case 4:
            l->num_players = 1;
            
            l->players[0].type = p;
            l->players[0].x = 3;
            l->players[0].y = 7;
            l->old_players[0].type = p;
            l->old_players[0].x = 3;
            l->old_players[0].y = 7;

            uint8_t i;
            l->grid[1][4] = w;
            l->grid[1][5] = w;
            l->grid[1][6] = w;
            for(i = 2; i < 9; i++){
                l->grid[i][1] = w;
                l->grid[i][9] = w;
            }
            for(i = 1; i < 10; i++){
                l->grid[2][i] = w;
                l->grid[8][i] = w;
            }

            l->grid[2][5] = inf;
            l->grid[3][5] = res;
            l->grid[5][2] = w;
            l->grid[5][3] = tel;
            l->grid[5][4] = w;
            l->grid[5][5] = w;
            l->grid[5][6] = w;
            l->grid[5][8] = w;
            l->grid[7][7] = w;
            l->grid[6][6] = mv;
            break;
        case 5:
            l->num_players = 1;
            
            l->players[0].type = p;
            l->players[0].x = 2;
            l->players[0].y = 2;
            l->old_players[0].type = p;
            l->old_players[0].x = 2;
            l->old_players[0].y = 2;

            cabin_form(l, 0, 1);

            l->grid[4][4] = inf;
            l->grid[3][4] = res;
            l->grid[4][5] = res;
            l->grid[3][5] = tel;
            l->grid[4][3] = tel;
            l->grid[4][2] = w;
            l->grid[5][3] = mv;
            l->grid[5][4] = mv;
            l->grid[5][5] = mv;
            break;
        case 6:
            l->num_players = 2;
            
            l->players[0].type = p;
            l->players[0].x = 3;
            l->players[0].y = 6;
            l->old_players[0].type = p;
            l->old_players[0].x = 3;
            l->old_players[0].y = 6;

            l->players[1].type = p;
            l->players[1].x = 13;
            l->players[1].y = 6;
            l->old_players[1].type = p;
            l->old_players[1].x = 13;
            l->old_players[1].y = 6;

            cabin_form(l, 1, 1);
            l->grid[1][3] = w;
            l->grid[1][4] = w;
            l->grid[1][5] = w;
            l->grid[2][4] = inf;

            l->grid[3][4] = mv;

            cabin_form(l, 1, 9);
            l->grid[1][11] = w;
            l->grid[1][12] = w;
            l->grid[1][13] = w;
            l->grid[2][12] = inf;
            break;
        case 7:
            l->num_players = 2;
            
            l->players[0].type = p;
            l->players[0].x = 4;
            l->players[0].y = 5;
            l->old_players[0].type = p;
            l->old_players[0].x = 4;
            l->old_players[0].y = 5;

            l->players[1].type = p;
            l->players[1].x = 12;
            l->players[1].y = 5;
            l->old_players[1].type = p;
            l->old_players[1].x = 12;
            l->old_players[1].y = 5;

            cabin_form(l, 1, 2);
            l->grid[4][1]= w;
            l->grid[5][1]= w;
            l->grid[6][1]= w;
            l->grid[5][2] = inf;

            l->grid[4][13] = tel;

            cabin_form(l, 1, 10);
            l->grid[1][12] = w;
            l->grid[1][13] = w;
            l->grid[1][14] = w;
            l->grid[2][13] = inf;
            break;
        case 8:
            l->num_players = 2;
            
            l->players[0].type = p;
            l->players[0].x = 4;
            l->players[0].y = 6;
            l->old_players[0].type = p;
            l->old_players[0].x = 4;
            l->old_players[0].y = 6;

            l->players[1].type = p;
            l->players[1].x = 12;
            l->players[1].y = 6;
            l->old_players[1].type = p;
            l->old_players[1].x = 12;
            l->old_players[1].y = 6;

            cabin_form(l, 1, 2);
            l->grid[4][1]= w;
            l->grid[5][1]= w;
            l->grid[6][1]= w;
            l->grid[5][2] = inf;
            l->grid[5][3] = res;

            l->grid[4][6] = mv;

            l->grid[5][13] = tel;

            cabin_form(l, 1, 10);
            l->grid[1][12] = w;
            l->grid[1][13] = w;
            l->grid[1][14] = w;
            l->grid[2][13] = inf;
            l->grid[3][13] = res;
            l->grid[6][14] = mv;
            break;
        case 9:
            l->num_players = 2;
            
            l->players[0].type = p;
            l->players[0].x = 3;
            l->players[0].y = 7;
            l->old_players[0].type = p;
            l->old_players[0].x = 3;
            l->old_players[0].y = 7;

            // uint8_t i;
            l->grid[1][4] = w;
            l->grid[1][5] = w;
            l->grid[1][6] = w;
            for(i = 2; i < 9; i++){
                l->grid[i][1] = w;
                l->grid[i][9] = w;
            }
            for(i = 1; i < 10; i++){
                l->grid[2][i] = w;
                l->grid[8][i] = w;
            }

            l->grid[2][5] = inf;
            l->grid[3][5] = res;
            l->grid[5][2] = w;
            l->grid[5][3] = tel;
            l->grid[5][4] = w;
            l->grid[5][5] = w;
            l->grid[5][6] = w;
            l->grid[5][8] = w;
            l->grid[7][7] = w;
            l->grid[6][6] = mv;

            // 2
            l->players[1].type = p;
            l->players[1].x = 12;
            l->players[1].y = 3;
            l->old_players[1].type = p;
            l->old_players[1].x = 12;
            l->old_players[1].y = 3;

            cabin_form(l, 1, 11);

            l->grid[5][14] = inf;
            l->grid[4][14] = res;
            l->grid[5][15] = res;
            l->grid[4][15] = tel;
            l->grid[5][13] = tel;
            l->grid[5][12] = w;
            l->grid[6][13] = mv;
            l->grid[6][14] = mv;
            l->grid[6][15] = mv;
            break;
        case 10:
            l->num_players = 3;

            // 1
            l->players[0].type = p;
            l->players[0].x = 3;
            l->players[0].y = 6;
            l->old_players[0].type = p;
            l->old_players[0].x = 3;
            l->old_players[0].y = 6;

            cabin_form(l, 1, 1);
            l->grid[1][3] = w;
            l->grid[1][4] = w;
            l->grid[1][5] = w;
            l->grid[2][4] = inf;

            // 2
            l->players[1].type = p;
            l->players[1].x = 13;
            l->players[1].y = 6;
            l->old_players[1].type = p;
            l->old_players[1].x = 13;
            l->old_players[1].y = 6;

            cabin_form(l, 1, 11);
            l->grid[1][13] = w;
            l->grid[1][14] = w;
            l->grid[1][15] = w;
            l->grid[2][14] = inf;

            // 3
            l->players[2].type = p;
            l->players[2].x = 3;
            l->players[2].y = 12;
            l->old_players[2].type = p;
            l->old_players[2].x = 3;
            l->old_players[2].y = 12;
            
            l->grid[11][18] = w;
            l->grid[12][18] = w;
            l->grid[13][18] = w;
            for(i = 10; i < 15; i++){
                l->grid[i][1] = w;
                l->grid[i][17] = w;
            }
            for(i = 1; i < 17; i++){
                if(i >= 7 && i <= 11){
                    l->grid[11][i] = w;
                }else{
                    l->grid[10][i] = w;
                }
                l->grid[14][i] = w;
            }
            l->grid[14][1] = 0;
            l->grid[14][2] = 0;
            l->grid[14][17] = 0;
            l->grid[14][16] = 0;
            l->grid[13][2] = w;
            l->grid[13][16] = w;
            l->grid[12][17] = inf;
            break;
    }
}

void clear_g(uint16_t g[GRID_HEIGHT][GRID_WIDTH]){
    uint8_t i, j;
    for(i = 0; i < GRID_HEIGHT; i++){
        for(j = 0; j < GRID_WIDTH; j++){
            g[i][j] = b;
        }
    }
}
