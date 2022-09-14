#include "Flight.cpp"
#include "PriorityList.cpp"
#include "Airport.cpp"
#include <random>
#include <ctime>

using namespace std;

#define OFFSET 17
#define MINUTES 60
#define NUM_MAX_PASSENGERS 500
#define NUM_AIRLINES 6
#define RUNWAY_QUANTITY 3

// debe llenar una lista de pCantidad vuelos aleatorios cuya hora y minutos de partida esten entre pStartHour y pEndHour
// tomando en cuenta las restricciones de los minutos de salida segun el ejercicio 3 del caso #3

random_device rd; //Elementos para crear un generador de números aleatorios con una distribución uniforme.
mt19937 gen(rd()); // mersenne twister

// Función que retorna un número entero aleatorio en el rango de [low, high - 1];
// Recibe el límite inferior inclusivo y el límite superior exclusivo.
// Retorna el número aleatorio.
int rand_num(int low, int high){
    uniform_int_distribution<> distrib(low, high - 1); // Generador de números aleatorios.
    return distrib(gen);
}

// Función para llenar los vuelos con valores aleatorios.
// Recibe la cantidad de vuelos, la hora de inicio, la hora de final, un puntero a la lista a llenar y
// un array con los nombres de las aerolíneas.
// Llena la lista dada con la cantidad de vuelos.
void fillFlights(int pCantidad, int pStartHour, int pEndHour, List<Flight> *pListPlanes, string pAirlines[NUM_AIRLINES]) {

    Flight *vuelo; // Puntero a objetos de tipo flight. Se usará para agregar los vuelos a la lista.

    for (int number = 0; number < pCantidad; number++){
        vuelo = new Flight(
            rand_num(pStartHour, pEndHour),
            rand_num(0, MINUTES - OFFSET) + rand_num(0, OFFSET + 1),
            pAirlines[rand_num(0, NUM_AIRLINES)], 
            (number + 1),
            rand_num(0, NUM_MAX_PASSENGERS));
            pListPlanes->add(vuelo);
            // Se crea el vuelo. Se genera un valor aleatorio entre el start hour y el end hour.
            // Para los minutos, se genera un número del 0 a (60 - el atraso (OFFSET)) y se le suma un atraso generado aleatoriamente.
            // Esta resta se hace 
            // Para el número de aerolínea, se genera un índice aleatorio del arreglo para que quede con una aerolínea aleatoria.
            // Para el número del avión, se asigna el número de la iteración que vamos recorriendo + 1.
            // De esta forma, nos aseguramos que no hay aviones con el mismo número.
            // Para la cantidad de pasajeros, se asigna un número aleatorio de la capacidad máxima de pasajeros.
        cout << number + 1 << ". Hora de vuelo: " << vuelo->flightTimeString() << "El entero es: " << vuelo->getIntTimeValue()
        << "\nLa aerolínea del avión es: " << vuelo->getAirline() << "\nEl número del avión es: " << vuelo->getNumFlight() 
        << "\nLa cantidad de pasajeros es: " << vuelo->getNumPassengers() << "\n" << endl;
        // Se imprime la información de cada avión.
    }
} 


int main() {
    Flight vuelo(4, 35, "United", 1, 100); // Se modifica el flightTime a valores específicos.
    cout << vuelo.flightTimeString() << "y el entero es: " << vuelo.getIntTimeValue() << endl;
    
    Flight otroVuelo(14,20, "American", 1234, 200);
    cout << otroVuelo.flightTimeString() << "y el entero es: " << otroVuelo.getIntTimeValue() << "\n" << endl;

    List<Flight> *flights = new List<Flight>(); // Se crea la lista de vuelos

    string airlines[NUM_AIRLINES] = {"United", "American", "Copa", "British", "Jet Blue", "Fly Emirates"};
    // arreglo de las aerolíneas.

    fillFlights(60, 0, 1, flights, airlines); // Las horas están en formato de 24 horas.

    Airport *airport = new Airport(RUNWAY_QUANTITY);
    airport->fillRunways(flights);
    airport->departures();
}