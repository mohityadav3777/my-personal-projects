#include <stdio.h>

struct student
{
    char name[30];
    int roll;
    float marks;
};

int main()
{
    FILE *fp;
    // FILE *check;
    int choice;
    struct student s;

    printf("--------Student Management System--------\n");
    do
    {
        printf("\nWhat Do You Want :\n");
        printf("1.Add Student \n");
        printf("2.Display Students \n");
        printf("3.Search Student \n");
        printf("4.Exit \n");
        printf("Enter Your choice :");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
        {
            int exist = 0;
            fp = fopen("student.txt", "a");

            if (fp == NULL)
            {
                printf("File Creation Failed!!\n");
                break;
            }

            printf("Enter Student Details :\n");
            printf("Enter Student's Name :");
            scanf(" %29[^\n]", s.name);
            printf("Enter Student's RollNo. :");
            scanf("%d", &s.roll);

            fp = fopen("student.txt", "r");
            if (fp != NULL)
            {
                struct student temp;

                while (fscanf(fp, " %29[^,],%d,%f",
                              temp.name,
                              &temp.roll,
                              &temp.marks) == 3)
                {
                    if (temp.roll == s.roll)
                    {
                        exist = 1;
                        break;
                    }
                }

                fclose(fp);
            }

            if (exist)
            {
                printf("Sorry! Student with Roll No %d already exists.\n",
                       s.roll);
            }
            else
            {
                fp = fopen("student.txt", "a");
                printf("Enter Student's Marks :");
                scanf("%f", &s.marks);
                fprintf(fp, "%s,%d,%.2f\n", s.name, s.roll, s.marks);
                fclose(fp);
                printf("Student added successfully!!\n");
            }

            break;
        }

        case 2:
        {
            fp = fopen("student.txt", "r");

            if (fp == NULL)
            {
                printf("Unable to open file!\n");
                break;
            }

            printf("\nStudents Details -\n");
            while (fscanf(fp, " %29[^,],%d,%f",
                          s.name,
                          &s.roll,
                          &s.marks) == 3)
            {
                printf("Name : %s\n", s.name);
                printf("Roll No. : %d\n", s.roll);
                printf("Marks : %.2f\n", s.marks);
                printf("\n");
            }

            fclose(fp);
            break;
        }

        case 3:
        {
            fp = fopen("student.txt", "r");
            int found = 0;

            if (fp == NULL)
            {
                printf("Unable to open file!\n");
                break;
            }

            int search;
            printf("Enter RollNo. of the student :");
            scanf("%d", &search);
            printf("\n-----Here are the details-----\n");
            while (fscanf(fp, " %29[^,],%d,%f",
                          s.name,
                          &s.roll,
                          &s.marks) == 3)
            {
                if (s.roll == search)
                {
                    printf("Name : %s\n", s.name);
                    printf("RollNo. : %d\n", s.roll);
                    printf("Marks : %.2f\n", s.marks);
                    found = 1;
                }
            }

            if (found == 0)
            {
                printf("No such student exist!\n");
            }

            fclose(fp);
            break;
        }

        case 4:
        {
            printf("Exited Successfully!!\n");
            break;
        }

        default:
        {
            printf("Wrong choice!! Enter a correct Number.");
        }
        }
    } while (choice != 4);

    return 0;
}