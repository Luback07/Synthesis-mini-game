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
#define ESC 27		  // ESC Ű �Է°� 
#define RESET 114	  // r Ű �Է°� 
#define RESET_L 82	  // R Ű �Է°� 
#define PAUSE 112	  // p Ű �Է°� 
#define PAUSE_L 80	  // P Ű �Է°� 

#define ticktacktoe 1
#define avoidgame 2
#define secret 3

#define avoid_BG_X 16		// ���ϱ� ���� ��� X
#define avoid_BG_Y 25		// ���ϱ� ���� ��� Y 

int key = 0;																	//?   
int g_s = 1;																	//          
int ex = 2;																		//                
static int game = 0;

#include "function.h"
/*---------------------------------ƽ    ��    ��---------------------------------*/ 
#include "ticktacktoe.h"
/*---------------------------------�� �� �� �� ��---------------------------------*/ 
#include "avoid.h"
/*---------------------------------��  ��  ȭ  ��---------------------------------*/ 
#include "main.h"
/*---------------------------------��  ��  ��  ��---------------------------------*/ 

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
