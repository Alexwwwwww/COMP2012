#include <iostream>
#include "wait_list.h"

using namespace std;

Student_ListNode::Student_ListNode(int student_id, Student_ListNode *next)
{
    this->student_id = student_id;
    this->next = next;
}

Wait_List::Wait_List()
{
    this->head = nullptr;
    this->end = nullptr;
}

Wait_List::Wait_List(const Wait_List &wait_list)
{
    Student_ListNode* tmp = wait_list.get_head();
    if (tmp == nullptr)
    {
        head = nullptr;
        return;
    }
    head = new Student_ListNode (tmp->student_id, nullptr);
    Student_ListNode *current = head;
    tmp = tmp->next;
    while (tmp != nullptr)
    {
        current->next = new Student_ListNode(tmp->student_id, nullptr);
        if (tmp->next = nullptr)
        {
            end = current->next;
        }
        current = current->next;
        tmp = tmp->next;
    }
}

Wait_List::~Wait_List()
{
    Student_ListNode* current = head;
    while (current != nullptr)
    {
        head = head->next;
        delete current;
        current = head;
    }
    delete end;
}

void Wait_List::print_list() const {
    Student_ListNode* temp = this->head;
    int index = 0;
    while(temp) {
        cout << "Waitlist Number: " << index++ << endl;
        cout << temp->student_id << endl;
        temp = temp->next;
    }
}

Student_ListNode* Wait_List::get_head() const {
    return head;
}

Student_ListNode* Wait_List::get_end() const {
    return end;
}

void Wait_List::set_head(Student_ListNode* const head) {
    this->head = head;
}

void Wait_List::set_end(Student_ListNode* const end) {
    this->end = end;
}