#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n; 
    
    for (int i = 0; i < n; i++)
    {
        int result = 0;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int k;
        cin >> k;
        int circle[51][3];
        for (int j = 0; j < k; j++)
        {
            int r, r1, r2;
            cin >> circle[j][0] >> circle[j][1] >> circle[j][2];
            r1 = pow(x1-circle[j][0],2) + pow(y1-circle[j][1], 2);
            r2 = pow(x2-circle[j][0],2) + pow(y2-circle[j][1], 2);
            r = pow(circle[j][2], 2);
            if (r1 < r && r2 > r) {
                result++;
            }
            else if (r1 > r && r2 < r) {
                result++;
            }
        }
        cout << result<<endl;
    }
}