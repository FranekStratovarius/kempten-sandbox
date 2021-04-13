#include "ViewPortGL.h"

class BinaryVisuals{
	public:
		/**
			Diese Methode dient zur (Vorbereitung der) Darstellung eines 
			einzigen Bits in einem ViewPort. Dabei soll ein Bit als Rechteck 
			dargestellt werden, das genau dann ausgefüllt wird, wenn es auf 
			1 gesetzt ist (wird durch Parameter isOne übergeben). Die Methode 
			zeichnet das Rechteck so, dass sein linkes, oberes Eck genau auf 
			den Koordinaten (xk, yk) liegt. Die Darstellung soll die Breite 
			width und die Höhe height besitzen.
		*/
		static void prepareBit(ViewPortGL& vp, int xk, int yk, int width, int height, bool isOne);

		/**
			Diese Methode dient dazu, einen Wert des Datentyps unsigned char 
			darzustellen. Die Bits des Wertes sollen waagerecht nebeneinander 
			angezeigt werden. Das niedrigwertigste Bits sitzt dabei ganz rechts, 
			das höchstwertigste ganz links. Die Position und Größe der 
			Darstellung wird (im selben Sinn wie in der Bit-Aufgabe) durch die 
			Parameter xk, yk, width, height vorgegeben.
		*/
		static void prepareRepresentation(ViewPortGL& vp, unsigned char value, int xk, int yk, int width, int height);

		/**
			Diese Methode soll analog zur obigen arbeiten, nun aber Werte vom 
			Typ unsigned int anzeigen. Benutzen Sie zu ihrer Umsetzung die 
			Methode für unsigned chars! Benutzen Sie entsprechende Bitoperationen, 
			um die chars aus dem int herauszufiltern.
		*/
		static void prepareRepresentation(ViewPortGL& vp, unsigned int value, int xk, int yk, int width, int height);
};
