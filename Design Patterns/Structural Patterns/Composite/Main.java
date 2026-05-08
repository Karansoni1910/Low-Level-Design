import java.util.*;

interface Menu {
    void display(String indent);
    int getItemCount();
}

class MenuItem implements Menu {
    private final String name;
    private final double price;

    public MenuItem(String name, double price) {
        this.name = name;
        this.price = price;
    }

    @Override
    public void display(String indent) {
        System.out.printf("%s%s - $%.2f%n", indent, name, price);
    }

    @Override
    public int getItemCount() { return 1; }
}

class SubMenu implements Menu {
    // TODO: Add a field to store the submenu name (String)
    // TODO: Add a field to store the list of Menu children (List<Menu>)
    private final String name;
    private final List<Menu> children = new ArrayList<>();

    public SubMenu(String name) {
        // TODO: Store the name and initialize the children list
        this.name = name;
    }

    public void addItem(Menu item) {
        // TODO: Add the given item to the children list
        this.children.add(item);
    }

    @Override
    public void display(String indent) {
        // TODO: Print the submenu name with indent + colon
        // TODO: Loop through children, calling child.display() with indent + "  "
        System.out.println(indent + this.name + ":");

        for(Menu m : children){
            m.display(indent + "  ");
        }
    }

    @Override
    public int getItemCount() {
        // TODO: Sum all children's getItemCount()
        int total = 0;
        for(Menu m : children){
            total += m.getItemCount();
        }
        return total;
    }
}

public class Main {
    public static void main(String[] args) {
        MenuItem burger = new MenuItem("Burger", 8.99);
        MenuItem fries = new MenuItem("Fries", 3.99);
        MenuItem cola = new MenuItem("Cola", 1.99);
        MenuItem water = new MenuItem("Water", 0.99);

        SubMenu drinks = new SubMenu("Drinks");
        drinks.addItem(cola);
        drinks.addItem(water);

        SubMenu mainMenu = new SubMenu("Main Menu");
        mainMenu.addItem(burger);
        mainMenu.addItem(fries);
        mainMenu.addItem(drinks);

        mainMenu.display("");
        System.out.println("\nTotal items: " + mainMenu.getItemCount());
    }
}