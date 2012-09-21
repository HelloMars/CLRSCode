#include "SortFunctors.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iterator>
using namespace std;

int main()
{
	const int SIZE = 100;
 	srand(time(NULL));
	std::vector<int> data(SIZE);
	std::for_each(data.begin(), data.end(), [](int& val){val=rand();});
// 	std::copy(data.begin(), data.end(), ostream_iterator<int>(cout, "\t"));
// 	cout << endl;

	std::vector<int> data_copy(data);
	InsertSortFunctor<vector<int>::iterator, std::less<int>> insert_sort;
	insert_sort(data_copy.begin(), data_copy.end());

	InsertSortFunction(data.begin(), data.end(), std::less<int>());

// 	std::copy(data.begin(), data.end(), ostream_iterator<int>(cout, "\t"));
// 	cout << endl;

	return 0;
}