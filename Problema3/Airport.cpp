#include "PriorityQueue.cpp"
#include "Flight.cpp"
#include <iostream>
#include <vector>

#ifndef AIRPORT

#define AIRPORT 1

using namespace std;

class Airport{
    private:
        vector<PriorityQueue<Flight>> runways;
        PriorityQueue<Flight> *queuePtr;
        int runwayQuantity;
        int flightQuantity;

    public:
        Airport(int pLaneQuantity){
            runwayQuantity = pLaneQuantity;
            for (int number = 0; number < pLaneQuantity; number++){
                queuePtr = new PriorityQueue<Flight>();
                runways.push_back(*queuePtr);    
            }
        }
        
        void fillRunways(List<Flight> *pFlights){
            Node<Flight> *flightPtr = pFlights->getFirst(); // Obtengo el primer vuelo
            Flight *flight;

            flightQuantity = pFlights->size();

            int runwayNum = 0;
            PriorityQueue<Flight> *runway;
            while (flightPtr != nullptr){
                runway = &runways[runwayNum]; // Obtengo la pista del vector de pistas.
                flight = flightPtr->structure; // Obtengo el vuelo que estoy analizando.

                runway->enqueue(flight->getIntTimeValue(), flight); // meto el vuelo en la pista con su prioridad.

                runwayNum++; // Me corro de pista
                flightPtr = flightPtr->getNext(); // Obtengo el siguiente vuelo.
                if (runwayNum == runwayQuantity){
                    runwayNum = 0; // cuando llego a la última pista, regreso a meter en la primera.
                }
            }
        }

        void departures(){
            Flight *flightTakeOff; // Puntero para el vuelo. 
            Flight *flightCheck; // Puntero para comparar el vuelo con los primeros de las otras colas.

            while (flightQuantity != 0){
                flightTakeOff = runways[0].front(); // Obtengo el primer vuelo de la primera pista.
                int runwayNum = 0;
                while (flightTakeOff == nullptr){ // Si la primer pista está vacía, busco en las otras hasta que encuentre un vuelo.
                    flightTakeOff = runways[++runwayNum].front();
                }

                // Itero por las otras pistas para revisar si hay un vuelo que debe salir antes.
                for (int counter = 1; counter < runwayQuantity; counter++){
                    // counter es el número de pista para sacar el vuelo a revisar. Como empiezo usualmente con el vuelo de la primera pista,
                    // el counter empieza con el vuelo desde la segunda pista.
                    flightCheck = runways[counter].front(); // Obtiene el primer vuelo de la pista de counter.
                    if (flightCheck == nullptr) { // Si la pista counter está vacía, continúa.
                        continue;
                    }
                    if (flightCheck->getIntTimeValue() < flightTakeOff->getIntTimeValue()){
                        // Si el vuelo que reviso tiene una prioridad menor que el vuelo que voy a sacar, lo cambio por el menor.
                        flightTakeOff = flightCheck;
                        runwayNum = counter;
                    }
                }
                cout << "El vuelo " << flightTakeOff->getNumFlight() << " de " << flightTakeOff->getAirline() << " despegó de la pista " 
                << runwayNum + 1 << " a las " << flightTakeOff->flightTimeString() << endl;
                runways[runwayNum].dequeue();
                flightQuantity--;
                // Imprimo el mensaje, saco el vuelo y decremento la cantidad de vuelos.
            }
        }

};

#endif