/* $Id: cgascr.cc 5834 2013-10-08 17:04:08Z os $ */

/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             C G A _ S C R E E N                           */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe dieser Klasse kann man auf den Bildschirm des PCs zugreifen.    */
/* Der Zugriff erfolgt direkt auf der Hardwareebene, d.h. ueber den Bild-    */
/* schirmspeicher bzw. die I/O-Ports der Grafikkarte.                        */
/*****************************************************************************/

#include "machine/cgascr.h"

void CGA_Screen::show(int x, int y, char c, unsigned char attrib)
{	
	if((x >= 0 && x <= 79) && (y >= 0 && y <= 24)){
		char *pos;
		pos = CGA_START + 2*(x + y*80);
		*pos = c;
		*(pos + 1) = attrib; // weiss auf schwarz
	}
}

void CGA_Screen::setpos(int x, int y)
{
	//scrollup(x, y);
	//cpu.disable_int();

	cursor_x = x;
	cursor_y = y;

	int position = (x + y*80);
	
	indexPort.outb(15); 
	datenPort.outb(position&0xff);

	indexPort.outb(14);
	datenPort.outb((position>>8)&0xff);	

	//cpu.enable_int();	
}

void CGA_Screen::getpos(int &x, int &y)
{
	/*
	indexPort.outb(14);
	int position = datenPort.inb() << 8;

	indexPort.outb(15);
	position |= datenPort.inb();

	x = position % 80;
	y = position / 80;*/
	x = cursor_x;
	y = cursor_y;
}

void CGA_Screen::print(char* text, int length, unsigned char attrib)
{
	int x ; int y;
	for(int i = 0; i < length ; i++){
		char c = *(text + i);
		getpos(x, y);
		if(c == '\n'){
			y +=1; x=0;
			scrollup(x, y);
			setpos(x, y);
		}else if(x >= MAX_COLS-1){
			show(x, y, c, attrib);
			y +=1; x=0;
			scrollup(x, y);
			setpos(x, y);
		}
		else {
			scrollup(x, y);
			show(x, y, c, attrib);
			setpos(x+1, y);
		}
	}
}

void CGA_Screen::clearscreen(){
	int row = 0;
	int col = 0;
	for ( row =0; row < 80 ; row ++) {
		for ( col =0; col < 24 ; col ++) {
		show( row , col , ' ' , 0x0f );
		}
	}
	// Move the cursor back to the top left corner.
	setpos(0 , 0);
}

void CGA_Screen::clearRow(int row){
 	char *pos;
	for(int i=0; i < MAX_COLS; i++){
		pos = CGA_START + 2*(i + row*MAX_COLS);
		*pos = 0;
		*(pos +1) =0;
	}
}

void CGA_Screen::memorycopy(char * source , char * dest , int no_bytes ){
	for (int i = 0; i < no_bytes; ++i){
		*(dest + i) = *(source +i);
	}
}

void CGA_Screen::scroll(){
 	char *source;
 	char *dest;
 	for (int y = 0; y < MAX_ROWS; y++){
 		source = CGA_START + 2*(0 + (y+1)*MAX_COLS);
 		dest = CGA_START + 2*(0 + y*MAX_COLS);
		memorycopy(source, dest, 2*MAX_COLS);
 	}
}

bool CGA_Screen::handlescroll(int x, int y){
	if(y >= MAX_ROWS){
		return true;
	}
	if(x >= MAX_COLS && y == MAX_ROWS-1){
		return true;
	}
	return false;
}

void CGA_Screen::scrollup(int &col, int &row){
	if(!handlescroll(col, row)){
		return;
	}
	char *source;
	char *dest;
	for (int y = 0; y < MAX_ROWS; y++){
	 	source = CGA_START + 2*(0 + (y+1)*MAX_COLS);
	 	dest = CGA_START + 2*(0 + y*MAX_COLS);
		memorycopy(source, dest, 2*MAX_COLS);
	 }
	// change value of y
	row = MAX_ROWS - 1;
	col = 0;
}

void CGA_Screen::startMsg(){
	int col = 16;
	int row = 5;
	setpos(col, row++);
	print("     _________\n", 15, 0x03);
	setpos(col, row++);    
	print("    /---------\\\n", 16, 0x03);   
	setpos(col, row++);  
	print("___/", 4, 0x03);print("___",3,0x0a);print("  C  ",5,0x03);print("___",3,0x0a);print("\\__",3,0x03);print(" ___              ____  ___ \n", 29, 0x0a);                                     
	setpos(col, row++); 
	print(" \\\\",3,0x07);print("/",1,0x0a);print("---",3,0x07);print("\\   /",5,0x0a);print("---",3,0x07);print("\\",1,0x0a);print("//",2,0x07);print("|___  _|_  |   | |    )|___\n", 29, 0x0a);
	setpos(col+1, row++); 
	print(" |",2,0x0a);print("|",1,0x06);print(" O ",3,0x06);print("|",1,0x06);print("|",1,0x0a);print("-",1,0x07);print("|",1,0x0a);print("| O |",5,0x06);print("|   s \\  |   | u | |BBBB     \\\n", 33, 0x0a);                            
	setpos(col+2, row++); 
	print(" \\___/   \\___/   ___/  |__ |___| |____) ___/\n", 46, 0x0a);
	setpos(col, row++); 
	print("    |    /\\   |\n", 16, 0x06);
	setpos(col, row++);    
	print("   #############\n", 17, 0x07);    
	setpos(col, row++);
	print("    #### ",9,0x07);print("<>",2,0x06);print(" ####\n", 7, 0x07);
	setpos(col, row++);    
	print("     \\_",7,0x06);print("#####",5,0x07);print("_/\n", 5, 0x06);   
	setpos(col, row++); 
	print("        ###\n ", 13, 0x07);
	setpos(col, row++); 
	setpos(35, 15); 
	print("WILLKOMMEN IN OOStuB", 20, 0x07);  
}
/* Hier muesst ihr selbst Code vervollstaendigen */ 
