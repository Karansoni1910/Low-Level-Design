#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;

// Forward declaration
class WeatherStation;

// Observer interface
class WeatherObserver {
public:
    virtual ~WeatherObserver() = default;
    virtual void update(WeatherStation* station) = 0;
};

// Subject: WeatherStation
class WeatherStation {
private:
    double temperature;
    double humidity;
    double pressure;
    vector<shared_ptr<WeatherObserver>> observers;

public:
    WeatherStation() : temperature(0), humidity(0), pressure(0) {}

    void registerObserver(shared_ptr<WeatherObserver> observer) {
        observers.push_back(observer);
    }

    void removeObserver(shared_ptr<WeatherObserver> observer) {
        auto it = find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

private:
    void notifyObservers() {
        for (auto observer : observers) {
            observer->update(this);
        }
    }

public:
    void setMeasurements(double temp, double hum, double press) {
        temperature = temp;
        humidity = hum;
        pressure = press;
        notifyObservers();
    }

    double getTemperature() const { return temperature; }
    double getHumidity() const { return humidity; }
    double getPressure() const { return pressure; }
};

// Concrete Observer 1: CurrentConditionsDisplay
class CurrentConditionsDisplay : public WeatherObserver {
public:
    void update(WeatherStation* station) override {
        cout << "Current Conditions -> Temp: " << station->getTemperature()
             << ", Humidity: " << station->getHumidity() << "%, Pressure: "
             << station->getPressure() << " hPa" << endl;
    }
};

// Concrete Observer 2: StatisticsDisplay
class StatisticsDisplay : public WeatherObserver {
private:
    vector<double> readings;

public:
    void update(WeatherStation* station) override {
        readings.push_back(station->getTemperature());
        
        double total = 0.0;
        for (double reading : readings) {
            total += reading;
        }
        double average = total / readings.size();
        
        cout << "Statistics -> Avg Temperature: " << fixed << setprecision(2) << average << endl;
    }
};

int main() {
    auto station = make_shared<WeatherStation>();
    auto current = make_shared<CurrentConditionsDisplay>();
    auto stats = make_shared<StatisticsDisplay>();

    station->registerObserver(current);
    station->registerObserver(stats);

    station->setMeasurements(25.0, 65.0, 1013.0);
    station->setMeasurements(28.0, 70.0, 1012.0);
    station->setMeasurements(22.0, 90.0, 1011.0);

    return 0;
}
