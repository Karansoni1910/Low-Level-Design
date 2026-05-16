#include <iostream>
using namespace std;

// Facade Pattern

class SmartLightsSystem {
public:
    void on() {
        cout << "Lights: Turned on." << endl;
    }

    void off() {
        cout << "Lights: Turned off." << endl;
    }
};

class Thermostat {
private:
    string mode;

public:
    void setTemperature(int degrees) {
        cout << "Thermostat: Mode set to " << mode << ". Temperature set to " << degrees << "C." << endl;
    }

    void setMode(const string& m) {
        mode = m;
    }
};

class SecuritySystem {
public:
    void arm() {
        cout << "Security: System armed." << endl;
    }

    void disarm() {
        cout << "Security: System disarmed." << endl;
    }
};

class SmartHomeFacade {
private:
    SmartLightsSystem* lights;
    Thermostat* thermostat;
    SecuritySystem* security;

public:
    SmartHomeFacade(SmartLightsSystem* lights, Thermostat* thermostat, SecuritySystem* security)
        : lights(lights), thermostat(thermostat), security(security) {}

    void leaveHome() {
        cout << "--- Leaving Home ---" << endl;
        lights->off();
        thermostat->setMode("eco");
        thermostat->setTemperature(18);
        security->arm();
        cout << "--- Home secured ---" << endl;
    }

    void arriveHome() {
        cout << "--- Arriving Home ---" << endl;
        lights->on();
        thermostat->setMode("comfort");
        thermostat->setTemperature(22);
        security->disarm();
        cout << "--- Welcome Home! ---" << endl;
    }
};

int main() {
    SmartLightsSystem lights;
    Thermostat thermostat;
    SecuritySystem security;

    SmartHomeFacade home(&lights, &thermostat, &security);
    home.leaveHome();
    cout << endl;
    home.arriveHome();

    return 0;
}
