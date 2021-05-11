#include <bits/stdc++.h>

using namespace std;




class node{

 private:

  int data;

  node* next;

  node* prev;

 public:

  void set_next(node * nx)
      {
          next=nx;
      }
      node * get_next()
      {
          return this->next;
      }
      int get_data()
      {
          return data;
      }
      void set_data(int data)
      {
          this->data=data;
      }
      void set_prev(node * pr)
          {
              prev=pr;
          }
          node * get_prev()
          {
              return this->prev;
          }
  };


class Circular_linked_list{

 private:

  int size;

  node* current;

 public:

  Circular_linked_list()
  {
      size=0;
      current=nullptr;
  }

  ~Circular_linked_list();

  void set_current(node * current)
      {
      this->current=current;
      }
      node * get_current()
      {
          return this->current;
      }

  void push();

  void pop();

  void pop(int data);

  void push_after(int new_data,int pa_data);

  void push_befor(int new_data,int pb_data);

  void print();







};










int main(){










}
