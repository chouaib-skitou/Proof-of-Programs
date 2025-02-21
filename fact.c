/*===========================================================
  File: fact.c
  Task: Factorial function with a formal definition 
===========================================================*/

/* 
   We declare a logic function Fact(n) and define it 
   with two axioms: 
   - Fact(0) = 1
   - Fact(n) = n * Fact(n-1) for n>0
*/

/*@ 
  axiomatic Fact {
    logic integer Fact(integer n);

    axiom Fact_1: Fact(0) == 1;

    axiom Fact_rec: 
      \forall integer m; m > 0 ==> Fact(m) == m * Fact(m - 1);
  }
*/

/*@
  requires n >= 0;
  ensures \result == Fact(n);
*/
int fact(int n) {
    int y = 1;
    int x = n;
  
    /*@
      // One possible invariant: y == Fact(n - x)
      loop invariant x >= 0;
      loop invariant y == Fact(n - x);
      loop assigns x, y;
      loop variant x;
    */
    while (x > 1) {
      y = y * x;
      x = x - 1;
    }
    return y;
  }
  