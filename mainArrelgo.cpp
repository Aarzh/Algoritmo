#include "Arreglo.h"
#include <iostream>

using namespace std;

int main()
{
	Arreglo p;
	p.lecturaDatos("doc.txt");
	p.impArreglo();
	p.cocktailSort();
	p.impArreglo();
	return 0;
}