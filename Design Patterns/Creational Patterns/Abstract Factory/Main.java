interface ThemeColor {
    void apply();
}

interface ThemeFont {
    void render();
}

class LightColor implements ThemeColor {
    @Override
    public void apply() {
        // TODO: Print "Applying light color: #FFFFFF background, #000000 text"
        System.out.println("Applying light color: #FFFFFF background, #000000 text");
    }
}

class DarkColor implements ThemeColor {
    @Override
    public void apply() {
        // TODO: Print "Applying dark color: #1E1E1E background, #FFFFFF text"
        System.out.println("Applying dark color: #1E1E1E background, #FFFFFF text");
    }
}

class LightFont implements ThemeFont {
    @Override
    public void render() {
        // TODO: Print "Rendering light theme font: Arial, 14px"
        System.out.println("Rendering light theme font: Arial, 14px");
    }
}

class DarkFont implements ThemeFont {
    @Override
    public void render() {
        // TODO: Print "Rendering dark theme font: Consolas, 14px"
        System.out.println("Rendering dark theme font: Consolas, 14px");
    }
}

interface ThemeFactory {
    ThemeColor createColor();
    ThemeFont createFont();
}

class LightThemeFactory implements ThemeFactory {
    @Override
    public ThemeColor createColor() {
        return new LightColor();
    }

    @Override
    public ThemeFont createFont() {
        return new LightFont();
    }
}

class DarkThemeFactory implements ThemeFactory {
    @Override
    public ThemeColor createColor() {
        return new DarkColor();
    }

    @Override
    public ThemeFont createFont() {
        return new DarkFont();
    }
}

class ThemeClient {
    private final ThemeColor color;
    private final ThemeFont font;

    public ThemeClient(ThemeFactory factory) {
        this.color = factory.createColor();
        this.font = factory.createFont();
    }

    public void applyTheme() {
        color.apply();
        font.render();
    }
}

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Light Theme ===");
        ThemeClient lightClient = new ThemeClient(new LightThemeFactory());
        lightClient.applyTheme();

        System.out.println();

        System.out.println("=== Dark Theme ===");
        ThemeClient darkClient = new ThemeClient(new DarkThemeFactory());
        darkClient.applyTheme();
    }
}