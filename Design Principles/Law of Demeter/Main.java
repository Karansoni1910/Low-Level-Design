class Address {
    private String city;

    public Address(String city) { this.city = city; }

    public String getCity() { return city; }
}

class Customer {
    private Address address;

    public Customer(Address address) { this.address = address; }

    public Address getAddress() { return address; }
}

class CreditCard {
    private String last4Digits;

    public CreditCard(String last4Digits) { this.last4Digits = last4Digits; }

    public String getLast4Digits() { return last4Digits; }
}

class Payment {
    private CreditCard creditCard;

    public Payment(CreditCard creditCard) { this.creditCard = creditCard; }

    public CreditCard getCreditCard() { return creditCard; }
}

class Order {
    private Customer customer;
    private Payment payment;

    public Order(Customer customer, Payment payment) {
        this.customer = customer;
        this.payment = payment;
    }

    // TODO: Add delegation methods
    public String getCustomerCity(){
        return this.customer.getAddress().getCity();
    }

    public String getPaymentLast4Digits(){
        return this.payment.getCreditCard().getLast4Digits();
    }

    public Customer getCustomer() { return customer; }
    public Payment getPayment() { return payment; }
}

class OrderSummaryPrinter {
    public void print(Order order) {
        // CURRENT (violates LoD):
        // String city = order.getCustomer().getAddress().getCity();
        // String last4 = order.getPayment().getCreditCard().getLast4Digits();

        // TODO: Refactor to use delegation methods on Order
        String city = order.getCustomerCity();
        String last4 = order.getPaymentLast4Digits();

        System.out.println("Ship to: " + city);
        System.out.println("Paid with card ending in: " + last4);
    }
}

class Main {
    public static void main(String[] args) {
        Address address = new Address("San Francisco");
        Customer customer = new Customer(address);
        CreditCard card = new CreditCard("4242");
        Payment payment = new Payment(card);
        Order order = new Order(customer, payment);

        OrderSummaryPrinter printer = new OrderSummaryPrinter();
        printer.print(order);
    }
}