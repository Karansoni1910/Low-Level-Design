// Classes and Objects: Blueprint and instances

class BankAccount {
    private accountNumber: string;
    private ownerName: string;
    private balance: number;

    constructor(accountNumber: string, ownerName: string) {
        this.accountNumber = accountNumber;
        this.ownerName = ownerName;
        this.balance = 0;
    }

    deposit(amount: number): void {
        if (amount > 0) {
            this.balance += amount;
        }
    }

    withdraw(amount: number): boolean {
        if (amount <= this.balance) {
            this.balance -= amount;
            return true;
        }
        return false;
    }

    getBalance(): number {
        return this.balance;
    }

    getAccountNumber(): string {
        return this.accountNumber;
    }

    getOwnerName(): string {
        return this.ownerName;
    }
}

// Usage
const account = new BankAccount("123456", "John Doe");
account.deposit(1000);
console.log(account.getBalance());  // 1000

const success = account.withdraw(500);
console.log(success);               // true
console.log(account.getBalance());  // 500

const failed = account.withdraw(1000);
console.log(failed);                // false
