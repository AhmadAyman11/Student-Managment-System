#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
struct student
{
    int id;
    char name[30];
    int age;
    float gpa;
};

// Node structure for linked list
struct node
{
    struct student data;
	struct node *next;
};

// Head of the linked list
struct node *head=NULL;

// Function to add a student to the linked list
void addStudent(const struct student *const ptr)
{
    struct node *current=head;
    // Check for duplicate ID
    while(current!=NULL)
    {
        if(current->data.id==ptr->id)
        {
            printf("This id is already exist\n");
            return;
        }
        current=current->next;
    }
    // Allocate memory for new node and add student data
    struct node *link=(struct node *) malloc(sizeof(struct node));
    link->data.id=ptr->id;
    strcpy(link->data.name,ptr->name);
    link->data.age=ptr->age;
    link->data.gpa=ptr->gpa;
    link->next=NULL;

    // If the list is empty, make the new node the head
    if(head==NULL)
    {
        head=link;
        return;
    }
    current=head;

    while(current->next!=NULL)
    {
        current=current->next;
    }

    current->next=link;
}

// Function to display all student data
void displayStudents(void)
{
    struct node *current=NULL;
    // Check if the list is empty
    if (head==NULL)
    {
        printf("The list is empty\n");
        return;
    }
    current=head;
    printf("\t*That is All of data*\n");
    // Print student data
    while(current!=NULL)
    {
        printf("Your id:%d||",current->data.id);
        printf("Your name:%s||",current->data.name);
        printf("Your age:%d||",current->data.age);
        printf("Your gpa=%f\n",current->data.gpa);
        printf("***********\n");
        current=current->next;
    }
}

// Function to search for a student by ID
void searchStudentByID(int id)
{
    struct node *current=NULL;
    struct node *ptr=NULL;
    // Check if the list is empty
    if (head==NULL)
    {
        printf("The list is empty\n");
        return;
    }
    current=head;
    //find the student with the given ID
    while(current!=NULL)
    {
        if(current->data.id==id)
        {
            ptr=current;
            printf("The id:%d\n",current->data.id);
            printf("It`s name:%s\n",current->data.name);
            printf("It`s age:%d\n",current->data.age);
            printf("It`s gpa=%f\n",current->data.gpa);
        }
        current=current->next;
    }
    // ID not found
    if(ptr==NULL)
    {
        printf("This id:(%d) doesn`t exist in data\n",id);
        return;
    }
}

// Function to update student data by ID
void updateStudent(int id)
{
    struct node *current=NULL;
    struct node *ptr=NULL;
    // Check if the list is empty
    if (head==NULL)
    {
        printf("The list is empty\n");
        return;
    }
    current=head;
    // Find the student with the given ID
    while(current!=NULL)
    {
        if(current->data.id==id)
        {
            ptr=current;
            printf("The data of id %d:\n",id);
            printf("\t***Update in whatever you want in data***\n");
            printf("It`s name:");
            scanf("%s",current->data.name);
            printf("It`s age:");
            scanf("%d",&current->data.age);
            printf("It`s gpa=");
            scanf("%f",&current->data.gpa);
        }
        current=current->next;
    }
    // ID not found
    if(ptr==NULL)
    {
        printf("This id:(%d) doesn`t exist in data\n",id);
        return;
    }
}

// Function to calculate and display the average GPA
void calculateAverageGPA(void)
{
   int count=0;
   float sum=0;
   float average=0;
   struct node *current=NULL;
   // Check if the list is empty
    if (head==NULL)
    {
        printf("The list is empty\n");
        return ;
    }
    current=head;
    // Accumulate GPA values
    while(current!=NULL)
    {
        sum+=current->data.gpa;
        count++;
        current=current->next;
    }
    // Calculate average GPA
    average=sum/count;
    printf("The Average of GPA=%f\n",average);
}

// Function to search and display the student with the highest GPA
void searchHighestGPA(void)
{
    float max=0;
    struct node *current=NULL;
    struct node *ptr=NULL;
    // Check if the list is empty
    if (head==NULL)
    {
        printf("The list is empty\n");
        return;
    }
    current=head;
    // Find the highest GPA
    while(current!=NULL)
    {
        if(max<current->data.gpa)
        {
            max=current->data.gpa; //store highest GPA
            ptr=current; //point to data of highest GPA
        }
        current=current->next;
    }
    // Display the student with the highest GPA
    printf("***The highest GPA=(%f)***\n",max);
    printf("It`s id:%d\n",ptr->data.id);
    printf("It`s name:%s\n",ptr->data.name);
    printf("It`s age:%d\n",ptr->data.age);
}

// Function to delete a student by ID
void deleteStudent(int id)
{
    int pos=0;
    struct node *current=NULL;
    struct node *delete_node=NULL;
    struct node *prev=NULL;
    // Check if the list is empty
    if (head==NULL)
    {
        printf("The list is empty\n");
        return;
    }
    pos++;
    // Check if the student to be deleted is the head node
    if(head->data.id==id)
	{
		delete_node=head;
		head=head->next;
		free(delete_node);
		printf("The data of id:(%d) is found in position (%d) is deleted\n",id,pos);
		return;
	}
	// Delete the student that not in head node
	pos++;
	current=head->next;
	prev=head;
	while(current != NULL)
	{
		if(current->data.id==id)
		{
			delete_node = current;
			prev->next=current->next;
			free(delete_node);
			printf("The data of id:(%d) is found in position (%d) is deleted\n",id,pos);
			return;
		}
		prev=current;
		current=current->next;
		pos++;
	}
	// ID not found
	if(delete_node==NULL)
	{
		printf("This id:(%d) doesn`t exist in data\n",id);
	}
}

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

    struct student x; // Variable to hold student data input by the user
    int num; // Variable to hold the user's menu choice
    do
    {
        // Display menu options
        printf("-----------------------------------\n");
        printf("1)Add student data\n");
        printf("2)Display student data\n");
        printf("3)Search student by id\n");
        printf("4)Update in student data\n");
        printf("5)Display average GPA\n");
        printf("6)Display highest GPA data\n");
        printf("7)Delete student data\n");
        printf("8)Exit project\n");
        printf("Enter number of Process:");
        scanf("%d",&num);
        printf("-----------------------------------\n");
        // Handle invalid input
        if((num<1)||(num>8))
        {
            printf("*Wrong Input Statment*\n");
            continue;
        }
        // Perform actions based on user's choice
        if(num==1)
        {
            // Add new student data
            printf("Enter your id:");
            scanf("%d",&x.id);
            printf("Enter your name:");
            scanf("%s",x.name);
            printf("Enter your age:");
            scanf("%d",&x.age);
            printf("Enter your gpa:");
            scanf("%f",&x.gpa);
            addStudent(&x);
        }
        if(num==2)
        {
            // Display all student data
            displayStudents();
        }
        if(num==3)
        {
            // Search for student by ID
            printf("Enter id to display it`s data:");
            scanf("%d",&x.id);
            searchStudentByID(x.id);
        }
        if(num==4)
        {
            // Update student data
            printf("Enter id of data you want to update in:");
            scanf("%d",&x.id);
            updateStudent(x.id);
        }
        if(num==5)
        {
            // Display average GPA
            calculateAverageGPA();
        }
        if(num==6)
        {
            // Display student with the highest GPA
            searchHighestGPA();
        }
        if(num==7)
        {
            // Delete student data
            printf("Enter id of data you want to delete:");
            scanf("%d",&x.id);
            deleteStudent(x.id);
        }
        if(num==8)
        {
            // Exit the program
            printf("Exiting the project...");
            break;
        }
    }while((num>=1)||(num<=8));

}
