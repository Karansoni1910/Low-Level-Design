// Enums: Represents a fixed set of constants

enum TrafficLight {
    RED = "RED",
    YELLOW = "YELLOW",
    GREEN = "GREEN",
}

interface TrafficLightInfo {
    color: TrafficLight;
    duration: number;
    next: TrafficLight;
}

class TrafficLightManager {
    private lightInfo: Map<TrafficLight, TrafficLightInfo> = new Map([
        [
            TrafficLight.RED,
            {
                color: TrafficLight.RED,
                duration: 30,
                next: TrafficLight.GREEN,
            },
        ],
        [
            TrafficLight.YELLOW,
            {
                color: TrafficLight.YELLOW,
                duration: 5,
                next: TrafficLight.RED,
            },
        ],
        [
            TrafficLight.GREEN,
            {
                color: TrafficLight.GREEN,
                duration: 25,
                next: TrafficLight.YELLOW,
            },
        ],
    ]);

    getDuration(light: TrafficLight): number {
        return this.lightInfo.get(light)?.duration || 0;
    }

    getNext(light: TrafficLight): TrafficLight {
        return this.lightInfo.get(light)?.next || TrafficLight.RED;
    }

    display(light: TrafficLight): void {
        const info = this.lightInfo.get(light);
        console.log(`${info?.color} (${info?.duration}s)`);
    }
}

// Usage
const manager = new TrafficLightManager();
let light = TrafficLight.RED;

for (let i = 0; i < 6; i++) {
    manager.display(light);
    light = manager.getNext(light);
}
