#include <iostream>

using namespace std;
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int reduce(int &num, int &denom) {
    if (num <= 0 || denom <= 0) {
        return 0; 
    }

    int divisor = gcd(num, denom);
    num /= divisor;
    denom /= divisor;

    return 1;
}

int main() {
    int numerator, denominator;

    cout << "Enter the numerator: ";
    cin >> numerator;
    cout << "Enter the denominator: ";
    cin >> denominator;

    int result = reduce(numerator, denominator);

    if (result == 1) {
        cout << "The reduced fraction is: " << numerator << "/" << denominator << "\n";
    } else {
        cout << "Failed to reduce the fraction. Ensure both numbers are positive.\n";
    }

    return 0;
}
