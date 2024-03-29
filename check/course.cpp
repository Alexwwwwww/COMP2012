#include "iostream"
#include <cstring>
#include "course.h"
#include "wait_list.h"

using namespace std;

Course::Course(const char* const name, const int num_credit, const int course_capacity) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->num_credit = num_credit;
    this->capacity = course_capacity;
    this->size = 0;
    this->wait_list = new Wait_List();
    this->students_enrolled = new int[course_capacity];
    for (int i = 0; i < course_capacity; i++)
    {
        this->students_enrolled[i] = 0;
    }
}

Course::Course(const Course& course) {
    name = new char[strlen(course.name) + 1];
    strcpy(name, course.name);
    num_credit = course.num_credit;
    capacity = course.capacity;
    size = course.size;
    wait_list = new Wait_List(*course.get_wait_list());
    students_enrolled = new int[capacity];
    for (int i = 0; i < capacity; i++)
    {
        (i < size) ? students_enrolled[i] = course.students_enrolled[i] : students_enrolled[i] = 0;
    }
}

Course::~Course() {
    delete[] name;
    delete[] students_enrolled;
    delete wait_list;
}

void Course::print_info() const {
    cout << "---------------------" << endl;
    cout << "Course Name: " << this->name << endl;
    cout << "Num Credit: " << this->num_credit << endl;
    cout << "Current Size: " << this->size << " out of Capacity: " << this->capacity << endl;
    cout << endl;
    cout << "Student Enrolled: " << endl;
    for(int i = 0; i < this->size; ++i) {
        cout << this->students_enrolled[i] << endl;
    }
    cout << endl;
    cout << "Waitlist Information: " << endl;
    this->wait_list->print_list();
    cout << endl;
}

char* Course::get_name() const {
    return name;
}

int Course::get_num_credit() const {
    return num_credit;
}

int Course::get_capacity() const {
    return capacity;
}

int Course::get_size() const {
    return size;
}

Wait_List* Course::get_wait_list() const {
    return wait_list;
}

int* Course::get_students_enrolled() const {
    return students_enrolled;
}

void Course::set_name(char* const name) {
    this->name = name;
}

void Course::set_num_credit(const int num_credit) {
    this->num_credit = num_credit;
}

void Course::set_capacity(const int capacity) {
    this->capacity = capacity;
}

void Course::set_size(const int size) {
    this->size = size;
}

void Course::set_wait_list(Wait_List* const wait_list) {
    this->wait_list = wait_list;
}

void Course::set_students_enrolled(int* const students_enrolled){
    this->students_enrolled = students_enrolled;
}