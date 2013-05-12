#include <curses.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/types.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) < (b) ? (b) : (a))
void blocuri(int *s,int *bx, int *by, int tip , int color , int *gata , char v[50][50], int *nomove )  // Functie care realizeaza miscarea in jos a blocurile precum si 
{     												// oprirea lor daca intalnesc un obstacol 											
     attron(COLOR_PAIR(color));
    if (tip==0) { 
		if (*bx==26 || v[*bx+1][*by]!=' ' || v[*bx+1][*by+1]!=' ' ) {*gata=1; v[*bx][*by]='0'+color; v[*bx][*by+1]='0'+color; v[*bx-1][*by]='0'+color; v[*bx-1][*by+1]='0'+color;} else
		if (*s==1) {mvaddstr(*bx,*by,"HH"); refresh(); *s=*s+1; *bx=*bx+1; } else
		if (*s==2) {mvaddstr(*bx,*by,"HH"); *s=*s+1; refresh(); *nomove=0;} else 
		if (*s>=3) {attrset(COLOR_PAIR(7)); mvaddstr(*bx-1,*by,"  "); attrset(COLOR_PAIR(color)); mvaddstr(*bx+1,*by,"HH"); refresh(); *bx=*bx+1; *by=*by; }
			
		   
		  }
    if (tip==1) { if (*bx==26 || v[*bx+1][*by]!=' ' || v[*bx+1][*by+1]!=' ' || v[*bx+1][*by+2]!=' ' || v[*bx+1][*by+3]!=' ' ) 
				{*gata=1; v[*bx][*by]='0'+color; v[*bx][*by+1]='0'+color; v[*bx][*by+2]='0'+color; v[*bx][*by+3]='0'+color;} 
				else if (*s==1) {mvaddstr(*bx,*by,"HHHH"); *s=*s+1;*nomove=0;}
			else {attrset(COLOR_PAIR(7)); mvaddstr(*bx,*by,"    "); attrset(COLOR_PAIR(color)); mvaddstr(*bx+1,*by,"HHHH"); *bx=*bx+1; }
		  }
	if (tip==2) { if (*bx==26 || v[*bx+1][*by]!=' '  ) 
				{*gata=1; v[*bx][*by]='0'+color; v[*bx-1][*by]='0'+color; v[*bx-2][*by]='0'+color; v[*bx-3][*by]='0'+color;} 
				else 
			if (*s==1) {mvaddstr(*bx,*by,"H"); *s=*s+1; } else
			  if (*s==2) {mvaddstr(*bx+1,*by,"H"); *s=*s+1; *bx=*bx+1;} else
		  		if (*s==3) {mvaddstr(*bx+1,*by,"H"); *s=*s+1; *bx=*bx+1;} else
				   if (*s==4) {mvaddstr(*bx+1,*by,"H"); *s=*s+1; *bx=*bx+1;*nomove=0;} else 
					if (*s>4) {mvaddstr(*bx+1,*by,"H"); attrset(COLOR_PAIR(7)); mvaddstr(*bx-3,*by," "); attrset(COLOR_PAIR(color)); *bx=*bx+1;}	
		     }
	if (tip==3) {   if (*bx==26 || v[*bx+1][*by]!=' ' || v[*bx+1][*by+1]!=' ' || v[*bx][*by+2]!=' ' ) 
				{*gata=1; v[*bx][*by]='0'+color; v[*bx][*by+1]='0'+color; v[*bx-1][*by+1]='0'+color; v[*bx-1][*by+2]='0'+color; } else
			if (*s==1) {mvaddstr(*bx,*by,"HH"); *s=*s+1; } else
			if (*s==2)  {attrset(COLOR_PAIR(7));mvaddstr(*bx,*by," ");attrset(COLOR_PAIR(color)); mvaddstr(*bx,*by+1,"HH"); mvaddstr(*bx+1,*by,"HH"); *s=*s+1; *bx=*bx+1;*nomove=0;} else
			 if (*s>=3) {attrset(COLOR_PAIR(7)); mvaddstr(*bx-1,*by,"   ");mvaddstr(*bx,*by," "); attrset(COLOR_PAIR(color)); mvaddstr(*bx,*by+1,"HH"); mvaddstr(*bx+1,*by,"HH");*bx=*bx+1;} 
			}
	if (tip==4) {	if (*bx==26 || v[*bx+1][*by+1]!=' ' || v[*bx][*by]!=' ' ) 
				{*gata=1; v[*bx][*by+1]='0'+color; v[*bx-1][*by+1]='0'+color; v[*bx-1][*by]='0'+color; v[*bx-2][*by]='0'+color; } else
			if (*s==1) {mvaddstr(*bx,*by+1,"H"); *s=*s+1; } else
			if (*s==2)  {mvaddstr(*bx,*by,"HH"); mvaddstr(*bx+1,*by+1,"H"); *s=*s+1;} else
			 if (*s==3) {mvaddstr(*bx,*by,"H");attrset(COLOR_PAIR(7));mvaddstr(*bx,*by+1," ");attrset(COLOR_PAIR(color));mvaddstr(*bx+1,*by,"HH"); mvaddstr(*bx+2,*by+1,"H");*bx=*bx+2; *s=*s+1;*nomove=0;} else
			  if (*s==4) {attrset(COLOR_PAIR(7));mvaddstr(*bx-2,*by," ");attrset(COLOR_PAIR(color));mvaddstr(*bx-1,*by,"H"); attrset(COLOR_PAIR(7)); mvaddstr(*bx-1,*by+1," ");attrset(COLOR_PAIR(color)); 
					 mvaddstr(*bx,*by,"HH");mvaddstr(*bx+1,*by+1,"H");*bx=*bx+1;} 
		      	
			}
	if (tip==5) {   if (*bx==26 || v[*bx+1][*by+1]!=' ' || v[*bx+1][*by+2]!=' ' || v[*bx][*by]!=' ' ) 
				{*gata=1; v[*bx][*by+1]='0'+color; v[*bx][*by+2]='0'+color; v[*bx-1][*by+1]='0'+color; v[*bx-1][*by]='0'+color; } else
			if (*s==1) {attrset(COLOR_PAIR(7)); mvaddstr(*bx,*by," "); attrset(COLOR_PAIR(color));mvaddstr(*bx,*by+1,"HH"); *s=*s+1; } else
			if (*s==2)  {attrset(COLOR_PAIR(7));mvaddstr(*bx,*by+2," "); mvaddstr(*bx+1,*by," ");attrset(COLOR_PAIR(color)); mvaddstr(*bx,*by,"HH"); mvaddstr(*bx+1,*by+1,"HH"); *s=*s+1; *bx=*bx+1;*nomove=0;} else
			 if (*s>=3) {attrset(COLOR_PAIR(7));mvaddstr(*bx-1,*by,"   ");mvaddstr(*bx,*by+2," "); attrset(COLOR_PAIR(color)); mvaddstr(*bx,*by,"HH"); mvaddstr(*bx+1,*by+1,"HH");*bx=*bx+1;} 
			}
	if (tip==6) {	if (*bx==26 || v[*bx+1][*by]!=' ' || v[*bx][*by+1]!=' ' ) 
				{*gata=1; v[*bx][*by]='0'+color; v[*bx-1][*by+1]='0'+color; v[*bx-1][*by]='0'+color; v[*bx-2][*by+1]='0'+color; } else
			if (*s==1) {mvaddstr(*bx,*by,"H"); *s=*s+1; } else
			if (*s==2)  {mvaddstr(*bx,*by,"HH"); mvaddstr(*bx+1,*by,"H"); *s=*s+1;} else
			 if (*s==3) {attrset(COLOR_PAIR(7));mvaddstr(*bx,*by," ");attrset(COLOR_PAIR(color)); mvaddstr(*bx,*by+1,"H");mvaddstr(*bx+1,*by,"HH"); mvaddstr(*bx+2,*by,"H");*bx=*bx+2; *s=*s+1;*nomove=0;} else
			  if (*s==4) {attrset(COLOR_PAIR(7)); mvaddstr(*bx-2,*by+1," ");mvaddstr(*bx-1,*by," "); attrset(COLOR_PAIR(color)); mvaddstr(*bx,*by+1,"H");mvaddstr(*bx+1,*by,"H");*bx=*bx+1;} 
		      	}
	if (tip==7) { if (*bx==26 || v[*bx+1][*by]!=' ' || v[*bx][*by+1]!=' ' || v[*bx][*by+2]!=' '  ) 
				{*gata=1; v[*bx][*by]='0'+color; v[*bx-1][*by]='0'+color; v[*bx-1][*by+1]='0'+color; v[*bx-1][*by+2]='0'+color;} 
				else 
			if (*s==1) {mvaddstr(*bx,*by,"H"); *s=*s+1; } else
			  if (*s==2) {mvaddstr(*bx+1,*by,"H");mvaddstr(*bx,*by,"HHH"); *s=*s+1; *bx=*bx+1;*nomove=0;} else
		  		if (*s==3) {attrset(COLOR_PAIR(7)); mvaddstr(*bx-1,*by,"   "); attrset(COLOR_PAIR(color)); mvaddstr(*bx+1,*by,"H");mvaddstr(*bx,*by,"HHH");*bx=*bx+1;}
		     }
	if (tip==8) { if (*bx==26 || v[*bx+1][*by]!=' ' || v[*bx+1][*by+1]!=' '   ) 
				{*gata=1; v[*bx][*by]='0'+color; v[*bx][*by+1]='0'+color; v[*bx-1][*by]='0'+color; v[*bx-2][*by]='0'+color;} 
				else 
			if (*s==1) {mvaddstr(*bx,*by,"HH"); *s=*s+1; } else
			  if (*s==2) {mvaddstr(*bx+1,*by,"HH");attrset(COLOR_PAIR(7));mvaddstr(*bx,*by+1," ");attrset(COLOR_PAIR(color)); *s=*s+1; } else
			  if (*s==3) {mvaddstr(*bx+2,*by,"HH");attrset(COLOR_PAIR(7)); mvaddstr(*bx+1,*by+1," "); attrset(COLOR_PAIR(color)); *s=*s+1; *bx=*bx+2; *nomove=0; } else
		  		if (*s==4) {attrset(COLOR_PAIR(7)); mvaddstr(*bx-2,*by," "); mvaddstr(*bx,*by+1," ");attrset(COLOR_PAIR(color)); mvaddstr(*bx+1,*by,"HH");*bx=*bx+1;}
		     }
	if (tip==9) { if (*bx==26 || v[*bx+1][*by]!=' ' || v[*bx+1][*by+1]!=' ' || v[*bx+1][*by+2]!=' '  ) 
				{*gata=1; v[*bx][*by]='0'+color; v[*bx][*by+1]='0'+color; v[*bx][*by+2]='0'+color; v[*bx-1][*by+2]='0'+color;} 
				else 
			if (*s==1) {mvaddstr(*bx,*by,"HHH"); *s=*s+1; } else
			  if (*s==2) {mvaddstr(*bx+1,*by,"HHH");mvaddstr(*bx,*by+2,"H"); attrset(COLOR_PAIR(7)); mvaddstr(*bx,*by," "); mvaddstr(*bx,*by+1," ");  attrset(COLOR_PAIR(color)); *s=*s+1; *bx=*bx+1;*nomove=0;} else
		  		if (*s==3) {attrset(COLOR_PAIR(7));mvaddstr(*bx-1,*by+2," "); mvaddstr(*bx,*by,"  ");attrset(COLOR_PAIR(color));mvaddstr(*bx+1,*by,"HHH");*bx=*bx+1;}
		     }
	if (tip==10) { if (*bx==26 || v[*bx+1][*by+1]!=' ' || v[*bx-1][*by]!=' '   ) 
				{*gata=1; v[*bx][*by+1]='0'+color; v[*bx-1][*by]='0'+color; v[*bx-2][*by+1]='0'+color; v[*bx-2][*by]='0'+color;} 
				else 
			if (*s==1) {mvaddstr(*bx,*by+1,"H"); *s=*s+1; } else
			  if (*s==2) {mvaddstr(*bx+1,*by+1,"H"); *s=*s+1;} else
			   if (*s==3) {mvaddstr(*bx+2,*by+1,"H");mvaddstr(*bx,*by,"H"); *s=*s+1; *bx=*bx+2;*nomove=0;} else
		  		if (*s==4) {attrset(COLOR_PAIR(7)); mvaddstr(*bx-2,*by,"  "); attrset(COLOR_PAIR(color)); mvaddstr(*bx-1,*by,"H");mvaddstr(*bx+1,*by+1,"H");*bx=*bx+1;}
		     }
	if (tip==11) { if (*bx==26 || v[*bx+1][*by+2]!=' ' || v[*bx][*by+1]!=' ' || v[*bx][*by]!=' '  ) 
				{*gata=1; v[*bx][*by+2]='0'+color; v[*bx-1][*by]='0'+color; v[*bx-1][*by+1]='0'+color; v[*bx-1][*by+2]='0'+color;} 
				else 
			if (*s==1) {mvaddstr(*bx,*by+2,"H"); *s=*s+1; } else
			  if (*s==2) {mvaddstr(*bx+1,*by+2,"H");mvaddstr(*bx,*by,"HH"); *s=*s+1; *bx=*bx+1;*nomove=0;} else
		  		if (*s==3) {attrset(COLOR_PAIR(7)); mvaddstr(*bx-1,*by,"   "); attrset(COLOR_PAIR(color)); mvaddstr(*bx+1,*by+2,"H");mvaddstr(*bx,*by,"HH");*bx=*bx+1;}
		     }
	if (tip==12) { if (*bx==26 || v[*bx+1][*by]!=' ' || v[*bx-1][*by+1]!=' '   ) 
				{*gata=1; v[*bx][*by]='0'+color; v[*bx-1][*by]='0'+color; v[*bx-2][*by+1]='0'+color; v[*bx-2][*by]='0'+color;} 
				else 
			if (*s==1) {mvaddstr(*bx,*by,"H"); *s=*s+1; } else
			  if (*s==2) {mvaddstr(*bx+1,*by,"H"); *s=*s+1; } else
				if (*s==3) {mvaddstr(*bx+2,*by,"H");mvaddstr(*bx,*by+1,"H"); *s=*s+1; *bx=*bx+2; *nomove=0;} else
		  		if (*s==4) {attrset(COLOR_PAIR(7)); mvaddstr(*bx-2,*by,"  "); attrset(COLOR_PAIR(color));  mvaddstr(*bx-1,*by+1,"H");mvaddstr(*bx+1,*by,"H");*bx=*bx+1;}
		     }
	if (tip==13) { if (*bx==26 || v[*bx+1][*by]!=' ' || v[*bx+1][*by+1]!=' ' || v[*bx+1][*by+2]!=' '  ) 
				{*gata=1; v[*bx][*by]='0'+color; v[*bx][*by+1]='0'+color; v[*bx][*by+2]='0'+color; v[*bx-1][*by]='0'+color;} 
				else 
			if (*s==1) {mvaddstr(*bx,*by,"HHH"); *s=*s+1; } else
			  if (*s==2) {mvaddstr(*bx+1,*by,"HHH");mvaddstr(*bx,*by,"H");attrset(COLOR_PAIR(7)); mvaddstr(*bx,*by+1,"  "); attrset(COLOR_PAIR(color)); *s=*s+1; *bx=*bx+1;*nomove=0;} else
		  		if (*s==3) {attrset(COLOR_PAIR(7)); mvaddstr(*bx-1,*by," "); attrset(COLOR_PAIR(color)); mvaddstr(*bx+1,*by,"HHH");
mvaddstr(*bx,*by,"H"); attrset(COLOR_PAIR(7)); mvaddstr(*bx,*by+1," ");mvaddstr(*bx,*by+2," "); attrset(COLOR_PAIR(color)); *bx=*bx+1;}
		     }
	if (tip==14) { if (*bx==26 || v[*bx+1][*by]!=' ' || v[*bx+1][*by+1]!=' ') 
				{*gata=1; v[*bx][*by]='0'+color; v[*bx][*by+1]='0'+color; v[*bx-1][*by+1]='0'+color; v[*bx-2][*by+1]='0'+color;} 
				else 
			if (*s==1) {mvaddstr(*bx,*by,"HH"); *s=*s+1; } else
			  if (*s==2) {mvaddstr(*bx+1,*by,"HH");attrset(COLOR_PAIR(7));mvaddstr(*bx,*by," ");attrset(COLOR_PAIR(color));  *s=*s+1;} else
			    if (*s==3) {mvaddstr(*bx+2,*by,"HH");attrset(COLOR_PAIR(7));mvaddstr(*bx+1,*by," "); attrset(COLOR_PAIR(color));*s=*s+1; *bx=*bx+2;*nomove=0;} else
		  		if (*s==4) {attrset(COLOR_PAIR(7)); mvaddstr(*bx,*by," "); mvaddstr(*bx-2,*by+1," ");attrset(COLOR_PAIR(color));mvaddstr(*bx+1,*by,"HH");*bx=*bx+1;}
		     }
	if (tip==15) { if (*bx==26 || v[*bx+1][*by+1]!=' ' || v[*bx][*by]!=' ' || v[*bx][*by+2]!=' '  ) 
				{*gata=1; v[*bx][*by+1]='0'+color; v[*bx-1][*by]='0'+color; v[*bx-1][*by+1]='0'+color; v[*bx-1][*by+2]='0'+color;} 
				else 
			if (*s==1) {mvaddstr(*bx,*by+1,"H"); *s=*s+1; } else
			  if (*s==2) {mvaddstr(*bx+1,*by+1,"H");mvaddstr(*bx,*by,"HHH"); *s=*s+1; *bx=*bx+1;*nomove=0;} else
		  		if (*s==3) {attrset(COLOR_PAIR(7)); mvaddstr(*bx-1,*by,"   ");attrset(COLOR_PAIR(color)); mvaddstr(*bx+1,*by+1,"H");mvaddstr(*bx,*by,"HHH");*bx=*bx+1;}
		     }
	if (tip==16) { if (*bx==26 || v[*bx+1][*by]!=' ' || v[*bx][*by+1]!=' ') 
				{*gata=1; v[*bx][*by]='0'+color; v[*bx-1][*by]='0'+color; v[*bx-1][*by+1]='0'+color; v[*bx-2][*by]='0'+color;} 
				else 
			if (*s==1) {mvaddstr(*bx,*by,"H"); *s=*s+1; } else
			  if (*s==2) {mvaddstr(*bx+1,*by,"H");mvaddstr(*bx,*by,"HH"); *s=*s+1; } else
				if (*s==3) {mvaddstr(*bx+2,*by,"H");mvaddstr(*bx,*by,"H");attrset(COLOR_PAIR(7)); 
						mvaddstr(*bx,*by+1," "); mvaddstr(*bx+1,*by+2," ");attrset(COLOR_PAIR(color));
						mvaddstr(*bx+1,*by+1,"H"); *s=*s+1; *bx=*bx+2;*nomove=0;} else
		  		if (*s==4) {attrset(COLOR_PAIR(7)); mvaddstr(*bx-2,*by," "); mvaddstr(*bx-1,*by+1," ");attrset(COLOR_PAIR(color));  
						mvaddstr(*bx+1,*by,"H");mvaddstr(*bx,*by+1,"H");*bx=*bx+1;}
		     }
	if (tip==17) { if (*bx==26 || v[*bx+1][*by+1]!=' ' || v[*bx+1][*by+2]!=' ' || v[*bx+1][*by]!=' '  ) 
				{*gata=1; v[*bx][*by]='0'+color; v[*bx][*by+1]='0'+color; v[*bx][*by+2]='0'+color; v[*bx-1][*by+1]='0'+color;} 
				else 
			if (*s==1) {mvaddstr(*bx,*by,"HHH"); *s=*s+1; } else
			  if (*s==2) {mvaddstr(*bx+1,*by,"HHH");attrset(COLOR_PAIR(7)); mvaddstr(*bx,*by," ");mvaddstr(*bx,*by+2," "); attrset(COLOR_PAIR(color)); mvaddstr(*bx,*by+1,"H"); *s=*s+1; *bx=*bx+1;*nomove=0;} else

		  		if (*s==3) {attrset(COLOR_PAIR(7)); mvaddstr(*bx-1,*by+1," "); attrset(COLOR_PAIR(color)); mvaddstr(*bx+1,*by,"HHH");attrset(COLOR_PAIR(7)); mvaddstr(*bx,*by," ");mvaddstr(*bx,*by+2," "); attrset(COLOR_PAIR(color));*bx=*bx+1;}
		     }
	if (tip==18) { if (*bx==26 || v[*bx+1][*by+1]!=' ' || v[*bx][*by]!=' ') 
				{*gata=1; v[*bx][*by+1]='0'+color; v[*bx-1][*by]='0'+color; v[*bx-1][*by+1]='0'+color; v[*bx-2][*by+1]='0'+color;} 
				else 
			if (*s==1) {mvaddstr(*bx,*by+1,"H"); *s=*s+1; } else
			  if (*s==2) {mvaddstr(*bx+1,*by+1,"H");mvaddstr(*bx,*by,"H"); *s=*s+1;} else
				if (*s==3) {mvaddstr(*bx+2,*by+1,"H");attrset(COLOR_PAIR(7)); mvaddstr(*bx,*by," ");attrset(COLOR_PAIR(color));
						mvaddstr(*bx+1,*by,"H"); *s=*s+1; *bx=*bx+2;*nomove=0;} else
		  		if (*s==4) {attrset(COLOR_PAIR(7)); mvaddstr(*bx-2,*by+1," ");mvaddstr(*bx-1,*by," "); attrset(COLOR_PAIR(color)); mvaddstr(*bx+1,*by+1,"H");mvaddstr(*bx,*by,"H");*bx=*bx+1;}
		     }
	attroff(COLOR_PAIR(color));
}  	 
void sgt(int x, int row , int col)
{
   attron(COLOR_PAIR(9));
   mvaddstr(x,col,  "     ");
    	
   mvaddstr(row,col,"---->");
   attroff(COLOR_PAIR(9));
	refresh();
}
void mdreapta(int *bx, int *by ,int tip , int color , char v[50][50], int *gata)//Mutarea la Dreapta a pieselor.
{
	attron(COLOR_PAIR(color));
	if (tip==0) { 
			if (v[*bx-1][*by+2]==' ' && v[*bx][*by+2]==' ') { attrset(COLOR_PAIR(7));mvaddstr(*bx-1,*by," ");mvaddstr(*bx,*by," ");attrset(COLOR_PAIR(color));mvaddstr(*bx-1,*by+2,"H");mvaddstr(*bx,*by+2,"H");
									  *by=*by+1; refresh();}
			 }
	if (tip==1) { 
		      if (v[*bx][*by+4]==' ') { attrset(COLOR_PAIR(7));mvaddstr(*bx,*by," "); attrset(COLOR_PAIR(color)); mvaddstr(*bx,*by+4,"H"); *by=*by+1; }
		  
			}
	if (tip==2) { 
			if (v[*bx][*by+1]==' ' && v[*bx-1][*by+1]==' ' && v[*bx-2][*by+1]==' ' && v[*bx-3][*by+1]==' ') 
					{ attrset(COLOR_PAIR(7));mvaddstr(*bx,*by," "); mvaddstr(*bx-1,*by," "); mvaddstr(*bx-2,*by," "); mvaddstr(*bx-3,*by," ");attrset(COLOR_PAIR(color)); 
					 mvaddstr(*bx,*by+1,"H"); mvaddstr(*bx-1,*by+1,"H"); mvaddstr(*bx-2,*by+1,"H"); mvaddstr(*bx-3,*by+1,"H"); 
					*by=*by+1; }
			}
	if (tip==3) { if (v[*bx][*by+2]==' ' && v[*bx-1][*by+3]==' ') {attrset(COLOR_PAIR(7));mvaddstr(*bx,*by," ");mvaddstr(*bx-1,*by+1," "); attrset(COLOR_PAIR(color));
									mvaddstr(*bx,*by+2,"H");mvaddstr(*bx-1,*by+3,"H"); *by=*by+1;}
			}	
	if (tip==4) { if (v[*bx][*by+2]==' ' && v[*bx-1][*by+2]==' ') 
			{attrset(COLOR_PAIR(7));mvaddstr(*bx-2,*by," ");mvaddstr(*bx,*by+1," ");mvaddstr(*bx-1,*by," "); attrset(COLOR_PAIR(color));
			 mvaddstr(*bx,*by+2,"H"); mvaddstr(*bx-2,*by+1,"H");mvaddstr(*bx-1,*by+2,"H"); *by=*by+1;}
			} 	
	if (tip==5) { if (v[*bx][*by+3]==' ' && v[*bx-1][*by+2]==' ') {attrset(COLOR_PAIR(7));mvaddstr(*bx,*by+1," ");mvaddstr(*bx-1,*by," ");attrset(COLOR_PAIR(color));
									mvaddstr(*bx,*by+3,"H");mvaddstr(*bx-1,*by+2,"H"); *by=*by+1;}
			}	
	if (tip==6) { if (v[*bx-2][*by+2]==' ' && v[*bx-1][*by+2]==' ') 
			{attrset(COLOR_PAIR(7));mvaddstr(*bx-2,*by+1," ");mvaddstr(*bx,*by," ");mvaddstr(*bx-1,*by," ");attrset(COLOR_PAIR(color));
			 mvaddstr(*bx,*by+1,"H"); mvaddstr(*bx-2,*by+2,"H");mvaddstr(*bx-1,*by+2,"H"); *by=*by+1;}
	 		}
		     
	if (tip==7) { if (v[*bx-1][*by+3]==' ') {attrset(COLOR_PAIR(7)); mvaddstr(*bx,*by," "); mvaddstr(*bx-1,*by," "); attrset(COLOR_PAIR(color)); mvaddstr(*bx,*by+1,"H"); mvaddstr(*bx-1,*by+3,"H"); *by=*by+1;} }
	if (tip==8) { if (v[*bx][*by+2]==' ') { attrset(COLOR_PAIR(7)); mvaddstr(*bx,*by," "); mvaddstr(*bx-1,*by," "); mvaddstr(*bx-2,*by," ");attrset(COLOR_PAIR(color)); mvaddstr(*bx,*by+2,"H");
						 mvaddstr(*bx-1,*by+1,"H"); mvaddstr(*bx-2,*by+1,"H"); *by=*by+1;}
			}	
	if (tip==9) { if (v[*bx-1][*by+3]==' ' && v[*bx][*by+3]==' ') {attrset(COLOR_PAIR(7)); mvaddstr(*bx,*by," "); mvaddstr(*bx-1,*by+2," "); attrset(COLOR_PAIR(color));mvaddstr(*bx,*by+3,"H"); 
							mvaddstr(*bx-1,*by+3,"H"); *by=*by+1;}
			}	
	if (tip==10) { if (v[*bx][*by+2]==' ' && v[*bx-1][*by+2]==' ' && v[*bx-2][*by+2]==' ') 
			{ attrset(COLOR_PAIR(7)); mvaddstr(*bx-2,*by," "); mvaddstr(*bx-1,*by+1," "); mvaddstr(*bx,*by+1," ");attrset(COLOR_PAIR(color)); mvaddstr(*bx,*by+2,"H");
						 mvaddstr(*bx-1,*by+2,"H"); mvaddstr(*bx-2,*by+2,"H"); *by=*by+1;}
		     }
	if (tip==11) { if (v[*bx-1][*by+3]==' ' && v[*bx][*by+3]==' ') { attrset(COLOR_PAIR(7));mvaddstr(*bx-1,*by," "); mvaddstr(*bx,*by+2," "); attrset(COLOR_PAIR(color));mvaddstr(*bx,*by+3,"H"); 
							mvaddstr(*bx-1,*by+3,"H"); *by=*by+1;}
			}
	if (tip==12) { if (v[*bx-2][*by+2]==' ') {attrset(COLOR_PAIR(7));mvaddstr(*bx,*by," "); mvaddstr(*bx-1,*by," "); mvaddstr(*bx-2,*by," ");attrset(COLOR_PAIR(color)); mvaddstr(*bx,*by+1,"H");
						 mvaddstr(*bx-1,*by+1,"H"); mvaddstr(*bx-2,*by+2,"H"); *by=*by+1;}
			}
	if (tip==13) { if (v[*bx][*by+3]==' ') { attrset(COLOR_PAIR(7));mvaddstr(*bx,*by," "); mvaddstr(*bx-1,*by," ");attrset(COLOR_PAIR(color)); mvaddstr(*bx-1,*by+1,"H"); mvaddstr(*bx,*by+3,"H"); *by=*by+1;} }
	if (tip==14) { if (v[*bx][*by+2]==' ' && v[*bx-1][*by+2]==' ' && v[*bx-2][*by+2]==' ') 
			{  attrset(COLOR_PAIR(7));mvaddstr(*bx,*by," "); mvaddstr(*bx-1,*by+1," "); mvaddstr(*bx-2,*by+1," ");attrset(COLOR_PAIR(color)); mvaddstr(*bx,*by+2,"H");
						 mvaddstr(*bx-1,*by+2,"H"); mvaddstr(*bx-2,*by+2,"H"); *by=*by+1;}
		     }	
	if (tip==15) { if (v[*bx-1][*by+3]==' ') {attrset(COLOR_PAIR(7));mvaddstr(*bx-1,*by," ");mvaddstr(*bx,*by+1," ");attrset(COLOR_PAIR(color));mvaddstr(*bx-1,*by+3,"H");mvaddstr(*bx,*by+2,"H"); *by=*by+1;} }
	if (tip==16) { if (v[*bx-1][*by+2]==' ') {attrset(COLOR_PAIR(7));mvaddstr(*bx,*by," ");mvaddstr(*bx-1,*by," ");mvaddstr(*bx-2,*by," ");attrset(COLOR_PAIR(color));mvaddstr(*bx-1,*by+2,"H");
							mvaddstr(*bx-2,*by+1,"H");mvaddstr(*bx,*by+1,"H"); *by=*by+1;}
		     }
	if (tip==17) { if (v[*bx][*by+3]==' ') {attrset(COLOR_PAIR(7));mvaddstr(*bx,*by," ");mvaddstr(*bx-1,*by+1," ");attrset(COLOR_PAIR(color));mvaddstr(*bx,*by+3,"H");mvaddstr(*bx-1,*by+2,"H"); *by=*by+1;} }
	if (tip==18) { if (v[*bx][*by+2]==' ' && v[*bx-1][*by+2]==' ' && v[*bx-2][*by+2]==' ') {attrset(COLOR_PAIR(7));mvaddstr(*bx-1,*by," ");mvaddstr(*bx,*by+1," ");
mvaddstr(*bx-2,*by+1," "); attrset(COLOR_PAIR(color));	mvaddstr(*bx-1,*by+2,"H");mvaddstr(*bx,*by+2,"H");mvaddstr(*bx-2,*by+2,"H"); *by=*by+1;}
			}
		
	attroff(COLOR_PAIR(color));
}	  
void mstanga(int *bx, int *by ,int tip , int color , char v[50][50],int *gata) //Mutarea la stanga a pieselor.
{	attron(COLOR_PAIR(color));
	if (tip==0) { 
			if (v[*bx-1][*by-1]==' ' && v[*bx][*by-1]==' ') {attrset(COLOR_PAIR(7)); mvaddstr(*bx-1,*by+1," ");mvaddstr(*bx,*by+1," ");attrset(COLOR_PAIR(color));
									mvaddstr(*bx-1,*by-1,"H");mvaddstr(*bx,*by-1,"H"); *by=*by-1; refresh();}
			 
			}
	if (tip==1) { 
			if (v[*bx][*by-1]==' ') { attrset(COLOR_PAIR(7)); mvaddstr(*bx,*by+3," "); attrset(COLOR_PAIR(color)); mvaddstr(*bx,*by-1,"H"); *by=*by-1; }
		  	}
	if (tip==2) {  
			if (v[*bx][*by-1]==' ' && v[*bx-1][*by-1]==' ' && v[*bx-2][*by-1]==' ' && v[*bx-3][*by-1]==' ') 
					{ attrset(COLOR_PAIR(7)); mvaddstr(*bx,*by," "); mvaddstr(*bx-1,*by," "); mvaddstr(*bx-2,*by," "); mvaddstr(*bx-3,*by," "); attrset(COLOR_PAIR(color));
					 mvaddstr(*bx,*by-1,"H"); mvaddstr(*bx-1,*by-1,"H"); mvaddstr(*bx-2,*by-1,"H"); mvaddstr(*bx-3,*by-1,"H"); 
					*by=*by-1; }
			}
	if (tip==3) { if (v[*bx][*by-1]==' ' && v[*bx-1][*by]==' ') {attrset(COLOR_PAIR(7)); mvaddstr(*bx,*by+1," ");mvaddstr(*bx-1,*by+2," "); attrset(COLOR_PAIR(color));
									mvaddstr(*bx,*by-1,"H");mvaddstr(*bx-1,*by,"H"); *by=*by-1;}
			}
	if (tip==4) { if (v[*bx-2][*by-1]==' ' && v[*bx-1][*by-1]==' ') 
			{attrset(COLOR_PAIR(7));mvaddstr(*bx-2,*by," ");mvaddstr(*bx,*by+1," ");mvaddstr(*bx-1,*by+1," "); attrset(COLOR_PAIR(color));
			 mvaddstr(*bx,*by,"H"); mvaddstr(*bx-2,*by-1,"H");mvaddstr(*bx-1,*by-1,"H"); *by=*by-1;}
			} 	
	if (tip==5) { if (v[*bx][*by]==' ' && v[*bx-1][*by-1]==' ') {attrset(COLOR_PAIR(7));mvaddstr(*bx,*by+2," ");mvaddstr(*bx-1,*by+1," ");attrset(COLOR_PAIR(color));
									mvaddstr(*bx,*by,"H");mvaddstr(*bx-1,*by-1,"H"); *by=*by-1;}
			}	
	if (tip==6) { if (v[*bx-1][*by-1]==' ' && v[*bx][*by-1]==' ') 
			{attrset(COLOR_PAIR(7));mvaddstr(*bx-2,*by+1," ");mvaddstr(*bx,*by," ");mvaddstr(*bx-1,*by+1," ");attrset(COLOR_PAIR(color));
			 mvaddstr(*bx,*by-1,"H"); mvaddstr(*bx-2,*by,"H");mvaddstr(*bx-1,*by-1,"H"); *by=*by-1;}
	 		}
		     
	if (tip==7) { if (v[*bx-1][*by-1]==' ' && v[*bx][*by-1]==' ') 
		{ attrset(COLOR_PAIR(7));mvaddstr(*bx,*by," "); mvaddstr(*bx-1,*by+2," ");attrset(COLOR_PAIR(color)); mvaddstr(*bx,*by-1,"H"); mvaddstr(*bx-1,*by-1,"H"); *by=*by-1;} }
	if (tip==8) { if (v[*bx][*by-1]==' ' && v[*bx-1][*by-1]==' ' && v[*bx-2][*by-1]==' ' ) 
			{ attrset(COLOR_PAIR(7)); mvaddstr(*bx-1,*by," "); mvaddstr(*bx-2,*by," "); mvaddstr(*bx,*by+1," ");attrset(COLOR_PAIR(color)); mvaddstr(*bx,*by-1,"H");
						 mvaddstr(*bx-1,*by-1,"H"); mvaddstr(*bx-2,*by-1,"H"); *by=*by-1;}
			}	
	if (tip==9) { if (v[*bx][*by-1]==' ') { attrset(COLOR_PAIR(7));mvaddstr(*bx,*by+2," "); mvaddstr(*bx-1,*by+2," "); attrset(COLOR_PAIR(color));mvaddstr(*bx,*by-1,"H"); 
							mvaddstr(*bx-1,*by+1,"H"); *by=*by-1;}
			}	
	if (tip==10) { if (v[*bx-2][*by-1]==' ') 
			{  attrset(COLOR_PAIR(7));mvaddstr(*bx-1,*by+1," "); mvaddstr(*bx,*by+1," "); mvaddstr(*bx-2,*by+1," ");attrset(COLOR_PAIR(color)); mvaddstr(*bx,*by,"H");
						 mvaddstr(*bx-1,*by,"H"); mvaddstr(*bx-2,*by-1,"H"); *by=*by-1;}
		     }
	if (tip==11) { if (v[*bx][*by-1]==' ') { attrset(COLOR_PAIR(7));mvaddstr(*bx-1,*by+2," "); mvaddstr(*bx,*by+2," "); attrset(COLOR_PAIR(color));mvaddstr(*bx,*by+1,"H"); 
							mvaddstr(*bx-1,*by-1,"H"); *by=*by-1;}
			}
	if (tip==12) { if (v[*bx-2][*by-1]==' ' && v[*bx-1][*by-1]==' ' && v[*bx][*by-1]==' ') 
			{attrset(COLOR_PAIR(7));mvaddstr(*bx,*by," "); mvaddstr(*bx-1,*by," "); mvaddstr(*bx-2,*by+1," "); attrset(COLOR_PAIR(color)); mvaddstr(*bx,*by-1,"H");
						 mvaddstr(*bx-1,*by-1,"H"); mvaddstr(*bx-2,*by-1,"H"); *by=*by-1;}
			}
	if (tip==13) { if (v[*bx][*by-1]==' ' && v[*bx-1][*by-1]==' ') 
		{ attrset(COLOR_PAIR(7));mvaddstr(*bx,*by+2," "); mvaddstr(*bx-1,*by," ");attrset(COLOR_PAIR(color)); mvaddstr(*bx-1,*by-1,"H"); mvaddstr(*bx,*by-1,"H"); *by=*by-1;} }
	if (tip==14) { if (v[*bx][*by-1]==' ' ) 
			{  attrset(COLOR_PAIR(7));mvaddstr(*bx,*by+1," "); mvaddstr(*bx-1,*by+1," "); mvaddstr(*bx-2,*by+1," "); attrset(COLOR_PAIR(color)); mvaddstr(*bx-1,*by,"H");
						 mvaddstr(*bx-2,*by,"H"); mvaddstr(*bx,*by-1,"H"); *by=*by-1;}
		     }	
	if (tip==15) { if (v[*bx-1][*by-1]==' ') {attrset(COLOR_PAIR(7));mvaddstr(*bx-1,*by+2," ");mvaddstr(*bx,*by+1," ");attrset(COLOR_PAIR(color));mvaddstr(*bx-1,*by-1,"H");mvaddstr(*bx,*by,"H"); *by=*by-1;} }
	if (tip==16) { if (v[*bx-1][*by-1]==' ' && v[*bx-2][*by-1]==' ' && v[*bx][*by-1]==' ') 
				{attrset(COLOR_PAIR(7));mvaddstr(*bx,*by," ");mvaddstr(*bx-1,*by+1," ");mvaddstr(*bx-2,*by," ");attrset(COLOR_PAIR(color));mvaddstr(*bx-1,*by-1,"H");
							mvaddstr(*bx-2,*by-1,"H");mvaddstr(*bx,*by-1,"H"); *by=*by-1;}
		     }
	if (tip==17) { if (v[*bx][*by-1]==' ') {attrset(COLOR_PAIR(7));mvaddstr(*bx,*by+2," ");mvaddstr(*bx-1,*by+1," ");attrset(COLOR_PAIR(color));mvaddstr(*bx,*by-1,"H");mvaddstr(*bx-1,*by,"H"); *by=*by-1;} }
	if (tip==18) { if (v[*bx-1][*by-1]==' ' ) {attrset(COLOR_PAIR(7));mvaddstr(*bx-2,*by+1," "); mvaddstr(*bx-1,*by+1," ");mvaddstr(*bx,*by+1," "); attrset(COLOR_PAIR(color));
				mvaddstr(*bx-1,*by-1,"H");mvaddstr(*bx,*by,"H");mvaddstr(*bx-2,*by,"H"); *by=*by-1;}
			}
	attroff(COLOR_PAIR(color));
}	  
void rotire(int *bx, int *by ,int *tip , int color , char v[50][50],int *s) //Functie pentru rotirea in sens trigonometrica a pieselor
{
	attron(COLOR_PAIR(color));
	if (*tip==1) {
			if (v[*bx-1][*by+2]==' ' && v[*bx+1][*by+2]==' ' && v[*bx+2][*by+2]==' ' )
		{attrset(COLOR_PAIR(7));mvaddstr(*bx,*by," ");mvaddstr(*bx,*by+1," ");mvaddstr(*bx,*by+3," ");attrset(COLOR_PAIR(color));
		 mvaddstr(*bx-1,*by+2,"H");mvaddstr(*bx+1,*by+2,"H");mvaddstr(*bx+2,*by+2,"H");
		 *tip=2; *bx=*bx+2; *by=*by+2; *s=*s+3; }
	 		} else
	if (*tip==2) {
			if (v[*bx-2][*by-2]==' ' && v[*bx-2][*by-1]==' ' && v[*bx-2][*by+1]==' ' )
		{attrset(COLOR_PAIR(7));mvaddstr(*bx,*by," ");mvaddstr(*bx-1,*by," ");mvaddstr(*bx-3,*by," ");attrset(COLOR_PAIR(color));
		 mvaddstr(*bx-2,*by-2,"H");mvaddstr(*bx-2,*by-1,"H");mvaddstr(*bx-2,*by+1,"H");
		 *tip=1; *bx=*bx-2; *by=*by-2; *s=*s-3; }
		     }  else
	if (*tip==3) {
			if (v[*bx-2][*by+1]==' ' && v[*bx][*by+2]==' ')
		{attrset(COLOR_PAIR(7));mvaddstr(*bx,*by,"  ");attrset(COLOR_PAIR(color));mvaddstr(*bx,*by+2,"H");mvaddstr(*bx-2,*by+1,"H");
		 *tip=4; *by=*by+1; *s=*s+1;}
			} else
	if (*tip==4) {	
		if (v[*bx][*by-1]==' ' && v[*bx][*by]==' ' && v[*bx-2][*by]==' ')
		{attrset(COLOR_PAIR(7));mvaddstr(*bx,*by+1," ");mvaddstr(*bx-2,*by," ");attrset(COLOR_PAIR(color));mvaddstr(*bx,*by-1,"HH");
		 *tip=3; *by=*by-1; *s=*s-1;} 
			} else
	if (*tip==5) {
			if (v[*bx-1][*by+2]==' ' && v[*bx-2][*by+2]==' ')
		{attrset(COLOR_PAIR(7));mvaddstr(*bx-1,*by," ");mvaddstr(*bx,*by+2," ");attrset(COLOR_PAIR(color));mvaddstr(*bx-1,*by+2,"H"); mvaddstr(*bx-2,*by+2,"H");
		 *tip=6; *by=*by+1; *s=*s+1;}
			} else
	if (*tip==6) {	
		if (v[*bx][*by+1]==' ' && v[*bx-1][*by-1]==' ')
		{attrset(COLOR_PAIR(7));mvaddstr(*bx-1,*by+1," ");mvaddstr(*bx-2,*by+1," ");attrset(COLOR_PAIR(color));mvaddstr(*bx-1,*by-1,"HH");mvaddstr(*bx,*by+1,"H");
		 *tip=5; *by=*by-1; *s=*s-1;} 
			} else
	if (*tip==7) {
		if (v[*bx][*by+1]==' ' && v[*bx][*by+2]==' ' && v[*bx-2][*by+1]==' ')
		{attrset(COLOR_PAIR(7));mvaddstr(*bx-1,*by," ");mvaddstr(*bx,*by," ");mvaddstr(*bx-1,*by+2," ");attrset(COLOR_PAIR(color));
		 mvaddstr(*bx,*by+1,"H");mvaddstr(*bx,*by+2,"H");mvaddstr(*bx-2,*by+1,"H");
		 *tip=8; *by=*by+1; *s=*s+1;}
		} else
	if (*tip==8) {
		if (v[*bx-2][*by+1]==' ' && v[*bx-1][*by-1]==' ' && v[*bx-1][*by+1]==' ')
		{attrset(COLOR_PAIR(7));mvaddstr(*bx,*by," ");mvaddstr(*bx,*by+1," ");mvaddstr(*bx-2,*by," ");attrset(COLOR_PAIR(color));
		 mvaddstr(*bx-2,*by+1,"H");mvaddstr(*bx-1,*by-1,"H");mvaddstr(*bx-1,*by+1,"H");
		 *tip=9; *by=*by-1; *bx=*bx-1; *s=*s-1;}
		} else
	if (*tip==9) {
		if (v[*bx+1][*by+1]==' ' && v[*bx-1][*by]==' ' && v[*bx-1][*by+1]==' ')
		{attrset(COLOR_PAIR(7));mvaddstr(*bx,*by," ");mvaddstr(*bx,*by+2," ");mvaddstr(*bx-1,*by+2," ");attrset(COLOR_PAIR(color));
		 mvaddstr(*bx+1,*by+1,"H");mvaddstr(*bx-1,*by,"H");mvaddstr(*bx-1,*by+1,"H");
		 *tip=10; *bx=*bx+1; *s=*s+1;}
		} else
	
	if (*tip==10) {
		if (v[*bx][*by]==' ' && v[*bx-1][*by]==' ' && v[*bx-1][*by+2]==' ')
		{attrset(COLOR_PAIR(7));mvaddstr(*bx,*by+1," ");mvaddstr(*bx-2,*by," ");mvaddstr(*bx-2,*by+1," ");attrset(COLOR_PAIR(color)); 
		 mvaddstr(*bx,*by,"H");mvaddstr(*bx-1,*by,"H");mvaddstr(*bx-1,*by+2,"H");
		 *tip=7; *s=*s-1;}
		} else
	
	if (*tip==11) {
		if (v[*bx-2][*by+1]==' ' && v[*bx-2][*by+2]==' ' && v[*bx][*by+1]==' ')
		{attrset(COLOR_PAIR(7));mvaddstr(*bx,*by+2," ");mvaddstr(*bx-1,*by," ");mvaddstr(*bx-1,*by+2," "); attrset(COLOR_PAIR(color)); 
		 mvaddstr(*bx-2,*by+1,"H");mvaddstr(*bx-2,*by+2,"H");mvaddstr(*bx,*by+1,"H");
		 *tip=12; *by=*by+1; *s=*s+1;}
		} else
	
	if (*tip==12) {
		if (v[*bx-2][*by-1]==' ' && v[*bx-1][*by-1]==' ' && v[*bx-1][*by+1]==' ')
		{attrset(COLOR_PAIR(7));mvaddstr(*bx-2,*by," ");mvaddstr(*bx,*by," ");mvaddstr(*bx-2,*by+1," ");attrset(COLOR_PAIR(color));
		 mvaddstr(*bx-2,*by-1,"H");mvaddstr(*bx-1,*by-1,"H");mvaddstr(*bx-1,*by+1,"H");
		 *tip=13; *by=*by-1; *bx=*bx-1; *s=*s-1;}
		} else	 
	
	if (*tip==13) {
		if (v[*bx+1][*by+1]==' ' && v[*bx+1][*by]==' ' && v[*bx-1][*by+1]==' ')
		{attrset(COLOR_PAIR(7));mvaddstr(*bx,*by," ");mvaddstr(*bx-1,*by," ");mvaddstr(*bx,*by+2," ");attrset(COLOR_PAIR(color));
		 mvaddstr(*bx+1,*by+1,"H");mvaddstr(*bx+1,*by,"H");mvaddstr(*bx-1,*by+1,"H");
		 *tip=14; *bx=*bx+1; *s=*s+1;}
		} else
	
	if (*tip==14) {
		if (v[*bx-1][*by]==' ' && v[*bx][*by+2]==' ' && v[*bx-1][*by+2]==' ')
		{attrset(COLOR_PAIR(7));mvaddstr(*bx,*by+1," ");mvaddstr(*bx,*by," ");mvaddstr(*bx-2,*by+1," ");attrset(COLOR_PAIR(color));
		 mvaddstr(*bx-1,*by,"H");mvaddstr(*bx,*by+2,"H");mvaddstr(*bx-1,*by+2,"H");
		 *tip=11; *s=*s-1;}
		} else
	
	if (*tip==15) {
		if (v[*bx-2][*by+1]==' ')
		{attrset(COLOR_PAIR(7));mvaddstr(*bx-1,*by," ");attrset(COLOR_PAIR(color));
		 mvaddstr(*bx-2,*by+1,"H");
		 *tip=16; *by=*by+1; *s=*s+1;}
		} else
	
	if (*tip==16) {
		if (v[*bx-1][*by-1]==' ' )
		{attrset(COLOR_PAIR(7));mvaddstr(*bx,*by," ");attrset(COLOR_PAIR(color));mvaddstr(*bx-1,*by-1,"H");
		 *tip=17; *by=*by-1; *bx=*bx-1; *s=*s-1;}
		} else
	
	if (*tip==17) {
		if (v[*bx+1][*by+1]==' ')
		{attrset(COLOR_PAIR(7));mvaddstr(*bx,*by+2," ");attrset(COLOR_PAIR(color));mvaddstr(*bx+1,*by+1,"H");
		 *tip=18; *bx=*bx+1; *s=*s+1;}
		} else
	
	if (*tip==18) {
		if (v[*bx-1][*by+2]==' ' )
		{attrset(COLOR_PAIR(7));mvaddstr(*bx-2,*by+1," ");attrset(COLOR_PAIR(color));mvaddstr(*bx-1,*by+2,"H");
		 *tip=15; *s=*s-1;}
		}
attroff(COLOR_PAIR(color));
}

