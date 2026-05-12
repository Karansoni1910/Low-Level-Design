// Association: One-to-Many relationship
// An Instructor can teach multiple Courses
// A Course can have one Instructor
// A Student can be enrolled in one Course

class Instructor {
    private name: string;
    private courses: Course[] = [];

    constructor(name: string) {
        this.name = name;
    }

    addCourse(course: Course): void {
        this.courses.push(course);
        course.setInstructor(this);
    }

    getName(): string {
        return this.name;
    }

    getCourses(): Course[] {
        return this.courses;
    }
}

class Course {
    private title: string;
    private instructor: Instructor | null = null;
    private students: Student[] = [];

    constructor(title: string) {
        this.title = title;
    }

    setInstructor(instructor: Instructor): void {
        this.instructor = instructor;
    }

    enrollStudent(student: Student): void {
        this.students.push(student);
        student.setEnrolledCourse(this);
    }

    getTitle(): string {
        return this.title;
    }

    getInstructor(): Instructor | null {
        return this.instructor;
    }

    getStudents(): Student[] {
        return this.students;
    }

    displayCourse(): void {
        console.log(`Course: ${this.title}`);
        console.log(`Instructor: ${this.instructor?.getName() || "None"}`);
        console.log("Students:");
        this.students.forEach(s => console.log(`  - ${s.getName()}`));
    }
}

class Student {
    private name: string;
    private enrolledCourse: Course | null = null;

    constructor(name: string) {
        this.name = name;
    }

    setEnrolledCourse(course: Course): void {
        this.enrolledCourse = course;
    }

    getName(): string {
        return this.name;
    }

    getEnrolledCourse(): Course | null {
        return this.enrolledCourse;
    }
}

// Usage
const instructor = new Instructor("Dr. Smith");

const course1 = new Course("TypeScript Basics");
instructor.addCourse(course1);

const course2 = new Course("Advanced TypeScript");
instructor.addCourse(course2);

const student1 = new Student("John");
const student2 = new Student("Jane");

course1.enrollStudent(student1);
course1.enrollStudent(student2);

course1.displayCourse();
console.log();
console.log(`${instructor.getName()} teaches: ${instructor.getCourses().map(c => c.getTitle()).join(", ")}`);
