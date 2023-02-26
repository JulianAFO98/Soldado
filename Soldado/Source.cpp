#include <iostream>
#include <string>
#include  <stdlib.h>
using namespace std;

class Arma {
protected:
	string nombre;
	string _ruido;
public:
	void Ruido();
	void Mostrarnombre();
};
void  Arma::Ruido() {
	cout << _ruido << "\n";
	cout << "-----------------------------------------" << "\n";
}
class Fusil :public Arma {
public:
	Fusil();

};
Fusil::Fusil() {
	nombre = "Fusil";
	_ruido = "PUMPUMPUM";
}
class Escopeta :public Arma {
public:
	Escopeta();
};
Escopeta::Escopeta() {
	nombre = "Escopeta";
	_ruido = "Paaaaaa";
}
class Revolver :public Arma {
public:
	Revolver();
};
Revolver::Revolver() {
	nombre = "Revolver";
	_ruido = "Pum";
}
void Arma::Mostrarnombre() {
	cout << nombre << "\n";
	cout << "-----------------" << "\n";
}
class Soldado {
	Arma* _arma;
	Arma* SinArma;
public:
	void RecogerArma(Arma* arma);
	void JalarGatillo();
	void DejarArma();
	void MostrarArma();
};
void Soldado::RecogerArma(Arma* arma) {
	if (_arma == SinArma) {
		_arma = arma;
	}
	else {
		cout << "Ya posee un arma" << "\n";
		cout << "--------------------" << "\n";
	}


}
void Soldado::JalarGatillo() {
	if (_arma == SinArma) {
		cout << "No lleva ningun arma" << "\n";
		cout << "--------------------------------" << "\n";
	}
	else {
		_arma->Ruido();
	}
}
void Soldado::DejarArma() {
	_arma = SinArma;


}
void Soldado::MostrarArma() {
	if (_arma != SinArma) {
		_arma->Mostrarnombre();
	}
	else {
		cout << "No tiene un arma" << "\n";
		cout << "----------------------------" << "\n";
	}
}
int main() {

	string opcion, opcion2;
	Soldado soldado;
	Fusil* fusil = new Fusil;
	Escopeta* escopeta = new Escopeta;
	Revolver* revolver = new Revolver;
	do {
		cout << "-== Bienvenido al campo de entrenamiento, Soldado ==-" << "\n";
		cout << "Que desea hacer?" << "\n";
		cout << "(presione el numero correspondiente a la opcion del menu)" << "\n";

		cout << "1- Recoger arma" << "\n";
		cout << "2- Dejar arma" << "\n";
		cout << "3- Disparar" << "\n";
		cout << "4- Ver arma en uso" << "\n";
		cout << "x- Salir" << "\n";
		getline(cin, opcion);
		system("cls");
		if (opcion == "1") {
			do {
				cout << "Elija que arma usar" << "\n";
				cout << "1- Rifle" << "\n";
				cout << "2- Escopeta" << "\n";
				cout << "3-Revolver" << "\n";
				cout << "x- Volver" << "\n";
				getline(cin, opcion2);
				if (opcion2 == "1") {
					soldado.RecogerArma(fusil);
				}
				else {
					if (opcion2 == "2") {
						soldado.RecogerArma(escopeta);
					}
					else {
						if (opcion2 == "3") {
							soldado.RecogerArma(revolver);
						}
					}

				}

			} while (opcion2 != "x");
		}
		if (opcion == "2") {
			soldado.DejarArma();
		}
		if (opcion == "3") {
			soldado.JalarGatillo();
		}
		if (opcion == "4") {
			soldado.MostrarArma();
		}
	} while (opcion != "x");


	return 0;
}