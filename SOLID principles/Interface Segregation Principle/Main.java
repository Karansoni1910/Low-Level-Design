// Before: Fat interface forces BasicPrinter to implement everything
interface MultiFunctionDevice {
    void print(String document);
    void scan(String document);
    void fax(String document, String number);
    void staple(String document);
}

interface Printable {
    public void print(String document);
}

interface Scannable {
    public void scan(String document);
}

interface Faxable {
    public void fax(String document, String number);
}

interface Stapleable {
    public void staple(String document);
}

class BasicPrinter implements Printable {
    public void print(String document) {
        System.out.println("BasicPrinter -> Printing: " + document);
    }
}

class OfficePrinter implements Printable, Scannable, Faxable {
    public void print(String document) {
        System.out.println("OfficePrinter -> Printing: " + document);
    }
    public void scan(String document) {
        System.out.println("OfficePrinter -> Scanning: " + document);
    }
    public void fax(String document, String number) {
        System.out.println("OfficePrinter -> Faxing: " + document + " to " + number);
    }
}

class FullDevice implements Printable, Scannable, Faxable, Stapleable {
    public void print(String document) {
        System.out.println("FullDevice -> Printing: " + document);
    }
    public void scan(String document) {
        System.out.println("FullDevice -> Scanning: " + document);
    }
    public void fax(String document, String number) {
        System.out.println("FullDevice -> Faxing: " + document + " to " + number);
    }
    public void staple(String document) {
        System.out.println("FullDevice -> Stapling: " + document);
    }
}

public class Main {
    public static void main(String[] args) {
        BasicPrinter basicPrinter = new BasicPrinter();
        basicPrinter.print("report.pdf");

        OfficePrinter officePrinter = new OfficePrinter();
        officePrinter.print("memo.pdf");
        officePrinter.scan("memo.pdf");
        officePrinter.fax("memo.pdf", "555-1234");
        
        FullDevice fullDevicePrinter = new FullDevice();
        fullDevicePrinter.print("contract.pdf");
        fullDevicePrinter.scan("contract.pdf");
        fullDevicePrinter.fax("contract.pdf", "555-5678");
        fullDevicePrinter.staple("contract.pdf");
    }
}