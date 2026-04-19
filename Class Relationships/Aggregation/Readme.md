Design Company Team Management

Problem: Build a company system where employees can belong to multiple teams. Dissolving a team doesn't remove the employees. This exercise reinforces that aggregation parts survive the deletion of the whole and can be shared.

Requirements:

Employee with a name and role. A getTeamNames() method that returns the names of all teams the employee belongs to.
Team with a name and a list of Employee objects. An addMember(employee) method that adds the employee and registers the team on the employee. A dissolve() method that clears the member list without destroying employees.
Company with a name and lists of both Employee and Team objects. A dissolveTeam(team) method that dissolves the team and removes it from the company.