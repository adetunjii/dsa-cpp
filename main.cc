#include <iostream>

using namespace std;

// typedef struct {
// 	bool allocated;
// 	bool unallocated;
// 	unsigned int length;
// 	uint32_t op;
// 	char name[];
// } blockHeaderStruct;

// int main() {

// 	bool allocated;

// 	cout << "Sizeof unsigned int:: " << sizeof(unsigned int) << endl;
// 	cout << "Size of blockHeaderStruct:: " << sizeof(blockHeaderStruct) << endl;

// 	// You can do modulo operation using bitwise &
// 	// ex: 3 % 2 = 3 & (2-1)
// 	int num = 3;
// 	int divisor = 2;
// 	int result = num & (divisor - 1);

// 	cout << "Result: " << endl;

// 	return 0;
// }

int main() {

	vector<vector<int>> A = {
		{1, 2, 3}, 
		{4, 5, 6}, 
		{7, 8, 9}
	};


	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[i].size(); j++) {
			cout << A[i][j] << endl;
		}
	}

	return 0;
}