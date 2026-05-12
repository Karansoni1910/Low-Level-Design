// Aggregation: Employee can belong to multiple Teams
// Team can exist without Employee, Employee can exist without Team

class Employee {
    private name: string;
    private role: string;
    private teams: Team[] = [];

    constructor(name: string, role: string) {
        this.name = name;
        this.role = role;
    }

    addTeam(team: Team): void {
        this.teams.push(team);
    }

    removeTeam(team: Team): void {
        this.teams = this.teams.filter(t => t !== team);
    }

    getTeamNames(): string[] {
        return this.teams.map(team => team.getName());
    }

    getName(): string {
        return this.name;
    }

    getRole(): string {
        return this.role;
    }
}

class Team {
    private name: string;
    private members: Employee[] = [];

    constructor(name: string) {
        this.name = name;
    }

    addMember(employee: Employee): void {
        this.members.push(employee);
        employee.addTeam(this);
    }

    removeMember(employee: Employee): void {
        this.members = this.members.filter(e => e !== employee);
        employee.removeTeam(this);
    }

    getName(): string {
        return this.name;
    }

    getMembers(): Employee[] {
        return this.members;
    }

    displayTeam(): void {
        console.log(`Team: ${this.name}`);
        this.members.forEach(member => {
            console.log(`  - ${member.getName()} (${member.getRole()})`);
        });
    }
}

// Usage
const dev1 = new Employee("Alice", "Developer");
const dev2 = new Employee("Bob", "Developer");
const qa1 = new Employee("Carol", "QA Engineer");

const backend = new Team("Backend");
const qa = new Team("QA");

backend.addMember(dev1);
backend.addMember(dev2);
qa.addMember(qa1);
qa.addMember(dev1); // Alice can be in multiple teams

backend.displayTeam();
console.log();
qa.displayTeam();
console.log();
console.log(`${dev1.getName()} is in teams: ${dev1.getTeamNames().join(", ")}`);
