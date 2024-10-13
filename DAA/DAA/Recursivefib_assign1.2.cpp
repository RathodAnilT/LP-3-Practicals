#include <iostream>
using namespace std;

int fibonacciRecursive(int n) {
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Fibonacci number (Recursive) at position " << n << " is: " << fibonacciRecursive(n) << endl;
    return 0;
}
