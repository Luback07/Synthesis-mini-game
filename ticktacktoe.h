static int t_bg[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};		//ƽ���� ������
int sel, x, y, rx, ry;																	// sel�� �÷��̾� Ű �� �޴� ���� 
char ch;																				// ��ĭ, O, X ��� 
static int count = 0;																	//��� ���� �״��� Ȯ�� 
static int game_end;

int game1_check_key() {
	key = 0;
	if(kbhit()){ //Ű�Է��� �ִ� ���
        key=getch(); //Ű���� ����
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

int p_s_t(){							// player O ��ġ ���� 
	while(game == 1){
		sel = 0;
		if(kbhit()){
			sel = game1_check_key();
			if(sel == 1000)
			{
				game = 0;
				break;
			}
			else if(sel == 100){
				ttt();
				break;
			}
			else if(sel <= 33 && sel >= 11)
			{
				y = sel/10;
				sel -= y*10;
				x = sel;
				if(t_bg[y-1][x-1] == 0){
				t_bg[y-1][x-1] = 1;
				count += 1;
				break;
				}
				else
				{
					printf("�̹� ���� �ڸ��Դϴ�.\n");
				}
			}
		}
	}
}

int r_s_t(){							// X��ġ 
	while(game == 1){
		if(count >= 9){
			break;
		}
		rx = rand()%3;
		ry = rand()%3;
		if(t_bg[ry][rx] == 0){
			t_bg[ry][rx] = 2;
			count += 1;
			break;
		}
	}
}

int t_check(){							// �� �ى���� Ȯ�� 
	for(int j = 0; j < 3; j++){			//���� Ȯ�� 
		for(int i = 0; i < 2; i++){
			if(t_bg[i][j] != t_bg[i+1][j]){
				break;
			}
			else{
				if(i == 1){
					if(t_bg[i][j] == 1){
						count += 10;
						t_print();
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // ���� ������ ���� 
						printf("  _____  _           __     ________ _____   __          _______ _   _ \n"
								" |  __ \\| |        /\\\\ \\   / /  ____|  __ \\  \\ \\        / /_   _| \\ | |\n"
								" | |__) | |       /  \\\\ \\_/ /| |__  | |__) |  \\ \\  /\\  / /  | | |  \\| |\n"
								" |  ___/| |      / /\\ \\\\   / |  __| |  _  /    \\ \\/  \\/ /   | | | . ` |\n"
								" | |    | |____ / ____ \\| |  | |____| | \\ \\     \\  /\\  /   _| |_| |\\  |\n"
								" |_|    |______/_/    \\_\\_|  |______|_|  \\_\\     \\/  \\/   |_____|_| \\_|\n"
        						"		                                                               \n"
             					"			                                                          ");
             					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // ���� �⺻�� ���� 
						game_end = 1;
						break;
					}
					else if(t_bg[i][j] == 2){
						count += 10;
						t_print();
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); // ���� ������ ���� 
						printf("  _____  _           __     ________ _____    _____  ______ ______ ______       _______ \n"
							" |  __ \\| |        /\\\\ \\   / /  ____|  __ \\  |  __ \\|  ____|  ____|  ____|   /\\|__   __|\n"
							" | |__) | |       /  \\\\ \\_/ /| |__  | |__) | | |  | | |__  | |__  | |__     /  \\  | |   \n"
							" |  ___/| |      / /\\ \\\\   / |  __| |  _  /  | |  | |  __| |  __| |  __|   / /\\ \\ | |   \n"
							" | |    | |____ / ____ \\\| |  | |____| | \\ \\  | |__| | |____| |    | |____ / ____ \\| |   \n"
							" |_|    |______/_/    \\_\\\_|  |______|_|  \\_\\ |_____/|______|_|    |______/_/    \\_\\_|   \n"
							"                                                                                        \n"
							"                                                                                        ");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // ���� �⺻�� ���� 
						game_end = 1;
						break;
					}
				}
			}
		}
	}
	for(int i = 0; i < 3; i++){			//���� Ȯ�� 
		for(int j = 0; j < 2; j++){
			if(t_bg[i][j] != t_bg[i][j+1]){
				break;
			}
			else{
				if(j == 1){
					if(t_bg[i][j] == 1){
						count += 10;
						t_print();
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // ���� ������ ���� 
						printf("  _____  _           __     ________ _____   __          _______ _   _ \n"
								" |  __ \\| |        /\\\\ \\   / /  ____|  __ \\  \\ \\        / /_   _| \\ | |\n"
								" | |__) | |       /  \\\\ \\_/ /| |__  | |__) |  \\ \\  /\\  / /  | | |  \\| |\n"
								" |  ___/| |      / /\\ \\\\   / |  __| |  _  /    \\ \\/  \\/ /   | | | . ` |\n"
								" | |    | |____ / ____ \\| |  | |____| | \\ \\     \\  /\\  /   _| |_| |\\  |\n"
								" |_|    |______/_/    \\_\\_|  |______|_|  \\_\\     \\/  \\/   |_____|_| \\_|\n"
        						"		                                                               \n"
             					"			                                                          ");
             					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // ���� �⺻�� ���� 
						game_end = 1;
						break;
					}
					else if(t_bg[i][j] == 2){
						count += 10;
						t_print();
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // ���� ������ ���� 
						printf("  _____  _           __     ________ _____    _____  ______ ______ ______       _______ \n"
							" |  __ \\| |        /\\\\ \\   / /  ____|  __ \\  |  __ \\|  ____|  ____|  ____|   /\\|__   __|\n"
							" | |__) | |       /  \\\\ \\_/ /| |__  | |__) | | |  | | |__  | |__  | |__     /  \\  | |   \n"
							" |  ___/| |      / /\\ \\\\   / |  __| |  _  /  | |  | |  __| |  __| |  __|   / /\\ \\ | |   \n"
							" | |    | |____ / ____ \\\| |  | |____| | \\ \\  | |__| | |____| |    | |____ / ____ \\| |   \n"
							" |_|    |______/_/    \\_\\\_|  |______|_|  \\_\\ |_____/|______|_|    |______/_/    \\_\\_|   \n"
							"                                                                                        \n"
							"                                                                                        ");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // ���� �⺻�� ���� 
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
					count += 10;
					t_print();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // ���� ������ ���� 
						printf("  _____  _           __     ________ _____   __          _______ _   _ \n"
								" |  __ \\| |        /\\\\ \\   / /  ____|  __ \\  \\ \\        / /_   _| \\ | |\n"
								" | |__) | |       /  \\\\ \\_/ /| |__  | |__) |  \\ \\  /\\  / /  | | |  \\| |\n"
								" |  ___/| |      / /\\ \\\\   / |  __| |  _  /    \\ \\/  \\/ /   | | | . ` |\n"
								" | |    | |____ / ____ \\| |  | |____| | \\ \\     \\  /\\  /   _| |_| |\\  |\n"
								" |_|    |______/_/    \\_\\_|  |______|_|  \\_\\     \\/  \\/   |_____|_| \\_|\n"
        						"		                                                               \n"
             					"			                                                          ");
             					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // ���� �⺻�� ���� 
					game_end = 10;
					break;
				}
				else if(t_bg[i][i] == 2){
					count += 10;
					t_print();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // ���� ������ ���� 
					printf("  _____  _           __     ________ _____    _____  ______ ______ ______       _______ \n"
							" |  __ \\| |        /\\\\ \\   / /  ____|  __ \\  |  __ \\|  ____|  ____|  ____|   /\\|__   __|\n"
							" | |__) | |       /  \\\\ \\_/ /| |__  | |__) | | |  | | |__  | |__  | |__     /  \\  | |   \n"
							" |  ___/| |      / /\\ \\\\   / |  __| |  _  /  | |  | |  __| |  __| |  __|   / /\\ \\ | |   \n"
							" | |    | |____ / ____ \\\| |  | |____| | \\ \\  | |__| | |____| |    | |____ / ____ \\| |   \n"
							" |_|    |______/_/    \\_\\\_|  |______|_|  \\_\\ |_____/|______|_|    |______/_/    \\_\\_|   \n"
							"                                                                                        \n"
							"                                                                                        ");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // ���� �⺻�� ���� 
					game_end = 10;
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
					count += 10;
					t_print();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // ���� ������ ���� 
						printf("  _____  _           __     ________ _____   __          _______ _   _ \n"
								" |  __ \\| |        /\\\\ \\   / /  ____|  __ \\  \\ \\        / /_   _| \\ | |\n"
								" | |__) | |       /  \\\\ \\_/ /| |__  | |__) |  \\ \\  /\\  / /  | | |  \\| |\n"
								" |  ___/| |      / /\\ \\\\   / |  __| |  _  /    \\ \\/  \\/ /   | | | . ` |\n"
								" | |    | |____ / ____ \\| |  | |____| | \\ \\     \\  /\\  /   _| |_| |\\  |\n"
								" |_|    |______/_/    \\_\\_|  |______|_|  \\_\\     \\/  \\/   |_____|_| \\_|\n"
        						"		                                                               \n"
             					"			                                                          ");
             					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // ���� �⺻�� ���� 
					game_end = 1;
					break;
				}
				else if(t_bg[2-i][i] == 2){
					count += 10;
					t_print();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // ���� ������ ����
					printf("  _____  _           __     ________ _____    _____  ______ ______ ______       _______ \n"
							" |  __ \\| |        /\\\\ \\   / /  ____|  __ \\  |  __ \\|  ____|  ____|  ____|   /\\|__   __|\n"
							" | |__) | |       /  \\\\ \\_/ /| |__  | |__) | | |  | | |__  | |__  | |__     /  \\  | |   \n"
							" |  ___/| |      / /\\ \\\\   / |  __| |  _  /  | |  | |  __| |  __| |  __|   / /\\ \\ | |   \n"
							" | |    | |____ / ____ \\\| |  | |____| | \\ \\  | |__| | |____| |    | |____ / ____ \\| |   \n"
							" |_|    |______/_/    \\_\\\_|  |______|_|  \\_\\ |_____/|______|_|    |______/_/    \\_\\_|   \n"
							"                                                                                        \n"
							"                                                                                        ");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // ���� �⺻�� ���� 
					game_end = 1;
					break;
				}
			}
		}
	}
}

int t_print(){							// ƽ���� ȭ�� ��� 
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // ���� ��� ���� 
	printf("    0 1 2\n");
	printf("   ------\n");
	for(int i = 0; i < 3; i++){
		printf("%d |", i);
		for(int j = 0; j < 3; j++){
			if(t_bg[i][j] == 0)
			{
				ch = ' ';
			}
			else if(t_bg[i][j] == 1)
			{
				ch = 'O';
			}
			else if(t_bg[i][j] == 2)
			{
				ch = 'X';
			}
			printf(" %c", ch);
		}
		printf("\n");
	}
	if(count == 9){
		printf("���º��� �� �ٺ���?");
	}
}

int ttt(){
	SetConsoleTitle("ƽ����");			//�ܼ� ���� ����
	count = 0;
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
