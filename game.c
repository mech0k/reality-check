#include "game.h"

volatile level l;
volatile uint8_t c_lvl = 0;
volatile uint8_t max_lvl = 11;

void redraw_p(){
    cli();
    for(uint8_t i = 0; i < l.num_players; i++){
        clear_block(l.old_players[i]);
    }
    redraw(&l);
    for(uint8_t i = 0; i < l.num_players; i++){
        draw_block(l.players[i]);
    }
    sei();
}

uint8_t check_col(uint8_t x, uint8_t y){
    if(l.grid[y][x] == w) return 1;
    return 0;
}

void spawn(){
    clear_area();
    if(c_lvl < max_lvl){
        load_level(&l, c_lvl); 
        display_lvl_msg(&l, c_lvl);
    }else{
        c_lvl = 0;
        load_level(&l, c_lvl); 
        display_title();
		while(!center_pressed()){}
        clear_area();
        display_lvl_msg(&l, c_lvl);
    }
}

void check_lvl(){
    for(uint16_t i = 0; i < GRID_HEIGHT; i++){
        for(uint16_t j = 0; j < GRID_WIDTH; j++){
            if(l.grid[i][j] == inf){
                uint8_t succ_f = 0;
                for(uint8_t z = 0; z < l.num_players; z++){
                    if(l.players[z].x == j && l.players[z].y == i){
                        succ_f = 1;
                    }
                }
                if(succ_f == 0) return;
            }
        }
    }
    l.displayed_msg = 0;
    c_lvl += 1;
    // exit screen condition
    // if(c_lvl > max_lvl) c_lvl = max_lvl;
    spawn();
}

void move_p(direction m){
    for(uint8_t i = 0; i < l.num_players; i++){
        l.old_players[i].x = l.players[i].x;
        l.old_players[i].y = l.players[i].y;
        
        int8_t x_i = 0;
        int8_t x_i_helper = 0;
        int8_t x_i_helper_2 = 0;
        int8_t y_i = 0;
        int8_t y_i_helper = 0;
        int8_t y_i_helper_2 = 0;
        int8_t x_dir = 0;
        int8_t y_dir = 0;
        switch(m){
            case Up:
                x_i = 0; x_i_helper = 0; y_i = -1; y_i_helper = -2; x_dir = 0; y_dir = -1;
                x_i_helper_2 = 0;
                y_i_helper_2 = -3;
                break;
            case Left:
                x_i = -1; x_i_helper = -2; y_i = 0; y_i_helper = 0; x_dir = -1; y_dir = 0;
                x_i_helper_2 = -3;
                y_i_helper_2 = 0;
                break;
            case Right:
                x_i = 1; x_i_helper = 2; y_i = 0; y_i_helper = 0; x_dir = 1; y_dir = 0;
                x_i_helper_2 = 3;
                y_i_helper_2 = 0;
                break;
            case Down:
                x_i = 0; x_i_helper = 0; y_i = 1; y_i_helper = 2; x_dir = 0; y_dir = 1;
                x_i_helper_2 = 0;
                y_i_helper_2 = 3;
                break;
        }

        // movement
        if(l.grid[l.players[i].y+y_i][l.players[i].x+x_i] == res) {
            restart_lvl();
            break;
        }
        if(l.grid[l.players[i].y+y_i][l.players[i].x+x_i] != w){
            if(l.grid[l.players[i].y+y_i][l.players[i].x+x_i] == mv && l.grid[l.players[i].y+y_i_helper][l.players[i].x+x_i_helper] != w && l.grid[l.players[i].y+y_i_helper][l.players[i].x+x_i_helper] != tel && l.grid[l.players[i].y+y_i_helper][l.players[i].x+x_i_helper] != mv ){
                if(l.grid[l.players[i].y+y_i_helper][l.players[i].x+x_i_helper] == inf){
                    restart_lvl();
                    break;
                }
                l.grid[l.players[i].y+y_i][l.players[i].x+x_i] = b;
                l.grid[l.players[i].y+y_i_helper][l.players[i].x+x_i_helper] = mv;
                l.players[i].x += x_i;
                l.players[i].y += y_i;
            }else if(l.grid[l.players[i].y+y_i][l.players[i].x+x_i] == mv && l.grid[l.players[i].y+y_i_helper][l.players[i].x+x_i_helper] == tel){
                if(l.grid[l.players[i].y+y_i_helper_2][l.players[i].x+x_i_helper_2] == inf){
                    restart_lvl();
                    break;
                }
                if(l.grid[l.players[i].y+y_i_helper_2][l.players[i].x+x_i_helper_2] != w && l.grid[l.players[i].y+y_i_helper_2][l.players[i].x+x_i_helper_2] != tel && l.grid[l.players[i].y+y_i_helper_2][l.players[i].x+x_i_helper_2] != mv){
                    l.grid[l.players[i].y+y_i][l.players[i].x+x_i] = b;
                    l.grid[l.players[i].y+y_i_helper_2][l.players[i].x+x_i_helper_2] = mv;
                    l.players[i].x += x_i;
                    l.players[i].y += y_i;
                }
            }else if(l.grid[l.players[i].y+y_i][l.players[i].x+x_i] != mv){
                if(l.grid[l.players[i].y+y_i][l.players[i].x+x_i] == tel && l.grid[l.players[i].y+y_i_helper][l.players[i].x+x_i_helper] == res){
                    restart_lvl();
                    break;
                }else if(l.grid[l.players[i].y+y_i][l.players[i].x+x_i] == tel && l.grid[l.players[i].y+y_i_helper][l.players[i].x+x_i_helper] != w && l.grid[l.players[i].y+y_i_helper][l.players[i].x+x_i_helper] != mv && l.grid[l.players[i].y+y_i_helper][l.players[i].x+x_i_helper] != tel){
                    // go through
                    l.players[i].x += x_i_helper;
                    l.players[i].y += y_i_helper;
                }else if(l.grid[l.players[i].y+y_i][l.players[i].x+x_i] != tel){
                    l.players[i].x += x_i;
                    l.players[i].y += y_i;
                }
            }
        }
    }

    check_lvl();
    redraw_p();
}

