/*
 * Bebas disini bisa masukin apa aja.
 * Misal mau testing atau debugging sendiri.
 *
 */

#include <iostream>

#include "queue.hpp"

using namespace strukdat::priority_queue;

template <typename T>
void Tranversal(Queue<T> Q){
  ElementPtr<T> pHelp = Q.head;
  ElementPtr<T> prev = nullptr;
  while (pHelp->next != Q.tail)
  {
    cout << pHelp->data << " ";
    prev = pHelp;
    pHelp = pHelp->next;
  }
  
}
int main()
{
  auto q = new_queue<int>();
  enqueue(q, 1, 5);
  std::cout << " Current top = " << top(q) << " (harusnya 1)\n\n1";
  enqueue(q, 2, 3);
  std::cout << " Current top = " << top(q) << " (harusnya 1)\n\n1 2";
  enqueue(q, 3, 7);
  std::cout << " Current top = " << top(q) << " (harusnya 3)\n\n3 1 2";
  enqueue(q, 4, 5);
  std::cout << " Current top = " << top(q) << " (harusnya 3)\n\n3 1 4 2";
  enqueue(q, 5, 1);
  std::cout << " Current top = " << top(q) << " (harusnya 3)\n\n3 1 4 2 5\n\n";

  Tranversal(q);
  cout << "\n\n";
  dequeue(q);
  std::cout << top(q) << " harusnya 1" <<'\n';
  dequeue(q);
  std::cout << top(q) << " harusnya 4" <<'\n';
  dequeue(q);
  std::cout << top(q) << " harusnya 2" <<'\n';
  dequeue(q);
  std::cout << top(q) << " harusnya 5\n\nbababooey";
  

  return 0;
}
