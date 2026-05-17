import java.util.*;

interface WeatherObserver {
    void update(WeatherStation station);
}

class WeatherStation {
    private double temperature;
    private double humidity;
    private double pressure;
    private List<WeatherObserver> observers = new ArrayList<>();

    public void registerObserver(WeatherObserver observer) {
        // TODO: Add observer to the list
        this.observers.add(observer);
    }

    public void removeObserver(WeatherObserver observer) {
        // TODO: Remove observer from the list
        this.observers.remove(observer);
    }

    private void notifyObservers() {
        // TODO: Call update on each observer, passing this station
        for(WeatherObserver observer: observers) {
            observer.update(this);
        }
    }

    public void setMeasurements(double temperature, double humidity, double pressure) {
        // TODO: Update fields and notify observers
        this.temperature = temperature;
        this.humidity = humidity;
        this.pressure = pressure;
        notifyObservers();
    }

    public double getTemperature() { return temperature; }
    public double getHumidity() { return humidity; }
    public double getPressure() { return pressure; }
}

class CurrentConditionsDisplay implements WeatherObserver {
    @Override
    public void update(WeatherStation station) {
        // TODO: Print "Current Conditions -> Temp: X, Humidity: Y%, Pressure: Z hPa"
        System.out.println("Current Conditions -> Temp: " + station.getTemperature() + ", Humidity: " + station.getHumidity() + "%, Pressure: " + station.getPressure() + " hPa");
    }
}

class StatisticsDisplay implements WeatherObserver {
    private List<Double> readings = new ArrayList<>();

    @Override
    public void update(WeatherStation station) {
        // TODO: Add temperature to readings, compute average, print "Statistics -> Avg Temperature: X"
        this.readings.add(station.getTemperature());
        Double total = 0.0;
        for(Double reading : readings) {
            total += reading;
        }
        Double average = total / readings.size();
        System.out.println("Statistics -> Avg Temperature: " + average);
    }
}

public class Main {
    public static void main(String[] args) {
        WeatherStation station = new WeatherStation();
        CurrentConditionsDisplay current = new CurrentConditionsDisplay();
        StatisticsDisplay stats = new StatisticsDisplay();
        station.registerObserver(current);
        station.registerObserver(stats);
        station.setMeasurements(25.0, 65.0, 1013.0);
        station.setMeasurements(28.0, 70.0, 1012.0);
        station.setMeasurements(22.0, 90.0, 1011.0);
    }
}