void restart_lvl(){
    l.displayed_msg = 0;
    spawn();
    redraw_p();
}

ISR(TIMER1_COMPA_vect)
{
	if(left_pressed()){
		move_p(Left);
	}
	if(right_pressed()){
		move_p(Right);
	}
	if(up_pressed()){
		move_p(Up);
	}
	if(down_pressed()){
		move_p(Down);
	}
    if(center_pressed()){
        restart_lvl();
    }
}

void display_title(){
    display_string_xy("______           _ _ _         ", 10, 10);
    display_string_xy("| ___ \\         | (_) |        ", 10, 20);
    display_string_xy("| |_/ /___  __ _| |_| |_ _   _ ", 10, 30);
    display_string_xy("|    // _ \\/ _` | | | __| | | |", 10, 40);
    display_string_xy("| |\\ \\  __/ (_| | | | |_| |_| |", 10, 50);
    display_string_xy("\\_| \\_\\___|\\__,_|_|_|\\__|\\__, |", 10, 60);
    display_string_xy("                          __/ |", 10, 70);
    display_string_xy("                         |___/ ", 10, 80);

    display_string_xy(" _____ _               _    ", 65, 90); 
    display_string_xy("/  __ \\ |             | |   ", 65, 100);
    display_string_xy("| /  \\/ |__   ___  ___| | __", 65, 110);
    display_string_xy("| |   | '_ \\ / _ \\/ __| |/ /", 65, 120);
    display_string_xy("| \\__/\\ | | |  __/ (__|   < ", 65, 130);
    display_string_xy(" \\____/_| |_|\\___|\\___|_|\\_\\", 65, 140); 

    display_string_xy("Press Center to Start", 25, 170);
}

int main()
{
	CLKPR = (1 << CLKPCE);
	CLKPR = 0;
	init_lcd();
	init_switches();
	set_frame_rate_hz(61);
	// set_orientation();
	
	DDRB |= _BV(PB7);
	PORTB &= ~_BV(PB7);

	/* enable button press interrupt */
	TCCR1A = 0;
	TCCR1B = _BV(WGM12);
	TCCR1B |= _BV(CS10);
	TIMSK1 |= _BV(OCIE1A);

	OCR3A = 0;

    display_title();	

    LED_ON;
	do{
		while(!center_pressed()){}
		rectangle background = {0,display.width,0,display.height};
        display.background = BLACK;
		display.foreground = WHITE;
		fill_rectangle(background,display.background);

        clear_area();
        spawn();
        redraw_p();

        LED_OFF;
        sei();
        while(1);
        cli();
        LED_ON;
	}while(1);

	return -1;
}
