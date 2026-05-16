#include <iostream>
#include <string>
#include <memory>
using namespace std;

// Dependency Inversion Principle: Depend on abstractions, not concretions

class Database {
public:
    virtual ~Database() = default;
    virtual void insert(const string& table, const string& data) = 0;
    virtual string query(const string& table, const string& id) = 0;
};

class MySQLDatabase : public Database {
public:
    void insert(const string& table, const string& data) override {
        cout << "MySQL: Inserting into " << table << " -> " << data << endl;
    }

    string query(const string& table, const string& id) override {
        cout << "MySQL: Querying " << table << " for id " << id << endl;
        return "{ id: " + id + ", item: 'Widget' }";
    }
};

class PostgreSQLDatabase : public Database {
public:
    void insert(const string& table, const string& data) override {
        cout << "PostgreSQL: Inserting into " << table << " -> " << data << endl;
    }

    string query(const string& table, const string& id) override {
        cout << "PostgreSQL: Querying " << table << " for id " << id << endl;
        return "{ id: " + id + ", item: 'Widget' }";
    }
};

class OrderService {
private:
    Database* database;

public:
    OrderService(Database* db) : database(db) {}

    void placeOrder(const string& orderId, const string& orderData) {
        cout << "Placing order: " << orderId << endl;
        database->insert("orders", orderData);
        cout << "Order placed successfully." << endl;
    }

    string getOrder(const string& orderId) {
        return database->query("orders", orderId);
    }
};

int main() {
    cout << "--- MySQL ---" << endl;
    MySQLDatabase mySqlDb;
    OrderService mySqlService(&mySqlDb);
    mySqlService.placeOrder("ORD-001", "{ item: 'Widget', qty: 3 }");
    string morder = mySqlService.getOrder("ORD-001");
    cout << "Order: " << morder << endl;

    cout << "\n--- PostgreSQL ---" << endl;
    PostgreSQLDatabase postgreSqlDb;
    OrderService postgreSqlService(&postgreSqlDb);
    postgreSqlService.placeOrder("ORD-001", "{ item: 'Widget', qty: 3 }");
    string porder = postgreSqlService.getOrder("ORD-001");
    cout << "Order: " << porder << endl;

    return 0;
}
