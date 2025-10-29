#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

bool visited[26][26];
int house[26][26];
int n;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int dfs(int x, int y) {
    visited[x][y] = true;
    int cnt = 1; 
    for (int dir=0; dir<4; ++dir) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx<0 || ny<0 || nx>=n || ny>=n) continue;
        if (!visited[nx][ny] && house[nx][ny]==1) {
            cnt += dfs(nx, ny);
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int result = 0;
    cin >> n;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
            house[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && house[i][j]) {
                int p = dfs(i, j);
                if (p) {
                    ans.push_back(p);
                    result++;
                    
                }
            }
        }
    }
    cout << result << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }


    
}