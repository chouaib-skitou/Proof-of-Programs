/*===========================================================
  File: loops.c
  Task: Simple examples of loop annotations
===========================================================*/

/*-----------------------------------------------------------
  loop1: Decrements x down to 0
-----------------------------------------------------------*/
/*@
  requires x >= 0 ;
  ensures \result == 0 ;
*/
int loop1(int x){
    int n = x;
    /*@
      loop invariant n >= 0;
      loop assigns n;
      loop variant n;
    */
    while (n > 0) {
      n--;
    }
    return n;
  }
  
  /*-----------------------------------------------------------
    loop2: Increments x up to 100
  -----------------------------------------------------------*/
  /*@
    requires x < 100 ; 
    ensures \result == 100 ;
  */
  int loop2(int x){
    int n = x;
    /*@
      loop invariant n <= 100;
      loop assigns n;
      loop variant 100 - n;
    */
    while (n < 100) {
      n++;
    }
    return n;
  }
  
  /*-----------------------------------------------------------
    loop3: Returns 100 if x >= 100, otherwise loops until n=100
  -----------------------------------------------------------*/
  /*@
    ensures \result == 100;
  */
  int loop3(int x){
    int n = x;
    if (n >= 100) {
      return 100;
    } else {
      /*@
        loop invariant n <= 100;
        loop assigns n;
        loop variant 100 - n;
      */
      while (n < 100) {
        n++;
      }
      return n;
    }
  }
  