#include <iostream>
#include <string>
#include <vector>

using namespace std;

//CARMEN SÁNCHEZ HERNÁNDEZ 

struct Estudiante {
	string nombre;
	string grado;
	string correo;
};

vector<Estudiante> baseDatos {};

void addEstudiante();
void eliminarEstudiante();
void listarEstudiantesPorGrado();
void listarTodosEstudiantes();

int menu();

int menu() {
	int respuesta;
	do {
		cout << " -------- BASE DE DATOS DE LA UNIVERSIDAD -------- " << "\n";
		cout << "1. Agregar estudiante: " << "\n";
		cout << "2. Borrar estudiante: " << "\n";
		cout << "3. Listar estudiantes por grado: " << "\n";
		cout << "4. Listar todos los estudiantes: " << "\n";
		cout << "5. Salir. " << "\n";
		cout << "Ingrese una opcion: ";
		cin >> respuesta;

		if (respuesta != 1 && respuesta != 2 && respuesta != 3 && respuesta != 4 && respuesta != 5)
			cout << "\n\n\t La opcion no es valida. Por favor, vuelva a seleccionar otra opcion. ";
	} while (respuesta != 1 && respuesta != 2 && respuesta != 3 && respuesta != 4 && respuesta != 5);

	return respuesta;
}

void addEstudiante() {
	cout << "--- Crear estudiante -- \n";

	Estudiante estudiante;

	cout << "Ingresa tu nombre: \n";
	cin.ignore();
	getline(cin, estudiante.nombre);

	cout << "Ingresa tu correo para la admision: \n";

	cin.ignore();
	getline(cin, estudiante.correo);

	cout << "Selecciona el grado que estudias: " << "\n";

	cout << "1. Informatica. " << "\n";
	cout << "2. Quimica. " << "\n";
	cout << "3. Fisica. " << "\n";
	cout << "4. Matematicas. " << "\n";

	int opcionGrado;
	cin >> opcionGrado;

	switch (opcionGrado) {
	case 1: {
		estudiante.grado = "Informatica. ";
		break;
	}
	case 2: {
		estudiante.grado = "Quimica. ";
		break;
	}
	case 3: {
		estudiante.grado = "Fisica. ";
		break;
	}
	case 4: {
		estudiante.grado = "Matematicas. ";
		break;
	}
	default: {
		cout << "No es ningun grado de nuestra universidad. Lo siento. " << "\n";
		return;
	}
	}

	baseDatos.push_back(estudiante);

	cout << " Estudiante agregado correctamente. " << "\n";
}

void eliminarEstudiante() {
	cout << "--- Eliminar estudiante ---" << "\n";

	string nombreEstudiante;
	cout << "Ingrese el nombre del estudiante a eliminar: ";
	cin.ignore();
	getline(cin, nombreEstudiante);

	bool estudianteEncontrado = false;
	for (auto it = baseDatos.begin(); it != baseDatos.end(); ++it) {
		if (it->nombre == nombreEstudiante) {
			estudianteEncontrado = true;
			it = baseDatos.erase(it);
			cout << "Estudiante eliminado correctamente. " << "\n";
			break;
		}
	}

	if (!estudianteEncontrado) {
		cout << "No se encontro al estudiante en la base de datos de la universidad. \n";
	}

	cout << "Lista actualizada de estudiantes de la universidad: " << "\n";
	for (const auto& listaEstudiante : baseDatos) {
		cout << "Nombre: " << listaEstudiante.nombre << "\n";
		cout << "Carrera: " << listaEstudiante.grado << "\n";
		cout << "Correo: " << listaEstudiante.correo << "\n";
		cout << "-----------------------------------" << "\n";
	}
}

void listarEstudiantesPorGrado() {
	cout << " --- Mostrar estudiantes por grado elegido --- " << "\n";

	if (baseDatos.empty()) {
		cout << "No hay estudiantes en la base de datos de la universidad. " << "\n";
	}
	else {
		cout << "Selecciona el grado que deseas mostrar: " << "\n";
		cout << "1. Informatica. " << "\n";
		cout << "2. Quimica. " << "\n";
		cout << "3. Fisica. " << "\n";
		cout << "4. Matematicas. " << "\n";

		int opcionGradoAMostrar;
		cin >> opcionGradoAMostrar;

		string gradoMostrar;
		switch (opcionGradoAMostrar) {
		case 1:
			gradoMostrar = "Informatica. ";
			break;
		case 2:
			gradoMostrar = "Quimica. ";
			break;
		case 3:
			gradoMostrar = "Fisica. ";
			break;
		case 4:
			gradoMostrar = "Matematicas. ";
			break;
		default:
			cout << "No es ningun grado de nuestra universidad. Lo siento." << "\n";
			return;
		}

		bool encontrado = false;
		cout << "Estudiantes en " << gradoMostrar << ":" << "\n";
		for (const auto& ListaEstudianteGrado : baseDatos) {
			if (ListaEstudianteGrado.grado == gradoMostrar) {
				cout << "Nombre: " << ListaEstudianteGrado.nombre << "\n";
				cout << "Carrera: " << ListaEstudianteGrado.grado << "\n";
				cout << "Correo: " << ListaEstudianteGrado.correo << "\n";
				encontrado = true;
			}
		}

		if (!encontrado) {
			cout << "No se encontraron estudiantes en " << gradoMostrar << "." << "\n";
		}
	}
}

void listarTodosEstudiantes() {
	cout << "--- Mostrar estudiante  ----" << "\n";

	if (baseDatos.empty()) {
		cout << "No hay estudiantes en la base de datos de la universidad. ";
	}
	else {
		cout << "Lista de estudiantes de la base de datos de la universidad: " << "\n";
		for (const auto& listadoEstudiante : baseDatos) {
			cout << "Nombre: " << listadoEstudiante.nombre << "\n";
			cout << "Carrera: " << listadoEstudiante.grado << "\n";
			cout << "Correo: " << listadoEstudiante.correo << "\n";
			cout << "--------------------------" << "\n";
		}
	}
	return;
}

int main() {

	int opcion = menu();

	while (opcion != 5) {
		switch (opcion) {
		case 1:
			addEstudiante();
			break;
		case 2:
			eliminarEstudiante();
			break;
		case 3:
			listarEstudiantesPorGrado();
			break;
		case 4:
			listarTodosEstudiantes();
			break;
		case 5:
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