void switchsafe(int *tip , int *stip , int *bx , int *by, char v[50][50], int *s) // Functie care realizeaza switch dintre blocul din joc si cel din Safe spot
{
  int i,j,ok,aux;
  if (*stip==0) {aux=*stip; *s=3;}
  if (*stip==1) {aux=1; *s=1;}
  if (*stip==2) {aux=2; *s=5;}
  if (*stip==3) {aux=3; *s=3;}
  if (*stip==4) {aux=4; *s=3;}
  if (*stip==5) {aux=5; *s=3;}
  if (*stip==6) {aux=6; *s=4;} 
  if (*stip==7) {aux=7; *s=3;}
  if (*stip==8) {aux=8; *s=4;}
  if (*stip==9) {aux=9; *s=3;}
  if (*stip==10) {aux=10; *s=4;}
  if (*stip==11) {aux=11; *s=3;}
  if (*stip==12) {aux=12; *s=4;}
  if (*stip==13) {aux=13; *s=3;}
  if (*stip==14) {aux=14; *s=4;}
  if (*stip==15) {aux=15; *s=3;} 
  if (*stip==16) {aux=16;  *s=4;}
  if (*stip==17) {aux=17;  *s=2;}
  if (*stip==18) {aux=18;  *s=4;}
   
  if (*tip==0) { ok=0; 
		for (i=*bx-2;i<=*bx+1;i++)
		 for (j=*by-1;j<=*by+2;j++) if (v[i][j]!=' ') ok=1;
   		if (ok==0) {
			      for (i=*bx-2;i<=*bx+1;i++)
		 		for (j=*by-1;j<=*by+2;j++) { move(i,j); addch(' '); }
				*bx=*bx-2;   
			*stip=*tip;
			   	
			    }
		}
  if (*tip==1) { ok=0; 
		for (i=*bx-2;i<=*bx+1;i++)
		 for (j=*by;j<=*by+3;j++) if (v[i][j]!=' ') ok=1;
   		if (ok==0) {
			      for (i=*bx-2;i<=*bx+1;i++)
		 		for (j=*by;j<=*by+3;j++) { move(i,j); addch(' '); }
			    *by=*by+1;*bx=*bx-2;
							   
			*stip=*tip;
			    }
		}
  if (*tip==2) { ok=0; 
		for (i=*bx-3;i<=*bx;i++)
		 for (j=*by-2;j<=*by+1;j++) if (v[i][j]!=' ') ok=1;
   		if (ok==0) {
			      for (i=*bx-3;i<=*bx;i++)
		 		for (j=*by-2;j<=*by+1;j++) { move(i,j); addch(' '); }
			   *bx=*bx-3; *by=*by-1;	
			    		   
			*stip=*tip;   
			 }
		}
  if (*tip>2) { ok=0; 
		for (i=*bx-2;i<=*bx+1;i++)
		 for (j=*by-1;j<=*by+2;j++) if (v[i][j]!=' ') ok=1;
   		if (ok==0) {
			      for (i=*bx-2;i<=*bx+1;i++)
		 		for (j=*by-1;j<=*by+2;j++) { move(i,j); addch(' '); }
			    *bx=*bx-2;	
			    *stip=*tip;
			    }
		}
  *tip=aux;
}     	
void preview(int tip, int color , int *bx , int *by,int bloc,int scrclr2) // functie care afiseaza in cele 2 spot-uri piesele
{
  int i;
  attron(COLOR_PAIR(scrclr2));
  if (bloc==1) for (i=4;i<=9;i++)  mvaddstr(i,35,"|              |");
  if (bloc==2) for (i=4;i<=9;i++)  mvaddstr(i,54,"|             |");
  attroff(COLOR_PAIR(scrclr2));
  attron(COLOR_PAIR(color));	
  if (tip==0) { mvaddstr(*bx,*by,"HH"); mvaddstr(*bx+1,*by,"HH");}
  if (tip==1) { mvaddstr(*bx+1,*by-2,"HHHH");}
  if (tip==2) { mvaddstr(*bx-1,*by,"H");mvaddstr(*bx,*by,"H");mvaddstr(*bx+1,*by,"H");mvaddstr(*bx+2,*by,"H"); }
  if (tip==5) { mvaddstr(*bx,*by-1,"HH");mvaddstr(*bx+1,*by,"HH");}
  if (tip==6) { mvaddstr(*bx+1,*by,"HH");mvaddstr(*bx+2,*by,"H");mvaddstr(*bx,*by+1,"H");} 
  if (tip==3) {	mvaddstr(*bx,*by,"HH");mvaddstr(*bx+1,*by-1,"HH"); }
  if (tip==4) {	mvaddstr(*bx+1,*by,"HH");mvaddstr(*bx,*by,"H");mvaddstr(*bx+2,*by+1,"H");} 
  if (tip==13) {mvaddstr(*bx-1,*by-2,"H");mvaddstr(*bx,*by-2,"HHHH"); }
  if (tip==14) {mvaddstr(*bx,*by,"H");mvaddstr(*bx+1,*by,"H");mvaddstr(*bx+2,*by-1,"HH");}
  if (tip==11) { mvaddstr(*bx+1,*by+1,"H");mvaddstr(*bx,*by-2,"HHHH");}
  if (tip==12) {mvaddstr(*bx,*by,"H");mvaddstr(*bx+1,*by,"H");mvaddstr(*bx-1,*by,"HH"); }
  if (tip==7) {mvaddstr(*bx+1,*by-2,"H");mvaddstr(*bx,*by-2,"HHHH");}
  if (tip==8) {mvaddstr(*bx,*by,"H");mvaddstr(*bx-1,*by,"H");mvaddstr(*bx+1,*by,"HH");}
  if (tip==9) {mvaddstr(*bx-1,*by+1,"H");mvaddstr(*bx,*by-2,"HHHH");}
  if (tip==10) {mvaddstr(*bx,*by,"H");mvaddstr(*bx+1,*by,"H");mvaddstr(*bx-1,*by-1,"HH");}
  if (tip==17) {mvaddstr(*bx+1,*by-1,"HHH");mvaddstr(*bx,*by,"H"); }
  if (tip==18) {mvaddstr(*bx+1,*by,"HH");mvaddstr(*bx,*by+1,"H");mvaddstr(*bx+2,*by+1,"H");}
  if (tip==15) {mvaddstr(*bx+1,*by,"H");mvaddstr(*bx,*by-1,"HHH");}
  if (tip==16) {mvaddstr(*bx,*by,"H");mvaddstr(*bx+2,*by,"H");mvaddstr(*bx+1,*by,"HH");}  

refresh();
  attroff(COLOR_PAIR(color));	
}
void reset(char v[50][50]) //Functia reseteaza harta de joc.
{
  int i ,j;
  v[1][3]=' '; v[1][34]=' '; for (i=4;i<=33;i++) v[1][i]='_';
  for (i=2;i<=25;i++) 
   for (j=3;j<=34;j++) if (j==3 || j==34) v[i][j]='|'; else v[i][j]=' ';
  v[26][3]='|'; v[26][34]='|'; for (i=4;i<=33;i++) v[26][i]=' ';
}  	 		
void create(int x, int scrclr1 , int scrclr2) //Creeaza harta de joc impreuna cu cele doua spot-uri
{
 int i;
 clear();
 
 attron(COLOR_PAIR(scrclr2));
 mvaddstr(3,35," ______________     _____________"); 
 for (i=4;i<=9;i++) 
 mvaddstr(i,35,"|              |   |             |");
 for (i=35;i<=67;i++) { move(10,i); addch(ACS_S1); }
 attroff(COLOR_PAIR(scrclr2));	
 attron(COLOR_PAIR(scrclr1));
 mvaddstr(1,3," ______________________________ ");
 for (i=2;i<=x;i++)
     mvaddstr(i,3, "|                              |");
 mvaddstr(x+1,3,   "|                              |");
 for (i=1;i<=29;i++) {move(27,i+3); addch(ACS_S1);}
 attroff(COLOR_PAIR(scrclr1));
 refresh();
}
int main()
{
  WINDOW* wnd = initscr();
  curs_set(0);
  clear();
  noecho();
  cbreak();
  keypad(wnd, TRUE);
  nodelay(wnd, TRUE);
  start_color();//Definire Culori si Afisarea primelor mesaje din meniul principal
  init_pair(0,COLOR_RED,COLOR_BLACK);
  init_pair(1,COLOR_WHITE,COLOR_WHITE);
  init_pair(2,COLOR_YELLOW,COLOR_YELLOW);
  init_pair(3,COLOR_GREEN,COLOR_GREEN);
  init_pair(4,COLOR_BLUE,COLOR_BLUE);
  init_pair(5,COLOR_MAGENTA,COLOR_MAGENTA);
  init_pair(6,COLOR_CYAN,COLOR_CYAN);
  init_pair(7,COLOR_CYAN,COLOR_BLACK);
  init_pair(8,COLOR_RED,COLOR_RED);
  init_pair(9,COLOR_RED,COLOR_BLACK);
  init_pair(10,COLOR_GREEN,COLOR_BLACK);
  init_pair(11,COLOR_BLUE,COLOR_BLACK);
  init_pair(12,COLOR_MAGENTA,COLOR_BLACK);
  init_pair(13,COLOR_YELLOW,COLOR_BLACK);	
  attron(COLOR_PAIR(10));
  mvaddstr(3, 20, "Welcome To TETRIS");
  attroff(COLOR_PAIR(10));
  attron(COLOR_PAIR(11));
  mvaddstr(5, 10, "New Game");
  attroff(COLOR_PAIR(11));
  attron(COLOR_PAIR(12));			
  mvaddstr(7, 10, "Set Starting Level");
  attron(COLOR_PAIR(12));
  attron(COLOR_PAIR(12)); 
  mvaddstr(9, 10, "Customize Game Screen");
  attron(COLOR_PAIR(12)); 
  attron(COLOR_PAIR(13)); 
  mvaddstr(11, 10, "Quit");
  attron(COLOR_PAIR(13));	
  int row,col,p,k,enter=0,scor=0, nivel=1,bx,by,i,j,xi=2,yi=15,urm_tip=0,urm_color=1,sx,sy,stip,scolor,safe=10;
  char v[50][50]; // Harta are 26 linii si 31 coloane;
  reset(&v);    
  
  char *a;
  time_t current;
  double last=0,interval=0.7;
  row=5;
  col=4;
  move(row,col);
  attron(COLOR_PAIR(9)); 	
  mvaddstr(row,col,"---->");
  attron(COLOR_PAIR(9)); 	
  refresh();
  int color=7,tip=1,s=1,gata=0,nrpas=0,ps=0,scrclr1=7,scrclr2=9,scrclr3=13;	
  while (1) { //Meniul principal
    enter=0;
    p=getch();
    switch (tolower(p)) {
      case ' ': case '\n' : enter=1; break;   	
      case  KEY_UP: k=row; row=row-2; if (row>11) row=5; if (row<5) row=11; sgt(k,row,col); break;
      case  KEY_DOWN: k=row; row=row+2; if (row>11) row=5; if (row<5) row=11; sgt(k,row,col); break;
                  }
    if (enter == 1) 
	{
	  if (row==5) { create(25,scrclr1,scrclr2); // Lansarea unui joc nou.
 			 reset(&v);
			 int movekey=1,inte;
			 double timp; 
			 srand(time(NULL));			
			 int next=1;
			 color=rand() % 7;
			 if (color==0) color=8; 
			 bx=xi;
			 by=yi;
			 interval=0.7;
 			 timp=interval;
			 for (inte=1;inte<nivel;inte++) {interval=interval-0.03;timp=interval;}
			 tip=rand() % 18;
			 
			 stip=rand() % 18;
			 scolor=rand() % 7;
			 if (scolor==0) scolor=8;
		         sx=6; sy=61;
			 preview(stip,scolor,&sx,&sy,2,scrclr2);
			 gata=0;
			 s=1;	
			 
			 while (2) {
	     			if (ps==0){
			        if (next==1) { sx=6; sy=42; next=0; urm_tip=rand() %18; urm_color=rand() % 7; if (urm_color==0) urm_color=8; preview(urm_tip,urm_color,&sx,&sy,1,scrclr2); }
				struct timeval tim;
             			gettimeofday(&tim, NULL);
             			double t1=tim.tv_sec+(tim.tv_usec/1000000.0);
				current=time(NULL);
				a=ctime(&current);
				attron(COLOR_PAIR(scrclr3));
				mvaddstr(2,35,"  Preview Spot        Safe Spot");                   		
				mvaddstr(15, 45, a);
				mvaddstr(16, 45, "SCOR="); 
				mvaddstr(17, 45, "Nivelul ");
				move(16,51); printw("%d",scor);
				move(17,53); printw("%d",nivel);
				mvaddstr(19, 45, "Press P to pause the game ");				
				mvaddstr(21,45, "Press BACKSPACE to switch the current block ");
				mvaddstr(22,47, "with the one in the safe spot");				
				refresh();
				mvaddstr(24,45, "Press ESC to return to the main menu");
				attroff(COLOR_PAIR(scrclr3));				
				int check,a,b,pas;
								
				for (i=1;i<=26;i++) // Verificare daca s.a realizat o linie de blocuri si acordarea punctajelor.
				{
				check=0;
				for (j=3;j<=34;j++) if (v[i][j]==' ' || v[i][j]=='_' ) { check=1; break; }	 
				if (check==0) { a=i; scor=scor+nivel*10; 
						while (a>=6) 
						 {for (j=4;j<=33;j++) 
							{b=v[a-1][j]-'0';  v[a][j]=v[a-1][j]; 
							if (v[a][j]!=' ') { attron(COLOR_PAIR(b)); move(a,j); addch(v[a][j]); refresh; attroff(COLOR_PAIR(b)); }  	
							  else	if (v[a][j]==' ') { attron(COLOR_PAIR(7)); move(a,j); addch(v[a][j]); refresh; attroff(COLOR_PAIR(7)); }
						        }
						  a=a-1;}			
					       }
				}
				//Verificare daca s.a indeplinit conditia pentru a trece la urmatorul nivel. 
			  	if (scor>=(nivel*10+10)*(nivel+2)) {nivel=nivel+1; for (inte=1;inte<nivel;inte++) {interval=interval-0.03;timp=interval;}}
				p=getch();
				
				if (gata==0 ) switch (tolower(p)) {
					case '\E' : k=0; break;
					case 'p': attron(COLOR_PAIR(13)); mvaddstr(12,50,"GAME PAUSED"); mvaddstr(19,45,"                         "); mvaddstr(13,45,"Press SPACE to unpause");  attroff(COLOR_PAIR(13));
								wtimeout(wnd, -4); ps=1; break;
					case  KEY_UP: rotire(&bx,&by,&tip,color,&v,&s); move(20,20);  refresh(); break; 
			  	
      					case  KEY_RIGHT: if ( movekey==0 ) {mdreapta(&bx,&by,tip,color,&v,&gata);} break;
      					case  KEY_LEFT:  if (movekey==0 ) {mstanga(&bx,&by,tip,color,&v,&gata);} break;
					case  KEY_DOWN:  interval=0.005; break;
							
					case KEY_BACKSPACE: if(safe>=10) {safe=1; sx=6; sy=61; switchsafe(&tip , &stip , &bx , &by, &v,&s); preview(stip,color,&sx,&sy,2,scrclr2); nrpas=s; s=1; a=scolor; scolor=color; color=a; interval=0.0001; pas=1;}  break;	}
				
				//Iesire in caz de apasarea butonului ESC
				if (k==0) { clear(); attrset(COLOR_PAIR(10)); mvaddstr(0, 10, "Welcome To TETRIS"); attrset(COLOR_PAIR(11)); mvaddstr(5, 10, "New Game");
					attrset(COLOR_PAIR(12));mvaddstr(7, 10, "Set Starting Level"); mvaddstr(9, 10, "Customize Game Screen");
	                          attrset(COLOR_PAIR(13));mvaddstr(11, 10, "Quit"); attrset(COLOR_PAIR(9));  mvaddstr(5,4,"---->"); attroff(COLOR_PAIR(9)); row=5; col=4; k=1; break; }
	  			if (t1 - last > interval) {      
      								last = t1;
								
							        if (gata==0) {
										
										blocuri(&s,&bx,&by,tip,color,&gata,&v,&movekey); refresh(); pas++; 
										safe++;beep();
										   
										}
								if (gata==1) { safe=6;bx=xi; by=yi; gata=0; s=1; tip=urm_tip; color=urm_color; next=1; movekey=1;
										  }
      							    }
				
      				if (pas>nrpas) interval=timp;		
     						
     				}
				// Momentul in care s.a lansat comanda de pauza.
				if (ps==1) {
				p=getch();
				switch (tolower(p)) {
					case ' ': attron(COLOR_PAIR(13)); mvaddstr(12,50,"           "); mvaddstr(19,45,"Press P to pause the game"); mvaddstr(13,45,"                      "); attroff(COLOR_PAIR(13));
								wtimeout(wnd, 0); ps=0; break;
					case '\E' : k=0; break;		}
					if (k==0) { wtimeout(wnd, 0); ps=0; clear(); attrset(COLOR_PAIR(10)); mvaddstr(0, 10, "Welcome To TETRIS"); attrset(COLOR_PAIR(11)); mvaddstr(5, 10, "New Game");
					attrset(COLOR_PAIR(12));mvaddstr(7, 10, "Set Starting Level"); mvaddstr(9, 10, "Customize Game Screen");
	                          attrset(COLOR_PAIR(13));mvaddstr(11, 10, "Quit"); attrset(COLOR_PAIR(9));  mvaddstr(5,4,"---->"); attroff(COLOR_PAIR(9)); row=5; col=4; k=1; break; }
					}			
				}
		       }
	if (row==11) break; // Exit din joc.
	if (row==7) {  clear(); //Alegerea nivelului.
			mvaddstr(15,20,"Choose level of dificulty");
			mvaddstr(16,25,"<---  1 --->");
			mvaddstr(25,15,"Use Left and Right keys to navigate.");
			mvaddstr(27,15, "Press Enter when you are done.");
			k=1;
			move(16,31);
			while(2) {
				p=getch();
				switch (tolower(p)) {
				  	
				  case KEY_LEFT: if (nivel>1) { if (nivel>10) move(16,30); else {move(16,30);addch(' '); move(16,31);} nivel=nivel-1; printw("%d",nivel);refresh();  } break;
				  case KEY_RIGHT: if (nivel<20) { if (nivel<9) move(16,31); else move(16,30); refresh(); nivel=nivel+1; printw("%d",nivel); }  break;
				  case '\n': k=0; break; }
				if (k==0) { clear(); attrset(COLOR_PAIR(10)); mvaddstr(0, 10, "Welcome To TETRIS"); attrset(COLOR_PAIR(11)); mvaddstr(5, 10, "New Game");
					attrset(COLOR_PAIR(12));mvaddstr(7, 10, "Set Starting Level"); mvaddstr(9, 10, "Customize Game Screen");
	                          attrset(COLOR_PAIR(13));mvaddstr(11, 10, "Quit"); attrset(COLOR_PAIR(9));  mvaddstr(5,4,"---->"); attroff(COLOR_PAIR(9)); row=5; col=4; k=1; break; }
				 }
                      }
	if (row==9) { clear(); int custom; //Custimization
			custom=1;int crow=7,ccol=4;
			int aux1,aux2,aux3;
			attrset(COLOR_PAIR(9)); mvaddstr(7,4,"---->");
			while (2) {
			mvaddstr(3,10,"Choose what color should the following items have :");
			mvaddstr(21,3,"You can always press ESC to return to the main menu and cancel all decisions");
			if (custom==1) {
			mvaddstr(5,5,"The Tetris Table:");			
			attrset(COLOR_PAIR(9));mvaddstr(7,10,"Red"); 
                      	attrset(COLOR_PAIR(10));mvaddstr(9,10,"Green");
			attrset(COLOR_PAIR(11));mvaddstr(11,10,"Blue");
			attrset(COLOR_PAIR(12));mvaddstr(13,10,"Magenta");
			attrset(COLOR_PAIR(13));mvaddstr(15,10,"Yellow");
			p=getch();
			
    			switch (tolower(p)) {
      			case ' ': case '\n' : custom=2; mvaddstr(7,24,"---->"); if (crow==7) aux1=9; if (crow==9) aux1=10; if (crow==11) aux1=11; if (crow==13) aux1=12; 
						if (crow==15) aux1=13;	crow=7; ccol=24;  break;   	
      			case  KEY_UP: k=crow; crow=crow-2; if (crow>15) crow=7; if (crow<7) crow=15; sgt(k,crow,ccol); break;
      			case  KEY_DOWN: k=crow; crow=crow+2; if (crow>15) crow=7; if (crow<7) crow=15; sgt(k,crow,ccol); break;	
			case '\E': k=0;break; 	
				             }
		                       }
			if (custom==2) {
			
			mvaddstr(5,25,"The Preview & Safe Spots:");			
			attrset(COLOR_PAIR(9));mvaddstr(7,30,"Red"); 
                      	attrset(COLOR_PAIR(10));mvaddstr(9,30,"Green");
			attrset(COLOR_PAIR(11));mvaddstr(11,30,"Blue");
			attrset(COLOR_PAIR(12));mvaddstr(13,30,"Magenta");
			attrset(COLOR_PAIR(13));mvaddstr(15,30,"Yellow");
			p=getch();
			
    			switch (tolower(p)) {
      			case ' ': case '\n' : custom=3; mvaddstr(7,54,"---->"); if (crow==7) aux2=9; if (crow==9) aux2=10; if (crow==11) aux2=11; if (crow==13) aux2=12; 
						if (crow==15) aux2=13;crow=7; ccol=54;  break;   	
      			case  KEY_UP: k=crow; crow=crow-2; if (crow>15) crow=7; if (crow<7) crow=15; sgt(k,crow,ccol); break;
      			case  KEY_DOWN: k=crow; crow=crow+2; if (crow>15) crow=7; if (crow<7) crow=15; sgt(k,crow,ccol); break;
			case '\E': k=0;break; 			
				             }
		                       }
			if (custom==3) {
			mvaddstr(5,57,"The Text:");			
			attrset(COLOR_PAIR(9));mvaddstr(7,60,"Red"); 
                      	attrset(COLOR_PAIR(10));mvaddstr(9,60,"Green");
			attrset(COLOR_PAIR(11));mvaddstr(11,60,"Blue");
			attrset(COLOR_PAIR(12));mvaddstr(13,60,"Magenta");
			attrset(COLOR_PAIR(13));mvaddstr(15,60,"Yellow");
			p=getch();
			
    			switch (tolower(p)) {
      			case ' ': case '\n' : custom=4; if (crow==7) aux3=9; if (crow==9) aux3=10; if (crow==11) aux3=11; if (crow==13) aux3=12; 
						if (crow==15) aux3=13; break;   	
      			case  KEY_UP: k=crow; crow=crow-2; if (crow>15) crow=7; if (crow<7) crow=15; sgt(k,crow,ccol); break;
      			case  KEY_DOWN: k=crow; crow=crow+2; if (crow>15) crow=7; if (crow<7) crow=15; sgt(k,crow,ccol); break;		
			case '\E': k=0;break; 				             
						}
		                       }
			if (custom==4) {
			
			 mvaddstr(17,10,"Are you sure?");
			 mvaddstr(19,10,"Press ENTER to confirm or press BACKSPACE to choose again");
			p=getch();
			
    			switch (tolower(p)) {
      			case ' ': case '\n' : k=0; scrclr1=aux1; scrclr2=aux2; scrclr3=aux3;   break;   	
      			case  KEY_BACKSPACE: custom=1; clear(); crow=7;ccol=4; mvaddstr(7,4,"---->"); break;
      			case '\E': k=0;break; 		
				             }			 
					}
			if (k==0) { clear(); attrset(COLOR_PAIR(10)); mvaddstr(0, 10, "Welcome To TETRIS"); attrset(COLOR_PAIR(11)); mvaddstr(5, 10, "New Game");
					attrset(COLOR_PAIR(12));mvaddstr(7, 10, "Set Starting Level"); mvaddstr(9, 10, "Customize Game Screen");
	                          attrset(COLOR_PAIR(13));mvaddstr(11, 10, "Quit"); attrset(COLOR_PAIR(9));  mvaddstr(5,4,"---->"); attroff(COLOR_PAIR(9)); row=5; col=4; k=1; break; }
			 refresh();
		        }
		    }	
        }   
  }
  endwin();
  return 0;
  } 
