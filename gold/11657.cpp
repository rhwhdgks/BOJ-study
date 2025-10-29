#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> edge;
vector <edge> bus;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector <long> city;
    int n, m;
    cin >> n >> m;
    bus.resize(n+1);
    city.resize(n+1);
    fill(city.begin(), city.end(), LONG_MAX);

    for (int i = 0; i < m; i++)
    {
        int s, e, p;
        cin >> s >> e >> p;
        bus.push_back(make_tuple(s, e, p));
    }

    city[1] = 0;
    for (int i= 1; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            edge now = bus[j];
            int first = get<0>(now);
            int second = get<1>(now);
            int third = get<2>(now);
            if (city[first] != LONG_MAX && city[second] > city[first] + third) {
                city[second] = city[first] + third;
            }
        }
    }

    bool ans = false;


        for (int j = 0; j < m; j++)
        {
            edge now = bus[j];
            int first = get<0>(now);
            int second = get<1>(now);
            int third = get<2>(now);
            if (city[first] != LONG_MAX && city[second] > city[first] + third) {
                ans = true;
            }
        }

        if (!ans) {
            for (int i = 2; i <= n; i++) {
                if (city[i] == LONG_MAX) {
                    cout << -1 << '\n';
                }
                else {
                    cout << city[i] << '\n';
                }
            }
        }
        else {
            cout << -1;
        }
    
    
    return 0;
}