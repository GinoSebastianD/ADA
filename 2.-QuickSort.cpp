
#include <iostream>
#include <vector>
using namespace std;

int particion(std::vector<int>& vec, int ini , int fin) {
	int pivot = vec[ini];
	int i = ini + 1;
	int j = fin;

	while (true)
	{
		while (i <= fin && vec[i] <= pivot) {
			i++;
		}
		while (vec[j] > pivot) {
			j--;
		}
		if (i >= j) {
			break;
		}
		swap(vec[i], vec[j]);
	}
	swap(vec[ini], vec[j]);
	return j;
}



void quicksort(std::vector<int>& vec , int ini , int fin) {
	if (ini < fin)
	{
		int pivot = particion(vec,ini,fin);
		quicksort(vec, ini, pivot - 1);
		quicksort(vec, pivot + 1, fin);
	}
}


int main() {			 // 6,1,3,5,0,4,2,7,8,9
	std::vector<int> vec= { 9,1,3,5,0,4,2,6,8,7 };
	quicksort(vec, 0, vec.size() - 1);
	for (auto n : vec)
	{
		cout << n << " ";
	}
}
