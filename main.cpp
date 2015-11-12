#include "XnOs.h"

int main()
{
    XnOs obj;
    obj.initenv();
    start:
    switch(obj.paintmenu()){
		case 1: obj.reset();
		    obj.game();break;
		     //goto start;
		case 2:obj.rules(); 
		     goto start;
		case 3:obj.credits();
		    goto start;
		case 4:break;
		default:printw("hey..enter right choice..");getch();clear();
		     goto start;       
		 
	}
	 
    // getch();
    wclear(win);
     
    delwin(win);
    //getch();
	endwin();
	return 0;

}
