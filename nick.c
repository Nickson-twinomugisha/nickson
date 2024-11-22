#include<stdio.h>
#include<stdlib.h>
struct Student{
	char name[60];
	int index;
};
void addStudent(FILE*file);
void viewStudent(FILE*file);
int main(){
FILE*file;
int choice;
do{
	printf("\nClass List of 2024\n");
	printf("1.Add Student\n");
	printf("2.View Student\n");
	printf("3.Exit\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
switch(choice){
case 1:
	file=fopen("nickson.txt","a");
	if(file==NULL){
		printf("Error opening file!");
		return 1;}
		addStudent(file);
		fclose(file);
		break;
case 2:
	file=fopen("nickson.txt","r");
	if(file==NULL){
		printf("No data found!");
	}else{
		viewStudent(file);
		fclose;
	}
	break;
case 3:
	printf("Exiting program...");
default:
	printf("invalid input! Try again.");
	}
}while(choice!=3);
return 0;
}
void addStudent(FILE*file){
	struct Student student;
	printf("\nEnter student name: ");
	getchar();
	fgets(student.name,sizeof(student.name),stdin);
	printf("Enter student index number: \n");
	scanf("%d",&student.index);
	fprintf(file,"%s%d",student.name,student.index);
	printf("\nStudent added successfully.\n");
}
void viewStudent(FILE*file){
	struct Student student;
	printf("List of students:");
	printf("Name\t\t\t\t\t\t\t\t\t\tIndex");
	printf("--------------------------------------------------------\n");
	while(fgets(student.name,sizeof(student.name),file)!=NULL){
		fscanf(file,"%d\n",&student.index);
		printf("%s\t\t\t\t\t\t\t\t\t\t%d",student.name,student.index);
	}
}
