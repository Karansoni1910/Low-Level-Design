interface TextFormatter {
    String format(String text);
}

class UpperCaseFormatter implements TextFormatter {
    @Override
    public String format(String text) {
        return text.toUpperCase(); // TODO: Return text converted to upper case
    }
}

class LowerCaseFormatter implements TextFormatter {
    @Override
    public String format(String text) {
        return text.toLowerCase(); // TODO: Return text converted to lower case
    }
}

class TitleCaseFormatter implements TextFormatter {
    @Override
    public String format(String text) {
        // TODO: Split by space, capitalize first letter of each word, rejoin
        String[] words = text.split(" ");
        StringBuilder result = new StringBuilder();
        
        for (String word : words) {
            if (word.length() > 0) {
                result.append(Character.toUpperCase(word.charAt(0)))
                    .append(word.substring(1).toLowerCase())
                    .append(" ");
            }
        }
        return result.toString().trim();
    }
}

class TextEditor {
    private TextFormatter formatter;

    public TextEditor(TextFormatter formatter) {
        this.formatter = formatter;
    }

    public void setFormatter(TextFormatter formatter) {
        this.formatter = formatter;
    }

    public void publishText(String text) {
        System.out.println(formatter.format(text));
    }
}

public class Main {
    public static void main(String[] args) {
        TextEditor editor = new TextEditor(new UpperCaseFormatter());
        editor.publishText("hello world from strategy pattern");

        editor.setFormatter(new LowerCaseFormatter());
        editor.publishText("Hello World From Strategy Pattern");

        editor.setFormatter(new TitleCaseFormatter());
        editor.publishText("hello world from strategy pattern");
    }
}