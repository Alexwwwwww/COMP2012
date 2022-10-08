#include <iostream>
#include <cstring>
#include "swap_list.h"

using namespace std;

Swap::Swap(const char *original_course_name, const char *target_course_name, Swap *next)
{
    this->original_course_name = new char[strlen(original_course_name) + 1];
    strcpy(this->original_course_name, original_course_name);
    this->target_course_name = new char[strlen(target_course_name) + 1];
    strcpy(this->target_course_name, target_course_name);
    this->next = next;
}

Swap::~Swap()
{
    delete[] original_course_name;
    delete[] target_course_name;
}

Swap_List::Swap_List()
{
    this->head = nullptr;
}

Swap_List::Swap_List(const Swap_List &swap_list)
{
    Swap* tmp = swap_list.get_head();
    if (tmp == nullptr)
    {
        head = nullptr;
        return;
    }
    head = new Swap(tmp->original_course_name, tmp->target_course_name, nullptr);
    Swap* current = head;
    tmp = tmp->next;
    while (tmp != nullptr)
    {
        current->next = new Swap(tmp->original_course_name, tmp->target_course_name, nullptr);
        current = current->next;
        tmp = tmp->next;
    }
}

Swap_List::~Swap_List()
{
    Swap* current = head;
    while (current != nullptr)
    {
        head = head->next;
        delete current;
        current = head;
    }
}

void Swap_List::print_list() const {
    Swap* temp = this->head;
    int index = 0;
    while(temp) {
        cout << "Swap: " << index++ << endl;
        cout << "Original Course: " << temp->original_course_name << endl;
        cout << "Target Course: " << temp->target_course_name << endl;
        temp = temp->next;
    }
}

Swap* Swap_List::get_head() const {
    return head;
}

void Swap_List::set_head(Swap* const head) {
    this->head = head;
}