// Realization: Interface implementation
// Plugin interface is realized by concrete plugin implementations

interface Plugin {
    execute(text: string): string;
    getName(): string;
}

class SpellCheckPlugin implements Plugin {
    execute(text: string): string {
        const words = text.split(/\s+/);
        return words
            .map(word => {
                if (word === "teh") return "the";
                if (word === "adn") return "and";
                return word;
            })
            .join(" ");
    }

    getName(): string {
        return "Spell Check";
    }
}

class WordCountPlugin implements Plugin {
    execute(text: string): string {
        const words = text.split(/\s+/);
        return text + `\n[Word count: ${words.length}]`;
    }

    getName(): string {
        return "Word Count";
    }
}

class UpperCasePlugin implements Plugin {
    execute(text: string): string {
        return text.toUpperCase();
    }

    getName(): string {
        return "Upper Case";
    }
}

class TextEditor {
    private plugins: Plugin[] = [];

    addPlugin(plugin: Plugin): void {
        this.plugins.push(plugin);
    }

    applyPlugin(pluginName: string, text: string): string | null {
        for (const plugin of this.plugins) {
            if (plugin.getName() === pluginName) {
                return plugin.execute(text);
            }
        }
        return null;
    }

    listPlugins(): void {
        console.log("Available plugins:");
        this.plugins.forEach(p => console.log(`  - ${p.getName()}`));
    }
}

// Usage
const editor = new TextEditor();

editor.addPlugin(new SpellCheckPlugin());
editor.addPlugin(new WordCountPlugin());
editor.addPlugin(new UpperCasePlugin());

editor.listPlugins();

console.log("\nOriginal text: 'teh quick brown fox adn lazy dog'");

const corrected = editor.applyPlugin("Spell Check", "teh quick brown fox adn lazy dog");
console.log(`After Spell Check: ${corrected}`);

const counted = editor.applyPlugin("Word Count", "hello world");
console.log(`After Word Count:\n${counted}`);

const uppercase = editor.applyPlugin("Upper Case", "hello world");
console.log(`After Upper Case: ${uppercase}`);
