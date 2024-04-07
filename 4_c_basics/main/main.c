#include <stdio.h>
#include <string.h>

typedef struct Person_struct {
    char firstName[20];
    char lastName[20];
    int age;
} Person;

void updatePerson(Person *person) {
    strcpy(person->firstName, "Amit");
    strcpy(person->lastName, "Upadhyay");
    person->age = 27;
}

void exclaimString(char *phrase) {
    strcat(phrase, "!");
}

// printViaFunctionPtr accepts a function pointer with the signature defined in the arg
void printViaFunctionPtr(void (*PrintIt)(char *msg)) {
    char toPrint[30] = "Amit Upadhyay";
    PrintIt(toPrint);
}

void printMsg(char *name) {
    printf("this program is written by: %s\n", name);
}

void app_main(void) {
    Person person;
    updatePerson(&person);
    printf("Person: %s %s is %d years old\n", person.firstName, person.lastName, person.age);

    char phrase[30] = {"good job"};
    // passing the array is same as passing the address to first item in the array
    exclaimString(phrase);
    printf("%s\n", phrase);

    // function pointer example
    printViaFunctionPtr(printMsg);
}
