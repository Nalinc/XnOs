#include<ncurses.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<cstdlib>
void game();
void rules();
void credits();
void reset();
int findmax();
void computer();
static int ci=0;
void displayplayer(int [],int);
void displaycomputer(int [],int);

int p[7],pr1=0,pr2=0,pr3=0,pr4=0,pc1=0,pc2=0,pc3=0,pc4=0,pd1=0,pd2=0;
int block1=0,block2=0,block3=0,block4=0,block5=0,block6=0,block7=0,block8=0,block9=0,block10=0;
int c[7],cr1=0,cr2=0,cr3=0,cr4=0,cc1=0,cc2=0,cc3=0,cc4=0,cd1=0,cd2=0;

int coor[4][4]={{11,12,13,14},
                 {21,22,23,24},
                 {31,32,33,34},
                 {41,42,43,44}};

 int mode;

int main()
{
	int sel;
	initscr();
	refresh();
	clear();
	WINDOW *win;
	win=newwin(20,20,40,40);
	move(0,0);
	start_color();
	init_pair(0,COLOR_WHITE,COLOR_BLACK);
	init_pair(1,COLOR_RED,COLOR_BLACK);
    init_pair(2,COLOR_BLUE,COLOR_BLACK);
    init_pair(3,COLOR_GREEN,COLOR_BLACK);
    init_pair(4,COLOR_CYAN,COLOR_BLACK);
    start:
	attron(COLOR_PAIR(0));

	
	printw("\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	attron(COLOR_PAIR(1));
	move(1,20);
	printw("\t\t\t   | Project 4-4-4 |\n");
	attroff(COLOR_PAIR(1));//use_default_colors();
	printw("\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	attron(COLOR_PAIR(2));
	printw("\n\n\n[Game Menu]\n\n");
     attroff(COLOR_PAIR(2));
    refresh();
    //use_default_colors();
	attron(COLOR_PAIR(3));
	printw("\n1)play\n2)rules\n3)credits\n4)quit\n");
    attroff(COLOR_PAIR(3));
    printw("\n\nenter your selection: ");
    scanw("%d",&sel);
    attroff(COLOR_PAIR(0));
     switch(sel)
     {
		 case 1: reset();
		         game();break;
		         //goto start;
		 case 2:rules(); 
		         goto start;
		 case 3:credits();
		        goto start;
		 case 4:break;
		 default:printw("hey..enter right choice..");getch();clear();
		         goto start;       
		 
	 }
	 
    // getch();
     wclear(win);
     
     //move(30,30);
     //printw("it works.");
     delwin(win);
     	//getch();
	endwin();
return 0;

}

void rules()
{
	clear();
	printw("\t\t\t\t\tProject 4-4-4 :\n\nRULES :\n\n");
	printw("- Project 4-4-4 is a 2 players game which is played on a 4x4 board.\n");
    printw("- one player has 8 crosses(X) & the other player has 8 zeroes (0)\n");
    printw("- each player can place the symbol in the cell alternatively.\n");

    printw("\n\nWINNING THE Game :\n");
    printw("- To win the game , player must create a line of 4 cells of their own symbol.\n");
    printw("- the first one to create a line ( horizontal, vrtical,diagonal) of atleast four cells of their\n   own symbol is the winner  of the game.\n");

    printw("\n\nDRAW RULES :\n");
printw("-  the game may end without a winner if all the cells are completely filled without either\n   player creating a line of 4.\n");


	printw("\n\n\n\n\t\t\tpress any key to return to main menu..");
	getch();
   clear(); 
}



void reset()
{
	pr1=0;pr2=0;pr3=0;pr4=0;pc1=0;pc2=0;pc3=0;pc4=0;pd1=0;pd2=0;
	cr1=0;cr2=0;cr3=0;cr4=0;cc1=0;cc2=0;cc3=0;cc4=0;cd1=0;cd2=0;
	ci=0;
	for(int i=0;i<7;i++)
	{		
			p[i]=0;
			c[i]=0;
			
	}
}


void game()
{
	int i,j,x,y;

	
clear();
   
	printw("select mode:\n\n1)Easy  2) Hard \n\n");
	scanw("%d",&mode);
	
//getch();
clear();

move(40,45);
printw("press '0000' if you want to quit ");	
move(5,20);
attron(COLOR_PAIR(3));
printw("current game");
attroff(COLOR_PAIR(3));
move(5,80);
attron(COLOR_PAIR(3));
printw("coordinates ");
attroff(COLOR_PAIR(3));


for(i=5;i<20;i++)
{
	move(i,55);
	printw("|");
}


attron(COLOR_PAIR(4));
for(i=10,j=8;i<=30&&j<=16;i+=4,j+=2)
{
	
	move(9,i);printw("|");
    move(11,i);printw("|");
    move(13,i);printw("|");
    move(15,i);printw("|");
    move(j,10);printw("-----------------");
    
    
 }   

for(i=71,j=8;i<=89&&j<=16;i+=4,j+=2)
{
	
	move(9,i);printw("|");
    move(11,i);printw("|");
    move(13,i);printw("|");
    move(15,i);printw("|");
    move(j,71);printw("-----------------");
    
    
 }   
 
 attroff(COLOR_PAIR(4));
 for(i=0,y=9;i<4&&y<=15;i++,y+=2)
{   x=0;
	for(j=0,x=72;j<4&&x<=88;j++,x+=4)
    {
	  move(y,x);printw("%d",coor[i][j]);	
	}
} 



move(22,0);
printw("player playing 'X':\n");

for(i=0;i<=7;i++)
{
	
move(23,0);
printw("enter your move:");
scanw("%d",&p[i]);
if(p[i]==0000)
break;
displayplayer(p,i);
if(pr1==4||pr2==4||pr3==4||pr4==4||pc1==4||pc2==4||pc3==4||pc4==4||pd1==4||pd2==4)
{move(23,0);
	printw("\t\t\n\nPLAYER WON  :) :) :)");
break;
}

move(23,0);
printw("\t\t  ");
move(23,0);

computer();
if(cr1==4||cr2==4||cr3==4||cr4==4||cc1==4||cc2==4||cc3==4||cc4==4||cd1==4||cd2==4)
{move(23,0);
	printw("\t\t\n\nCOMPUTER WON :( :( :(");
break;
}


}
	
getch();
clear();
}


void displayplayer(int p[7],int i)
{
if(p[i]==11)
{move(9,11);pr1++;pc1++;pd2++;}
else if(p[i]==12)
{move(9,15);pr1++;pc2++;}
else if(p[i]==13)
{move(9,19);pr1++;pc3++;}
else if(p[i]==14)
{move(9,23);pr1++;pc4++;pd1++;}
else if(p[i]==21)
{move(11,11);pr2++;pc1++;}
else if(p[i]==22)
{move(11,15);pr2++;pc2++;pd2++;}
else if(p[i]==23)
{move(11,19);pr2++;pc3++;pd1++;}
else if(p[i]==24)
{move(11,23);pr2++;pc4++;}
else if(p[i]==31)
{move(13,11);pr3++;pc1++;}
else if(p[i]==32)
{move(13,15);pr3++;pc2++;pd1++;}
else if(p[i]==33)
{move(13,19);pr3++;pc3++;pd2++;}
else if(p[i]==34)
{move(13,23);pr3++;pc4++;}
else if(p[i]==41)
{move(15,11);pr4++;pc1++;pd1++;}
else if(p[i]==42)
{move(15,15);pr4++;pc2++;}
else if(p[i]==43)
{move(15,19);pr4++;pc3++;}
else if(p[i]==44)
{move(15,23);pr4++;pc4++;pd2++;}

attron(COLOR_PAIR(2));
printw("X");
attroff(COLOR_PAIR(2));
	
}

void computer()
{
	int max;
int coor[]={11,12,13,14,21,22,23,24,31,32,33,34,41,42,43,44};

	int j;
	int buf;
	

if(mode==2)
{
	int dia[]={41,32,23,14,11,22,33,44};
	int cols[]={11,21,31,41,12,22,32,42,13,23,33,43,14,24,34,44};
	max=findmax();
    
    if(max==pr1&&block1!=1)
    {
	 l1:
	 
	 srand(time(NULL));     
	 buf=rand();            
	 buf=(buf%4);              	
		for(j=0;j<7;j++)
		{if(coor[buf]==p[j])
		goto l1;
		if(coor[buf]==c[j])
		goto l1;	
		}
	c[ci]=coor[buf];
	displaycomputer(coor,buf);
	goto last;	
	}
    else if(max==pr2&&block2!=1)
    {
	l2:
	
	 srand(time(NULL));     
	 buf=rand();            
	 buf=(buf%4+4);              	
		for(j=0;j<7;j++)
		{if(coor[buf]==p[j])
		goto l2;
		if(coor[buf]==c[j])
		goto l2;	
		}
	c[ci]=coor[buf];	
	displaycomputer(coor,buf);
	goto last;
	}
    else if(max==pr3&&block3!=1)
    {
	l3:
	
	srand(time(NULL));     
	 buf=rand();            
	 buf=(buf%4+8);              	
		for(j=0;j<7;j++)
		{if(coor[buf]==p[j])
		goto l3;
		if(coor[buf]==c[j])
		goto l3;	
		}
	c[ci]=coor[buf];	
	displaycomputer(coor,buf);
	goto last;
	}
    else if(max==pr4&&block4!=1)
    {
	l4:
	
	srand(time(NULL));     
	 buf=rand();            
	 buf=(buf%4+12);              	
		for(j=0;j<7;j++)
		{if(coor[buf]==p[j])
		goto l4;
		if(coor[buf]==c[j])
		goto l4;	
		}
	c[ci]=coor[buf];	
	displaycomputer(coor,buf);
	goto last;
	}
    else if(max==pc1&&block5!=1)
    {
	l5:
	
	 srand(time(NULL));     
	 buf=rand();            
	 buf=(buf%4);              	
		for(j=0;j<7;j++)
		{if(cols[buf]==p[j])
		goto l5;
		if(cols[buf]==c[j])
		goto l5;	
		}
	c[ci]=cols[buf];	
	displaycomputer(cols,buf);
	goto last;
	}
    else if(max==pc2&&block6!=1)
    {
	l6:
	
	srand(time(NULL));     
	 buf=rand();            
	 buf=(buf%4+4);              	
		for(j=0;j<7;j++)
		{if(cols[buf]==p[j])
		goto l6;
		if(cols[buf]==c[j])
		goto l6;	
		}
	c[ci]=cols[buf];	
	displaycomputer(cols,buf);
	goto last;
	}
    else if(max==pc3&&block7!=1)
    {
	l7:
	
	srand(time(NULL));     
	 buf=rand();            
	 buf=(buf%4+8);              	
		for(j=0;j<7;j++)
		{if(cols[buf]==p[j])
		goto l7;
		if(cols[buf]==c[j])
		goto l7;	
		}
	c[ci]=cols[buf];	
	displaycomputer(cols,buf);
	goto last;
	}
    else if(max==pc4&&block8!=1)
    {
	l8:
	
	 srand(time(NULL));     
	 buf=rand();            
	 buf=(buf%4+12);              	
		for(j=0;j<7;j++)
		{if(cols[buf]==p[j])
		goto l8;
		if(cols[buf]==c[j])
		goto l8;	
		}
	c[ci]=cols[buf];	
	displaycomputer(cols,buf);
	goto last;
	}
    else if(max==pd1&&block9!=1)
    {
	l9:
	
	srand(time(NULL));     
	 buf=rand();            
	 buf=(buf%4);              	
		for(j=0;j<7;j++)
		{if(dia[buf]==p[j])
		goto l9;
		if(dia[buf]==c[j])
		goto l9;	
		}
	c[ci]=dia[buf];	
	displaycomputer(dia,buf);
	goto last;
	}
    else if(max==pd2&&block10!=1)
    {
	l10:
	
	srand(time(NULL));     
	 buf=rand();            
	 buf=(buf%4+4);              	
		for(j=0;j<7;j++)
		{if(dia[buf]==p[j])
		goto l10;
		if(dia[buf]==c[j])
		goto l10;	
		}
	c[ci]=dia[buf];	
	displaycomputer(dia,buf);
	goto last;
	}
    
	
}


//mode1->easy
else
{	
	l:
	//RANDOM NUMBER GENERATOR
	srand(time(NULL));      //  CHECK CODE IN THESE 3 LINES
	buf=rand();             //   COMPUTER IS SELECTING RANDOM NUMBERS FROM FIRST ROW ONLY.
	buf=(buf%16);            //     AND IT GETS CONFUSED ONCE THE UPPER PORTION   :/
	                        //    OF MATRIX GETS DENSE..
    	
	for(j=0;j<7;j++)
	{
		if(coor[buf]==p[j])
	   {
	    goto l;
           }		
	   
	    if(coor[buf]==c[j])
	    {
		  goto l;	
		}
	
	}
c[ci]=coor[buf];
displaycomputer(coor,buf);
}
	
	
		
	last:	
	
	ci++;
		
		
	}
	
	

void displaycomputer(int p[7],int i)
{
if(p[i]==11)
{move(9,11);cr1++;cc1++;cd2++;}
else if(p[i]==12)
{move(9,15);cr1++;cc2++;}
else if(p[i]==13)
{move(9,19);cr1++;cc3++;}
else if(p[i]==14)
{move(9,23);cr1++;cc4++;cd1++;}
else if(p[i]==21)
{move(11,11);cr2++;cc1++;}
else if(p[i]==22)
{move(11,15);cr2++;cc2++;cd2++;}
else if(p[i]==23)
{move(11,19);cr2++;cc3++;cd1++;}
else if(p[i]==24)
{move(11,23);cr2++;cc4++;}
else if(p[i]==31)
{move(13,11);cr3++;cc1++;}
else if(p[i]==32)
{move(13,15);cr3++;cc2++;cd1++;}
else if(p[i]==33)
{move(13,19);cr3++;cc3++;cd2++;}
else if(p[i]==34)
{move(13,23);cr3++;cc4++;}
else if(p[i]==41)
{move(15,11);cr4++;cc1++;cd1++;}
else if(p[i]==42)
{move(15,15);cr4++;cc2++;}
else if(p[i]==43)
{move(15,19);cr4++;cc3++;}
else if(p[i]==44)
{move(15,23);cr4++;cc4++;cd2++;}

attron(COLOR_PAIR(1));
printw("0");
attroff(COLOR_PAIR(1));	
}


int findmax()
{
    int max=0,maxc=0,maxr=0,maxd=0;

if(pr1+cr1==4){block1=1;pr1=0;}
if(pr2+cr2==4){block2=1;pr2=0;}
if(pr3+cr3==4){block3=1;pr3=0;}
if(pr4+cr4==4){block4=1;pr4=0;}
if(pc1+cc1==4){block5=1;pc1=0;}
if(pc2+cc2==4){block6=1;pc2=0;}
if(pc3+cc3==4){block7=1;pc3=0;}
if(pc4+cc4==4){block8=1;pc4=0;}
if(pd1+cd1==4){block9=1;pd1=0;}
if(pd2+cd2==4){block10=1;pd2=0;}


	
	if(pr1>=pr2&&pr1>=pr3&&pr1>=pr4&&block1!=1)
		maxr=pr1;
	else if(pr2>=pr1&&pr2>=pr3&&pr2>=pr4&&block2!=1)
		maxr=pr2;	
	else if(pr3>=pr1&&pr3>=pr2&&pr3>=pr4&&block3!=1)
		maxr=pr3;
	else if(pr4>=pr1&&pr4>=pr2&&pr4>=pr3&&block4!=1)
		maxr=pr4;
		
	if(pc1>=pc2&&pc1>=pc3&&pc1>=pc4&&block5!=1)
		maxc=pc1;
	else if(pc2>=pc1&&pc2>=pc3&&pc2>=pc4&&block6!=1)
		maxc=pc2;
	else if(pc3>=pc1&&pc3>=pc2&&pc3>=pc4&&block7!=1)
		maxc=pc3;
    else if(pc4>=pc1&&pc4>=pc2&&pc4>=pc3&&block8!=1)
		maxc=pc4;
				
	if(pd1>=pd2&&block9!=1)
	    maxd=pd1;
	else if(pd2>=pd1&&block10!=1)
	    maxd=pd2;    	

if(maxr>=maxd&&maxr>=maxc)max=maxr;
else if(maxd>=maxr&&maxd>=maxc)max=maxd;
else if(maxc>=maxr&&maxc>=maxd)max=maxc;


return max;
}


void credits()
{
	clear();
	printw("\n\n\t\t\t\t\t   Game Developed by:\n\n\n");
	printw("\n\n\n\t\t\t\t\t\tNalin Chhibber \n\n");
	printw("\t\t\t\t\t     CSE 2nd Year,  MSIT");
	getch();
	clear();
}
