/*===========================================================
  File: getIndexMin.c
  Task: Return the index of the minimum element of t[]
===========================================================*/

/*@
  requires \valid(t + (0..n-1)) && n > 0;
  // The result is a valid index
  ensures 0 <= \result < n;
  // The element at that index is a minimum
  ensures \forall integer i; 0 <= i < n ==> t[\result] <= t[i];
*/
int getIndexMin(int t[], int n) {
    int index = 0;
    /*@
      loop invariant 1 <= i <= n;
      loop invariant 0 <= index < n;
      loop invariant \forall integer j; 0 <= j < i ==> t[index] <= t[j];
      loop assigns i, index;
      loop variant n - i;
    */
    for(int i = 1; i < n; i++) {
      if (t[i] < t[index]) {
        index = i;
      }
    }
    return index;
  }
  