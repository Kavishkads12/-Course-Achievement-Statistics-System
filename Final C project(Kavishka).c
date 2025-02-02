#include <stdio.h>
#include <stdlib.h>
#define STU_NUM 30

typedef struct {
    long student_number;
    char name[100];
    float score;
} Student;

Student students[STU_NUM];
int student_count = 0;

int Menu(void);
void ReadScore(void);
void AverSumofScore(void);
void StatisticAnalysis(void);
void PrintScore(void);

int main() {
    int itemSelected;
    
    printf("input student number (n<%d):\n", STU_NUM);
    scanf("%d", &student_count);
    
    while(1) {
        itemSelected = Menu();
        switch(itemSelected) {
            case 1:
                ReadScore();
                break;
            case 2:
                AverSumofScore();
                break;
            case 3:
                StatisticAnalysis();
                break;
            case 4:
                PrintScore();
                break;
            case 0:
                printf("End of program!\n");
                exit(0);
            default:
                printf("Input error!\n");
        }
    }
    return 0;
}

int Menu(void) {
    int itemSelected;
    printf("\nManagement for student's scores\n");
    printf("1-input record\n");
    printf("2-calculate total and average score of course\n");
    printf("3-statistic analysis\n");
    printf("4-list record\n");
    printf("0-exit\n");
    
    printf("please input your choice:");
    scanf("%d", &itemSelected);
    
    return itemSelected;
}

void ReadScore() {
	int i;
    for ( i = 0; i < student_count; i++) {
        printf("\nEnter student number for student %d: ", i + 1);
        scanf("%ld", &students[i].student_number);
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", students[i].name); 
        printf("Enter score for student %d: ", i + 1);
        scanf("%f", &students[i].score);  
    }
}

void AverSumofScore() {
	int i;
    int total = 0;
    for (i = 0; i < student_count; i++) {
        total += students[i].score;
    }
    float average = total / student_count;
    printf("sum= %d, aver= %.2f\n", total,average);
}

void StatisticAnalysis() {
    int i;
    int categories[6] = {0}; 
    for (i = 0; i < student_count; i++) {
        if (students[i].score == 100) categories[0]++;
        else if (students[i].score >= 90 && students[i].score < 100) categories[1]++;
        else if (students[i].score >= 80 && students[i].score < 90) categories[2]++;
        else if (students[i].score >= 70 && students[i].score < 80) categories[3]++;
        else if (students[i].score >= 60 && students[i].score < 70) categories[4]++;
        else categories[5]++;
    }
    printf("Fail     	<60     %d\t %.2f%%\n", categories[5], (float)categories[5] / student_count * 100);
    printf("Pass      	60-69   %d\t %.2f%%\n", categories[4], (float)categories[4] / student_count * 100);
    printf("Medium    	70-79   %d\t %.2f%%\n", categories[3], (float)categories[3] / student_count * 100);
    printf("Good      	80-89   %d\t %.2f%%\n", categories[2], (float)categories[2] / student_count * 100);
    printf("Very Good	90-99   %d\t %.2f%%\n", categories[1], (float)categories[1] / student_count * 100); // Adjusted range from "90-100" to "90-99"
    printf("Excellent	100     %d\t %.2f%%\n", categories[0], (float)categories[0] / student_count * 100);
}


void PrintScore() {
	int i;
    for (i = 0; i < student_count; i++) {
    printf("Student Number: %ld, Name: %s, Score: %.0f\n", students[i].student_number, students[i].name, students[i].score);
    }
}

