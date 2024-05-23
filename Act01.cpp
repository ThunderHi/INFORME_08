#include <iostream>
using namespace std;

class Figura{   //Clase abstracta
    public:
    int area;
    virtual float calcularArea()=0; //Metodo abstracto 
};

class Circulo : public Figura {     //Clase Circulo derivada de la clase Figura
    public:
    int radio;

    Circulo(int r) : radio(r) {}

    float calcularArea() {      //Implementacion del metodo abtracto de acuerdo a la formula correspondiente del area de la figura
        return 3.14 * radio * radio;
    }
};

class Rectangulo : public Figura {  //Clase Rectangulo derivada de la clase Figura
    public:
    int altura;
    int base;

    Rectangulo(int altura, int base): altura(altura), base(base) {}

    float calcularArea() {      //Implementacion del metodo abtracto de acuerdo a la formula correspondiente del area de la figura
        return base*altura;
    }
};

class Triangulo : public Figura {   //Clase Triangulo derivada de la clase Figura
    public:
    int base;
    int altura;

    Triangulo(int altura, int base): base(base), altura(altura){}

    float calcularArea() {      //Implementacion del metodo abtracto de acuerdo a la formula correspondiente del area de la figura
        return (base*altura)/2;
    }
};

class Cuadrado : public Figura {    //Clase Cuadrado derivada de la clase Figura
    public:
    int lado;

    Cuadrado(int lado): lado(lado){}

    float calcularArea() {      //Implementacion del metodo abtracto de acuerdo a la formula correspondiente del area de la figura
        return (lado*lado);
    }
};

class Pentagono : public Figura {   //Clase Pentagono derivada de la clase Figura
    public:
    int lado;
    int apotema;

    Pentagono(int lado, int apotema): lado(lado), apotema(apotema){}

    float calcularArea(){       //Implementacion del metodo abtracto de acuerdo a la formula correspondiente del area de la figura
        return ((5*lado)*apotema)/2;
    }
};

int menu(){     //Funcion que muestra por pantalla un menu para elegir una figura
    cout<<"Elija una figura: "<<endl;
    cout<<"1) Circulo"<<endl<<"2) Rectangulo"<<endl<<"3) Triangulo"<<endl<<"4) Cuadrado"<<endl<<"5) Pentagono"<<endl;
    int opcion;     //Se guarda la opcion elegida en la variavle opcion
    cin >> opcion;
    return opcion;
};

int main(){
    int opcion = menu();    
    switch (opcion) {     
        //Se pide al usuario los datos ecesarios para hallar el area de la figura que desee 
        case 1: {      //Si se elije la opcion 1) Circulo
            int radio;
            cout << "Ingrese el radio del circulo: ";
            cin >> radio;
            Circulo c(radio);       //Se crea un objeto de la clase Circulo
            cout << "El area del circulo es: " << c.calcularArea()<<endl;
            break;
        }
        case 2: {   //Si se elije la opcion 2) Rectangulo
            int altura, base;
            cout<< "Ingrese la altura del rectangulo: ";
            cin>> altura;
            cout<< "Ingrese la base del rectangulo: ";
            cin>> base;
            Rectangulo r(altura, base);     //Se crea un objeto de la clase Rectangulo
            cout<< "El area del rectangulo es: " << r.calcularArea()<<endl;
            break;
        }
        case 3: {   //Si se elije la opcion 3) Triangulo
            int altura, base;   
            cout<< "Ingrese la altura del triangulo: ";
            cin>> altura;
            cout<< "Ingrese la base del triangulo: ";
            cin>> base;
            Triangulo t(altura, base);      //Se crea un objeto de la clase Triangulo
            cout<< "El area del triangulo es: " << t.calcularArea()<<endl;
            break;
        }
        case 4:{    //Si se elije la opcion 4) Cuadrado
            int lado;
            cout << "Ingrese el lado del cuadrado: ";
            cin>> lado;
            Cuadrado c(lado);       //Se crea un objeto de la clase Cuadrado
            cout<< "El area del cuadrado es: " << c.calcularArea()<<endl;
            break;
        }
        case 5: {   //Si se elije la opcion 4) Pentagono
            int lado;
            int apotema;
            cout<< "Ingrese el lado del pentagono: ";
            cin>> lado;
            cout<< "Ingrese el apotema del pentagono: ";
            cin>> apotema;
            Pentagono p(lado, apotema); //Se crea un objeto de la clase Pentagono
            cout<< "El area del pentagono es: " << p.calcularArea()<<endl;
            break;
        }
        default:    
            cout<< "Opcion invalida!" << endl;
            break;
    }

    return 0;
}
