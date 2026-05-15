
/*1. Ordene el siguiente vector de números enteros ( 9 1 3 5 0 4 2 6 8 7 )
a. ... utilizando el algoritmo Mergesort.
*/
#include <iostream>
#include <vector>
using namespace std;


void particion(std::vector<int>&vec , int inicio, int medio,int fin) {
	std::vector<int> arr_izq(vec.begin() + inicio, vec.begin() + medio + 1);
	std::vector<int> arr_der(vec.begin() + medio + 1, vec.begin() + fin+1);

	int izq = 0, der = 0, k = inicio;

	while (izq < arr_izq.size() && der < arr_der.size() )
	{
		if (arr_izq[izq] <= arr_der[der])
		{
			vec[k++] = arr_izq[izq++];
		}
		else
		{
			vec[k++] = arr_der[der++];
		}
	}

	while (izq < arr_izq.size())
	{
		vec[k++] = arr_izq[izq++];
	}
	while (der < arr_der.size())
	{
		vec[k++] = arr_der[der++];
	}
}



void merge(std::vector<int> &vec , int inicio , int fin) {
	if (inicio < fin)
	{
		int medio = (inicio + fin) / 2;
		merge(vec, inicio, medio);
		merge(vec, medio + 1, fin);
		particion(vec,inicio,medio,fin);
	}

}


int main() {
	std::vector<int> vec= { 9,1,3,5,0,4,2,6,8,7 };
	merge(vec, 0, vec.size() - 1);
	for (auto n : vec)
	{
		cout << n << " ";
	}
}






