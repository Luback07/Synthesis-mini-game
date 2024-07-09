static int avoid_bg[avoid_BG_Y][avoid_BG_X];			// 메인 배경 
static int avoid_bg_cpy[avoid_BG_Y][avoid_BG_X];		// 히든 배경 - 메인 배경과 비교하는 용도
static int avoid_pt[5][30][avoid_BG_X];					// 공격 패턴 저장할 곳 
int point;							// 점수
static int avoid_speed;				// 내려오는 속도 
static int avoid_key;				// 입력받은 키
static int p_l_a;					// 플레이어 위치 
static int level;					// 게임 레벨 
int spawn;							// 총알 스폰 
int spawn_speed;					// 총알 소환되는 속도 및 떨어지는 속도 
int spawn_num;						// 소환될 총알 갯수 
static double playtime;				// 게임 플레이 시간 
static double pausetime;			// 멈춘 시간 
static int now_score;				// 현재 점수 
static int last_score;				// 이전 점수 
static int best_score;				// 최고 점수 
static int bullet_avoid;			// 총알 내려올 갯수 
int r_pattern;						// 공격 패턴 랜덤 지정 
int pattern;						// 공격 패턴 

int avoid_system(){
	if(now_score >= 0 && now_score < 10000){
		level = 1;
	}
	else if(now_score >= 10000 && now_score < 20000){
		level = 2;
	}
	else if(now_score >= 20000){
		level = 3;
	} 
	switch (level) {
		case 1:
			avoid_speed = 50;
			break;
		case 2:
			avoid_speed = 30;
			break;
		case 3:
			avoid_speed = 15;
			break;
	}
}

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
	}														// 정지 했을 때 
	else if(avoid_key == 200){
		gotoxy(4, 10); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");
        gotoxy(4, 11); printf("▤                             ▤");
        gotoxy(4, 12); printf("▤  +-----------------------+  ▤");
        gotoxy(4, 13); printf("▤  |       P A U S E       |  ▤");
        gotoxy(4, 14); printf("▤  +-----------------------+  ▤");
        gotoxy(4, 15); printf("▤  Press any key to resume..  ▤");
        gotoxy(4, 16); printf("▤                             ▤");
        gotoxy(4, 17); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");
		clock_t p_start = clock();
		while(game == 2){
			if(kbhit()){
				avoid_key = game2_check_key();
				switch(avoid_key){
					case 1000:
						game = 0;
						break;
					case 100:
						avoid();
						break;
					case 200:
						clock_t p_end = clock();
						pausetime += (double)(p_end - p_start) / CLOCKS_PER_SEC;
						for(int i = 0; i < avoid_BG_Y; i++){			//배경 초기화 
							for(int j = 0; j < avoid_BG_X; j++){
								avoid_bg_cpy[i][j] = 100;
							}
						}
						gotoxy(5, 10); printf(" ");
						gotoxy(5, 17); printf(" ");
						return 0;
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
	if(bullet_avoid == 0){						// 총알 패턴 생성 
		for(int i = 0; i < 5; i++){				// 총알 패턴 초기화 
			for(int j = 0; j < 30; j++){
				for(int o = 0; o < avoid_BG_X; o++){
					avoid_pt[i][j][o] = 0;
				}
			}
		}
		r_pattern = rand() % (2+level);
		switch (r_pattern) {
			case 0:								// 무작위 패턴 
				for(int i = 0; i < 30; i++){
					spawn_num = rand()%3+2;
					for(int j = 0; j < spawn_num; j++){
						spawn = rand()%(6+level);
						if(spawn > 3){
							spawn = rand()%(avoid_BG_X-2)+1;
							avoid_pt[0][i][spawn] = -1;
						}
					}
				}
				bullet_avoid = 35;
				pattern = 0;
				break;
			case 1:								// 대각선 패턴 
				for(int i = 0; i < 28; i++){
					for(int j = 1; j < avoid_BG_X-1; j++){
						avoid_pt[1][i][j] = -1;
					}
				}
				for(int i = 0; i < avoid_BG_X-2; i++){
					avoid_pt[1][i][i] = 0;
					avoid_pt[1][i][i+1] = 0;
					avoid_pt[1][i][i+2] = 0;
					avoid_pt[1][i][i+3] = 0;
					avoid_pt[1][i][i-1] = 0;
				}
				for(int i = 0; i < avoid_BG_X-2; i++){
					avoid_pt[1][i+14][avoid_BG_X-1-i] = 0;
					avoid_pt[1][i+14][avoid_BG_X-2-i] = 0;
					avoid_pt[1][i+14][avoid_BG_X-3-i] = 0;
					avoid_pt[1][i+14][avoid_BG_X-4-i] = 0;
					avoid_pt[1][i+14][avoid_BG_X-i] = 0;
				}
				bullet_avoid = 35;
				pattern = 1;
				break;
			case 2:
				for(int o = 0; o < 2; o++){
				for(int i = 0; i < 6; i++){
					int p_2 = rand()%11;
					for(int j = 0;  j < 1; j++){
						avoid_pt[2][5*i+j][p_2+1] = -1;
						avoid_pt[2][5*i+j][p_2+2] = -1;
						avoid_pt[2][5*i+j][p_2+3] = -1;
						avoid_pt[2][5*i+j][p_2+4] = -1;
					}
				}
				}
				bullet_avoid = 35;
				pattern = 2;
				break;
			case 3:
				for(int i = 0; i < 3; i++){
					for(int j = 0; j < avoid_BG_X-5; j++){
						if(i%2 == 0){
							avoid_pt[3][10*i][j+1] = -1;
						}
						else{
							avoid_pt[3][10*i][j+4] = -1;
						}
					}
				}
				bullet_avoid = 35;
				pattern = 3;
				break;
			case 4:								// 최종 패턴
				for(int i = 0; i < 5; i++){
					for(int j = 0; j < 7; j++){
						avoid_pt[4][6*i+1][2*j+2] = -1;
						avoid_pt[4][6*i+4][2*j+1] = -1;
					}
				}
				bullet_avoid = 35;
				pattern = 4;
				break;
		}
	}
	if(bullet_avoid >= 1){						// 총알 소환 
		bullet_avoid -= 1;
		if(bullet_avoid >= 5){
			for(int m = 1; m < avoid_BG_X-1; m++){
			avoid_bg[0][m] = avoid_pt[pattern][bullet_avoid-5][m];
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

int avoid_over(){					// 게임 오버 함수 
	gotoxy(4, 29); printf(" _____ _____ _____ _____    _____ _____ _____ _____ ");
	gotoxy(4, 30); printf("|   __|  _  |     |   __|  |     |  |  |   __| __  |");
	gotoxy(4, 31); printf("|  |  |     | | | |   __|  |  |  |  |  |   __|    -|");
	gotoxy(4, 32); printf("|_____|__|__|_|_|_|_____|  |_____|\\___/|_____|__|__|");
	last_score = now_score;															// 이전 점수를 현재 점수로 바꿈 
	while(game == 2){																// 키 입력 받고 메인으로 나갈지 재시작할지 결정하는 함수 
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

int avoid_reset(){									// 게임 초기화 
	system("cls");									// 화면 초기화
	bullet_avoid = 0;			 				 	// 총알 패턴 초기화
	playtime = 0;									// 시간 초기화 
	pausetime = 0;									// 멈춘 시간 초기화 
	p_l_a = avoid_BG_X/2;							// 플레이어 위치 지정 
	level = 1;										// 게임 레벨 초기화 
	for(int i = 0; i < avoid_BG_Y; i++){			//배경 초기화 
		for(int j = 0; j < avoid_BG_X; j++){
			avoid_bg[i][j] = 0;
			avoid_bg_cpy[i][j] = 100;
		}
	}
	for(int i = 0; i < avoid_BG_Y; i++){			// 화면 양쪽 벽 지정 
		avoid_bg[i][0] = 1;
		avoid_bg[i][avoid_BG_X-1] = 1;
	}
	for(int i = 0; i < avoid_BG_X; i++){			// 화면 밑 벽 지정 
		avoid_bg[avoid_BG_Y-1][i] = 1;
	}
	avoid_bg[avoid_BG_Y-2][avoid_BG_X/2] = 5;		// 플레이어 위치 소환 
}

int score_cal(){
	now_score = (playtime-pausetime)*100;
	if(now_score > best_score){
		best_score = now_score;
		FILE* file = fopen("BEST SCORE", "w");
		if(file == NULL) {
			best_score = -1;
		}
		fprintf(file, "%d", best_score);
		fclose(file);
	}
}

int draw_avoid(){												// 피하기 게임 출력 
	for(int i = 0; i < avoid_BG_Y; i++){
		for(int j = 0; j < avoid_BG_X; j++){
			if(avoid_bg_cpy[i][j] != avoid_bg[i][j])
			{
				gotoxy((j+2)*2, i+2);
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
	gotoxy(40, 3); printf("LEVEL : %d", level);
	gotoxy(40, 5); printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦");
    gotoxy(40, 6); printf("▦                          ▦");
    gotoxy(40, 7); printf("▦  YOUR SCORE : %10d ▦", now_score);
    gotoxy(40, 8); printf("▦                          ▦");
    gotoxy(40, 9); printf("▦  LAST SCORE : %10d ▦", last_score);
    gotoxy(40, 10); printf("▦                          ▦");
    if(best_score >= 0){
    	gotoxy(40, 11); printf("▦  BEST SCORE : %10d ▦", best_score);
	}
    else{
    	gotoxy(40, 11); printf("▦  BEST SCORE : ERROR      ▦");
	}
    gotoxy(40, 12); printf("▦                          ▦");
    gotoxy(40, 13); printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦");
    gotoxy(40, 15); printf("◁  ▷ : 좌 / 우");
    gotoxy(40, 17); printf("ESC : 메인화면으로 돌아가기");
	gotoxy(40, 19); printf("P : 일시정지");
	gotoxy(40, 21); printf("R : 재시작"); 
}

int avoid(){
	FILE* file = fopen("BEST SCORE", "r");
	if(file == NULL) {
		best_score = -1;
	}
	fscanf(file, "%d", &best_score);
	fclose(file);
	SetConsoleTitle("피하기 게임");			//콘솔 제목 변경
	avoid_reset();
	draw_avoid();
	clock_t start = clock();
	while(game == 2){
		avoid_system();
		for(int a = 0; a < 5; a++){			// 블럭이 한번 내려올 동안 총 5번 키를 받을 수 있음 
			avoid_key = 0;
			avoid_key = game2_check_key();
			player_move_avoid();
			draw_avoid();
			Sleep(avoid_speed);
			playtime = (double)(clock() - start) / CLOCKS_PER_SEC;
			score_cal();
			draw_avoid();
		}
		bullet_fallen();
		bullet_spawn();
		playtime = (double)(clock() - start) / CLOCKS_PER_SEC;
		score_cal();
		draw_avoid();
	}
}
