/*백준 골드5, 단순 구현 문제였지만 좌표에 대한 개념을 헷갈려 실수했고 범위에 대한 것도 꼼꼼히 재확인할 필요가 있어보임*/
#include <iostream>

using namespace std;

const int MAX = 50;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int room[MAX][MAX] = {0, };
int n, m;
int ans = 0;
int check(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx, ny;
        
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (room[nx][ny] == 0) {
            return 0;
        }
    }
    return 1;
}
void clean(int x, int y, int d) {
    if (room[x][y] == 0) {
        room[x][y] = 2;
        ans++;
        clean(x, y, d);
    }
    else if (check(x, y) == 1)
    {
        int k = d+2;
        if (k > 3) k -= 4;
        int nx, ny;
        nx = x + dx[k];
        ny = y + dy[k];
        if (room[nx][ny] == 1 || nx < 0 || nx >= n || ny < 0 || ny >= m){
            return;
        } 
        else clean(nx, ny, d);
    }
    else {
        int k = d;
        for (int i = 0; i < 4; i++)
            {
                k = (k+3)%4;
                int nx, ny;
                nx = x + dx[k];
                ny = y + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || room[nx][ny] != 0)
                {
                    continue;
                }
                else if (room[nx][ny] == 0) {
                    clean(nx, ny, k);
                    break;
                }
            }
        
    }
    return;
}


int main(){
    cin >> n >> m;
    int x, y, d;
    cin >> x >> y >> d;
    for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                {
                    cin >> room[i][j];
                }
        }
    clean(x, y, d);
    cout << ans << endl;
}