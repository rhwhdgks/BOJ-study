#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int chess[15];
int result = 0;
int n;

void queen(int now) {
    if (now == n)
    {
        result++;
    }
    else {
        for (int i = 0; i < n; i++)
        {
            chess[now] = i;
            int correct = 1;
            for (int j = 0; j < now; j++)
            {
                if (chess[now] == chess[j] || now - j == abs(i - chess[j])) 
                {
                    correct = 0;
                    break;
                }
            }
            if (correct == 1)
            {
                queen(now+1);
            }
        }
    }
}

int main() {
    
    cin >> n;
    queen(0);
    cout << result << endl;

}