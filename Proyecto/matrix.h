#include <vector>
#include <iostream>
#include <random>
#include <omp.h>

using namespace std;

class matrix
{
public:
  vector<vector<double>> matrixData; // M: Filas, N:Columnas
  int M;
  int N;

  matrix(){};

  matrix(int M, int N)
  {
    this->M = M;
    this->N = N;
    matrixData.resize(M);

    for(int i=0; i<M; i++)
    {
      matrixData[i].resize(N);
    }

    cout << "se definio matriz de " << M << " x " << N << endl;
  }

  matrix mult(matrix B)
  {
    if(N == B.M)
    {
      int i, j, k;
      matrix C(M, B.N);

      #pragma omp parallel shared(B, C)
      {
        #pragma omp for private(i, j, k)
        for(i=0; i<M; i++)
        {
          for(j=0; j<B.N; j++)
          {
            C.matrixData[i][j] = 0;
            for(k = 0; k<N; k++)
            {
              C.matrixData[i][j] += matrixData[i][k] * B.matrixData[k][j];
            }
          }
        }
      }
      return C;
    }else{
      cout << "error: A.N debe de ser igual a B.M" << endl;
      return *this;
    }
  }
};
