#include<iostream>
#include<time.h>
#define MAX 1000
using namespace std;
void MinHeap(int A[], int pos, int heapsize);
void ExportArray(int A[], int n);
void MergeDe(int A[], int left, int mid, int right);
int SetupH(int h[], int n);
void HeapMinSort(int A[], int length);
void BuildMinHeap(int A[], int length);
void EnterArray(int A[], int n);
void swap(int &a, int &b);
void BubbleSort(int A[], int n);
void InsertionSort(int A[], int n);
void SelectionSort(int A[], int n);
void MaxHeap(int A[], int pos, int heapsize);
void BuildMaxHeap(int A[], int heapsize);
void HeapSort(int A[], int heapsize);
void CopyArray(int X[], int A[], int n);
void Merge(int A[], int left, int mid, int right);
void MergeSort(int A[], int left, int right);
void ShellSort(int A[], int n);
int Partition(int A[], int p, int r);
void ExchangeSort(int A[], int n);
void InsertionCTSort(int A[], int n);
void QuickSort(int A[], int p, int r);
void DeMaxHeapSort(int A[], int length);
void ShakerSort(int A[], int n);
void MergeSortDe(int A[], int l, int r);
int main()
{
    clock_t start, end;
    double time;
    start = clock();
    int n;
    int A[MAX] = {1,4,2,3,9,7,14,8,16,10};
    // BubbleSort(A,10);
    // InsertionSort(A,10);
    // SelectionSort(A,10);
    // HeapSort(A,10);
    // MergeSort(A,0, 9);
    // QuickSort(A,0,9);
    // ShellSort(A,10);
    // ShakerSort(A,10);
    // ExchangeSort(A,10);
    // HeapMinSort(A,10);
    // InsertionCTSort(A,10);
    // DeMaxHeapSort(A,10);// loi
    // MergeSortDe(A,0,9); 
    ExportArray(A,10);
    end = clock();
    time = ((double)(end-start))/CLOCKS_PER_SEC;
    cout<<time;
    return 0;
}
void MergeSortDe(int A[], int l, int r)
{
    int mid;
    if(l<r)
    {
        mid = (l+r)/2;
        MergeSortDe(A,l,mid);
        MergeSortDe(A,mid+1,r);
        MergeDe(A,l,mid,r);
    }
}
void MergeDe(int A[], int left, int mid, int right)
{
    int B[MAX];
    CopyArray(B,A,right-left+1);
    int bcount = 0;
    int lcount = left;
    int rcount = mid+1;
    while(lcount <= mid && rcount <= right)
    {
        if(A[lcount]<A[rcount]) B[bcount++] = A[rcount++];
        else B[bcount++] = A[lcount++];
    }
    if(lcount>mid)
        while(rcount<=right) B[bcount++] = A[rcount++];
    else
        while(lcount<=mid) B[bcount++] = A[lcount++]; 
   for(bcount = 0; bcount < right - left + 1; bcount++) 
        A[left+bcount] = B[bcount];
}
void DeMaxHeapSort(int A[], int length)
{
    int heapsize = length;
    BuildMaxHeap(A,length);
    for(int i = length - 1; i >= 1; i--)
    {
        heapsize= heapsize - 1;
        MaxHeap(A,0,heapsize);
    }
}
void HeapMinSort(int A[], int length)
{
    int heapsize = length;
    BuildMinHeap(A,length);
    for(int i = length-1;i>=1;i--)
    {
        swap(A[0],A[i]);
        heapsize = heapsize - 1; 
        MinHeap(A,0,heapsize);
    }
}
void MinHeap(int A[], int pos, int heapsize)
{
    int l,r,smallest;
    l = 2*pos + 1;
    r = 2*pos + 2;
    if(l<heapsize && A[l] < A[pos])
        smallest = l;
    else smallest = pos;
    if(r<heapsize && A[r] < A[smallest])
        smallest = r;
    if(smallest != pos) 
    {
        swap(A[pos], A[smallest]);
        MinHeap(A,smallest,heapsize);
    }
}
void BuildMinHeap(int A[], int length)
{
   int heapsize = length;
   for(int i = length/2 -1; i >= 0; i--)
   {
       MinHeap(A,i,heapsize);
   } 
}
void InsertionCTSort(int A[], int n)
{
    int j, temp;
    for(int i = n-2;i>=1;i--)
    {
        j = i;
        temp = A[j];
        while(j<n-1 && temp > A[j+1])
        {
            A[j] = A[j+1];
            j++;
        }
        A[j] = temp;
    }
}
void ExchangeSort(int A[], int n)
{
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(A[i]>A[j]) swap(A[i],A[j]);
}
void ShakerSort(int A[], int n)
{
    int swapped;
    do
    {
       swapped = 0;
       for(int i = 0; i <= n - 2; i++) 
       {
           if(A[i]>A[i+1]) 
           {
                swap(A[i],A[i+1]);
                swapped = 1;
           }
       }
       if(swapped == 0) break;
       swapped = 0;
       for(int i = n - 2; i >= 0; i--)
       {
           if(A[i] > A[i+1])
            {
                swap(A[i],A[i+1]);
                swapped = 1;
            }
       }
    } while (swapped==1);
}
void ShellSort(int A[], int n)
{
    int h[MAX];    
    int hsize = SetupH(h,n);
    SetupH(h,n);
    for(int i = 0; i < hsize ; i++)
    {
        for(int k = h[i]; k < n; k++) 
        {
            int temp = A[k];
            int j = k; 
            while(j >= h[i] && A[j-h[i]]>temp)
            {
                 A[j] = A[j-h[i]];
                 j = j - h[i];
            }
            A[j] = temp;
        }
    }
}
int SetupH(int h[], int n)
{
    int count= 0;
    for(int i = n/2; i > 0; i=i/2)
        h[count++] = i;
    ExportArray(h,count);
    return count;
}
void QuickSort(int A[], int p, int r)
{
    int q;
    if(p<r)
    {
        q = Partition(A,p,r); 
        cout<<q<<" ";
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
    if(p==r) cout<<"NULL"<<" ";
    else
    {
        cout<<"Rong"<<" ";
    }
    
}
int Partition(int A[], int p, int r)
{
    int i = p - 1;
    int x = A[r];
    for(int j = p; j <= r - 1; j++)
        if(A[j]<x)
        {
            i++;
            swap(A[i],A[j]);
        }
    swap(A[i+1],A[r]); 
    return i+1;
}
void MergeSort(int A[], int left, int right)
{
    int mid;
    if(left < right)
    {
        mid = (left + right)/2; 
        MergeSort(A,left,mid);
        MergeSort(A,mid+1,right);
        Merge(A,left,mid,right);
    }
}
void Merge(int A[], int left, int mid, int right)
{
    int B[MAX];
    CopyArray(B,A,right-left+1);
    int bcount = 0;
    int lcount = left;
    int rcount = mid+1;
    while(lcount <= mid && rcount <= right)
    {
        if(A[lcount]<A[rcount]) B[bcount++] = A[lcount++];
        else B[bcount++] = A[rcount++];
    }
    if(lcount > mid)
        while(rcount <= right) B[bcount++] = A[rcount++];
    else 
        while(lcount <= mid) B[bcount++] = A[lcount++];
    for(bcount = 0; bcount < right - left + 1; bcount++)
        A[left+bcount] = B[bcount];
}
void CopyArray(int X[], int A[], int n)
{
    for(int i = 0; i < n; i++)
        X[i] = A[i];
}
void HeapSort(int A[], int heapsize)
{
    int length = heapsize;
    BuildMaxHeap(A,heapsize);
    for(int i = length - 1; i >= 1; i--)
    {
        swap(A[i],A[0]);
        heapsize = heapsize - 1;
        MaxHeap(A,0,heapsize);
    }
}
void BuildMaxHeap(int A[], int heapsize)
{
    for(int i = heapsize/2 - 1; i >= 0; i--)
        MaxHeap(A,i,heapsize);
    ExportArray(A,heapsize);
}
void MaxHeap(int A[], int pos, int heapsize)
{
    int l,r,largest;
    l = 2*pos + 1;
    r = 2*pos + 2;
    if(l < heapsize && A[l] > A[pos])
        largest = l;
    else largest = pos;
    if(r < heapsize && A[r] > A[largest])
        largest = r;
    if(largest != pos)
    {
        swap(A[pos],A[largest]);
        MaxHeap(A,largest,heapsize);
    }
}
void SelectionSort(int A[], int n)
{
    int i,j,k;
    for(i = 0; i < n - 1; i++)
    {
        k = i;
        for(int j = i + 1; j < n; j++)
            if(A[j]<A[k]) k = j;
        swap(A[i], A[k]);
    }
}
void InsertionSort(int A[], int n)
{
    int temp, j;
    for(int i = 1; i < n; i++)
    {
        j = i;
        temp = A[j];
        while(j > 0 && temp < A[j-1])
        {
            A[j] = A[j-1];
            j--;
        }
        A[j] = temp;
    }
}
void BubbleSort(int A[], int n)
{
    for(int i = 0; i < n-1; i++)
        for(int j = n - 1; j>i; j--)
            if(A[j] < A[i])
                swap(A[i],A[j]);
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void EnterArray(int A[], int n)
{
    cin>> n; 
    for(int i = 0; i < n; i++)
        cin>>A[i];
}
void ExportArray(int A[], int n)
{
    for(int i = 0; i < n; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}
