// Low Coupling + High Cohesion Implementation

interface DataSource {
    fetchData(): string[];
}

interface ReportFormatter {
    format(data: string[]): string;
}

interface Distributor {
    distribute(report: string): void;
}

// Concrete Implementations (High Cohesion - Each does one thing)
class SimpleDataSource implements DataSource {
    fetchData(): string[] {
        return ["Sales: $10,000", "Revenue: $5,000", "Profit: $3,000"];
    }
}

class SimpleReportFormatter implements ReportFormatter {
    format(data: string[]): string {
        let report = "========== REPORT ==========\n";
        data.forEach(line => {
            report += line + "\n";
        });
        report += "============================\n";
        return report;
    }
}

// Distributors (High Cohesion - Each only distributes in one way)
class EmailDistributor implements Distributor {
    distribute(report: string): void {
        console.log("Email: Sending report to admin@example.com");
        console.log(report);
    }
}

class FileDistributor implements Distributor {
    distribute(report: string): void {
        console.log("File: Saving report to report.txt");
        console.log(report);
    }
}

class ConsoleDistributor implements Distributor {
    distribute(report: string): void {
        console.log("Console: Printing report");
        console.log(report);
    }
}

// Report Generator (High Cohesion - Only generates)
class ReportGenerator {
    private dataSource: DataSource;
    private formatter: ReportFormatter;

    constructor(dataSource: DataSource, formatter: ReportFormatter) {
        this.dataSource = dataSource;
        this.formatter = formatter;
    }

    generate(): string {
        const data = this.dataSource.fetchData();
        return this.formatter.format(data);
    }
}

// Report Service (Orchestrator - Low Coupling via interfaces)
class ReportService {
    private generator: ReportGenerator;
    private distributors: Distributor[] = [];

    constructor(generator: ReportGenerator) {
        this.generator = generator;
    }

    addDistributor(distributor: Distributor): void {
        this.distributors.push(distributor);
    }

    generateAndDistribute(): void {
        const report = this.generator.generate();
        this.distributors.forEach(distributor => {
            distributor.distribute(report);
        });
    }
}

// Usage
const dataSource = new SimpleDataSource();
const formatter = new SimpleReportFormatter();
const generator = new ReportGenerator(dataSource, formatter);

const service = new ReportService(generator);
service.addDistributor(new ConsoleDistributor());
service.addDistributor(new EmailDistributor());
service.addDistributor(new FileDistributor());

service.generateAndDistribute();
