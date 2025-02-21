/*===========================================================
  File: sum.c
  Task: Sum of first n odd numbers = n^2
===========================================================*/

/*@
  ensures \result == n * n;
*/
int f(int n) {
    int i = 0;
    int s = 0;
    /*@
      loop invariant 0 <= i <= n;
      loop invariant s == i * i;
      loop assigns i, s;
      loop variant n - i;
    */
    while (i != n) {
      i++;
      s += (2 * i - 1);
    }
    return s;
  }
  