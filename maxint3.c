/*===========================================================
  File: maxint3.c
  Task: Maximum of 3 values using the previous maxint
===========================================================*/

/* 
   We reuse the definition of maxint from Task 1.
   If you prefer, you can place it in a separate header 
   and include it. For simplicity, we re-declare it here.
*/

/*@
  ensures \result >= x && \result >= y;
  ensures \result == x || \result == y;
*/
int maxint(int x, int y) {
    return (x > y) ? x : y;
  }
  
  /*@
    ensures \result >= x && \result >= y && \result >= z;
    ensures \result == x || \result == y || \result == z;
  */
  int maxint3(int x, int y, int z) {
    /*
      We call maxint twice:
      1) to get max of y and z,
      2) to get max of x and that result.
    */
    int m = maxint(y, z);
    return maxint(x, m);
  }
  