# include<iostream>
using namespace std;


int gcd(int a, int b){
    while(b != 0){
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int lcm(int a, int b){
    return a * b /gcd(a,b);
}

int power(int x, int n){
    int prod = 1;
    while(n != 0){
        if(n % 2 == 1)
            prod *= x;
        x *= x;
        n = n/2;
    }
    return prod;
}


int main(){
    int a = 50, b = 30;
    cout << "Euclid gcd algorithms: gcd(50 , 30): " << gcd(a,b) << endl;
    cout << "Euclid lcm algorithms: lcm(50 , 30): " << lcm(a,b) << endl;
    cout << "Euclid lcm algorithms: 2^10: " << power(2, 10) << endl;

}