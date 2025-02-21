/*===========================================================
  File: swap1.c
  Task: Swapping integers (first version) 
===========================================================*/

void swap(int a, int b) {
    int x = a;
    int y = b;
    //@ assert x == a && y == b;
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
    //@ assert y == a && x == b;
  }
  