// KISS Principle: Keep It Simple, Stupid
// Simple implementation without over-engineering

class DisplayNameFormatter {
    formatDisplayName(name: string): string {
        return name.trim().charAt(0).toUpperCase() + name.trim().slice(1);
    }
}

// Usage
const formatter = new DisplayNameFormatter();
console.log(formatter.formatDisplayName("  john doe  "));
console.log(formatter.formatDisplayName("ALICE"));
console.log(formatter.formatDisplayName("  bob  "));
