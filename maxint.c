/*===========================================================
  File: maxint.c
  Task: Maximum of 2 integers
===========================================================*/

/*@
  ensures \result >= x && \result >= y;
  ensures \result == x || \result == y;
*/
int maxint(int x, int y) {
    return (x > y) ? x : y;
  }
  