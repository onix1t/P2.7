#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student{
    string fullname;
    int aig, dm, sdia;
    Student(string name, int aigGrade, int dmGrade, int sdiaGrade): fullname(name), aig(aigGrade), dm(dmGrade), sdia(sdiaGrade) {}
};

vector<Student> GetSuccess(const vector<Student>& students) 
{
    vector<Student> StudentsSuccess;

    for (const Student& student : students) {
        // Предполагаем, что оценки >= 50 являются проходными
        if (student.aig >= 50 && student.dm >= 50 && student.sdia >= 50) {
            StudentsSuccess.push_back(student);
        }
    }

    return StudentsSuccess;
}

int main()
{
    setlocale(LC_ALL, "ru");

    cout << "Практика 7 | Вариант 7\r\n\r\n";

    // Создаем вектор студентов
    vector<Student> students { 
        Student("Иванов Иван Иванович", 60, 70, 80),
        Student("Петров Петр Дмитриевич", 40, 50, 60),
        Student("Сидоров Павел Евгеньевич", 70, 80, 90),
        Student("Кузнецов Николай Викторович", 50, 40, 60)
    };

    
    vector<Student> successfulStudents = GetSuccess(students); // Получаем список студентов, успевающих по всем дисциплинам

    // Выводим список успевающих студентов
    cout << "Список студентов, успевающих по всем дисциплинам:\n";
    for (const Student& student : successfulStudents) {
        cout << student.fullname << endl;
    }

    return 0;
}