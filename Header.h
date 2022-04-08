#ifndef _HEADER_H_
#define _HEADER_H_
#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include <time.h>   
#include <conio.h>
using namespace std;

struct Date {
	string d, m, y;
};
struct Staff_infor
{
	string username, password, fullname, sex, job, phone_numbers;
};
struct Lecturer_infor {
	string username, password, fullname, degree, sex;
	Date Dob;
};
struct Student_infor {
	string fullname, ID, Class, username, password, sex, status;
	Date Dob;
};
struct Class_infor {
	string name;
	int  num_students = 0, num_status = 0;
	Student_infor sv[30];
};
struct date {
	string d, m, y;
};
struct course {
	string ID, course_name, class_name, users_name, day_of_week, start_hour, start_minute, end_hour, end_minute, room,lecturer_name;
	date start_date, end_date;
};
struct infor_course_of_student {
	string ID, name_student, gender, name_class, status, Midtem, Final, Bonus, Total, start_hour, start_minute, end_hour, end_minute;
	date Dob;
	string day[10], month[10], years[10], diemdanh[10];
};
struct import_scoreboard_from_csv {
    string stt,ID,name_student,Midtem,Final,Bonus,Total;
};
extern int num_staff, num_lecturer, num_student, num_student_in_course, num_classes, num_status, num_course_of_class;
extern Staff_infor* staff;
extern Student_infor* student;
extern Lecturer_infor* lecturer;
extern Class_infor* Class;
extern infor_course_of_student* student_in_course;


//_____________ GENERAL.cpp_________________//
string Password(Date z);
string the_path(string s);
int Check_Login_Staff(string a, string b);
int Check_Login_Lecturer(string a, string b);
int Check_Login_Student(string a, string b);
void Load_Data_Staff(ifstream& fi);
void Load_Data_lecturer(ifstream& fi);
void Load_Data_Student(ifstream& fi);
void Save_Data_Students(ofstream& fo, Student_infor*& student_temp, int& num_student_temp);
void Save_Data_Lecturer(ofstream& fo, Lecturer_infor*& Lec_temp, int num_lec_temp);
void Load_Data_Class(ifstream& fi);
void find_years_and_semester(string& s1, string& s2);




//______________STAFF.cpp__________________//
void Run_Staff(int location);
void Load(ifstream& fi, int& num, course*& b);
void Load_infor_course_of_student(ifstream& fi, int& num, infor_course_of_student*& a);
void Save_infor_corse_of_student(ofstream& fo, int num, infor_course_of_student* a);
void Save(ofstream& fo, int num, course* b);


//_______________LECTURER.cpp______________//
void Run_Lecturer(int location );


//________________STUDENT.cpp______________//
void Run_Student(int location);

#endif
