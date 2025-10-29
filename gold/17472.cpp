#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int island[11][11] = {0,};
bool visited[11][11];
int n, m;
vector <pair<int, int> > start;
int a[4] = {1, -1, 0, 0};
int b[4] = {0, 0, 1, -1};

void find(int n1, int m1, int key) {
    int n2,m2;
    for (int i= 0; i < 4; i++){
        n2 = n1 + a[i];
        m2 = m1 + b[i];
        if (n2 >= 0 && n2 < n && m2 >= 0 && m2 < m) {
            if (island[n2][m2] && !visited[n2][m2]) {
                island[n2][m2] = key;
                visited[n2][m2] = true;
                find(n2, m2, key);
            }
        }
    }
}


int main() {
    cin >> n >> m;

    
    int land[7][7] = {0,};
        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> island[i][j];
        }
    }
    
    int key = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (island[i][j] && !visited[i][j]) {
                find(i, j, key);
                island[i][j] = key;
                key++;
            }
        }
    }
    key--;
    cout << key << '\n';
    
    for (int i = 0; i < n; i++) {
        for (int l = 0; l < m; l++ ) {
            if (island[i][l] == 0) continue;
            int n1 = i;
            int m1 = l;
            int k = island[n1][m1];
            for (int j = 0; j < 4; j++) {
                int n2 = n1 + a[j];
                int m2 = m1 + b[j];
                if (island[n2][m2] == k) {
                    continue;
                }
                else if (!island[n2][m2]) {
                    int ans = 1;
                    while (n2 >= 0 && n2 < n && m2 >= 0 && m2 < m) {
                        n2 += a[j];
                        m2 += b[j];
                        cout << ans << '\n';
                        if (!island[n2][m2]) {
                            ans++;
                        }
                        else {
                            land[k][island[n2][m2]] = ++ans;
                            land[island[n2][m2]][k] = ans;
                        }
                    }
                }
            }
        
        }
    }



    
}