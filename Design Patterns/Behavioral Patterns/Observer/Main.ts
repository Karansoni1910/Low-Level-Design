// Observer interface
interface WeatherObserver {
    update(station: WeatherStation): void;
}

// Subject: WeatherStation
class WeatherStation {
    private temperature: number = 0;
    private humidity: number = 0;
    private pressure: number = 0;
    private observers: WeatherObserver[] = [];

    registerObserver(observer: WeatherObserver): void {
        this.observers.push(observer);
    }

    removeObserver(observer: WeatherObserver): void {
        const index = this.observers.indexOf(observer);
        if (index > -1) {
            this.observers.splice(index, 1);
        }
    }

    private notifyObservers(): void {
        for (const observer of this.observers) {
            observer.update(this);
        }
    }

    setMeasurements(temperature: number, humidity: number, pressure: number): void {
        this.temperature = temperature;
        this.humidity = humidity;
        this.pressure = pressure;
        this.notifyObservers();
    }

    getTemperature(): number {
        return this.temperature;
    }

    getHumidity(): number {
        return this.humidity;
    }

    getPressure(): number {
        return this.pressure;
    }
}

// Concrete Observer 1: CurrentConditionsDisplay
class CurrentConditionsDisplay implements WeatherObserver {
    update(station: WeatherStation): void {
        console.log(
            `Current Conditions -> Temp: ${station.getTemperature()}, ` +
            `Humidity: ${station.getHumidity()}%, Pressure: ${station.getPressure()} hPa`
        );
    }
}

// Concrete Observer 2: StatisticsDisplay
class StatisticsDisplay implements WeatherObserver {
    private readings: number[] = [];

    update(station: WeatherStation): void {
        this.readings.push(station.getTemperature());

        const total = this.readings.reduce((sum, reading) => sum + reading, 0);
        const average = total / this.readings.length;

        console.log(`Statistics -> Avg Temperature: ${average.toFixed(2)}`);
    }
}

// Main execution
const station = new WeatherStation();
const current = new CurrentConditionsDisplay();
const stats = new StatisticsDisplay();

station.registerObserver(current);
station.registerObserver(stats);

station.setMeasurements(25.0, 65.0, 1013.0);
station.setMeasurements(28.0, 70.0, 1012.0);
station.setMeasurements(22.0, 90.0, 1011.0);
