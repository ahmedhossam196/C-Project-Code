#include <stdio.h>
#include <stdlib.h>

// Define structure for student
struct student {
    int id;
    char name[50];
    float gpa;
    int age;
};

// Define structure for the node in the linked list
struct node {
    struct student data;
    struct node* next;
};

// Head of the linked list
struct node* head = NULL;

// Function prototypes
void addStudent(const struct student *const ptr);
void displaystudents(void);
void searchStudentByID(int id);
void updateStudent(int id);
void deletestudent(int id);
float calculateAverageGPA(void);
void searchHighestGpa(void);

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    int choice;

    while (1) {
        printf("\n    Student Management System   \n");
        printf("********************************************************\n");
        printf("1 - Add a Student\n");
        printf("2 - Display All Students\n");
        printf("3 - Search for a Student by ID\n");
        printf("4 - Update Student Information\n");
        printf("5 - Delete Student\n");
        printf("6 - Calculate Average GPA\n");
        printf("7 - Find Student with Highest GPA\n");
        printf("8 - Exit\n");
        printf("********************************************************\n");
        printf("Please enter your choice: ");
        // Validate choice input
               if (scanf("%d", &choice) != 1) {
                   printf("Invalid input! Please enter a valid number.\n");
                   // Clear input buffer
                   while (getchar() != '\n');
                   continue; // Skip the rest of the loop and prompt again
               }
        switch (choice) {
            case 1: {
                struct student new_student;
                printf("Enter Student ID: ");
                fflush(stdin);
                scanf("%d", &new_student.id);
                printf("Enter Student Name: ");
                fflush(stdin);
                gets(new_student.name);
                printf("Enter Student Age: ");
                fflush(stdin);
                scanf("%d", &new_student.age);
                printf("Enter Student GPA: ");
                fflush(stdin);
                scanf("%f", &new_student.gpa);
                addStudent(&new_student);
                break;
            }
            case 2:
                displaystudents();
                break;

            case 3: {
                int id;
                printf("The ID to search: ");
                scanf("%d", &id);

                searchStudentByID(id);
                break;
            }

            case 4: {
                int id;
                printf("Please enter the ID of the student to update: ");
                scanf("%d", &id);
                updateStudent(id);
                break;

            }
            case 5: {
            	int id;
            	printf("Enter the student id you want to delete ");
            	scanf("%d" , &id);

            	deletestudent(id);
            	break;
            }

            case 6: calculateAverageGPA();
                 break;

            case 7: searchHighestGpa();
                 break;

            case 8:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    }

    return 0;
}

void addStudent(const struct student *const ptr) {
    // Check if the list is empty
    if (head == NULL) {
        // Allocate memory for the new node
        struct node *new_node = (struct node*) malloc(sizeof(struct node));
        if (new_node == NULL) {
            printf("Error: Memory allocation failed. Unable to add student.\n");
            return;
        }

        // Copy student data into the new node
        new_node->data = *ptr;
        new_node->next = NULL;

        // Set the new node as the head
        head = new_node;
        return;
    }

    // Start from the head of the list
    struct node *current = head;

    // Traverse the list to check for a duplicate student ID
    while (current->next != NULL) {
        if (current->data.id == ptr->id) {
            printf("Error: ID already exists. Please enter a different ID.\n");
            return;
        }
        current = current->next; // Move to the next node
    }

    // Check the last node for a duplicate ID
    if (current->data.id == ptr->id) {
        printf("Error: ID already exists. Please enter a different ID.\n");
        return;
    }

    // Allocate memory for the new node
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: failed , Unable to add student.\n");
        return;
    }

    // Copy student data into the new node
    new_node->data = *ptr;
    new_node->next = NULL;

    // Link the last node to the new node
    current->next = new_node;
}


void displaystudents(void) {
    int student_num = 1; // Initialize a counter to track the number of students
    struct node *studentinfo = head; // Start at the head of the list

    // Check if the list is empty
    if (studentinfo == NULL) {
        printf("No students found\n"); // Print message if there are no students
        return; // Exit the function
    }

    // Traverse the linked list
    while (studentinfo != NULL) {
        // Print the student's information
        printf("Information for student number %d is : \n", student_num); // Student number
        printf("ID: %d\n", studentinfo->data.id); // Student ID
        printf("Name: %s\n", studentinfo->data.name); // Student name
        printf("Age: %d\n", studentinfo->data.age); // Student age
        printf("GPA: %f\n", studentinfo->data.gpa); // Student GPA
        printf("\n----------------------------------\n");

        student_num++; // Increment the student number
        studentinfo = studentinfo->next; // Move to the next node in the list
    }
}

