static int avoid_bg[avoid_BG_Y][avoid_BG_X];
static int avoid_bg_cpy[avoid_BG_Y][avoid_BG_X];
int point;							// ���� 
int avoid_speed;					// �������� �ӵ� 
static int avoid_key;				// �Է¹��� Ű
static int p_l_a;					// �÷��̾� ��ġ 
int level;							// ���� ���� 
int spawn;							// �Ѿ� ���� 
int spawn_speed;					// �Ѿ� ��ȯ�Ǵ� �ӵ� �� �������� �ӵ� 
int spawn_num;						// ��ȯ�� �Ѿ� ���� 

int player_move_avoid(){									// �÷��̾� ������ 
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

int bullet_spawn(){								// �Ѿ� ���� �Լ� 
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

int bullet_fallen(){							// �Ѿ� ���� �Լ� 
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

int avoid_over(){								// ���� ���� �Լ� 
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
	if(kbhit()){ 								//Ű�Է��� �ִ� ���
        key=getch(); 							//Ű���� ����
        if(key==224){ 							//����Ű�ΰ�� 
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
	avoid_speed = 40;						// �⺻ �ӵ� 
	p_l_a = avoid_BG_X/2+1;								// �÷��̾� ��ġ ���� 
	level = 1;
	for(int i = 0; i < avoid_BG_Y; i++){			//��� �ʱ�ȭ 
		for(int j = 0; j < avoid_BG_X; j++){
			avoid_bg[i][j] = 0;
			avoid_bg_cpy[i][j] = 100;
		}
	}										// ȭ�� ���� �� ���� 
	for(int i = 0; i < avoid_BG_Y; i++){
		avoid_bg[i][0] = 1;
		avoid_bg[i][avoid_BG_X-1] = 1;
	}
	for(int i = 0; i < avoid_BG_X; i++){	// ȭ�� �� �� ���� 
		avoid_bg[avoid_BG_Y-1][i] = 1;
	}
	avoid_bg[avoid_BG_Y-2][avoid_BG_X/2+1] = 5;
	gotoxy(20, 2); printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�");
}

int draw_avoid(){												// ���ϱ� ���� ��� 
	for(int i = 0; i < avoid_BG_Y; i++){
		for(int j = 0; j < avoid_BG_X; j++){
			if(avoid_bg_cpy[i][j] != avoid_bg[i][j])
			{
				gotoxy(j+2, i+2);
				switch(avoid_bg[i][j]){
					case 1:
						printf("��");
						break;
					case -1:
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // ���� ������ ���� 
						printf("��");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // ���� �⺻�� ���� 
						break;
					case 5:
						printf("��");
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
	
}

int avoid(){
	SetConsoleTitle("���ϱ� ����");			//�ܼ� ���� ����
	avoid_reset();
	draw_avoid();
	while(game == 2){
		for(int a = 0; a < 3; a++){			// ���� �ѹ� ������ ���� �� 3�� Ű�� ���� �� ���� 
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
