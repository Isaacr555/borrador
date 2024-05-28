#include <iostream>
#include "Lote.h"

using namespace std;

// Constructor por defecto
Lote::Lote() : nombreCliente(""), idCliente(0), precioLote(0.0), estadoOcupacion('L'), identificadorLote(""), cantRepisasLote(0), categoriaRiego(""), servicio(""), precioServicio(0.0), precioRiego(0.0), iva(0.0), precioTotal(0.0), dispo(true) {}

// Constructor con parámetros
Lote::Lote(string nombreCliente, int idCliente, double precioLote, char estadoOcupacion, string identificadorLote, int cantRepisasLote, string categoriaRiego, string servicio, double precioServicio, double precioRiego, double iva, double precioTotal)
    : nombreCliente(nombreCliente), idCliente(idCliente), precioLote(precioLote), estadoOcupacion(estadoOcupacion), identificadorLote(identificadorLote), cantRepisasLote(cantRepisasLote), categoriaRiego(categoriaRiego), servicio(servicio), precioServicio(precioServicio), precioRiego(precioRiego), iva(iva), precioTotal(precioTotal), dispo(true) {}

// Setters
void Lote::setNombreCliente(string nombreCliente) { this->nombreCliente = nombreCliente; }
void Lote::setIdCliente(int idCliente) { this->idCliente = idCliente; }
void Lote::setPrecioLote(double precioLote) { this->precioLote = precioLote; }
void Lote::setEstadoOcupacion(char estadoOcupacion) { this->estadoOcupacion = estadoOcupacion; }
void Lote::setIdentificadorLote(string identificadorLote) { this->identificadorLote = identificadorLote; }
void Lote::setCantRepisasLote(int cantRepisasLote) { this->cantRepisasLote = cantRepisasLote; }
void Lote::setCategoriaRiego(string categoriaRiego) { this->categoriaRiego = categoriaRiego; }
void Lote::setServicio(string servicio) { this->servicio = servicio; }
void Lote::setPrecioServicio(double precioServicio) { this->precioServicio = precioServicio; }
void Lote::setPrecioRiego(double precioRiego) { this->precioRiego = precioRiego; }
void Lote::setIva(double iva) { this->iva = iva; }
void Lote::setPrecioTotal(double precioTotal) { this->precioTotal = precioTotal; }
void Lote::setDispo(bool dispo) { this->dispo = dispo; }

// Getters
string Lote::getNombreCliente() { return nombreCliente; }
int Lote::getIdCliente() { return idCliente; }
double Lote::getPrecioLote() { return precioLote; }
char Lote::getEstadoOcupacion() { return estadoOcupacion; }
string Lote::getIdentificadorLote() { return identificadorLote; }
int Lote::getCantRepisasLote() { return cantRepisasLote; }
string Lote::getCategoriaRiego() { return categoriaRiego; }
string Lote::getServicio() { return servicio; }
double Lote::getPrecioServicio() { return precioServicio; }
double Lote::getPrecioRiego() { return precioRiego; }
double Lote::getIva() { return iva; }
double Lote::getPrecioTotal() { return precioTotal; }
bool Lote::getDispo() { return dispo; }

// Método para calcular el precio total
void Lote::calcularPrecioTotal() {
    double basePrice = precioLote;

    // Calcular el precio del servicio
    if (servicio == "todo incluido") {
        precioServicio = basePrice * 0.15;
    } else if (servicio == "estándar") {
        precioServicio = basePrice * 0.05;
    }

    // Calcular el precio del riego
    if (categoriaRiego == "aspersión mecanizada") {
        precioRiego = basePrice * 0.05;
    } else {
        precioRiego = 0.0;
    }

    // Calcular IVA
    iva = (basePrice + precioServicio + precioRiego) * 0.13;

    // Calcular el precio total
    precioTotal = basePrice + precioServicio + precioRiego + iva;
}

// Funciones para manejar la lógica sin entrada/salida directa
void comprarLote(Lote lotes[], int numLotes, string nombreCliente, int idCliente, int lotesComprados, string categoriaRiego, string servicio) {
    char estadoOcupacion = 'O';
    double precioLote;

    if (lotesComprados > numLotes) {
        throw invalid_argument("No hay suficientes lotes disponibles.");
    }

    if (lotesComprados == 1) {
        precioLote = 1500.00;
    } else if (lotesComprados == 2) {
        precioLote = 1350.00;
    } else if (lotesComprados == 3) {
        precioLote = 1200.00;
    } else if (lotesComprados >= 4) {
        precioLote = 1050.00;
    }

    for (int i = 0; i < numLotes && lotesComprados > 0; i++) {
        if (lotes[i].getEstadoOcupacion() == 'L') {
            lotes[i].setNombreCliente(nombreCliente);
            lotes[i].setIdCliente(idCliente);
            lotes[i].setEstadoOcupacion(estadoOcupacion);
            lotes[i].setPrecioLote(precioLote);
            lotes[i].setCategoriaRiego(categoriaRiego);
            lotes[i].setServicio(servicio);
            lotes[i].calcularPrecioTotal();
            lotesComprados--;
        }
    }
}

void consultarLotes(Lote lotes[], int numLotes, string& consulta) {
    consulta.clear();
    for (int i = 0; i < numLotes; i++) {
        if (lotes[i].getEstadoOcupacion() == 'O') {
            consulta += "Lote " + to_string(i + 1) + ":\n";
            consulta += "Nombre del cliente: " + lotes[i].getNombreCliente() + "\n";
            consulta += "ID del cliente: " + to_string(lotes[i].getIdCliente()) + "\n";
            consulta += "Precio del lote: " + to_string(lotes[i].getPrecioLote()) + "\n";
            consulta += "Categoría de riego: " + lotes[i].getCategoriaRiego() + "\n";
            consulta += "Servicio: " + lotes[i].getServicio() + "\n";
            consulta += "Precio total: " + to_string(lotes[i].getPrecioTotal()) + "\n\n";
        }
    }
}



    return 0;
}
