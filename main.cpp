#include <cstdlib>

#include "ES582.h"


int main()
{
	ES582 es582;	
	es582.OpenCANController();
	//es582.listening();

	system("pause");
}