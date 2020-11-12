#include <iostream>
#include <list>
#include <string>
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
void accionMenu(string nombreCliente), dramaMenu(string nombreCliente), comediaMenu(string nombreCliente);
bool confirmar();
void mostrarTicket(list<nodo> *s);

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
    int opcionMenuP{0}, opcionTran{0}; string client_name;//Incializando la variable opcion
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
            cin.ignore();
            cout<<"Ingrese el nombre y apellido del cliente: ";
            getline(cin, client_name);
            while(estadoTran){
                cout << "\n     | Transaccion |\n" << endl;
                cout << "1. Pelicula de Accion\n2.Pelicula de Drama\n3.Pelicula de Comedia\n4.Terminar transaccion" << endl;
                cout << "Seleccione accion a realizar: ";
                cin >> opcionTran;
                switch(opcionTran){
                    case 1:
                    accionMenu(client_name);
                    estadoTran=confirmar();
                        break;
                    case 2:
                    estadoTran=confirmar();
                        break;
                    case 3:
                    estadoTran=confirmar();
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

void accionMenu(string nombreCliente){
    int opc, canTicket;
    bool estado = true;
    while(estado){
    cout << "\n     | Peliculas de accion |\n" << endl;
                cout << "1. The Karate Kid\n2. Avengers: Endgame\n3.Spiderman: Un nuevo universo\n4.Dragon Ball Super: Broly" << endl;
                cout << "Seleccione accion a realizar: ";
                cin >> opc;
                canTicket = cant(); 
                switch(opc){
                    case 1:
                    push_backL(nombreCliente,"The Karate Kid", canTicket, &accion);
                    estado = false;
                    mostrarTicket(&accion);
                        break;
                    case 2:
                    push_backL(nombreCliente,"Avengers: Endgame", canTicket, &accion);
                    estado = false;
                    mostrarTicket(&accion);
                        break;
                    case 3:
                    push_backL(nombreCliente,"Spiderman: Un nuevo universo", canTicket, &accion);
                    estado = false;
                    mostrarTicket(&accion);
                        break;
                    case 4:
                    push_backL(nombreCliente,"Dragon Ball Super: Broly", canTicket, &accion);
                    estado = false;
                    mostrarTicket(&accion);
                        break;
                    default:
                    cout << "Seleccione una opcion valida " << endl;
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

bool confirmar(){
    int opcion;
    while(true){
        cout<<"1. Si\n2. No"<<endl;
                cout<<"¿Desea realizar una venta mas al cliente actual?: ";
                cin>>opcion;
                switch(opcion){
                    case 1:
                        return true;
                        break;
                    case 2:
                        cout<<"Venta finalizada"<<endl;
                        return false;
                    default:
                        cout<<"Ingrese una opcion valida."<<endl;
               }
    }
}

void mostrarTicket(list<nodo> *s){
    cout<<"Nombre del cliente: "<<s->back().nombre<<endl;
    cout<<"Pelicula: "<<s->back().ticket.nombrePelicula<<endl;
    cout<<"Precio c/u: "<<s->back().ticket.precio<<endl;
    cout<<"Cantidad de tickets: "<<s->back().ticket.cantidad<<endl;
    cout<<"Monto total: "<<s->back().total<<endl;
}