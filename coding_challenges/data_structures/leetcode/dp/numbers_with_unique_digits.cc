#include <iostream>

using namespace std;

// this algorithm runs in O(N) time
// The intuition behind solving this problem is that as N increases, the row reduces.
// Row is the the possible numbers between 1-9 (in hundredths) that cannot be duplicates
// Row: [0-9, 10 - 99, 100 - 999, 1000 - 9999 ...]
int numbersWithUniqueDigits(int n) {

	if (n == 0) return 1;
	if (n == 1) return 10;

	int res = 10;
	int uniqueNumbers = 81; // [9 * 9] => between [10 - 99]
	int rowsLeftToExplore = 8;

	for (int i = 2; i <= n; i++) {
		res += uniqueNumbers;
		uniqueNumbers *= rowsLeftToExplore;

		/* reduce the rows left to explore because the wider the range of the number,
		 * the more duplicates you get from the top
		 *
		 * for ex: 1000 - 1020 all contain duplicates. 
		 * 
		 */
		rowsLeftToExplore -= 1; 
	}

	return res;
}

int main() {

	int N;
	while(cin >> N) 
		cout << numbersWithUniqueDigits(N) << "\n";

	return 0;
}