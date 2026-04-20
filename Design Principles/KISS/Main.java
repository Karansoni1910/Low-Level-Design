class DisplayNameFormatter {
    public String formatDisplayName(String name) {
        // Your implementation here
        name = name.trim();
        String s1 = name.substring(0, 1).toUpperCase();
        String nameCapitalized = s1 + name.substring(1);
        return nameCapitalized;
    }
}

// Test
public class Main {
    public static void main(String[] args) {
        DisplayNameFormatter formatter = new DisplayNameFormatter();
        System.out.println(formatter.formatDisplayName("  john doe  "));
        System.out.println(formatter.formatDisplayName("ALICE"));
        System.out.println(formatter.formatDisplayName("  bob  "));
    }
}