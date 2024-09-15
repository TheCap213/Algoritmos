#include "Feedback.h"

class ListaFeedbacks {
private:
	Feedback** feedbacks;
	int numFeedbacks;
public:
	ListaFeedbacks() {
		numFeedbacks = 0;
		feedbacks = new Feedback * [numFeedbacks];
	}

	~ListaFeedbacks() {
		for (int i = 0; i < numFeedbacks; i++) {
			delete feedbacks[i];
		}
		delete[] feedbacks;
	}

	void AgregarFeedback(Feedback * f) {
		Feedback** aux = new Feedback * [numFeedbacks + 1];
		for (int i = 0; i < numFeedbacks; i++) {
			aux[i] = feedbacks[i];
		}
		aux[numFeedbacks] = f;
		numFeedbacks++;

		if (feedbacks != nullptr) delete[] feedbacks;
		feedbacks = aux;
	}

	void EliminarFeedback(int ind) {
		if (ind < 0 || ind >= numFeedbacks) {
			cout << "Feedback no encontrado." << endl;
			return;
		}

		Feedback** aux = new Feedback * [numFeedbacks - 1];
		for (int i = 0, j = 0; i < numFeedbacks; i++) {
			aux[j++] = feedbacks[i];
		}
		delete feedbacks[ind];
		delete[] feedbacks;
		feedbacks = aux;
		numFeedbacks--;

		cout << "Feedback eliminado correctmente." << endl;
	}

	void MostrarListaFeedbacks() {
		if (numFeedbacks == 0) {
			cout << "No se encuentran Feedbacks registrados..." << endl;
		}

		cout << "Codigo\t\tEdad\tCiudad\tFecha\t\tMinutos\tScore" << endl;
		for (int i = 0; i < numFeedbacks; i++) {
			cout << feedbacks[i]->getCodigoJugador() << "\t"
				<< feedbacks[i]->getEdad() << "\t"
				<< feedbacks[i]->getCiudad() << "\t"
				<< feedbacks[i]->getFecha() << "\t"
				<< feedbacks[i]->getMinutosJuegos() << "\t"
				<< feedbacks[i]->getScoreRecomendacion() << endl;
		}

	}
	
	void ReporteCiudadLima() {
		for (int i = 0; i < numFeedbacks; i++) {
			if (feedbacks[i]->getCiudad() == "Lima" || feedbacks[i]->getCiudad() == "LIMA") {
				feedbacks[i]->mostrarFeedback();
			}
		}
	}

	void ReporteMayorMinutos() {
		if (numFeedbacks == 0) {
			cout << "No hay feedbacks registrados..." << endl;
		}

		int maxMinutos = feedbacks[0]->getMinutosJuegos();
		int indiceMayor = 0;

		for (int i = 0; i < numFeedbacks; i++) {
			if (feedbacks[i]->getMinutosJuegos() > maxMinutos) {
				maxMinutos = feedbacks[i]->getMinutosJuegos();
				indiceMayor = i;
			}
		}

		cout << "Jugador con mayores minutos jugados:\n";
		feedbacks[indiceMayor]->mostrarFeedback();
	}

	void ReporteAgosto2024() {
		for (int i = 0; i < numFeedbacks; i++) {
			if (feedbacks[i]->getFecha().substr(0, 6) == "202408") {
				feedbacks[i]->mostrarFeedback();
			}
		}
	}

	void ReportesScoreMenorCinco() {
		for (int i = 0; i < numFeedbacks; i++) {
			if (feedbacks[i]->getScoreRecomendacion() < 5) {
				feedbacks[i]->mostrarFeedback();
			}
		}
	}

};