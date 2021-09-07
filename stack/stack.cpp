#include<iostream>
using namespace std;

class Node 
{
    public:
    int data;
    Node *next;
};

class Stack
{
    private:
    Node *top;

    public:
    Stack(){top = NULL;}
    void Display();
    void push(int x);
    int pop();
};

void Stack::Display()
{
    if(!top) cout<<"Stack Empty!"<<endl;
    else
    {
        Node *p = top;
        while(p)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<endl;
    }
}

void Stack::push(int x)
{
    Node *p;
    p = new Node;

    if(!p) cout<<"Stack is full!"<<endl;

    else{
        p->data = x;
        p->next = top;
        top = p;
    }
}

int Stack::pop()
{
    if(!top) cout<<"Stack Empty!"<<endl;
    else
    {
        Node *p = top;
        top = top->next;
        int x = p->data;
        free(p);
        return x;
    }
    return -1;
}

int main()
{

    Stack st;
    for(int i = 1; i<5; i++)
    {
        st.push(10*i);
    }
    st.Display();
    st.pop();
    st.Display();
    return 0;
}