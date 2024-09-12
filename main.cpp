#include <iostream>
#include <string.h>
#define TAM 50

using namespace std;

// Clase Empleado
class Empleado {
private:
    int ClavEmpleado;
    char Nombre[50];
    char Domicilio[100];
    float Sueldo;
    char ReportaA[50];

public:
    Empleado() : ClavEmpleado(0), Sueldo(0.0) {
        strcpy(Nombre, "");
        strcpy(Domicilio, "");
        strcpy(ReportaA, "");
    }

    void setDatos(int clave, const char* nombre, const char* domicilio, float sueldo, const char* reportaA) {
        ClavEmpleado = clave;
        strcpy(Nombre, nombre);
        strcpy(Domicilio, domicilio);
        Sueldo = sueldo;
        strcpy(ReportaA, reportaA);
    }

    void imprimeDatos() const {
        cout << "Clave: " << ClavEmpleado << endl;
        cout << "Nombre: " << Nombre << endl;
        cout << "Domicilio: " << Domicilio << endl;
        cout << "Sueldo: " << Sueldo << endl;
        cout << "Reporta a: " << ReportaA << endl;
    }
};

// Clase Pila
class Pila {
private:
    Empleado datos[TAM];
    int ult;  // Índice del último elemento (cima de la pila)

public:
    Pila() : ult(-1) {}  // Constructor inicializa la pila vacía

    bool vacia() const;
    bool llena() const;
    bool push(const Empleado&);  // Inserta un elemento en la pila
    bool pop();                  // Elimina el elemento en la cima
    Empleado top() const;         // Devuelve el elemento en la cima
    void imprime() const;         // Imprime todos los elementos de la pila
};

bool Pila::vacia() const {
    return ult == -1;
}

bool Pila::llena() const {
    return ult == TAM - 1;
}

bool Pila::push(const Empleado& elem) {
    if (llena()) {
        cout << "La pila está llena, no se puede insertar." << endl;
        return false;
    }
    ult++;
    datos[ult] = elem;
    return true;
}

bool Pila::pop() {
    if (vacia()) {
        cout << "La pila está vacía, no se puede eliminar." << endl;
        return false;
    }
    ult--;
    return true;
}

Empleado Pila::top() const {
    if (vacia()) {
        cout << "La pila está vacía." << endl;
        Empleado vacio;
        return vacio;
    }
    return datos[ult];
}

void Pila::imprime() const {
    if (vacia()) {
        cout << "La pila está vacía." << endl;
        return;
    }
    for (int i = ult; i >= 0; i--) {
        datos[i].imprimeDatos();
        cout << "---------------------" << endl;
    }
}

// Función principal con menú
int main() {
    Pila miPila;
    int opcion, clave;
    char nombre[50], domicilio[100], reportaA[50];
    float sueldo;

    do {
        cout << "Menu de opciones:\n";
        cout << "1. Push (Apilar un empleado)\n";
        cout << "2. Pop (Desapilar un empleado)\n";
        cout << "3. Top (Mostrar el empleado en la cima)\n";
        cout << "4. Salir\n";
        cout << "Elija una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Empleado emp;
                cout << "Ingrese la clave del empleado: ";
                cin >> clave;
                cin.ignore();  // Para limpiar el buffer de entrada
                cout << "Ingrese el nombre: ";
                cin.getline(nombre, 50);
                cout << "Ingrese el domicilio: ";
                cin.getline(domicilio, 100);
                cout << "Ingrese el sueldo: ";
                cin >> sueldo;
                cin.ignore();  // Limpiar el buffer
                cout << "Ingrese el nombre de la persona a la que reporta: ";
                cin.getline(reportaA, 50);

                emp.setDatos(clave, nombre, domicilio, sueldo, reportaA);

                if (miPila.push(emp)) {
                    cout << "Empleado apilado exitosamente.\n";
                }
                break;
            }
            case 2:
                if (miPila.pop()) {
                    cout << "Empleado desapilado exitosamente.\n";
                }
                break;
            case 3: {
                Empleado emp = miPila.top();
                if (!miPila.vacia()) {
                    cout << "El empleado en la cima de la pila es:\n";
                    emp.imprimeDatos();
                }
                break;
            }
            case 4:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
        cout << endl;
    } while (opcion != 4);

    return 0;
}
