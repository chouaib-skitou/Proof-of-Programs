/*===========================================================
  File: swap2.c
  Task: Swapping integers (second version) 
===========================================================*/

void swap(int a, int b) {
    int x = a;
    int y = b;
    //@ assert x == a && y == b;
  
    // A more arithmetic-based swapping trick
    x = 2 * (x + y);
    y = x / 2 - y;
    x = x / 2 - y;
  
    //@ assert y == a && x == b;
  }
  