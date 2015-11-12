#ifndef XNOS_H
#define XNOS_H

#include<ncurses.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<cstdlib>

static int ci = 0;
static	WINDOW *win;

using namespace std;

class XnOs
{    

public:

	int p[7],pr1,pr2,pr3,pr4,pc1,pc2,pc3,pc4,pd1,pd2;
	int block1,block2,block3,block4,block5,block6,block7,block8,block9,block10;
	int c[7],cr1,cr2,cr3,cr4,cc1,cc2,cc3,cc4,cd1,cd2;

	int coor[4][4];

	int mode;

	XnOs()
	{ 
		pr1=0;pr2=0;pr3=0;pr4=0;pc1=0;pc2=0;pc3=0;pc4=0;pd1=0;pd2=0;
		block1=0;block2=0;block3=0;block4=0;block5=0;block6=0;block7=0;block8=0;block9=0;block10=0;
		cr1=0;cr2=0;cr3=0;cr4=0;cc1=0;cc2=0;cc3=0;cc4=0;cd1=0;cd2=0;
		int tmp[4][4] = {
			{11,12,13,14},
			{21,22,23,24},
			{31,32,33,34},
			{41,42,43,44}
     	};
     	for(int i=0;i<4;i++){
     		for(int j=0;j<4;j++){
     			this->coor[i][j]=tmp[i][j];
     		}
     	}

	}

	void game();
	void rules();
	void credits();
	void reset();
	void initenv();
	int paintmenu();
	int findmax();
	void computer();
	void displayplayer(int [],int);
	void displaycomputer(int [],int);

   ~XnOs()
   {
//	  fout.close(); 
   }
};

#endif

