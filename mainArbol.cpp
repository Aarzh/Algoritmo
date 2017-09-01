#include "BST.h"
#include <iostream>

using namespace std;

int main()
{
	ArbolBinario p1;
	p1.crear("doc.txt");
	p1.preorden(p1.raiz);
	cout<<endl;
	p1.inorden(p1.raiz);
	cout<<endl;
	p1.postorden(p1.raiz);
	/*	p1.imprime();
	cout<<endl;
	p1.insertar(2);
	cout<<endl;
	//p1.elimina(17);
	cout<<endl;
	p1.insertar(680);
	cout<<endl;
	p1.buscar(2, p1.raiz);
	cout<<endl;
	p1.buscar(505, p1.raiz);
	cout<<endl;
	p1.imprime();
	cout<<endl;
	p1.elimina(76);
	cout<<endl;
	p1.insertar(2);
	cout<<endl;
	p1.insertar(30);
	cout<<endl;
	p1.imprime();
	cout<<endl;

	//p1.imprimeArbol(p1.raiz, 0);
	/*p1.crearArbol(p1.raiz);
	cout<<endl;*/
	return 0;
}