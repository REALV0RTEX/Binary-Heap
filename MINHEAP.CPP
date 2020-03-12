//Credit to GeeksForGeeks  @ geeksforgeeks.org/binary-heap/
#include<iostream>
#include<climits>

using namespace std;

void swap(int *x, int *y);
class MinHeap
{
    int *harr; //points to numbers in heap array
    int Capacity; //max size in min heap
    int Heap_Size; //Amount of numbers in min heap
public:
    MinHeap(int Capacity);

    void MinHeapify(int ); //heapify a subtree

    int parent(int i)
        {
            return (i-1)/2; //to get parent index
        }
    int left(int i)
        {
            return (2*i+1); // to get index of left child
        }
    int right(int i)
        {
            return (2*i+2); //to get index of right child
        }
    int ExtractMin(); //to take out minimum element
    void DecreaseKey(int i, int NewVal); //Decreases key value
    int getMin()
        {
            return harr[0]; // Returns minimum key from min heap
        }
    void DeleteKey(int i);
    void InsertKey(int k);
};
MinHeap::MinHeap(int Cap) //Builds a heap from a given array of a given size.
{
    Heap_Size = 0;
    Capacity = Cap;
    harr = new int[Cap];
}
void MinHeap::InsertKey(int k) //Insertion of new element in Min Heap
{
    if(Heap_Size == Capacity)
        {
            cout << "\n OverFlow: Couldn't InsertKey \n" << endl;
            return;
        }
    Heap_Size++; //inserts new key at end of heap
    int i = Heap_Size - 1;
    harr[i] = k;

    while (i != 0 && harr[parent(i)] > harr[i]) //to fix min heap if not true
        {
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
}
void MinHeap::DecreaseKey(int i, int NewVal) // Decreases value of key[i] to a new value
{
    harr[i] = NewVal;
    while( i != 0 && harr[parent(i)] > harr[i]) //NewVal is smaller than harr[i]
        {
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
}
int MinHeap::ExtractMin() //Removes lowest element from the tree.
{
    if(Heap_Size <= 0)
        return INT_MAX;
    if(Heap_Size == 1)
        {
            Heap_Size--;
            return harr[0];
        }
    int root = harr[0];     //Stores min value and removes it from heap
    harr[0] = harr[Heap_Size-1];
    Heap_Size--;
    MinHeapify(0);

    return root;
}

void MinHeap::DeleteKey(int i) //Deletion in Min Heap
{
    DecreaseKey(i, INT_MIN);
    ExtractMin();
}

void MinHeap::MinHeapify(int i) //Method to heapify a subtree
{
    int L = left(i);
    int R = right(i);
    int Smallest = i;
    if(L < Heap_Size && harr[L] < harr[i])
        Smallest = L;
    if(R < Heap_Size && harr[R] < harr[Smallest])
        Smallest = R;
    if(Smallest != i)
        {
            swap(&harr[i], &harr[Smallest]);
            MinHeapify(Smallest);
        }
}

void swap(int *x, int *y) //Helps swap 2 elements from tree
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    MinHeap a(15);
    a.InsertKey(3);
    a.InsertKey(5);
    a.DeleteKey(1);
    a.InsertKey(11);
    a.InsertKey(10);
    a.InsertKey(8);
    a.InsertKey(17);
    cout << a.ExtractMin() << " ";
    cout << a.getMin() << " ";
    a.DecreaseKey(2, 1);
    cout << a.getMin();
    return 0;
}
