/*
    Version: 2.0
*/



# include <iostream>
# include <stdlib.h>
# include <string.h>
# include "iGraphics.h"
# include <stdio.h>
using namespace std;

bool musicON=true;
bool eatON = true;

struct batton{
	int x;
	int y;
}menu_cordinat[3],end_cordinat[3];


char start_menu_image[20]="start manu.bmp";
char end_menu_image[30]="snake background.bmp";
int box_height=55,box_weight=214;

int mposx,  mposy;

int height = 800, weight = 600;

int life=4 ,point=0 ;



char snake[36][20]={"snake\\9 (4).bmp","snake\\9 (3).bmp","snake\\9 (2).bmp","snake\\9 (1).bmp","snake\\8 (4).bmp","snake\\8 (3).bmp","snake\\8 (2).bmp","snake\\8 (1).bmp",
					"snake\\7 (4).bmp","snake\\7 (3).bmp","snake\\7 (2).bmp","snake\\7 (1).bmp","snake\\6 (4).bmp","snake\\6 (3).bmp","snake\\6 (2).bmp","snake\\6 (1).bmp",
					"snake\\5 (4).bmp","snake\\5 (3).bmp","snake\\5 (2).bmp","snake\\5 (1).bmp","snake\\4 (4).bmp","snake\\4 (3).bmp","snake\\4 (2).bmp","snake\\4 (1).bmp",
					"snake\\3 (4).bmp","snake\\3 (3).bmp","snake\\3 (2).bmp","snake\\3 (1).bmp","snake\\2 (4).bmp","snake\\2 (3).bmp","snake\\2 (2).bmp","snake\\2 (1).bmp",
					"snake\\1 (4).bmp","snake\\1 (3).bmp","snake\\1 (2).bmp","snake\\1 (1).bmp"};
int snake_x=weight/2-50,snake_y=0;
int snake_height = 190	, snake_weight = 40;
int snakeindex=28;           

char ball_0_imagelocation[100]="life ball1.bmp";
int ball_0_x=0;
int ball_0_y=height;
int ball_0_image_hight=45 ,ball_0_image_weight=45;
int ball_0_speed=2.2;

char ball_1_imagelocation[100]="burning_coal1.bmp";
int ball_1_x=0;
int ball_1_y=height;
int ball_1_image_hight=75 ,ball_1_image_weight=75;
int ball_1_speed=4;

char ball_2_imagelocation[100]="burning_coal2.bmp";
int ball_2_x=345;
int ball_2_y=height;
int ball_2_image_hight=56 ,ball_2_image_weight=75;
int ball_2_speed=3;

char ball_3_imagelocation[100]="burning_coal3.bmp";
int ball_3_x=100;
int ball_3_y=height;
int ball_3_image_hight=45 ,ball_3_image_weight=70;
int ball_3_speed=7;

char ball_4_imagelocation[100]="burning_coal1.bmp";
int ball_4_x=0;
int ball_4_y=height;
int ball_4_image_hight=75 ,ball_4_image_weight=75;
int ball_4_speed=6;

char ball_5_imagelocation[100]="life ball1.bmp";
int ball_5_x=0;
int ball_5_y=height;
int ball_5_image_hight=45 ,ball_5_image_weight=45;
int ball_5_speed=3.5;

	void set_position(int *position_x, int *position_y, int *speed, int *imageweight )
	{
		if (*position_y <= 0)
		{
			*position_x = rand() % (weight - *imageweight);
			*position_y = height+500;
		}
		else
		{
			*position_y -= *speed;
		}


	}
	void  sound()
{
	if(musicON)
	{   musicON = false;
		PlaySound(0,0,0);
	}
	else if((ball_0_x +ball_0_image_weight > snake_x && ball_0_x < snake_x + snake_weight )&&(ball_0_y +ball_0_image_hight > snake_y && ball_0_y < snake_y + snake_height))
	{
		    PlaySound("sound//eat.wav", NULL,SND_ASYNC );
			//musicON = true;
	}
	PlaySound("sound//background.wav", NULL, SND_LOOP|SND_ASYNC);
	
}



/*
	function iDraw() is called again and again by the system.
*/
	char point_str[5];
	char life_str[5];
	bool go_left=true;
	bool go_right=true;


	int game_state=-1;
