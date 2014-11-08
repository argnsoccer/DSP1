#include "linkedlist.h"
LinkedList::LinkedList() : size(0), index(0)
{
     head = nullptr;
     iterator = head;
}

void LinkedList::setSize(int size)
{
    this->size = size;
}

int LinkedList::getSize()
{
    return size;
}

void LinkedList::setIndex(int index)
{
    this->index = index;
}

int LinkedList::getIndex()
{
    return index;
}

void LinkedList::start(string &x)
{
    head = new Node;
    head->city = x;
    head->next = nullptr;
}

//void LinkedList::setHeadFlightName(string &cityName)
//{
//    head->flight->city = cityName;
//    head->flight->next = nullptr;
//}

//void LinkedList::setHeadFlightCost(int cost)
//{
//    head->flight->flightCost = cost;
//}

void LinkedList::appendFlights(int index, string &cityName, int cost)
{
    Node* cur = head;
    for(int i = 0; i < index; ++i)
    {
        cur = cur->next;
    }

    cur->flight = new Node;
    cur->flight->city = cityName;
    cur->flight->flightCost = cost;

    cur->flight->next = nullptr;
}

void LinkedList::append(string &x)
{
    Node* cur = head;

    while(cur->next != nullptr)
    {
        cur = cur->next;
    }
    cur->next = new Node;
    cur->next->city = x;

    cur->next->next = nullptr;
}

void LinkedList::reset()
{
    iterator = head;
    index = 0;
}

void LinkedList::advance()
{
    iterator = iterator->next;
    index++;
}

string LinkedList::getCurrentData()
{
    return iterator->city;
}


bool LinkedList::hasNext()
{
    if(iterator->next != nullptr)
    {
        return true;
    }
    else
        return false;
}

void LinkedList::flightAdvance()
{
    flightIterator = flightIterator->next;
}

void LinkedList::setFlightIterator(int index)
{
    Node* temp = head;
    for(int i = 0; i < index; ++i)
    {
        temp = temp->next;
    }
    flightIterator = temp->flight;
}

string LinkedList::getCurrentFlightCityName()
{
    return flightIterator->city;
}

int LinkedList::getCurrentFlightCost()
{
    return flightIterator->flightCost;
}
