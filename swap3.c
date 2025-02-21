/*===========================================================
  File: swap3.c
  Task: Swapping the contents of two pointers 
===========================================================*/

/*@
  ensures *a == \old(*b);
  ensures *b == \old(*a);
*/
void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
