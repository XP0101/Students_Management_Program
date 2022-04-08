#include"Header.h"
/////////////////////////////////////////////
string Password(Date z) {
	return z.d + z.m + z.y;
}
string the_path(string s)
{
	return "Database\\" + s + ".txt";
}
//////////////////////////////////////////////
int Check_Login_Staff(string a, string b)
{
	int check = -1;
	for (int i = 0; i < num_staff; i++)
	{
		if (staff[i].username == a && staff[i].password == b) check = i;
	}
	return check;
}

int Check_Login_Lecturer(string a, string b)
{
	int check = -1;
	for (int i = 0; i < num_lecturer; i++)
	{
		if (lecturer[i].username == a && lecturer[i].password == b) check = i;
	}
	return check;
}

int Check_Login_Student(string a, string b)
{
	int check = -1;
	for (int i = 0; i < num_student; i++) {
		if (student[i].ID == a && student[i].password == b) check = i;
	}
	return check;
}
////////////////////////////////////////////////////////////
void Load_Data_Staff(ifstream& fi)
{
	fi >> num_staff;
	fi.ignore();
	staff = new Staff_infor[num_staff + 1];
	for (int i = 0; i < num_staff; i++)
	{
		getline(fi, staff[i].username);
		getline(fi, staff[i].password);
		getline(fi, staff[i].fullname);
		getline(fi, staff[i].sex);
		getline(fi, staff[i].job);
		getline(fi, staff[i].phone_numbers);
		fi.ignore();
	}
}
void Load_Data_lecturer(ifstream& fi)
{
	fi >> num_lecturer;
	fi.ignore();
	lecturer = new Lecturer_infor[num_lecturer + 1];
	for (int i = 0; i < num_lecturer; i++)
	{
		getline(fi, lecturer[i].username);
		getline(fi, lecturer[i].password);
		getline(fi, lecturer[i].fullname);
		getline(fi, lecturer[i].degree);
		getline(fi, lecturer[i].sex);
		fi.ignore();
	}
}

void Load_Data_Student(ifstream& fi)
{
	fi >> num_student;
	num_status = num_student;
	fi.ignore();
	student = new Student_infor[num_student + 1];
	for (int i = 0; i < num_student; i++)
	{
		getline(fi, student[i].ID);
		getline(fi, student[i].password);
		getline(fi, student[i].fullname);
		getline(fi, student[i].Dob.y, '-');
		getline(fi, student[i].Dob.m, '-');
		getline(fi, student[i].Dob.d, '\n');
		getline(fi, student[i].Class);
		getline(fi, student[i].sex);
		getline(fi, student[i].status);
		fi.ignore();
	}
}

void Load_Data_Class(ifstream& fi) {
	fi >> num_classes;
	fi.ignore();
	Class = new Class_infor[num_classes];
	for (int i = 0; i < num_classes; i++) {
		getline(fi, Class[i].name);
	}
}
////////////////////////////////////////////////////

void Save_Data_Students(ofstream& fo, Student_infor*& student_temp, int& num_student_temp)
{
	fo << num_student_temp << endl;
	for (int i = 0; i < num_student_temp; i++)
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

void Save_Data_Lecturer(ofstream& fo, Lecturer_infor*& Lec_temp, int num_lec_temp) {
	fo << num_lec_temp << endl;
	for (int i = 0; i < num_lec_temp; i++) {
		fo << Lec_temp[i].username << endl;
		fo << Lec_temp[i].password << endl;
		fo << Lec_temp[i].fullname << endl;
		fo << Lec_temp[i].degree << endl;
		if (Lec_temp[i].sex == "Male") {
			fo << 0 << endl;
		}
		else {
			fo << 1 << endl;
		}
		fo << endl;
	}
}
