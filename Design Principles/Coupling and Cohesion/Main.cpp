#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// Coupling and Cohesion Principle

class DataSource {
public:
    virtual ~DataSource() = default;
    virtual vector<string> fetchData() = 0;
};

class ReportFormatter {
public:
    virtual ~ReportFormatter() = default;
    virtual string format(const vector<string>& data) = 0;
};

class Distributor {
public:
    virtual ~Distributor() = default;
    virtual void distribute(const string& report) = 0;
};

class SimpleDataSource : public DataSource {
public:
    vector<string> fetchData() override {
        return {"Sales: $10,000", "Revenue: $5,000", "Profit: $3,000"};
    }
};

class SimpleReportFormatter : public ReportFormatter {
public:
    string format(const vector<string>& data) override {
        stringstream ss;
        ss << "========== REPORT ==========\n";
        for (const auto& line : data) {
            ss << line << "\n";
        }
        ss << "============================\n";
        return ss.str();
    }
};

class EmailDistributor : public Distributor {
public:
    void distribute(const string& report) override {
        cout << "Email: Sending report to admin@example.com\n" << report;
    }
};

class FileDistributor : public Distributor {
public:
    void distribute(const string& report) override {
        cout << "File: Saving report to report.txt\n" << report;
    }
};

class ConsoleDistributor : public Distributor {
public:
    void distribute(const string& report) override {
        cout << "Console: Printing report\n" << report;
    }
};

class ReportGenerator {
private:
    DataSource* dataSource;
    ReportFormatter* formatter;

public:
    ReportGenerator(DataSource* ds, ReportFormatter* fmt)
        : dataSource(ds), formatter(fmt) {}

    string generate() {
        auto data = dataSource->fetchData();
        return formatter->format(data);
    }
};

class ReportService {
private:
    ReportGenerator* generator;
    vector<Distributor*> distributors;

public:
    ReportService(ReportGenerator* gen) : generator(gen) {}

    void addDistributor(Distributor* distributor) {
        distributors.push_back(distributor);
    }

    void generateAndDistribute() {
        string report = generator->generate();
        for (auto dist : distributors) {
            dist->distribute(report);
        }
    }
};

int main() {
    SimpleDataSource dataSource;
    SimpleReportFormatter formatter;
    ReportGenerator generator(&dataSource, &formatter);
    ReportService service(&generator);

    ConsoleDistributor console;
    EmailDistributor email;
    FileDistributor file;

    service.addDistributor(&console);
    service.addDistributor(&email);
    service.addDistributor(&file);

    service.generateAndDistribute();

    return 0;
}
