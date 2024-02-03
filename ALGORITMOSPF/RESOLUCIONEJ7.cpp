#include <iostream>
using namespace std;
bool numperf(int num) {
    int sumadiv = 1;
    int i = 2;
    while (i <= num / 2) {
        if (num % i == 0) {
            sumadiv += i;
        }
        i++;
    }
    return (sumadiv == num);
}
int main() {
    char respuesta = 's';
    while (respuesta == 's') {
        int NUM;
        cout << "Ingrese un número positivo: ";
        cin >> NUM;
        if (NUM <= 0) {
            cout << "Por favor, ingrese un número positivo." << endl;
            return 1;
        }
        int contperf = 0;
        int i = 2;
        while (i <= NUM) {
            if (numperf(i)) {
                cout << i << " ";
                contperf++;
            }
            i++;
        }
        cout << "\nCantidad de números perfectos: " << contperf << endl;
        cout << "¿Desea agregar otro número? (s/n): ";
        cin >> respuesta;
    }
    return 0;
}