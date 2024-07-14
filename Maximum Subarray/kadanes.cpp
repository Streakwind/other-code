#define ll long long

#include <iostream>
#include <vector>

using namespace std;

int main () {
    ll maxi = 0;
    ll curNum = 0;

    ll curSum = 0;
    ll res = 0;

    vector<ll> givenNum;

    cin >> maxi;

    for (ll i = 0; i < maxi; i++) {
        cin >> curNum;

        givenNum.push_back(curNum);
    }

    res = INT64_MIN;

    for (int i = 0; i < givenNum.size(); i++) {
        curSum = max(curSum + givenNum[i], givenNum[i]);

        res = max(res, curSum);
    }

    cout << res << endl;

    return 0;
}
