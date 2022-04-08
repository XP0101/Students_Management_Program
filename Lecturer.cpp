#include"Header.h"
void View_Profile_Lecturer(int location);
void Save_Data_Lecturer(ofstream& fo);
void Edit_StudentGrade(int location);
void View_list_student_of_a_course(int location);
void View_attendance_of_a_course(int location);
void Import_grade_from_csv_file(int location);
void Load_file(ifstream& fi, infor_course_of_student*& a, int num);
void Change_password_lecturer(int location);
void Run_Lecturer(int location) {
    int k;
loop_lecturer1:;
    system("cls");
    cout << "Hello " << lecturer[location].fullname << endl;
    cout << "-----------------MENU----------------- " << endl;
    cout << "Choose 1: View profile information " << endl;
    cout << "Choose 2: View list student of a course" << endl;
    cout << "Choose 3: View & Edit scoreboard of class" << endl;
    cout << "Choose 4: View & Edit attendance of a course" << endl;
    cout << "Choose 5: Import scoreboard from csv file" << endl;
    cout << "Choose 6: Change password " << endl;
    cout << "Choose 7: Log out!" << endl;
    cout << "Input a number:"; cin >> k;
    switch (k) {
    case 1: {
        View_Profile_Lecturer(location);
        ofstream fo;
        fo.open("Database\\Lecturer.txt");
        Save_Data_Lecturer(fo);
        fo.close();
        goto loop_lecturer1;
        break;
    }
    case 3: {
        Edit_StudentGrade(location);
        goto loop_lecturer1;
    }
    case 2: {
        View_list_student_of_a_course(location);
        goto loop_lecturer1;
    }
    case 4: {
        View_attendance_of_a_course(location);
        goto loop_lecturer1;
    }
    case 5: {
        Import_grade_from_csv_file(location);
        goto loop_lecturer1;
    }
    case 6: {
        Change_password_lecturer(location);
        goto loop_lecturer1;
    }
    }
    return;
}
void View_Profile_Lecturer(int location) {
    int k3, k4;
loop_lecturer2:
    system("cls");
    cout << "         Your profile information:" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Fullname: " << lecturer[location].fullname << endl;
    if (lecturer[location].sex == "1") cout << "Sex: Female" << endl;
    else cout << "Sex: Male" << endl;
    cout << "Degree: " << lecturer[location].degree << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Choose 1: Edit your profile" << endl;
    cout << "Choose 2: Quit ! " << endl;
    cout << "Your choice: ";
    cin >> k3;
    if (k3 == 1) {
        system("cls");
        cout << "Edit your profile information :" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Choose 1: Edit fullname" << endl;
        cout << "Choose 2: Edit sex" << endl;
        cout << "Choose 3: Edit degree" << endl;
        cout << "Choose 4: Go Back!" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Your choice: ";
        cin >> k4;
        switch (k4) {
        case 1: {
            cout << "Enter fullname: ";
            cin.ignore();
            getline(cin, lecturer[location].fullname);
            goto loop_lecturer2;

        }
        case 2: {
            cout << "-----------------------------------------------" << endl;
            cout << "Choose 0: Male" << endl;
            cout << "Choose 1: Female" << endl;
            cout << "Your choice: ";
            cin.ignore();
            getline(cin, lecturer[location].sex);
            goto loop_lecturer2;
        }
        case 3: {
            cout << "Enter degree: ";
            cin.ignore();
            getline(cin, lecturer[location].degree);
            goto loop_lecturer2;
        }
        }
    }

}
void Save_Data_Lecturer(ofstream& fo) {
    fo << num_lecturer << endl;
    for (int i = 0; i < num_lecturer; i++)
    {
        fo << lecturer[i].username << endl;
        fo << lecturer[i].password << endl;
        fo << lecturer[i].fullname << endl;
        fo << lecturer[i].degree << endl;
        fo << lecturer[i].sex << endl<<endl;
    }
}
void Edit_StudentGrade(int location)
{
loop:;
    string s1 , s2, s3 ,s4;
    find_years_and_semester(s1,s2);
    ifstream fi;
    fi.open("Database\\Class.txt");
    Load_Data_Class(fi);
    fi.close();
    int num_of_course = 0 , dem = 0;
    course* course_tmp = new course[6];
    for( int i = 0 ; i < num_classes ; ++i) {
        course* courses;
        s3 = "Database\\" +s1 + "-" + s2 + "-Schedule-" + Class[i].name + ".txt";
        fi.open(s3);
        Load(fi,num_of_course,courses);
        fi.close();
        for( int j = 0 ; j < num_of_course ; ++j) {
            if (courses[j].users_name == lecturer[location].username) {
                course_tmp[dem] = courses[j];
                dem++;
            }
        } delete[] courses;
    }
    system("cls");
    cout << "View & Edit scoreboard of class" << endl;
    cout << "------------------------------------" << endl;
    int store;
    cout << "No.             Course                       Class" << endl;
    for (int i = 0; i < dem; ++i) {
        cout << i + 1 << ".  " << course_tmp[i].course_name;
        for (int k1 = 0; k1 < 41 - course_tmp[i].course_name.length(); k1++) {
            cout << " ";
        }
        cout << course_tmp[i].class_name << endl;
    }
    cout << endl;
    cout << "0: Go Back!" << endl;
    cout << "------------------------------------" << endl;
    cout << "Your choice: "; cin >> store;
    if (store == 0) return;
    store--;
    s4 = "Database/" + s1 + "-" + s2 + "-" + course_tmp[store].class_name + "-" + course_tmp[store].ID + "-Student.txt";
    infor_course_of_student* infor;
    int num_of_student;
    fi.open(s4);
    Load_infor_course_of_student(fi, num_of_student, infor);
    fi.close();
loop_lecturer5:;
    system("cls");
    cout << "View & Edit scoreboard of class" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Course name: " << course_tmp[store].course_name << endl;
    cout << "Class: " << course_tmp[store].class_name << endl;
    cout << "Time: " << course_tmp[store].start_hour << ":" << course_tmp[store].start_minute << "->" << course_tmp[store].end_hour << ":" << course_tmp[store].end_minute << endl;
    cout << "Room: " << course_tmp[store].room << endl;
    cout << "--------------------------------------------" << endl;
    cout << " No.        Name          Midterm     Final       Bonus       Total" << endl;
    for (int i = 0; i < num_of_student; i++) {
        cout << "  " << i + 1;
        if (i < 9)cout << "   ";
        else cout << "  ";
        cout << infor[i].name_student;
        int k1;
        for (k1 = 0; k1 < 22 - infor[i].name_student.length(); k1++) {
            cout << " ";
        }
        cout << infor[i].Midtem;
        for (k1 = 0; k1 < 11 - infor[i].Midtem.length(); k1++) {
            cout << " ";
        }
        cout << infor[i].Final;
        for (k1 = 0; k1 < 12 - infor[i].Final.length(); k1++) {
            cout << " ";
        }
        cout << infor[i].Bonus;
        for (k1 = 0; k1 < 12 - infor[i].Bonus.length(); k1++) {
            cout << " ";
        }
        cout << infor[i].Total << endl;
    }
    cout << "--------------------------------------------" << endl;
    int chon;
    cout << "Do you want to edit grade ? " << endl;
    cout << "1. YES         2.NO" << endl;
    cout << "Your choice: ";
    cin >> chon;
    if (chon == 1) {
        int preview;
        cout << "------------------------" << endl;
        cout << "Choose student: ";
        cin >> preview;
        preview--;
        if (preview > num_of_student||preview<0) {
            cout << "ERROR";
            goto loop;
        }
        int choice;
        string nscore;
        cout << "------------------------------------------------" << endl;
        cout << "Choose 1: Edit midterm score" << endl;
        cout << "Choose 2: Edit final score" << endl;
        cout << "Choose 3: Edit bonus score" << endl;
        cout << "Choose 4: Edit total score" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "Your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "New midterm score: ";
            cin >> nscore;
            infor[preview].Midtem = nscore;
            ofstream fo;
            fo.open(s4);
            Save_infor_corse_of_student(fo, num_of_student, infor);
            fo.close();
            goto loop_lecturer5;
        }
        case 2: {
            cout << "New final score: ";
            cin >> nscore;
            infor[preview].Final = nscore;
            ofstream fo;
            fo.open(s4);
            Save_infor_corse_of_student(fo, num_of_student, infor);
            fo.close();
            goto loop_lecturer5;
        }
        case 3: {
            cout << "New bonus score: ";
            cin >> nscore;
            infor[preview].Bonus = nscore;
            ofstream fo;
            fo.open(s4);
            Save_infor_corse_of_student(fo, num_of_student, infor);
            fo.close();
            goto loop_lecturer5;
        }
        case 4: {
            cout << "New total score: ";
            cin >> nscore;
            infor[preview].Total = nscore;
            ofstream fo;
            fo.open(s4);
            Save_infor_corse_of_student(fo, num_of_student, infor);
            fo.close();
            goto loop_lecturer5;
        }
        default: {
            cout << "Error: Illegal choice" << endl;
            cout << "Please enter your choice once more" << endl;
            goto loop_lecturer5;
        }
        }



    }
    else {
        goto loop;
    }
 return;
}
void View_list_student_of_a_course(int location) {
loop:;
    string s1, s2, s4;
    find_years_and_semester(s1, s2);
    ifstream fi;
    fi.open("Database/Class.txt");
    Load_Data_Class(fi);
    fi.close();
    int num_of_course = 0, dem = 0;
    course* course_tmp = new course[6];
    for (int i = 0; i < num_classes; ++i) {
        course* courses;
        string s3 = "Database/" + s1 + "-" + s2 + "-Schedule-" + Class[i].name + ".txt";
        fi.open(s3);
        Load(fi, num_of_course, courses);
        fi.close();
        for (int j = 0; j < num_of_course; ++j) {
            if (courses[j].users_name == lecturer[location].username) {
                course_tmp[dem] = courses[j];
                dem++;
            }
        } delete[] courses;
    }
    system("cls");
    cout << "View list student of a course" << endl;
    cout << "------------------------------------" << endl;
    int store;
    cout << "No.             Course                       Class" << endl;
    for (int i = 0; i < dem; ++i) {
        cout << i + 1 << ".  " << course_tmp[i].course_name;
        for (int k1 = 0; k1 < 41 - course_tmp[i].course_name.length(); k1++) {
            cout << " ";
        }
        cout << course_tmp[i].class_name << endl;
    }
    cout << endl;
    cout << "0: Go back!" << endl;
    cout << "------------------------------------" << endl;
    cout << "Your choice: "; cin >> store;
    if (store == 0) return;
    store--;
    s4 = "Database/" + s1 + "-" + s2 + "-" + course_tmp[store].class_name + "-" + course_tmp[store].ID + "-Student.txt";
    infor_course_of_student* infor;
    int num_of_student;
    fi.open(s4);
    Load_infor_course_of_student(fi, num_of_student, infor);
    fi.close();
    system("cls");
    cout << "View list student of a course" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Course name: " << course_tmp[store].course_name << endl;
    cout << "Class: " << course_tmp[store].class_name << endl;
    cout << "Time: " << course_tmp[store].start_hour << ":" << course_tmp[store].start_minute << "->" << course_tmp[store].end_hour << ":" << course_tmp[store].end_minute << endl;
    cout << "Room: " << course_tmp[store].room << endl;
    cout << "--------------------------------------------" << endl;
    cout << " No.    ID student          Fullname                   Dob              Gender" << endl;
    for (int i = 0; i < num_of_student; i++) {
        cout << "  " << i + 1;
        if (i < 9)cout << "      ";
        else cout << "     ";
        cout << infor[i].ID << "         ";
        cout << infor[i].name_student;
        int k1;
        for (k1 = 0; k1 < 26 - infor[i].name_student.length(); k1++) {
            cout << " ";
        }
        cout << infor[i].Dob.d<<"-"<<infor[i].Dob.m<<"-"<<infor[i].Dob.y;
        for (k1 = 0; k1 < 18 - infor[i].Dob.d.length()-infor[i].Dob.m.length()-infor[i].Dob.y.length(); k1++) {
            cout << " ";
        }
        cout << infor[i].gender<<endl;
    }
    cout << "--------------------------------------------" << endl;
    system("pause");
    goto loop;
    return;
}
void View_attendance_of_a_course(int location) {
loop:;
    string s1, s2, s3, s4;
    find_years_and_semester(s1, s2);
    ifstream fi;
    fi.open("Database\\Class.txt");
    Load_Data_Class(fi);
    fi.close();
    int num_of_course = 0, dem = 0;
    course* course_tmp = new course[6];
    for (int i = 0; i < num_classes; ++i) {
        course* courses;
        s3 = "Database\\" + s1 + "-" + s2 + "-Schedule-" + Class[i].name + ".txt";
        fi.open(s3);
        Load(fi, num_of_course, courses);
        fi.close();
        for (int j = 0; j < num_of_course; ++j) {
            if (courses[j].users_name == lecturer[location].username) {
                course_tmp[dem] = courses[j];
                dem++;
            }
        } delete[] courses;
    }
    system("cls");
    cout << "View & Edit attendance of a course" << endl;
    cout << "------------------------------------" << endl;
    int store;
    cout << "No.             Course                       Class" << endl;
    for (int i = 0; i < dem; ++i) {
        cout << i + 1 << ".  " << course_tmp[i].course_name;
        for (int k1 = 0; k1 < 41 - course_tmp[i].course_name.length(); k1++) {
            cout << " ";
        }
        cout << course_tmp[i].class_name << endl;
    }
    cout << endl;
    cout << "0: Go Back!" << endl;
    cout << "------------------------------------" << endl;
    cout << "Your choice: "; cin >> store;
    if (store == 0) return;
    store--;
    s4 = "Database/" + s1 + "-" + s2 + "-" + course_tmp[store].class_name + "-" + course_tmp[store].ID + "-Student.txt";
    infor_course_of_student* infor;
    int num_of_student;
    fi.open(s4);
    Load_infor_course_of_student(fi, num_of_student, infor);
    fi.close();
loop_lecturer5:;
    system("cls");
    cout << "View & Edit attendance of a course" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Course name: " << course_tmp[store].course_name << endl;
    cout << "Class: " << course_tmp[store].class_name << endl;
    cout << "Time: " << course_tmp[store].start_hour << ":" << course_tmp[store].start_minute << "->" << course_tmp[store].end_hour << ":" << course_tmp[store].end_minute << endl;
    cout << "Room: " << course_tmp[store].room << endl;
    cout << "--------------------------------------------" << endl;
    cout << " No.   ID student      Fullname          Week1  Week2  Week3  Week4  Week5  Week6  Week7  Week8  Week9  Week10"<<endl;

    for (int i = 0; i < num_of_student; i++) {
        cout <<" "<< i + 1;
        if (i < 9)cout << "     ";
        else cout << "    ";
        cout << infor[i].ID << "     ";
        cout << infor[i].name_student;
        int k1;
        for (k1 = 0; k1 < 22 - infor[i].name_student.length(); k1++) {
            cout << " ";    
        }
        for (int j = 0; j < 9; j++) {
            if (infor[i].diemdanh[j] != "-1") cout << "O";
            else cout << "-";
            cout << "      ";
        }
        if (infor[i].diemdanh[9] != "-1") cout << "O" << endl;
        else cout << "-"<<endl;


    }
    cout << "--------------------------------------------" << endl;
    int chon;
    cout << "Do you want to edit attendance ? " << endl;
    cout << "1. YES         2.NO" << endl;
    cout << "Your choice: ";
    cin >> chon;
    if (chon == 1) {
        int preview,z;
        cout << "------------------------" << endl;
        cout << "Choose student: ";
        cin >> preview;
        preview--;
        cout << "Choose week: ";
        cin >> z;
        z--;
        if (preview > num_of_student || preview < 0||z<0||z>9) {
            cout << "ERROR"<<endl;
            system("pause");
            goto loop;
        }
        if (infor[preview].diemdanh[z] == "-1") {
            infor[preview].diemdanh[z] = "1";
        }
        else {
            infor[preview].diemdanh[z] = "-1";
        }
        ofstream fo;
        fo.open(s4);
        Save_infor_corse_of_student(fo, num_of_student, infor);
        fo.close();
        goto loop_lecturer5;

    }
    else {
        goto loop;
    }
    return;
}
void Import_grade_from_csv_file(int location) {
    string s1, s2, s3, s4;
    find_years_and_semester(s1, s2);
    ifstream fi;
    fi.open("Database\\Class.txt");
    Load_Data_Class(fi);
    fi.close();
    int num_of_course = 0, dem = 0;
    course* course_tmp = new course[6];
    for (int i = 0; i < num_classes; ++i) {
        course* courses;
        s3 = "Database\\" + s1 + "-" + s2 + "-Schedule-" + Class[i].name + ".txt";
        fi.open(s3);
        Load(fi, num_of_course, courses);
        fi.close();
        for (int j = 0; j < num_of_course; ++j) {
            if (courses[j].users_name == lecturer[location].username) {
                course_tmp[dem] = courses[j];
                dem++;
            }
        } delete[] courses;
    }
loop1:;
    system("cls");
    cout << "----------Import Scoreboard---------" << endl;
    cout << "------------------------------------" << endl; 
    int store;
    cout << "No.             Course                       Class" << endl;
    for (int i = 0; i < dem; ++i) {
        cout << i + 1 << ".  " << course_tmp[i].course_name;
        for (int k1 = 0; k1 < 41 - course_tmp[i].course_name.length(); k1++) {
            cout << " ";
        }
        cout << course_tmp[i].class_name << endl;
    }
    cout << endl;
    cout << "0: Go Back!" << endl;
    cout << "------------------------------------" << endl;
    cout << "Your choice: "; cin >> store;
    if (store == 0) return;
    store--;
    s4 = "Database/" + s1 + "-" + s2 + "-" + course_tmp[store].class_name + "-" + course_tmp[store].ID + "-Student.txt";
    infor_course_of_student* infor;
    int num_of_student;
    fi.open(s4);
    Load_infor_course_of_student(fi, num_of_student, infor);
    fi.close();
    string q;
loop:;
    q = "";
    system("cls");
    cout << "----------Import Scoreboard---------" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Course name: " << course_tmp[store].course_name << endl;
    cout << "Class: " << course_tmp[store].class_name << endl;
    cout << "Time: " << course_tmp[store].start_hour << ":" << course_tmp[store].start_minute << "->" << course_tmp[store].end_hour << ":" << course_tmp[store].end_minute << endl;
    cout << "Room: " << course_tmp[store].room << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Enter the path: ";
    cin.ignore();
    getline(cin, q);
    fi.open(q);
    if (!fi.is_open()) {
        int l;
        cout << "--------------------------------------------" << endl;
        cout << "Can not open file!"<<endl;
        cout << "Choose 1: Enter again" << endl;
        cout << "Choose 2: Quit!" << endl;
        cout << "Your choice: ";
        cin >> l;
        if (l == 1) {
            goto loop;
        }
        else {
            goto loop1;
        }
    }
    Load_file(fi, infor, num_of_student);
    fi.close();
    ofstream fo;
    fo.open(s4);
    Save_infor_corse_of_student(fo, num_of_student, infor);
    fo.close();
    cout << "Import Successfully!" << endl;
    system("pause");
    return;
}
void Load_file(ifstream& fi, infor_course_of_student*& a, int num) {
    string rac;
    getline(fi, rac);
    for (int i = 0; i < num; i++) {
        getline(fi, rac, ',');
        getline(fi, rac, ',');
        getline(fi, rac, ',');
        getline(fi, a[i].Midtem, ',');
        getline(fi, a[i].Final, ',');
        getline(fi, a[i].Bonus, ',');
        getline(fi, a[i].Total, '\n');
    }
    return;
}
void Change_password_lecturer(int location) {
    string s1, s2, s3;
    char ch;
    int tk = 0;
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
    if (s1 != lecturer[location].password) {
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
            lecturer[location].password = s2;
            cout << "------------------------" << endl;
            cout << "Change password successfully! " << endl;
            ofstream fo;
            fo.open("Database\\Lecturer.txt");
            Save_Data_Lecturer(fo);
            fo.close();
        }
    }
    system("pause");
    return;
}

