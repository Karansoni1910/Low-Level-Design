import java.util.ArrayList;
import java.util.List;

interface Plugin {
    String execute(String text);
    String getName();
}

class SpellCheckPlugin implements Plugin {
    public String execute(String text) {
        // TODO: replace "teh" with "the", "adn" with "and"
        String[] words = text.split("\\s+");
        for(int i=0; i < words.length; i++){
            if(words[i].equals("teh")) words[i] = "the";
            if(words[i].equals("adn")) words[i] = "and";
        }
        return String.join(" ", words);
    }

    public String getName() {
        return "Spell Check";
    }
}

class WordCountPlugin implements Plugin {
    public String execute(String text) {
        // TODO: append "\n[Word count: X]" to the text
        String[] words = text.split("\\s+");
        return text + "\n[Word count: " + words.length + "]";
    }

    public String getName() {
        return "Word Count";
    }
}

class UpperCasePlugin implements Plugin {
    public String execute(String text) {
        // TODO: return text.toUpperCase()
        return text.toUpperCase();
    }

    public String getName() {
        return "Upper Case";
    }
}

class TextEditor {
    private List<Plugin> plugins = new ArrayList<>();

    public void registerPlugin(Plugin plugin) {
        // TODO: Add the plugin to the list and print "Registered: [name]"
        plugins.add(plugin);
        System.out.println("Registered: " + plugin.getName());
    }

    public String runPlugins(String text) {
        // TODO: Run each plugin in sequence, passing output of one as input to the next
        // Print "Running: [name]" before each plugin
        // Return the final processed text
        for(Plugin p : plugins){
            System.out.println("Running: " + p.getName());
            text = p.execute(text);
        }
        return text;
    }
}

public class Main {
    public static void main(String[] args) {
        TextEditor editor = new TextEditor();
        editor.registerPlugin(new SpellCheckPlugin());
        editor.registerPlugin(new WordCountPlugin());

        String result = editor.runPlugins("teh quick brown fox adn teh lazy dog");
        System.out.println("\nFinal output: " + result);
    }
}