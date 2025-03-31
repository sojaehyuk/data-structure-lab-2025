#include "Complex.h"
#include "Car.h"
void main()
{
//	Complex a, b, c;
//	a.read ("A = ");
//	b.read ("B = ");
//	c.add (a, b);
//	a.print ("A = ");
//	b.print ("B = ");
//	c.print ("A+B= ");

	Car myCar(9, "K3",2);
	Car momCar(10, "K5", 1);

	myCar.whereAmI();
	momCar.whereAmI();
	myCar.changeGear(3);
	myCar.display();
}
