// Suppose we have a coordinate (x, y). On a 2D grid, a robot is at (0, 0) position and want to reach (x, y). It can move up, down, left or right or stay at current
// cell. It wants to reach destination with as minimum as possible commands. We have to count the number of steps needed.

// So, if the input is like x = 3; y = 4, then the output will be 7

#include <bits/stdc++.h>
using namespace std;

int solve(int x, int y) {
   return x + y + min(abs(x - y), min(abs(x - y + 1), abs(x - y - 1)));
}
int main() {
   int x = 3;
   int y = 4;
   cout << solve(x, y) << endl;
}
