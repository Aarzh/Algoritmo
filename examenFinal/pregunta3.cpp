#include <iostream>
#include <vector>

using namespace std;

class Matriz
{
public:
    int N;
    int M;
    vector < vector <int> > matrixData; // M: Filas, N:Columnas
    Matriz(){};
    matrix(int N, int M)
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
    ~Matriz(){};
	void selectionSort()
	{
		int cont;
    		for (int j = 0; j < B.N; ++j)
    		{
    			int min=j;
    			for (int i = 0; i < M; ++i)
    			{
    				if (matrixData[i][j]<matrixData[i+1][j])
    				{
    					min=i+1;
    					cont++;
    				}
    			}
    			swap(i, min, j);
    		}
	}
    int swap(int el1, int el2, int pos2)
    {
        int temp=matrixData[i][j];
        matrixData[i][j]=matrixData[min][j];
        matrixData[min][j]=temp;
    }
};
