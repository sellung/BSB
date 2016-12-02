#ifndef __screen_include__
#define __screen_include__

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

#include "machine/io_port.h"

#define MAX_ROWS  25
#define MAX_COLS  80
#define CGA_START (char *)0xb8000

class CGA_Screen
 {
private:
   CGA_Screen(const CGA_Screen &copy); // Verhindere Kopieren
/* Hier muesst ihr selbst Code vervollstaendigen */ 
   //const char *CGA_START = (char *) 0xb8000;
   IO_Port indexPort ;//= IO_Port(980); // 0x3d4 = 980
   IO_Port datenPort ;//= IO_Port(981); // 0x3d5 = 981
   int cursor_x;
   int cursor_y;

public:
   CGA_Screen(): indexPort(0x3d4), datenPort(0x3d5)
   {
      // clearscreen();
      setpos(0,0);
   }
   void show(int x, int y, char c, unsigned char attrib);
   void setpos(int x, int y);
   void getpos(int &x, int &y);
   void print(char* text, int length, unsigned char attrib);
   void clearscreen();
   void startMsg();
   /* Copy bytes from one place to another . */
   void memorycopy(char * source , char * dest , int no_bytes );

   bool handlescroll(int x, int y);
   void scrollup(int &x, int &y);

   void clearRow(int row);
   void scroll();
 };

/* Hier muesst ihr selbst Code vervollstaendigen */ 

#endif

