class Email {
    readonly to: string;
    readonly subject: string;
    readonly cc: string[];
    readonly bcc: string[];
    readonly body: string;
    readonly priority: string;
    readonly attachments: string[];

    constructor(builder: EmailBuilder) {
        this.to = builder.to;
        this.subject = builder.subject;
        this.cc = [...builder.cc];
        this.bcc = [...builder.bcc];
        this.body = builder.body;
        this.priority = builder.priority;
        this.attachments = [...builder.attachments];
    }

    toString(): string {
        return `Email{to='${this.to}', subject='${this.subject}', cc=${JSON.stringify(this.cc)}, bcc=${JSON.stringify(this.bcc)}, body='${this.body}', priority='${this.priority}', attachments=${JSON.stringify(this.attachments)}}`;
    }
}

class EmailBuilder {
    to: string;
    subject: string;
    cc: string[] = [];
    bcc: string[] = [];
    body: string = "";
    priority: string = "normal";
    attachments: string[] = [];

    constructor(to: string, subject: string) {
        this.to = to;
        this.subject = subject;
    }

    addCc(cc: string): EmailBuilder {
        this.cc.push(cc);
        return this;
    }

    addBcc(bcc: string): EmailBuilder {
        this.bcc.push(bcc);
        return this;
    }

    setBody(body: string): EmailBuilder {
        this.body = body;
        return this;
    }

    setPriority(priority: string): EmailBuilder {
        this.priority = priority;
        return this;
    }

    addAttachment(attachment: string): EmailBuilder {
        this.attachments.push(attachment);
        return this;
    }

    build(): Email {
        return new Email(this);
    }
}

// Usage
const email1 = new EmailBuilder("alice@example.com", "Meeting Tomorrow")
    .setBody("Let's meet at 10am in conference room B.")
    .build();

const email2 = new EmailBuilder("bob@example.com", "Project Update")
    .addCc("carol@example.com")
    .addCc("dave@example.com")
    .addBcc("manager@example.com")
    .setBody("Attached is the Q4 report.")
    .setPriority("high")
    .addAttachment("q4-report.pdf")
    .addAttachment("summary.xlsx")
    .build();

console.log(email1.toString());
console.log();
console.log(email2.toString());
