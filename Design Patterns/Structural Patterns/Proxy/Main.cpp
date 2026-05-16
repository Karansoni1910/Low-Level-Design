#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// Proxy Pattern

class ApiService {
public:
    virtual ~ApiService() = default;
    virtual string request(const string& endpoint) = 0;
};

class RealApiService : public ApiService {
public:
    string request(const string& endpoint) override {
        return "Response from " + endpoint;
    }
};

class RateLimitingProxy : public ApiService {
private:
    ApiService* apiService;
    vector<long> timestamps;
    const int MAX_REQUESTS = 3;
    const long TIME_WINDOW_MS = 10000;

public:
    RateLimitingProxy(ApiService* service) : apiService(service) {}

    string request(const string& endpoint) override {
        long curTime = chrono::duration_cast<chrono::milliseconds>(
            chrono::system_clock::now().time_since_epoch()).count();

        // Remove timestamps older than TIME_WINDOW_MS
        timestamps.erase(
            remove_if(timestamps.begin(), timestamps.end(),
                     [curTime, this](long t) { return curTime - t > TIME_WINDOW_MS; }),
            timestamps.end()
        );

        if (timestamps.size() >= MAX_REQUESTS) {
            return "Rate limit exceeded. Try again later.";
        }

        timestamps.push_back(curTime);
        return apiService->request(endpoint);
    }
};

int main() {
    RealApiService realService;
    RateLimitingProxy api(&realService);

    cout << api.request("/users") << endl;
    cout << api.request("/orders") << endl;
    cout << api.request("/products") << endl;
    cout << api.request("/inventory") << endl;  // Should be rejected

    return 0;
}
