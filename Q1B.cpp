#include <iostream>
using namespace std;

void PP(int n, int row = 1) {
    if (row > n)
        return;

    for (int i = 1; i < row; i++)
        cout << "1 ";

    int remaining = n - row + 1;
    if (remaining > 0)
        cout << remaining;
    cout << endl;

    PP(n, row + 1);
}

void PrintP(int &n) {
    PP(n);
}

int main() {
    int n = 4;
    PrintP(n);
    return 0;
}
