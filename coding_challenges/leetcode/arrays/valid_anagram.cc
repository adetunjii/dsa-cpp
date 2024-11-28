#include <iostream>
#include <unordered_map>

class Solution {
	public:
		bool isAnagram(std::string& s, std::string& t) {
			if (s.size() != t.size()) return false;

			std::unordered_map<char, int> m;

			for (int i = 0; i < s.size(); i++) {
				m[s[i]] += 1;
			}

			for (int j = 0; j < t.size(); j++) {
				if (m[t[j]] - 1 == 0) m.erase(t[j]);
				m[t[j]] -= 1;
			}

			return m.size() == 0;
		}
};