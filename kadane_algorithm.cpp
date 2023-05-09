/**
* Reference: https://en.wikipedia.org/wiki/Maximum_subarray_problem#:~:text=The%20maximum%20subarray%20problem%20was,dimensional%20array%20of%20real%20numbers.
*/

// Empty subarrays admitted
int best = 0, sum = 0;
for (int k = 0; k < n; k++) {
  sum = max(0, sum+array[k]);
  best = max(best, sum);
}
cout << best << "\n";
    
// No empty subarrays admitted
int best = MIN_INF, sum = 0;
for (int k = 0; k < n; k++) {
  sum = max(array[k], sum+array[k]);
  best = max(best, sum);
}
cout << best << "\n";

