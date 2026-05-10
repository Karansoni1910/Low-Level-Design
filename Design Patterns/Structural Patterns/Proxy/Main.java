import java.util.*;

interface ApiService {
    String request(String endpoint);
}

class RealApiService implements ApiService {
    @Override
    public String request(String endpoint) {
        return "Response from " + endpoint;
    }
}

class RateLimitingProxy implements ApiService {
    // TODO: Add a field to store the real ApiService reference
    // TODO: Add a List<Long> to store timestamps of recent requests
    // TODO: Add a constant for MAX_REQUESTS (3)
    // TODO: Add a constant for TIME_WINDOW_MS (10000)
    private ApiService apiService;
    private List<Long> timestamps;
    private final int MAX_REQUESTS = 3;
    private final long TIME_WINDOW_MS = 10000;

    public RateLimitingProxy(ApiService service) {
        // TODO: Store the real service reference
        // TODO: Initialize the timestamps list
        this.apiService = service;
        this.timestamps = new ArrayList<>();
        
    }

    @Override
    public String request(String endpoint) {
        // TODO: Get the current time using System.currentTimeMillis()
        // TODO: Remove timestamps older than TIME_WINDOW_MS from the list
        // TODO: If the size of timestamps >= MAX_REQUESTS, return "Rate limit exceeded. Try again later."
        // TODO: Add the current timestamp to the list
        // TODO: Delegate to the real service's request() and return the result
        Long curTime = System.currentTimeMillis();
        this.timestamps.removeIf(t -> (curTime - t> TIME_WINDOW_MS));

        if(this.timestamps.size() >= MAX_REQUESTS){
            return "Rate limit exceeded. Try again later.";
        }

        this.timestamps.add(curTime);
        return this.apiService.request(endpoint);
    }
}

public class Main {
    public static void main(String[] args) {
        ApiService api = new RateLimitingProxy(new RealApiService()); // Replace with RateLimitingProxy

        System.out.println(api.request("/users"));
        System.out.println(api.request("/orders"));
        System.out.println(api.request("/products"));
        System.out.println(api.request("/inventory")); // Should be rejected

        // After waiting 10 seconds, requests should work again
    }
}