#ifndef LOTE_H
#define LOTE_H

#include <string>
using namespace std;

class Lote {
private:
    string nombreCliente;
    int idCliente;
    double precioLote;
    char estadoOcupacion;
    string identificadorLote;
    int cantRepisasLote;
    string categoriaRiego;
    string servicio;
    double precioServicio;
    double precioRiego;
    double iva;
    double precioTotal;
    bool dispo;

public:
    Lote();
    Lote(string nombreCliente, int idCliente, double precioLote, char estadoOcupacion, string identificadorLote, int cantRepisasLote, string categoriaRiego, string servicio, double precioServicio, double precioRiego, double iva, double precioTotal);

    // Setters
    void setNombreCliente(string nombreCliente);
    void setIdCliente(int idCliente);
    void setPrecioLote(double precioLote);
    void setEstadoOcupacion(char estadoOcupacion);
    void setIdentificadorLote(string identificadorLote);
    void setCantRepisasLote(int cantRepisasLote);
    void setCategoriaRiego(string categoriaRiego);
    void setServicio(string servicio);
    void setPrecioServicio(double precioServicio);
    void setPrecioRiego(double precioRiego);
    void setIva(double iva);
    void setPrecioTotal(double precioTotal);
    void setDispo(bool dispo);

    // Getters
    string getNombreCliente();
    int getIdCliente();
    double getPrecioLote();
    char getEstadoOcupacion();
    string getIdentificadorLote();
    int getCantRepisasLote();
    string getCategoriaRiego();
    string getServicio();
    double getPrecioServicio();
    double getPrecioRiego();
    double getIva();
    double getPrecioTotal();
    bool getDispo();

    // Método adicional
    void calcularPrecioTotal();
};

#endif // LOTE_H