void iDraw()
{
	//place your drawing codes here
	iClear();

	if(game_state==-1)
	{
		
		iShowBMP(0,0,start_menu_image);
		iSetColor(255,0,0);
		iText(343,313,point_str,GLUT_BITMAP_TIMES_ROMAN_24);
		
				life=3;
		        point=0;
	ball_0_speed= 2.2;
	ball_1_speed= 4;
	ball_2_speed= 3;
	ball_3_speed= 7;
	ball_4_speed= 6;
	ball_5_speed= 3.5;

		
	}
	else if(game_state==0)
	{
		itoa(point,point_str,10);
	     itoa(life,life_str,10);
			iShowBMP(0,0,"background.bmp");
			iShowBMP2(520,720,"life ball1.bmp",0);
			iText(531,700,life_str,GLUT_BITMAP_TIMES_ROMAN_24);
			iShowBMP2(470,720,"XP.bmp",0);
			iText(480,700,point_str,GLUT_BITMAP_TIMES_ROMAN_24);

		set_position(&ball_0_x,&ball_0_y,&ball_0_speed,&ball_0_image_weight);
	iShowBMP2(ball_0_x,ball_0_y,ball_0_imagelocation,0);

	set_position(&ball_1_x,&ball_1_y,&ball_1_speed,&ball_1_image_weight);
	iShowBMP2(ball_1_x,ball_1_y,ball_1_imagelocation,0);

		set_position(&ball_2_x,&ball_2_y,&ball_2_speed,&ball_2_image_weight);
	iShowBMP2(ball_2_x,ball_2_y,ball_2_imagelocation,0);

	set_position(&ball_5_x,&ball_5_y,&ball_5_speed,&ball_5_image_weight);
	iShowBMP2(ball_5_x,ball_5_y,ball_5_imagelocation,0);

			set_position(&ball_3_x,&ball_3_y,&ball_3_speed,&ball_3_image_weight);
	iShowBMP2(ball_3_x,ball_3_y,ball_3_imagelocation,0);

		set_position(&ball_4_x,&ball_4_y,&ball_4_speed,&ball_4_image_weight);
	iShowBMP2(ball_4_x,ball_4_y,ball_4_imagelocation,0);

		iShowBMP2(snake_x,snake_y,snake[snakeindex],0);
		/*if(snake_x <= 0)
		{
			go_left=false;
		}
		if(snake_x + 65 >= weight)
		{
			go_right=false;
		}*/
		


		//iShowBMP2(0,0,snake[35],0);
	}
	else if(game_state==1)
	{
		iShowBMP(0,0,end_menu_image);
		iSetColor(255,0,0);
		iText(472,575,point_str,GLUT_BITMAP_TIMES_ROMAN_24);

	}
	else if(game_state==2)
	{
		iSetColor(255,0,0);
		iText(343,313,point_str,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(game_state==3)
	{
		iSetColor(255,0,0);
		iText(343,313,point_str,GLUT_BITMAP_TIMES_ROMAN_24);
	}

	


}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{printf("x=%d  y=%d\n",mx,my);
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		if(mx >= 328 && mx <= 328 + box_weight && my >= 654 && my <= 654 + box_height)//end menu
		{
			game_state=-1;
		}
		else if(mx >= 328 && mx <= 328 + box_weight && my >= 558 && my <= 558 + box_height)//end score
		{
			game_state=-1;
		}
		else if(mx >= 328 && mx <= 328 + box_weight && my >= 464 && my <= 464 + box_height)//end exit
		{
			exit(0);
		}
		else if(mx >= 202 && mx <= 202 + box_weight && my >= 396 && my <= 396 + box_height)//start menu
		{
			game_state=0;
		}
		else if(mx >= 202 && mx <= 202 + box_weight && my >= 300 && my <= 300 + box_height)//start score
		{
			game_state=-1;
		}
		else if(mx >= 202 && mx <= 202 + box_weight && my >= 203 && my <= 203 + box_height)//start exit
		{
			exit(0);
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{    
		//place your codes here
		/*if(mx >= 202 && mx <= 202 + box_weight && my >= 404 && my <= 404 + box_height)
		{
			game_state=0;
		}*/

	}
}

/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == '0')
	{
		//do something with 'q'
		game_state=0;
	}
	else if(key == '1')
	{
		//do something with 'q'
		game_state=-1;
	}
	else if(key == '2')
	{game_state=1;
		//do something with 'q'
	}
		
	else if(key == '3')
	{
		game_state=2;
		//do something with 'q'
	}
		else if(key == '4')
	{
		game_state=3;
		//do something with 'q'
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	if(snake_x >=11)
	{
			if(key == GLUT_KEY_LEFT)
		{		
			snake_x-=15;				
		}
	}
	if(snake_x + snake_weight+10 <=weight)
	{
		if(key == GLUT_KEY_RIGHT)
		{
			snake_x+=15;
		}
	}
	//place your codes for other keys here
}

void collision_check()
{  // printf("collision_check =%d\n  " ,a++);
		if((ball_0_x +ball_0_image_weight > snake_x && ball_0_x < snake_x + snake_weight )&&(ball_0_y +ball_0_image_hight > snake_y && ball_0_y < snake_y + snake_height))
		{
			ball_0_y=-200;
			life++;
					sound();
			       
					sound();
					
			printf("life =%d point =%d\n  " ,life,point);

		}
		if((ball_5_x +ball_5_image_weight > snake_x && ball_5_x < snake_x + snake_weight )&&(ball_5_y +ball_5_image_hight > snake_y && ball_5_y < snake_y + snake_height))
		{
			ball_5_y=-200;
			life++;
			       sound();
				 
				sound();
					

		}
		if((ball_1_x +ball_1_image_weight > snake_x && ball_1_x < snake_x + snake_weight )&&(ball_1_y +ball_1_image_hight > snake_y && ball_1_y < snake_y + snake_height))
		{
			ball_1_y=-200;
			point++;
			life--;
			printf("life =%d point =%d\n  " ,life,point);
		}
		if((ball_2_x +ball_2_image_weight > snake_x && ball_2_x < snake_x + snake_weight )&&(ball_2_y +ball_2_image_hight > snake_y && ball_2_y < snake_y + snake_height))
		{
			ball_2_y=-200;
			point++;
			life--;
			printf("life =%d point =%d\n  " ,life,point);
		}
		if((ball_3_x +ball_3_image_weight > snake_x && ball_3_x < snake_x + snake_weight )&&(ball_3_y +ball_3_image_hight > snake_y && ball_3_y < snake_y + snake_height))
		{
			ball_3_y=-200;
			point++;
			life--;
			printf("life =%d point =%d\n  " ,life,point);
		}
		if((ball_4_x +ball_4_image_weight > snake_x && ball_4_x < snake_x + snake_weight )&&(ball_4_y +ball_4_image_hight > snake_y && ball_4_y < snake_y + snake_height))
		{
			ball_4_y=-200;
			point++;
			life--;
			printf("life =%d point =%d\n  " ,life,point);
		}
		
	}

void snake_movement()
	{
		snakeindex++;
		if(life >=9){if(snakeindex >= 3){snakeindex=0;}}

		else if(life==8){if(snakeindex >= 7){snakeindex=4;}}

		else if(life==7){if(snakeindex >= 11){snakeindex=8;}}

		else if(life==6){if(snakeindex >= 15){snakeindex=12;}}

		else if(life==5){if(snakeindex >= 19){snakeindex=16;}}

		else if(life==4){if(snakeindex >= 23){snakeindex=20;}}

		else if(life==3){if(snakeindex >= 27){snakeindex=24;}}

		else if(life==2){if(snakeindex >=31){snakeindex=28;}}

		else if(life==1){if(snakeindex >= 35){snakeindex=32;}}

		else if(life==0){game_state=1;}				
		
	}
void snake_speed()
{ 
	ball_0_speed+= 1;
	ball_1_speed+= 1;
	ball_2_speed+= 1;
	ball_3_speed+= 1;
	ball_4_speed+= 1;
	ball_5_speed+= 1;
}


int main()
{

	iSetTimer(25,collision_check);
    iSetTimer(250,snake_movement);
	 iSetTimer(10000,snake_speed);

	itoa(point,point_str,10);
	itoa(life,life_str,10);


	if(musicON){
	PlaySound("sound//background.wav", NULL, SND_LOOP|SND_ASYNC);
	}	

	iInitialize(weight, height, "snake");
	return 0;
}