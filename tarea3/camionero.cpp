//Complejidad: O(n)

#include <iostream>
using namespace std;

void paro(int kmRecorridos, int n, int *numGas, int gasolineras)
 {
	int i = 0;
	int temp = 0;
	while (gasolineras > i)
	 {
		if (n - kmRecorridos == (numGas[i + 1] - numGas[i]) || n - 1 == (numGas[i + 1] - numGas[i]))
		{
			cout << "Carga gasolina en la gasolinera # " << numGas[i] << endl;
			kmRecorridos = 0;
		}
		else {
			cout << "No es necesario cargar" << endl;
		}
		i++;
		kmRecorridos++;
		temp++;

	}
}

int main()
{
	int distancia = 20;
	int n = 5;
	int numeroDegasolineras = 8;
  int gasolineras[numeroDegasolineras] =  {1, 2, 3, 5, 7, 11, 15, 19};
  paro(0, n, gasolineras, numeroDegasolineras);

  return 0;
}
