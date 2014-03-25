using namespace std;


/**
 * Clase TSPPoint
 * Representa una ciudad en un plano 2D y guarda sus coordenadas cartesianas
 * además de ofrecer cierta funcionalidad;
 */

class TSPPoint {

	private:

		/**
		 * Coordenadas cartesianas de la ciudad en el plano
		 */

		double x, y;

	public:

		/**
		 * Constructor de la clase TSPPoint
		 * @param x: abscisa de la ciudad
		 * @param y: ordenada de la ciudad
		 */

		TSPPoint(double x, double y);

		/**
		 * Calcula la distancia entre dos ciudades
		 * @param other: instancia de la clase TSPPoint que representa la otra ciudad.
		 * @return la distancia a la que se encuentra la otra ciudad.
		 */

		double getDistanceTo(TSPPoint other);
}