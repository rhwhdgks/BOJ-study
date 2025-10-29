#include <iostream>
#include <tuple>
#include <limits.h>
#include <vector>
#include <queue>
using namespace std;

typedef tuple <int, int, int> edge;
int main() {

    int n, s, e, m;
    cin >> n >> s >> e >> m;
    vector <edge> bus;
    vector <int> earn;
    vector <long> city;
    vector <bool> visited;
    vector <vector<int>> ex;
    visited.resize(n+1);
    city.resize(n+1);
    earn.resize(n+1);
    ex.resize(n+1);
    fill(city.begin(), city.end(), LONG_MAX);
    for (int i = 0; i < m; i++) {
        int start, end, price;
        cin >> start >> end >> price;
        bus.push_back(make_tuple(start, end, price));
        ex[start].push_back(end);
    }
    for (int i = 0; i < n; i++) {
        cin >> earn[i];
    }
    queue <int> q;
    q.push(s);
    while (!q.empty()) {
        int now = q.front(); q.pop();
        visited[now] = true;
        for (int i : ex[now]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    if (!visited[e]) {
        cout << "gg" << '\n';
        return 0;
    }

    city[s] = 0;
    for (int i= 1; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            edge now = bus[j];
            int first = get<0>(now);
            int second = get<1>(now);
            int third = get<2>(now);
            if (city[first] != LONG_MAX && city[second] < city[first] + third) {
                city[second] = city[first] + third;
            }
        }
    }
}