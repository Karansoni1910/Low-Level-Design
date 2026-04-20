// Low Coupling + High Cohesion Implementation

import java.util.ArrayList;
import java.util.List;

// Abstractions (Reduce Coupling)
interface DataSource {
    List<String> fetchData();
}

interface ReportFormatter {
    String format(List<String> data);
}

interface Distributor {
    void distribute(String report);
}

// Concrete Implementations (High Cohesion - Each does one thing)
class SimpleDataSource implements DataSource {
    public List<String> fetchData() {
        List<String> data = new ArrayList<>();
        data.add("Sales: $10,000");
        data.add("Revenue: $5,000");
        data.add("Profit: $3,000");
        return data;
    }
}

class SimpleReportFormatter implements ReportFormatter {
    public String format(List<String> data) {
        StringBuilder report = new StringBuilder();
        report.append("========== REPORT ==========\n");
        for (String line : data) {
            report.append(line).append("\n");
        }
        report.append("============================\n");
        return report.toString();
    }
}

// Distributors (High Cohesion - Each only distributes in one way)
class EmailDistributor implements Distributor {
    public void distribute(String report) {
        System.out.println("Email: Sending report to admin@example.com");
        System.out.println(report);
    }
}

class FileDistributor implements Distributor {
    public void distribute(String report) {
        System.out.println("File: Saving report to report.txt");
        System.out.println(report);
    }
}

class ConsoleDistributor implements Distributor {
    public void distribute(String report) {
        System.out.println("Console: Printing report");
        System.out.println(report);
    }
}

// Report Generator (High Cohesion - Only generates)
class ReportGenerator {
    private DataSource dataSource;
    private ReportFormatter formatter;

    public ReportGenerator(DataSource dataSource, ReportFormatter formatter) {
        this.dataSource = dataSource;
        this.formatter = formatter;
    }

    public String generate() {
        List<String> data = dataSource.fetchData();
        return formatter.format(data);
    }
}

// Report Service (Orchestrator - Low Coupling via interfaces)
class ReportService {
    private ReportGenerator generator;
    private List<Distributor> distributors;

    public ReportService(ReportGenerator generator) {
        this.generator = generator;
        this.distributors = new ArrayList<>();
    }

    public void addDistributor(Distributor distributor) {
        distributors.add(distributor);
    }

    public void generateAndDistribute() {
        String report = generator.generate();
        for (Distributor distributor : distributors) {
            distributor.distribute(report);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        // Create low-coupling, high-cohesion components
        DataSource dataSource = new SimpleDataSource();
        ReportFormatter formatter = new SimpleReportFormatter();
        ReportGenerator generator = new ReportGenerator(dataSource, formatter);

        // Create service
        ReportService service = new ReportService(generator);

        // Add multiple distributors (easily extensible)
        service.addDistributor(new ConsoleDistributor());
        service.addDistributor(new EmailDistributor());
        service.addDistributor(new FileDistributor());

        // Generate and distribute
        service.generateAndDistribute();
    }
}
