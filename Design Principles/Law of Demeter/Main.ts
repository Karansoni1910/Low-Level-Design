// Law of Demeter: Don't talk to strangers
// Use delegation methods instead of deep method chaining

class Address {
    private city: string;

    constructor(city: string) {
        this.city = city;
    }

    getCity(): string {
        return this.city;
    }
}

class Customer {
    private address: Address;

    constructor(address: Address) {
        this.address = address;
    }

    getAddress(): Address {
        return this.address;
    }
}

class CreditCard {
    private last4Digits: string;

    constructor(last4Digits: string) {
        this.last4Digits = last4Digits;
    }

    getLast4Digits(): string {
        return this.last4Digits;
    }
}

class Payment {
    private creditCard: CreditCard;

    constructor(creditCard: CreditCard) {
        this.creditCard = creditCard;
    }

    getCreditCard(): CreditCard {
        return this.creditCard;
    }
}

class Order {
    private customer: Customer;
    private payment: Payment;

    constructor(customer: Customer, payment: Payment) {
        this.customer = customer;
        this.payment = payment;
    }

    // Delegation methods (Law of Demeter)
    getCustomerCity(): string {
        return this.customer.getAddress().getCity();
    }

    getPaymentLast4Digits(): string {
        return this.payment.getCreditCard().getLast4Digits();
    }

    getCustomer(): Customer {
        return this.customer;
    }

    getPayment(): Payment {
        return this.payment;
    }
}

class OrderSummaryPrinter {
    print(order: Order): void {
        // Using delegation methods instead of chaining
        const city = order.getCustomerCity();
        const last4 = order.getPaymentLast4Digits();

        console.log("Ship to: " + city);
        console.log("Paid with card ending in: " + last4);
    }
}

// Usage
const address = new Address("San Francisco");
const customer = new Customer(address);
const card = new CreditCard("4242");
const payment = new Payment(card);
const order = new Order(customer, payment);

const printer = new OrderSummaryPrinter();
printer.print(order);
