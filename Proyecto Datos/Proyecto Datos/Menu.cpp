#include "Menu.h"

void Menu::mostrar() {
    int opcion;
    bool finaliza = true;
    do {
        std::cout << "      ___________________________________________________";
        std::cout << "     |                                                   |";
        std::cout << "     |                        MENU                       |";
        std::cout << "     |___________________________________________________|";
        std::cout << "     |                                                   |";
        std::cout << "     |-->DIGITE 1:| Insertar un usuario a la cola        |";
        std::cout << "     | ------------------------------------------------  |";
        std::cout << "     |-->DIGITE 2:| Eliminar usuario prioritario         |";
        std::cout << "     | ------------------------------------------------  |";
        std::cout << "     |-->DIGITE 3:| Mostrar usuario prioritario          |";
        std::cout << "     | -----------------------------------------------   |";
        std::cout << "     |-->DIGITE 3:| Ver elementos en la cola             |";
        std::cout << "     | -----------------------------------------------   |";
        std::cout << "     |-->DIGITE 4:| Insertar una lista a una cola        |";
        std::cout << "     | -----------------------------------------------   |";
        std::cout << "     |-->DIGITE 0:| Salir                                |";
        std::cout << "     |___________________________________________________|";
        std::cout << "Elija la opcion que desee llevar a cabo: "; std::cin >> opcion;

        switch (opcion) {
        case 1: {
            insertar();
            break;
        }

        case 2: {
            modificar();
            break;
        }

        case 3: {
            borrarInfo();
            break;
        }

        case 4: {
            ingresarDinero();
            break;
        }
        case 5: {
            retirarDinero();
            break;
        }
        case 6: {
            maquinaAdmin->toString();
            pausa();
            break;
        }
        case 0: {
            finaliza = false;
            break;
        }

        default: imprimeCadenaEndl("Opcion no valida"); break;
        }
    } while (finaliza);
}

void Menu::insertar(){
    int prioridad;
    std::string nombre;

    std::cout << "Ingrese la informacion del elemento a insertar: \n";
    std::cout << "Ingrese el caracter identificador: (A,B,C,D...) \n";
    std::cin >> nombre;

    std::cout << "Ingrese la prioridad del elemento:\n";
    std::cin >> prioridad;
    Usuario usuario(nomre, prioridad);
    cola->insertar(usuario);

    std::cout << "\tUsuario encolado exitosamente.\n\n";
 
   system("pause");

}

void Menu::eliminar() {
    cola->eliminar();
}