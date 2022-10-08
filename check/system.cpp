#include <iostream>
#include <cstring>
#include "system.h"
#include "student.h"
#include "course.h"
#include "course_database.h"
#include "student_database.h"
#include "wait_list.h"
#include "swap_list.h"

using namespace std;

/*
The following 3 helper functions may be useful in add/swap/drop function. You may implement them if you find them useful.
If not, you can remove these 3 helper functions as we will NOT set any test case testing these helper functions.
*/

// Helper function: add the Student to the end of the waitlist of the Course.
void join_waitlist(const int student_id, Course *course)
{
    Wait_List* list = new Wait_List(*course->get_wait_list());
    list->get_end()->next = new Student_ListNode (student_id, nullptr);
    list->set_end(list->get_end()->next);
    course->set_wait_list(list);
}

// Helper function: find the index of a course within the enrolled course list of a student.
int search_course_index(const Student *const student, const char *const course_name)
{
    for (int i = 0; i < student->get_num_enrolled_course(); i++)
    {
        if (!strcmp(student->get_enrolled_courses()[i], course_name))
        {
            return i;
        }
    }
    return -1;
}

// Helper function: find the index of the student_id in the enrolled student list
int search_student_id(const int student_id, const Course *const course)
{
    for (int i = 0; i < course->get_size(); i++)
    {
        if (course->get_students_enrolled()[i] == student_id)
        {
            return i;
        }
    }
    return -1;
}

System::System(const int max_num_course, const int max_num_student)
{
    course_database = new Course_Database(max_num_course);
    student_database = new Student_Database(max_num_student);
}

System::System(const System &system)
{
    this->course_database = new Course_Database(*system.course_database);
    this->student_database = new Student_Database(*system.student_database);
}

System::~System()
{
    delete course_database;
    delete student_database;
}

void System::admit(const char *const name, const int student_id, const double gpa)
{
    this->student_database->create_entry(name, student_id, gpa);
}

bool System::apply_overload(int student_id, const int request_credit)
{
    Student * student = this->student_database->get_student_by_id(student_id);
    if (student != nullptr)
    {
        const double gpa = student->get_gpa();
        if (request_credit > 30 || (request_credit >= 24 && gpa < 3.7) || (request_credit >= 18 && gpa < 3.3))
        {
            return false;
        }
        student->set_max_credit(request_credit);
        return true;
    }
    return false;
}

bool System::add(int student_id, const char *course_name)
{
    Student *student = this->student_database->get_student_by_id(student_id);
    Course *course = this->course_database->get_course_by_name(course_name);
    int curr = student->get_curr_credit();
    int pend = student->get_pending_credit();
    int course_cred = course->get_num_credit();
    if ((curr + course_cred + pend) > student->get_max_credit())
    {
        return false;
    }
    int capacity = course->get_capacity();
    int *list = course->get_students_enrolled();
    for (int i = 0; i < capacity; i++)
    {
        if (list[i] == 0)
        {
            list[i] = student->get_student_id();
            course->set_students_enrolled(list);
            course->set_size(course->get_size() + 1);
            student->set_num_enrolled_course(student->get_num_enrolled_course() + 1);
            student->set_curr_credit(curr + course_cred);
            char **courses = student->get_enrolled_courses();
            courses[student->get_num_enrolled_course() - 1] = new char[strlen(course->get_name()) + 1];
            strcpy(courses[student->get_num_enrolled_course() - 1], course->get_name());
            student->set_enrolled_courses(courses);
            return true;
        }
    }
    student->set_pending_credit(student->get_pending_credit() + course->get_num_credit());
    join_waitlist(student_id, course);
    return true;
}

bool System::swap(int student_id, const char *original_course_name, const char *target_course_name)
{
    Student *student = this->student_database->get_student_by_id(student_id);
    Course *ori_course = this->course_database->get_course_by_name(original_course_name);
    Course *tar_course = this->course_database->get_course_by_name(target_course_name);
    int curr = student->get_curr_credit();
    int ori_course_cred = ori_course->get_num_credit();
    int tar_course_cred = tar_course->get_num_credit();
    if ((curr - ori_course_cred + tar_course_cred) > student->get_max_credit())
    {
        return false;
    }
    this->drop(student_id, original_course_name);
    this->add(student_id, target_course_name);
    return true;
}

void System::drop(int student_id, const char *course_name)
{
    Student *student = this->student_database->get_student_by_id(student_id);
    Course *course = this->course_database->get_course_by_name(course_name);
    int curr = student->get_curr_credit();
    int course_cred = course->get_num_credit();
    int capacity = course->get_capacity();
    int *list = course->get_students_enrolled();
    for (int i = 0; i < capacity; i++)
    {
        if (list[i] == student->get_student_id())
        {
            list[i] = 0;
            course->set_students_enrolled(list);
            course->set_size(course->get_size() - 1);
            char **courses = student->get_enrolled_courses();
            for (int j = 0; j < student->get_num_enrolled_course(); j++)
            {
                if (!strcmp(course_name, courses[j]))
                {
                    delete[] courses[j];
                    if (j != student->get_num_enrolled_course() - 1)
                    {
                        courses[j] = new char[strlen(courses[student->get_num_enrolled_course() - 1]) + 1];
                        strcpy(courses[j], courses[student->get_num_enrolled_course() - 1]);
                        delete[] courses[student->get_num_enrolled_course() - 1];
                    }
                    student->set_num_enrolled_course(student->get_num_enrolled_course() - 1);
                    student->set_enrolled_courses(courses);
                    student->set_curr_credit(curr - course_cred);
                }
            }
        }
    }
}

void System::add_course(const char *const name, const int num_credit, const int course_capacity)
{
    this->course_database->create_entry(name, num_credit, course_capacity);
}

void System::print_info() const
{
    this->course_database->print_all_course();
    this->student_database->print_all_students();
}

Course_Database *System::get_course_database() const
{
    return course_database;
}

Student_Database *System::get_student_database() const
{
    return student_database;
}

void System::set_course_database(Course_Database *const course_database)
{
    this->course_database = course_database;
}

void System::set_student_database(Student_Database *const student_database)
{
    this->student_database = student_database;
}
