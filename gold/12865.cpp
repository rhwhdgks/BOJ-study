#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    int n, k, w, v;
    cin >> n >> k;
    int ans = 0;
    vector <pair<int, int>> bag;
    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        bag.push_back({w, v});
    }
    vector<int> dp(k+1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = k; j >= bag[i].first; j--) {
            dp[j] = max(dp[j], dp[j-bag[i].first]+bag[i].second);
        }
    }
    cout << dp[k] << endl;
}