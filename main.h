void CursorView()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void gotoxy(int x,int y) { //gotoxy함수 
    COORD pos={x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

int game0_check_key() {
	key = 0;
	if(kbhit()){ //키입력이 있는 경우
        key=getch(); //키값을 받음
        if(key==224){ //방향키인경우 
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
	g_s = 1;								//게임 선택 변수 
	SetConsoleTitle("시작화면");			//콘솔 제목 변경
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 글자 기본색 지정 
	printf("  ______    ______   __       __  ________         ______   ________  __        ________   ______   ________ \n"
" /      \\  /      \\ /  \\     /  |/        |       /      \\ /        |/  |      /        | /      \\ /        |\n"
"/$$$$$$  |/$$$$$$  |$$  \\   /$$ |$$$$$$$$/       /$$$$$$  |$$$$$$$$/ $$ |      $$$$$$$$/ /$$$$$$  |$$$$$$$$/ \n"
"$$ | _$$/ $$ |__$$ |$$$  \\ /$$$ |$$ |__          $$ \\__$$/ $$ |__    $$ |      $$ |__    $$ |  $$/    $$ |   \n"
"$$ |/    |$$    $$ |$$$$  /$$$$ |$$    |         $$      \\ $$    |   $$ |      $$    |   $$ |         $$ |   \n"
"$$ |$$$$ |$$$$$$$$ |$$ $$ $$/$$ |$$$$$/           $$$$$$  |$$$$$/    $$ |      $$$$$/    $$ |   __    $$ |   \n"
"$$ \\__$$ |$$ |  $$ |$$ |$$$/ $$ |$$ |_____       /  \\__$$ |$$ |_____ $$ |_____ $$ |_____ $$ \\__/  |   $$ |   \n"
"$$    $$/ $$ |  $$ |$$ | $/  $$ |$$       |      $$    $$/ $$       |$$       |$$       |$$    $$/    $$ |   \n"
" $$$$$$/  $$/   $$/ $$/      $$/ $$$$$$$$/        $$$$$$/  $$$$$$$$/ $$$$$$$$/ $$$$$$$$/  $$$$$$/     $$/    \n"
"\n\n\n");		//출력  	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 글자 흰색 지정 
	printf("> Ticktacktoe ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); // 글자 기본색 지정 
	printf("- Dodge ");
	 while(game == 0)					//첫번째 화면일 때 실행 
	 {	
	 	if(kbhit()){
	    	system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 글자 흰색 지정 
		    printf("  ______    ______   __       __  ________         ______   ________  __        ________   ______   ________ \n"
" /      \\  /      \\ /  \\     /  |/        |       /      \\ /        |/  |      /        | /      \\ /        |\n"
"/$$$$$$  |/$$$$$$  |$$  \\   /$$ |$$$$$$$$/       /$$$$$$  |$$$$$$$$/ $$ |      $$$$$$$$/ /$$$$$$  |$$$$$$$$/ \n"
"$$ | _$$/ $$ |__$$ |$$$  \\ /$$$ |$$ |__          $$ \\__$$/ $$ |__    $$ |      $$ |__    $$ |  $$/    $$ |   \n"
"$$ |/    |$$    $$ |$$$$  /$$$$ |$$    |         $$      \\ $$    |   $$ |      $$    |   $$ |         $$ |   \n"
"$$ |$$$$ |$$$$$$$$ |$$ $$ $$/$$ |$$$$$/           $$$$$$  |$$$$$/    $$ |      $$$$$/    $$ |   __    $$ |   \n"
"$$ \\__$$ |$$ |  $$ |$$ |$$$/ $$ |$$ |_____       /  \\__$$ |$$ |_____ $$ |_____ $$ |_____ $$ \\__/  |   $$ |   \n"
"$$    $$/ $$ |  $$ |$$ | $/  $$ |$$       |      $$    $$/ $$       |$$       |$$       |$$    $$/    $$ |   \n"
" $$$$$$/  $$/   $$/ $$/      $$/ $$$$$$$$/        $$$$$$/  $$$$$$$$/ $$$$$$$$/ $$$$$$$$/  $$$$$$/     $$/    \n"
"\n\n\n");		//출력  	
		    
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
			if(g_s == 0) g_s = 2;
			else if(g_s == 3) g_s = 1;
						
		 	switch(g_s){
		 		case ticktacktoe:
	 				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 글자 흰색 지정 
					printf("> Ticktacktoe ");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); // 글자 기본색 지정 
					printf("- Dodge ");
					break;
				case avoidgame:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); // 글자 기본색 지정 
					printf("- Ticktacktoe ");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 글자 흰색 지정 
					printf("> Dodge ");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); // 글자 기본색 지정 
					break;
				}
		}
	}
}

int exit(){
	ex = 2;
	system("cls");
	SetConsoleTitle("게임 종료");			//콘솔 제목 변경
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 글자 기본색 지정 
	printf("게임을 종료하시겠습니까?\n\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); // 글자 기본색 지정 
	printf("YES");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 글자 기본색 지정 
	printf("      NO");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); // 글자 기본색 지정 
	while(game == -1)
	{
		if(kbhit()){
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 글자 기본색 지정 
		    printf("게임을 종료하시겠습니까?\n\n\n");		//출력
 
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
	 				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 글자 흰색 지정 
					printf("YES");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); // 글자 기본색 지정 
					printf("      NO");
					break;
				case 2:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); // 글자 흰색 지정 
					printf("YES");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 글자 기본색 지정 
					printf("      NO");
					break;
				}
		}
	}
	
}
