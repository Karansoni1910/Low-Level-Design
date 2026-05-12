// Interface Segregation Principle: Clients should not depend on interfaces they don't use

interface Printable {
    print(document: string): void;
}

interface Scannable {
    scan(document: string): void;
}

interface Faxable {
    fax(document: string, number: string): void;
}

interface Stapleable {
    staple(document: string): void;
}

class BasicPrinter implements Printable {
    print(document: string): void {
        console.log(`BasicPrinter -> Printing: ${document}`);
    }
}

class OfficePrinter implements Printable, Scannable, Faxable {
    print(document: string): void {
        console.log(`OfficePrinter -> Printing: ${document}`);
    }

    scan(document: string): void {
        console.log(`OfficePrinter -> Scanning: ${document}`);
    }

    fax(document: string, number: string): void {
        console.log(`OfficePrinter -> Faxing: ${document} to ${number}`);
    }
}

class FullDevice implements Printable, Scannable, Faxable, Stapleable {
    print(document: string): void {
        console.log(`FullDevice -> Printing: ${document}`);
    }

    scan(document: string): void {
        console.log(`FullDevice -> Scanning: ${document}`);
    }

    fax(document: string, number: string): void {
        console.log(`FullDevice -> Faxing: ${document} to ${number}`);
    }

    staple(document: string): void {
        console.log(`FullDevice -> Stapling: ${document}`);
    }
}

// Usage
const basicPrinter: Printable = new BasicPrinter();
basicPrinter.print("report.pdf");

const officePrinter: Printable & Scannable & Faxable = new OfficePrinter();
officePrinter.print("memo.pdf");
officePrinter.scan("memo.pdf");
officePrinter.fax("memo.pdf", "555-1234");

const fullDevice: Printable & Scannable & Faxable & Stapleable = new FullDevice();
fullDevice.print("contract.pdf");
fullDevice.scan("contract.pdf");
fullDevice.fax("contract.pdf", "555-5678");
fullDevice.staple("contract.pdf");
