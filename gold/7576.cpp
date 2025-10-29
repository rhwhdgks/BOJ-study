#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> m >> n;
    int notasty = 0;
    int tomato[1001][1001];
    vector<vector<int>> a(n, vector<int>(m));
    queue<pair<int, int>> t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1){
                t.push({i, j});
            }
            else if (tomato[i][j] == 0){
                notasty++;
            }
        }
    }

    if (notasty == 0) {
        cout << 0 << '\n';
        return 0;
    }

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int days = 1;

    while (!t.empty()) {
        int x, y;
        x = t.front().first;
        y = t.front().second;
        t.pop();

        for (int dir=0; dir<4; ++dir) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if (tomato[nx][ny] != 0) continue;
            
            tomato[nx][ny] = tomato[x][y]+1;
            notasty--;
            days = max(days, tomato[nx][ny]); 
            t.push({nx,ny});
        }
    }

    if (notasty > 0) cout << -1 << '\n';
    else cout << days << '\n';
    return 0;

}   