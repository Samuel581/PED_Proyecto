#include <iostream>
#include <list>
#include <string>
using namespace std;

struct Pelicula{
    string nombrePelicula;
    float precio = 3.50;
    int cantidad = 0;
};

typedef struct Pelicula pelicula; // Creamos un tipo definido para struct Pelicula

struct transaccion{
    string nombre;
    pelicula ticket;
    float total;
};

typedef struct transaccion nodo; // Creamos un tipo definido para struct transaccion

list<nodo> accion; //Inicializamos las listas donde se guardaran los ticket vendidos
list<nodo> drama;
list<nodo> comedia;
void push_backL(string nombre, string nombreP, int cantidad, list<nodo> *s);
int cant();
void accionMenu(string nombreCliente), dramaMenu(string nombreCliente), comediaMenu(string nombreCliente);
bool confirmar();
void mostrarTicket(list<nodo> *s);
void TicketsPorCategoria();
void ganancia();
float gananciastotales=0;

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
    bool estadoMenuP{true}, estadoTran;//Inizializando un bool para usarlo como continuacion o stop del menu
    while(estadoMenuP){
        estadoTran=true;
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
                cout << "1. Pelicula de Accion\n2. Pelicula de Drama\n3. Pelicula de Comedia\n" << endl;
                cout << "Seleccione accion a realizar: ";
                cin >> opcionTran;
                switch(opcionTran){
                    case 1:
                    accionMenu(client_name);
                    estadoTran=confirmar();
                        break;
                    case 2:
                    dramaMenu(client_name);
                    estadoTran=confirmar();
                        break;
                    case 3:
                    comediaMenu(client_name);
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
            cout<<endl;
            cout << "     | Categorias mas populares | " << endl;
            cout<<endl;
            TicketsPorCategoria();
            cout<<endl;
                break;
            case 3:
            cout << "     | Ganancias totales |" << endl;
                ganancia();
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

void accionMenu(string nombreCliente){ //Menu de peliculas de accion
    int opc, canTicket;
    bool estado = true;
    while(estado){
    cout << "\n     | Peliculas de accion |\n" << endl;
                cout << "1. The Karate Kid\n2. Avengers: Endgame\n3. Spiderman: Un nuevo universo\n4. Dragon Ball Super: Broly" << endl;
                cout << "Seleccione accion a realizar: ";
                cin >> opc;
                switch(opc){
                    case 1:
                    canTicket = cant(); 
                    push_backL(nombreCliente,"The Karate Kid", canTicket, &accion);
                    estado = false;
                    mostrarTicket(&accion);
                        break;
                    case 2:
                    canTicket = cant(); 
                    push_backL(nombreCliente,"Avengers: Endgame", canTicket, &accion);
                    estado = false;
                    mostrarTicket(&accion);
                        break;
                    case 3:
                    canTicket = cant();     
                    push_backL(nombreCliente,"Spiderman: Un nuevo universo", canTicket, &accion);
                    estado = false;
                    mostrarTicket(&accion);
                        break;
                    case 4:
                    canTicket = cant(); 
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

void dramaMenu(string nombreCliente){ //Menu de peliculas de drama
    int opc, canTicket;
    bool estado = true;
    while(estado){
    cout << "\n     | Peliculas de drama |\n" << endl;
                cout << "1. Bajo la misma estrella\n2. Extraordinario\n3. Una voz silenciosa\n4. Your name" << endl;
                cout << "Seleccione accion a realizar: ";
                cin >> opc;
                switch(opc){
                    case 1:
                    canTicket = cant(); 
                    push_backL(nombreCliente,"Bajo la misma estrella", canTicket, &drama);
                    estado = false;
                    mostrarTicket(&drama);
                        break;
                    case 2:
                    canTicket = cant(); 
                    push_backL(nombreCliente,"Extraorninario", canTicket, &drama);
                    estado = false;
                    mostrarTicket(&drama);
                        break;
                    case 3:
                    canTicket = cant(); 
                    push_backL(nombreCliente,"Una voz silenciosa", canTicket, &drama);
                    estado = false;
                    mostrarTicket(&drama);
                        break;
                    case 4:
                    canTicket = cant(); 
                    push_backL(nombreCliente,"Your name", canTicket, &drama);
                    estado = false;
                    mostrarTicket(&drama);
                        break;
                    default:
                    cout << "Seleccione una opcion valida " << endl;
                        break;
                }    
    }
    
}

void comediaMenu(string nombreCliente){ //Menu de peliculas de comedia
    int opc, canTicket;
    bool estado = true;
    while(estado){
    cout << "\n     | Peliculas de comedia |\n" << endl;
                cout << "1. Shaolin Soccer\n2. Matilda\n3. Mi pequeño angelito\n4. Una pelicula de huevos" << endl;
                cout << "Seleccione accion a realizar: ";
                cin >> opc; 
                switch(opc){
                    case 1:
                    canTicket = cant(); 
                    push_backL(nombreCliente,"Shaolin Soccer", canTicket, &comedia);
                    estado = false;
                    mostrarTicket(&comedia);
                        break;
                    case 2:
                    canTicket = cant(); 
                    push_backL(nombreCliente,"Matilda", canTicket, &comedia);
                    estado = false;
                    mostrarTicket(&comedia);
                        break;
                    case 3:
                    canTicket = cant(); 
                    push_backL(nombreCliente,"Mi pequeño angelito", canTicket, &comedia);
                    estado = false;
                    mostrarTicket(&comedia);
                        break;
                    case 4:
                    canTicket = cant(); 
                    push_backL(nombreCliente,"Una pelicula de huevos", canTicket, &comedia);
                    estado = false;
                    mostrarTicket(&comedia);
                        break;
                    default:
                    cout << "Seleccione una opcion valida " << endl;
                        break;
                }    
    }
    
}

//Con esta funcion ingresaremos la venta realizada al cliente en su respectiva lista por genero
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

//Usamos esta funcion para ingresar la cantidad de tickets y validar que el numero ingresado es correcto
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

//Usamos esta funcion para confirmar si ya no se realizara otra venta al mismo cliente o si se continuara
bool confirmar(){
    int opcion;
    while(true){
        cout<<"¿Desea realizar una venta mas al cliente actual?"<<endl;
        cout<<"1. Si\n2. No"<<endl;
        cout<<"Ingrese una opcion: ";
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

//Con esta funcion mostramos la compra de ticket luego de ser ingresada a la lista
void mostrarTicket(list<nodo> *s){
    cout << "\n     | Resumen de la compra |" << endl;
    cout<<"Nombre del cliente: "<<s->back().ticket.nombrePelicula <<endl;
    cout<<"Pelicula: "<<s->back().ticket.nombrePelicula<<endl;
    cout<<"Precio c/u: $"<<s->back().ticket.precio<<endl;
    cout<<"Cantidad de tickets: "<<s->back().ticket.cantidad<<endl;
    cout<<"Monto total: $"<<s->back().total<<endl<<endl;
    gananciastotales+=s->back().total;
}

void TicketsPorCategoria(){
    int acc=0,dram=0,com=0;
    //Se recorren cada una de las listas y se guarda la cantidad de tickets totales de la lista
    list<nodo>::const_iterator(i);
    for(i=accion.begin(); i!=accion.end();i++){
        acc+=i->ticket.cantidad;
    }
    for(i=drama.begin(); i!=drama.end();i++){
        dram+=i->ticket.cantidad;
    }
    for(i=comedia.begin(); i!=comedia.end();i++){
        com+=i->ticket.cantidad;
    }
    //Se comparan las cantidades de tickets para obtener quien es el que ha tenido mayor popularidad(segun las vista)
    if (acc==0 && dram==0 && com==0){
        cout<<"Aun no se ha visto ninguna pelicula\n";
    }else if(acc>dram &&dram==0 && com==0){
        cout<<"1-Accion: "<<acc<<endl;
        cout<<"Comedia y Drama aun no han sido vistas\n";
    }else if(dram>acc && acc==0 && com==0){
        cout<<"1-Drama: "<<dram<<endl;
        cout<<"Comedia y Accion aun no han sido vistas\n";
    }else if(com>dram && dram==0 && acc==0){
        cout<<"1-Comedia: "<<com<<endl;
        cout<<"Drama y Accion aun no han sido vistas\n";
    }else if(acc>dram && dram>com && com==0){
        cout<<"1-Accion: "<<acc<<endl;
        cout<<"2-Drama: "<<dram<<endl;
        cout<<"3-Comedia: "<<com<<endl;
    }else if(acc>com && com>dram && dram==0){
        cout<<"1-Accion: "<<acc<<endl;
        cout<<"2-Comedia: "<<com<<endl;
        cout<<"3-Drama: "<<dram<<endl;
    }else if(dram>acc && acc>com && com==0){
        cout<<"1-Drama: "<<dram<<endl;
        cout<<"2-Accion: "<<acc<<endl;
        cout<<"3-Comedia: "<<com<<endl;
    }else if(dram>com && com>acc && acc==0){
        cout<<"1-Drama: "<<dram<<endl;
        cout<<"2-Comedia: "<<com<<endl;
        cout<<"3-Accion: "<<acc<<endl; 
    }else if(com>acc && acc>dram && dram==0){
        cout<<"1-Comedia: "<<com<<endl;
        cout<<"2-Accion: "<<acc<<endl;
        cout<<"3-Drama: "<<dram<<endl;
    }else if(com>dram && dram>acc && acc==0){
        cout<<"1-Comedia: "<<com<<endl;
        cout<<"2-Drama: "<<dram<<endl;
        cout<<"3-Accion: "<<acc<<endl;
    }else if(acc>dram && dram>com){
        cout<<"1-Accion: "<<acc<<endl;
        cout<<"2-Drama: "<<dram<<endl;
        cout<<"3-Comedia: "<<com<<endl;
    }else if(acc>com && com>dram){
        cout<<"1-Accion: "<<acc<<endl;
        cout<<"2-Comedia: "<<com<<endl;
        cout<<"3-Drama: "<<dram<<endl;
    }else if(dram>acc && acc>com){
        cout<<"1-Drama: "<<dram<<endl;
        cout<<"2-Accion: "<<acc<<endl;
        cout<<"3-Comedia: "<<com<<endl;
    }else if(dram>com && com>acc){
        cout<<"1-Drama: "<<dram<<endl;
        cout<<"2-Comedia: "<<com<<endl;
        cout<<"3-Accion: "<<acc<<endl; 
    }else if(com>acc && acc>dram){
        cout<<"1-Comedia: "<<com<<endl;
        cout<<"2-Accion: "<<acc<<endl;
        cout<<"3-Drama: "<<dram<<endl;
    }else if(com>dram && dram>acc){
        cout<<"1-Comedia: "<<com<<endl;
        cout<<"2-Drama: "<<dram<<endl;
        cout<<"3-Accion: "<<acc<<endl;
    }
}

void ganancia(){
    nodo unNodo;
    unNodo.total=gananciastotales;
    if(unNodo.total==0){
        cout<<"Actualmente no se han registrado transacciones "<<endl;
    }
    else{
        cout<<"La ganancia total registrada es de: "<<unNodo.total<<endl;
    }
}
