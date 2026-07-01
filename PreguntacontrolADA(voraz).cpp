

#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
struct program
{
	int id;
	int capacidad;
	
	program(int i, int cap) {
		id = i;
		capacidad = cap;
	}
};

void maximizar(vector<program>& vec , int capacidad_disco) {
	std::sort(vec.begin(), vec.end(), [](const program& a, const program& b) {
		return  a.capacidad < b.capacidad;
	});
	
	int cap = 0;
	int n = 0;

	for (auto& it: vec)
	{
		if (cap + it.capacidad <= capacidad_disco )
		{
			cap = cap + it.capacidad;
			n++;
			cout << it.id << endl;
		}
	}
	cout << n << endl;
}


int main() {
	int capacidad_disco = 25;
	vector<program> vec = { {1,12} , {2,7}, {3,5} , {4,20},{5,9},{6,4} };
	maximizar(vec,capacidad_disco);


	return 0;
}
