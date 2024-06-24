void CursorView()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
    cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void gotoxy(int x,int y) { //gotoxy�Լ� 
    COORD pos={2*x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

int game0_check_key() {
	key = 0;
	if(kbhit()){ //Ű�Է��� �ִ� ���
        key=getch(); //Ű���� ����
        if(key==224){ //����Ű�ΰ�� 
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
	    		case ENTER:
	    			return 100;
	    			break;
	    		case ESC:
	    			if(game == 0)
	    			{
	    				return 1000;
	    				break;
					}
					else if(game == -1)
					{
						break;
					}
				default:
					return 0;
					break;
			}
		}
	}
}

int start(){
	system("cls");
	g_s = 1;								//���� ���� ���� 
	SetConsoleTitle("����ȭ��");			//�ܼ� ���� ����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // ���� �⺻�� ���� 
	printf("  ______    ______   __       __  ________         ______   ________  __        ________   ______   ________ \n"
" /      \\  /      \\ /  \\     /  |/        |       /      \\ /        |/  |      /        | /      \\ /        |\n"
"/$$$$$$  |/$$$$$$  |$$  \\   /$$ |$$$$$$$$/       /$$$$$$  |$$$$$$$$/ $$ |      $$$$$$$$/ /$$$$$$  |$$$$$$$$/ \n"
"$$ | _$$/ $$ |__$$ |$$$  \\ /$$$ |$$ |__          $$ \\__$$/ $$ |__    $$ |      $$ |__    $$ |  $$/    $$ |   \n"
"$$ |/    |$$    $$ |$$$$  /$$$$ |$$    |         $$      \\ $$    |   $$ |      $$    |   $$ |         $$ |   \n"
"$$ |$$$$ |$$$$$$$$ |$$ $$ $$/$$ |$$$$$/           $$$$$$  |$$$$$/    $$ |      $$$$$/    $$ |   __    $$ |   \n"
"$$ \\__$$ |$$ |  $$ |$$ |$$$/ $$ |$$ |_____       /  \\__$$ |$$ |_____ $$ |_____ $$ |_____ $$ \\__/  |   $$ |   \n"
"$$    $$/ $$ |  $$ |$$ | $/  $$ |$$       |      $$    $$/ $$       |$$       |$$       |$$    $$/    $$ |   \n"
" $$$$$$/  $$/   $$/ $$/      $$/ $$$$$$$$/        $$$$$$/  $$$$$$$$/ $$$$$$$$/ $$$$$$$$/  $$$$$$/     $$/    \n"
"\n\n\n");		//���  	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // ���� ��� ���� 
	printf("> ƽ���� ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); // ���� �⺻�� ���� 
	printf("- ���ϱ� ���� ");
	printf("- ??? ");
	 while(game == 0)					//ù��° ȭ���� �� ���� 
	 {	
	 	if(kbhit()){
	    	system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // ���� ��� ���� 
		    printf("  ______    ______   __       __  ________         ______   ________  __        ________   ______   ________ \n"
" /      \\  /      \\ /  \\     /  |/        |       /      \\ /        |/  |      /        | /      \\ /        |\n"
"/$$$$$$  |/$$$$$$  |$$  \\   /$$ |$$$$$$$$/       /$$$$$$  |$$$$$$$$/ $$ |      $$$$$$$$/ /$$$$$$  |$$$$$$$$/ \n"
"$$ | _$$/ $$ |__$$ |$$$  \\ /$$$ |$$ |__          $$ \\__$$/ $$ |__    $$ |      $$ |__    $$ |  $$/    $$ |   \n"
"$$ |/    |$$    $$ |$$$$  /$$$$ |$$    |         $$      \\ $$    |   $$ |      $$    |   $$ |         $$ |   \n"
"$$ |$$$$ |$$$$$$$$ |$$ $$ $$/$$ |$$$$$/           $$$$$$  |$$$$$/    $$ |      $$$$$/    $$ |   __    $$ |   \n"
"$$ \\__$$ |$$ |  $$ |$$ |$$$/ $$ |$$ |_____       /  \\__$$ |$$ |_____ $$ |_____ $$ |_____ $$ \\__/  |   $$ |   \n"
"$$    $$/ $$ |  $$ |$$ | $/  $$ |$$       |      $$    $$/ $$       |$$       |$$       |$$    $$/    $$ |   \n"
" $$$$$$/  $$/   $$/ $$/      $$/ $$$$$$$$/        $$$$$$/  $$$$$$$$/ $$$$$$$$/ $$$$$$$$/  $$$$$$/     $$/    \n"
"\n\n\n");		//���  	
		    
		    g_s += game0_check_key();
			if(g_s > 100 && g_s < 110)
			{
				system("cls");
				if(g_s == 101) game = 1;
				if(g_s == 102) game = 2;
				if(g_s == 103) game = 3;
			}
			else if(g_s >= 1000 && g_s <= 1010)
			{
				game = -1;
			}
			if(g_s == 0) g_s = 3;
			else if(g_s == 4) g_s = 1;
						
		 	switch(g_s){
		 		case ticktacktoe:
	 				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // ���� ��� ���� 
					printf("> ƽ���� ");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); // ���� �⺻�� ���� 
					printf("- ���ϱ� ���� ");
					printf("- ??? ");
					break;
				case avoidgame:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); // ���� �⺻�� ���� 
					printf("- ƽ���� ");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // ���� ��� ���� 
					printf("> ���ϱ� ���� ");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); // ���� �⺻�� ���� 
					printf("- ??? ");
					break;
				case secret: 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); // ���� �⺻�� ���� 
					printf("- ƽ���� ");
					printf("- ���ϱ� ���� ");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // ���� ��� ���� 
					printf("> ??? ");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); // ���� �⺻�� ���� 
					break;
				}
		}
	}
}

int exit(){
	ex = 2;
	system("cls");
	SetConsoleTitle("���� ����");			//�ܼ� ���� ����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // ���� �⺻�� ���� 
	printf("������ �����Ͻðڽ��ϱ�?\n\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); // ���� �⺻�� ���� 
	printf("YES");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // ���� �⺻�� ���� 
	printf("      NO");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); // ���� �⺻�� ���� 
	while(game == -1)
	{
		if(kbhit()){
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // ���� �⺻�� ���� 
		    printf("������ �����Ͻðڽ��ϱ�?\n\n\n");		//���
 
		    ex += game0_check_key();
			if(ex >= 100 && ex <= 103)
			{
				system("cls");
				if(ex == 101) game = -2; system("cls");
				if(ex == 102) game = 0;
				break;
			}
			if(ex == 0) ex = 2;
			else if(ex == 3) ex = 1;		
		 	switch(ex){
		 		case 1:
	 				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // ���� ��� ���� 
					printf("YES");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); // ���� �⺻�� ���� 
					printf("      NO");
					break;
				case 2:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); // ���� ��� ���� 
					printf("YES");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // ���� �⺻�� ���� 
					printf("      NO");
					break;
				}
		}
	}
	
}
