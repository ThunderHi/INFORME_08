#include <iostream>
#include <string>
using namespace std;

class Empleado{
    protected:
        string nombre;
        float salario;
        int horas;
        static float costoHora;
    public:
        Empleado(string n, int h){
            this->nombre = n;
            this->horas = h;
        }
        virtual float calcularSalario() = 0;

};
float Empleado::costoHora = 40;

class TiempoCompleto: public Empleado{
    public:
        TiempoCompleto(string n, int h) : Empleado(n, h){}
        float calcularSalario() override {
            salario = horas*costoHora;
            return salario;
        }
        void mostrarDatos(){
            cout<<"Nombres: "<<nombre<<endl;
            cout<<"Horas trabajadas: "<<horas<<endl;
            cout<<"Salario: "<<salario<<endl;
        }

};
class MedioTiempo: public Empleado{
    public:
        MedioTiempo(string n, int h) : Empleado(n, h){}
        float calcularSalario() override {
            salario = horas*costoHora;
            return salario;
        }
        void mostrarDatos(){
            cout<<"Nombres: "<<nombre<<endl;
            cout<<"Horas trabajadas: "<<horas<<endl;
            cout<<"Salario: "<<salario<<endl;
        }
};

int main(){
    TiempoCompleto persona1("Jose", 50);
    persona1.calcularSalario();
    persona1.mostrarDatos();

    MedioTiempo persona2("Maria", 30);
    persona2.calcularSalario();
    persona2.mostrarDatos();
    return 0;
}
