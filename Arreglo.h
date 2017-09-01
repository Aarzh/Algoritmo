/*#ifndef ARREGLO_H
#define ARREGLO_H*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Arreglo
{
public:
	Arreglo();
	~Arreglo(){};
	void lecturaDatos(string archivo);
	int busquedaSecuencial(int k);
	int busquedaBinaria(int inicio, int fin, int k);
	void merge(int inicio, int mid, int fin);
	void quickSort(int lo, int hi);
	void cocktailSort()
	{
	    bool swapp = true;
	    int principio = 0;
	    int fin = size-1;
	    while (swapp)
	    {
	        swapp = false;
	        for (int i = principio; i < fin; ++i)
	        {
	            if (array[i] > array[i + 1])
	            {
	                swap(array[i], array[i+1]);
	                swapp = true;
	            }
	        }
	         if (!swapp)
	            break;
	         swapp = false;
	         --fin;
	        for (int i = fin - 1; i >= principio; --i)
	        {
	            if (array[i] > array[i + 1])
	            {
	                swap(array[i], array[i+1]);
	                swapp = true;
	            }
	        }
	        ++principio;
	    }
	}
	void shellSort()
	{
		int temp;
	// Gap 'i' between index of the element to be compared, initially n/2.
		for(int i = size/2; i > 0; i = i/2)
		{
			for(int j = i; j < size; j++)
			{
				for(int k = j-i; k >= 0; k = k-i)
				{
					if(array[k+i] >= array[k])
					break;
					else
					{
						swap(array[k],array[k+1]);
					}
				}
			}
		}
	}
	void selectionSort()
	{
		int cont;
		for (int i = 0; i < size; ++i)
		{
			int min=i;
			for (int j = 0; j < size; ++j)
			{
				if (array[j]<array[min])
				{
					min=j;
					cont++;
				}
			}
			swap(i, min);
		}
		impArreglo();
	}
	int particion(int lo, int hi)
	{
		int tmp;
		int i=lo;
		int j=hi+1;
		int pivot=array[lo];
		while(i<=j)
		{
			impArreglo();
			while(array[i]<pivot)
				++i;
			while(array[j]>pivot)
				--j;
			if (i>=j)
			{
				break;
			}
			else
			{
				tmp=array[i];
				array[i]=array[j];
				array[j]=tmp;
			}
		}
		pivot=array[j];
		return j;
	}
	void mergeSort(int inicio, int fin)
	{
		int mid=0;
		cout<<inicio;
		if (inicio<fin)
		{
			cout<<mid<<" "<<inicio<<" "<<fin;
			mid=inicio+(fin-inicio)/2;
			mergeSort(inicio, mid);
			mergeSort(mid+1, fin);
			merge(inicio, mid, fin);
		}
	}
	int getSize()
	{
		return size;
	}
	int swap(int el1, int el2)
	{
		int temp=array[el1];
		array[el1]=array[el2];
		array[el2]=temp;
	}
	void bubbleSort();
	void impArreglo()
	{
		for (int i = 0; i < size+2; ++i)
		{
			cout<<array[i]<<" ";
		}
		cout<<"\n";
	}
private:
	int *array;
	int *copia;
	int aux;
	int size;
	int posicion(int p, int k);
};
Arreglo::Arreglo()
{
	size=0;
}
int Arreglo::posicion(int p, int k)
{
	if(size==p)
		return -1;
	else
	{
		if (array[p]==k)
		{
			return p;
		}
		else
			return posicion(p+1, k);
	}
}
void Arreglo::lecturaDatos(string archivo)
{
	string line;
	int pos=0;
	ifstream myfile (archivo);
	if(myfile.is_open())
	{
		while(getline(myfile, line))
		{
			if (size==0)
			{
				size=stoi(line);
				array=new int[size];
				copia=new int[size];
			}
			else
			{
				array[pos]=stoi(line);
				copia[pos]=stoi(line);
				++pos;
			}
		}
	}
}
int Arreglo::busquedaSecuencial(int k)
{
	return posicion(0, k);
}
int Arreglo::busquedaBinaria(int inicio, int final, int k)
{
	int tam=0;
	if (inicio==final)
	{
		if(array[inicio]==k)
			return inicio;
		else
			return -1;
	}
	else
	{
		if ((final+inicio)%2==0)
		{
			tam=(final+inicio)/2;
		}
		else
		{
			tam=((final+inicio)+1)/2;
		}
		if (array[tam]>=k)
		{
			if (array[tam]==k)
			{
				return tam;
			}
			else
			{
				return busquedaBinaria(inicio, tam, k);
			}
		}
		else
		{
			return busquedaBinaria(tam, final, k);
		}


	}
}
void Arreglo::merge(int inicio, int mid, int fin)
{
	int h=inicio; //para poderlas manejar como dos contadores 
	int i=inicio;
	int j=mid+1;
	int k;
	while((j<=fin)&&(h<=mid))
 	{
		if(array[h]<=array[j])//si es menor, lo copiamos al arreglo copia
  		{
   			copia[i]=array[h];
   			++h;
  		}
		else//de lo contrario lo copiamos el otro
		{
			copia[i]=array[j];
	   		++j;
	  	}
  		i++;//incrementamos la posicion en el copia
 	}
	if(h>mid)//si inicio es mayor a mid, copiamos los elementos
 	{
  		for(k=j; k<=fin; ++k)
  		{
   			copia[i]=array[k];
   			i++;
  		}
 	}
 	else//copiamos la otra mitad de los elementos
 	{
  		for(k=h;k<=mid;k++)
  		{
   			copia[i]=array[k];
   			i++;
 		}
 	}
	for(k=inicio; k<=fin; ++k)//acabamos con lo que falta
 	{
    	array[k]=copia[k];
 	}
 	impArreglo();
}
void Arreglo::bubbleSort()
{
	bool band=false;
	for (int i = 1; i <=size; ++i)
	{
		band=false;
		for (int j = 0; j <=size-i; ++j)
		{
			if (array[j]>array[j+1])
			{
				aux=array[j];//funcion intercambia
				array[j]=array[j+1];
				array[j+1]=aux;
				band=true;
				impArreglo();
			}
		}
		if (band)
		{
			break;
		}
	}
}
void Arreglo::quickSort(int lo, int hi)
{
	if (hi<=lo)
	{
		return;
	}
	int j=particion(lo, hi);
	quickSort(lo, j-1);
	quickSort(j+1, hi);
}