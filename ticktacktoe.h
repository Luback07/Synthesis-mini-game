static int t_bg[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};		//틱택토 게임판
int sel, x, y, rx, ry;																	// sel는 플레이어 키 값 받는 변수 
char ch;																				// 빈칸, O, X 출력 
static int tick_count = 0;																	//몇번 수를 뒀는지 확인 
static int game_end;

int game1_check_key() {
	key = 0;
	if(kbhit()){ //키입력이 있는 경우
        key=getch(); //키값을 받음
	    switch (key) {
	    	case 49:
	    		return 31;
	    		break;
	    	case 50:
	    		return 32;
	    		break;
	    	case 51:
	    		return 33;
	    		break;
	    	case 52:
	    		return 21;
	    		break;
	    	case 53:
	    		return 22;
	    		break;
	    	case 54:
	    		return 23;
	    		break;
	    	case 55:
	    		return 11;
	    		break;
	    	case 56:
	    		return 12;
	    		break;
	    	case 57:
	    		return 13;
	    		break;
	    	case ESC:
				return 1000;
				break;
			case RESET_L: 
			case RESET:
				return 100;
				break;
			default:
				return 0;
				break;
		}
	}
}

int t_reset(){
	while(game == 1){
		sel = 0;
		if(kbhit()){
			sel = game1_check_key();
			if(sel == 1000){
				game = 0;
			}
			else if(sel == 100){
				ttt();
				break;
			}
		}
	}
}

int p_s_t(){							// player O 위치 선택 
	int loc = 0;
	while(game == 1){
		sel = 0;
		if(kbhit()){
			sel = game1_check_key();
			if(sel == 1000)
			{
				game = 0;
				return 0;
			}
			else if(sel == 100){
				ttt();
				return 0;
			}
			else if(sel <= 33 && sel >= 11)
			{
				y = sel/10;
				sel -= y*10;
				x = sel;
				if(t_bg[y-1][x-1] == 0){
					t_bg[y-1][x-1] = 1;
					tick_count += 1;
					if(loc > 0){
						system("cls");
					}
					return 0;
				}
				else
				{
					gotoxy(3, 26+loc);
					printf("이미 놓은 자리입니다.\n");
					loc += 1;
				}
			}
		}
	}
}

int r_s_t(){							// X설치 
	while(game == 1){
		if(tick_count >= 9){
			break;
		}
		rx = rand()%3;
		ry = rand()%3;
		if(t_bg[ry][rx] == 0){
			t_bg[ry][rx] = 2;
			tick_count += 1;
			break;
		}
	}
}

