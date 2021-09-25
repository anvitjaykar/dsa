#include<iostream>
using namespace std;
/*
class Heap
{
    int A[int n];
    //int n;
    public:

};
*/
/*
void swap(int *p, int* q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void Insert(int A[], int n)
{
    int temp = A[n];
    int i = n;

    while(i>1 && temp>A[i/2])
    {
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}

void Create(int A[], int n)
{
    int i = 2;
    while(i<=n)
    {
        Insert(A, i);
        i++;
    }
}

int Delete(int A[], int n)
{
    int x = A[1];
    A[1] = A[n];
    A[n] = 0;

    int i = 1, j = 2*i;
    while(j<n-1)
    {
        if(A[j+1]>A[j]) j = j+1;
        if(A[i]<A[j])
        {
            swap(A[i], A[j]);
            i = j;
            j = 2*j;
        }
        else break;
    }
    return x;
}

int main()
{

    int A[] = {0,40,35,30,15,10,25,5};
    Create(A, 7);
    for(int i = 1; i<8; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;

    Delete(A,7);
    for(int i = 1; i<8; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;

    return 0;
}

*/

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void Heapify(int A[], int n, int i)
{
    int largest = i;
    int l = 2*i+1;
    int r = 2*i + 2;

    if(l<n && A[l]>A[largest])
    largest = l;

    if(r<n && A[r]>A[largest])
    largest = r;

    if(largest != i){
        swap(A[largest], A[i]);
        Heapify(A, n, largest);
    }
}

void createHeap(int A[], int n)
{
    for(int i = n/2-1; i>=0; i--)
    {
        Heapify(A, n, i);
    }
}

int Delete(int A[], int n)
{
    int x = A[0];
    A[0] = A[n-1];
    A[n-1] = 0;

    Heapify(A, n-1, 0);

    return x;
}

int main()
{
    int A[] = {40,35,30,15,10,25,5};
    createHeap(A, 7);
    for (int i = 0; i<7; i++)
    cout<<A[i]<<" ";

    cout<<endl;

    int x =-1;
    for(int i = 0; i<4; i++)
    {
        x = Delete(A, 7-i);
    }
    cout<<"Kth max: "<<x<<endl;
    return 0;
}