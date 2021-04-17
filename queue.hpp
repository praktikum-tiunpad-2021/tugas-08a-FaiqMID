#pragma once
#include <iostream>
using namespace std;
namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  T data;
  T priority;
  Element<T> *next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  ElementPtr<T> head;
  ElementPtr<T> tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  Queue<T> Q; 
  Q.head = nullptr;
  Q.tail = nullptr;
  return Q;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  ElementPtr<T> ptrPrev = nullptr;
    //ElementPtr<T> ptrNext = nullptr;
    ElementPtr<T> pHelp = q.head;

    ElementPtr<T> newElement = new Element<T>;  
    newElement->data = value;
    newElement->priority = priority;
    newElement->next = nullptr;
    
    if (q.head == nullptr && q.tail == nullptr){
      q.head = newElement;
      q.tail = newElement;
    } else
    {
      while (newElement->priority <= pHelp->priority)
      {
        if(pHelp->next == nullptr){
          break;
        }
        ptrPrev = pHelp;
        pHelp = pHelp->next;
      }

        if (pHelp == q.head && newElement->priority > pHelp->priority)
        {
          newElement->next = pHelp;
          q.head = newElement;
        }
        else if (pHelp == q.tail && newElement->priority < pHelp->priority)
        {
          pHelp->next = newElement;
          q.tail = newElement;
        }
        else {
          ptrPrev->next = newElement;
          newElement->next = pHelp;
        }
    }
    
    /*do
    {
      //cout << "=> loop  newElmdata = " << newElement->data << " newElmPri = " << newElement->priority << " vs pHelpdata = " << pHelp->data << " pHelpPri = " << pHelp->priority << "\n ";
      if (q.head == nullptr && q.tail == nullptr)
      {
        q.head = newElement;
        q.tail = newElement;
        break;
      } else if (pHelp == q.head && newElement->priority > pHelp->priority) //first
      {
        q.head = newElement;
        newElement->next = pHelp;
        break;
      } else if (pHelp == q.tail && newElement->priority <= pHelp->priority) //last
      {
        pHelp->next = newElement;
        q.tail = newElement;
        break;
      } else if (newElement->priority > pHelp->priority){
        ptrPrev->next = newElement;
        newElement->next = pHelp;
      } else if (newElement->priority <= pHelp->priority){
        do
        {
          ptrPrev = pHelp;
          pHelp = pHelp->next;
        } while (pHelp != nullptr && newElement->priority < pHelp->priority);  
        
        if (pHelp == nullptr) //last
        {
          ptrPrev->next = newElement;
          q.tail = newElement;
          break;
        } else {
          ptrNext = pHelp->next;
          pHelp->next = newElement;
          newElement->next= ptrNext;
          break;
        }
        
      }

      pHelp = pHelp->next;
    } while (pHelp != nullptr && pHelp != q.tail);*/
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  return q.head->data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  ElementPtr<T> delElement = new Element<T>;
  if (q.head == nullptr && q.tail == nullptr)
  {
    delElement = nullptr;
  }
  else if (q.head->next == nullptr)
  {
    delElement = q.head;
    q.head = nullptr;
    q.tail = nullptr;
  }
  else
  {
    delElement = q.head;
    q.head = q.head->next;
    delElement->next = nullptr;
  }
  
  
}

}  // namespace priority_queue

}  // namespace strukdat
