class BankAccount {
    protected String ownerName;
    protected String accountNumber;
    protected double balance;

    public BankAccount(String ownerName, String accountNumber, double balance) {
        // TODO: initialize ownerName, accountNumber, and balance
        this.ownerName = ownerName;
        this.accountNumber = accountNumber;
        this.balance = balance;
    }

    public boolean deposit(double amount) {
        // TODO: add amount to balance if amount > 0, return true if successful
        if(amount > 0){
            balance += amount;
            return true;
        }
        return false;
    }

    public boolean withdraw(double amount) {
        // TODO: subtract amount from balance if balance >= amount, return true
        if(amount > 0 && balance >= amount){
            balance -= amount;
            return true;
        }
        return false;
    }

    public void displayAccount() {
        // TODO: print "ownerName (accountNumber) | Balance: $balance"
        // Hint: use String.format("$%.2f", balance) for formatting
        System.out.println(ownerName + " (" + accountNumber +") | Balance: " + String.format("$%.2f", balance));
    }
}

class SavingsAccount extends BankAccount {
    private double interestRate;

    public SavingsAccount(String ownerName, String accountNumber,
                          double balance, double interestRate) {
        super(ownerName, accountNumber, balance);
        // TODO: initialize interestRate
        this.interestRate = interestRate;
    }

    @Override
    public boolean withdraw(double amount) {
        // TODO: only allow if (balance - amount) >= 100 (minimum balance rule)
        if(amount > 0 && balance - amount >= 100){
            balance -= amount;
            return true;
        }
        return false;
    }

    public void applyInterest() {
        // TODO: add (balance * interestRate / 100) to balance
        balance += (balance * interestRate / 100);
    }
}

class CheckingAccount extends BankAccount {
    private double overdraftLimit;

    public CheckingAccount(String ownerName, String accountNumber,
                           double balance, double overdraftLimit) {
        super(ownerName, accountNumber, balance);
        // TODO: initialize overdraftLimit
        this.overdraftLimit = overdraftLimit;
    }

    @Override
    public boolean withdraw(double amount) {
        // TODO: allow if (balance + overdraftLimit) >= amount
        if(amount > 0 && balance + overdraftLimit >= amount){
            balance -= amount;
            return true;
        }
        return false;
    }
}

public class Main {
    public static void main(String[] args) {
        SavingsAccount savings = new SavingsAccount("Alice", "SAV-001", 1000, 2.0);
        savings.displayAccount();
        System.out.println("Withdraw $950: " + savings.withdraw(950));
        savings.applyInterest();
        savings.displayAccount();

        System.out.println();

        CheckingAccount checking = new CheckingAccount("Bob", "CHK-002", 500, 300);
        checking.displayAccount();
        System.out.println("Withdraw $700: " + checking.withdraw(700));
        checking.displayAccount();
    }
}