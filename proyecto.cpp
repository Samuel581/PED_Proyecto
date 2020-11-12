#include <iostream>
#include <list>
using namespace std;

struct Pelicula{
    string nombrePelicula;
    float precio = 3.50;
    int cantidad=0;
};

typedef struct Pelicula pelicula;

struct transaccion{
    string nombre;
    pelicula ticket;
    float total;
};

typedef struct transaccion nodo;

list<nodo> accion;
list<nodo> drama;
list<nodo> comedia;
void push_backL(string nombre, string nombreP, int cantidad, list<nodo> *s);
int cant();

int main(){
    cout << " ----------------------------------------------------------------------------" << endl;
    cout << "| #######                                    #######                         |" << endl;
    cout << "| #         ##   #    # # #     #     #      #       # #      #    #  ####   |" << endl;
    cout << "| #        #  #  ##  ## # #      #   #       #       # #      ##  ## #       |" << endl;
    cout << "| #####   #    # # ## # # #       # #        #####   # #      # ## #  ####   |" << endl;
    cout << "| #       ###### #    # # #        #         #       # #      #    #      #  |" << endl;
    cout << "| #       #    # #    # # #        #         #       # #      #    # #    #  |" << endl;
    cout << "| #       #    # #    # # ######   #         #       # ###### #    #  ####   |" << endl;
    cout << " ----------------------------------------------------------------------------" << endl << endl;
    int opcion = 0;//Incializando la variable opcion
    bool estado = true;//Inizializando un bool para usarlo como contunuacion o stop del menu
    while(estado){
        cout <<"1. Hacer una transaccion" << endl;
        cout <<"2. Ver las categorias mas populares" << endl;
        cout <<"3. Calcular ganancias totales" << endl;
        cout <<"4. Salir" << endl;
        cout << ">>>> ";
        cin >> opcion;//Obtener accion a realizar
        //Menu
        switch(opcion){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
            cout << "Gracias por usar nuestro software!" << endl;
            estado = false;
                break;
            default:
            cout << "\nSeleccione una opcion valida!\n" << endl;
                break;
        }
    }
}

void push_backL(string nombre, string nombreP, int cantidad,  list<nodo> *s){
    nodo auxiliar;
    pelicula aux;
    aux.nombrePelicula = nombreP;
    aux.cantidad = cantidad;
    auxiliar.nombre = nombre;
    auxiliar.total = (float) aux.cantidad * aux.precio;
    auxiliar.ticket = aux;
    s->push_back(auxiliar);
}

int cant(){
    int x=0;
    while(x<=0){
        cout<<"Ingrese la cantidad de tickets a comprar: ";
        cin>>x;
        if(x>0){
            break;
        }else{
            cout<<"Ingrese una cantidad de tickets valida"<<endl;
    }
    return x;
}