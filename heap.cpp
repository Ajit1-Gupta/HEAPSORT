#include<iostream>
#include<queue>
using namespace std;
class heap{
    public:
    int arr[100];
    int size;
    heap()
    {
        arr[0]=-1;
        size=0;
    }
    void insert(int val)
    {
        size=size+1;
        int index=size;
        arr[index]=val;
        while(index>1)
        {
            int parent=index/2;
            if(arr[parent]<arr[index])
            {
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
        
    }
    void deleteFromHeap()
    {
        if(size==0)
        {
            cout<<"nothing to delete "<<endl;
            return;
        }
        //step:1 put last element into first index
        arr[1]=arr[size];
        //step:1 remove last node
        size--;
        //step:3 take root node its correct position
        
        int i=1;
        while(i<size)
        {
            int leftIndex=2*i;
            int rightIndex=2*i+1;
            if(leftIndex<size && arr[i]<arr[leftIndex])
            {
                swap(arr[i],arr[leftIndex]);
                i=leftIndex;
            }
            else if(rightIndex<size && arr[i]<arr[rightIndex])
            {
                swap(arr[i],arr[rightIndex]);
                i=rightIndex;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for(int i=1;i<=size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
void heapify(int arr[],int n,int i)
{
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && arr[left]>arr[largest])
    {
        largest=left;
    }
    if(right<=n && arr[right]>arr[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[],int n)
{
    int size=n;
    while(size>1)
    {
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
}
int main()
{
    heap h;
    cout<<"insert the element into node : ";
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    cout<<endl<<"delete node from heap: ";
    h.deleteFromHeap();
    h.print();
    cout<<endl;
    cout<<"heapify algorithm : "<<endl;
    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--)
    {
        heapify(arr,n,i);
    }
    cout<<"printing the array now ;"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"printing sorted array using heap sort :";
    heapSort(arr,n);
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    cout<<"using STL for heap sort, heapify :"<<endl;
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    maxheap.push(40);
    maxheap.push(30);
    maxheap.push(80);
    cout<<endl<<"top of element of max heap: "<<maxheap.top();
    cout<<endl;
    minheap.push(40);
    minheap.push(30);
    minheap.push(10);
    minheap.push(80);
    cout<<"top of element of min heap: "<<minheap.top();
    cout<<endl;
    
    return 0;
    
}