interface Formatter {
    String format(String message);
}

class PlainFormatter implements Formatter {
    public String format(String message) {
        // Return the message as-is
        return message;
    }
}

class JsonFormatter implements Formatter {
    public String format(String message) {
        // Return the message wrapped in JSON: {"log": "message"}
        return "{\"log\": \"" + message + "\"}";
    }
}

class Logger {
    private Formatter formatter;

    public Logger(Formatter formatter) {
        this.formatter = formatter;
    }

    public void log(String message) {
        // Use the formatter to format the message, then print the result
        System.out.println(formatter.format(message));
    }
}

// Test your implementation
public class Main {
    public static void main(String[] args) {
        Logger plainLogger = new Logger(new PlainFormatter());
        plainLogger.log("Server started on port 8080");

        Logger jsonLogger = new Logger(new JsonFormatter());
        jsonLogger.log("Server started on port 8080");
    }
}