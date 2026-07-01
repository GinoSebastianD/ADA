#include "iostream"
#include "vector"
#include "unordered_set"
#include "algorithm"
using namespace std;


vector<int> eliminar_duplicados(const vector<int>& izq , const vector<int>& der) {
	unordered_set<int> unicos;
	vector<int> result;
	for (auto it : izq)
	{
		unicos.insert(it);
	}
	for (auto it : der)
	{
		unicos.insert(it);
	}
	for (auto it: unicos)
	{
		result.push_back(it);
	}
	sort(result.begin(), result.end());

	return result;
}

vector<int> merge(vector<int>& vec, int inicio, int fin) {
	if (inicio == fin)
	{
		return { vec[inicio] };
	}
	int medio = inicio + (fin - inicio) / 2;
	vector<int> izq = merge(vec, inicio, medio);
	vector<int> der = merge(vec, medio + 1, fin);
	return eliminar_duplicados(izq , der);
}


void doble(vector<int>& vec) {
	if (vec.empty())
	{
		return;
	}
	vector<int> result = merge(vec, 0, vec.size() - 1);
	vec = result;
}


int main() {
	vector<int> vec = { 5, 2, 8, 2, 5, 9, 1, 8, 3 };

	doble(vec);
	for (auto it: vec)
	{
		cout << it << " ";
	}
}
