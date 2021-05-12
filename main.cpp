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

//  ~Circular_linked_list();

  void set_current(node * current)
      {
      this->current=current;
      }
      node * get_current()
      {
          return this->current;
      }

  void push(int data)
  {
      node * tmp=new node();
      tmp->set_data(data);
      if (size==0)
      {
          tmp->set_next(tmp);
          tmp->set_prev(tmp);
          size++;
          current=tmp;
      }
      else
      {
          tmp->set_next(current->get_next());
          current->get_next()->set_prev(tmp);
          current->set_next(tmp);
          tmp->set_prev(current);
          current=tmp;
          size++;
      }
  }


  void pop();

  void pop(int data);

  void push_after(int new_data,int pa_data);

  void push_befor(int new_data,int pb_data);

  void print()
  {
      cout<<current->get_data()<<endl;

      if(size==1)
      {
          return;
      }
     else
      {
          node * tmp=current->get_next();
      while (tmp!=current)
      {
          cout<<tmp->get_data()<<endl;
          tmp=tmp->get_next();
      }
      }
  }







};










int main(){


Circular_linked_list c;
c.push(7);
c.push(6);
c.push(5);
c.push(4);
c.push(3);
c.push(2);
c.push(1);
c.print();









}
