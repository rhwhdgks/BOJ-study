#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int MAX = 100;
vector <vector<int>> v(MAX);
vector <vector<int>> v2(MAX);
bool checked[MAX][MAX];
bool checked2[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n;
void dfs(int i, int j)
{
    if (checked[i][j]) return;
    checked[i][j] = true;
    for (int p = 0; p < 4; p++)
    {
        int x, y;
        x = i + dx[p];
        y = j + dy[p];
        if (x < 0 || x == n || y < 0 || y == n) continue;
        else {
            if (v[i][j] == v[x][y] && !checked[i][j]) {
                dfs(x,y);
            }
        }
    }
}
void dfs2(int i, int j)
{
    checked2[i][j] = true;
    for (int p = 0; p < 4; p++)
    {
        int x, y;
        x = i + dx[p];
        y = j + dy[p];
        if (x < 0 || x == n || y < 0 || y == n) continue;
        else {
            if (v2[i][j] == v2[x][y] && !checked2[i][j]) {
                dfs2(x,y);
            }
        }
    }
}
int main(){
    int ans = 0;
    int ans1 = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (char c : s) {
            if (c == 'R') {
                v[i].push_back(1);
                v2[i].push_back(1);
            }
            else if (c == 'B') 
            {
                v[i].push_back(3);
                v2[i].push_back(2);
            }
            else if (c == 'G') 
            {
                v[i].push_back(2);
                v2[i].push_back(1);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            checked[i][j] = false;
            checked2[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!checked[i][j]) {
                dfs(i, j);
                ans++;
            }
            if (!checked2[i][j]) {
                dfs2(i, j);
                ans1++;
            }
        }
    }

    cout << ans << " "<< ans1 << endl;

}