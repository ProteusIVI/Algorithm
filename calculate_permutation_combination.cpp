#include <iostream>

using namespace std;

int fact(int n) {
   if (n == 0 || n == 1)
   return 1;
   else
   return n * fact(n - 1);
}

int main() {
   int n, r, comb, per;
  
   cout<<"Enter n : ";
   cin>>n;
  
   cout<<"\nEnter r : ";
   cin>>r;
  
   // formula without repetition
   comb = fact(n) / (fact(r) * fact(n-r));
   cout << "\nCombination : " << comb;
   
   // If r = 2, then using for loop will be faster.
   comb = 0;
   for (int k = 1; k < n; k++) {
      comb += n - k;
   }
   
   // Below method works for every r
   // Refer to https://stackoverflow.com/questions/1838368/calculating-the-amount-of-combinations
   comb = 1;
   for (unsigned long long d = 1; d <= r; ++d) {
       comb = comb * n / d;
       n = n - 1;
   }
  
  // formula without repetition
   per = fact(n) / fact(n-r);
   cout << "\nPermutation : " << per;
  
   return 0;
}
