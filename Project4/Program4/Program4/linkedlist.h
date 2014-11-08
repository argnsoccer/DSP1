#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

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

    public: //Constructor | Destructor
         LinkedList();
         ~LinkedList()
         {
             delete head;
             delete iterator;
         }

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

         void appendFlights(int index, string &cityName, int cost);

         void setHeadFlightName(string &cityName);

         void setHeadFlightCost(int cost);

         void setSize(int size);

         int getSize();

         void setIndex(int index);

         int getIndex();
};

#endif // LINKEDLIST_H
