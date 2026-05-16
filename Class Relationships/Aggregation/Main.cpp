#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Team;

class Employee {
private:
    string name;
    string role;
    vector<Team*> teams;

public:
    Employee(const string& name, const string& role)
        : name(name), role(role) {}

    void addTeam(Team* team) {
        teams.push_back(team);
    }

    void removeTeam(Team* team) {
        teams.erase(remove(teams.begin(), teams.end(), team), teams.end());
    }

    vector<string> getTeamNames() const;
    string getName() const { return name; }
    string getRole() const { return role; }
};

class Team {
private:
    string name;
    vector<Employee*> members;

public:
    Team(const string& name) : name(name) {}

    void addMember(Employee* employee) {
        members.push_back(employee);
        employee->addTeam(this);
    }

    void dissolve() {
        for (auto e : members) {
            e->removeTeam(this);
        }
        members.clear();
    }

    string getName() const { return name; }
    vector<Employee*> getMembers() const { return members; }
    int getMemberCount() const { return members.size(); }
};

vector<string> Employee::getTeamNames() const {
    vector<string> teamNames;
    for (const auto& team : teams) {
        teamNames.push_back(team->getName());
    }
    return teamNames;
}

class Company {
private:
    string name;
    vector<Employee*> employees;
    vector<Team*> teams;

public:
    Company(const string& name) : name(name) {}

    void addEmployee(Employee* employee) {
        employees.push_back(employee);
    }

    void addTeam(Team* team) {
        teams.push_back(team);
    }

    void dissolveTeam(Team* team) {
        team->dissolve();
        teams.erase(remove(teams.begin(), teams.end(), team), teams.end());
    }

    string getName() const { return name; }
    int getEmployeeCount() const { return employees.size(); }
    int getTeamCount() const { return teams.size(); }
};

int main() {
    Company company("TechCorp");

    Employee alice("Alice", "Engineer");
    Employee bob("Bob", "Manager");
    Employee charlie("Charlie", "Designer");

    company.addEmployee(&alice);
    company.addEmployee(&bob);
    company.addEmployee(&charlie);

    Team backend("Backend");
    Team frontend("Frontend");

    company.addTeam(&backend);
    company.addTeam(&frontend);

    backend.addMember(&alice);
    backend.addMember(&bob);
    frontend.addMember(&charlie);
    frontend.addMember(&bob);

    cout << company.getName() << " has " << company.getEmployeeCount() 
         << " employees and " << company.getTeamCount() << " teams" << endl;

    cout << alice.getName() << " is in teams: ";
    for (const auto& team : alice.getTeamNames()) {
        cout << team << " ";
    }
    cout << endl;

    cout << backend.getName() << " team has " << backend.getMemberCount() << " members" << endl;

    company.dissolveTeam(&backend);
    cout << "After dissolving backend team, " << company.getName() 
         << " has " << company.getTeamCount() << " teams" << endl;

    return 0;
}
