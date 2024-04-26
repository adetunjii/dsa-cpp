#include <iostream>
#include <string>

using namespace std;

string decode_string(const string& s, int& idx) {
	string res;

	while (idx < s.length() && s[idx] != ']') {
		if (!isdigit(s[idx])) res += s[idx++];
		else {
			int outer_num = 0;
			while (idx < s.length() && isdigit(s[idx])) {
				outer_num *= 10;
				outer_num += s[idx++] - '0';
			}

			idx += 1; // skip the opening bracket
			string decoded = decode_string(s, idx);
			idx += 1; // skip the closing bracket

			while (outer_num > 0) {
				res += decoded;
				outer_num -= 1;
			}
		}
	}

	return res;
}


string decodeString(string s) {
	int idx = 0;

	return decode_string(s, idx);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		cout << "Testcase #" << i+1 << ": " << decodeString(s) << "\n\n";
	}

	return 0;
}