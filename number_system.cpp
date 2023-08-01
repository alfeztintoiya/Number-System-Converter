#include<bits/stdc++.h>

using namespace std;
// Function to convert a number from a given base to decimal
int toDecimal(const string& num, int base) {
    int decimal = 0;
    int power = 0;
    int len = num.length();
    
    for (int i = len - 1; i >= 0; --i) {
        int digit;
        if (num[i] >= '0' && num[i] <= '9') {
            digit = num[i] - '0';
        } else if (num[i] >= 'A' && num[i] <= 'Z') {
            digit = num[i] - 'A' + 10;
        } else if (num[i] >= 'a' && num[i] <= 'z') {
            digit = num[i] - 'a' + 10;
        } else {
            
            return -1;
        }
        
        if (digit >= base) {
            // Invalid base
            return -1;
        }
        
        decimal += digit * pow(base, power);
        ++power;
    }
    
    return decimal;
}

// Function to convert a decimal number to a given base
string fromDecimal(int decimal, int base) {
    string result;
    
    while (decimal > 0) {
        int remainder = decimal % base;
        char digit;
        if (remainder < 10) {
            digit = '0' + remainder;
        } else {
            digit = 'A' + remainder - 10;
        }
        
        result = digit + result;
        decimal /= base;
    }
    
    return result;
}

// Function to convert a number from one base to another base
string convertNumberSystem(const string& num, int inputBase, int outputBase) {
    int decimal = toDecimal(num, inputBase);
    
    if (decimal == -1) {
        
        return "Invalid input number";
    }
    
    return fromDecimal(decimal, outputBase);
}

int main() {
    string inputNumber;
    int inputBase, outputBase;

    cout << "Enter the number: ";
    cin >> inputNumber;

   cout << "Enter the base of the input number: ";
    cin >> inputBase;

    cout << "Enter the base of the output number: ";
    cin >> outputBase;

    string outputNumber = convertNumberSystem(inputNumber, inputBase, outputBase);
    cout << "Converted number: " << outputNumber <<endl;

    return 0;
}
