#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <deque>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int result = 0;
    deque<int> dq(n);
    iota(dq.begin(), dq.end(), 1);
    for (int i = 0; i < m; i++) 
    {
        int k;
        cin >> k;
        auto it = find(dq.begin(), dq.end(), k);
        int j = distance(dq.begin(), it);
        if (j > dq.size()-j) {
            result += dq.size()-j;
            rotate(dq.rbegin(), dq.rbegin()+dq.size()-j, dq.rend());
        }
        else if (dq.size()-j >= j)
        {
            result += j;
            rotate(dq.begin(), dq.begin()+j, dq.end());
        }
        dq.pop_front();
    }
    cout << result;
}