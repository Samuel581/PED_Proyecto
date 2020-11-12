#include <iostream>
#include <list>
using namespace std;

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