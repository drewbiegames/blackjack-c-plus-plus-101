#include "input.h"
#include <conio.h>

// Gets input without making loops wait
KeyType Input::ReadInput(){
	int KBcode = 0;

	if (_kbhit())
	{
		KBcode = _getch();
	}

	return (KeyType)KBcode;
}