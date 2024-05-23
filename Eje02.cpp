#include <iostream>
#include <string>
using namespace std;

//interfaz "Reproductor"
class Reproductor{ //metodos virtuales puros para reproducir, pausar y detener
    public:
        virtual void reproducir(string archivo) = 0;
        virtual void pausar() = 0;
        virtual void detener() = 0;
};

//clase "Reproductormp3" que implementa la interfaz "Reproductor"
class Reproductormp3 : public Reproductor{
    private:
        bool reproduciendo; //atributo booleano (indica si se esta reproduciendo un archivo)
        string archivoActual;

    public:
        Reproductormp3() : reproduciendo(false), archivoActual(""){}

        void reproducir(string archivo) override{ //implementamos el metodo "reproducir"
            if (reproduciendo == false){ //si el archivo no se esta reproduciendo
                reproduciendo = true; //el archivo empieza a reproducirse
                archivoActual = archivo;
                cout << "reproduciendo archivo mp3: " << archivoActual << endl;
            }else{
                cout << "ya se esta reproduciendo un archivo mp3" << endl;
            }
        }

        void pausar() override{
            if (reproduciendo){ //si el archivo se esta reproduciendo
                reproduciendo = false; //el archivo deja de reproducirse
                cout<< "pausando reproduccion del archivo mp3: " << archivoActual << endl;
            }else{
                cout<< "no se esta reproduciendo ningun archivo mp3, no se puede pausar" << endl;
            }
        }
    
        void detener() override{
            if (reproduciendo){
                reproduciendo = false;
                cout<<"deteniendo reproduccion del archivo mp3: " << archivoActual << endl;
            }else{
                cout<<"no se esta reproduciendo ningun archivo mp3, no se puede detener"<< endl;
            }
        }
};

int main(){
    Reproductormp3 rp; //creamos objeto de la clase "Reproductormp3"
    rp.detener(); //muestra mensaje de error
    rp.pausar(); //en este caso tambien
    rp.reproducir("cumbia.mp3"); //se reproduce este archivo
    rp.reproducir("salsa.mp3"); //se intenta reproducir este, pero sale error
    rp.pausar(); //se pausa la reproduccion del archivo "cumbia.mp3"
    rp.reproducir("salsa.mp3"); //este archivo empieza a reproducirse
    rp.reproducir("bachata.mp3"); //otra vez sale error al intentar reproducir un archivo cuando otro ya lo está haciendo
    rp.detener(); //se detiene la reproduccion de "salsa.mp3"
    rp.reproducir("reggaeton.mp3"); //se reproduce "reggaeton.mp3"

    return 0;
}
