/*===========================================================
  File: fill.c
  Task: Fill a[0..n-1] with val
===========================================================*/

/*@
  requires \valid(a + (0..n-1)) && n >= 0;
  assigns a[0..n-1];
  ensures \forall integer i; 0 <= i < n ==> a[i] == val;
*/
void fill(int *a, int n, int val) {
    /*@
      loop invariant 0 <= i <= n;
      loop invariant \forall integer k; 0 <= k < i ==> a[k] == val;
      loop assigns i, a[0..n-1];
      loop variant n - i;
    */
    for (int i = 0; i < n; i++) {
      a[i] = val;
    }
  }
  