#include <iostream>
using namespace std;

int jumlah(int A, int B){
    if (B == 0)
        return A;
    else
        return jumlah(A + 1, B - 1);
}

int main(){
    cout << "Jumlah(3,4)" << endl;
    cout << "Jumlah bilangan: "
         << jumlah(3,4) << endl;
    cout << "Jumlah(4,6)" << endl;
    cout << "Jumlah bilangan: "
         << jumlah(4,6) << endl;

    return 0;
}
