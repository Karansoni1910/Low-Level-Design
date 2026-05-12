// Inheritance: Child classes inherit properties and methods from parent

class BankAccount {
    protected ownerName: string;
    protected accountNumber: string;
    protected balance: number;

    constructor(ownerName: string, accountNumber: string, balance: number) {
        this.ownerName = ownerName;
        this.accountNumber = accountNumber;
        this.balance = balance;
    }

    deposit(amount: number): boolean {
        if (amount > 0) {
            this.balance += amount;
            return true;
        }
        return false;
    }

    withdraw(amount: number): boolean {
        if (amount > 0 && this.balance >= amount) {
            this.balance -= amount;
            return true;
        }
        return false;
    }

    displayAccount(): void {
        console.log(
            `${this.ownerName} (${this.accountNumber}) | Balance: $${this.balance.toFixed(2)}`
        );
    }
}

class SavingsAccount extends BankAccount {
    private interestRate: number;

    constructor(
        ownerName: string,
        accountNumber: string,
        balance: number,
        interestRate: number
    ) {
        super(ownerName, accountNumber, balance);
        this.interestRate = interestRate;
    }

    override withdraw(amount: number): boolean {
        // Only allow if balance - amount >= 100 (minimum balance rule)
        if (amount > 0 && this.balance - amount >= 100) {
            this.balance -= amount;
            return true;
        }
        return false;
    }

    applyInterest(): void {
        this.balance += (this.balance * this.interestRate) / 100;
    }
}

class CheckingAccount extends BankAccount {
    private overdraftLimit: number;

    constructor(
        ownerName: string,
        accountNumber: string,
        balance: number,
        overdraftLimit: number
    ) {
        super(ownerName, accountNumber, balance);
        this.overdraftLimit = overdraftLimit;
    }

    override withdraw(amount: number): boolean {
        // Allow if (balance + overdraftLimit) >= amount
        if (amount > 0 && this.balance + this.overdraftLimit >= amount) {
            this.balance -= amount;
            return true;
        }
        return false;
    }
}

// Usage
const savings = new SavingsAccount("Alice", "SAV-001", 1000, 2.0);
savings.displayAccount();
console.log("Withdraw $950: " + savings.withdraw(950));
savings.applyInterest();
savings.displayAccount();

console.log();

const checking = new CheckingAccount("Bob", "CHK-002", 500, 300);
checking.displayAccount();
console.log("Withdraw $700: " + checking.withdraw(700));
checking.displayAccount();
