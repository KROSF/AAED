#ifndef CRONOMETRO_HPP
#define CRONOMETRO_HPP

#include <ctime>
using std::clock;
using std::clock_t;

const double pps = static_cast<double>(CLOCKS_PER_SEC);

class cronometro {
public:
    cronometro(): activo(false) {}
    void activar() { activo = true; t0 = clock(); }
    void parar() { if (activo) { t1 = clock(); activo = false; } }
    double tiempo() const { return ((activo ? clock() : t1) - t0) / pps; }
private:
    bool activo;	   // Estado de actividad del cronómetro.
    clock_t t0, t1;  // Tiempos inicial y final.
};
#endif
