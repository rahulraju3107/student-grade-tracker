#include <stdio.h>

// Define student struct
typedef struct
{
    char name[100];
    float grade;
} student;

// Function prototypes
float highest_grade(student students[], int n);
float lowest_grade(student students[], int n);
float average_grade(student students[], int n);

int main(void)
{
    // This program is a student grade tracker that displays grade statistics
    // Input names and marks for students
    // Display average, highest, and lowest grades

    printf("This program provides grade statics for student.\n\n");

    // Prompt for number of students
    int n;
    printf("How many students will be graded: ");
    scanf("%i", &n);

    // Declare array of students
    student students[n];

    // Input names and grades using loop
    for (int i = 0; i < n; i++)
    {
        printf("Student name: ");
        scanf("%s", students[i].name);  // No '&' needed for char arrays

        printf("Grade: ");
        scanf("%f", &students[i].grade);
    }

    // Compute statistics
    float high = highest_grade(students, n);
    float low = lowest_grade(students, n);
    float avg = average_grade(students, n);

    // Prints the results
    printf("\n--- Grade Summary ---\n");
    printf("Highest grade: %.2f\n", high);
    printf("Lowest grade: %.2f\n", low);
    printf("Average grade: %.2f\n\n", avg);
}

// Calculate highest grade
float highest_grade(student students[], int n)
{
    float highest_score = students[0].grade;

    for (int i = 0; i < n; i++)
    {
        if (students[i].grade > highest_score)
        {
            highest_score = students[i].grade;
        }
    }
    return highest_score;
}

// Calculate lowest grade
float lowest_grade(student students[], int n)
{
    float lowest_score = students[0].grade;

    for (int i = 0; i < n; i++)
    {
        if (students[i].grade < lowest_score)
        {
            lowest_score = students[i].grade;
        }
    }
    return lowest_score;
}

// Calculate average grade
float average_grade(student students[], int n)
{
    float total = 0.0;

    for (int i = 0; i < n; i++)
    {
        total += students[i].grade;
    }
    return total / n;
}
