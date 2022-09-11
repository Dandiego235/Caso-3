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
            Node<Flight> *flightPtr = pFlights->getFirst();
            Flight *flight;

            flightQuantity = pFlights->size();

            int runwayNum = 0;
            PriorityQueue<Flight> *runway;
            while (flightPtr != nullptr){
                runway = &runways[runwayNum];
                flight = flightPtr->structure;

                runway->enqueue(flight->getIntTimeValue(), flight);

                runwayNum++;
                flightPtr = flightPtr->getNext();
                if (runwayNum == runwayQuantity){
                    runwayNum = 0;
                }
            }
        }

        void departures(){
            Flight *flightTakeOff = runways[0].front();
            Flight *flightCheck;
            while (flightQuantity != 0){
                flightTakeOff = runways[0].front();
                int runwayNum = 0;
                while (flightTakeOff == nullptr){
                    flightTakeOff = runways[++runwayNum].front();
                }
                for (int counter = 1; counter < runwayQuantity; counter++){
                    flightCheck = runways[counter].front();
                    if (flightCheck == nullptr) {
                        continue;
                    }
                    if (flightCheck->getIntTimeValue() < flightTakeOff->getIntTimeValue()){
                        flightTakeOff = flightCheck;
                        runwayNum = counter;
                    }
                }
                cout << "El vuelo " << flightTakeOff->getNumFlight() << " de " << flightTakeOff->getAirline() << " despegó de la pista " << runwayNum + 1 << " a las " << flightTakeOff->flightTimeString() << endl;
                runways[runwayNum].dequeue();
                flightQuantity--;
            }
        }

};

#endif