// Problem https://codeforces.com/problemset/problem/2202/A

// Intuition: First I used the recursion approach and it gave the TLE.
// This problem is math based not recursion.
// Instead of trying moves, think:
// Each move changes (x, y) in a structured way.
// Let’s assume:
// You perform a moves of type (2,1)
// b moves of type (3,0)
// c moves of type (4,-1)
// Then:  `x = 2a + 3b + 4c`,`y = 1a + 0b - 1c`
// Substituting `a = y + c` into the x equation gives: `x = 2(y + c) + 3b + 4c` => `x = 2y + 2c + 3b + 4c` => `x = 2y + 6c + 3b` => `x - 2y = 6c + 3b` => `(x - 2y) % 3 == 0` and `x >= 2y` (since a, b, c must be non-negative).
// And this approach was also failing for {4,-1} as it was giving yes, it should be No

// we missed an important constraint:
// 👉 From
// y = a - c  →  a = y + c
// Since a ≥ 0:
// y + c ≥ 0  →  c ≥ -y

// To make a ≥ 0, we must choose:
// c ≥ max(0, -y)

// Now plug this into:
// x = 2y + 6c + 3b

// To minimize x:
// take b = 0
// take smallest valid c

// Case 1: y ≥ 0
// Then c ≥ 0, so min c = 0:

// x ≥ 2y
// Case 2: y < 0
// Then c ≥ -y, so min c = -y:

// x ≥ 2y + 6(-y)
// x ≥ 2y - 6y
// x ≥ -4y

// Final Correct Condition
// (x - 2*y) % 3 == 0  AND  x >= max(2*y, -4*y)


// When should YOU apply this trick?

// Whenever you see:
// Signals:
// Start from origin (0,0)
// Given fixed moves
// Unlimited usage of moves
// Only final position matters

// When NOT to use this?
// If order matters (like path constraints)
// If grid has obstacles
// If shortest path is asked


#include <bits/stdc++.h>
using namespace std;



int main(){
    int t;
    cin >> t;
    while(t--){
        long long x, y;
        cin >> x >> y;

        long long lower_bound = max(2*y, -4*y);

        if(x >= lower_bound && (x - 2*y) % 3 == 0){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}