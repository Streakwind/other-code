#define ll long long

#include <iostream>
#include <vector>

using namespace std;

ll crossingsub (vector<ll> theList, ll low, ll mid, ll high) {
    ll leftSum = 0;
    ll rightSum = 0;
    ll curSum = 0;

    leftSum = INT64_MIN;

    for (int i = mid; i > low-1; i--) {
        curSum += theList[i];

        leftSum = max(leftSum, curSum);
    }
    
    curSum = 0;

    rightSum = INT64_MIN;

    for (int i = mid; i < high+1; i++) {
        curSum += theList[i];

        rightSum = max(rightSum, curSum);
    }

    return max(max(leftSum, rightSum), leftSum + rightSum - theList[mid]);
}

ll maxsubarray (vector<ll> theList, ll low, ll high) {
    ll mid = 0;

    //cout << low << ", " << high << endl;

    if (low > high) {
        return INT64_MIN; //invalid
    }

    if (low == high) {
        return theList[low];
    }

    mid = low + high;
    mid /= 2;

    return max(max(maxsubarray(theList, low, mid), maxsubarray(theList, mid+1, high)), crossingsub(theList, low, mid, high)); //do not put high+1 for highest point because then it keeps adding 1. only mid can be modified as it is calculated every time
    //mid+1 needed on right side or else mid always will be less than high
    //mid or mid-1 on left doesn't matter, 7 or 7-1 = 6 divided by two result in the same number
}

int main () {
    ll maxi = 0;
    ll curNum = 0;

    ll res = 0;

    vector<ll> givenNum;

    cin >> maxi;

    for (ll i = 0; i < maxi; i++) {
        cin >> curNum;

        givenNum.push_back(curNum);
    }

    res = maxsubarray (givenNum, 0, maxi-1);
    
    cout << res << endl;

    return 0;
}
