#include <iostream>
using namespace std;


void ChangeL(char *Array, int b1, int b2) {

    if (b1 >= b2)
        return;

 
    char temp = Array[b1];
    Array[b1] = Array[b2];
    Array[b2] = temp;


    ChangeL(Array, b1 + 1, b2 - 1);
}


void PrintA(char *Array, int size) {
    for (int i = 0; i < size; i++)
        cout << Array[i] << " ";
    cout << endl;
}


int main() {
    char Array[8] = {'C', 'O', 'M', 'P', 'U', 'T', 'E', 'R'};
    int b1 = 2; 
    int b2 = 6; 

    cout << "Before Changeing Location \n";
    PrintA(Array, 8);

    ChangeL(Array, b1, b2);

    cout << "After Changing  location  \n ";
    PrintA(Array, 8);

    return 0;
}
