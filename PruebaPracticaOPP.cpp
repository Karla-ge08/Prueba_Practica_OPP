#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

// Función para obtener fecha actual
string obtenerFecha() {
    time_t tiempo = time(0);
    tm *fecha = localtime(&tiempo);
    string dia = to_string(fecha->tm_mday);
    string mes = to_string(fecha->tm_mon + 1);
    string anio = to_string(fecha->tm_year + 1900);
    return dia + "/" + mes + "/" + anio;
}

// Función para asegurar que el archivo de estudiantes exista con la lista completa
void inicializarArchivoEstudiantes() {
    ifstream archivoPrueba("estudiantes.txt");
    if (!archivoPrueba.is_open()) {
        ofstream archivoCrear("estudiantes.txt");
        archivoCrear << "Acosta Hanna\nAndrade Hugo\nAtiencia Josué\nBalarrezo Diego\n"
                     << "Barrionuevo Job\nBedoya Juan\nBravo Samuel\nCajiao Paulo\n"
                     << "Calvopiña Brandon\nCastelo Katherine\nChacha Víctor\n"
                     << "Chiluiza Steed\nDomínguez Daniel\nFreire Alan\nGualle Abisag\n"
                     << "Guaman Alexander\nGuanga Sebastian\nGuanotoa Karla\n"
                     << "Landeta Edison\nLara Karen\nLoor Jhon\nLopez Washington\n"
                     << "Miranda Imanol\nMonar Jhair\nMuyulema Mateo\nNarváez Antonella\n"
                     << "Nuñez Bryan\nPilco Mario\nPomaquero Katherine\nQuevedo Gina\n"
                     << "Rivadeneira Matias\nRocha Carolina\nSanchez Isaac\n"
                     << "Segovia Joseph\nSupe Joan\nToapanta Matias\nVerdesoto Kevin\n"
                     << "Villacrés Alejandro\nViteri Shantal\n";
        archivoCrear.close();
    }
    archivoPrueba.close();
}

int main() {
    inicializarArchivoEstudiantes();

    int opcion;
    string nombreSeleccionado = "Ninguno";
    vector<string> listaEstudiantes;
    string linea;

    // Cargar la lista desde el archivo
    ifstream archivoEstudiantes("estudiantes.txt");
    if (archivoEstudiantes.is_open()) {
        while (getline(archivoEstudiantes, linea)) {
            if (!linea.empty()) listaEstudiantes.push_back(linea);
        }
        archivoEstudiantes.close();
    }

    double num1, num2, resultado;
    float notas[5], suma, promedio, mayor, menor;
    int aprobados, reprobados;

    do {
        cout << "\n======================================" << endl;
        cout << "      SISTEMA INTERACTIVO C++         " << endl;
        cout << "======================================" << endl;
        cout << "Estudiante actual: " << nombreSeleccionado << endl;
        cout << "--------------------------------------" << endl;
        cout << "1. Seleccionar estudiante de la lista\n";
        cout << "2. Operaciones basicas\n";
        cout << "3. Registro de notas (Rango 0-10)\n";
        cout << "4. Guardar resultados en archivo\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                cout << "\n--- LISTA DE ESTUDIANTES ---" << endl;
                for (size_t i = 0; i < listaEstudiantes.size(); i++) {
                    cout << i + 1 << ". " << listaEstudiantes[i] << endl;
                }
                int sel;
                cout << "\nSeleccione el numero del estudiante: ";
                cin >> sel;
                if (sel > 0 && sel <= (int)listaEstudiantes.size()) {
                    nombreSeleccionado = listaEstudiantes[sel - 1];
                    cout << "Seleccionado exitosamente: " << nombreSeleccionado << endl;
                } else {
                    cout << "Opcion no valida." << endl;
                }
                break;
            }

            case 2: {
                int opMat;
                cout << "\n1. Suma 2. Resta 3. Multiplicacion 4. Division: ";
                cin >> opMat;
                cout << "Ingrese numero 1: "; cin >> num1;
                cout << "Ingrese numero 2: "; cin >> num2;

                if(opMat == 1) resultado = num1 + num2;
                else if(opMat == 2) resultado = num1 - num2;
                else if(opMat == 3) resultado = num1 * num2;
                else if(opMat == 4) {
                    if(num2 != 0) resultado = num1 / num2;
                    else { cout << "Error: Division por cero." << endl; break; }
                }
                cout << "Resultado: " << resultado << endl;
                break;
            }

            case 3: {
                cout << "\n--- REGISTRO DE NOTAS (Estudiante: " << nombreSeleccionado << ") ---" << endl;
                suma = 0; aprobados = 0; reprobados = 0;

                for(int i = 0; i < 5; i++) {
                    do {
                        cout << "Ingrese la nota " << (i + 1) << " (0 a 10): ";
                        cin >> notas[i];
                        if(notas[i] < 0 || notas[i] > 10) {
                            cout << "¡ERROR! La nota debe estar entre 0 y 10." << endl;
                        }
                    } while(notas[i] < 0 || notas[i] > 10);

                    suma += notas[i];
                    if(i == 0) { mayor = menor = notas[i]; }
                    if(notas[i] > mayor) mayor = notas[i];
                    if(notas[i] < menor) menor = notas[i];
                    if(notas[i] >= 7) aprobados++; else reprobados++;
                }
                promedio = suma / 5;
                cout << "\nPromedio: " << promedio << " | Aprobados: " << aprobados << " | Reprobados: " << reprobados << endl;
                break;
            }

            case 4: {
                if(nombreSeleccionado == "Ninguno") {
                    cout << "Error: Primero debe seleccionar un estudiante (Opcion 1)." << endl;
                } else {
                    ofstream archivoRes("resultados.txt", ios::app);
                    if(archivoRes.is_open()) {
                        archivoRes << "Fecha: " << obtenerFecha() << " | Estudiante: " << nombreSeleccionado
                                   << " | Promedio: " << promedio << " | Mayor: " << mayor
                                   << " | Menor: " << menor << endl;
                        archivoRes.close();
                        cout << "Resultados de " << nombreSeleccionado << " guardados con exito." << endl;
                    }
                }
                break;
            }
        }
    } while(opcion != 5);

    return 0;
}
