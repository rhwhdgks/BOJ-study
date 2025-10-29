/* 백준 골드5, 문제가 구현만 하면 되는 단순한 문제였기에 어려움은 딱히 없었음. 문자열 입력에 대한 이해를 높일 수 있던 문제*/
#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s, l;
        int m, k;
        cin >> l;
        cin >> m;
        cin >> s;
        int now = 0;
        deque <int> v;
        for (int j = 0; j < s.size(); j++) {
            k = s[j] - '0';
            if (k <= 9 && k >= 0) {
                now = now*10+k;
            }
            else if (now != 0) {
                v.push_back(now);
                now = 0;
            }
        }
        int pop = 1; 
        for (int z = 0; z < l.size(); z++) {
            if (s[z] == 'R') {
                pop *= -1;
            }
            else if (s[z] == 'D') {
                if (!v.empty()) {
                    if (pop == 1) {
                        v.pop_front();
                    }
                    else v.pop_back();
                }
                else {
                    cout << "error" << endl;
                    return 0;
                }
            }
        }
        cout << "[";
        while (!v.empty()) {
            if (pop == 1) {
                cout << v.front(); v.pop_front();
            }
            else {
                cout << v.back(); v.pop_back();
            }
            if (!v.empty()) {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
    
}