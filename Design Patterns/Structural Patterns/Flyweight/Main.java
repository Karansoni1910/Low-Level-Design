import java.util.HashMap;
import java.util.Map;

interface FontStyle {
    void format(int line, int column, char character);
}

class ConcreteFontStyle implements FontStyle {
    // TODO: Add fields (fontFamily, fontSize, bold, italic)
    private String fontFamily;
    private int fontSize;
    private boolean bold;
    private boolean italic;

    public ConcreteFontStyle(String fontFamily, int fontSize, boolean bold, boolean italic) {
        // TODO: Store fontFamily, fontSize, bold, italic
        this.fontFamily = fontFamily;
        this.fontSize = fontSize;
        this.bold = bold;
        this.italic = italic;
    }

    @Override
    public void format(int line, int column, char character) {
        // TODO: Print "[fontFamily, fontSize, style] 'character' at line:column"
        // where style is "bold" if bold, "italic" if italic, otherwise "normal"
        // Example: "[Arial, 12, normal] 'H' at 1:1"
        String style = bold ? "bold" : italic ? "italic" : "normal"; 
        System.out.println("[" + this.fontFamily + ", " + this.fontSize + ", " + style + "] '" + character + "' at " + line + ":"+ column);
    }
}

class FontStyleFactory {
    // TODO: Add a Map<String, FontStyle> cache field
    private Map<String, FontStyle> cache = new HashMap<>();

    public FontStyle getFontStyle(String fontFamily, int fontSize, boolean bold, boolean italic) {
        // TODO: Build key from fontFamily + fontSize + bold + italic
        // TODO: If key exists in cache, return cached instance
        // TODO: Otherwise create new ConcreteFontStyle, store in cache, return it
        String key = fontFamily + fontSize + bold + italic;
        if(cache.containsKey(key)) return cache.get(key);
        FontStyle fontStyle = new ConcreteFontStyle(fontFamily, fontSize, bold, italic);
        cache.put(key, fontStyle);
        return cache.get(key);
    }

    public int getStyleCount() {
        // TODO: Return the number of cached styles
        return cache.size();
    }
}

public class Main {
    public static void main(String[] args) {
        FontStyleFactory factory = new FontStyleFactory();
        FontStyle arial12 = factory.getFontStyle("Arial", 12, false, false);
        FontStyle arial12Bold = factory.getFontStyle("Arial", 12, true, false);
        FontStyle arial12Again = factory.getFontStyle("Arial", 12, false, false);
        
        arial12.format(1, 1, 'H');
        arial12Bold.format(1, 2, 'e');
        arial12Again.format(1, 3, 'l');
        
        System.out.println("Same instance? " + (arial12 == arial12Again));
        System.out.println("Total styles: " + factory.getStyleCount());
    }
}