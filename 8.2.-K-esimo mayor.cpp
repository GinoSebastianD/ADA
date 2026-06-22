#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;
int tam;
int buscar = 2;
int particion(std::vector<int>& vec, int inicio, int fin) {
	int pivote = vec[fin];
	int ant = inicio - 1;
	for (int i = inicio; i < fin ; i++)
	{
		if (vec[i] < pivote)
		{
			ant++;
			swap(vec[ant], vec[i]);
		}
	}
	swap(vec[fin], vec[ant + 1]);
	return ant + 1;
}

void merge(std::vector<int>& vec, int inicio, int fin) {
	if (inicio<=fin)
	{
		int indice = particion(vec, inicio, fin);
		if (tam- buscar == indice) //busca-1 --> si s l k-simo mnor
		{
			cout << vec[indice] << endl;
			return;
		}
		if (tam - buscar < indice)
		{
			merge(vec, inicio, indice - 1);
		}
		else
		{
			merge(vec, indice + 1, fin);
		}
	}

}							

int main() { //              0 1 2 3 4 5 9
	std::vector<int> vec = { 9,1,3,5,0,4,2 };
	tam = vec.size();

	merge(vec, 0, vec.size() - 1);
	for (auto it : vec)
	{
		cout << it << " ";
	}


}
