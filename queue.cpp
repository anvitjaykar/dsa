#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

class Queue
{
    private:
    Node *front, *rear;

    public:
    Queue(){front = rear = NULL;}
    void enqueue(int x);
    int dequeue();
    void display();
};

void Queue::enqueue(int x)
{
    Node *t = new Node;
    if(!t) cout<<"Queue is full!"<<endl;
    else
    {
        t->data = x;
        t->next = NULL;

        if(!front){front = rear = t;}
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int Queue::dequeue()
{
    int x = -1;
    if(!front) cout<<"Queue is empty!"<<endl;
    else
    {
        Node *p = front;
        front = front->next;
        x = p->data;
        free(p);
    }
    return x;
}

void Queue::display()
{
    if(!front) cout<<"Queue is empty!"<<endl;
    else
    {
        Node *p = front;
        while(p)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<endl;
    }
}

int main()
{
    Queue q;
    for(int i = 1; i<=5 ; i++)
    {
        q.enqueue(10*i);
    }
    q.display();
    q.dequeue();
    q.display();
    return 0;
}

