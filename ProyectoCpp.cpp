#include<iostream>
#include<cmath>
#include<fstream>				//incluimos librerias
#include<cstdlib>
#include<stdlib.h>
using namespace std;


class Cliente{ 							//Creamos la clase Cliente
	private:							//Determinamos los atributos privados de la clase
		float total = 100;
		float ingr, extr;		
		
	public: 							//Determinamos los metodos (publicos de la clase)
		void ingreso();
		void extraer();
		void  ver();
};


void Cliente::ver(){
	
	cout << "Ha solicitado la opcion de revisar el saldo de su cuenta." << endl;
	
	ifstream archivo; 											//creamos el objeto archivo de la clase ifstream 
	string nombreArchivo;										//creamos el objeto nombreArchivo de la clase string
	string linea;												//creamos el objeto linea de la clase string para introducir texto(una linea)
	
	cout <<"Nombre de la libreta que quieres leer: ";
	cin.ignore(256,'\n');										//borramos buffer
	getline(cin, nombreArchivo);								//tomamos el nombre de la nueva libreta
	archivo.open(nombreArchivo.c_str(), ios::in);				//abrimos la libreta con el nombre especificado
	
	if(archivo.fail()){											//si dicha libreta no existe, se da error
		cout<<"No pude abrir el archivo";
		exit(1);
	}
	while(!archivo.eof()){										//si la libreta existe, se abre y vemos lo que hay escrito en ella
		getline(archivo, linea);
		cout<<linea<<endl;
	}
	archivo.close();	 										//cerramos la libreta

	cout << "El capital disponible de su cuenta es de " << total << " euros" << endl;
	cout << "Accion realizada con exito, gracias por confiar en nosotros." << endl;
	system("pause");
}

void Cliente::ingreso(){
	cout << "Ha solicitado la opcion de ingresar saldo en su cuenta." << endl;
	
	fflush(stdin);												//vaciamos buffer
	ofstream archivo; 											//creamos el objeto archivo de la clase ofstream 
	string nombreArchivo; 
	string linea;
	
	cout << "Nombre de tu cartilla del banco en la que realizar el ingreso: ";
	getline(cin, nombreArchivo);
	archivo.open(nombreArchivo.c_str(), ios::app);

	if(archivo.fail()){
		cout<<"No pude abrir tu libreta.";
		exit(1);
	}

	cout << "¿Cuantos euros quiere ingresar? // ** para cerrar tu libreta.";		//solicitamos la cantidad a ingresar
	cin >>  ingr;																	//dicha cantidad se guarda en la variable ingr
	
	do{																				//hasta que se escriba **, se escribe en la libreta el ingreso
		getline(cin,linea);
		if(linea!="**"){
		
			archivo<<"ingreso    ---------------  +"<<ingr<<linea<<endl;
		}
	}
	while(linea!="**");																//cuando escribamos ** se cerrara la libreta
	archivo.close();

	cout << "Capital en la cuenta: " << total << " euros." << endl;
	cout << "Capital ingresado: " << ingr << " euros" << endl;
	total = total + ingr;
	cout << "Capital actualizado de la cuenta: " << total << " euros." << endl;
	cout << "Accion realizada con exito, gracias por confiar en nosotros." << endl;
	
	system("pause");																//el sistema se detiene hasta que pulsas cualquier tecla
}



void Cliente::extraer(){
	cout << "Ha solicitado la opcion de extraer saldo de su cuenta." << endl;
	
	fflush(stdin);
	ofstream archivo; 
	string nombreArchivo; 
	string linea;
	
	cout << "Nombre de tu cartilla del banco en la que realizar la extraccion: ";
	getline(cin, nombreArchivo);
	archivo.open(nombreArchivo.c_str(), ios::app);

	if(archivo.fail()){
		cout<<"No pude abrir tu libreta.";
		exit(1);
	}

	cout << "¿Cuantos euros quiere extraer? // ** tras el capital a extraer. ";		//solicitamos la cantidad a extraer
	cin >>  extr;																	//dicha cantidad se guarda en la variable extr
	
	if(total < extr){															//si extr es mayor que el capital total, no se realiza la extraccion
		cout << "No es posible extraer la cantidad deseada" << endl;
		cout << "Solo hay " << total << " euros disponibles" << endl;
	}
	else if(total >= extr){															//si extr es menor que el capital total, se realiza la extraccion
		total = total - extr;
		cout << "Capital extraido: " << extr << "euros" << endl;
		cout << "Capital disponible: " << total << endl;
		
		cout << "Ha extraido con exito " << extr << " euros, gracias por confiar en nosotros." << endl;		
	}
	
	
	do{																				//si se extrae capital, se indica en la libreta
		getline(cin,linea);
		if(linea!="**"){
		
			archivo<<"extraccion ---------------  -"<<extr<<linea<<endl;
		}
	}
	while(linea!="**");
	archivo.close();
	
	
	
	system("pause");
}


int main(){																		
	int op;
	Cliente c;																//creamos un objeto de la clase Cliente que llamamos c
	
	cout << "*****   B I E N V E N I D O   *****" << endl;
	
	do{																		//escribimos en pantalla el menu principal
		cout << "=======================================" << endl;
		cout << "Seleccione la accion que desea realizar: " << endl;
		cout << "=======================================" << endl;
		cout << "1.- Revisar saldo de la cuenta" << endl;
		cout << "2.- Realizar un nuevo ingreso" << endl;
		cout << "3.- Extraer efectivo" << endl;
		cout << "4.- Salir" << endl;
		
		cin >> op;															//la opcion elegida se guarda en la variable op

		
		switch(op){															//dependiendo del valor de op(opcion escogida) se llama a un metodo de 
			case 1: c.ver();												//cliente o a otro diferente
					break;
			case 2: c.ingreso();
					break;
			case 3: c.extraer();
					break;
			case 4: cout << "Hasta otra!!" << endl;
					break;
			default: cout << "Esa opcion no esta en el menu";
					 break;  
		}
		system("cls");														//tras ejecutarse la opcion elegida, se vuelve al menu


	}
	
	while (op!=4);
	
	system ("pause");
	
	return 0;
}
