// Composition: Strong "has-a" relationship
// When Conversation is deleted, Messages are destroyed
// Messages cannot exist without Conversation

class Message {
    private sender: string;
    private text: string;
    private timestamp: number;

    constructor(sender: string, text: string) {
        this.sender = sender;
        this.text = text;
        this.timestamp = Date.now();
    }

    display(): void {
        console.log(`[${this.sender}]: ${this.text}`);
    }

    getSender(): string {
        return this.sender;
    }

    getText(): string {
        return this.text;
    }
}

class Conversation {
    private title: string;
    private messages: Message[] = [];

    constructor(title: string) {
        this.title = title;
        this.messages = [];
    }

    sendMessage(sender: string, text: string): void {
        this.messages.push(new Message(sender, text));
    }

    printHistory(): void {
        console.log(`--- ${this.title} ---`);
        this.messages.forEach(m => m.display());
    }

    delete(): void {
        // Clear all messages (they are destroyed with the conversation)
        this.messages = [];
        console.log(`Conversation "${this.title}" deleted`);
    }

    getMessages(): Message[] {
        return this.messages;
    }
}

// Usage
const chat = new Conversation("Project Discussion");

chat.sendMessage("Alice", "Hey, how's the project going?");
chat.sendMessage("Bob", "Good! I'm working on the backend");
chat.sendMessage("Alice", "Great! Let's sync up tomorrow");

chat.printHistory();

console.log();
console.log("Deleting conversation...");
chat.delete();
console.log("Messages remaining:", chat.getMessages().length);
