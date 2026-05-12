interface ApiService {
    request(endpoint: string): string;
}

class RealApiService implements ApiService {
    request(endpoint: string): string {
        return "Response from " + endpoint;
    }
}

class RateLimitingProxy implements ApiService {
    private apiService: ApiService;
    private timestamps: number[] = [];
    private readonly MAX_REQUESTS: number = 3;
    private readonly TIME_WINDOW_MS: number = 10000;

    constructor(service: ApiService) {
        this.apiService = service;
    }

    request(endpoint: string): string {
        const curTime = Date.now();
        
        // Remove timestamps older than TIME_WINDOW_MS
        this.timestamps = this.timestamps.filter((t) => curTime - t <= this.TIME_WINDOW_MS);

        if (this.timestamps.length >= this.MAX_REQUESTS) {
            return "Rate limit exceeded. Try again later.";
        }

        this.timestamps.push(curTime);
        return this.apiService.request(endpoint);
    }
}

// Usage
const api: ApiService = new RateLimitingProxy(new RealApiService());

console.log(api.request("/users"));
console.log(api.request("/orders"));
console.log(api.request("/products"));
console.log(api.request("/inventory")); // Should be rejected

// After waiting 10 seconds, requests should work again
