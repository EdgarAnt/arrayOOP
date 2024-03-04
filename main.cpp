#include <iostream>
#include <iomanip>
#include <limits>
#include "persona.h"

void limpiarBuffer() {
    // Limpiar el búfer de entrada
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Limpiar los flags de error
    std::cin.clear();
}
using namespace std;

int main(){
	CPersona arregloP[5];
	char opcion;
	int cantidadElementos=0;

    do{
    	cout<<"----------------------------------------------------------------------"<<endl;
    	cout<<"\n";
        cout << setw(40)<<"MENU - Agenda de contactos"<<endl;
        cout <<"\n"<< setw(25)<<"1.- Altas"<<endl;
        cout << setw(49)<<"2.- Consulta individual(telefono)"<<endl;
        cout << setw(39)<<"3.- Consultas guardadas"<<endl;
        cout << setw(25)<<"4.- Salir"<<endl;
        cout << setw(24)<<"Opcion: ";
        cin>>opcion;
        switch(opcion){

			case '1':{
				if (cantidadElementos < 5) {
		    		string nom, dir;
    				long long tel;
    				cout << "\n";
    				for (int i = 0; i < 5; i++) {
        				limpiarBuffer();  // Limpiar el búfer antes de leer el nombre
        				cout << "-------------------------------------------------------------------------------" << endl;
				        cout << setw(25)<< "Nombre: ";
				        getline(cin, nom);
        				cout << setw(28)<< "Direccion: ";
    				    getline(cin, dir);
					    cout << setw(27)<< "Telefono: ";
        				cin >> tel;
						limpiarBuffer();
    					arregloP[cantidadElementos].asignarNombre(nom);
   						arregloP[cantidadElementos].asignarTelefono(tel);
    					arregloP[cantidadElementos].asignarDireccion(dir);
    					cantidadElementos++;
					}
    			}
    			else{
    				cout << "\n----------------------------------------------------------------------" << endl;
    				cout << "\n" << setw(25) << "Se encuentra la agenda llena\n"<<endl;
				}
    			break;
    		}
			case '2':{
				long long  numero;
    	        cout << "\n----------------------------------------------------------------------------------------" << endl;
        	    cout << "\n"<<setw(25) << "Ingresa un numero: ";
       	    	limpiarBuffer(); // Limpiar el búfer antes de leer el número
        	    cin >> numero;
            	limpiarBuffer(); // Limpiar el búfer después de leer el número

    	        bool encontrado = false;
            	for (int i = 0; i < cantidadElementos; i++) {
            	    if (arregloP[i].obtenerTelefono() == numero) {
                	    cout << "\n------------------------------------------------------------------\n"<<endl;
                	    cout << setw(25) << "Telefono:" << setw(11)<< arregloP[i].obtenerTelefono() << endl;
                	    cout << setw(23) << "Nombre:" << setw(18)<< arregloP[i].obtenerNombre() << endl;
                	    cout << setw(26) << "Direccion:" << setw(15)<< arregloP[i].obtenerDireccion() <<"\n"<< endl;
                	    encontrado = true;
                	    break;
                	}
            	}

            	if (!encontrado) {
                	cout<< "---------------------------------------------------" << endl;
                	cout<<"\n"<<setw(25) << "Numero no encontrado" << endl;
            	}
            	break;
        	}
            case '3': {
    // Encontrar la longitud máxima del nombre para ajustar el ancho del campo
            int max_longitud_nombre = 0;//determinar la longitud maxima de los nombres de un arreglo
            for (int i = 0; i < 5; i++) {
                int longitud_actual = arregloP[i].obtenerNombre().length();//sabes el valor de longitud dedl objeto
                if (longitud_actual > max_longitud_nombre) {
                    max_longitud_nombre = longitud_actual;
                }
            }


            // Imprimir encabezado de la tabla
            cout << "-----------------------------------------------------------------------------------------------------------" << endl;
            cout << setw(max_longitud_nombre + 5) << right << "NOMBRE";//determinar la longitud maxima del objeto y ajustarlo a su ancho
            cout << setw(20) << right << "TELEFONO";
            cout << setw(20) << right << "DIRECCION" << endl;
            cout << "-----------------------------------------------------------------------------------------------------------" << endl;

            // Imprimir datos de cada objeto en el arreglo
            for (int i = 0; i < 5; i++) {
                cout << setw(max_longitud_nombre + 5) << arregloP[i].obtenerNombre();
                cout << setw(20) << arregloP[i].obtenerTelefono();
                cout <<"\t"<< setw(20) << arregloP[i].obtenerDireccion() << endl;
            }

            cout << endl;
            break;
        }
        	case '4':{
        		cout<<"------------------------------------------------"<<endl;
        		cout<<setw(25)<<"Saliendo del programa..."<<endl;
				break;
			}
			default:
				cout<<"\n------------------------------------------------"<<endl;
				cout<<"\n"<<setw(25)<<"Opcion incorrecta, vuelva elegir\n"<<endl;
			}
    }while(opcion!='4');
}
