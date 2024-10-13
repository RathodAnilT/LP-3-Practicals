#include <iostream>
using namespace std;

int fibonacciIterative(int n) {
    if (n <= 1)
        return n;

    int prev = 0, curr = 1, next;
    for (int i = 2; i <= n; i++) {
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Fibonacci number (Iterative) at position " << n << " is: " << fibonacciIterative(n) << endl;
    return 0;
}
