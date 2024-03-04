#include "persona.h"
#include <iostream>
#include "persona.h"

using namespace std;

//constructor que vimos en la materia


CPersona::CPersona(string nom, string dir, long long tel)
{
    asignarNombre(nom);
    asignarDireccion(dir);
    asignarTelefono(tel);
}

void CPersona::asignarNombre(const string& nom)
{
    nombre = nom;
}

string CPersona::obtenerNombre() const
{
    return nombre;
}

void CPersona::asignarDireccion(const string& dir)
{
    direccion = dir;
}

string CPersona::obtenerDireccion() const
{
    return direccion;
}

void CPersona::asignarTelefono(long long tel)
{
    telefono = tel;
}

long long CPersona::obtenerTelefono() const
{
    return telefono;
}

