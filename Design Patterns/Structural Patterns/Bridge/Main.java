interface MessageSender {
    void sendMessage(String content);
}

class EmailSender implements MessageSender {
    @Override
    public void sendMessage(String content) {
        System.out.println("Email: " + content);
    }
}

class SmsSender implements MessageSender {
    @Override
    public void sendMessage(String content) {
        System.out.println("SMS: " + content);
    }
}

abstract class Message {
    // TODO: Add a protected field for the MessageSender reference
    // TODO: Add a protected field for the message content (String)
    protected MessageSender sender;
    protected String content;

    public Message(MessageSender sender, String content) {
        // TODO: Store the sender and content
        this.sender = sender;
        this.content = content;
    }

    public abstract void send();
}

class TextMessage extends Message {
    public TextMessage(MessageSender sender, String content) {
        // TODO: Call the parent constructor
        super(sender, content);
    }

    @Override
    public void send() {
        // TODO: Delegate to sender.sendMessage() with the content as-is
        this.sender.sendMessage(this.content);
    }
}

class UrgentMessage extends Message {
    public UrgentMessage(MessageSender sender, String content) {
        // TODO: Call the parent constructor
        super(sender, content);
    }

    @Override
    public void send() {
        // TODO: Delegate to sender.sendMessage() with "[URGENT] " prepended to the content
        this.sender.sendMessage("[URGENT] " + content);
    }
}

public class Main {
    public static void main(String[] args) {
        MessageSender email = new EmailSender();
        MessageSender sms = new SmsSender();
        Message m1 = new TextMessage(email, "Hello there");
        Message m2 = new UrgentMessage(sms, "Server is down");
        m1.send();
        m2.send();
    }
}