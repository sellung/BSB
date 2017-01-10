/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            O _ S T R E A M                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse O_Stream enthaelt die Definition des << Operators fuer die     */
/* wichtigsten der vordefinierten Datentypen und realisiert somit die        */
/* bekannte Ausgabefunktion der C++ IO_Stream Bibliothek. Zur Zeit wird die  */
/* Darstellung von Zeichen, Zeichenketten und ganzen Zahlen unterstuetzt.    */
/* Ein weiterer << Operator erlaubt die Verwendung von Manipulatoren.        */
/*                                                                           */
/* Neben der Klasse O_Stream sind hier auch die Manipulatoren hex, dec, oct  */
/* und bin fuer die Wahl der Basis bei der Zahlendarstellung, sowie endl     */
/* fuer den Zeilenumbruch definiert.                                         */
/*****************************************************************************/

#include "object/o_stream.h"

/* Hier muesst ihr selbst Code vervollstaendigen */

void O_Stream::flush(){}

O_Stream& O_Stream::operator>> (unsigned char c){
	this->put(c);
	return *this;
}

O_Stream& O_Stream::operator<< (unsigned char c){
	this->put(c);
	return *this;
}

O_Stream& O_Stream::operator<< (char c){
	if(c < 0){
		this->put('-');
	}
	this->put(c);
	return *this;
}

O_Stream& O_Stream::operator<< (unsigned short number){
	if(number == 0){
		this->put('0');
	}
	char str[128] = {0}; // large enough for an int event on 64 bit;
	unsigned int  i = 127;

	while (number != 0){
        str[i--] = '0' + (number % 10);
        number /= 10;
    }
    for (int j = i+1; j < 128; j++)
    {
    	this->put(str[j]);
    }
	return *this;
}

O_Stream& O_Stream::operator<< (short number){
	if(number < 0 ){
		this->put('-');
		number *= -1;
	}
	unsigned short num = number;
	return *this << num;
}

O_Stream& O_Stream::operator<< (unsigned int number){
    numbertostring(number, zahlensystem);
	return *this;
}

O_Stream& O_Stream::operator<< (int number){
	
	if(number < 0){

		if(zahlensystem == dec){
			this->put('-');
			number = -number;
		}
	
		numbertostring(number, zahlensystem);
	}else{
		numbertostring(number, zahlensystem);
	}
	return *this;
}

O_Stream& O_Stream::operator<< (unsigned long number){
	if(number == 0){
		this->put('0');
	}
	char str[128] = {0}; // large enough for an int event on 64 bit;
	unsigned int  i = 127;

	while (number != 0){
        str[i--] = '0' + (number % 10);
        number /= 10;
    }
    for (int j = i+1; j < 128; j++)
    {
    	this->put(str[j]);
    }
	return *this;
}

O_Stream& O_Stream::operator<< (long number){
	if(number < 0 ){
		this->put('-');
		number *= -1;
	}
	unsigned long num = number;
	return *this << num;
}
O_Stream& O_Stream::operator<< (void* pointer){
	*this << '0' << 'x';
	int number = (int) pointer;
	while (number != 0){
		int c = number % 16;
        //O_Stream::put((char)(number%10));
        if(c <= 9 ){
			*this << c;
		}else {
			*this << char('A' - 10 + c);
		}
        number /= 16;
    }
    return *this ;
}

O_Stream& O_Stream::operator<< (char* text){
	// screen.print("\n *TE", 5, 0x02);
	int i = 0;
	char c = *(text + i);
	while(c != '\0'){
		this->put(c);
		// screen.print("\n c", 3, 0x02);
		i++;
		c = *(text + i);
	}
	return *this;
}

void O_Stream::numbertostring(unsigned long number, int base){
	if(number == 0){
		this->put('0');
		return;
	}
	char str[128] = {0}; // large enough for an int event on 64 bit;
	int i = 0;
	do{
		str[i] = digits[number % base];
		i++;
		number /=base;
	} while (number!=0);
	for (int j = i-1; j >= 0; j--){
    	this->put(str[j]);
    }
}

void O_Stream::numbertostring2(long number, int base){
	if(number == 0){
		this->put('0');
		return;
	}
	if(number < 0){
		if(base == dec){
			this->put('-');
			numbertostring(-number, base);
			return;
		}
		number = -number;
		int num[128] ={0};
		int i = 0;
		do{
			num[i] = base - (number % base);
			i++;
			number /=base;
		} while (number!=0);

		bool term = false;
		for (int j = 0; j < i; j++){
			if(num[j] + 1 >= base){
				num[j] = 0;
				continue;
			}else{
				num[j] += 1;
				term = true;
				break;
			}
    	}
    	if(!term){
    		num[i] = base-1;
    		i++;
    	}
		for (int j = i-1; j >= 0; j--){
	    	this->put(digits[num[j]]);
	    }
	}
}

O_Stream& O_Stream::operator<< (O_Stream& (*fkt) (O_Stream&)){
	return fkt(*this);
}

O_Stream& O_Stream::operator>> (O_Stream& (*fkt) (O_Stream&)){
	return fkt(*this);
}

O_Stream& endl (O_Stream& os)
{
	os << '\n';
	os.flush(); 
	return os;
}

O_Stream& bin (O_Stream& os){
	os.zahlensystem = O_Stream::bin;
	return os;
}

O_Stream& oct (O_Stream& os){
	os.zahlensystem = O_Stream::oct;
	return os;
}

O_Stream& dec (O_Stream& os){
	os.zahlensystem = O_Stream::dec;
 	return os;
 }
 
 O_Stream& hex (O_Stream& os){
 	os.zahlensystem = O_Stream::hex;
 	return os;
 }
