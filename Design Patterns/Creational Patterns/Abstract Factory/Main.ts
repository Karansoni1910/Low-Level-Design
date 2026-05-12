interface ThemeColor {
    apply(): void;
}

interface ThemeFont {
    render(): void;
}

class LightColor implements ThemeColor {
    apply(): void {
        console.log("Applying light color: #FFFFFF background, #000000 text");
    }
}

class DarkColor implements ThemeColor {
    apply(): void {
        console.log("Applying dark color: #1E1E1E background, #FFFFFF text");
    }
}

class LightFont implements ThemeFont {
    render(): void {
        console.log("Rendering light theme font: Arial, 14px");
    }
}

class DarkFont implements ThemeFont {
    render(): void {
        console.log("Rendering dark theme font: Consolas, 14px");
    }
}

interface ThemeFactory {
    createColor(): ThemeColor;
    createFont(): ThemeFont;
}

class LightThemeFactory implements ThemeFactory {
    createColor(): ThemeColor {
        return new LightColor();
    }

    createFont(): ThemeFont {
        return new LightFont();
    }
}

class DarkThemeFactory implements ThemeFactory {
    createColor(): ThemeColor {
        return new DarkColor();
    }

    createFont(): ThemeFont {
        return new DarkFont();
    }
}

class ThemeClient {
    private color: ThemeColor;
    private font: ThemeFont;

    constructor(factory: ThemeFactory) {
        this.color = factory.createColor();
        this.font = factory.createFont();
    }

    applyTheme(): void {
        this.color.apply();
        this.font.render();
    }
}

// Usage
console.log("=== Light Theme ===");
const lightClient = new ThemeClient(new LightThemeFactory());
lightClient.applyTheme();

console.log();

console.log("=== Dark Theme ===");
const darkClient = new ThemeClient(new DarkThemeFactory());
darkClient.applyTheme();
