
#include "iostream"
#include "vector"


using namespace std;
int tam;
int particion(std::vector<int>& vec, int inicio,int fin, int indice) {
	int pivote = vec[fin];
	int ant = inicio -1;
	for (int i = inicio ; i< fin ; i++)
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
		
		int indice = (tam - 1) / 2;
		int recibir_indice = particion(vec, inicio, fin,indice);
		if (indice == recibir_indice)
		{
			if (tam % 2 == 1)
			{
				cout << vec[recibir_indice] << endl;
			
			}
			else
			{
				cout << (vec[recibir_indice] + vec[recibir_indice + 1]) / 2.0 << endl;
			
			}
			return;
		}
		if (indice < recibir_indice)
		{
			merge(vec, inicio, recibir_indice - 1);
		}
		else
		{
			merge( vec, recibir_indice + 1 , fin);
		}
	}
	
}

int main() {
	std::vector<int> vec = { 9,1,3,5,0,4,2,6,8,7 };
	tam = vec.size();
	merge(vec, 0, vec.size() - 1);
	for (auto it : vec) 
	{
		cout << it << " ";
	}
	

}
