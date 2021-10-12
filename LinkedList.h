/*
Yassine El Yacoubi
CS 212
6/21/2021
Adding set-like operations in LinkedList<T> template class
*/

#include <stdexcept>
#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
  Node() // No-arg constructor
  {
    next = nullptr;
  }

  Node(T element) // Constructor
  {
    this->element = element;
    next = nullptr;
  }
    Node<T> &operator=(const T &str ){
      this->element = str;
      Node<T>& ret = *this;
      return ret;
    }
    friend ostream& operator<<( ostream& os,  Node<string>& node );

  // just for console testing:
  void printNodes()
  {
    Node<T> *current = this;
    while (current->next != nullptr)
    {
      cout << current->element << " ";
      current = current->next;
    }
    cout << current->element << endl;
  }

  // so we can keep nodes private
  void setNext(Node<T> *change)
  {
    next = change;
  }

  T getData()
  {
    return element;
  }

  Node<T> *getNext()
  {
    return next;
  }

private:
  T element;     // Element contained in the node
  Node<T> *next; // Pointer to the next node
};

// template linked list class
template <typename T>
class LinkedList
{

  // accessors and mutators declaration list -------------------------
public:
  LinkedList();
  int getSize() { return this->size; }
  void addLast(T element);
  void add(T element);
  void printList();
  void addAll(const LinkedList<T> &list);    //done
  void removeAll(const LinkedList<T> &list); //done
  void retainAll(const LinkedList<T> &list); //done
  void remove(T element);                    //done
  int lastIndexOf(T element);                //done
  bool contains(T element);                  //done
  LinkedList<T> operator+(const LinkedList<T> &otherList)
  {
    addAll(otherList);
    return *this;
  }
  //done
  LinkedList<T> &operator-(const LinkedList &otherList)
  {
    removeAll(otherList);
    return *this;
  } //done

  // function operator for deep copy
  LinkedList<T> &operator=(const LinkedList &otherList);

  LinkedList<T> &operator^(const LinkedList<T> otherList) //done
  {
    retainAll(otherList);
    return *this;
  }

  Node<T>& operator[](int index)
  {
    Node<T> *iterator;
    iterator = head;
    for (int i = 0; i < index; i++)
    {
      if (iterator == nullptr){
        i = index;
      }else{
      iterator->getNext();
      }
    }
    return *iterator;
  }

  void removeAll()
  {
    Node<T> *previous, *current;
    previous = current = head;
    if (head == nullptr)
      return;
    if (head->getNext() == nullptr)
    {
      reset();
      return;
    }

    current = previous->getNext();
    while (current != nullptr)
    {
      delete previous;
      head = previous = current;
      current = current->getNext();
    }

    if (previous != nullptr)
    {
      delete previous;
      tail = head = nullptr;
    }
    reset();
  }
  void reset()
  {
    if (head != nullptr)
    {
      delete head;
    }
    if (tail != nullptr)
    {
      delete tail;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
  }

  LinkedList(const LinkedList<T> &other)
  {
    head = tail = nullptr;
    size = 0;
    addAll(other);
  }

private:
  Node<T> *head;
  Node<T> *tail;
  int size;
};

template <typename T>
LinkedList<T>::LinkedList()
{
  head = tail = nullptr;
  size = 0;
}

//-----------------------------operator functions----------------------------
template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList &otherList)
{
  LinkedList<T> temp = otherList;
  this->removeAll();
  addAll(temp);
  return *this;
}

ostream &operator<< (ostream &os,  Node<string>& nod)
{ 
    os <<"" <<nod.getData()<<"";
    return os;
}

template <typename T>
void LinkedList<T>::printList()
{
  head->printNodes();
}

template <typename T>
void LinkedList<T>::addLast(const T element)
{
  if (head == nullptr)
  {
    head = tail = new Node<T>(element);
  }
  else
  {
    Node<T> *temp = new Node<T>(element);
    tail->setNext(temp);
    tail = temp;
  }
  size++;
}

// Standard List adds data at end of list
template <typename T>
void LinkedList<T>::add(T element)
{
  addLast(element);
}

template <typename T>
void LinkedList<T>::addAll(const LinkedList<T> &list)
{
  Node<T> *temp;
  temp = list.head;
  T data;
  while (temp != nullptr)
  {
    data = temp->getData();
    addLast(temp->getData());
    temp = temp->getNext();
  }
}

template <typename T>
void LinkedList<T>::remove(T data)
{
  if (head == nullptr)
  {
    return;
  }

  if (head == tail)
  {
    if (head->getData() == data)
    {
      reset();
    }
  }
  Node<T> *current, *previous;
  current = previous = head;
  //find the data
  while (current != nullptr)
  {
    while ((current != nullptr) && (current->getData() != data))
    {
      previous = current;
      current = current->getNext();
    }
    //found data
    if (current != nullptr && current->getData() == data)
    {
      //capture item to delete from memory
      Node<T> *temp = current;
      //if we delete the head element
      if (current == head)
      {
        head = head->getNext();
        current = previous = head;
      }
      else
      {
        //any other general case including tail case.
        previous->setNext(current->getNext());
        current = previous->getNext();
      }

      delete temp;
      size--;
    }
  }
}

template <typename T>
void LinkedList<T>::removeAll(const LinkedList<T> &list)
{
  Node<T> *temp2;
  temp2 = list.head;

  T data;
  int count = 0;
  while (temp2 != nullptr)
  {
    data = temp2->getData();
    remove(data);
    temp2 = temp2->getNext();
  }
}

template <typename T>
void LinkedList<T>::retainAll(const LinkedList<T> &list)
{
  LinkedList<T> newlist;
  Node<T> *temp, *temp2;
  temp2 = list.head;
  temp = head;
  T data, dataCheck;
  int count = 0;
  while (temp2 != nullptr)
  {
    data = temp2->getData();
    temp = head;
    while (temp != nullptr)
    {
      dataCheck = temp->getData();
      if (data == dataCheck)
      {
        newlist.add(data);
      }
      temp = temp->getNext();
    }
    temp2 = temp2->getNext();
  }
  head = newlist.head;
}

template <typename T>
int LinkedList<T>::lastIndexOf(T element)
{
  Node<T> *temp;
  temp = head;
  int index = -1;
  int lastIndex = -1;

  while (temp != nullptr)
  {
    T tempdata = temp->getData();
    if (tempdata == element)
    {
      lastIndex = index + 1;
    }
    index++;
    temp = temp->getNext();
  }
  return lastIndex;
}

template <typename T>
bool LinkedList<T>::contains(T element)
{
  Node<T> *temp;
  temp = head;
  while (temp != nullptr)
  {
    T tempdata = temp->getData();
    if (tempdata == element)
    {
      return true;
    }
    temp = temp->getNext();
  }
  return false;
}
