#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

//CARMEN SÁNCHEZ HERNÁNDEZ 

struct Libro {
	string autor;
	string titulo;
	array<string,3> tags; 
	string ubicacion;
	int indice;
};

vector<Libro> biblioteca{}; //almacen de libros

//funciones 
int menu();
void darDeAltaLibro();
void darDeBajaLibro();
void listarLibros();
void modificarLibro();
void buscarLibroTags();
void buscarLibroTitulo();
void buscarLibroAutor();

int menu() {

	int respuesta;
	bool opcionValida = false;
	vector<int> opcionesValidas = { 1, 2, 3, 4, 5, 6, 7, 8 };
	do {
		cout << "\n";
		cout << " -------- GESTION DE UNA BIBLIOTECA  -------- " << "\n";
		cout << "1. Dar de alta un libro. " << "\n";
		cout << "2. Dar de baja un libro. " << "\n";
		cout << "3. Listar todos los libros de la biblioteca. " << "\n";
		cout << "4. Modificar los datos del libro. " << "\n";
		cout << "5. Buscar un libro por tags. " << "\n";
		cout << "6. Buscar un libro por titulo. " << "\n";
		cout << "7. Buscar un libro por autor. " << "\n";
		cout << "8. Salir. " << "\n";
		cout << "Ingrese una opcion: ";
		cin >> respuesta;

		for (int opcion : opcionesValidas) {
			if (respuesta == opcion) {
				opcionValida = true;
				break;
			}
		}
		if (!opcionValida) { 
			cout << "\n\n\t La opcion no es valida. Por favor, vuelva a seleccionar otra opcion. ";
		}
	} while (!opcionValida);  

	return respuesta;
}

void darDeAltaLibro() {
	Libro librito;
	cout << "\n Ingrese el autor del libro que quiere: ";
	cin.ignore();
	getline(cin, librito.autor);

	cout << "\n Ingrese el titulo del libro que quiere: ";
	getline(cin, librito.titulo);

	cout << "\n Ingrese las etiquetas del libro: ";
	for (int i{ 0 }; i < librito.tags.size(); i++) {
		getline(cin, librito.tags[i]); 
	}

	cout << "\n Ingrese la ubicacion del libro: ";
	getline(cin, librito.ubicacion);

	cout << "\n Ingrese el indice del libro: ";
	cin >> librito.indice;

	biblioteca.push_back(librito);

	cout << "\n El libro ha sido dado de alta con exito. ";
}

void darDeBajaLibro() {
	string tituloABuscar;
	cout << "Ingrese el titulo del libro a dar de baja: "; 
	cin.ignore();
	cin >> tituloABuscar;
	
	bool libroEncontrado = false;

	for (auto it = biblioteca.begin(); it != biblioteca.end(); it++) {
		if (it->titulo == tituloABuscar) {
			libroEncontrado = true;
			it = biblioteca.erase(it);
			cout << "\n El libro ha sido de baja correctamente. ";
			break;
		}
	}

	if (!libroEncontrado) { 
		cout << "\n No se encontro el libro en la biblioteca. ";
	}
}

void listarLibros() {
	if (biblioteca.empty()) {
		cout << "\n La biblioteca esta vacia. ";
	}
	cout << "\n Lista de libros: ";
	for (const Libro& lib : biblioteca) { 
		cout << "\n Titulo: " << lib.titulo; 
		cout << "\n Autor: " << lib.autor; 
		cout << "\n Ubicacion: " << lib.ubicacion;  
		cout << "\n Indice: " << lib.indice; 
		cout << "\n Tags: "; 
		for (const string& tag : lib.tags) { 
			cout << tag << " "; 
		}
	}
}

