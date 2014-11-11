
#include "linkedlist.h"
LinkedList::LinkedList() : size(0), index(0)
{
     head = nullptr;
     iterator = head;
}

void LinkedList::destroy(Node *cur)
{
    if(cur->next != nullptr)
    {
        destroy(cur->next);
    }
    delete cur;
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

void LinkedList::start(string &x)//build linkedlist
{
    head = new Node;
    head->city = x;
    head->next = nullptr;
    head->flight = nullptr;
}

void LinkedList::appendFlights(int index, string &cityName, int cost)
{
    Node* cur = head;
    for(int i = 0; i < index; ++i)//iterate to the origin city you want
    {
        cur = cur->next;
    }
    if(cur->flight == nullptr)//if no destinations have been made
    {
        cur->flight = new Node;//begin flight linked list
    }
    else //if flight linked list has been built already
    {
        while(cur->flight != nullptr)//iterate to end of flight linkedlist
        {
            cur = cur->flight;
        }
        cur->flight = new Node;//create new destination
    }
    cur->flight->city = cityName;//input data
    cur->flight->flightCost = cost;

    cur->flight->flight = nullptr;
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
    cur->next->flight = nullptr;
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
    if(iterator == nullptr)
    {
        return false;
    }
    else if(iterator != nullptr)
    {
        return true;
    }
    else
        return false;
}

void LinkedList::flightAdvance()
{
    flightIterator = flightIterator->flight;
}

bool LinkedList::flightHasNext()
{
    if(flightIterator != nullptr)
    {
        return true;
    }
    else
        return false;
}

void LinkedList::setFlightIterator(int index)
{
    Node* temp = head;
    for(int i = 0; i < index; ++i)//get to origin city you want
    {
        temp = temp->next;
    }
    flightIterator = temp->flight;//set the iterator to point to the flight linked list
}

string LinkedList::getCurrentFlightCityName()
{
    return flightIterator->city;
}

int LinkedList::getCurrentFlightCost()
{
    return flightIterator->flightCost;
}

string LinkedList::find(string& cityName)
{
    reset();
    while(this->hasNext())
    {
        if(this->getCurrentData() == cityName)
        {
            return (this->getCurrentData());
        }
        else
            this->advance();
    }
}
