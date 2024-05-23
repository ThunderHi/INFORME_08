#include <iostream>
#include <string>
using namespace std;

class Forma{ //clase completamente abstracta (no metodos ni atributos, solo el metodo abstracto)
    public:
    virtual double calcularPerimetro() = 0; //metodo abstracto para calcular perimetro
};

class Circulo : public Forma{ //clase derivada de la clase Forma 
    public:
    int radio; //atributo del radio
    Circulo(int r) : radio(r) {} //constructor que inicializa el radio
    
    double calcularPerimetro(){ //implementacion del metodo abstracto
        return 3.14159*radio*2; //retorna el perimetro de la figura
    }
};

class Rectangulo : public Forma{
    public:
    int base;
    int altura;
    Rectangulo(int b, int h) : base(b), altura(h){}
    double calcularPerimetro(){
        return base+base+altura+altura;
    }
};

class Cuadrado : public Forma{
    public:
    int lado;
    Cuadrado(int l) : lado(l){}
    double calcularPerimetro(){
        return lado*4;
    }
};

class Triangulo : public Forma{
    public:
    int lado;
    Triangulo(int l) : lado(l){}
    double calcularPerimetro(){
        return lado*3;
    }
};

int main(){
    int r, b, h, l; //declaramos las variables a usar en las figuras
    double per;
    string figura; //variable string para ingresar por teclado
    
    cout<<"circulo(cir), rectangulo(rec), cuadrado(cua), triangulo equilatero(tri)"<<endl;
    cout<<"ingrese la figura que desea calcular el perimetro (ingresar datos positivos): ";
    cin>>figura;
    if (figura == "cir"){ //en caso de elegir el circulo
        do{ 
            cout<<"ingrese el radio del circulo: ";
            cin>>r; 
        }while (r<1); //valida que el numero ingresado sea positivo y distinto de 0
        Circulo ci1(r); //creamos un objeto de la clase Circulo
        ci1.calcularPerimetro();
        cout<<"El perimetro del circulo es: "<< ci1.calcularPerimetro() <<endl;
    }
    
    if (figura == "rec"){
        do{
            cout<<"ingrese la base del rectangulo: ";
            cin>>b; 
        }while (b<1);
        do{
            cout<<"ingrese la altura del rectangulo: ";
            cin>>h; 
        }while (h<1);
        Rectangulo r1(b,h);
        per = r1.calcularPerimetro();
        cout<<"El perimetro del rectangulo es: "<< per <<endl;
    }
    
    if (figura == "cua"){
        do{
            cout<<"ingrese el lado del cuadrado: ";
            cin>>l; 
        }while (l<1);
        Cuadrado cu1(l);
        cu1.calcularPerimetro();
        cout<<"El perimetro del cuadrado es: "<< cu1.calcularPerimetro() <<endl;
    }
    
    if (figura == "tri"){
        do{
            cout<<"ingrese el lado del triangulo equilatero: ";
            cin>>l; 
        }while (l<1);
        Triangulo t1(l);
        t1.calcularPerimetro();
        cout<<"El perimetro del triangulo equilatero es: "<< t1.calcularPerimetro() <<endl;
    }
    
    if(figura != "cir" && figura != "rec" && figura != "cua" && figura != "tri"){
        cout<<"opcion no valida, terminando programa...";
    }
    return 0;
}
