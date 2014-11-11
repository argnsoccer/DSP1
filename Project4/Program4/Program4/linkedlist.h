#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <iostream>

using namespace std;

class LinkedList
{

    private: //Member Variables
        struct Node
        {
            public:
            Node* next;
            Node* flight;
            string city= "";
            int flightCost;
            Node* prev;
        };

         Node* head;
         Node* iterator;
         Node* flightIterator;
         int size;
         int index;
         void destroy(Node* cur);

    public: //Constructor | Destructor
         LinkedList();
//         ~LinkedList()
//         {
//             destroy(this->head);
//             //delete iterator;
//             //delete flightIterator;
//         }

    public: //Member Functions

         void append(string &x);

         void start(string &x);

         void advance();

         void flightAdvance();

         void setFlightIterator(int index);

         string getCurrentFlightCityName();

         int getCurrentFlightCost();

         void reset();

         string getCurrentData();

         bool hasNext();

         bool flightHasNext();

         void appendFlights(int index, string &cityName, int cost);

         void setHeadFlightName(string &cityName);

         void setHeadFlightCost(int cost);

         void setSize(int size);

         int getSize();

         void setIndex(int index);

         int getIndex();

         string find(string& cityName);
};

#endif // LINKEDLIST_H
