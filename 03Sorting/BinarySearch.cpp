# include <iostream>
using namespace std;

void quicksort(int x[], int left, int right){
    if(right - left < 1)
        return;
    int pivot = (x[left] + x[right])/2;
    int i = left, j = right;
    while(i < j){
        while(x[i] <= pivot && i < right)
            i++;
        while(x[j] > pivot && j > left)
            j--;
        if(i < j)
            swap(x[i], x[j]);
    }
    quicksort(x, left, i - 1);
    quicksort(x, i, right);
}

int binarysearch(int x[], int target, int n){
    int left = 0, right = n - 1;
    while(left < right){
        int mid = (left + right)/2;
        if(x[mid] > target)
            right = mid;
        else if(x[mid] < target)
            left = mid;
        else{
            cout << "Found!" << endl;
            return mid;
        }
            
    }
    cout << "Not Found!" << endl;
    return 0;
}

int main(){
    int a[10] = {3,2,1,6,10,8,9,5,7,6};
    //int a[10] = {7,2,3,6,5,10,4,9,8,1};
    int n = sizeof(a)/sizeof(a[0]);
    quicksort(a, 0, n-1);
    for(int i = 0; i < n; i++)
        cout << a[i] <<' ';
    cout << endl;
    binarysearch(a, 9, n);
}