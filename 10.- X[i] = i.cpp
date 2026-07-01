
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int existe(vector<int>& vec, int inicio, int fin) {
	if (inicio <= fin)
	{
		int medio = inicio + (fin - inicio) / 2;
		if (vec[medio] == medio)
		{
			return medio;
		}
		else if (vec[medio] > medio)
		{
			return existe(vec, inicio, medio - 1);
		}
		else
		{
			return existe(vec, medio + 1, fin);
		}
	}      
	return -1;
}

int main() {
	vector<int> vec = {-4,-1,2,4,7,9,12};
	//sort(vec.begin(), vec.end());
	int resultado = existe(vec, 0, vec.size()-1);
	cout << resultado<<endl;

	return 0;
}
