// alias s='g++ -o ./solution solution.cpp && ./solution'
#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

int main () {
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    int kutije;

    while (t--)
    {
        cin >> kutije;
        vector<int> bomboni(kutije);
        long int counter = 0;
        long int najmanji = INT_MAX;

        for (int i = 0; i < kutije; i++)
        {
            cin >> bombon[i];
            if (bombon[i] < najmanji) najmanji = bombon[i];
        }
        for (int i = 0; i < kutije; i++)
        {
            if (bombon[i] > najmanji) counter += bombon[i] - najmanji;
            else if (kutije == 1) counter = 0;
        }
        cout << counter << endl;
    }

    return 0;
}
