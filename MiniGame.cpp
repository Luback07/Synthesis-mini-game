#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<math.h>

#define LEFT 75       //     ?   
#define RIGHT 77 	  //       ?   
#define UP 72		  //   ?  
#define DOWN 80		  // ?  ?  
#define SPACE 32 	  //     ?    ?    
#define ENTER 13	  //     ?   
#define ESC 27		  // ESC 키 입력값 
#define RESET 114	  // r 키 입력값 
#define RESET_L 82	  // R 키 입력값 
#define PAUSE 112	  // p 키 입력값 
#define PAUSE_L 80	  // P 키 입력값 

#define ticktacktoe 1
#define avoidgame 2
#define secret 3

#define avoid_BG_X 16		// 피하기 게임 배경 X
#define avoid_BG_Y 25		// 피하기 게임 배경 Y 

int key = 0;																	//?   
int g_s = 1;																	//          
int ex = 2;																		//                
static int game = 0;

#include "function.h"
/*---------------------------------틱    택    토---------------------------------*/ 
#include "ticktacktoe.h"
/*---------------------------------피 하 기 게 임---------------------------------*/ 
#include "avoid.h"
/*---------------------------------기  본  화  면---------------------------------*/ 
#include "main.h"
/*---------------------------------메  인  함  수---------------------------------*/ 

int main(){
	CursorView();
	for(;;){
		if(game == 0){
			start();					//           ?        
		}
		else if(game == 1){
			ttt();						// ?          
		}
		else if(game == 2){
			avoid();					//    ?            
		}
		else if(game == -1){
			exit();						//          ?        
		}
		else if(game == -2){
			return 0;
		}
	}
}
