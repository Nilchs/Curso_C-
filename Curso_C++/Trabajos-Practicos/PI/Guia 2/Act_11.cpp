/*Implementar un programa que almacene en un arreglo estático, los datos de los ciudadanos que solicitaron un
certificado de antecedentes en el Registro Nacional de las Personas. De cada ciudadano se conoce: nombre y
apellido, fecha de nacimiento (tipo long: formato AAAAMMDD), dirección, número de documento, tipo de
documento (tipo int: 1 -DNI-, 2 -Pasaporte-, 3 -Otro-) y sexo (tipo char: 'M', 'F').
a) Hacer un módulo de carga del arreglo, utilizando una condición de corte adecuada. Se debe validar el
tipo de documento (1, 2 ó 3) y dejar al usuario en un bucle mientras ingrese un número inválido.
b) Imprimir el listado, con el siguiente formato de ejemplo:
Nombre y apellido: Juan Perez
Dirección: Levalle 132
Fecha de nacimiento: 27/10/1979
Tipo de documento: DNI
Número de documento: 27439221
Sexo: masculino
- La fecha debe mostrarse en formato dd/mm/aa. El tipo de documento debe mostrarse con su nombre.
- El género debe mostrar la palabra completa.
c) Implementar un módulo que, dado el arreglo original, cargue en otro arreglo los ciudadanos de sexo
masculino únicamente. Imprimir este nuevo arreglo.
d) Hacer lo mismo que en el punto anterior, pero obteniendo sólo las mujeres. Modularizar para no repetir
código.*/

#include <iostream>
#include <string>
using namespace std;

struct Documento {
        int long DNI;
        string pasaporte;
        string  otro;
};

struct Ciudadano {
    string nombre;
    string apellido;
    string direccion;
    int long fecha_nacimiento;
    char sex;
    int tipo_documento;
    Documento documentos; 
};

const int max_Ciudadanos = 500;

void  cargaCiudadanos(Ciudadano ciudadanos[], int& dl) {
    if (dl >= max_Ciudadanos) // Si el arreglo está lleno, no se puede cargar más ciudadanos.
    {
        cout << "\nNo hay más espacio para agregar alumnos." << endl;
        return;
    }
    for (int  i = dl; i < max_Ciudadanos; i++) {
        cout  << "\nIngrese el nombre del ciudadano: ";
        getline(cin >> ws, ciudadanos[i].nombre);
        cout  << "Ingrese el apellido del ciudadano: ";
        getline(cin >> ws, ciudadanos[i].apellido);
        cout  << "Ingrese la fecha de nacimiento del ciudadano (AAAA/MM/DD): ";
        cin >> ciudadanos[i].fecha_nacimiento;
        cin.ignore();
        cout  << "Ingrese el tipo de documento del ciudadano (1 - DNI-,  2 -Pasaporte-, 3 -Otro-): ";
        int tipo_doc;
        cin >> tipo_doc;
        while  (tipo_doc < 1 || tipo_doc > 3) {
            cout << "\nError, ingrese un tipo de documento valido (1, 2 o 3): "; //  Si el tipo de documento no es válido, solicitarlo nuevamente.
            cin >> tipo_doc;
        }
        ciudadanos[i].tipo_documento = tipo_doc; // Guarda el tipo de documento que ingreso el usuario.
        if  (tipo_doc == 1) {
            cout << "\nIngrese el DNI del ciudadano: ";
            cin >> ciudadanos[i].documentos.DNI;
        }
        else if  (tipo_doc == 2) {
            cout << "\nIngrese el Pasaporte del ciudadano: ";
            getline(cin >> ws, ciudadanos[i].documentos.pasaporte);
        }
        else {
            cout << "\nIngrese el Otro del ciudadano: ";
            getline(cin >> ws, ciudadanos[i].documentos.otro);
        }
        cout << "\nIngrese el sexo del ciudadano (M/F): ";
        cin >> ciudadanos[i].sex;
        dl++;
        
        cout << "\n¿Desea agregar otro ciudadano? (S/N): ";
        char respuesta;
        cin >> respuesta;
        if (respuesta == 'N' || respuesta == 'n') {
            break;
        }
    }
}

void  imprimirCiudadanos(Ciudadano ciudadanos[], int dl) {
    for (int i = 0; i < dl; i++) {
        int dia, mes, ano;
        dia = ciudadanos[i].fecha_nacimiento % 100; //  Obtiene el dia de la fecha de nacimiento.   
        mes = (ciudadanos[i].fecha_nacimiento / 100) % 100; //   Obtiene el mes de la fecha de nacimiento.
        ano = ciudadanos[i].fecha_nacimiento / 10000; //   Obtiene el año de la fecha de nacimiento.
        string tipo_documento; //   Variable para mostrar el tipo de documento.
        
        cout << "\nNombre y apellido: " << ciudadanos[i].nombre << " " << ciudadanos[i].apellido;
        cout << "\nDireccion: " << ciudadanos[i].direccion;
        cout << "\nFecha de nacimiento: " << dia << "/" << mes << "/" << ano;
        if (ciudadanos[i].tipo_documento == 1) {
            cout  << "\nTipo de documento: DNI";
        } else if (ciudadanos[i].tipo_documento == 2) {
            cout  << "\nTipo de documento: Pasaporte";
        } else {
            cout  << "\nTipo de documento: Otro";
        }
        cout << "Numero de documento: " << ciudadanos[i].documentos.DNI;
        string sexo;
        if (ciudadanos[i].sex == 'M') {
            sexo = "Masculino";
        } else {
            sexo = "Femenino";
        }
    }
}

void filtrar_por_sexo(Ciudadano ciudadanos[], int dl, char sexo) {
    Ciudadano ciudadanosM[max_Ciudadanos];
    int  dlM = 0;
    for (int i = 0; i < dl; i++)
    {
        if (ciudadanos[i].sex == sexo) {
            ciudadanosM[dlM] = ciudadanos[i];
            dlM++;
        }
    }
    for (int j = 0; j < dlM; j++)
    {
        //mostramos aca
    }
    
}


int main () {
    int dl = 0;
    Ciudadano ciudadanos[max_Ciudadanos];
    cargaCiudadanos(ciudadanos, dl);

    imprimirCiudadanos(ciudadanos, dl);

    return 0;
}