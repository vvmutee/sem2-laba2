#include <iostream>
using namespace std;

void printNumbers(int A, int B) {
    if (A > B) return;  
    cout << A << endl;   
    printNumbers(A + 1, B);  
}

int main() {
    int A = 3, B = 7;  
    printNumbers(A, B);
    return 0;
}
