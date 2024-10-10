#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#define DECIMAL_DIGIT 2

struct Student {
    int id;
    std::string name;
    std::vector<int> scores;
};

std::vector<Student> students  = {
    {1, "Alice", {85, 92, 78, 94, 88}},
    {2, "Bob", {76, 81, 72, 85, 79}},
    {3, "Charlie", {93, 89, 84, 91, 95}},
    {4, "David", {65, 70, 75, 60, 80}},
    {5, "Eve", {54, 68, 72, 77, 65}}
};

/**
 * Calculate the average score of the given student
 * @param Student : the student
 * @return the average of students scores
 */
float calculateAverage(Student student) {
    
    // TODO
    int total=0;
    for(int i:student.scores){
        total+=i;
    }
    return (float)total/student.scores.size();    // To change
}

/**
 * Calculate GPA based on average score
 * @param Student : the student
 * @return the average of students scores
 */
float calculateGPA(Student student) {

    // TODO
    float avg;
    avg=calculateAverage(student);
    if(avg>=90 && avg <=100){
        return 4.0;
    }else if(avg>=80 && avg<90){
        return 3.0;
    }else if(avg>=70 && avg<80){
        return 2.0;
    }else if(avg>=60 && avg<70){
        return 1.0;
    }
    return 0.0;
}


/**
 * Calculate letter grade based on GPA
 * @param Student : the student
 * @return the average of students scores
 */
std::string calculatGrade(Student student) {

    // TODO
    float gpa=calculateGPA(student);
    if(gpa==4.0) return "A";
    if(gpa==3.0) return "B";
    if(gpa==2.0) return "C";
    if(gpa==1.0) return "D";
    return "E"; // To change
}


/**
 * Compute and print students statistic (average, GPA, grade letter) on console
 * @param Student : the student
 */
void printStudentStatistics(const Student& student) {
        float average = calculateAverage(student);
        float gpa = calculateGPA(student);
        std::string grade = calculatGrade(student);

        std::cout << "| " << std::setw(10) << student.id << " | "
                  << std::setw(10) << student.name << " | "
                  << std::setw(14) << average << " | "
                  << std::setw(4) << gpa << " | "
                  << std::setw(5) << grade << " |\n";
}


int main() {
    std::cout << std::fixed << std::setprecision(DECIMAL_DIGIT); // Set decimal precision for average and GPA
    std::cout << "------------------------------------------------------------\n";
    std::cout << "| Student ID | Name      | Average Score |  GPA | Grade |\n";
    std::cout << "------------------------------------------------------------\n";

    // Call the function printStudentStatistics for each student
    // TODO
    for(Student i:students){
        printStudentStatistics(i);
    }
    std::cout << "------------------------------------------------------------\n";
    
    return 0;
}