void modificarLibro() {
	cout << "\n Modificar libro: ";
	if (biblioteca.empty()) { 
		cout << "No hay libros para modificar.\n";
	}
	else {
		int indiceAModificar{ 0 };
		cout << "\n Ingrese el numero de indice que desea modificar: ";
		cin >> indiceAModificar;

		if (indiceAModificar >= 1 && indiceAModificar <= biblioteca.size()) {
			Libro& librito = biblioteca.at(indiceAModificar - 1);
			
			cout << "\n Ingrese el nuevo autor del libro: ";
			cin >> librito.autor;
			cout << "\n Ingrese el nuevo titulo del libro: ";
			cin >> librito.titulo; 
			cout << "\n Ingrese la nueva ubicacion del libro: "; 
			cin >> librito.ubicacion;

			cout << "\n Ingrese los nuevos tags del libro (separados por espacios): ";
			for (int i{ 0 }; i < 3; i++) {
				cin >> librito.tags[i]; 
			}

			cout << "\n Libro modificado correctamente. ";

		}
		else {
			cout << "\n Indice incorrecto. ";
		}
	}
}

void buscarLibroTags() {
	if (biblioteca.empty()) {
		cout << "\n La biblioteca esta vacia.";
	}

	string tagBusqueda;  
	cout << "Ingrese el tag a buscar: "; 
	cin >> tagBusqueda; 

	bool libroTagEncontrado = false; 

	for (const Libro& librito : biblioteca) { 
		for (const string& tag : librito.tags) {  
			if (tag == tagBusqueda) { 
				cout << "\n Autor: " << librito.autor; 
				cout << "\n Titulo: " << librito.titulo; 
				cout << "\n Tags: "; 
				for (const string& libroTag : librito.tags) { 
					cout << libroTag << " "; 
				}

				libroTagEncontrado = true;
				break;
			}
		}
	}

	if (!libroTagEncontrado) {
		cout << "\n No se encontraron libros con el tag especificado.";
	}
}

void buscarLibroTitulo() {
	if (biblioteca.empty()) { 
		cout << "La biblioteca esta vacia.";
	}

	string tituloBusqueda; 
	cout << "\n Ingrese el titulo a buscar: ";
	cin.ignore(); 
	getline(cin, tituloBusqueda); 

	bool libroTituloEncontrado = false;

	for (const Libro& librito : biblioteca) {
		for (const char& titulito : librito.titulo) {
			if (librito.titulo == tituloBusqueda) {
				cout << "\n Autor: " << librito.autor;
				cout << "\n Titulo: " << librito.titulo;
				cout << "\n Tags: ";
				for (const string& libroTag : librito.tags) {
					cout << libroTag << " ";
				}

				libroTituloEncontrado = true; 
				break;
			}
		}
	}

	if (!libroTituloEncontrado) {
		cout << "\n No se encontraron libros con el titulo especificado.";
	}
}

void buscarLibroAutor() { 
	if (biblioteca.empty()) { 
		cout << "La biblioteca esta vacia.";
	}

	string autorBusqueda; 
	cout << "\n Ingrese el autor a buscar: "; 
	cin.ignore(); 
	getline(cin, autorBusqueda);

	bool libroAutorEncontrado = false;

	for (const Libro& librito : biblioteca) { 
		if (librito.autor == autorBusqueda) { 
			cout << "\n Autor: " << librito.autor; 
 			cout << "\n Titulo: " << librito.titulo;
			cout << "\n Tags: "; 
			for (const string& libroTag : librito.tags) { 
				cout << libroTag << " "; 
			}

			libroAutorEncontrado = true; 
			break;
		}
	}

	if (!libroAutorEncontrado) {
		cout << "\n No se encontraron libros con el autor especificado.";
	}
}

int main() { 
	 
	int opcion = menu(); 

	while (opcion != 8) {
		switch (opcion) { 
		case 1:
			darDeAltaLibro();
			break;
		case 2:
			darDeBajaLibro();
			break;
		case 3:
			listarLibros();
			break;
		case 4:
			modificarLibro();
			break;
		case 5:
			buscarLibroTags();
			break;
		case 6:
			buscarLibroTitulo();
			break;
		case 7: 
			buscarLibroAutor();
			break;
		case 8:
			cout << "Saliendo... "; 
			exit(0); 
		default:
			cout << "Opcion invalida. Intente nuevamente." << "\n";
			break;
		}
		opcion = menu();
	}

	return 0;

}
