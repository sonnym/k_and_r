/**
 * Our binary search makes two tests inside the loop, when one would suffice (at
 * the price of more tests outside.)  Write a version with only one test inside
 * the loop and measure the difference in run-time.
 */

#include <stdio.h>

void build_array(int[], int);
int binsearch(int, int[], int);

int main() {
  int arr[6];
  build_array(arr, 6);

  printf("%d\n", binsearch(3, arr, 6));
}

int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;

  while (low < high) {
    mid = (low + high) / 2;

    if (x <= v[mid]) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  return (v[low] == x) ? low : -1;
}

void build_array(int arr[], int len) {
  int i;

  for (i = 0; i < len; i++) {
    arr[i] = i;
  }
}
