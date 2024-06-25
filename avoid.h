static int avoid_bg[avoid_BG_Y][avoid_BG_X];
static int avoid_bg_cpy[avoid_BG_Y][avoid_BG_X];
int point;							// 점수 
int avoid_speed;					// 내려오는 속도 
static int avoid_key;				// 입력받은 키
static int p_l_a;					// 플레이어 위치 
int level;							// 게임 레벨 
int spawn;							// 총알 스폰 
int spawn_speed;					// 총알 소환되는 속도 및 떨어지는 속도 
int spawn_num;						// 소환될 총알 갯수 
static int now_score;				// 현재 점수 
static int last_score;				// 이전 점수 
static int best_score;				// 최고 점수 

int player_move_avoid(){									// 플레이어 움직임 
	if(avoid_key == 1){
		if(p_l_a >= 1 && p_l_a <= avoid_BG_X-3){
			if(avoid_bg[avoid_BG_Y-2][p_l_a+1] != 0){
				avoid_over();
			}
			else{
				avoid_bg[avoid_BG_Y-2][p_l_a] = 0;
				avoid_bg[avoid_BG_Y-2][p_l_a+1] = 5;
				p_l_a += 1;
			}
		}
	}
	else if(avoid_key == -1){
		if(p_l_a >= 2 && p_l_a <= avoid_BG_X-2){
			if(avoid_bg[avoid_BG_Y-2][p_l_a-1] != 0){
				avoid_over();
			}
			else{
				avoid_bg[avoid_BG_Y-2][p_l_a] = 0;
				avoid_bg[avoid_BG_Y-2][p_l_a-1] = 5;
				p_l_a -= 1;
			}
		}
	}
	else if(avoid_key == 200){
		while(game == 2){
			if(kbhit()){
				avoid_key = game2_check_key();
				switch(avoid_key){
					case 1000:
						game = 0;
						break;
					case 200:
						return 0;
						break;
					case 100:
						avoid();
						break;
				}
			}
		}
	}
	else if(avoid_key == 1000){
		game = 0;
	}
}

int bullet_spawn(){								// 총알 생성 함수 
	if(level == 1){
		spawn_num = rand()%3+5;
		for(int i = 0; i < spawn_num; i++){
			spawn = rand()%5;
			if(spawn > 2){
				spawn = rand()%(avoid_BG_X-2)+1;
				avoid_bg[0][spawn] = -1;
			}
		}
	}
}

int bullet_fallen(){							// 총알 낙하 함수 
	for(int i = avoid_BG_Y; i > 0; i--){
		for(int j = 0; j < avoid_BG_X; j++){
			if(avoid_bg[i-1][j] == -1){
				if(avoid_bg[i][j] == 5){
					avoid_over();
				}
				else if(avoid_bg[i][j] == 1){
					avoid_bg[i-1][j] = 0;
				}
				else{
					avoid_bg[i-1][j] = 0;
					avoid_bg[i][j] = -1;
				}
			}
		}
	}
}

int avoid_over(){								// 게임 오버 함수 
	gotoxy(0, 26);
	printf("GAME OVER");
	while(game == 2){
		avoid_key = game2_check_key();
		switch (avoid_key){
			case 1000:
				game = 0;
				break;
			case 100:
				avoid();
				break;
		}
	}
}

int game2_check_key(){
	key = 0;
	if(kbhit()){ 								//키입력이 있는 경우
        key=getch(); 							//키값을 받음
        if(key==224){ 							//방향키인경우 
           	do{key=getch();} while(key==224);
       	    	    switch (key) {
           	    	case LEFT:
               	    	return -1;
               	    	break;
   	            	case RIGHT:
   	                	return 1;
       	        	    break;
       	        	default:
						return 0;
						break;
					}
       	}
	    else{
	    	switch (key) {
	    		case ESC:
	    			return 1000;
	    			break;
	    		case RESET:
	    		case RESET_L:
	    			return 100;
	    			break;
	    		case PAUSE:
	    			return 200;
	    			break;
				default:
					return 0;
					break;
			}
		}
	}
}

int avoid_reset(){
	system("cls");
	avoid_speed = 40;						// 기본 속도 
	p_l_a = avoid_BG_X/2+1;								// 플레이어 위치 지정 
	level = 1;
	for(int i = 0; i < avoid_BG_Y; i++){			//배경 초기화 
		for(int j = 0; j < avoid_BG_X; j++){
			avoid_bg[i][j] = 0;
			avoid_bg_cpy[i][j] = 100;
		}
	}										// 화면 양쪽 벽 지정 
	for(int i = 0; i < avoid_BG_Y; i++){
		avoid_bg[i][0] = 1;
		avoid_bg[i][avoid_BG_X-1] = 1;
	}
	for(int i = 0; i < avoid_BG_X; i++){	// 화면 밑 벽 지정 
		avoid_bg[avoid_BG_Y-1][i] = 1;
	}
	avoid_bg[avoid_BG_Y-2][avoid_BG_X/2+1] = 5;
}

int draw_avoid(){												// 피하기 게임 출력 
	for(int i = 0; i < avoid_BG_Y; i++){
		for(int j = 0; j < avoid_BG_X; j++){
			if(avoid_bg_cpy[i][j] != avoid_bg[i][j])
			{
				gotoxy(j+2, i+2);
				switch(avoid_bg[i][j]){
					case 1:
						printf("▩");
						break;
					case -1:
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // 글자 빨간색 지정 
						printf("▼");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 글자 기본색 지정 
						break;
					case 5:
						printf("▣");
						break;
					default:
						printf("  ");
						break;
				}
			}
		}
	}
	for(int i = 0; i < avoid_BG_Y; i++){
		for(int j = 0; j < avoid_BG_X; j++){
			avoid_bg_cpy[i][j] = avoid_bg[i][j];
		}
	}
	gotoxy(20, 0); printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦");
    gotoxy(20, 1); printf("▦                          ▦");
    gotoxy(20, 2); printf("▦  YOUR SCORE : %10d ▦", now_score);
    gotoxy(20, 3); printf("▦                          ▦");
    gotoxy(20, 4); printf("▦  LAST SCORE : %10d ▦", last_score);
    gotoxy(20, 3); printf("▦                          ▦");
    gotoxy(20, 4); printf("▦  BEST SCORE : %10d ▦", best_score);
    gotoxy(20, 5); printf("▦                          ▦");
    gotoxy(20, 6); printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦");
}

int avoid(){
	SetConsoleTitle("피하기 게임");			//콘솔 제목 변경
	avoid_reset();
	draw_avoid();
	while(game == 2){
		for(int a = 0; a < 3; a++){			// 블럭이 한번 내려올 동안 총 3번 키를 받을 수 있음 
			avoid_key = 0;
			avoid_key = game2_check_key();
			player_move_avoid();
			draw_avoid();
			Sleep(avoid_speed);
		}
		bullet_fallen();
		bullet_spawn();
		draw_avoid();
	}
}
