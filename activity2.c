#include <stdio.h>

int main() {
    // STUDENT GRADE ANALYSIS SYSTEM
    // 
    // You are managing grades for 5 students across 4 subjects.
    // Each student has scores in: Math, Science, English, History
    // 
    // Student data (fill this into your 2D array):
    // Student 0: 85, 92, 78, 88
    // Student 1: 76, 84, 91, 79  
    // Student 2: 93, 87, 85, 92
    // Student 3: 68, 75, 82, 71
    // Student 4: 89, 90, 87, 94
    
    
    int grades[5][4] = {
        {85, 92, 78, 88},
        {76, 84, 91, 79},
        {93, 87, 91, 79},
        {68, 75, 82, 71},
        {89, 90, 87, 94}
    }; // 5 students, 4 subjects

    
    int student_avg[5]; // Average grade for each student
    int subject_avg[4]; // Average grade for each subject
    
    printf("STUDENT GRADE ANALYSIS SYSTEM\n");
    printf("============================\n\n");
    
    // PART 1: Initialize the grades array with the data above
    // TODO: Fill the grades array with the student scores
    
/*    for (int i = 0; i < 5; i++){
        printf("\nStudent number %d", i);
        printf("\nEnter Math Grade:");
        scanf("%d", &grades[i][1]);
        printf("\nEnter Science Grade:");
        scanf("%d", &grades[i][2]);
        printf("\nEnter English Grade:");
        scanf("%d", &grades[i][3]);
        printf("\nEnter History Grade:");
        scanf("%d", &grades[i][4]);
    }
*/    
    // Display the grade table
    printf("Original Grades:\n");
    printf("Student | Math | Science | English | History\n");
    printf("--------|------|---------|---------|--------\n");
    
    for(int i = 0; i < 5; i++) {
        printf("   %d    |", i);
        for(int j = 0; j < 4; j++) {
            printf("  %d  |", grades[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // PART 2: Calculate each student's average grade
    // TODO: Calculate the average grade for each student
    // Store results in student_avg array
    
    for (int i = 0; i < 5; i++){
        student_avg[i] = (grades[i][0] + grades[i][1] + grades[i][2] + grades[i][3]) / 4;
    }
    
    printf("Student Averages:\n");
    for(int i = 0; i < 5; i++) {
        printf("Student %d: %d\n", i, student_avg[i]);
    }
    printf("\n");
    
    // PART 3: Calculate each subject's average grade  
    // TODO: Calculate the average grade for each subject
    // Store results in subject_avg array
    
    for (int i = 0; i < 4; i++){
        subject_avg[i] = (grades[0][i] + grades[1][i] + grades[2][i] + grades[3][i] + grades[4][i]) / 5;
    }
    
    printf("Subject Averages:\n");
    printf("Math: %d, Science: %d, English: %d, History: %d\n\n", 
           subject_avg[0], subject_avg[1], subject_avg[2], subject_avg[3]);

    // PART 4: Find the best and worst performing students
    // TODO: Find which student has the highest average
    // TODO: Find which student has the lowest average
    
    int best_student = 0;
    int worst_student = 0;
    
    
    for (int i = 0; i < 5; i++){
        if (student_avg[i] >= student_avg[0] && student_avg[i] >= student_avg[1] && student_avg[i] >= student_avg[2] && student_avg[i] >= student_avg[3]
            && student_avg[i] >= student_avg[4]){
                best_student = i;
                break;
        }
    }
    
    for (int i = 0; i < 5; i++){
        if (student_avg[i] <= student_avg[0] && student_avg[i] <= student_avg[1] && student_avg[i] <= student_avg[2] && student_avg[i] <= student_avg[3]
            && student_avg[i] <= student_avg[4]){
                worst_student = i;
                break;
        }
    }
    
    printf("Best Student: Student %d with average %d\n", best_student, student_avg[best_student]);
    printf("Worst Student: Student %d with average %d\n\n", worst_student, student_avg[worst_student]);
    
    // PART 5: Grade Improvement Simulation
    // Simulate what happens if each student's lowest grade is improved by 10 points
    // (but don't let any grade go above 100)
    

    int improved_grades[5][4] = {
        {85, 92, 78, 88},
        {76, 84, 91, 79},
        {93, 87, 91, 79},
        {68, 75, 82, 71},
        {89, 90, 87, 94}
    };
    
    // First, copy original grades to improved_grades array
    // TODO: Copy all grades from grades[][] to improved_grades[][]
    for (int i = 0; i < 5; i++){
        for (int j = 0; i < 4; j++){
            if (improved_grades[i][j] <= improved_grades[i][0] && improved_grades[i][j] <= improved_grades[i][1] && improved_grades[i][j]
                <= improved_grades[i][2] && improved_grades[i][j] <= improved_grades[i][3]) {
                        improved_grades[i][j]+=10;
                        break;
            }
        }
    }
    
    
    
    // Now find and improve each student's lowest grade
    // TODO: For each student, find their lowest grade and add 10 points
    // (maximum grade is 100)
    
    
    
    printf("After improving each student's weakest subject by 10 points:\n");
    printf("Student | Math | Science | English | History | New Avg\n");
    printf("--------|------|---------|---------|---------|--------\n");
    
    for(int i = 0; i < 5; i++) {
        printf("   %d    |", i);
        int total = 0;
        for(int j = 0; j < 4; j++) {
            printf("  %2d  |", improved_grades[i][j]);
            total += improved_grades[i][j];
        }
        printf("   %2d   \n", total / 4);
    }
    printf("\n");
       
    // PART 6: Grade Distribution Analysis
    // Count how many grades fall into each range:
    // A: 90-100, B: 80-89, C: 70-79, D: 60-69, F: below 60
    
    int grade_counts[5] = {0, 0, 0, 0, 0}; // F, D, C, B, A
    
    // TODO: Count grades in each category using the original grades array
    // grade_counts[0] = F grades (below 60)
    // grade_counts[1] = D grades (60-69)  
    // grade_counts[2] = C grades (70-79)
    // grade_counts[3] = B grades (80-89)
    // grade_counts[4] = A grades (90-100)
    
    for (int i = 0; i < 5; i++){
        if (student_avg[i] < 60)
            grade_counts[0]++;
        else if (student_avg[i] >= 60 && student_avg[i] < 70)
            grade_counts[1]++;
        else if (student_avg[i] >= 70 && student_avg[i] < 80)
            grade_counts[2]++;
        else if (student_avg[i] >= 80 && student_avg[i] < 90)
            grade_counts[3]++;
        else if (student_avg[i] >= 90 && student_avg[i] < 100)
            grade_counts[4]++;
        else
            printf("ERROR!");
    }
    
    
    printf("Grade Distribution:\n");
    printf("A grades (90-100): %d\n", grade_counts[4]);
    printf("B grades (80-89):  %d\n", grade_counts[3]);
    printf("C grades (70-79):  %d\n", grade_counts[2]);
    printf("D grades (60-69):  %d\n", grade_counts[1]);
    printf("F grades (below 60): %d\n\n", grade_counts[0]);

    // PART 7: Subject Difficulty Ranking
    // Rank subjects from easiest to hardest based on average grades
    // Create an array that holds the subject indices sorted by average (highest to lowest)
    
    int subject_ranking[4] = {0, 1, 2, 3}; // Will hold indices 0,1,2,3 sorted by subject averages
    
    // TODO: Sort the subjects by their averages (highest average = easiest subject)
    // You can use a simple sorting method like bubble sort or selection sort
    // Store the subject indices in subject_ranking array
    
    for (int i = 0; i < 4 - 1; i++) {
        for (int j = 0; j < 4 - i - 1; j++) {
            if (subject_avg[subject_ranking[j]] < subject_avg[subject_ranking[j + 1]]) {
                int temp = subject_ranking[j];
                subject_ranking[j] = subject_ranking[j + 1];
                subject_ranking[j + 1] = temp;
            }
        }
    }
    
    
    printf("Subject Difficulty Ranking (Easiest to Hardest):\n");
    char subject_names[4][10] = {"Math", "Science", "English", "History"};
    
    for(int i = 0; i < 4; i++) {
        printf("%d. %s (Average: %d)\n", i+1, 
               subject_names[subject_ranking[i]], 
               subject_avg[subject_ranking[i]]);
    }
    

    
    return 0;
}