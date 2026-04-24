// Before: OrderService is tightly coupled to MySQLDatabase
interface Database {
    public void insert(String table, String data);
    public String query(String tablee, String data);
}

class PostgreSQLDatabase implements Database {
    public void insert(String table, String data) {
        System.out.println("PostgreSQL: Inserting into " + table + " -> " + data);
    }

    public String query(String table, String id) {
        System.out.println("PostgreSQL: Querying " + table + " for id " + id);
        return "{ id: " + id + ", item: 'Widget' }";
    }
}

class MySQLDatabase implements Database {
    public void insert(String table, String data) {
        System.out.println("MySQL: Inserting into " + table + " -> " + data);
    }

    public String query(String table, String id) {
        System.out.println("MySQL: Querying " + table + " for id " + id);
        return "{ id: " + id + ", item: 'Widget' }";
    }
}

class OrderService {
    private Database database;

    public OrderService(Database database) {
        this.database = database; // Direct dependency!
    }

    public void placeOrder(String orderId, String orderData) {
        System.out.println("Placing order: " + orderId);
        database.insert("orders", orderData);
        System.out.println("Order placed successfully.");
    }

    public String getOrder(String orderId) {
        return database.query("orders", orderId);
    }
}

// Usage
public class Main {
    public static void main(String[] args) {
        System.out.println("--- MySQL ---");
        OrderService mySqlService = new OrderService(new MySQLDatabase());
        mySqlService.placeOrder("ORD-001", "{ item: 'Widget', qty: 3 }");
        String morder = mySqlService.getOrder("ORD-001");
        System.out.println("Order: " + morder);
        System.out.println();
        System.out.println("--- PostgreSQL ---");
        OrderService postgreSqlService = new OrderService(new PostgreSQLDatabase());
        postgreSqlService.placeOrder("ORD-001", "{ item: 'Widget', qty: 3 }");
        String porder = postgreSqlService.getOrder("ORD-001");
        System.out.println("Order: " + porder);
    }
}

// TODO: Create a Database interface with insert() and query() methods.
// TODO: Make MySQLDatabase implement the interface.
// TODO: Create a PostgresDatabase that prints "PostgreSQL: ..." instead of "MySQL: ...".
// TODO: Refactor OrderService to accept a Database via its constructor.