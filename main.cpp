#include <bits/stdc++.h>
using namespace std;

class node
{
private:

    int data;
    node * next;
    node * prev;

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

class Circular_linked_list
{
private:

    int size;
    node * current;

public:

    Circular_linked_list()
    {
        size=0;
        current=nullptr;
    }

    ~Circular_linked_list(){
        if(this->size==1)
            delete this->current;
        else{
            node * tmp=this->current->get_next();
            while(tmp!=this->current){
                delete tmp;
                tmp=tmp->get_next();
            }
            delete this->current;
        }
    }

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

    void pop()
    {
        node * q = this->current ;
        q->get_prev()->set_next( q->get_next() ) ;
        q->get_next()->set_prev( q->get_prev() ) ;
        current = current->get_next() ;
        delete q ;
        size -- ;
    }

    void pop(int data){
        node * tmp=find(data);
        if(tmp==this->current){
            pop();
            return ;
        }
        else{
            node * tp=this->current;
            this->current=tmp;
            pop();
            this->current=tp;
        }
    }

    void push_after(int new_data,int pa_data)
    {
        node * tmp=find( pa_data);
        node * tp=current;
        current=tmp;
        push(new_data);
        current=tp;
    }

    void push_befor(int new_data,int pb_data)
    {
        node * tmp=find( pb_data);
        node * tp=current;
        current=tmp->get_prev();
        push(new_data);
        current=tp;
    }

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

    node * find(int data)
    {
        node * tmp=current;
        while (tmp->get_data()!=data)
        {
            tmp=tmp->get_next();
        }
        return tmp;
    }

};

int main()
{
    Circular_linked_list c;

    c.push(7);
    c.pop() ;
    c.push(5);
    c.push_befor(6,5);
    c.push_after(4,5);
    c.push(0);
    c.pop(0) ;

    c.print() ;

    return 0 ;
}
