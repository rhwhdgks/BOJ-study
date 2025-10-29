/* 맨 처음에 바로 bfs로 풀지 못하고 dfs로 시작하는 바람에 시행착오가 좀 있었음. 백준 문제를 해결할때에는 const int로 MAX 값 주고 배열 만드는 게
좋아보임 이게 코테에서 나올 수 있는 bfs 난이도와 제일 유사할 듯함*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 1000;
struct Node {int x, y, z; };
int map[MAX][MAX] = {0,};
int ans[MAX][MAX][2];
int main() {
    int n, m;
    cin >> n >> m;
    int now = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
    queue <Node> q;
    q.push({0, 0, 0});
    ans[0][0][0] = 0;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while(!q.empty()){
        auto [x,y,z] = q.front(); q.pop();
        if (x == n-1 && y == m-1) {
            cout << ans[x][y][z] << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx, ny;
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                
            if (map[nx][ny] == 0 && ans[nx][ny][z] == 0 ){
                ans[nx][ny][z] = ans[x][y][z] + 1;
                q.push({nx, ny, z});
            }
            else if (map[nx][ny] == 1 && z == 0 && ans[nx][ny][1] == 0){
                ans[nx][ny][1] = ans[x][y][z] + 1;
                q.push({nx, ny, 1});
            }
        }
        
    }
    cout << -1 << endl;
}