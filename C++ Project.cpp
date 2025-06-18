#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//Use classes or structs to store tasks, including the following details for each task
struct info
{
	int id;
	string title;
	string description;
	int deadline;
	char priority;
	string category;
	bool compelete;
};

const int MAX_TASKS = 100;
info tasks[MAX_TASKS];
int numTasks = 0;
void task(info& information)
{
	cout << "Enter your Id NO.: ";
	cin >> information.id;
	cout << "Enter your task title: ";
	cin >> information.title;
	cout << "Enter your task description: ";
	cin >> information.description;
	cout << "Enter your task deadline: ";
	cin >> information.deadline;
	cout << "Enter your task priority: ";
	cin >> information.priority;
	cout << "Enter your task category (Personal-Work-Study): ";
	cin >> information.category;
	cout << "Enter if your task completed or not (0 - 1): ";
	cin >> information.compelete;
}

//Add new tasks, including a title, description, deadline, and priority level.
void addTask() {
	if (numTasks < MAX_TASKS) {
		task(tasks[numTasks]);
		numTasks++;
	}
	else {
		cout << "Task list is full!" << endl;
	}
}


void Deadline(int deadline)
{
	cout << "Enter your deadline: ";
	cin >> deadline;
	int today;
	cout << "Enter the number of this day: ";
	cin >> today;
	if (today == deadline - 1)
	{
		cout << "Today in day number: " << today << ". Remeber your task, you have only one day to submit!" << endl;
	}
	else if (today == deadline)
	{
		cout << "Your task submission has been expired." << endl;
	}
	else
	{
		cout << "The deadline for your day in still after " << deadline - today << " days" << endl;
	}
}

//Mark tasks as complete or in progress.
void Statue(bool complete)
{
	string ti;
	cout << "Enter the title: ";
	cin >> ti;
	for (int i = 0; i < numTasks; ++i)
	{
		if (tasks[i].title == ti)
		{
			cout << "Task Found:" << endl;
			if (tasks[i].compelete == 0)
			{
				cout << "Title: " << tasks[i].title << " is in progress" << endl;
			}
			else
			{
				cout << "Title: " << tasks[i].title << " is completed" << endl;
				break;
			}
		}
		else
		{
			cout << "File is not found." << endl;
		}
	}
}

void viewTasksByDeadline() {
	for (int i = 0; i < numTasks; ++i) {
		cout << "Title: " << tasks[i].title << ", Deadline: " << tasks[i].deadline << endl;
	}
}

void viewTasksByPriority() {
	for (int i = 0; i < numTasks; ++i) {
		cout << "Title: " << tasks[i].title << ", Priority: " << tasks[i].priority << endl;
	}
}

void viewTasksByCategory() {
	for (int i = 0; i < numTasks; ++i) {
		cout << "Title: " << tasks[i].title << ", Category: " << tasks[i].category << endl;
	}
}
void searchTaskByTitle(const string& title) {
	string ti;
	cout << "Enter the title: ";
	cin >> ti;
	for (int i = 0; i < numTasks; ++i)
	{
		if (tasks[i].title == ti)
		{
			cout << "Task Found:" << endl;
			cout << "Title: " << tasks[i].title << ", Description: " << tasks[i].description << endl;
		}
		else
		{
			cout << "File is not found." << endl;
		}
	}
}
void savefile(string file)
{
	ofstream filename(file);
	if (filename.is_open())
	{
		for (int i = 0; i < numTasks; i++)
		{
			filename << numTasks << "." << endl;
			filename << "Id: " << tasks[i].id << endl;
			filename << "Tittle: " << tasks[i].title << endl;
			filename << "Description: " << tasks[i].description << endl;
			filename << "Deadline: " << tasks[i].deadline << endl;
			filename << "Priority: " << tasks[i].priority << endl;
			filename << "Category: " << tasks[i].category << endl;
			filename << "Compelete: " << tasks[i].compelete << endl;
			filename << "=================================" << endl;
		}
	}
	filename.close();
}

void loadfile(string file) {
	ifstream filename(file);
	if (filename.is_open()) {
		filename >> numTasks;
		for (int i = 0; i < numTasks; i++) {
			string temp;

			filename >> temp >> tasks[i].id;
			cout << "Id: " << tasks[i].id << endl;
			filename.ignore(); // To ignore the newline character after id

			getline(filename, tasks[i].title);

			cout << tasks[i].title << endl;

			getline(filename, tasks[i].description);

			cout << tasks[i].description << endl;
			filename.ignore(); // To ignore the newline character after priority
			filename >> tasks[i].deadline;
			cout << "Deadline: " << tasks[i].deadline << endl;

			filename >> tasks[i].priority;

			cout << "Priority: " << tasks[i].priority << endl;

			filename.ignore(); // To ignore the newline character after priority

			getline(filename, tasks[i].category);
			cout << "Category: " << tasks[i].category << endl;

			filename >> tasks[i].compelete;
			cout << "Compelete:  " << tasks[i].compelete << endl;
		}
		filename.close();
	}
	else {
		cout << "No file to open" << endl;
	}
}


int main()
{
	info information;
	const string filename = "task.txt";
	int choice;
	do {
		cout << "1. Add Task\n"
			<< "2. View Tasks by Deadline\n"
			<< "3. View Tasks by Priority\n"
			<< "4. View Tasks by Category\n"
			<< "5. Deadline\n"
			<< "6. Compelete\n"
			<< "7. Search for task\n"
			<< "8. Save data\n"
			<< "9. Load data\n"
			<< "10. Exit\n"
			<< "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			addTask();
			break;
		case 2:
			viewTasksByDeadline();
			break;
		case 3:
			viewTasksByPriority();
			break;
		case 4:
			viewTasksByCategory();
			break;
		case 5:
			Deadline(information.deadline);
			break;
		case 6:
			Statue(information.compelete);
			break;
		case 7:
			searchTaskByTitle(information.title);
			break;
		case 8:
			savefile("task.txt");
			cout << "The task is saved in external file." << endl;
			break;
		case 9:
			cout << "Your data: \n";
			cout << "==========\n";
			loadfile("task.txt");
			break;
		case 10:
			cout << "Exiting...." << endl;
			break;
		default:
			cout << "Invalid choice! Please enter again." << endl;
		}
		cout << "==========================================" << endl;
	} while (choice != 10);

}
