// Subsystem: Controls smart lights in the house
class SmartLightsSystem {
    public void on() {
        // TODO: Print "Lights: Turned on."
        System.out.println("Lights: Turned on.");
    }

    public void off() {
        // TODO: Print "Lights: Turned off."
        System.out.println("Lights: Turned off.");
    }
}

// Subsystem: Controls the thermostat temperature and mode
class Thermostat {
    private String mode;

    public void setTemperature(int degrees) {
        // TODO: Print "Thermostat: Mode set to {mode}. Temperature set to {degrees}C."
        System.out.println("Thermostat: Mode set to " + mode + ". Temperature set to " + degrees + "C.");
    }

    public void setMode(String mode) {
        // TODO: Store the mode
        this.mode = mode;
    }
}

// Subsystem: Controls the home security system
class SecuritySystem {
    public void arm() {
        // TODO: Print "Security: System armed."
        System.out.println("Security: System armed.");
    }

    public void disarm() {
        // TODO: Print "Security: System disarmed."
        System.out.println("Security: System disarmed.");
    }
}

// Facade: Provides simplified methods to control all smart home subsystems
class SmartHomeFacade {
    private SmartLightsSystem lights;
    private Thermostat thermostat;
    private SecuritySystem security;

    public SmartHomeFacade(SmartLightsSystem lights, Thermostat thermostat, SecuritySystem security) {
        // TODO: Store references to all subsystems
        this.lights = lights;
        this.thermostat = thermostat;
        this.security = security;
    }

    public void leaveHome() {
        // TODO: Print "--- Leaving Home ---"
        // TODO: Turn off lights, set thermostat to eco mode (18C), arm security
        // TODO: Print "--- Home secured ---"
        System.out.println("--- Leaving Home ---");
        lights.off();
        thermostat.setMode("eco");
        thermostat.setTemperature(18);
        security.arm();
        System.out.println("--- Home secured ---");
    }

    public void arriveHome() {
        // TODO: Print "--- Arriving Home ---"
        // TODO: Turn on lights, set thermostat to comfort mode (22C), disarm security
        // TODO: Print "--- Welcome home! ---"
        System.out.println("--- Arriving Home ---");
        lights.on();
        thermostat.setMode("comfort");
        thermostat.setTemperature(22);
        security.disarm();
        System.out.println("--- Welcome Home! ---");
    }
}

public class Main {
    public static void main(String[] args) {
        SmartLightsSystem lights = new SmartLightsSystem();
        Thermostat thermostat = new Thermostat();
        SecuritySystem security = new SecuritySystem();

        SmartHomeFacade home = new SmartHomeFacade(lights, thermostat, security);
        home.leaveHome();
        System.out.println();
        home.arriveHome();
    }
}