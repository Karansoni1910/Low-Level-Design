// Dependency Inversion Principle: Depend on abstractions, not concrete implementations

interface Database {
    insert(table: string, data: string): void;
    query(table: string, id: string): string;
}

class PostgreSQLDatabase implements Database {
    insert(table: string, data: string): void {
        console.log(`PostgreSQL: Inserting into ${table} -> ${data}`);
    }

    query(table: string, id: string): string {
        console.log(`PostgreSQL: Querying ${table} for id ${id}`);
        return `{ id: ${id}, item: 'Widget' }`;
    }
}

class MySQLDatabase implements Database {
    insert(table: string, data: string): void {
        console.log(`MySQL: Inserting into ${table} -> ${data}`);
    }

    query(table: string, id: string): string {
        console.log(`MySQL: Querying ${table} for id ${id}`);
        return `{ id: ${id}, item: 'Widget' }`;
    }
}

class OrderService {
    private database: Database;

    constructor(database: Database) {
        this.database = database;
    }

    placeOrder(orderId: string, orderData: string): void {
        console.log(`Placing order: ${orderId}`);
        this.database.insert("orders", orderData);
        console.log("Order placed successfully.");
    }

    getOrder(orderId: string): string {
        return this.database.query("orders", orderId);
    }
}

// Usage
console.log("--- MySQL ---");
const mySqlService = new OrderService(new MySQLDatabase());
mySqlService.placeOrder("ORD-001", "{ item: 'Widget', qty: 3 }");
const morder = mySqlService.getOrder("ORD-001");
console.log("Order: " + morder);

console.log();

console.log("--- PostgreSQL ---");
const postgreSqlService = new OrderService(new PostgreSQLDatabase());
postgreSqlService.placeOrder("ORD-001", "{ item: 'Widget', qty: 3 }");
const porder = postgreSqlService.getOrder("ORD-001");
console.log("Order: " + porder);
