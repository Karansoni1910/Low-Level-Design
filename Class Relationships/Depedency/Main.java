class FileReader {
    public String read(String filePath) {
        // TODO: Simulate reading a file and return its content
        return "name,age,city";
    }
}

class FormatParser {
    public String parse(String content, String targetFormat) {
        // TODO: Simulate converting content to the target format
        System.out.println("Parsing content to " + targetFormat + " format");
        return "[{\"name\":\"Alice\",\"age\":30,\"city\":\"NYC\"}]";
    }
}

class FileWriter {
    public void write(String filePath, String content) {
        // TODO: Simulate writing content to a file
    }
}

class FileConverter {
    public void convert(String sourcePath, String targetPath, String targetFormat,
                        FileReader reader, FormatParser parser, FileWriter writer) {
        // TODO: Use reader to read, parser to parse, writer to write
        System.out.println("Reading file: " + sourcePath);
        String content = reader.read(sourcePath);
        
        System.out.println("Content: " + content);
        String parsed = parser.parse(content, targetFormat);
        System.out.println("Parsed: " + parsed);

        System.out.println("Writing to file: " + targetPath);
        writer.write(targetPath, content);
        System.out.println("File conversion complete: " + sourcePath + " -> " + targetPath);
        // Print each step so you can verify the flow
    }
}

public class Main {
    public static void main(String[] args) {
        FileConverter converter = new FileConverter();

        FileReader reader = new FileReader();
        FormatParser parser = new FormatParser();
        FileWriter writer = new FileWriter();

        converter.convert("data.csv", "output.json", "JSON", reader, parser, writer);
    }
}