void searchStudentByID(int id) {
    struct node *searchid = head;
    while (searchid != NULL) {
        if (searchid->data.id == id) {
            printf("Information for id number %d is :\n" , id);
            printf("ID: %d\n", searchid->data.id);
            printf("Name: %s\n", searchid->data.name);
            printf("Age: %d\n", searchid->data.age);
            printf("GPA: %f\n", searchid->data.gpa);
            printf("----------------------------------\n");
            return;
        }
        searchid = searchid->next;
    }
    printf("invalid ID!\n");
}


void updateStudent(int id) {
    struct node *updatedstudent = head;

    // Traverse the list to find the student with the given ID
    while (updatedstudent != NULL) {
        if (updatedstudent->data.id == id) {
            // Student found, prompt for new information
            printf("please update informations :\n");
            fflush(stdin);
            printf("New ID: ");
            scanf("%d", &updatedstudent->data.id);
            printf("New Name: ");
            fflush(stdin);
            gets(updatedstudent->data.name);
            printf("New Age: ");
            fflush(stdin);
            scanf("%d", &updatedstudent->data.age);
            printf("New GPA: ");
            fflush(stdin);
            scanf("%f", &updatedstudent->data.gpa);


            printf("Student information updated successfully.\n");
            return;
        }

        // Move to the next node
        updatedstudent = updatedstudent->next;
    }

    // If student with the given ID was not found
    printf("invalid ID!\n");
}





float calculateAverageGPA(void) {
    float totalgpa = 0.0; // To accumulate the total GPA
    int studentCount = 0; // To count the number of students
    struct node *ptrgpa = head; // Start at the head of the list

    // Check if the list is empty
    if (ptrgpa == NULL) {
        return 0.0; // Return 0.0 if no students are found
    }

    // Traverse the list to sum GPAs and count students
    while (ptrgpa != NULL) {
        totalgpa += ptrgpa->data.gpa; // Add current student's GPA to total
        studentCount++; // Increment the student count
        ptrgpa = ptrgpa->next; // Move to the next node
    }

    // Calculate average GPA
    float averageGPA;
      if (studentCount > 0) {
          averageGPA = totalgpa / studentCount; // Compute average GPA
      } else {
          averageGPA = 0.0; // Set average GPA to 0 if there are no students
      }

    // Print the average GPA
    printf("Average GPA is %f\n", averageGPA);

    // Return the average GPA
    return averageGPA;
}

void searchHighestGpa(void) {

    struct node *current = head;
    struct node *topgpa = head;

    if (topgpa == NULL) {
        printf("no student found\n");
        return;
    }
    while (current) {
        if (current->data.gpa > topgpa->data.gpa) {
            topgpa = current;
        }
        current = current->next;
    }

    printf("student with highest gpa:\n");
    printf("id: %d\n", topgpa->data.id);
    printf("name: %s\n", topgpa->data.name);
    printf("age: %d\n", topgpa->data.age);
    printf("gpa: %f\n", topgpa->data.gpa);
}


void deletestudent(int id) {
    struct node *current = head; // Start at the head of the list
    struct node *previous = NULL; // Pointer to keep track of the previous node
    struct node *nodetodelete = NULL; // Pointer to the node to be deleted

    // Check if the list is empty
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Check if the node to delete is the head node
    if (head->data.id == id) {
        nodetodelete = head;
        head = head->next;
        printf("student with ID %d deleted\n", id);
        free(nodetodelete);
        return;
    }

    // Traverse the list to find the node to delete
    previous = head;
    current = head->next;

    while (current != NULL) {
        if (current->data.id == id) {
            nodetodelete = current;
            previous->next = current->next;
            printf("student with ID %d found and deleted\n", id);
            free(nodetodelete);
            return;
        }
        previous = current;
        current = current->next;
    }

    // Node with the specified ID was not found
    printf("student with ID %d not found\n", id);
}


