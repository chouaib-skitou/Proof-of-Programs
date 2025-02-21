/*===========================================================
  File: equal.c
  Task: Check whether t[] and u[] (both of length n) are equal
===========================================================*/

/*@
  requires \valid(t+(0..n-1)) && \valid(u+(0..n-1));
  // \result is 1 if they are the same array contents, 0 otherwise
  ensures \result <==> (\forall integer i; 0 <= i < n ==> t[i] == u[i]);
*/
int equal(int t[], int u[], int n) {
    /*@
      loop invariant 0 <= k <= n;
      loop invariant \forall integer j; 0 <= j < k ==> t[j] == u[j];
      loop assigns k;
      loop variant n - k;
    */
    for (int k = 0; k < n; k++) {
      if (t[k] != u[k]) {
        return 0;
      }
    }
    return 1;
  }
  