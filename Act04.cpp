#include <iostream>
using namespace std;

class Vehiculo{     //Clase base Vehiculo
    public:
    virtual void acelerar(){       //Metodo virtual
        cout<<"Acelerando vehiculo"<<endl;
    }
};

class Coche : public Vehiculo{  //Clase derivada Coche que hereda de la clase Vehiculo
    public:
    void acelerar(){    //Se redefine el metodo acelerar (Reemplazo)
        cout<<"Acelerando Coche"<<endl;
    }

    void encenderluces() {      //Se añade un nuevo metodo a la clase Coche (Refinamiento)
        cout<<"Luces del coche encendidas"<<endl;
    }

};

class Motocicleta : public Vehiculo{    //Clase derivada Motocicleta que hereda de la clase Vehiculo
    public:
    void acelerar(){    //Se redefine el metodo acelerar (Reemplazo)
        cout<<"Acelerando Motocicleta"<<endl;
    }
};
int main()
{
    Vehiculo vehiculo;
    vehiculo.acelerar();

    Coche coche;
    coche.acelerar();
    coche.encenderluces();

    Motocicleta motocicleta;
    motocicleta.acelerar();
    return 0;
}
