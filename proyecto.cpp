#include <iostream>
#include <list>
using namespace std;

struct Pelicula{
    string nombrePelicula;
    float precio = 3.50;
    int cantidad = 0;
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
    int opcionMenuP{0}, opcionTran{0};//Incializando la variable opcion
    bool estadoMenuP{true}, estadoTran{true};//Inizializando un bool para usarlo como contunuacion o stop del menu
    while(estadoMenuP){
        cout << "   - | Menu principal | -\n" << endl;
        cout <<"1. Hacer una transaccion" << endl;
        cout <<"2. Ver las categorias mas populares" << endl;
        cout <<"3. Calcular ganancias totales" << endl;
        cout <<"4. Salir" << endl;
        cout << "Seleccione accion a realizar: ";
        cin >> opcionMenuP;//Obtener accion a realizar
        //Menu
        switch(opcionMenuP){
            case 1:
            while(estadoTran){
                cout << "\n     | Transaccion |\n" << endl;
                cout << "1. Pelicula de Accion\n2.Pelicula de Drama\n3.Pelicula de Comedia\n4.Terminar transaccion" << endl;
                cout << "Seleccione accion a realizar: ";
                cin >> opcionTran;
                switch(opcionTran){
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                    estadoTran = false;
                        break;
                    default:
                    cout << "Seleccione una opcion valida " << endl;
                        break;
                }
                cout << endl;
            }
                break;
            case 2:
            cout << "     | Categorias mas populares | " << endl;
                break;
            case 3:
            cout << "     | Ganancias totales |" << endl;
                break;
            case 4:
            cout << "\nGracias por usar nuestro software!" << endl;
            estadoMenuP = false;
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
    }
    return x;
}