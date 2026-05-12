interface FontStyle {
    format(line: number, column: number, character: string): void;
}

class ConcreteFontStyle implements FontStyle {
    private fontFamily: string;
    private fontSize: number;
    private bold: boolean;
    private italic: boolean;

    constructor(fontFamily: string, fontSize: number, bold: boolean, italic: boolean) {
        this.fontFamily = fontFamily;
        this.fontSize = fontSize;
        this.bold = bold;
        this.italic = italic;
    }

    format(line: number, column: number, character: string): void {
        const style = this.bold ? "bold" : this.italic ? "italic" : "normal";
        console.log(`[${this.fontFamily}, ${this.fontSize}, ${style}] '${character}' at ${line}:${column}`);
    }
}

class FontStyleFactory {
    private cache: Map<string, FontStyle> = new Map();

    getFontStyle(fontFamily: string, fontSize: number, bold: boolean, italic: boolean): FontStyle {
        const key = `${fontFamily}${fontSize}${bold}${italic}`;
        
        if (this.cache.has(key)) {
            return this.cache.get(key)!;
        }

        const fontStyle = new ConcreteFontStyle(fontFamily, fontSize, bold, italic);
        this.cache.set(key, fontStyle);
        return fontStyle;
    }

    getStyleCount(): number {
        return this.cache.size;
    }
}

// Main execution
const factory = new FontStyleFactory();
const arial12 = factory.getFontStyle("Arial", 12, false, false);
const arial12Bold = factory.getFontStyle("Arial", 12, true, false);
const arial12Again = factory.getFontStyle("Arial", 12, false, false);

arial12.format(1, 1, "H");
arial12Bold.format(1, 2, "e");
arial12Again.format(1, 3, "l");

console.log(`Same instance? ${arial12 === arial12Again}`);
console.log(`Total styles: ${factory.getStyleCount()}`);
