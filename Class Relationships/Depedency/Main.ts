// Dependency: Loose coupling between classes
// FileConverter depends on FileReader, FormatParser, and FileWriter
// But doesn't own them (they're passed as parameters)

class FileReader {
    read(filePath: string): string {
        return "name,age,city";
    }
}

class FormatParser {
    parse(content: string, targetFormat: string): string {
        console.log(`Parsing content to ${targetFormat} format`);
        return `[{"name":"Alice","age":30,"city":"NYC"}]`;
    }
}

class FileWriter {
    write(filePath: string, content: string): void {
        // Simulate writing content to a file
    }
}

class FileConverter {
    convert(
        sourcePath: string,
        targetPath: string,
        targetFormat: string,
        reader: FileReader,
        parser: FormatParser,
        writer: FileWriter
    ): void {
        console.log(`Reading file: ${sourcePath}`);
        const content = reader.read(sourcePath);

        console.log(`Content: ${content}`);
        const parsed = parser.parse(content, targetFormat);
        console.log(`Parsed: ${parsed}`);

        console.log(`Writing to file: ${targetPath}`);
        writer.write(targetPath, content);
        console.log(`File conversion complete: ${sourcePath} -> ${targetPath}`);
    }
}

// Usage
const converter = new FileConverter();
const reader = new FileReader();
const parser = new FormatParser();
const writer = new FileWriter();

converter.convert("data.csv", "output.json", "JSON", reader, parser, writer);
