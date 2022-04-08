#include"Header.h"
void Profile_student(int location);
void Result_checkin(int location);
void View_schedules(int location);
void View_scores(int location);
void Checkin_student(int location);
void Change_password_student(int location);
void Save_Data_Student(ofstream& fo, Student_infor*& student_temp, int& num_student_temp)
{
	fo << num_student_temp << endl;
	for (int i = 0; i < num_student_temp; i++)
	{
		fo << student_temp[i].ID << endl;
		fo << student_temp[i].password << endl;
		fo << student_temp[i].fullname << endl;
		fo << student_temp[i].Dob.y << "-" << student_temp[i].Dob.m << "-" << student_temp[i].Dob.d << endl;
		fo << student_temp[i].Class << endl;
		fo << student_temp[i].sex << endl;
		fo << 1 << endl << endl;
	}
}
void Run_Student(int location) {
	int n;
loop:;
	system("cls");
	cout << "Hello " << student[location].fullname << " !" << endl;
	cout << "------------------ MENU ------------------" << endl;
	cout << "Choose 1: View profile information" << endl;
	cout << "Choose 2: Check-in" << endl;
	cout << "Choose 3: View check-in result" << endl;
	cout << "Choose 4: View schedules" << endl;
	cout << "Choose 5: View your scores of a course" << endl;
	cout << "Choose 6: Change password" << endl;
	cout << "Choose 7: Logout" << endl;
	cout << "------------------------------------------" << endl;
	cout << "Your choice: ";
	cin >> n;
	switch (n)
	{
	case 1: {
		Profile_student(location);
		goto loop;
		break;
	}
	case 2: {
		Checkin_student(location);
		goto loop;
		break;
	}
	case 3: {
		Result_checkin(location);
		goto loop;
		break;
	}
	case 4: {
		View_schedules(location);
		goto loop;
		break;
	}
	case 5: {
		View_scores(location);
		goto loop;
		break;
	}
	case 6: {
		Change_password_student(location);
		goto loop;
		break;
	}
	}
	system("pause");
	return;
}
void Profile_student(int location) {
	system("cls");
	cout << "Your profile information: " << endl;
	cout << "--------------------------------" << endl;
	cout << "Fullname: " << student[location].fullname << endl;
	cout << "ID student: " << student[location].ID << endl;
	cout << "Date of birth: " << student[location].Dob.d << "-" << student[location].Dob.m << "-" << student[location].Dob.y << endl;
	cout << "Class: " << student[location].Class << endl;
	cout << "--------------------------------" << endl;
	system("pause");
	return;
}
void Checkin_student(int location) {
loop:;
	string s1, s2;
	int num;
	string* link_course;
	find_years_and_semester(s1, s2);
	string s = "Database\\" + s1 + "-" + s2 + "-Allcourses.txt";
	ifstream fi;
	fi.open(s);
	if (!fi.is_open()) {
		cout << "Can not open file! " << endl;
		system("pause");
		return;
	}
	fi >> num;
	link_course = new string[num];
	fi.ignore();
	for (int i = 0; i < num; i++) {
		getline(fi, link_course[i]);
	}
	fi.close();
	int num1 = 0;
	string ID, rac;
	infor_course_of_student* mon;
	mon = new infor_course_of_student[6];
	int n = 0;
	string* IDmon;
	string* Nameclass;
	IDmon = new string[6];
	Nameclass = new string[6];
	for (int i = 0; i < num; i++) {
		s = "";
		s = "Database\\" + link_course[i] + ".txt";
		fi.open(s);
		if (fi.is_open()) {
			fi >> num1;
			fi.ignore();
			for (int j = 0; j < num1; j++) {
				getline(fi, ID);
				if (ID != student[location].ID) {
					for (int t = 0; t < 20; t++) {
						getline(fi, rac);
					}
				}
				else {
					int dem = 0;
					IDmon[n] = "";
					string link = link_course[i];
					for (int t = 0; t < link.length(); t++) {
						if (link[t] == '-') {
							dem += 1;
							continue;
						}
						if (dem == 4) IDmon[n] += link[t];
					}
					dem = 0;
					Nameclass[n] = "";
					for (int t = 0; t < link.length(); t++) {
						if (link[t] == '-') {
							dem += 1;
							continue;
						}
						if (dem == 3) Nameclass[n] += link[t];
					}

					mon[n].ID = ID;
					getline(fi, mon[n].name_student);
					getline(fi, mon[n].Dob.d, '-');
					getline(fi, mon[n].Dob.m, '-');
					getline(fi, mon[n].Dob.y, '\n');
					getline(fi, mon[n].gender);
					getline(fi, mon[n].name_class);
					getline(fi, mon[n].status);
					getline(fi, mon[n].Midtem);
					getline(fi, mon[n].Final);
					getline(fi, mon[n].Bonus);
					getline(fi, mon[n].Total);
					for (int t = 0; t < 10; t++) {
						getline(fi, mon[n].day[t], ' ');
						getline(fi, mon[n].month[t], ' ');
						getline(fi, mon[n].years[t], ' ');
						getline(fi, mon[n].start_hour, ' ');
						getline(fi, mon[n].start_minute, ' ');
						getline(fi, mon[n].end_hour, ' ');
						getline(fi, mon[n].end_minute, ' ');
						getline(fi, mon[n].diemdanh[t]);
					}
					fi.ignore();
					n += 1;
				}
			}
		}
		fi.close();
	}
	int somon = 0, q;
	course* monchon = new course[n];
	system("cls");
	cout << "Check-in "<< endl;
	cout << "------------- List Courses --------------" << endl;
	for (int i = -1; i < n; i++) {
		if (i == -1) {
			cout << "0. Go back!" << endl << endl;
			continue;
		}
		cout << i + 1 << ". ";
		string name_file = "Database\\" + s1 + "-" + s2 + "-Schedule-" + Nameclass[i] + ".txt";
		course* b;
		fi.open(name_file);
		Load(fi, num, b);
		for (int j = 0; j < num; j++) {
			if (IDmon[i] == b[j].ID) {
				monchon[somon] = b[j];
				somon += 1;
				cout << b[j].course_name << endl;
				cout << "   " << b[j].ID << endl;
				cout << "   " << b[j].lecturer_name << endl << endl;
			}
		}
		fi.close();
		delete[]b;
	}
	cout << "-----------------------------------------" << endl;
	cout << "Your choice: ";
	cin >> q;
	if (q == 0 || q > somon) return;
	system("cls");
	cout << "Check-in" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Course: " << monchon[q - 1].course_name << endl;
	cout << "ID coures: " << monchon[q - 1].ID << endl;
	cout << "Class: " << monchon[q - 1].class_name << endl;
	cout << "day of week: " << monchon[q - 1].day_of_week << endl;
	cout << monchon[q - 1].start_hour << ":" << monchon[q - 1].start_minute << "->" << monchon[q - 1].end_hour << ":" << monchon[q - 1].end_minute << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Do you want to check-in ?" << endl;
	int chon;
	cout << "1.YES            2.NO" << endl;
	cout << "Your choice: ";
	cin >> chon;
	if (chon == 2) {
		goto loop;
	}
	else {
		time_t rawtime;
		struct tm* timeinfo;
		timeinfo = new tm[1];
		time(&rawtime);
		localtime_s(timeinfo, &rawtime);
		int day, month, years,start_hour,start_minute,end_hour,end_minute;
		start_hour = stoi(mon[q - 1].start_hour);
		start_minute = stoi(mon[q - 1].start_minute);
		end_hour = stoi(mon[q - 1].end_hour);
		end_minute = stoi(mon[q - 1].end_minute);
		bool check = false;
		if ((timeinfo[0].tm_hour * 60 + timeinfo[0].tm_min) <= (start_hour * 60 + start_minute) || (timeinfo[0].tm_hour * 3600 + timeinfo[0].tm_min * 60 + timeinfo[0].tm_sec) > (end_hour * 3600 + end_minute * 60)) {
			cout << "You can't check in !" << endl;
			system("pause");
			goto loop;
		}
		else {
			for (int i = 0; i < 10; i++) {
				day = stoi(mon[q - 1].day[i]);
				month = stoi(mon[q - 1].month[i]);
				years = stoi(mon[q - 1].years[i]);
				if (day == timeinfo[0].tm_mday && month == timeinfo[0].tm_mon + 1 && years == 1900 + timeinfo[0].tm_year) {
					check = true;
					mon[q - 1].diemdanh[i] = "1";
				}
			}
		}
		if (check == false) {
			cout << "You can't check in" << endl;
		}
		else {
			string name_file = "Database\\" + s1 + "-" + s2 + "-" + monchon[q - 1].class_name + "-" + monchon[q-1].ID + "-Student.txt";
			infor_course_of_student* a;
			int k;
			fi.open(name_file);
			if (!fi.is_open()) {
				cout << "Can not open file! " << endl;
				system("pause");
				return;
			}
			Load_infor_course_of_student(fi, k, a);
			for (int i = 0; i < k; i++) {
				if (a[i].ID == mon[q - 1].ID) {
					a[i] = mon[q - 1];
					break;
				}
			}
			fi.close();
			ofstream fo;
			fo.open(name_file);
			Save_infor_corse_of_student(fo, k, a);
			fo.close();
			cout << "Check-in successfully ! " << endl;
		}
	}
	system("pause");
	delete[]Nameclass;
	delete[]IDmon;
	delete[]monchon;
	delete[]mon;
	goto loop;
	return;
}
void Result_checkin(int location) {
loop:;
	string s1, s2;
	int num;
	string* link_course;
	find_years_and_semester(s1, s2);
	string s = "Database\\" + s1 + "-" + s2 + "-Allcourses.txt";
	ifstream fi;
	fi.open(s);
	if (!fi.is_open()) {
		cout << "Can not open file! " << endl;
		system("pause");
		return;
	}
	fi >> num;
	link_course = new string[num];
	fi.ignore();
	for (int i = 0; i < num; i++) {
		getline(fi, link_course[i]);
	}
	fi.close();
	int num1=0;
	string ID, rac;
	infor_course_of_student* mon;
	mon = new infor_course_of_student[6];
	int n = 0;
	string* IDmon;
	string* Nameclass;
	IDmon = new string[6];
	Nameclass = new string[6];
	for (int i = 0; i < num; i++) {
		s = "";
		s = "Database\\" + link_course[i] + ".txt";
		fi.open(s);
		if (fi.is_open()) {
			fi >> num1;
			fi.ignore();
			for (int j = 0; j < num1; j++) {
				getline(fi, ID);
				if (ID != student[location].ID) {
					for (int t = 0; t < 20; t++) {
						getline(fi, rac);
					}
				}
				else {
					int dem = 0;
					IDmon[n] = "";
					string link = link_course[i];
					for (int t = 0; t < link.length(); t++) {
						if (link[t] == '-') {
							dem += 1;
							continue;
						}
						if (dem == 4) IDmon[n] += link[t];
					}
					 dem = 0;
					Nameclass[n] = "";
					for (int t = 0; t < link.length(); t++) {
						if (link[t] == '-') {
							dem += 1;
							continue;
						}
						if (dem == 3) Nameclass[n] += link[t];
					}
			
					mon[n].ID = ID;
					getline(fi, mon[n].name_student);
					getline(fi, mon[n].Dob.d, '-');
					getline(fi, mon[n].Dob.m, '-');
					getline(fi, mon[n].Dob.y, '\n');
					getline(fi, mon[n].gender);
					getline(fi, mon[n].name_class);
					getline(fi, mon[n].status);
					getline(fi, mon[n].Midtem);
					getline(fi, mon[n].Final);
					getline(fi, mon[n].Bonus);
					getline(fi, mon[n].Total);
					for (int t = 0; t < 10; t++) {
						getline(fi, mon[n].day[t], ' ');
						getline(fi, mon[n].month[t], ' ');
						getline(fi, mon[n].years[t], ' ');
						getline(fi, mon[n].start_hour, ' ');
						getline(fi, mon[n].start_minute, ' ');
						getline(fi, mon[n].end_hour, ' ');
						getline(fi, mon[n].end_minute, ' ');
						getline(fi, mon[n].diemdanh[t]);
					}
					fi.ignore();
					n += 1;
				}
			}
		}
		fi.close();
	}
	int somon = 0, q;
	course* monchon = new course[n];
	system("cls");
	cout << "View check-in result" << endl;
	cout << "------------- List Courses --------------" << endl;
	for (int i = -1; i < n; i++) {
		if (i == -1) {
			cout << "0. Go back!" << endl<<endl;
			continue;
		}
		cout << i + 1 << ". ";
		string name_file = "Database\\" + s1 + "-" + s2 + "-Schedule-" + Nameclass[i]+".txt";
		course* b;
		fi.open(name_file);
		Load(fi, num, b);
		for(int j = 0; j < num; j++) {
			if (IDmon[i] == b[j].ID) {
				monchon[somon] = b[j];
				somon += 1;
				cout << b[j].course_name << endl;
				cout << "   " << b[j].ID << endl;
				cout << "   " << b[j].lecturer_name << endl << endl;
			}
		}
		fi.close();
		delete[]b;
	}
	cout << "-----------------------------------------" << endl;
	cout << "Your choice: ";
	cin >> q;
	if (q == 0||q>somon) return;
	system("cls");
	cout << "View check-in result" << endl;
	cout << "-----------------------------------------" << endl;
	cout <<"Course: "<< monchon[q-1].course_name << endl;
	cout << "ID coures: " << monchon[q - 1].ID << endl;
	cout << "Class: " << monchon[q - 1].class_name << endl;
	cout << "day of week: " << monchon[q - 1].day_of_week << endl;
	cout << monchon[q - 1].start_hour << ":" << monchon[q - 1].start_minute << "->" << monchon[q - 1].end_hour << ":" << monchon[q - 1].end_minute << endl;
	cout << "-----------------------------------------" << endl;
	cout << "   Week        Date         Check-in  " << endl;
	for (int i = 0; i < 10; i++) {
		cout <<"    "<< i + 1;
		if (i < 9) cout << "        ";
		else cout << "       ";
		cout << mon[q - 1].day[i] << "-" << mon[q - 1].month[i] << "-" << mon[q - 1].years[i] ;
		for (int j = 0; j < 16 - mon[q - 1].day[i].length() - mon[q - 1].month[i].length() - mon[q - 1].years[i].length(); j++) cout << " ";
		if (mon[q - 1].diemdanh[i] != "-1") cout << "O" << endl; else cout << "X" << endl;
	}
	cout << "-----------------------------------------" << endl;
	cout << "Note:" << endl;
	cout << "O: vailable" <<endl<<"X: absent"<< endl;
	
	system("pause");
	delete[]Nameclass;
	delete[]IDmon;
	delete[]monchon;
	delete[]mon;
	goto loop;
	return;
}
void View_schedules(int location) {
	string s1, s2;
	int num;
	string* link_course;
	find_years_and_semester(s1, s2);
	string s = "Database\\" + s1 + "-" + s2 + "-Allcourses.txt";
	ifstream fi;
	fi.open(s);
	if (!fi.is_open()) {
		cout << "Can not open file! " << endl;
		system("pause");
		return;
	}
	fi >> num;
	link_course = new string[num];
	fi.ignore();
	for (int i = 0; i < num; i++) {
		getline(fi, link_course[i]);
	}
	fi.close();
	int num1 = 0;
	string ID, rac;
	infor_course_of_student* mon;
	mon = new infor_course_of_student[6];
	int n = 0;
	string* IDmon;
	string* Nameclass;
	IDmon = new string[6];
	Nameclass = new string[6];
	for (int i = 0; i < num; i++) {
		s = "";
		s = "Database\\" + link_course[i] + ".txt";
		fi.open(s);
		if (fi.is_open()) {
			fi >> num1;
			fi.ignore();
			for (int j = 0; j < num1; j++) {
				getline(fi, ID);
				if (ID != student[location].ID) {
					for (int t = 0; t < 20; t++) {
						getline(fi, rac);
					}
				}
				else {
					int dem = 0;
					IDmon[n] = "";
					string link = link_course[i];
					for (int t = 0; t < link.length(); t++) {
						if (link[t] == '-') {
							dem += 1;
							continue;
						}
						if (dem == 4) IDmon[n] += link[t];
					}
					dem = 0;
					Nameclass[n] = "";
					for (int t = 0; t < link.length(); t++) {
						if (link[t] == '-') {
							dem += 1;
							continue;
						}
						if (dem == 3) Nameclass[n] += link[t];
					}

					mon[n].ID = ID;
					getline(fi, mon[n].name_student);
					getline(fi, mon[n].Dob.d, '-');
					getline(fi, mon[n].Dob.m, '-');
					getline(fi, mon[n].Dob.y, '\n');
					getline(fi, mon[n].gender);
					getline(fi, mon[n].name_class);
					getline(fi, mon[n].status);
					getline(fi, mon[n].Midtem);
					getline(fi, mon[n].Final);
					getline(fi, mon[n].Bonus);
					getline(fi, mon[n].Total);
					for (int t = 0; t < 10; t++) {
						getline(fi, mon[n].day[t], ' ');
						getline(fi, mon[n].month[t], ' ');
						getline(fi, mon[n].years[t], ' ');
						getline(fi, mon[n].start_hour, ' ');
						getline(fi, mon[n].start_minute, ' ');
						getline(fi, mon[n].end_hour, ' ');
						getline(fi, mon[n].end_minute, ' ');
						getline(fi, mon[n].diemdanh[t]);
					}
					fi.ignore();
					n += 1;
				}
			}
		}
		fi.close();
	}
	int somon = 0;
	course* monchon = new course[n];
	system("cls");
	cout << "View your schedule " << endl;
	cout << "-----------------------------------------" << endl;
	for (int i = 0; i < n; i++) {
		string name_file = "Database\\" + s1 + "-" + s2 + "-Schedule-" + Nameclass[i] + ".txt";
		course* b;
		fi.open(name_file);
		Load(fi, num, b);
		for (int j = 0; j < num; j++) {
			if (IDmon[i] == b[j].ID) {
				monchon[somon] = b[j];
				somon += 1;
			}
		}
		fi.close();
		delete[]b;
	}
	cout << " No.              Course                 Class       Day of week         Time           Room" << endl;
	for (int i = 0; i < somon; i++) {
		cout <<" "<< i + 1 << ".   ";
		cout << monchon[i].course_name;
		if (monchon[i].course_name.length() < 35) {
			for (int t = 0; t < 35 - monchon[i].course_name.length(); t++) {
				cout << " ";
			}
		}
		cout << monchon[i].class_name;
		if (monchon[i].class_name.length() < 14) {
			for (int t = 0; t < 14 - monchon[i].class_name.length(); t++) {
				cout << " ";
			}
		}
		cout << monchon[i].day_of_week;
		if (monchon[i].day_of_week.length() < 15) {
			for (int t = 0; t < 15 - monchon[i].day_of_week.length(); t++) {
				cout << " ";
			}
		}
		cout << monchon[i].start_hour << ":" << monchon[i].start_minute << "->" << monchon[i].end_hour << ":" << monchon[i].end_minute;
		int length = monchon[i].start_hour.length() + monchon[i].start_minute.length() + monchon[i].end_hour.length() + monchon[i].end_minute.length();
		if (length<15) {
			for (int t = 0; t < 15-length; t++) {
				cout << " ";
			}
		}
		cout << monchon[i].room << endl;
	}
	cout << "-----------------------------------------" << endl;
	system("pause");
	delete[]Nameclass;
	delete[]IDmon;
	delete[]monchon;
	delete[]mon;
	return;
}
void View_scores(int location) {
	string s1, s2;
	int num;
	string* link_course;
	find_years_and_semester(s1, s2);
	string s = "Database\\" + s1 + "-" + s2 + "-Allcourses.txt";
	ifstream fi;
	fi.open(s);
	if (!fi.is_open()) {
		cout << "Can not open file! " << endl;
		system("pause");
		return;
	}
	fi >> num;
	link_course = new string[num];
	fi.ignore();
	for (int i = 0; i < num; i++) {
		getline(fi, link_course[i]);
	}
	fi.close();
	int num1 = 0;
	string ID, rac;
	infor_course_of_student* mon;
	mon = new infor_course_of_student[6];
	int n = 0;
	string* IDmon;
	string* Nameclass;
	IDmon = new string[6];
	Nameclass = new string[6];
	for (int i = 0; i < num; i++) {
		s = "";
		s = "Database\\" + link_course[i] + ".txt";
		fi.open(s);
		if (fi.is_open()) {
			fi >> num1;
			fi.ignore();
			for (int j = 0; j < num1; j++) {
				getline(fi, ID);
				if (ID != student[location].ID) {
					for (int t = 0; t < 20; t++) {
						getline(fi, rac);
					}
				}
				else {
					int dem = 0;
					IDmon[n] = "";
					string link = link_course[i];
					for (int t = 0; t < link.length(); t++) {
						if (link[t] == '-') {
							dem += 1;
							continue;
						}
						if (dem == 4) IDmon[n] += link[t];
					}
					dem = 0;
					Nameclass[n] = "";
					for (int t = 0; t < link.length(); t++) {
						if (link[t] == '-') {
							dem += 1;
							continue;
						}
						if (dem == 3) Nameclass[n] += link[t];
					}

					mon[n].ID = ID;
					getline(fi, mon[n].name_student);
					getline(fi, mon[n].Dob.d, '-');
					getline(fi, mon[n].Dob.m, '-');
					getline(fi, mon[n].Dob.y, '\n');
					getline(fi, mon[n].gender);
					getline(fi, mon[n].name_class);
					getline(fi, mon[n].status);
					getline(fi, mon[n].Midtem);
					getline(fi, mon[n].Final);
					getline(fi, mon[n].Bonus);
					getline(fi, mon[n].Total);
					for (int t = 0; t < 10; t++) {
						getline(fi, mon[n].day[t], ' ');
						getline(fi, mon[n].month[t], ' ');
						getline(fi, mon[n].years[t], ' ');
						getline(fi, mon[n].start_hour, ' ');
						getline(fi, mon[n].start_minute, ' ');
						getline(fi, mon[n].end_hour, ' ');
						getline(fi, mon[n].end_minute, ' ');
						getline(fi, mon[n].diemdanh[t]);
					}
					fi.ignore();
					n += 1;
				}
			}
		}
		fi.close();
	}
	int somon = 0;
	course* monchon = new course[n];
	system("cls");
	cout << "View your Scoreboard " << endl;
	cout << "-----------------------------------------" << endl;
	for (int i = 0; i < n; i++) {
		string name_file = "Database\\" + s1 + "-" + s2 + "-Schedule-" + Nameclass[i] + ".txt";
		course* b;
		fi.open(name_file);
		Load(fi, num, b);
		for (int j = 0; j < num; j++) {
			if (IDmon[i] == b[j].ID) {
				monchon[somon] = b[j];
				somon += 1;
			}
		}
		fi.close();
		delete[]b;
	}
	cout << " No.            Course                    Class       Midtem         Final          Bonus          Total  " << endl;
	for (int i = 0; i < somon; i++) {
		cout << " " << i + 1 << ".   ";
		cout << monchon[i].course_name;
		if (monchon[i].course_name.length() < 35) {
			for (int t = 0; t < 35 - monchon[i].course_name.length(); t++) {
				cout << " ";
			}
		}
		cout << monchon[i].class_name;
		if (monchon[i].class_name.length() < 14) {
			for (int t = 0; t < 14 - monchon[i].class_name.length(); t++) {
				cout << " ";
			}
		}
		cout << mon[i].Midtem;
		if (mon[i].Midtem.length() < 15) {
			for (int t = 0; t < 15 - mon[i].Midtem.length(); t++) {
				cout << " ";
			}
		}
		cout << mon[i].Final;
		if (mon[i].Final.length() < 15) {
			for (int t = 0; t < 15 - mon[i].Final.length(); t++) {
				cout << " ";
			}
		}
		cout << mon[i].Bonus;
		if (mon[i].Bonus.length() < 15) {
			for (int t = 0; t < 15 - mon[i].Bonus.length(); t++) {
				cout << " ";
			}
		}
		cout << mon[i].Total << endl;
	}
	cout << "-----------------------------------------" << endl;
	system("pause");
	delete[]Nameclass;
	delete[]IDmon;
	delete[]monchon;
	delete[]mon;
	return;
}
void Change_password_student(int location) {
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
	if (s1 != student[location].password) {
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
			student[location].password = s2;
			cout << "------------------------" << endl;
			cout << "Change password successfully! " << endl;
			ofstream fo;
			fo.open("Database\\Student.txt");
			Save_Data_Student(fo, student, num_student);
			fo.close();
		}
	}
	system("pause");
	return;
}
