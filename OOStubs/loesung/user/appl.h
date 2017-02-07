/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

#ifndef __application_include__
#define __application_include__

#include "thread/entrant.h"
#include "syscall/thread.h"
#include "machine/key.h"
#include "syscall/guarded_buzzer.h"
#include "meeting/bellringer.h"

class Application : public Thread
 
 {
private:
    Application (const Application &copy); // Verhindere Kopieren
	Guarded_Buzzer buzzer;
public:
	int row;
	int col;
	int i;
	int id;

    Application(void* tos): Thread(tos), i(0){} 
    void action ();
    void setCoord(int c, int r){ col = c; row = r;}
 };

/*###########################################################*/

 class Keyboard_App : public Thread
 
 {
private:
    Keyboard_App (const Keyboard_App &copy); // Verhindere Kopieren
    //Guarded_Keyboard guarded_keyboard;
    Key key;
public:
	int row;
	int col;
	int i;
	int id;
	int count;

    Keyboard_App(void* tos): Thread(tos), i(0), count(0){
		//buzzer.set(10);
	} 
    void action ();
    void setCoord(int c, int r){ col = c; row = r;}
 };
 
 /*###########################################################*/

 class EmptyApp : public Thread
 
 {
private:
    EmptyApp (const EmptyApp &copy); // Verhindere Kopieren
	Guarded_Buzzer buzzer;
public:
	enum {OFF=0, START=1, ON=2, PAUSE=3, OVER=4};
	int row;
	int col;
	int i;
	int id;
    EmptyApp(void* tos): Thread(tos), i(0){} 
    void action ();
    void setCoord(int c, int r){ col = c; row = r;}
    void show_digit(int to_show, int col, int row);
	void gameover(int x, int y, char color);
 };

/*#############################################################*/
class Start : public Thread
 
 {
private:
    Start (const Start &copy); // Verhindere Kopieren
	Guarded_Buzzer buzzer;
public:
    Start(void* tos): Thread(tos){} 
	void game_logo1(int x, int y, char color);
	void game_logo2(int x, int y, char color);      
	void instruction(int x, int y, char color);

	void clear_game_logo1(int x, int y);
	void clear_game_logo2(int x, int y);
	void clear_instruction(int x, int y);
    void action ();
 };

#endif
