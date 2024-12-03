#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>

using namespace std;

bool isValidReport(vector<int> list) {
    int N = (int) list.size();
    bool ok = true;
    bool isIncreasing = true;
    bool isDecreasing = true;

    for (int i = 0; i < N - 1; i++) {
        int diff = list[i+1] - list[i]; 
        if (diff < 0) {
            isIncreasing = false;
        }

        if (diff > 0) {
            isDecreasing = false;
        }

        if (!((1 <= abs(diff)) && (abs(diff) <= 3))) {
            ok = false;
            break;
        }
    }

    return ok && (isIncreasing || isDecreasing);
}

int main() {
    int count = 0;
    int T = 1000;

    while(T--) {
        vector<int> list;

        while (true) {
            int N; 
            scanf("%d", &N);
            list.push_back(N);
            
            char c;
            scanf("%c", &c);
            if (c == '\n') {
                break;
            }

            bool isOk = false;
            auto remove = [&](int i) {
                vector<int> b = list;
                b.erase(b.begin() + i);
                isOk = isValidReport(b);
            };

            cout << "Printing list content :: " << endl;
            for (int num : list) {
                cout << num << " ";
            }
            cout << "\n" << endl; 

            int k = list.size();
            remove(0);
            for (int i = 0; i < k - 1; i++) {
                int diff = list[i+1] - list[i];
                if (abs(diff) < 1 || abs(diff) > 3) {
                    remove(i);
                    remove(i+1);
                    break;
                }

                if (i + 2 < k) {
                    int diff2 = list[i+2] - list[i+1];
                    if ((diff > 0) != (diff2 > 0)) {
                        remove(i);
                        remove(i+1);
                        remove(i+2);
                        break;
                    }
                }
            }

            if (isOk) {
                count += 1;
            }
        }
    }

    cout << count << endl;
}
