/*===========================================================
  File: allZeros.c
  Task: Check if all elements of t[] are zero
===========================================================*/

/*@
  requires n >= 0 && \valid(t + (0..n-1));
  assigns \nothing ;
  // \result != 0  <==>  all elements are zero
  ensures \result != 0 
    <==> (\forall integer j; 0 <= j < n ==> t[j] == 0);
*/
int all_zeros(int t[], int n) {
    /*@
      loop invariant 0 <= k <= n;
      loop invariant (\forall integer j; 0 <= j < k ==> t[j] == 0);
      loop assigns k;
      loop variant n - k;
    */
    for (int k = 0; k < n; k++) {
      if (t[k] != 0) {
        return 0; // found a non-zero, so the array is not all zeros
      }
    }
    return 1;     // never found a non-zero element
  }
  