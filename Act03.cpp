#include <iostream>
#include <string>

using namespace std;
//Clase base "Animal"
class Animal {
public:
    virtual void hacerSonido() {
        cout<<"Los animales hacen un sonido."<<endl;
    }
};

//Clases derivadas
class Perro : public Animal {
public:
    void hacerSonido() override {
        cout<<"El perro dice: Guau guau"<<endl;
    }
};

class Gato : public Animal {
public:
    void hacerSonido() override {
        cout<<"El gato dice: Miau miau"<<endl;
    }
};

class Vaca : public Animal {
public:
    void hacerSonido() override {
        cout<<"La vaca dice: Muuu muuu"<<endl;
    }
};

int main() {
    //Crear instancias de diferentes animales
    Animal* perro = new Perro();
    Animal* gato = new Gato();
    Animal* vaca = new Vaca();

    //Llamar al método hacerSonido() en cada animal
    perro->hacerSonido();
    gato->hacerSonido();
    vaca->hacerSonido();

    //Liberar la memoria de las instancias
    delete perro;
    delete gato;
    delete vaca;

    return 0;
}
