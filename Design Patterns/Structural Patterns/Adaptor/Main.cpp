#include <iostream>
#include <iomanip>
using namespace std;

// Adapter Pattern

class Thermometer {
public:
    virtual ~Thermometer() = default;
    virtual double getTemperature() const = 0;
};

class CelsiusSensor : public Thermometer {
public:
    double getTemperature() const override {
        return 25.0;
    }
};

class FahrenheitSensor {
public:
    double readFahrenheit() const {
        return 98.6;
    }
};

class FahrenheitSensorAdapter : public Thermometer {
private:
    FahrenheitSensor* sensor;

public:
    FahrenheitSensorAdapter(FahrenheitSensor* sensor) : sensor(sensor) {}

    double getTemperature() const override {
        double fahrenheit = sensor->readFahrenheit();
        return (fahrenheit - 32) * 5.0 / 9.0;
    }
};

int main() {
    CelsiusSensor celsius;
    cout << fixed << setprecision(1);
    cout << "Celsius sensor: " << celsius.getTemperature() << " C" << endl;

    FahrenheitSensor fSensor;
    FahrenheitSensorAdapter adapted(&fSensor);
    cout << "Fahrenheit sensor (adapted): " << adapted.getTemperature() << " C" << endl;

    return 0;
}
