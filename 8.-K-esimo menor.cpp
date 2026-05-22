
//8. Diseñe un algoritmo "divide y vencerás" que permita calcular el k−ésimo menor
//elemento de un vector.


#include "iostream"
#include "vector"


using namespace std;
int tam;
int buscar = 1;
int particion(std::vector<int>& vec, int inicio, int fin) {
	int pivote = vec[fin];
	int ant = inicio - 1;
	for (int i = inicio; i < fin; i++)
	{
		if (vec[i] < pivote)
		{
			ant++;
			std::swap(vec[i], vec[ant]);
		}

	}
	std::swap(vec[ant + 1], vec[fin]);



	return ant + 1;
}

void merge(std::vector<int>& vec, int inicio, int fin) {
	if (inicio <= fin)
	{

		int recibir_indice = particion(vec, inicio, fin);
		if (recibir_indice == buscar - 1)
		{
				cout << vec[recibir_indice] << endl;	
			return;
		}
		if (buscar-1 < recibir_indice)
		{
			merge(vec, inicio, recibir_indice - 1);
		}
		else
		{
			merge(vec, recibir_indice + 1, fin);
		}
	}

}

int main() {
	std::vector<int> vec = { 9,1,3,5,0,4,2 };
	tam = vec.size();
	
	merge(vec, 0, vec.size() - 1);
	for (auto it : vec)
	{
		cout << it << " ";
	}


}
