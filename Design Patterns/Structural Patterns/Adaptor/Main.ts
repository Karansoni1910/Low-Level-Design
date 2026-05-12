interface Thermometer {
    getTemperature(): number; // Returns Celsius
}

class CelsiusSensor implements Thermometer {
    getTemperature(): number {
        return 25.0; // Simulated reading
    }
}

class FahrenheitSensor {
    readFahrenheit(): number {
        return 98.6; // Simulated reading
    }
}

class FahrenheitSensorAdapter implements Thermometer {
    private fahrenheitSensor: FahrenheitSensor;

    constructor(sensor: FahrenheitSensor) {
        this.fahrenheitSensor = sensor;
    }

    getTemperature(): number {
        const fahrenheit = this.fahrenheitSensor.readFahrenheit();
        return (fahrenheit - 32) * (5.0 / 9.0);
    }
}

// Usage
const celsius = new CelsiusSensor();
console.log(`Celsius sensor: ${celsius.getTemperature().toFixed(1)} C`);

const sensor = new FahrenheitSensor();
const adapted = new FahrenheitSensorAdapter(sensor);
console.log(`Fahrenheit sensor (adapted): ${adapted.getTemperature().toFixed(1)} C`);
