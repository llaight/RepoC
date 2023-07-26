#include <stdio.h>

struct Students
{
    int studentID;
    char Name[50];
    int age;
    float marks;
};
struct Students student[50];
int new_rec(int i, struct Students *student);
void display_rec();
int search_students(int i, struct Students *student);
int calculate(int i, struct Students *student);
void erase();

int main(){
    int choice;
    static int i = 0; //index
    
do{
    printf("\n");
    printf("Student Records Management\n");
    printf("1. Add a new student record\n");
    printf("2. Display the student record\n");
    printf("3. Search for students by their ID\n");
    printf("4. Calculate the average marks of all students\n");
    printf("5. Erase File\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            i = new_rec(i, student);
            break;
        case 2:
            display_rec();
            break;
        case 3:
            search_students(i, student);
            break;
        case 4:
            calculate(i, student);
            break;
        case 5:
            erase();
            break;


    }
}while(choice != 6 || choice > 6 || choice < 0);
return 0;

}

int new_rec(int i, struct Students *student){
    FILE *fp;
    fp = fopen("student_recs.txt", "a"); //append the file
    struct Students tempRec;
    static int tempID;
    tempID = i + 1;
    printf("\n");
    printf("ID number: %d", tempID);
    tempRec.studentID = tempID;

    getchar();

    printf("\nName: ");
    scanf("%[^\n]%*c", &tempRec.Name);

    printf("Age: ");
    scanf("%d", &tempRec.age);

    printf("Marks: ");
    scanf("%f", &tempRec.marks);

    //file
    fprintf(fp, "\n");
    fprintf(fp, "Student ID: %d\n", tempRec.studentID);
    fprintf(fp, "Student Name[ID: %d]: %s\n", tempRec.studentID, tempRec.Name);
    fprintf(fp, "Student Age[ID: %d]: %d\n", tempRec.studentID, tempRec.age);
    fprintf(fp, "Student Marks[ID: %d]: %.02f\n", tempRec.studentID, tempRec.marks);
    fprintf(fp, "\n");

    student[i] = tempRec;
    fclose(fp);
    i++;
    return i;

}

void display_rec(){
    printf("\n");
    FILE *fp;
    fp= fopen ("student_recs.txt", "r");
    if(fp != NULL){
        char c;
        while((c=fgetc(fp)) != EOF){
            putchar(c);
        };
        fclose(fp);
    }
    else{
        printf("Error opening file\n");
    }
}

int search_students(int i, struct Students *student){
    int search_ID;
    printf("\n");
    printf("Enter th ID of the student you want to search: ");
    scanf("%d", &search_ID);

    for (int seek = 0; seek < i; seek++)
    {
        if(student[seek].studentID == search_ID){
            printf("Student ID: %d\n", student[seek].studentID);
            printf("Student Name[ID: %d]: %s\n", student[seek].studentID, student[seek].Name);
            printf("Student Age[ID: %d]: %d\n", student[seek].studentID, student[seek].age);
            printf("Student Marks[ID: %d]: %.02f\n", student[seek].studentID, student[seek].marks);
        }
    };
}

int calculate(int i, struct Students *student){
    float total_marks = 0;
    float average_marks = 0;
    printf("\n");
    for(int seek = 0; seek < i; seek++){
        total_marks += student[seek].marks;
    }
    average_marks = total_marks / i;

    printf("Average marks of all students: %.02f\n", average_marks);
}

void erase(){
    printf("\n");
    FILE *fp;
    fp = fopen("student_recs.txt", "w+");
    fclose(fp);
    printf("File erased\n");
}