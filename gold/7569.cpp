#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, h;
    cin >> m >> n >> h;
    int notasty = 0;
    int tomato[101][101][101];
    queue<tuple<int, int, int>> t;
    for(int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++) {
                    cin >> tomato[i][j][k];
                    if (tomato[i][j][k] == 1){
                        t.push({i, j, k});
                    }
                    else if (tomato[i][j][k] == 0){
                            notasty++;
                    }
                }
            }
    }
        

    if (notasty == 0) {
        cout << 0 << '\n';
        return 0;
    }

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int dz[2] = {1, -1};
    int days = 1;

    while (!t.empty()) {
        auto [x, y, z] = t.front();
        t.pop();

        for (int dir=0; dir<4; ++dir) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if (tomato[nx][ny][z] != 0) continue;
            
            tomato[nx][ny][z] = tomato[x][y][z]+1;
            notasty--;
            days = max(days, tomato[nx][ny][z]); 
            t.push({nx,ny, z});
        }
        for (int dir=0; dir<2; ++dir) {
            int nz = z + dz[dir];
            if (nz >= h || nz < 0) continue;
            if (tomato[x][y][nz] != 0) continue;
            
            tomato[x][y][nz] = tomato[x][y][z]+1;
            notasty--;
            days = max(days, tomato[x][y][nz]); 
            t.push({x,y, nz});
        }
    }

    if (notasty > 0) cout << -1 << '\n';
    else cout << days-1 << '\n';
    return 0;

}   