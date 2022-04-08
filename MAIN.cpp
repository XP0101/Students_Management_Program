#include"Header.h"
int num_staff = 0, num_lecturer = 0, num_student = 0, num_classes = 0, num_status = 0, num_student_in_course = 0, num_course_of_class = 0;
Staff_infor* staff;
Student_infor* student;
Lecturer_infor* lecturer;
Class_infor* Class;
infor_course_of_student* student_in_course;

int main() {
loop_main:;
	ifstream fi;
	fi.open("Database/Staff.txt");			// read file staff.txt
	if (!fi.is_open())
	{
		cout << "Can not open file Staff.txt";
		return 0;
	}
	else {
		Load_Data_Staff(fi);
		fi.close();
	}

	fi.open("Database/Lecturer.txt");				// read file Lecturer.txt
	if (!fi.is_open())
	{
		cout << "Can not open file Lecturer.txt";
		return 0;
	}
	else {
		Load_Data_lecturer(fi);
		fi.close();
	}


	fi.open("Database/Student.txt");				// read file student.txt
	if (!fi.is_open())
	{
		cout << "Can not open file Student.txt";
		return 0;
	}
	else {
		Load_Data_Student(fi);
		fi.close();
	}
	int choose;
	string Username_or_ID;
	string Password = "";
	char ch;
	bool check_pass = false;

	cout << "-------MENU------- " << endl;						
	cout << "Choose 1: Login" << endl;
	cout << "Choose 2: Exit" << endl;
	cout << "------------------" << endl;
	cout << "Your choice: ";
	cin >> choose;
	system("cls");
	if (choose != 1) return 0;
	if (choose == 1) {
		cout << "------- LOGIN -------" << endl;
		cout << "Username: ";
		cin.ignore();
		getline(cin, Username_or_ID);
		
	loop:;
		Password = "";
		cout << "Password: ";
		ch = _getch();
		while (ch != 13) {
			Password.push_back(ch);
			cout << '*';
			ch = _getch();
		}

	}


	if (Check_Login_Staff(Username_or_ID, Password) != -1)
	{
		int location = Check_Login_Staff(Username_or_ID, Password);
		Run_Staff(location);
		system("cls");
		goto loop_main;
		check_pass = true;
	}


	if (Check_Login_Lecturer(Username_or_ID, Password) != -1)
	{
		int location = Check_Login_Lecturer(Username_or_ID, Password);
		Run_Lecturer(location);
		system("cls");
		goto loop_main;
		check_pass = true;
	}



	if (Check_Login_Student(Username_or_ID, Password) != -1)
	{
		int location = Check_Login_Student(Username_or_ID, Password);
		Run_Student(location);
		system("cls");
		goto loop_main;
		check_pass = true;
	}


	if (check_pass == false)				// Neu sai nhap lai mat khau 
	{
		system("cls");
		cout << "Not correct !" << endl;
		cout << "Username: ";
		getline(cin, Username_or_ID);
		goto loop;
	}
	delete[]staff;
	delete[]student;
	delete[]lecturer;
	delete[]Class;
	return 0;
}