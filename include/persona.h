#ifndef PERSONA_H
#define PERSONA_H
#include <string>
using namespace std;

class CPersona{
private:
    std::string nombre;
    std::string direccion;
    long long telefono;
public:

    CPersona(string nom="", string dir="", long long tel=0);
    //CPersona(std::string n, long t, std::string d);
    void asignarNombre(const std::string& nom);
    std::string obtenerNombre() const;
    void asignarDireccion(const std::string& dir);
    std::string obtenerDireccion() const;
    void asignarTelefono(long long tel);
    long long obtenerTelefono() const;
};

#endif // PERSONA_H


