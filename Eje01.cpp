#include <iostream>
using namespace std;

//Se crea clase Abstracta "Figura"
class Figura {
public:
    virtual void dibujar() = 0;
    virtual double calcular_area() = 0;
};

//Se crea Clase Derivada "Círculo"
class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    void dibujar() override {
        //Implementación para dibujar un círculo
        cout<<"Dibujando un circulo..."<<endl;
    }
    double calcular_area() override {
        return 3.14159 * radio * radio; //Fórmula para el área de un círculo
    }
};

//Clase Derivada "Rectángulo"
class Rectangulo : public Figura {
private:
    double base;
    double altura;
public:
    Rectangulo(double b, double h) : base(b), altura(h) {}
    void dibujar() override {
        //Implementación para dibujar un rectángulo
        cout<<"Dibujando un rectangulo..."<<endl;
    }
    double calcular_area() override {
        return base * altura; //Fórmula para el área de un rectángulo
    }
};

//Clase Derivada "Triángulo"
class Triangulo : public Figura {
private:
    double base;
    double altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {}
    void dibujar() override {
        //Implementación para dibujar un triángulo
        cout<<"Dibujando un triangulo..."<<endl;
    }
    double calcular_area() override {
        return (base * altura) / 2; //Fórmula para el área de un triángulo
    }
};

int main() {
    Circulo circulo(5);  //Círculo con radio 5
    Rectangulo rectangulo(4, 6);  //Rectángulo con base 4 y altura 6
    Triangulo triangulo(3, 4);  //Triángulo con base 3 y altura 4

    circulo.dibujar();
    cout<<"Area del circulo: "<<circulo.calcular_area()<<endl;

    rectangulo.dibujar();
    cout<<"Area del rectangulo: "<<rectangulo.calcular_area()<<endl;

    triangulo.dibujar();
    cout<<"Area del triangulo: "<<triangulo.calcular_area()<<endl;

    return 0;
}
