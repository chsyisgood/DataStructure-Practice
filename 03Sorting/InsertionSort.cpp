#include <iostream>
using namespace std;

void InsertionSort(int x[], int n){
    int temp = 0;
    for(int i = 1; i < n; i++){
        temp = x[i];
        int j = i - 1;
        for(j = i - 1; j >= 0; j--){
            if(x[j] > temp){
                x[j+1] = x[j];
            }
            else{
                x[j+1] = temp;
                break;
            }
        }
        x[j+1] = temp;
    }
}

int main(){
    int a[10] = {7,2,3,6,5,10,4,9,8,1};
    InsertionSort(a, 10);
    for(int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;
}