#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Quiz #6
// 1. Utilizando esta classe agregue los atributos del vuelo: aerolinea, numero de vuelo, cantidad de pasajeros
// 2. Complete el constructor de la clase, de tal forma que se pueda modificar el flightTime para una hora y minutos específicos
// 3. Implementar alguna forma de convertir el time a un número entero de tal forma que entre menor la hora menor el número, eso en getIntTimeValue()
// 4. En el test.cpp, implementar la función fillFlights()
// fecha de entrega: jueves 8 de setiembre antes de las 10pm
// entrega al asistente al correo: kevinqj.2002@gmail.com
// subject: estructuras de datos - quiz #6
// adjuntan el archivo test.cpp y Flight.h

/* Por: Daniel Granados Retana
   Carné: 2022104692
*/
#ifndef FLIGHT

#define FLIGHT 1

class Flight {
    public: 
        Flight(int pHour, int pMinutes, string pAerolinea, int pNumVuelo, int pNumPasajeros) {

            airline = pAerolinea;
            numFlight = pNumVuelo;
            numPassengers = pNumPasajeros;

            flightTime = time(0); // Se obtiene la fecha actual
            tm *currentDay = localtime(&flightTime); // Se crea un objeto tm para poder modificar las horas, minutos y segundos.
            currentDay->tm_hour = pHour; // Se establecen las horas como las recibidas por el constructor.
            currentDay->tm_min = pMinutes; // Se establecen los minutos como los recibidos por el constructor.
            currentDay->tm_sec = 0; // Se establecen los segundos en 0 para 
            flightTime = mktime(currentDay); // Se convierte este valor a un time_t
        }

        char* flightTimeString() {
            char* result = ctime(&flightTime); // Se convierte la hora a un string.
            return result;
        }

        int getIntTimeValue() {
            return flightTime; // Como flightTime es un int que contiene la cantidad de segundos desde el epoch, retornamos
            // la cantidad de segundos. Entre menor sea la hora, menos segundos hay y por lo tanto, menor el número. 
            //Se podría convertir los segundos a minutos para que quede un menor número.
        }

        string getAirline(){
            return airline;
        }

        int getNumFlight(){
            return numFlight;
        }

        int getNumPassengers(){
            return numPassengers;
        }

    private:
        string airline;
        int numFlight;
        int numPassengers;
        time_t flightTime;
};

#endif