#include <iostream>
using namespace std;

string obtenerNombreDia(int diaSemana) {
    switch (diaSemana) {
        case 0:
            return "Domingo";
        case 1:
            return "Lunes";
        case 2:
            return "Martes";
        case 3:
            return "Miércoles";
        case 4:
            return "Jueves";
        case 5:
            return "Viernes";
        case 6:
            return "Sábado";
        default:
            return "Error";
    }
}

int calcularDiaSemana(int dia, int mes, int anio) {
    if (mes < 3) {
        mes += 12;
        anio--;
    }
    int k = anio % 100;
    int j = anio / 100;
    int diaSemana = (dia + 13 * (mes + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

    return (diaSemana + 5) % 7;
}

void imprimirFechasReuniones(int anio) {
    for (int mes = 1; mes <= 12; mes += 3) {
        int diaSemana = calcularDiaSemana(1, mes, anio);
        int diaDelMes = 1;

        cout << "Reunión trimestral para el mes " << mes << " del " << anio << " cae en un día " << obtenerNombreDia(diaSemana);

        if (diaSemana == 0) {
            cout << " (es domingo), se pasa para el lunes";
            diaSemana = 1;
            diaDelMes++;
        } else if (diaSemana == 6) {
            cout << " (es sábado), se pasa para el lunes";
            diaSemana = 1;
            diaDelMes += 2;
        }

        cout << ", día " << diaDelMes << ".\n";
    }
}

int main() {
    int anio;

    cout << "Ingrese el año: ";
    cin >> anio;

    imprimirFechasReuniones(anio);

    return 0;
}