#include <iostream>
#include <string>

using namespace std;
//clase Empleado
class Empleado {
    protected:  //Atributos protegidos
        string nombre;  //nombre de empleado
        int horas;      //horas que trabaja
        float salario;  //salario de empleado
        static const int costoHora = 40;    //atributo estático

    public:     //métodos públicos
        //Constructor de la clase
        Empleado(string n, int h) : nombre(n), horas(h) {}

        //Métodos virtuales puros
        virtual float calcularSalario()  = 0;
        virtual void mostrarDatos() = 0;

        //Destructor virtual de la clase
        virtual ~Empleado() {}
};

//Clase Empleado de Tiempo Completo
class EmpleadoTiempoCompleto : public Empleado { //Herencia pública
    public: //Métodos públicos
        //Constructor de la clase
        EmpleadoTiempoCompleto(string n, int h) : Empleado(n, h) {}

        //Sobreescritura de calcularSalario()
        float calcularSalario() override {
            salario = horas * costoHora;
            return salario;
        }
        //Sobreescritura de mostrarDatos()
        void mostrarDatos() override {
            cout<<"Empleado de tiempo completo"<<endl;
            cout<<"El salario de "<<nombre<<" es: "<<salario<<" soles."<<endl;
        }
    };

class EmpleadoMedioTiempo : public Empleado {   //Herencia pública
    public: //Métodos públicos
        //Constructor de la clase
        EmpleadoMedioTiempo(string n, int h) : Empleado(n, h) {}

        //Sobreescritura de calcularSalario;
        float calcularSalario() override {
            salario = horas * costoHora;
            return salario;
        }
        //Sobreescritura de mostrarDatos()
        void mostrarDatos() override {
            cout<<"Empleado de medio tiempo"<<endl;
            cout<<"El salario de "<<nombre<<" es: "<<salario<<" soles."<<endl;
        }
};

int main() {
    int cantidad;   //cantidad de empleados

    cout<<"Ingrese la cantidad de empleados: ";
    cin>>cantidad;  //cantidad de empleados

    Empleado* empleados[cantidad];  //Arreglo de empleados

    //For para crear objetos de cada Tipo de Empleado
    for (int i = 0; i < cantidad; ++i) {
        string nombre;  //nombre de empleado
        int horas;      //horas trabajadas

        cout<<"Ingrese el nombre del empleado "<<i + 1<<": ";
        cin>>nombre;    //nombre de empleado
        cout<<"Ingrese las horas trabajadas por "<<nombre<<": ";
        cin>>horas;     //horas trabajadas

        if (horas >= 40) {  //Mayor a 40 horas es trabajo de tiempo completo
            //Creación de objetos de manera dinámica
            empleados[i] = new EmpleadoTiempoCompleto(nombre, horas);
        } else {
            //Creación de objetos de manera dinámica
            empleados[i] = new EmpleadoMedioTiempo(nombre, horas);
        }
        //Calcula el salario de cada empleado que se va creando
        empleados[i]->calcularSalario();
    }

    //For para mostrar datos de Empleados
    cout<<endl<<"Datos de los empleados:"<<endl;
    for (int i = 0; i < cantidad; ++i) {
        cout<<endl;     //espacio entre cada empleado
        empleados[i]->mostrarDatos();
        delete empleados[i]; // Liberar la memoria
    }
    return 0;
}
