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
        vector<int> runwayIndexes;
        int runwayQuantity;
        int flightQuantity;

    public:
        Airport(int pLaneQuantity){
            runwayQuantity = pLaneQuantity;
            for (int number = 0; number < pLaneQuantity; number++){
                queuePtr = new PriorityQueue<Flight>();
                runways.push_back(*queuePtr);
                runwayIndexes.push_back(number);
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
                flight = flightPtr->getData(); // Obtengo el vuelo que estoy analizando.
                runway->enqueue(flight->getIntTimeValue(), flight); // meto el vuelo en la pista con su prioridad.
                runwayNum = ++runwayNum % runwayQuantity; // incremento la pista y la mantengo entre el rango
                flightPtr = flightPtr->getNext(); // Obtengo el siguiente vuelo.
            }
        }

        void departures(){
            Flight *flightTakeOff; // Puntero para el vuelo. 
            Flight *flightCheck; // Puntero para comparar el vuelo con los primeros de las otras colas.
            while (flightQuantity != 0){
                flightTakeOff = runways[runwayIndexes[0]].front(); // Obtengo el primer vuelo de la primera pista no vacía.
                int runwayNum = 0;
                // Itero por las otras pistas para revisar si hay un vuelo que debe salir antes.
                for (int counter = 1; counter < runwayIndexes.size(); counter++){
                    // counter es el número de pista para sacar el vuelo a revisar. Como empiezo usualmente con el vuelo de la primera pista no vacía,
                    // el counter empieza con el vuelo desde la segunda pista no vacía.
                    flightCheck = runways[runwayIndexes[counter]].front(); // Obtiene el primer vuelo de la pista de counter.
                    if (flightCheck->getIntTimeValue() < flightTakeOff->getIntTimeValue()){
                        // Si el vuelo que reviso tiene una prioridad menor que el vuelo que voy a sacar, lo cambio por el menor.
                        flightTakeOff = flightCheck;
                        runwayNum = counter;
                    }
                }
                cout << "El vuelo " << flightTakeOff->getNumFlight() << " de " << flightTakeOff->getAirline() << " despegó de la pista " 
                << runwayIndexes[runwayNum] + 1 << " a las " << flightTakeOff->flightTimeString() << endl;

                runways[runwayIndexes[runwayNum]].dequeue();

                if (runways[runwayIndexes[runwayNum]].isEmpty()){ // Si la pista quedó vacía, 
                    runwayIndexes.erase(runwayIndexes.begin() + runwayNum); // borro la pista de la lista de índices, para no tomarla en cuenta.
                }
                flightQuantity--;
                // Imprimo el mensaje, saco el vuelo y decremento la cantidad de vuelos.
            }
        }

};

#endif