/*
Design a parking lot using object-oriented principles.

Asked In : Amazon, Apple, Google and many more interviews

Solution: For our purposes right now, we’ll make the following assumptions.
We made these specific assumptions to add a bit of complexity to the problem without
adding too much. If you made different assumptions, that’s totally fine.
1) The parking lot has multiple levels. Each level has multiple rows of spots.
2) The parking lot can park motorcycles, cars, and buses.
3) The parking lot has motorcycle spots, compact spots, and large spots.
4) A motorcycle can park in any spot.
5) A car can park in either a single compact spot or a single large spot.
6) A bus can park in five large spots that are consecutive and within the same row.
It cannot park in small spots.

In the below implementation, we have created an abstract class Vehicle, from which Car,
Bus, and Motorcycle inherit. To handle the different parking spot sizes, we have just
one class ParkingSpot which has a member variable indicating the size.
*/



//vehicles and its inherited classes
enum VehicleSize {Motorcycle, Compact, Large}

class Vehicle {
    type *p_spot = new type[n];
    protected :
    string licensePlate;
    int spotsNeeded;
    VehicleSize size;

    public:
    int getSpotsNeeded()
{
	return spotsNeeded;

}
VehicleSize getSize() {
	return size;
}

/* Park vehicle in this spot (among others,
         potentially) */
void p_spot(ParkingSpot s)
{
	p_spot.
}




};
