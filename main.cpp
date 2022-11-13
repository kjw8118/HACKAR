#include <cstdlib>

#include "ES582.h"


int main()
{
	ES582 es582(ES582::DOUBLE_CAN);	
	es582.OpenCANController();
	es582.listening();

	system("pause");
}