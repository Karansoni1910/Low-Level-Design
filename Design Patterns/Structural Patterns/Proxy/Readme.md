# 🛡️ Proxy Pattern

**Definition:** The Proxy Pattern is a structural design pattern that provides a surrogate or placeholder for another object to control access to it. The proxy acts as an intermediary, allowing you to add additional functionality (like access control, logging, caching, or lazy initialization) without changing the original object.

---

## 📋 Problem Statement

Implement a **Rate Limiting Proxy** for an API service. The proxy allows a maximum of 3 requests within any 10-second window. Requests beyond the limit are rejected, protecting the service from excessive usage.

**Real-World Example:** API gateways rate limiting requests, lazy loading of expensive resources, access control proxies for database connections, logging and monitoring proxies, or caching proxies for frequently accessed data.

---

## ✅ Requirements

### Subject Interface (ApiService)
- **request(String endpoint)** - Returns a String response

### Real Subject (RealApiService)
- **Implementation:** Returns "Response from [endpoint]"
- **Purpose:** The actual API service that handles requests

### Proxy (RateLimitingProxy)
- **Controls Access:** Allows at most 3 requests per 10-second window
- **Request Throttling:** Tracks requests within time windows
- **Access Denial:** Rejects excess requests with "Rate limit exceeded"
- **Delegation:** Forwards valid requests to the real service

---

## 🎯 Key Features

- **Access Control:** Controls who/what can access the real object
- **Lazy Initialization:** Defers creation of expensive objects until needed
- **Request Throttling:** Implements rate limiting and request queuing
- **Caching:** Stores expensive operation results
- **Logging & Monitoring:** Tracks access patterns and metrics
- **Transparent Operation:** Proxy appears identical to the real object

---

## 💡 Key Concepts Covered

- Providing controlled access to another object
- Implementing access control and validation
- Request throttling and rate limiting
- Lazy initialization patterns
- Maintaining proxy-subject contracts
- Transparent interception of requests

---

## 🎯 Common Use Cases

- **API Rate Limiting:** Preventing abuse by limiting request frequency
- **Database Connection Pooling:** Managing and pooling expensive database connections
- **Lazy Loading:** Deferring expensive object creation until first access
- **Caching Proxies:** Storing and reusing expensive computation results
- **Access Control:** Implementing permission checks before allowing access
- **Logging & Auditing:** Tracking all access to sensitive objects
- **Remote Proxies:** Accessing objects across network boundaries