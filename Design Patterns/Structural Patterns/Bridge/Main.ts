interface MessageSender {
    sendMessage(content: string): void;
}

class EmailSender implements MessageSender {
    sendMessage(content: string): void {
        console.log("Email: " + content);
    }
}

class SmsSender implements MessageSender {
    sendMessage(content: string): void {
        console.log("SMS: " + content);
    }
}

abstract class Message {
    protected sender: MessageSender;
    protected content: string;

    constructor(sender: MessageSender, content: string) {
        this.sender = sender;
        this.content = content;
    }

    abstract send(): void;
}

class TextMessage extends Message {
    constructor(sender: MessageSender, content: string) {
        super(sender, content);
    }

    send(): void {
        this.sender.sendMessage(this.content);
    }
}

class UrgentMessage extends Message {
    constructor(sender: MessageSender, content: string) {
        super(sender, content);
    }

    send(): void {
        this.sender.sendMessage("[URGENT] " + this.content);
    }
}

// Usage
const email = new EmailSender();
const sms = new SmsSender();

const m1: Message = new TextMessage(email, "Hello there");
const m2: Message = new UrgentMessage(sms, "Server is down");

m1.send();
m2.send();
