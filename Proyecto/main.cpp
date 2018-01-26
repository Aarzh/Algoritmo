#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
    vect A(3);
    vect B(3);

  A.populate(time(NULL), 10);
  A.printVector();

  B.populate(time(NULL), 10);
  B.printVector();

  vect resultado = A.suma(B);
  resultado.printVector();
  return 0;
}
