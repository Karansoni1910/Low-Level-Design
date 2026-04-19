Design Online Course Platform

Problem: Build a course platform where instructors create courses and students enroll in them. This exercise practices unidirectional and one-to-many associations.

Requirements:

Instructor with a name and a list of Course objects they teach. An addCourse(course) method that adds the course and sets the instructor on the course.
Course with a title, an Instructor reference, and a list of enrolled Student objects. An enrollStudent(student) method that adds the student and sets the enrolled course on the student.
Student with a name and an enrolledCourse reference (the course they're currently taking). A getInstructorName() method that navigates through the course to return the instructor's name.