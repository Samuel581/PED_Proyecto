#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <locale.h>
 
using namespace std;
 
//Estructura utilizada para realizar el ranking de géneros más vistos
struct sortGen{
    int cant_tick = 0;
    string id;
};
 
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
 
list<nodo> accion; //Inicializamos las listas donde se guardaran los tickets vendidos
list<nodo> drama;
list<nodo> comedia;
void push_backL(string nombre, string nombreP, int cantidad, list<nodo> *s); //Declaramos las funciones que usaremos en el programa
int cant();
void accionMenu(string nombreCliente), dramaMenu(string nombreCliente), comediaMenu(string nombreCliente);
bool confirmar();
void mostrarTicket(list<nodo> *s);
void TicketsPorCategoria();
vector<sortGen> sortV(int accion, int comedia, int drama);
void ganancia();
float gananciastotales=0;
 
int main(){
    setlocale(LC_ALL, "");  //Función utilizada para agregar caracteres especiales: palabras tildadas
    cout << R"(
   ---------------------------------------------------------------
       ______                _ __         _______ __              
      / ____/___ _____ ___  (_) /_  __   / ____(_) /___ ___  _____
     / /_  / __ `/ __ `__ \/ / / / / /  / /_  / / / __ `__ \/ ___/
    / __/ / /_/ / / / / / / / / /_/ /  / __/ / / / / / / / (__  )
   /_/    \__,_/_/ /_/ /_/_/_/\__, /  /_/   /_/_/_/ /_/ /_/____/  
                             /____/                              
   ---------------------------------------------------------------
   )" << endl;
    int opcionMenuP{0}, opcionTran{0}; string client_name;//Inicializando la variable opcion
    bool estadoMenuP{true}, estadoTran;//Inicializando un bool para usarlo como continuación o stop del menú
    while(estadoMenuP){
        estadoTran=true;
        cout << "   - | Menú principal | -\n" << endl;
        cout <<"1. Hacer una transacción" << endl;
        cout <<"2. Ver las categorías más populares" << endl;
        cout <<"3. Calcular ganancias totales" << endl;
        cout <<"4. Salir" << endl;
        cout << "Opción a escoger: ";
        cin >> opcionMenuP;//Obtener accion a realizar
        //Menu
        switch(opcionMenuP){
            case 1:
            cin.ignore();
            cout<<"Ingrese el nombre y apellido del cliente: ";
            getline(cin, client_name);
            while(estadoTran){
                cout << "\n     | Transacción |\n" << endl;
                cout << "1. Película de Acción\n2. Película de Drama\n3. Película de Comedia\n" << endl;
                cout << "Opción a escoger: ";
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
                    cout << "Seleccione una opción válida " << endl;
                        break;
                }
                cout << endl;
            }
                break;
            case 2:
            cout<<endl;
            cout << "     | Categorías más populares | " << endl;
            cout<<endl;
            TicketsPorCategoria();
            cout<<endl;
            cout<<endl;
                break;
            case 3:
            cout << endl;
            cout << "     | Ganancias totales |" << endl;
            ganancia();
            cout << endl;
                break;
            case 4:
            cout << "\n¡Gracias por usar nuestro software!" << endl;
            estadoMenuP = false;
                break;
            default:
            cout << "\nSeleccione una opción válida\n" << endl;
                break;
        }
    }
}
 
void accionMenu(string nombreCliente){ //Menú de peliculas de accion
    int opc, canTicket;
    bool estado = true;
    while(estado){
    cout << "\n     | Películas de acción |\n" << endl;
                cout << "El precio para todas las películas es de: $3.50\n\n";
                cout << "1. The Karate Kid\n2. Avengers: Endgame\n3. Spiderman: Un nuevo universo\n4. Dragon Ball Super: Broly" << endl;
                cout << "Opción a escoger: ";
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
                    cout << "Seleccione una opción valida " << endl;
                        break;
                }    
    }
   
}
 
void dramaMenu(string nombreCliente){ //Menú de peliculas de drama
    int opc, canTicket;
    bool estado = true;
    while(estado){
    cout << "\n     | Películas de drama |\n" << endl;
                cout << "El precio para todas las películas es de: $3.50\n\n";
                cout << "1. Bajo la misma estrella\n2. Extraordinario\n3. Una voz silenciosa\n4. Your name" << endl;
                cout << "Opción a escoger: ";
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
                    cout << "Seleccione una opción valida " << endl;
                        break;
                }    
    }
   
}
 
void comediaMenu(string nombreCliente){ //Menú de peliculas de comedia
    int opc, canTicket;
    bool estado = true;
    while(estado){
    cout << "\n     | Películas de comedia |\n" << endl;
                cout << "El precio para todas las películas es de: $3.50\n\n";
                cout << "1. Shaolin Soccer\n2. Matilda\n3. Mi pequeño angelito\n4. Una película de huevos" << endl;
                cout << "Opción a escoger: ";
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
                    push_backL(nombreCliente,"Una película de huevos", canTicket, &comedia);
                    estado = false;
                    mostrarTicket(&comedia);
                        break;
                    default:
                    cout << "Seleccione una opción válida " << endl;
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
            cout<<"\nIngrese una cantidad de tickets válida"<<endl;
        }
    }
    return x;
}
 
//Usamos esta funcion para confirmar si ya no se realizara otra venta al mismo cliente o si se continuara
bool confirmar(){
    int opcion;
    while(true){
        cout<<"¿Desea realizar una venta más al cliente actual?"<<endl;
        cout<<"1. Si\n2. No"<<endl;
        cout<<"Ingrese una opción: ";
        cin>>opcion;
            switch(opcion){
                case 1:
                    return true;
                    break;
                case 2:
                    cout<<"Venta finalizada"<<endl;
                    return false;
                default:
                    cout<<"\nIngrese una opción válida."<<endl<<endl;
                }
    }
}
 
//Con esta funcion mostramos la compra de ticket luego de ser ingresada a la lista
void mostrarTicket(list<nodo> *s){
    cout << "\n     | Resumen de la compra |" << endl;
    cout<<"Nombre del cliente: "<<s->back().nombre <<endl;
    cout<<"Película: "<<s->back().ticket.nombrePelicula<<endl;
    cout<<"Precio c/u: $"<<s->back().ticket.precio<<endl;
    cout<<"Cantidad de tickets: "<<s->back().ticket.cantidad<<endl;
    cout<<"Monto total: $"<<s->back().total<<endl<<endl;
    gananciastotales+=s->back().total;
}
 
// Esta funcion devuelve un vector ordenado por la cantidad de tickets y nombre del genero, especificamente a la funcion TicketsPorCategoria
vector<sortGen> sortV(int accion, int comedia, int drama){
    vector<sortGen> ordenar;
    sortGen auxiliarSort;
    auxiliarSort.cant_tick = accion;
    auxiliarSort.id = "Acción";
    ordenar.push_back(auxiliarSort);
    auxiliarSort.cant_tick = comedia;
    auxiliarSort.id = "Comedia";
    ordenar.push_back(auxiliarSort);
    auxiliarSort.cant_tick = drama;
    auxiliarSort.id = "Drama";
    ordenar.push_back(auxiliarSort);
    sort( ordenar.begin(), ordenar.end(),[]( const sortGen &left, sortGen &right ){
        return ( left.cant_tick < right.cant_tick);}); //utilizamos sort para ordenar el vector a partir de la cantidad de tickets de manera ascendente
    cout<<endl;
    return ordenar; //retorna el vector ordenado para ser desplegado en pantalla
}
 
//Esta funcion imprime el ranking de generos con tickets mas comprados utilizando un vector que devuelve ordenado de menor a mayor la cantidad de tickets
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
 
    vector<sortGen> arreglo = sortV(acc,com,dram);
 
    if (acc==0 && dram==0 && com==0){
        cout<<"Aún no se ha visto ninguna película\n\n";
    }else if(acc>0 && acc==dram && dram==com){
        cout<<"Todas las categorías tienen la misma cantidad de tickets comprados. \n\n"; //Imprimimos desde el ultimo ya que fue ordenado de menor a mayor
        cout<< arreglo.at(2).id<<" -> tickets comprados: "<<arreglo.at(2).cant_tick;
        cout<<"\n"<<arreglo.at(1).id<<" -> tickets comprados: "<<arreglo.at(1).cant_tick;
        cout<<"\n"<<arreglo.at(0).id<<" -> tickets comprados: "<<arreglo.at(0).cant_tick;
    }else{
        cout<<"1- "<<arreglo.at(2).id<<" -> tickets comprados: "<<arreglo.at(2).cant_tick;
        cout<<"\n2- "<<arreglo.at(1).id<<" -> tickets comprados: "<<arreglo.at(1).cant_tick;
        cout<<"\n3- "<<arreglo.at(0).id<<" -> tickets comprados: "<<arreglo.at(0).cant_tick;
    }
}
 
//Esta funcion devuelve las ganancias de todas las ventas de tickets
void ganancia(){
    nodo unNodo;
    unNodo.total=gananciastotales;
    if(unNodo.total==0){
        cout<<"\nActualmente no se han registrado transacciones "<<endl;
    }
    else{
        cout<<"\nLa ganancia total registrada es de: $"<<unNodo.total<<endl;
    }
}
