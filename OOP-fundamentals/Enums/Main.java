enum TrafficLight {
    // Define enum constants with duration: RED(30), YELLOW(5), GREEN(25)
    RED(30, GREEN),
    YELLOW(5, RED),
    GREEN(25, YELLOW);

    private final int duration;
    private final TrafficLight next;

    TrafficLight(int duration, TrafficLight next) {
        this.duration = duration;
        this.next = next;
    }

    public int getDuration() {
        return duration;
    }

    public TrafficLight next() {
        // Return next light: RED->GREEN, GREEN->YELLOW, YELLOW->RED
        return this.next;
    }

    public void display() {
        // Print: "COLOR (Xs)" e.g. "RED (30s)"
        System.out.println(this.name() + " (" + duration + "s)");
    }
}

// Test your implementation
public class Main {
    public static void main(String[] args) {
        TrafficLight light = TrafficLight.RED;
        for (int i = 0; i < 6; i++) {
            light.display();  // Should show color and duration
            light = light.next();
        }
    }
}