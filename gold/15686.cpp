#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, c, h, ans;
vector <pair<int, int>> chicken, house, final;
bool check[13];

int dist() {
    int s = 0;
    for (int i = 0; i < house.size(); i++) {
        int l = 100000;
        int x = house[i].first;
        int y = house[i].second;
        for (int j = 0; j < final.size(); j++) {
            int x2 = final[j].first;
            int y2 = final[j].second;
            l = min(l, abs(x-x2)+abs(y-y2));    
        }
        s += l;
    }
    return s;
}
void select(int idx, int cnt) {
    if (cnt == m) {
        ans = min(ans, dist());
        return;
    }
    for (int i = idx; i < c; i++) {
        if (check[i] == true) continue;
        check[i] = true;
        final.push_back(chicken[i]);
        select(idx, cnt+1);
        check[i] = false;
        final.pop_back();
    }
}

int main() {
    cin >> n >> m;
    
    vector<vector<pair<int,int>>> distance;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int k;
            cin >> k;
            if (k == 1) {
                house.push_back({i, j});
            }
            else if (k == 2) {
                chicken.push_back({i, j});
            }
        }
    }
    c = chicken.size();
    h = house.size();

    select(0, 0);
    cout << ans;
}   