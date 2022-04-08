#include"Header.h"
void View_profile_staff(int location);
void Import_class(ifstream& fi, Student_infor*& student_temp, int& num_student_temp);
void Save_Data_Staff(ofstream& fo);
void Division_Class(void);
void Creat_file_class(void);
void Add_new_student(Student_infor& student_new);
void Save_Student_new(ofstream& fo, Student_infor*& student_temp, int& num_student_temp);
void Manage_classes(void);
void View_Scoreboard_of_course(void);
void Change_password_staff(int location);

///////////////////////////////
void Manage_courses(void);
void Manage_lecturer(void);
void Load_lecturer_csv(ifstream& fi, Lecturer_infor*& Lec_temp, int& num_lec_temp);
void Manage_academic(void);
void Import_Schedule(void);
void Load_Course(ifstream& fi, int& num_course, course*& mon);
void Print_Date(ofstream& fo, course mon);
void Add_new_course(void);
void Remove_a_course(void);
void Remove_student_from_course(void);
void View_attendance_list_of_course(void);
void Add_student_from_course(void);
void View_students_of_course(void);
void Load_all_course(ifstream& fi, int& num_course_temp, string*& course_temp);
void View_list_course(void);
void Change_classA_to_classB(void);
void Edit_course(void);


void Run_Staff(int location) {
	int k;
loop2:;
	system("cls");
	cout << "Hello " << staff[location].fullname << " !" << endl;
	cout << "-----------------MENU----------------- " << endl;
	cout << "Choose 1: View profile information " << endl;
	cout << "Choose 2: Manage classes " << endl;
	cout << "Choose 3: Manage courses " << endl;
	cout << "Choose 4: View Scoreboard of a course" << endl;
	cout << "Choose 5: View attendance list" << endl;
	cout << "Choose 6: Change password" << endl;
	cout << "Choose 7: Logout" << endl;
	cout << "--------------------------------------" << endl;
	cout << "Your choice: ";
	cin >> k;
	switch (k)
	{
	case 1:
	{
		View_profile_staff(location);
		ofstream fo;
		fo.open("Database\\Staff.txt");
		Save_Data_Staff(fo);
		fo.close();
		goto loop2;
		break;
	}
	case 2:
	{
		Manage_classes();
		goto loop2;
		break;
	}
	case 3:
	{
		Manage_courses();
		goto loop2;
		break;
	}

	case 4:
	{
		View_Scoreboard_of_course();
		goto loop2;
		break;
	}
	case 5:
	{
		View_attendance_list_of_course();
		goto loop2;
		break;
	}
	case 6: {
		Change_password_staff(location);
		ofstream fo;
		fo.open("Database\\Staff.txt");
		Save_Data_Staff(fo);
		fo.close();
		goto loop2;
		break;
	}
	}
	return;
}
void View_profile_staff(int location)
{
	int k1, k2;
loop1:;
	system("cls");
	cout << "         Your profile information:" << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "Fullname: " << staff[location].fullname << endl;
	if (staff[location].sex == "1") cout << "Sex: Female" << endl;
	else cout << "Gender: Male" << endl;
	cout << "Job: " << staff[location].job << endl;
	cout << "Phone numbers: " << staff[location].phone_numbers << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "Choose 1: Edit your profile" << endl;
	cout << "Choose 2: Quits ! " << endl;
	cout << "Your choice: ";
	cin >> k1;
	if (k1 == 1) {
		system("cls");
		cout << "Edit your profile information :" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "Choose 1: Edit fullname" << endl;
		cout << "Choose 2: Edit gender" << endl;
		cout << "Choose 3: Edit job" << endl;
		cout << "Choose 4: Edit phone numbers" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "Your choice: ";
		cin >> k2;
		switch (k2) {
		case 1: {
			cout << "Enter fullname: ";
			cin.ignore();
			getline(cin, staff[location].fullname);
			goto loop1;

		}
		case 2: {
			cout << "-----------------------------------------------" << endl;
			cout << "Choose 0: Male" << endl;
			cout << "Choose 1: Female" << endl;
			cout << "Your choice: ";
			cin.ignore();
			getline(cin, staff[location].sex);
			goto loop1;
		}
		case 3: {
			cout << "Enter job: ";
			cin.ignore();
			getline(cin, staff[location].job);
			goto loop1;
		}
		case 4: {
			cout << "Enter phone numbers: ";
			cin.ignore();
			getline(cin, staff[location].phone_numbers);
			goto loop1;
		}
		}
	}
}
void Import_class(ifstream& fi, Student_infor*& student_temp, int& num_student_temp)
{
	string No;
	getline(fi, No);
	while (!fi.eof())
	{
		getline(fi, No, ',');
		getline(fi, student_temp[num_student_temp].ID, ',');
		getline(fi, student_temp[num_student_temp].fullname, ',');
		getline(fi, student_temp[num_student_temp].Dob.y, '-');
		getline(fi, student_temp[num_student_temp].Dob.m, '-');
		getline(fi, student_temp[num_student_temp].Dob.d, ',');
		getline(fi, student_temp[num_student_temp].sex, ',');
		getline(fi, student_temp[num_student_temp].Class, '\n');
		num_student_temp += 1;
	}
	num_student_temp -= 1;

}
void Save_Data_Staff(ofstream& fo)
{
	fo << num_staff << endl;
	for (int i = 0; i < num_staff; i++)
	{
		fo << staff[i].username << endl;
		fo << staff[i].password << endl;
		fo << staff[i].fullname << endl;
		fo << staff[i].sex << endl;
		fo << staff[i].job << endl;
		fo << staff[i].phone_numbers << endl << endl;
	}
}
void Division_Class() {
	ofstream fo;
	for (int i = 0; i < num_classes; i++) {
		fo.open(the_path(Class[i].name));
		fo << Class[i].num_status << endl;
		for (int j = 0; j < num_student; j++) {
			if (student[j].Class == Class[i].name) {
				fo << student[j].ID << endl;
				fo << student[j].fullname << endl;
				fo << student[j].Dob.d << "-" << student[j].Dob.m << "-" << student[j].Dob.y<<endl;
				fo << student[j].sex << endl;
				fo << student[j].Class << endl;
				fo << 1 << endl << endl;
			}
		}
		fo.close();
	}
}
void Creat_file_class() {
	ofstream fo;
	fo.open(the_path("Class"));
	fo << num_classes << endl;
	for (int i = 0; i < num_classes; i++) {
		fo<<Class[i].name<<endl;
	}
	fo.close();
}
void Add_new_student(Student_infor &student_new) {
	int l;
	ifstream fi;
	fi.open("Database\\Class.txt");
	Load_Data_Class(fi);
	fi.close();
	cout << "Add a new student to a class" << endl;
	cout << "-------------------------------------" << endl;
	cout << "Enter fullname: ";
	cin.ignore();
	getline(cin, student_new.fullname);
	cout << "Enter ID: ";
loopa:;
	cin >> student_new.ID;
	for (int i = 0; i < num_student; i++) {
		if (student[i].ID == student_new.ID) {
			cout << "Student ID is exists! "<<endl;
			cout << "Enter ID again: ";
			goto loopa;
			
		}
	}
	cout << "Enter Dob (dd-mm-yyyy): " << endl;
	cout << "dd: ";
	cin >> student_new.Dob.d;
	cout << "mm: ";
	cin >> student_new.Dob.m;
	cout << "yyyy: ";
	cin >> student_new.Dob.y;
	cout << "Enter sex: ";
	cin >> student_new.sex;
	cout << "Choose Class: " << endl;
	cout << "-------- List Class -------" << endl;
	for (int i = 0; i < num_classes; i++) {
		cout << i + 1 << ". " << Class[i].name << endl;
	}
	cout << "---------------------------" << endl;
	cout << "Your choice: ";
	cin >> l;
	student_new.Class = Class[l - 1].name;
	student_new.password = Password(student_new.Dob);
	return;
}
void Save_Student_new(ofstream& fo, Student_infor*& student_temp, int& num_student_temp)
{
	fo << num_student_temp << endl;
	for (int i = 0; i < num_student_temp-1; i++)
	{
		fo << student_temp[i].ID << endl;
		fo << Password(student_temp[i].Dob) << endl;
		fo << student_temp[i].fullname << endl;
		fo << student_temp[i].Dob.y << "-" << student_temp[i].Dob.m << "-" << student_temp[i].Dob.d << endl;
		fo << student_temp[i].Class << endl;
		fo << student_temp[i].sex << endl;
		fo << 1 << endl << endl;
	}
}
void Manage_classes(void)
{
	int k;
loop5:;
	system("cls");
	cout << "Manage Classes " << endl;
	cout << "--------------------------MENU------------------------------" << endl;
	cout << "Choose 1: Import students" << endl;
	cout << "Choose 2: Add a new student to a class" << endl;
	cout << "Choose 3: Edit an existing student" << endl;
	cout << "Choose 4: Remove a student" << endl;
	cout << "Choose 5: Change students from class A to class B" << endl;
	cout << "Choose 6: View list of classes" << endl;
	cout << "Choose 7: View list of students in a class" << endl;
	cout << "Choose 8: Quits! " << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "Your choice: ";
	cin >> k;
	switch (k)
	{
	case 1: {

		int tong = 0;
		cout << "Enter number of classes: ";
		cin >> num_classes;
		Class = new Class_infor[num_classes + 1];
		for (int i = 0; i < num_classes; i++)
		{
			cout << "Name class " << i + 1 << ": ";
			cin >> Class[i].name;
			cout << "The number of students in " << Class[i].name << ": ";
			cin >> Class[i].num_students;
			Class[i].num_status = Class[i].num_students;
		}
		cout << "Total number of students: ";
		cin >> tong;
		cin.ignore();
		string path;
	loop4:;
		cout << "Enter the path : ";
		getline(cin, path);
		ifstream fi;
		Student_infor* student_temp;

		student_temp = new Student_infor[30];
		int num_student_temp = 0;
		fi.open(path);
		if (!fi.is_open())
		{
			cout << "Can not open file .csv !" << endl;
			goto loop4;
			return;
		}
		else {
			Import_class(fi, student_temp, num_student_temp);
			fi.close();
			cout << "Import successfully !" << endl;
			cout << "Success: " << num_student_temp << "/" << tong << endl;
			num_status = num_student_temp;
		}
		ofstream fo;
		fo.open("Database\\Student.txt");
		Save_Data_Students(fo, student_temp, num_student_temp);
		fo.close();
		fi.open("Database\\Student.txt");
		Load_Data_Student(fi);
		fi.close();
		Division_Class();
		Creat_file_class();
		system("pause");
		goto loop5;
		break;
	}
	case 2: {
		system("cls");
		Student_infor student_new;
		Add_new_student(student_new);
		ofstream fo;
		num_student += 1;
		fo.open("Database\\Student.txt");
		Save_Student_new(fo, student, num_student);
		fo << student_new.ID << endl;
		fo << Password(student_new.Dob) << endl;
		fo << student_new.fullname << endl;
		fo << student_new.Dob.y << "-" << student_new.Dob.m << "-" << student_new.Dob.d << endl;
		fo << student_new.Class << endl;
		fo << student_new.sex << endl;
		fo << 1 << endl << endl;
		fo.close();
		ifstream fi;
		fi.open("Database\\Student.txt");
		Load_Data_Student(fi);
		int n = 0;
		Student_infor* s;
		fi.close();
		fi.open(the_path(student_new.Class));
		fi >> n;
		fi.ignore();
		s = new Student_infor[n];
		for (int i = 0; i < n; i++) {
			getline(fi, s[i].ID);
			getline(fi, s[i].fullname);
			getline(fi, s[i].Dob.d, '-');
			getline(fi, s[i].Dob.m, '-');
			getline(fi, s[i].Dob.y, '\n');
			getline(fi, s[i].sex);
			getline(fi, s[i].Class);
			getline(fi, s[i].status);
			fi.ignore();
		}
		fi.close();
		fo.open(the_path(student_new.Class));
		fo << n + 1 << endl;
		for (int i = 0; i < n; i++) {
			fo << s[i].ID << endl << s[i].fullname << endl << s[i].Dob.d << "-" << s[i].Dob.m << "-" << s[i].Dob.y << endl;
			fo << s[i].sex << endl << s[i].Class << endl << s[i].status << endl << endl;
		}
		fo << student_new.ID << endl << student_new.fullname << endl << student_new.Dob.d << "-" << student_new.Dob.m << "-" << student_new.Dob.y << endl;
		fo << student_new.sex << endl << student_new.Class << endl << "1" << endl;
		fo.close();
		cout << "Add successfully!" << endl;
		delete[]s;
		system("pause");
		goto loop5;
		break;
	}
	case 3: {
	loops:;
		system("cls");
		string ID;
		int k1, k2;
		cout << "-------------------------------" << endl;
		cout << "    Edit an existing student  " << endl;
		cout << "-------------------------------" << endl;
		cout << "Enter ID: ";
		cin >> ID;
		int kt = -1;
		for (int i = 0; i < num_student; i++) {
			if (ID == student[i].ID) {
				system("cls");
				cout << "---------------------------------------" << endl;
				cout << "           Profile information  " << endl;
				cout << "---------------------------------------" << endl;
				cout << "Fullname: " << student[i].fullname << endl;
				cout << "ID: " << student[i].ID << endl;
				cout << "Gende: " << student[i].sex << endl;
				cout << "Dob: " << student[i].Dob.d << "-" << student[i].Dob.m << "-" << student[i].Dob.y << endl;
				cout << "Class: " << student[i].Class << endl;
				kt = i;
				break;
			}
		}
		if (kt == -1) {
			cout << "-------------------------------" << endl;
			cout << "ID doesn't exists" << endl;
			cout << "Choose 1: Enter again! " << endl;
			cout << "Choose 2: Quits!" << endl;
			cout << "-------------------------------" << endl;
			cout << "Your choice: ";
			cin >> k1;
			if (k1 == 1) goto loops;
			else goto loop5;
		}
		cout << "---------------------------------------" << endl;
		cout << "Choose 1: Edit profile " << endl;
		cout << "Choose 2: Quits!" << endl;
		cout << "Your choise: ";
		cin >> k1;
		if (k1 != 1) {
			goto loop5;
		}
		else {
		loop_1:;
			system("cls");
			cout << "---------------------------------------" << endl;
			cout << "           Profile information  " << endl;
			cout << "---------------------------------------" << endl;
			cout << "Fullname: " << student[kt].fullname << endl;
			cout << "ID: " << student[kt].ID << endl;
			cout << "Gende: " << student[kt].sex << endl;
			cout << "Dob: " << student[kt].Dob.d << "-" << student[kt].Dob.m << "-" << student[kt].Dob.y << endl;
			cout << "Class: " << student[kt].Class << endl;
			cout << "---------------------------------------" << endl;
			cout << "     Edit your profile information  " << endl;
			cout << "---------------------------------------" << endl;
			cout << "Choose 1: Edit Fullname " << endl;
			cout << "Choose 2: Edit Gende " << endl;
			cout << "Choose 3: Edit Dob" << endl;
			cout << "Choose 4: Quits! " << endl;
			cout << "---------------------------------------" << endl;
			cout << "Your choise: ";
			cin >> k2;
			switch (k2)
			{
			case 1: {
				cout << "Enter Fullname: ";
				cin.ignore();
				getline(cin, student[kt].fullname);
				goto loop_1;
				break;
			}
			case 2: {
				cout << "Enter Gende: ";
				cin.ignore();
				getline(cin, student[kt].sex);
				goto loop_1;

				break;
			}
			case 3: {
				cout << "Enter Dob (dd-mm-yyyyy): " << endl;
				cout << "dd: ";
				cin >> student[kt].Dob.d;
				cout << "mm: ";
				cin >> student[kt].Dob.m;
				cout << "yyyy: ";
				cin >> student[kt].Dob.y;
				goto loop_1;
				break;
			}
			}
		}
		ofstream fo;
		fo.open("Database\\Student.txt");
		Save_Data_Students(fo,student,num_student);
		fo.close();
		int n = 0;
		Student_infor* s;
		ifstream fi;
		fi.open(the_path(student[kt].Class));
		fi >> n;
		fi.ignore();
		s = new Student_infor[n];
		for (int i = 0; i < n; i++) {
			getline(fi, s[i].ID);
			getline(fi, s[i].fullname);
			getline(fi, s[i].Dob.d, '-');
			getline(fi, s[i].Dob.m, '-');
			getline(fi, s[i].Dob.y, '\n');
			getline(fi, s[i].sex);
			getline(fi, s[i].Class);
			getline(fi, s[i].status);
			fi.ignore();
		}
		fi.close();
		fo.open(the_path(student[kt].Class));
		fo << n<<endl;
		for (int i = 0; i < n; i++) {
			if (s[i].ID != student[kt].ID) {
				fo << s[i].ID << endl << s[i].fullname << endl << s[i].Dob.d << "-" << s[i].Dob.m << "-" << s[i].Dob.y << endl;
				fo << s[i].sex << endl << s[i].Class << endl << s[i].status << endl << endl;
			}
			else {
				fo << student[kt].ID << endl << student[kt].fullname << endl << student[kt].Dob.d << "-" << student[kt].Dob.m << "-" << student[kt].Dob.y << endl;
				fo << student[kt].sex << endl << student[kt].Class << endl << student[kt].status << endl << endl;
			}	
		}
		fo.close();
		goto loop5;
		break;
	}
	case 4: {
		string ID;
		int a1,a2;
	loop_2:;
		system("cls");
		cout << "------------------------------" << endl;
		cout << "        Remove a student" << endl;
		cout << "------------------------------" << endl;
		cout << "Enter ID: ";
		cin >> ID;
		int kt1 = -1;
		for (int i = 0; i < num_student; i++) {
			if (ID == student[i].ID) {
				system("cls");
				cout << "---------------------------------------" << endl;
				cout << "           Profile information  " << endl;
				cout << "---------------------------------------" << endl;
				cout << "Fullname: " << student[i].fullname << endl;
				cout << "ID: " << student[i].ID << endl;
				cout << "Gende: " << student[i].sex << endl;
				cout << "Dob: " << student[i].Dob.d << "-" << student[i].Dob.m << "-" << student[i].Dob.y << endl;
				cout << "Class: " << student[i].Class << endl;
				kt1 = i;
				break;
			}
		}
		if (kt1 != -1) {
			cout << "---------------------------------------" << endl;
			cout << "Are you sure to remove student ?" << endl;
			cout << "Choose 1: Yes" << endl;
			cout << "Choose 2: No" << endl;
			cout << "---------------------------------------" << endl;
			cout << "Your choice: ";
			cin >> a1;
			if (a1 == 1) {
				ofstream fo;
				fo.open("Database\\Student.txt");
				fo << num_student - 1<<endl;
				for (int j = 0; j < num_student; j++) {
					if (j == kt1)continue;
					else {
						fo << student[j].ID<<endl;
						fo << Password(student[j].Dob) << endl;
						fo << student[j].fullname << endl;
						fo << student[j].Dob.y << "-" << student[j].Dob.m << "-" << student[j].Dob.d << endl;
						fo << student[j].Class << endl;
						fo << student[j].sex << endl;
						fo << 1 << endl << endl;
					}
				}
				fo.close();
				ifstream fi;
				int n = 0;
				Student_infor* s;
				fi.open(the_path(student[kt1].Class));
				fi >> n;
				fi.ignore();
				s = new Student_infor[n];
				for (int i = 0; i < n; i++) {
					getline(fi, s[i].ID);
					getline(fi, s[i].fullname);
					getline(fi, s[i].Dob.d, '-');
					getline(fi, s[i].Dob.m, '-');
					getline(fi, s[i].Dob.y, '\n');
					getline(fi, s[i].sex);
					getline(fi, s[i].Class);
					getline(fi, s[i].status);
					fi.ignore();
				}
				fi.close();
				fo.open(the_path(student[kt1].Class));
				fo << n-1 << endl;
				for (int i = 0; i < n; i++) {
					if (s[i].ID != student[kt1].ID) {
						fo << s[i].ID << endl << s[i].fullname << endl << s[i].Dob.d << "-" << s[i].Dob.m << "-" << s[i].Dob.y << endl;
						fo << s[i].sex << endl << s[i].Class << endl << s[i].status << endl << endl;
					}
				}
				fo.close();
				fi.open("Database\\Student.txt");
				Load_Data_Student(fi);
				fi.close();
				cout << "Successfully!" << endl;
				system("pause");
			}
			else {
				goto loop_2;
			}
		}
		else {
			cout << "---------------------------------------" << endl;
			cout << "ID does't exists" << endl;
			cout << "Choose 1: Enter ID again" << endl;
			cout << "Choose 2: Quits !" << endl;
			cout << "---------------------------------------" << endl;
			cout << "Your choice: ";
			cin >> a2;
			if (a2 == 1) {
				goto loop_2;
			}
		}
			goto loop5;
			break;
		}
	case 5: {
		Change_classA_to_classB();			
		goto loop5;
		break;
	}     
	case 6: {
		ifstream fi;
		fi.open("Database\\Class.txt");
		Load_Data_Class(fi);
		fi.close();
		system("cls");
		cout << "View list of classes" << endl;
		cout << "-------------- List class -------------" << endl;
		for (int i = 0; i < num_classes; i++) {
			cout << i + 1 << ". " << Class[i].name << endl;
		}
		cout << "---------------------------------------" << endl;

		system("pause");
		goto loop5;
		break;
	}
	case 7: {
		ifstream fi;
		int e;
		fi.open("Database\\Class.txt");
		Load_Data_Class(fi);
		fi.close();

		system("cls");
		cout << "View list of students in a class" << endl;
		cout << "------------------------------------------" << endl;
		cout << "Choose class: " << endl;
		for (int i = 0; i < num_classes; i++) {
			cout << i + 1 << ". " << Class[i].name << endl;
		}
		cout << "------------------------------------------" << endl;
		cout << "Your choice: ";
		cin >> e;
		int n = 0;
		Student_infor* s;
		fi.open(the_path(Class[e-1].name));
		fi >> n;
		fi.ignore();
		s = new Student_infor[n];
		for (int i = 0; i < n; i++) {
			getline(fi, s[i].ID);
			getline(fi, s[i].fullname);
			getline(fi, s[i].Dob.d, '-');
			getline(fi, s[i].Dob.m, '-');
			getline(fi, s[i].Dob.y, '\n');
			getline(fi, s[i].sex);
			getline(fi, s[i].Class);
			getline(fi, s[i].status);
			fi.ignore();
		}
		fi.close();
		int max = 18;
		max += 6;
		system("cls");
		cout << "View list of students in a class" << endl;
		cout << "------------------------------------------" << endl;
		cout << "No.    ID student        Fullname              Date of birth       Gender " << endl;
		for (int i = 0; i < n; i++) {
			cout << i + 1;
			if (i < 9) cout << "       ";
			else cout << "      ";
			cout << s[i].ID << "        ";
			cout << s[i].fullname;
			for (int j = 0; j < max - s[i].fullname.length(); j++)cout << " ";
			cout<< s[i].Dob.d << "-" << s[i].Dob.m << "-" << s[i].Dob.y << "          " << s[i].sex << endl;
		}
		cout << "Numbers students: " << n << endl;
		system("pause");
		goto loop5;
		break; 
	}
	}
	
}
void Change_classA_to_classB(void) {
	string ID;
	int a1, a2;
loop_2:;
	system("cls");
	cout << "Change students from class A to class B: " << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Enter ID: ";
	cin >> ID;
	int kt1 = -1;
	for (int i = 0; i < num_student; i++) {
		if (ID == student[i].ID) {
			system("cls");
			cout << "---------------------------------------" << endl;
			cout << "           Profile information  " << endl;
			cout << "---------------------------------------" << endl;
			cout << "Fullname: " << student[i].fullname << endl;
			cout << "ID: " << student[i].ID << endl;
			cout << "Gende: " << student[i].sex << endl;
			cout << "Dob: " << student[i].Dob.d << "-" << student[i].Dob.m << "-" << student[i].Dob.y << endl;
			cout << "Class: " << student[i].Class << endl;
			kt1 = i;
			break;
		}
	}
	if (kt1 != -1) {
		int a;
		cout << "---------------------------------------" << endl;
		cout << "Do you want to change class ?" << endl;
		cout << "Choose 1: Yes" << endl;
		cout << "Choose 2: No" << endl;
		cout << "---------------------------------------" << endl;
		cout << "Your choice: ";
		cin >> a1;
		if (a1 == 1) {
			ifstream fi;
			fi.open("Database\\Class.txt");
			Load_Data_Class(fi);
			fi.close();
			cout << "-------------- Class new --------------" << endl;
			for (int i = 0; i < num_classes; i++) {
				cout << i + 1 << ". " << Class[i].name << endl;
			}
			cout << "---------------------------------------" << endl;
			cout << "Your choice: ";
			cin >> a2;
			int n = 0;
			Student_infor* s;
			fi.open(the_path(student[kt1].Class));
			fi >> n;
			fi.ignore();
			s = new Student_infor[n];
			for (int i = 0; i < n; i++) {
				getline(fi, s[i].ID);
				getline(fi, s[i].fullname);
				getline(fi, s[i].Dob.d, '-');
				getline(fi, s[i].Dob.m, '-');
				getline(fi, s[i].Dob.y, '\n');
				getline(fi, s[i].sex);
				getline(fi, s[i].Class);
				getline(fi, s[i].status);
				fi.ignore();
			}
			fi.close();
			ofstream fo;
			fo.open(the_path(student[kt1].Class));
			fo << n - 1 << endl;
			for (int i = 0; i < n; i++) {
				if (s[i].ID != student[kt1].ID) {
					fo << s[i].ID << endl << s[i].fullname << endl << s[i].Dob.d << "-" << s[i].Dob.m << "-" << s[i].Dob.y << endl;
					fo << s[i].sex << endl << s[i].Class << endl << s[i].status << endl << endl;
				}
			}
			fo.close();
			delete[]s;
			student[kt1].Class = Class[a2 - 1].name;
			fo.open("Database\\Student.txt");
			fo << num_student << endl;
			for (int j = 0; j < num_student; j++) {
					fo << student[j].ID << endl;
					fo << Password(student[j].Dob) << endl;
					fo << student[j].fullname << endl;
					fo << student[j].Dob.y << "-" << student[j].Dob.m << "-" << student[j].Dob.d << endl;
					fo << student[j].Class << endl;
					fo << student[j].sex << endl;
					fo << 1 << endl << endl;
			}
			fo.close();
			
			Student_infor* sk;
			fi.open(the_path(student[kt1].Class));
			fi >> n;
			fi.ignore();
			sk = new Student_infor[n];
			for (int i = 0; i < n; i++) {
				getline(fi, sk[i].ID);
				getline(fi, sk[i].fullname);
				getline(fi, sk[i].Dob.d, '-');
				getline(fi, sk[i].Dob.m, '-');
				getline(fi, sk[i].Dob.y, '\n');
				getline(fi, sk[i].sex);
				getline(fi, sk[i].Class);
				getline(fi, sk[i].status);
				fi.ignore();
			}
			fi.close();
		fo.open(the_path(student[kt1].Class));
			fo << n + 1 << endl;
			for (int i = 0; i < n; i++) {
				if (s[i].ID != student[kt1].ID) {
					fo << s[i].ID << endl << s[i].fullname << endl << s[i].Dob.d << "-" << s[i].Dob.m << "-" << s[i].Dob.y << endl;
					fo << s[i].sex << endl << s[i].Class << endl << s[i].status << endl << endl;
				}
			}
			fo << student[kt1].ID << endl << student[kt1].fullname << endl << student[kt1].Dob.d << "-" << student[kt1].Dob.m << "-" << student[kt1].Dob.y << endl << student[kt1].sex << endl << student[kt1].Class << endl << 1 << endl << endl;
			fo.close();
			delete[]s;

			fi.open("Database\\Student.txt");
			Load_Data_Student(fi);
			fi.close();
			cout << "Successfully!" << endl;
			system("pause");
		}
		else {
			return;
		}
	}
	else {
		cout << "---------------------------------------" << endl;
		cout << "ID does't exists" << endl;
		cout << "Choose 1: Enter ID again" << endl;
		cout << "Choose 2: Quits !" << endl;
		cout << "---------------------------------------" << endl;
		cout << "Your choice: ";
		cin >> a2;
		if (a2 == 1) {
			goto loop_2;
		}
	}

}
void View_Scoreboard_of_course(void) {
	string s, s1, s2, s3;
	ifstream fi;
	int choose1, choose2;
	fi.open("Database\\Class.txt");
	Load_Data_Class(fi);
	fi.close();
	find_years_and_semester(s1, s2);
	system("cls");
	cout << "View Scoreboard of a course: " << endl;
	cout << "-----------------------------------" << endl;
	cout << "----------- List Classes ----------" << endl;
	for (int i = 0; i < num_classes; i++) {
		cout << i + 1 << ". " << Class[i].name << endl;
	}
	cout << "-----------------------------------" << endl;
	cout << "Choose Class: ";
	cin >> choose1;
	s = Class[choose1 - 1].name;
	string name_file = "Database\\" + s1 + "-" + s2 + "-Schedule-" + s + ".txt";
	int num;
	course* b;
	fi.open(name_file);
	Load(fi, num, b);
	fi.close();
	system("cls");
	cout << "View Scoreboard of a course " << endl;
	cout << "-----------------------------------" << endl;
	cout << "----------- List courses ----------" << endl;
	for (int i = 0; i < num; i++) {
		cout << i + 1 << ". " << b[i].ID << endl << "   " << b[i].course_name << endl << "   " << b[i].class_name << endl << endl;
	}
	cout << "-----------------------------------" << endl;
	cout << "Choose course: ";
	cin >> choose2;
	s3 = "Database\\" + s1 + "-" + s2 + "-" + s + "-" + b[choose2 - 1].ID + "-Student" + ".txt";
	infor_course_of_student* a;
	fi.open(s3);
	if (!fi.is_open()) {
		cout << "Can not open file! ";
		system("pause");
		return;
	}
	Load_infor_course_of_student(fi, num, a);
	system("cls");
	cout << "View Scoreboard of a course " << endl;
	cout << "-----------------------------------" << endl;
	cout << "Course name: " << b[choose2 - 1].course_name << endl;
	cout << "Course ID: " << b[choose2 - 1].ID << endl;
	cout << "Class: " << b[choose2 - 1].class_name << endl;
	cout << "Room: " << b[choose2 - 1].room << endl;
	cout << b[choose2 - 1].start_hour << ":" << b[choose2 - 1].start_minute << " -> " << b[choose2 - 1].end_hour << ":" << b[choose2 - 1].end_minute << endl;
	cout << "-----------------------------------" << endl;
	int max = 12;
	for (int i = 0; i < num; i++) {
		if (max < a[i].name_student.length()) max = a[i].name_student.length();
	}
	cout << "No.  ID student    Fullname                  Midterm     Final     Bonus     Total" << endl;
	for (int i = 0; i < num; i++) {
		cout << i + 1 << ".";
		if (i <= 8)cout << "   ";
		else cout << "  ";
		cout << a[i].ID << "      " << a[i].name_student;
		if (27 > a[i].name_student.length()) {
			for (int j = 0; j < 27 - a[i].name_student.length(); j++) cout << " ";
		}
		cout << a[i].Midtem << "         " << a[i].Final << "        " << a[i].Bonus << "        " << a[i].Total << endl;
	}
	cout << "-----------------------------------" << endl;
	cout << "Do you want to export list to a csv file ?" << endl;
	cout << "1. YES           2.NO" << endl << "Your choice: ";
	cin >> max;
	if (max == 1) {
		ofstream fo;
		string l="D:\\Final_Project\\Scoreboard-"+s1+"-"+s2+"-"+b[choose2-1].class_name+"-"+b[choose2-1].course_name+".csv";
		fo.open(l);
		fo << "No,ID student,Fullname,Midterm,Final,Bonus,Total" << endl;
		for (int i = 0; i < num; i++) {
			fo << i + 1 << "," << a[i].ID << "," << a[i].name_student << "," << a[i].Midtem << "," << a[i].Final << "," << a[i].Bonus << "," << a[i].Total << endl;
		}
		fo.close();
		cout << "Export successfully!" << endl;
	}
	system("pause");
	return;
}
void Change_password_staff(int location) {
	string s1,s2,s3;
	char ch;
	int tk=0;
	looppw:;
	system("cls");
	cout << "Change passwords " << endl;
	cout << "------------------------" << endl;
	cout << "Enter your password: ";
	ch = _getch();
	s1 = "";
	while (ch != 13) {
		s1.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	cout << endl;
	if (s1 != staff[location].password) {
		cout << "------------------------" << endl;
		cout << "Incorrect password!" << endl;
		cout << "Choose 1: Enter again" << endl;
		cout << "Choose 2: Quits! " << endl;
		cout << "------------------------" << endl;
		cout << "Your choice: ";
		cin >> tk;
		if (tk == 1) goto looppw;
		else return;
	}
	else {
		cout << endl;
		s2 = ""; s3 = "";
		cout << "New password: ";
		ch = _getch();
		while (ch != 13) {
			s2.push_back(ch);
			cout << '*';
			ch = _getch();
		}
		cout << endl;
		cout << "Confirm new password: ";
		ch = _getch();
		while (ch != 13) {
			s3.push_back(ch);
			cout << '*';
			ch = _getch();
		}
		cout << endl;

		if (s3 != s2) {
			cout << "------------------------" << endl;
			cout << "Incorrect new password!" << endl;
			cout << "Choose 1: Enter again" << endl;
			cout << "Choose 2: Quits! " << endl;
			cout << "------------------------" << endl;
			cout << "Your choice: ";
			cin >> tk;
			if (tk == 1) goto looppw;
		
		}
		else {
			staff[location].password = s2;
			cout << "------------------------" << endl;
			cout << "Change password successfully! " << endl;
		}
	}
	system("pause");
	return;
}

//////////////////////////////////////////////////////////////////////////////
void Manage_courses(void) {
	int q;
loopss:;
	system("cls");
	cout << "Manage courses" << endl;
	cout << "--------------------------MENU------------------------------" << endl;
	cout << "Choose 1: Manage academic years and semesters" << endl;
	cout << "Choose 2: Import courses" << endl;
	cout << "Choose 3: Add a new course " << endl;
	cout << "Choose 4: Edit an existing course" << endl;
	cout << "Choose 5: Remove a course" << endl;
	cout << "Choose 6: Remove a specific student from a course" << endl;
	cout << "Choose 7: Add a specific student to a course" << endl;
	cout << "Choose 8: View list of courses in the current semester" << endl;
	cout << "Choose 9: View list of students of a course" << endl;
	cout << "Choose 10: View attendance list of a course" << endl;
	cout << "Choose 11: Manage lecturer" << endl;
	cout << "Choose 12: Quits!" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "Your choice: ";
	cin >> q;
	switch (q)
	{
	case 1:{
		Manage_academic();
		goto loopss;
		break;
	}
	case 2: {
		Import_Schedule();
		goto loopss;
		break;
	}
	case 3: {
		Add_new_course();
		goto loopss;
		break;
	}
	case 4: {						
		Edit_course();	
		goto loopss;
		break;
	}
	case 5: {
		Remove_a_course();
		goto loopss;
		break;
	}
	case 6: {
		Remove_student_from_course();
		goto loopss;
		break;
	}
	case 7: {
		Add_student_from_course();
		goto loopss;
		break;
	}
	case 8: {
		View_list_course();												
		goto loopss;
		break;
	}
	case 9: {
		View_students_of_course();
		goto loopss;
		break;
	}
	case 10: {
		View_attendance_list_of_course();
		goto loopss;
		break;
	}
	case 11: {
		Manage_lecturer();
		goto loopss;
		break;
	}
	}
	return;
}
void Edit_course() {
	string s, s1, s2, s3;
	ifstream fi;
	int choose1, choose2;
	fi.open("Database\\Class.txt");
	Load_Data_Class(fi);
	fi.close();
	find_years_and_semester(s1, s2);
	system("cls");
	cout << "Edit an existing course: " << endl;
	cout << "-----------------------------------" << endl;
	cout << "----------- List Classes ----------" << endl;
	for (int i = 0; i < num_classes; i++) {
		cout << i + 1 << ". " << Class[i].name << endl;
	}
	cout << "-----------------------------------" << endl;
	cout << "Choose Class: ";
	cin >> choose1;
	s = Class[choose1 - 1].name;
	string name_file = "Database\\" + s1 + "-" + s2 + "-Schedule-" + s + ".txt";
	int num;
	course* b;
	fi.open(name_file);
	Load(fi, num, b);
	fi.close();
	system("cls");
	cout << "Edit an existing course: " << endl;
	cout << "-----------------------------------" << endl;
	cout << "----------- List courses ----------" << endl;
	for (int i = 0; i < num; i++) {
		cout << i + 1 << ". " << b[i].ID << endl << "   " << b[i].course_name << endl << "   " << b[i].class_name << endl << endl;
	}
	cout << "-----------------------------------" << endl;
	cout << "Choose course: ";
	cin >> choose2;
	int k;
loop:;
	system("cls");
	cout << "-----------------------------------" << endl;
	cout << "         Information course " << endl;
	cout << "-----------------------------------" << endl;
	cout << " Course name: " << b[choose2 - 1].course_name << endl;
	cout << " Class: " << b[choose2 - 1].class_name << endl;
	cout << " Start date: " << b[choose2 - 1].start_date.d << "-" << b[choose2 - 1].start_date.m << "-" << b[choose2 - 1].start_date.y << endl;
	cout << " End date: "<< b[choose2 - 1].end_date.d << "-" << b[choose2 - 1].end_date.m << "-" << b[choose2 - 1].end_date.y << endl;
	cout << " Day of Week: " << b[choose2 - 1].day_of_week << endl;
	cout << " Time: " << b[choose2 - 1].start_hour << ":" << b[choose2 - 1].start_minute << " -> " << b[choose2 - 1].end_hour << ":" << b[choose2 - 1].end_minute << endl;
	cout << "-----------------------------------" << endl;
	cout << " Choose 1: Edit course" << endl;
	cout << " Choose 2: Quit!" << endl;
	cout << "Your choice: ";
	cin >> k;
	if (k == 1) {
		int k1;
		cout << "-----------------------------------" << endl;
		cout << "Edit course: " << endl;
		cout << "-----------------------------------" << endl;
		cout << " Choose 1: Edit Course name" << endl;
		cout << " Choose 2: Edit Start date" << endl;
		cout << " Choose 3: Edit End date" << endl;
		cout << " Choose 4: Edit Day of Week" << endl;
		cout << " Choose 5: Edit Time" << endl;
		cout << "-----------------------------------" << endl;
		cout << "Your choice: ";
		cin >> k1;
		switch (k1)
		{
		case 1: {
			cout << "-----------------------------------" << endl;
			cout << "Enter Course name: ";
			cin.ignore();
			getline(cin, b[choose2 - 1].course_name);
			goto loop;
			break;

		}
		case 2: {
			cout << "-----------------------------------" << endl;
			cout << " Enter Start Date: " << endl;
			cout << "dd: ";
			cin >> b[choose2 - 1].start_date.d;
			cout << "mm: ";
			cin >> b[choose2 - 1].start_date.m;
			cout << "yyyy: ";
			cin >> b[choose2 - 1].start_date.y;
			goto loop;
			break;
		}
		case 3: {
			cout << "-----------------------------------" << endl;
			cout << "Enter End Date: " << endl;
			cout << "dd: ";
			cin >> b[choose2 - 1].end_date.d;
			cout << "mm: ";
			cin >> b[choose2 - 1].end_date.m;
			cout << "yyyy: ";
			cin >> b[choose2 - 1].end_date.y;
			goto loop;
			break;
		}
		case 4: {
			cout << "-----------------------------------" << endl;
			cout << "Enter Day of Week: " ;
			cin>> b[choose2 - 1].day_of_week;
			goto loop;
			break;
		}
		case 5: {
			cout << "-----------------------------------" << endl;
			cout << "Time: " << endl;
			cout << "Enter Start hour: ";
			cin >> b[choose2 - 1].start_hour;
			
			cout << "Enter Start minute: ";
			cin >> b[choose2 - 1].start_minute;
			
			cout << "Enter End hour:";
			cin >> b[choose2 - 1].end_hour;

			cout << "Enter End minute: ";
			cin >> b[choose2 - 1].end_minute;
		
			goto loop;
			break;
		}
		}

	}
	else {
		int k2;
		cout << "Do you want to save information course ? " << endl;
		cout << "1. YES           2.NO" << endl;
		cout << "Your choice: ";
		cin >> k2;
		if (k2 == 1) {
			ofstream fo;
			fo.open(name_file);
			Save(fo, num, b);
			fo.close();
			string file1 = "Database\\" + b[choose2].class_name + ".txt";
			string file2 = "Database\\" + s1 + "-" + s2 + "-" + s + "-" + b[choose2-1].ID + "-Student.txt";
			
			string s3;
			fi.open(file1);
			fo.open(file2);
			fi >> num;
			fi.ignore();
			fo << num << endl;
			for (int i = 0; i < num; i++) {
				getline(fi, s3);
				fo << s3 << endl;
				getline(fi, s3);
				fo << s3 << endl;
				getline(fi, s3);
				fo << s3 << endl;
				getline(fi, s3);
				fo << s3 << endl;
				getline(fi, s3);
				fo << s3 << endl;
				getline(fi, s3);
				fo << s3 << endl;
				getline(fi, s3);
				fo << s3;
				fo << -1 << endl << -1 << endl << -1 << endl << -1 << endl;
				Print_Date(fo, b[choose2-1]);
			}
			fo.close();
			cout << "Successfully!" << endl;
		}
	}
	system("pause");
	return;
}
void Manage_lecturer() {
	int q;
	string s;
	loop_lec:;
	system("cls");
	cout << "Manage lecturer" << endl;
	cout << "---------------MENU-----------------" << endl;
	cout << "Choose 1: Import lecturer" << endl;
	cout << "Choose 2: Add a lecturer" << endl;
	cout << "Choose 3: Remove a lecturer" << endl;
	cout << "Choose 4: View all lecturers" << endl;
	cout << "Choose 5: Quits!" << endl;
	cout << "------------------------------------" << endl;
	cout << "Your choice: ";
	cin >> q;
	switch (q)
	{
	case 1: {
		Lecturer_infor* lec_temp;
		lec_temp = new Lecturer_infor[10];
		int num_lec_temp = 0;
		system("cls");
		cout << "Import lecturer" << endl;
		cout << "----------------------------" << endl;
		cout << "Enter the path : " << endl;
	loopw:;
		cin.ignore();
		getline(cin, s);
		ifstream fi;
		fi.open(s);
		if (!fi.is_open()) {
			cout << "Can not open file !" << endl;
			cout << "Enter the path again: ";
			goto loopw;
		}
		else {
			Load_lecturer_csv(fi, lec_temp, num_lec_temp);
			fi.close();
			ofstream fo;
			fo.open("Database\\Lecturer.txt");
			Save_Data_Lecturer(fo, lec_temp, num_lec_temp);
			fi.open("Database\\Lecturer.txt");
			Load_Data_lecturer(fi);
			cout << "Iport successfully!" << endl;
			fo.close();
			system("pause");
		}
		goto loop_lec;
		break;
	}
	case 2: {
		Lecturer_infor temp;
		int num_lec_temp = 0;
		system("cls");
		cout << "Add a lecturer" << endl;
		cout << "----------------------------" << endl;
		cout << "Enter fullname: ";
		cin.ignore();
		getline(cin, temp.fullname);
		cout << "Enter username: ";
		cin.ignore();
		getline(cin, temp.username);
		temp.password = "123456";
		cout << "Enter degree: ";
		getline(cin, temp.degree);
		cout << "Enter gender: "<<endl;
		cout << "Choose 1:Male        Choose 2: Female" << endl;
		cout << "Your choice: ";
		getline(cin, temp.sex);
		ofstream fo;
		fo.open("Database\\Lecturer.txt");
		fo << num_lecturer+1 << endl;
		for (int i = 0; i < num_lecturer; i++) {
			fo <<lecturer[i].username << endl;
			fo << lecturer[i].password << endl;
			fo << lecturer[i].fullname << endl;
			fo << lecturer[i].degree << endl;
			if (lecturer[i].sex == "Male") {
				fo << 0 << endl;
			}
			else {
				fo << 1 << endl;
			}
			fo << endl;
		}
		fo << temp.username << endl;
		fo << temp.password << endl;
		fo << temp.fullname << endl;
		fo << temp.degree << endl;
		fo << temp.sex << endl << endl;
		fo.close();
		ifstream fi;
		fi.open("Database\\Lecturer.txt");
		Load_Data_lecturer(fi);
		fi.close();
		cout << "Add successfully! " << endl;
		system("pause");
		goto loop_lec;
		break;
	}
	case 3: {
		int t,q;
		system("cls");
		cout << "Remove a Lecturer" << endl;
		cout << "------------------------------------" << endl;
		cout << "Lecturers list " << endl;
		for (int i = 0; i < num_lecturer; i++){
			cout << i+1 << ".  " << lecturer[i].fullname << endl;
		}
		cout << "------------------------------------" << endl;
		cout << "Your choice: ";
		cin >> t;
		cout << "Are you sure to delete this lecturer" << endl;
		cout << "1. YES           2. NO" << endl;
		cout << "Your choice: ";
		cin >> q;
		if (q == 1) {
			ofstream fo;
			fo.open("Database\\Lecturer.txt");
			fo << num_lecturer - 1 << endl;
			for (int i = 0; i < num_lecturer; i++) {
				if (i == t - 1) { continue; }
				else {
					fo << lecturer[i].username << endl;
					fo << lecturer[i].password << endl;
					fo << lecturer[i].fullname << endl;
					fo << lecturer[i].degree << endl;
					if (lecturer[i].sex == "Male") {
						fo << 0 << endl;
					}
					else {
						fo << 1 << endl;
					}
					fo << endl;
				}
			}
			fo.close();
			cout << "Delete successfully! " << endl;
			ifstream fi;
			fi.open("Database\\Lecturer.txt");
			Load_Data_lecturer(fi);
			fi.close();
			system("pause");
		}
		goto loop_lec;
		break;
	}
	case 4: {
		system("cls");
		cout << "View all lecturers" << endl;
		cout << "------------------------------------" << endl;
		for (int i = 0; i < num_lecturer; i++) {
			cout << i + 1 << ". Fullname: " << lecturer[i].fullname<<endl;
			cout << "   Degree: " << lecturer[i].degree << endl;
			cout << "   Gender: ";
			if (lecturer[i].sex == "1") {
				cout << "Male"<<endl;
			}
			else{
				cout << "Female" << endl;
			}
			cout << endl;
		}
		cout << "------------------------------------" << endl;
		system("pause");
		goto loop_lec;
		break;
	}
	}
}
void Load_lecturer_csv(ifstream &fi,Lecturer_infor*& Lec_temp,int & num_lec_temp) {
	string No;
	getline(fi, No);
	while (!fi.eof()) {
		getline(fi, No, ',');
		getline(fi, Lec_temp[num_lec_temp].username, ',');
		getline(fi, Lec_temp[num_lec_temp].password, ',');
		getline(fi, Lec_temp[num_lec_temp].fullname, ',');
		getline(fi, Lec_temp[num_lec_temp].degree, ',');
		getline(fi, Lec_temp[num_lec_temp].sex, '\n');
		num_lec_temp += 1;
	}
	num_lec_temp -= 1;
	return;
}
void Manage_academic(void) {
	int q;
	loopz:;
	system("cls");
	cout << "Manage academic years and semesters" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "Choose 1: Creat academic years new " << endl;
	cout << "Choose 2: Update semesters" << endl;
	cout << "Choose 3: View academic years" << endl;
	cout << "Choose 4: Quits! " << endl;
	cout << "--------------------------------------------" << endl;
	cout << "Your choice: ";
	cin >> q;
	switch (q)
	{
	case 1:{
		string s1, s2;
		int a;
		system("cls");
		cout << "Creat academic years new" << endl;
		cout << "--------------------------------------------" << endl;
		cout << "Years: ";
		cin.ignore();
		getline(cin, s1);
		ifstream fi;
		fi.open("Database\\Semester.txt");
		fi >> a;
		fi.ignore();
		string *years;
		string* s;
		s = new string[a];
		years = new string[a];

		for (int i = 0; i < a; i++) {
			getline(fi, years[i]);
			getline(fi, s[i]);
			fi.ignore();
		}
		fi.close();
		ofstream fo;
		fo.open("Database\\Semester.txt");
		fo << a+1 << endl;
		fo << s1 << endl;
		fo << "HK1" << endl<<endl;
		for (int i = 0; i < a; i++) {
			fo << years[i] << endl;
			fo << s[i] << endl << endl;
		}
		fo.close();
		cout << "Successfully! " << endl;
		system("pause");
		delete []s;
		goto loopz;
		break;
	}
	case 2: {
		string s1, s2;
		int a;
		ifstream fi;
		fi.open("Database\\Semester.txt");
		fi >> a;
		fi.ignore();
		string *years;
		string* s;
		s = new string[a];
		years = new string[a];
		
		for (int i = 0; i < a; i++) {
			getline(fi,years[i]);
			getline(fi, s[i]);
			fi.ignore();
		}
		fi.close();
		string t;
		t = s[0][2];
		int sum = stoi(t);
		ofstream fo("Database\\Semester.txt");
		fo << a+1 << endl;
		fo << years[0] << endl;
		fo << "HK" << sum + 1 << endl << endl;
		for (int i = 0; i < a; i++) {
			fo << years[i] << endl;
			fo << s[i] << endl << endl;
		}
		fo.close();
		cout << "Successfully! " << endl;
		system("pause");
		delete[]s;

		goto loopz;
		break;
	}
	case 3: {
		string s1, s2;
		int a;
		ifstream fi;
		fi.open("Database\\Semester.txt");
		fi >> a;
		fi.ignore();
		string *years;
		string* s;
		s = new string[a];
		years = new string[a];

		for (int i = 0; i < a; i++) {
			getline(fi, years[i]);
			getline(fi, s[i]);
			fi.ignore();
		}
		fi.close();
		system("cls");
		cout << "View academic years" << endl;
		cout << "--------------------------------------------" << endl;
		for (int i = a - 1; i >= 0; i--) {
			cout << "Years:    " << years[i] << endl;
			cout << "Semester: " << s[i] << endl << endl;
		}
		system("pause");
		delete[]s;
		goto loopz;
		break;
	}
	}

}
void Import_Schedule(void) {
	string s,s1,s2,s3,path;
	ifstream fi;
	int choose;
	fi.open("Database\\Class.txt");
	Load_Data_Class(fi);
	fi.close();
	system("cls");
	cout << "Import schedule: "<<endl;
	cout << "-----------------------------" << endl;
	for (int i = 0; i < num_classes; i++) {
		cout << i + 1 << ". " << Class[i].name << endl;
	}
	cout << "-----------------------------" << endl;
	cout << "Choose Class: ";
	cin >> choose;
	s = Class[choose - 1].name;
	cout << "Enter the path: ";
	cin.ignore();
	loopq:;
	getline(cin, path);
	find_years_and_semester(s1, s2);
	string name_file = "Database\\" +s1+ "-" + s2 + "-Schedule-" + s + ".txt";
	int num_course = 0;
	course* mon = new course[5];
	ofstream fo;
	fo.open(name_file);
	fi.open(path);
	if (!fi.is_open()) {
		cout << "Can not open file! " << endl;
		cout << "Enter the path again: ";
		goto loopq;
	}
	else {
		Load_Course(fi, num_course, mon);
	}
	fi.close();
	fo << num_course << endl;
	for (int i = 0; i < num_course; i++) {
		fo << mon[i].ID << endl;
		fo << mon[i].course_name << endl;
		fo << mon[i].class_name << endl;
		fo << mon[i].lecturer_name << endl;
		fo << mon[i].users_name << endl;
		fo << mon[i].start_date.d << "-" << mon[i].start_date.m << "-" << mon[i].start_date.y << endl;
		fo << mon[i].end_date.d << "-" << mon[i].end_date.m << "-" << mon[i].end_date.y << endl;
		fo << mon[i].day_of_week << endl;
		fo << mon[i].start_hour << " "<<mon[i].start_minute<<endl;
		fo << mon[i].end_hour << " " << mon[i].end_minute << endl;
		fo << mon[i].room << endl<<endl;
	}
	fo.close();
	string z="Database\\"+s+".txt";
	string zz = "Database\\"+s1+"-"+s2+"-"+"Allcourses.txt";
	int num;
	int num_course_temp;
	string* courses_temp;
	fi.open(zz);
	if (!fi.is_open()) {
		fi.close();
		ofstream fo;
		fo.open(zz);
		fo << num_course << endl;
		for (int i = 0; i < num_course; i++) {
			fo <<s1<<"-"<<s2<<"-"<<s << "-" << mon[i].ID<<"-"<<"Student" << endl;
		}
	}
	else {
		Load_all_course(fi, num_course_temp, courses_temp);
		fi.close();
		fo.open(zz);
		fo << num_course_temp + num_course << endl;
		for (int i = 0; i < num_course_temp; i++) {
			fo << courses_temp[i] << endl;
		}
		for (int i = 0; i < num_course; i++) {
			fo << s1 << "-" << s2 << "-" << s << "-" << mon[i].ID<<"-"<<"Student"<< endl;
		}
		fo.close();

	}
	for (int i = 0; i < num_course; i++) {
		string file = "Database\\" + s1 + "-" + s2 + "-" + s + "-" + mon[i].ID + "-Student.txt";
		fi.open(z);
		fi >> num;
		fi.ignore();
		fo.open(file);
		fo << num << endl;
		for (int j = 0; j < num; j++) {
			getline(fi, s3);
			fo << s3 << endl;
			getline(fi, s3);
			fo << s3 << endl;
			getline(fi, s3);
			fo << s3 << endl;
			getline(fi, s3);
			fo << s3 << endl;
			getline(fi, s3);
			fo << s3 << endl;
			getline(fi, s3);
			fo << s3 << endl;
			getline(fi, s3);
			fo << s3;
			fo << -1 << endl << -1 << endl << -1 << endl << -1 << endl;
			Print_Date(fo, mon[i]);

		}
		fo.close();
		fi.close();
	}
	

	cout << "Successfully!" << endl;
	


	
	system("pause");
}
void find_years_and_semester(string& s1, string& s2) {
	ifstream fi;
	fi.open("Database/Semester.txt");
	getline(fi, s1);
	getline(fi,s1);
	getline(fi, s2);
	fi.close();
	return;
}
void Load_Course(ifstream& fi, int& num_course, course*& mon) {
	string No;
	getline(fi, No);
	while (!fi.eof()) {
		getline(fi, No, ',');
		getline(fi, mon[num_course].ID, ',');
		getline(fi, mon[num_course].course_name, ',');
		getline(fi, mon[num_course].class_name, ',');
		getline(fi, mon[num_course].lecturer_name, ',');
		getline(fi, mon[num_course].users_name, ',');
		getline(fi, mon[num_course].start_date.d, '/');
		getline(fi, mon[num_course].start_date.m, '/');
		getline(fi, mon[num_course].start_date.y, ',');
		getline(fi, mon[num_course].end_date.d, '/');
		getline(fi, mon[num_course].end_date.m, '/');
		getline(fi, mon[num_course].end_date.y, ',');
		getline(fi, mon[num_course].day_of_week, ',');
		getline(fi, mon[num_course].start_hour, ',');
		getline(fi, mon[num_course].start_minute, ',');
		getline(fi, mon[num_course].end_hour, ',');
		getline(fi, mon[num_course].end_minute, ',');
		getline(fi, mon[num_course].room, '\n');
		num_course += 1;
	}
	num_course -= 1;
	return;
}
void Load(ifstream& fi, int& num, course*& b) {
	fi >> num;
	fi.ignore();
	b = new course[num];
	for (int i = 0; i < num; i++) {
		getline(fi, b[i].ID);
		getline(fi, b[i].course_name);
		getline(fi, b[i].class_name);
		getline(fi, b[i].lecturer_name);
		getline(fi, b[i].users_name);
		getline(fi, b[i].start_date.d, '-');
		getline(fi, b[i].start_date.m, '-');
		getline(fi, b[i].start_date.y, '\n');
		getline(fi, b[i].end_date.d, '-');
		getline(fi, b[i].end_date.m, '-');
		getline(fi, b[i].end_date.y, '\n');
		getline(fi, b[i].day_of_week);
		getline(fi, b[i].start_hour, ' ');
		getline(fi, b[i].start_minute, '\n');
		getline(fi, b[i].end_hour, ' ');
		getline(fi, b[i].end_minute, '\n');
		getline(fi, b[i].room);
		fi.ignore();
	}
	return;
}
void Save(ofstream& fo, int num, course* b) {
	fo << num << endl;
	for (int i = 0; i < num; i++) {
		fo << b[i].ID << endl << b[i].course_name << endl << b[i].class_name << endl << b[i].lecturer_name << endl;
		fo << b[i].users_name << endl << b[i].start_date.d << "-" << b[i].start_date.m << "-" << b[i].start_date.y << endl;
		fo << b[i].end_date.d << "-" << b[i].end_date.m << "-" << b[i].end_date.y << endl;
		fo << b[i].day_of_week << endl << b[i].start_hour << " " << b[i].start_minute << endl;
		fo << b[i].end_hour << " " << b[i].end_minute << endl;
		fo << b[i].room << endl << endl;
	}
	return;
}
void Print_Date(ofstream& fo, course mon) {
	fo << mon.start_date.d << " " << mon.start_date.m << " " << mon.start_date.y << " " << mon.start_hour << " " << mon.start_minute << " " << mon.end_hour << " " << mon.end_minute <<" "<<"-1"<< endl;
	int ng = stoi(mon.start_date.d);
	int th = stoi(mon.start_date.m);
	int nam = stoi(mon.start_date.y);
	int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0)) {
		a[2] = 29;
	}
	for (int t = 0; t < 9; t++) {
		ng += 7;
		if (ng > a[th]) {
			ng = ng - a[th];
			th += 1;
		}
		if (th > 12) {
			th = 1;
			nam += 1;
		}
		fo<<ng<<" "<<th<<" "<<nam<<" "<< mon.start_hour << " " << mon.start_minute << " " << mon.end_hour << " " << mon.end_minute<<" " << "-1" << endl;
	}
	fo << endl;
}
void Add_new_course(void) {
	string s,s1,s2;
	ifstream fi;
	int choose;
	fi.open("Database\\Class.txt");
	Load_Data_Class(fi);
	fi.close();
	find_years_and_semester(s1, s2);
	course a;
	system("cls");
	cout << "Add new a course: " << endl;
	cout << "-----------------------------" << endl;
	for (int i = 0; i < num_classes; i++) {
		cout << i + 1 << ". " << Class[i].name << endl;
	}
	cout << "Choose Class: ";
	cin >> choose;
	s = Class[choose - 1].name;
	string name_file = "Database\\" + s1 + "-" + s2 + "-Schedule-" + s + ".txt";
	cout << "-----------------------------" << endl;
	cout << "Enter information:" << endl;
	cout << "-----------------------------" << endl;
	cout << "Course ID: ";
	cin.ignore();
	getline(cin, a.ID);
	cout << "Course Name: ";
	getline(cin, a.course_name);
	cout << "Lecturer name: ";
	getline(cin, a.lecturer_name);
	cout << "Lecturer account: ";
	getline(cin, a.users_name);
	cout << "Start date: "<<endl;
	cout << "Day: ";
	getline(cin, a.start_date.d);
	cout << "Month: ";
	getline(cin, a.start_date.m);
	cout << "Years: ";
	getline(cin, a.start_date.y);
	cout << "End date: "<<endl;
	cout << "Day: ";
	getline(cin, a.end_date.d);
	cout << "Month: ";
	getline(cin, a.end_date.m);
	cout << "Years: ";
	getline(cin, a.end_date.y);
	cout << "Day of week: ";
	getline(cin, a.day_of_week);
	cout << "Start hour: ";
	getline(cin, a.start_hour);
	cout << "Start minute: ";
	getline(cin, a.start_minute);
	cout << "End hour: ";
	getline(cin, a.end_hour);
	cout << "End minute: ";
	getline(cin, a.end_minute);
	cout << "Room: ";
	getline(cin, a.room);
	int num;
	course* b;
	fi.open(name_file);
	Load(fi, num, b);
	fi.close();
	ofstream fo;
	num += 1;
	fo.open(name_file);
	Save(fo, num, b);
	fo << a.ID << endl << a.course_name << endl << s << endl << a.lecturer_name << endl;
	fo << a.users_name << endl << a.start_date.d << "-" << a.start_date.m << "-" << a.start_date.y << endl;
	fo << a.end_date.d << "-" << a.end_date.m << "-" << a.end_date.y << endl;
	fo << a.day_of_week << endl << a.start_hour << " " << a.start_minute << endl;
	fo << a.end_hour << " " << a.end_minute << endl;
	fo << a.room << endl << endl;
	fo.close();
	string file1 = "Database\\"+ s + ".txt";
	string file2 = "Database\\" + s1 + "-" + s2 + "-" + s + "-" + a.ID + "-Student.txt";
	string zz ="Database\\"+ s1 + "-" + s2 + "-Allcourses.txt";
	int num_course_temp;
	string* courses_temp;
	fi.open(zz);
	Load_all_course(fi, num_course_temp, courses_temp);
	fi.close();
	fo.open(zz);
	fo << num_course_temp + 1 << endl;
	for (int i = 0; i < num_course_temp; i++) {
		fo << courses_temp[i] << endl;
	}
	fo << s1 + "-" + s2 + "-" + s + "-" + a.ID + "-Student";
	fo.close();

	string s3;
	fi.open(file1);
	fo.open(file2);
	fi >> num;
	fi.ignore();
	fo << num << endl;
	for (int i = 0; i < num; i++) {
		getline(fi, s3);
		fo << s3 << endl;
		getline(fi, s3);
		fo << s3 << endl;
		getline(fi, s3);
		fo << s3 << endl;
		getline(fi, s3);
		fo << s3 << endl;
		getline(fi, s3);
		fo << s3 << endl;
		getline(fi, s3);
		fo << s3 << endl;
		getline(fi, s3);
		fo << s3;
		fo << -1 << endl << -1 << endl << -1 << endl << -1 << endl;
		Print_Date(fo,a);
	}
	fo.close();
	cout << "Successfully!" << endl;
	system("pause");
	return;
		
}
void Remove_a_course(void) {
	string s, s1, s2;
	ifstream fi;
	int choose;
	fi.open("Database\\Class.txt");
	Load_Data_Class(fi);
	fi.close();
	find_years_and_semester(s1, s2);
	loopa:;
	system("cls");
	cout << "Remove a course: " << endl;
	cout << "-----------------------------" << endl;
	for (int i = 0; i < num_classes; i++) {
		cout << i + 1 << ". " << Class[i].name << endl;
	}
	cout << num_classes+1 << ". Quits!" << endl;
	cout << "Choose Class: ";
	cin >> choose;
	if (choose == num_classes+1) return;
	s = Class[choose - 1].name;
	string name_file = "Database\\" + s1 + "-" + s2 + "-Schedule-" + s + ".txt";
	int num;
	course* b;
	fi.open(name_file);
	Load(fi, num, b);
	fi.close();
	system("cls");
	cout << "Remove a course: " << endl;
	cout << "-----------------------------" << endl;
	for (int i = 0; i < num; i++) {
		cout << i + 1 << ". " << b[i].ID << endl << "   " << b[i].course_name << endl << "   " << b[i].lecturer_name << endl<<"   "<< b[i].class_name<<endl<<endl;
	}
	cout << "-----------------------------" << endl;
	cout << "Your choice: ";
	cin >> choose;
	int q;
	cout << "Are you sure? " << endl;
	cout << "1. YES            2.NO " << endl;
	cout << "Your choice: ";
	cin >> q;
	if (q == 1) {
		ofstream fo;
		fo.open(name_file);
		fo << num - 1 << endl;
		for (int i = 0; i < num; i++) {
			if (choose == i + 1) continue;
			fo << b[i].ID << endl;
			fo << b[i].course_name << endl;
			fo << b[i].class_name << endl;
			fo << b[i].lecturer_name << endl;
			fo << b[i].users_name << endl;
			fo << b[i].start_date.d << "-" << b[i].start_date.m << "-" << b[i].start_date.y << endl;
			fo << b[i].end_date.d << "-" << b[i].end_date.m << "-" << b[i].end_date.y << endl;
			fo << b[i].day_of_week << endl;
			fo << b[i].start_hour << " " << b[i].start_minute << endl;
			fo << b[i].end_hour << " " << b[i].end_minute << endl;
			fo << b[i].room << endl<<endl;
		}
		fo.close();
		string zz = "Database\\" + s1 + "-" + s2 + "-Allcourses.txt";
		string z1=s1 + "-" + s2+"-"+ s+"-"+b[choose-1].ID+"-Student";
		int num_course_temp;
		string* courses_temp;
		fi.open(zz);
		Load_all_course(fi, num_course_temp, courses_temp);
		fi.close();
		fo.open(zz);
		fo << num_course_temp - 1 << endl;
		for (int i = 0; i < num_course_temp; i++) {
			if (courses_temp[i] != z1) fo << courses_temp[i] << endl;
		}
		fo.close();
	}
	else {
		goto loopa;
	}
	cout << "Successfully!" << endl;
	system("pause");
	return;

}
void Load_infor_course_of_student(ifstream& fi, int& num, infor_course_of_student*&a) {
	fi >> num;
	a = new infor_course_of_student[num];
	fi.ignore();
	for (int i = 0; i < num; i++) {
		getline(fi, a[i].ID);
		getline(fi, a[i].name_student);
		getline(fi, a[i].Dob.d, '-');
		getline(fi, a[i].Dob.m, '-');
		getline(fi, a[i].Dob.y, '\n');
		getline(fi, a[i].gender);
		getline(fi, a[i].name_class);
		getline(fi, a[i].status);
		getline(fi, a[i].Midtem);
		getline(fi, a[i].Final);
		getline(fi, a[i].Bonus);
		getline(fi, a[i].Total);
		for (int j = 0; j < 10; j++) {
			getline(fi, a[i].day[j], ' ');
			getline(fi, a[i].month[j], ' ');
			getline(fi, a[i].years[j], ' ');
			getline(fi, a[i].start_hour, ' ');
			getline(fi, a[i].start_minute, ' ');
			getline(fi, a[i].end_hour, ' ');
			getline(fi, a[i].end_minute, ' ');
			getline(fi, a[i].diemdanh[j], '\n');
		}
		fi.ignore();
	}
	return;
}
void Save_infor_corse_of_student(ofstream& fo, int num, infor_course_of_student* a) {
	fo << num << endl;
	for (int i = 0; i < num; i++) {
		fo << a[i].ID << endl;
		fo << a[i].name_student << endl;
		fo << a[i].Dob.d << "-" << a[i].Dob.m << "-" << a[i].Dob.y << endl;
		fo << a[i].gender << endl;
		fo << a[i].name_class << endl;
		fo << a[i].status << endl << a[i].Midtem << endl << a[i].Final << endl << a[i].Bonus << endl << a[i].Total << endl;
		for (int j = 0; j < 10; j++) {
			fo << a[i].day[j] << " " << a[i].month[j] << " " << a[i].years[j] << " " << a[i].start_hour << " " << a[i].start_minute << " " << a[i].end_hour << " " << a[i].end_minute << " " << a[i].diemdanh[j] << endl;
		}
		fo << endl;

	}
	return;
}
void Remove_student_from_course(void) {
	string s, s1, s2,s3;
	int z;
	ifstream fi;
	int choose1,choose2;
	fi.open("Database\\Class.txt");
	Load_Data_Class(fi);
	fi.close();
	find_years_and_semester(s1, s2);
	system("cls");
	cout << "Remove a student from course: " << endl;
	cout << "-----------------------------------" << endl;
	cout << "----------- List Classes ----------" << endl;
	for (int i = 0; i < num_classes; i++) {
		cout << i + 1 << ". " << Class[i].name << endl;
	}
	cout << "-----------------------------------" << endl;
	cout << "Choose Class: ";
	cin >> choose1;
	s = Class[choose1 - 1].name;
	string name_file = "Database\\" + s1 + "-" + s2 + "-Schedule-" + s + ".txt";
	int num;
	course* b;
	fi.open(name_file);
	Load(fi, num, b);
	fi.close();
	system("cls");
	cout << "Remove a student from course: " << endl;
	cout << "-----------------------------------" << endl;
	cout << "----------- List courses ----------" << endl;
	for (int i = 0; i < num; i++) {
		cout << i + 1 << ". " << b[i].ID << endl << "   " << b[i].course_name << endl << "   " << b[i].class_name << endl << endl;
	}
	cout << "-----------------------------------" << endl;
	cout << "Choose course: ";
	cin >> choose2;
	s3 = "Database\\" + s1 + "-" + s2 + "-" + s +"-"+b[choose2-1].ID+"-Student" +".txt";
	infor_course_of_student* a;
	fi.open(s3);
	Load_infor_course_of_student(fi, num, a);
	system("cls");
	cout << "Remove a student from course: " << endl;
	cout << "-----------------------------------" << endl;
	cout << "---------- List students ---------- " << endl;
	cout << " No.    Student ID        Name student        Gender " << endl;
	for (int i = 0; i < num; i++) {
		cout <<" "<< i + 1 << "       " << a[i].ID << "         " << a[i].name_student << "         " << a[i].gender << endl;
	}
	cout << "-----------------------------------" << endl;
	cout << "Choose student: ";
	cin >> choose1;
	cout << "Are you sure remove student ?" << endl;
	cout << "1. YES             2.NO   " << endl;
	cout << "Your choice: ";
	cin >> z;
	if (z == 1) {
		ofstream fo;
		fo.open(s3);
		fo << num-1 << endl;
		for (int i = 0; i < num; i++) {
			if (i != choose1 - 1) {
				fo << a[i].ID << endl;
				fo << a[i].name_student << endl;
				fo << a[i].Dob.d << "-" << a[i].Dob.m << "-" << a[i].Dob.y << endl;
				fo << a[i].gender << endl;
				fo << a[i].name_class << endl;
				fo << a[i].status << endl << a[i].Midtem << endl << a[i].Final << endl << a[i].Bonus << endl << a[i].Total << endl;
				for (int j = 0; j < 10; j++) {
					fo << a[i].day[j] << " " << a[i].month[j] << " " << a[i].years[j] << " " << a[i].start_hour << " " << a[i].start_minute << " " << a[i].end_hour << " " << a[i].end_minute << " " << a[i].diemdanh[j] << endl;
				}
				fo << endl;
			}

		}
		fo.close();
		cout << "Successfully!" << endl;
		system("pause");
	}
	else {
		return;
	}
	
	return;

}
void Add_student_from_course(void) {
	string s, s1, s2, s3;
	int z;
	ifstream fi;
	int choose1, choose2;
	fi.open("Database\\Class.txt");
	Load_Data_Class(fi);
	fi.close();
	find_years_and_semester(s1, s2);
	system("cls");
	cout << "Add student to a course: " << endl;
	cout << "-----------------------------------" << endl;
	cout << "----------- List Classes ----------" << endl;
	for (int i = 0; i < num_classes; i++) {
		cout << i + 1 << ". " << Class[i].name << endl;
	}
	cout << "-----------------------------------" << endl;
	cout << "Choose Class: ";
	cin >> choose1;
	s = Class[choose1 - 1].name;
	string name_file = "Database\\" + s1 + "-" + s2 + "-Schedule-" + s + ".txt";
	int num;
	course* b;
	fi.open(name_file);
	Load(fi, num, b);
	fi.close();
	system("cls");
	cout << "Add student to a course: " << endl;
	cout << "-----------------------------------" << endl;
	cout << "----------- List courses ----------" << endl;
	for (int i = 0; i < num; i++) {
		cout << i + 1 << ". " << b[i].ID << endl << "   " << b[i].course_name << endl << "   " << b[i].class_name << endl << endl;
	}
	cout << "-----------------------------------" << endl;
	cout << "Choose course: ";
	cin >> choose2;
	s3 = "Database\\" + s1 + "-" + s2 + "-" + s + "-" + b[choose2 - 1].ID + "-Student" + ".txt";
	infor_course_of_student* a;
	fi.open(s3);
	Load_infor_course_of_student(fi, num, a);
	string c[4];
	date d;
	system("cls");
	cout << "Add student to a course: " << endl;
	cout << "-----------------------------------" << endl;
	cout << "Enter information student:" << endl;
	cout << "ID student: ";
	cin.ignore();
	getline(cin, c[0]);
	cout << "Fullname: ";
	getline(cin, c[1]);
	cout << "Date of birth: " << endl;
	cout << "dd: ";
	getline(cin, d.d);
	cout << "mm: ";
	getline(cin, d.m);
	cout << "yyyy: ";
	getline(cin, d.y);
	cout << "Gender: ";
	getline(cin, c[2]);
	cout << "Class: ";
	getline(cin, c[3]);
	cout << "-----------------------------------" << endl;
	cout << "Are you sure add student ?" << endl;
	cout << "1. YES         2.NO   " << endl;
	cout << "Your choice: ";
	cin >> z;
	if (z == 1) {
		
		ofstream fo;
		fo.open(s3);
		fo << num + 1 << endl;
		for (int i = 0; i < num; i++) {
				fo << a[i].ID << endl;
				fo << a[i].name_student << endl;
				fo << a[i].Dob.d << "-" << a[i].Dob.m << "-" << a[i].Dob.y << endl;
				fo << a[i].gender << endl;
				fo << a[i].name_class << endl;
				fo << a[i].status << endl << a[i].Midtem << endl << a[i].Final << endl << a[i].Bonus << endl << a[i].Total << endl;
				for (int j = 0; j < 10; j++) {
					fo << a[i].day[j] << " " << a[i].month[j] << " " << a[i].years[j] << " " << a[i].start_hour << " " << a[i].start_minute << " " << a[i].end_hour << " " << a[i].end_minute << " " << a[i].diemdanh[j] << endl;
				}
				fo << endl;

		}
		fo << c[0] << endl << c[1] << endl << d.d << "-" << d.m << "-" << d.y << endl << c[2] << endl << c[3] << endl;
		fo << a[0].status << endl << a[0].Midtem << endl << a[0].Final << endl << a[0].Bonus << endl << a[0].Total << endl;
		for (int j = 0; j < 10; j++) {
			fo << a[0].day[j] << " " << a[0].month[j] << " " << a[0].years[j] << " " << a[0].start_hour << " " << a[0].start_minute << " " << a[0].end_hour << " " << a[0].end_minute << " " << a[0].diemdanh[j] << endl;
		}
		fo << endl;
		fo.close();
		cout << "Successfully! " << endl;
		system("pause");
	}
	return;
}
void View_attendance_list_of_course(void) {
	string s, s1, s2, s3;
	ifstream fi;
	int choose1, choose2;
	fi.open("Database\\Class.txt");
	Load_Data_Class(fi);
	fi.close();
	find_years_and_semester(s1, s2);
	system("cls");
	cout << "View attendance list of a course: " << endl;
	cout << "-----------------------------------" << endl;
	cout << "----------- List Classes ----------" << endl;
	for (int i = 0; i < num_classes; i++) {
		cout << i + 1 << ". " << Class[i].name << endl;
	}
	cout << "-----------------------------------" << endl;
	cout << "Choose Class: ";
	cin >> choose1;
	s = Class[choose1 - 1].name;
	string name_file = "Database\\" + s1 + "-" + s2 + "-Schedule-" + s + ".txt";
	int num;
	course* b;
	fi.open(name_file);
	Load(fi, num, b);
	fi.close();
	system("cls");
	cout << "View attendance list of a course: " << endl;
	cout << "-----------------------------------" << endl;
	cout << "----------- List courses ----------" << endl;
	for (int i = 0; i < num; i++) {
		cout << i + 1 << ". " << b[i].ID << endl << "   " << b[i].course_name << endl << "   " << b[i].class_name << endl << endl;
	}
	cout << "-----------------------------------" << endl;
	cout << "Choose course: ";
	cin >> choose2;
	s3 = "Database\\" + s1 + "-" + s2 + "-" + s + "-" + b[choose2 - 1].ID + "-Student" + ".txt";
	infor_course_of_student* a;
	fi.open(s3);
	Load_infor_course_of_student(fi, num, a);
	system("cls");
	cout << "View attendance list of a course: " << endl;
	cout << "-----------------------------------" << endl;
	cout << "Course name: " << b[choose2 - 1].course_name << endl;
	cout << "Course ID: " << b[choose2 - 1].ID << endl;
	cout << "Class: " << b[choose2 - 1].class_name << endl;
	cout << "Room: " << b[choose2 - 1].room << endl;
	cout << b[choose2 - 1].start_hour << ":" << b[choose2 - 1].start_minute << " -> " << b[choose2 - 1].end_hour << ":" << b[choose2 - 1].end_minute << endl;
	cout << "-----------------------------------" << endl;

	cout << "NO.  ID student    Fullname            Week01  Week02  Week03  Week04  Week05  Week06  Week07  Week08  Week09  Week10" << endl;
	for (int i = 0; i < num; i++) {
		cout << i + 1;
		if (i <= 8) cout << "    ";
		else cout << "   ";
		cout << a[i].ID << "      " << a[i].name_student;
		for (int j = 0; j < 21 - a[i].name_student.length(); j++) {
			cout << " ";
		}
		for (int j = 0; j < 10; j++) {
			if (a[i].diemdanh[j] != "-1") {
				cout << "YES     ";
			}
			else cout << "NO      ";
		}
		cout << endl;

	}
	int m;
	cout << "-----------------------------------" << endl;
	cout << "Do you want to export list to a csv file ?" << endl;
	cout << "1. YES           2.NO" << endl << "Your choice: ";
	cin >> m;
	if (m == 1) {
		ofstream fo;
		string l = "D:\\Final_Project\\AttendanceList-" + s1 + "-" + s2 + "-" + b[choose2 - 1].class_name + "-" + b[choose2 - 1].course_name + ".csv";
		fo.open(l);
		fo << "No,ID student,Fullname,Week01,Week02,Week03,Week04,Week05,Week06,Week07,Week08,Week09,Week10" << endl;
		for (int i = 0; i < num; i++) {
			fo << i + 1 << "," << a[i].ID << "," << a[i].name_student;
			for (int j = 0; j < 10; j++) {
				if (a[i].diemdanh[j] != "-1") {
					fo << ",YES";
				}
				else {
					fo << ",NO";
				}
			}
			fo << endl;
		}
		fo << "Note:" << endl;
		fo << "YES: Available" << endl;
		fo << "NO: Absent" << endl;
		fo.close();
		cout << "Export successfully!" << endl;
	}
	system("pause");
	return;
	
}
void View_students_of_course(void) {
	string s, s1, s2, s3;
	ifstream fi;
	int choose1, choose2;
	fi.open("Database\\Class.txt");
	Load_Data_Class(fi);
	fi.close();
	find_years_and_semester(s1, s2);
	system("cls");
	cout << "View list of students of a course: " << endl;
	cout << "-----------------------------------" << endl;
	cout << "----------- List Classes ----------" << endl;
	for (int i = 0; i < num_classes; i++) {
		cout << i + 1 << ". " << Class[i].name << endl;
	}
	cout << "-----------------------------------" << endl;
	cout << "Choose Class: ";
	cin >> choose1;
	s = Class[choose1 - 1].name;
	string name_file = "Database\\" + s1 + "-" + s2 + "-Schedule-" + s + ".txt";
	int num;
	course* b;
	fi.open(name_file);
	Load(fi, num, b);
	fi.close();
	system("cls");
	cout << "View list of students of a course " << endl;
	cout << "-----------------------------------" << endl;
	cout << "----------- List courses ----------" << endl;
	for (int i = 0; i < num; i++) {
		cout << i + 1 << ". " << b[i].ID << endl << "   " << b[i].course_name << endl << "   " << b[i].class_name << endl << endl;
	}
	cout << "-----------------------------------" << endl;
	cout << "Choose course: ";
	cin >> choose2;
	s3 = "Database\\" + s1 + "-" + s2 + "-" + s + "-" + b[choose2 - 1].ID + "-Student" + ".txt";
	infor_course_of_student* a;
	fi.open(s3);
	if (!fi.is_open()) {
		cout << "Can not open file! ";
		system("pause");
		return;
	}
	Load_infor_course_of_student(fi, num, a);
	system("cls");
	cout << "View list of students of a course " << endl;
	cout << "-------------------------------------------" << endl;
	cout << "Academic years: " << s1 << endl;
	cout << "Semesters: " << s2 << endl;
	cout << "Course: " << b[choose2 - 1].course_name << endl;
	cout << "ID course: " << b[choose2 - 1].ID << endl;
	cout << "Class: " << s << endl;
	cout << "Numbers students: " << num << endl;
	cout << "--------------- List Students -------------" << endl;
	cout << "NO.  ID student    Fullname            Gender " << endl;
	for (int i = 0; i < num; i++) {
		cout << i + 1 << ".";
		if (i <= 8) cout << "   ";
		else cout << "  ";
		cout << a[i].ID << "      " << a[i].name_student;
		for (int j = 0; j < 20 - a[i].name_student.length(); j++)cout << " ";
		cout << a[i].gender << endl;
	}
	system("pause");
	return;
} 
void Load_all_course(ifstream&fi,int &num_course_temp,string *&course_temp) {
	fi >> num_course_temp;
	fi.ignore();
	if (num_course_temp == 0) return;
	else {
		course_temp = new string[num_course_temp];
		for (int i = 0; i < num_course_temp; i++) {
			getline(fi, course_temp[i]);
		}
		return;
	}
}
void View_list_course(void) {
	string s, s1, s2, s3;
	ifstream fi;
	fi.open("Database\\Class.txt");
	Load_Data_Class(fi);
	fi.close();
	find_years_and_semester(s1, s2);
	system("cls");
	cout << "View list of courses in the current semester: " << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Academic years: " << s1 << endl;
	cout << "Semester: " << s2 << endl;
	cout << "----------------------------------------------------" << endl;
	for (int i = 0; i < num_classes; i++) {
		cout <<"Class: ";
		cout << Class[i].name << endl;
		string name_file = "Database\\" + s1 + "-" + s2 + "-Schedule-" + Class[i].name + ".txt";
		int num;
		course* b;
		fi.open(name_file);
		Load(fi, num, b);
		fi.close();
		cout << " No.   CourseID             Course name" << endl;
		for (int j = 0; j < num; j++) {
			cout << "  " << j + 1 << "     ";
			cout<<b[j].ID;
			for(int t=0;t<10-b[j].ID.length();t++){
				cout << " ";
			}
			cout << b[j].course_name << endl;
		}
		cout << "----------------------------------------------------" << endl;
	}
	system("pause");
	return;
}