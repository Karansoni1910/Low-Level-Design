import java.util.HashMap;
import java.util.Map;

class ShoppingCart {
    private Map<String, Double> items = new HashMap<>();
    private boolean discountApplied = false;
    private boolean isCheckedOut = false;

    public void addItem(String name, double price) {
        // Add item to cart, but reject if already checked out
        if(!isCheckedOut){
            items.put(name, price);
        }
        else{
            System.out.println("Cannot modify a checked-out cart");
        }
    }

    public boolean applyDiscount(String code) {
        // If code is "SAVE10" and no discount applied yet and not checked out,
        // mark discount as applied and return true. Otherwise return false.
        if(!discountApplied && code == "SAVE10"){
            return discountApplied = true;
        }
        return false;
    }

    public double getTotal() {
        // Sum all item prices. If discount was applied, subtract 10%.
        double total = items.values().stream()
            .mapToDouble(Double::doubleValue)
            .sum();

        if(discountApplied){
            total -= total/10;
        }
        return  Math.round(total * 100.0) / 100.0;
    }

    public void checkout() {
        // Mark cart as checked out (only if it has items and isn't already checked out)
        if(!items.isEmpty() && !isCheckedOut){
            isCheckedOut = true;
        }
    }
}

// Test your implementation
public class Main {
    public static void main(String[] args) {
        ShoppingCart cart = new ShoppingCart();
        cart.addItem("Laptop", 999.99);
        cart.addItem("Mouse", 29.99);

        System.out.println("Total: $" + cart.getTotal());            // 1029.98

        System.out.println("Discount: " + cart.applyDiscount("SAVE10")); // true
        System.out.println("Total: $" + cart.getTotal());            // 926.98

        System.out.println("Discount: " + cart.applyDiscount("SAVE10")); // false (already applied)

        cart.checkout();
        cart.addItem("Keyboard", 79.99);  // Should be rejected
        System.out.println("Total: $" + cart.getTotal());            // 926.98 (unchanged)
    }
}