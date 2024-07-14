#define ll long long

#include <iostream>
#include <vector>

using namespace std;

int main () {
    ll maxi = 0;
    ll curNum = 0;
    
    ll minPreSum = 0;
    ll res = 0;

    vector<ll> preSum(1);
    vector<ll> givenNum;

    cin >> maxi;

    for (ll i = 0; i < maxi; i++) {
        cin >> curNum;

        givenNum.push_back(curNum);
    }

    //gen preSum. could do in cin as well
    preSum[0] = givenNum[0];

    for (ll i = 1; i < givenNum.size(); i++) {preSum.push_back(preSum[i-1] + givenNum[i]);}

    res = INT64_MIN;
    
    //max diff between two preSum
    for (ll i = 0; i < maxi; i++) {
        res = max(res, preSum[i] - minPreSum);
        minPreSum = min(minPreSum, preSum[i]);
    }

    cout << res << endl;

    return 0;
}
