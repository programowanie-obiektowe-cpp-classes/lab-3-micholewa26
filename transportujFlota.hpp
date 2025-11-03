#pragma once
#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    if (towar == 0)
        return 0; // nic do przewiezienia ? 0 ¿aglowców

    Stocznia     stocznia{};          // fabryka statków
    unsigned int suma            = 0; // ile ju¿ przewieziono ³¹cznie
    unsigned int liczbaZaglowcow = 0; // ile razy utworzono ¿aglowiec

    while (suma < towar) {
        Statek* s = stocznia(); // 1) tworzymy statek (losowy typ)

        // 2) transport i 3) dodanie do sumy
        suma += s->transportuj();

        // policz tylko ¿aglowce
        if (dynamic_cast< Zaglowiec* >(s) != nullptr)
            ++liczbaZaglowcow;

        delete s; // 4) niszczymy statek
        // 5) warunek pêtli sprawdzany na pocz¹tku (suma < towar)
    }

    return liczbaZaglowcow;
}
