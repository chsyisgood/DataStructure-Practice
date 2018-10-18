#include <iostream>
using namespace std;

void makesubheap(int x[], int i, int n){
    int left = 2*i + 1, right = 2*i + 2;
    int largest = i;
    if(x[left] > x[largest] && left < n)
        largest = left;
    if(x[right] > x[largest] && right < n)
        largest = right;
    if(i != largest){
        swap(x[i], x[largest]);
        makesubheap(x, largest, n);
    }
}
void makeheap(int x[], int n){
    for(int i = n/2 - 1; i >= 0 ; i--)
        makesubheap(x, i, n);
}
void heapsort(int x[], int n){
    makeheap(x, n);
    for(int i = n-1; i >= 0; i--){
        swap(x[0], x[i]);
        makesubheap(x, 0, i);
    }
}

int main(){
    int a[10] = {1,3,4,6,8,9,10,12,2,7};
    int n = sizeof(a)/sizeof(a[1]);
    heapsort(a, n);
    cout << n << endl;
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}