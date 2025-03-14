#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    float gpa;
} student;

void task1(){
    int n;
    scanf("%d", &n);
    
    student *students = malloc(n * sizeof(student));

    for (int i = 0; n - i; i++)
        scanf("%s%d%f", &students[i].name, &students[i].age, &students[i].gpa);

    printf("\n\n");
    while (n--)
        printf("Name: %s\nAge: %d\nGPA: %.2f\n\n", students[n].name, students[n].age, 
            students[n].gpa);

    free(students);
    return;
}

void task2(){
    typedef struct {
        char name[50];
        int quantity;
        float Price;
    } Item;

    int n;
    scanf("%d", &n);
    
    Item *Items = malloc(n * sizeof(Item));

    for (int i = 0; n - i; i++)
        scanf("%s%d%f", &Items[i].name, &Items[i].quantity, &Items[i].Price);

    printf("\n\n");
    while (n--)
        printf("Item: %s\nQuantity: %d\nPrice: %f\n\n", Items[n].name, 
            Items[n].quantity, Items[n].Price);

    free(Items);
    return;
}

void task3(){
    typedef struct{
        char event_name[50], description[50];
        int date, month, year;
    }Event;

    int n;
    scanf("%d", &n);

    Event *events = malloc(n * sizeof(Event));

    for (int i = 0; i - n; i++)
        scanf("%s%d%d%d%s", &events[i].event_name, &events[i].date, &events[i].month,
            &events[i].year, &events[i].description);
    
    printf("\n\n");

    while (n--)
    printf("Event:%s\nDate:%d %d %d\nDescription:%s\n\n", events[n].event_name,
        events[n].date, events[n].month, events[n].year, events[n].description);
    
    free(events);
    return;
}

void task4(){
    typedef struct{
        char name[50], position[50];
        float salary;
    }Employee;

    int n;
    scanf("%d", &n);

    Employee *employees = malloc(n * sizeof(Employee));

    for (int i = 0; i - n; i++)
        scanf("%s%s%f", &employees[i].name, &employees[i].position,
        &employees[i].salary);
    
    printf("\n\n");

    while (n--)
    printf("Name:%s\nPosition:%s\nSalary:%f\n\n", employees[n].name,
        employees[n].position, employees[n].salary);
    
    free(employees);
    return;
}

void task5(){
    typedef struct{
        int i;
        float f;
        char st[50];
    }Data;

    Data d;

    int n;
    scanf("%d", &n);

    switch (n){
        case 1:
            scanf("%d", &d.i);
            printf("Integer:%d\n", d.i);
            break;

        case 2:
            scanf("%f", &d.f);
            printf("Float:%f\n", d.f);
            break;

        case 3:
            scanf("%s", &d.st);
            printf("Srting:%s\n", d.st);
            break;

        default:
            printf("Error\n"); 
    }

    return;
}

void task6(){
    typedef struct {
        char brand[50];
        char model[50];
        int year;
        char engine[50];
    } Vehicle;

    int n;
    scanf("%d", &n);
    
    Vehicle *vehicles = malloc(n * sizeof(Vehicle));

    for (int i = 0; i < n; i++){
        scanf("%s %s %d %s", &vehicles[i].brand, &vehicles[i].model,
            &vehicles[i].year, &vehicles[i].engine);
        
        if (vehicles[i].engine != "Gasoline" && vehicles[i].engine != "Diesel" 
            && vehicles[i].engine != "Electric"){
            printf("Error");
            return;
        }
    }

    printf("\n\n");

    for (int i = 0; i < n; i++)
        printf("Vehicle: %s %s\nYear: %d\nEngine Type: %s\n\n", vehicles[i].brand, 
            vehicles[i].model, vehicles[i].year, vehicles[i].engine);

    free(vehicles);
    return;
}

void outputStudent(student *st){
    printf("Name: %s\nAge: %d\nGPA: %.2f\n\n", st -> name, st -> age, st -> gpa);

}

void task7(){
    int n;
    scanf("%d", &n);
    
    student *students = malloc(n * sizeof(student));

    for (int i = 0; n - i; i++)
        scanf("%s%d%f", &students[i].name, &students[i].age, &students[i].gpa);

    printf("\n\n");
    while (n--)
        outputStudent(&students[n]);

    free(students);
    return;
}

void task8() {
    //я не понял условия
    //поэтому сделел с вводом типа перед вводом оценки
    union Grade {
        int num;
        char cr;
    };

    int n;
    scanf("%d", &n);
    union Grade grades = malloc(n * sizeof(Grade));

    for (int i = 0; i - n; i++) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &grades[i].num);
            printf("Grade: %d\n", grades[i].num);
        }

        if (type == 2) {
            scanf(" %c", &grades[i].cr);
            printf("Grade: %c\n", grades[i].cr);
        }
    }

    return;
}

void task9(){
    typedef struct {
        float temp, hum;
        char con[50];
    } Weather;

    Weather we;

    scanf("%f%f%s", &we.temp, &we.hum, &we.con);

    if (con != "Sunny" && con != "Cloudy" && con != "Rainy"){
        printf("Error");
        return;
    }

    printf("Temperature: %f\nHumidity: %f%%\nCondition: %s", we.temp, we.hum, we.con);
    return;
}

void task10(){
    typedef struct{
        char name1[50], name2[50];
        int kr;
    }Course;

    int n;
    scanf("%d", &n);

    Course *courses = malloc(n * sizeof(Course));

    for (int i = 0; i - n; i++)
        scanf("%s%d%s", &courses[i].name1, &courses[i].kr, &courses[i].name2);
    
    printf("\n\n");

    while (n--)
    printf("Course:%s\nCredits:%d\nProfessor:%s\n\n", courses[n].name1,
        courses[n].kr, courses[n].name2);
    
    free(courses);
    return;
}

int main(){
    task8();
    return 0;
}