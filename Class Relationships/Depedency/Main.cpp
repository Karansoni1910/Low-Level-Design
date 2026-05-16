#include <iostream>
#include <string>
using namespace std;

class FileReader {
public:
    string read(const string& filePath) const {
        return "name,age,city";
    }
};

class FormatParser {
public:
    string parse(const string& content, const string& targetFormat) const {
        cout << "Parsing content to " << targetFormat << " format" << endl;
        return "[{\"name\":\"Alice\",\"age\":30,\"city\":\"NYC\"}]";
    }
};

class FileWriter {
public:
    void write(const string& filePath, const string& content) const {
        // Simulate writing
    }
};

class FileConverter {
public:
    void convert(const string& sourcePath, const string& targetPath,
                 const string& targetFormat, const FileReader& reader,
                 const FormatParser& parser, const FileWriter& writer) const {
        cout << "Reading file: " << sourcePath << endl;
        string content = reader.read(sourcePath);

        cout << "Content: " << content << endl;
        string parsed = parser.parse(content, targetFormat);
        cout << "Parsed: " << parsed << endl;

        cout << "Writing to file: " << targetPath << endl;
        writer.write(targetPath, content);
        cout << "File conversion complete: " << sourcePath << " -> " << targetPath << endl;
    }
};

int main() {
    FileConverter converter;
    FileReader reader;
    FormatParser parser;
    FileWriter writer;

    converter.convert("data.csv", "output.json", "JSON", reader, parser, writer);

    return 0;
}