int t_w_d(int t_result){
	if( t_result == 1){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // 글자 빨간색 지정 
		gotoxy(6, 26); printf("  _____  _           __     ________ _____   __          _______ _   _ \n");
		gotoxy(6, 27); printf(" |  __ \\| |        /\\\\ \\   / /  ____|  __ \\  \\ \\        / /_   _| \\ | |\n");
		gotoxy(6, 28); printf(" | |__) | |       /  \\\\ \\_/ /| |__  | |__) |  \\ \\  /\\  / /  | | |  \\| |\n");
		gotoxy(6, 29); printf(" |  ___/| |      / /\\ \\\\   / |  __| |  _  /    \\ \\/  \\/ /   | | | . ` |\n");
		gotoxy(6, 30); printf(" | |    | |____ / ____ \\| |  | |____| | \\ \\     \\  /\\  /   _| |_| |\\  |\n");
		gotoxy(6, 31); printf(" |_|    |______/_/    \\_\\_|  |______|_|  \\_\\     \\/  \\/   |_____|_| \\_|\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 글자 기본색 지정 
	}
	else if( t_result == -1){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); // 글자 빨간색 지정 
		gotoxy(6, 26); printf("  _____  _           __     ________ _____    _____  ______ ______ ______       _______ \n");
		gotoxy(6, 27); printf(" |  __ \\| |        /\\\\ \\   / /  ____|  __ \\  |  __ \\|  ____|  ____|  ____|   /\\|__   __|\n");
		gotoxy(6, 28); printf(" | |__) | |       /  \\\\ \\_/ /| |__  | |__) | | |  | | |__  | |__  | |__     /  \\  | |   \n");
		gotoxy(6, 29); printf(" |  ___/| |      / /\\ \\\\   / |  __| |  _  /  | |  | |  __| |  __| |  __|   / /\\ \\ | |   \n");
		gotoxy(6, 30); printf(" | |    | |____ / ____ \\\| |  | |____| | \\ \\  | |__| | |____| |    | |____ / ____ \\| |   \n");
		gotoxy(6, 31); printf(" |_|    |______/_/    \\_\\\_|  |______|_|  \\_\\ |_____/|______|_|    |______/_/    \\_\\_|   \n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 글자 기본색 지정 
	}
}

int t_check(){							// 한 줄됬는지 확인 
	for(int j = 0; j < 3; j++){			//세로 확인 
		for(int i = 0; i < 2; i++){
			if(t_bg[i][j] != t_bg[i+1][j]){
				break;
			}
			else{
				if(i == 1){
					if(t_bg[i][j] == 1){
						tick_count += 10;
						t_print();
						t_w_d(1);
						game_end = 1;
						break;
					}
					else if(t_bg[i][j] == 2){
						tick_count += 10;
						t_print();
						t_w_d(-1);
						game_end = 1;
						break;
					}
				}
			}
		}
	}
	for(int i = 0; i < 3; i++){			//가로 확인 
		for(int j = 0; j < 2; j++){
			if(t_bg[i][j] != t_bg[i][j+1]){
				break;
			}
			else{
				if(j == 1){
					if(t_bg[i][j] == 1){
						tick_count += 10;
						t_print();
						t_w_d(1);
						game_end = 1;
						break;
					}
					else if(t_bg[i][j] == 2){
						tick_count += 10;
						t_print();
						t_w_d(-1);
						game_end = 1;
						break;
					}
				}
			}
		}
	}
	for(int i = 0; i < 2; i++){
		if(t_bg[i][i] != t_bg[i+1][i+1]){
			break;
		}
		else{
			if(i == 1){
				if(t_bg[i][i] == 1){
					tick_count += 10;
					t_print();
					t_w_d(1);
					game_end = 1;
					break;
				}
				else if(t_bg[i][i] == 2){
					tick_count += 10;
					t_print();
					t_w_d(-1);
					game_end = 1;
					break;
				}
			}
		}
	}
	for(int i = 0; i < 2; i++){
		if(t_bg[2-i][i] != t_bg[1-i][i+1]){
			break;
		}
		else{
			if(i == 1){
				if(t_bg[2-i][i] == 1){
					tick_count += 10;
					t_print();
					t_w_d(1);
					game_end = 1;
					break;
				}
				else if(t_bg[2-i][i] == 2){
					tick_count += 10;
					t_print();
					t_w_d(-1);
					game_end = 1;
					break;
				}
			}
		}
	}
}

int t_print(){							// 틱택토 화면 출력 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 글자 흰색 지정 
	for(int i = 0; i < 4; i++){
		gotoxy(6, 3+7*i); printf("▩ ▩ ▩ ▩ ▩ ▩ ▩ ▩ ▩ ▩ ▩ ▩ ▩ ▩ ▩ ▩ ▩ ▩ ▩ ▩ ▩ ▩");
		if(i < 3){
			for(int j = 1; j < 8; j++){
				gotoxy(6, 3+7*i+j); printf("▩             ▩             ▩             ▩");
			}
		}
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(t_bg[i][j] == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); // 글자 회색 지정
				if(i == 0){
					if(j == 0){
						gotoxy(8, 5); printf("  ■ ■ ■ ■");
						gotoxy(8, 6); printf("        ■");
						gotoxy(8, 7); printf("        ■");
						gotoxy(8, 8); printf("        ■");
						gotoxy(8, 9); printf("        ■");
					}
					else if(j == 1){
						gotoxy(22, 5); printf("  ■ ■ ■ ■");
						gotoxy(22, 6); printf("  ■     ■");
						gotoxy(22, 7); printf("  ■ ■ ■ ■");
						gotoxy(22, 8); printf("  ■     ■");
						gotoxy(22, 9); printf("  ■ ■ ■ ■");
					}
					else if(j == 2){
						gotoxy(36, 5); printf("  ■ ■ ■ ■");
						gotoxy(36, 6); printf("  ■     ■");
						gotoxy(36, 7); printf("  ■ ■ ■ ■");
						gotoxy(36, 8); printf("        ■");
						gotoxy(36, 9); printf("        ■");
					}
				}
				else if(i == 1){
					if(j == 0){
						gotoxy(8, 12); printf("        ■");
						gotoxy(8, 13); printf("      ■ ■");
						gotoxy(8, 14); printf("    ■   ■");
						gotoxy(8, 15); printf("  ■ ■ ■ ■");
						gotoxy(8, 16); printf("        ■");
					}
					else if(j == 1){
						gotoxy(22, 12); printf("  ■ ■ ■ ■");
						gotoxy(22, 13); printf("  ■");
						gotoxy(22, 14); printf("  ■ ■ ■ ■");
						gotoxy(22, 15); printf("        ■");
						gotoxy(22, 16); printf("  ■ ■ ■ ■");
					}
					else if(j == 2){
						gotoxy(36, 12); printf("  ■ ■ ■ ■");
						gotoxy(36, 13); printf("  ■");
						gotoxy(36, 14); printf("  ■ ■ ■ ■");
						gotoxy(36, 15); printf("  ■     ■");
						gotoxy(36, 16); printf("  ■ ■ ■ ■");
					}
				}
				else if(i == 2){
					if(j == 0){
						gotoxy(8, 19); printf("      ■");
						gotoxy(8, 20); printf("    ■ ■");
						gotoxy(8, 21); printf("      ■");
						gotoxy(8, 22); printf("      ■");
						gotoxy(8, 23); printf("   ■ ■ ■");
					}
					else if(j == 1){
						gotoxy(22, 19); printf("  ■ ■ ■ ■");
						gotoxy(22, 20); printf("        ■");
						gotoxy(22, 21); printf("  ■ ■ ■ ■");
						gotoxy(22, 22); printf("  ■");
						gotoxy(22, 23); printf("  ■ ■ ■ ■");
					}
					else if(j == 2){
						gotoxy(36, 19); printf("  ■ ■ ■ ■");
						gotoxy(36, 20); printf("        ■");
						gotoxy(36, 21); printf("  ■ ■ ■ ■");
						gotoxy(36, 22); printf("        ■");
						gotoxy(36, 23); printf("  ■ ■ ■ ■");
					}
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 글자 흰색 지정
			}
			else if(t_bg[i][j] == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // 글자 연두색 지정 
				gotoxy((4+7*j)*2, 4+7*i); printf("  ■ ■ ■ ■");
				gotoxy((4+7*j)*2, 4+7*i+1); printf("■         ■");
				gotoxy((4+7*j)*2, 4+7*i+2); printf("■         ■");
				gotoxy((4+7*j)*2, 4+7*i+3); printf("■         ■");
				gotoxy((4+7*j)*2, 4+7*i+4); printf("■         ■");
				gotoxy((4+7*j)*2, 4+7*i+5); printf("  ■ ■ ■ ■");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 글자 흰색 지정 
			}
			else if(t_bg[i][j] == 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // 글자 노란색 지정 
				gotoxy((4+7*j)*2, 4+7*i); printf("■         ■");
				gotoxy((4+7*j)*2, 4+7*i+1); printf("  ■     ■");
				gotoxy((4+7*j)*2, 4+7*i+2); printf("    ■ ■");
				gotoxy((4+7*j)*2, 4+7*i+3); printf("    ■ ■");
				gotoxy((4+7*j)*2, 4+7*i+4); printf("  ■     ■");
				gotoxy((4+7*j)*2, 4+7*i+5); printf("■         ■");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 글자 흰색 지정 
			}
		}
	}
	gotoxy(60, 8); printf("Number Pad : O 설치");
	gotoxy(60, 10); printf("ESC : 메인화면으로 돌아가기");
	gotoxy(60, 12); printf("R : 재시작");
	if(tick_count == 9){
		printf("무승부임 님 바보임?");
	}
}

int ttt(){
	SetConsoleTitle("틱택토");			//콘솔 제목 변경
	system("cls");
	tick_count = 0;
	game_end = 0;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			t_bg[i][j] = 0;
		}
	}
	t_print();
	while(game == 1){
		p_s_t();
		t_check();
		if(game_end == 1){
			t_reset();
		}
		t_print();
		if(game != 1){
			break;
		}
		Sleep((rand()%5+1)*200);
		r_s_t();
		t_check();
		if(game_end == 1){
			t_reset();
		}
		t_print();
	}
}
