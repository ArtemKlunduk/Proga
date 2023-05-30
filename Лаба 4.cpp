#include <iostream>
#include <string>

using namespace std;

class Automobile {
protected:
    string model;
    int maxSpeed;

public:
    Automobile(const string& _model, int _maxSpeed) : model(_model), maxSpeed(_maxSpeed) {}

    virtual void printParameters() {
        cout << "Model: " << model << endl;
        cout << "Max Speed: " << maxSpeed << " km/h" << endl;
    }
};

class Bus : public Automobile {
private:
    int maxPassengers;

public:
    Bus(const string& _model, int _maxSpeed, int _maxPassengers)
        : Automobile(_model, _maxSpeed), maxPassengers(_maxPassengers) {}

    void printParameters() override {
        Automobile::printParameters();
        cout << "Max Passengers: " << maxPassengers << endl;
    }
};

int main() {
    Automobile car("Sedan", 200);
    Bus bus("City Bus", 120, 50);

    cout << "Car Parameters: " << endl;
    car.printParameters();

    cout << "\nBus Parameters: " << endl;
    bus.printParameters();

    return 0;
}