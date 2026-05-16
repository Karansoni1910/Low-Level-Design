#include <iostream>
#include <string>
using namespace std;

enum class TrafficLight {
    RED,
    YELLOW,
    GREEN
};

class TrafficLightManager {
private:
    TrafficLight current;

    string getName(TrafficLight light) const {
        switch (light) {
            case TrafficLight::RED:    return "RED";
            case TrafficLight::YELLOW: return "YELLOW";
            case TrafficLight::GREEN:  return "GREEN";
            default:                   return "UNKNOWN";
        }
    }

    int getDuration(TrafficLight light) const {
        switch (light) {
            case TrafficLight::RED:    return 30;
            case TrafficLight::YELLOW: return 5;
            case TrafficLight::GREEN:  return 25;
            default:                   return 0;
        }
    }

public:
    TrafficLightManager() : current(TrafficLight::RED) {}

    void display() const {
        cout << getName(current) << " (" << getDuration(current) << "s)" << endl;
    }

    void next() {
        switch (current) {
            case TrafficLight::RED:
                current = TrafficLight::GREEN;
                break;
            case TrafficLight::GREEN:
                current = TrafficLight::YELLOW;
                break;
            case TrafficLight::YELLOW:
                current = TrafficLight::RED;
                break;
        }
    }
};

int main() {
    TrafficLightManager light;
    for (int i = 0; i < 6; i++) {
        light.display();
        light.next();
    }
    return 0;
}
