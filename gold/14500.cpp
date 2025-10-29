/*백준 골드 4, 브루트포스 방식과 dfs 방식 두가지 풀이 방법이 있지만, 브루트포스 방식을 잘 생각하지 못해서 좀 돌아간 부분이 있음. 이런 구현 문제 같은 경우에는
시간 복잡도 체크 후 구현에 더 신경 쓰는 것이 필요해 보임*/
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 500;
int paper[MAX][MAX] = {0, };
bool visited[MAX][MAX];
int ans = 0;
int n,m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void dfs(int x, int y, int depth, int sum) {
    if (depth == 4) {
        ans = max(ans, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx, ny;
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (!visited[nx][ny]) {
            visited[nx][ny] = true;
             dfs(nx, ny, depth+1, sum+paper[nx][ny]);
             visited[nx][ny] = false;
        }
    }
}
void dfs2(int x, int y) {
    int sum = paper[x][y];
    int pop = 1001;
    for (int i = 0; i < 4; i++) {
        int nx, ny;
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) return;
        sum += paper[nx][ny];
        pop = min(pop, paper[nx][ny]);
    }
    ans = max(ans, sum - pop);
}
int main() {

    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dfs(i, j, 1, paper[i][j]);
            dfs2(i, j);
        }
    }
    cout << ans << endl;
}