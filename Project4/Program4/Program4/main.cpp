#include "linkedlist.h"
#include "stack.h"
#include <iostream>
#include <fstream>

using namespace std;
int findTotalCost(int totalCost, Stack& stack, LinkedList& list, string& originCity, string& destinationCity, int counter)
{
    string flight;
    while(list.flightHasNext())//pushes all destinations of cur city to stack
    {
        flight = list.getCurrentFlightCityName();
        counter++;
        if(counter > list.getSize())//for if a city does not exist
        {
            return 0;
        }
        stack.push(list.getCurrentFlightCost(), flight);//push destination onto the stack
        if(flight == destinationCity)//if the destination is the same as the one we want
        {
            totalCost += stack.popOffCost();//get the total cost and pop off stack
            cout << "There is a flight from " << originCity << " to " << destinationCity << "for: " << totalCost << endl;
            return totalCost;
        }
        list.flightAdvance();
    }
    totalCost += stack.popOffCost();
    list.find(flight);//goes through and finds the flight in the origin list
    list.setFlightIterator(list.getIndex());//sets the iterator to the right origin city
    findTotalCost(totalCost, stack, list, originCity, destinationCity, counter);//recursively iterates to find the destination if it is not a direct flight
}

bool backtrack(LinkedList list, string& originCity, string& destinationCity, LinkedList& flight_path,int size)
{
    Stack stack(20);//create a stack of size of the linked list
    string cur;
    int totalCost;
    list.reset();//iterator = head;
    int index = list.getIndex();//sets index to 0 because of list reset
    flight_path.start(originCity);//add the origin to the flight path first
    stack.push(originCity);
    while(stack.isEmpty() == false)
    {
        list.find(originCity);//finds origin city in originList
        cur = list.getCurrentData();
        list.setFlightIterator(index);//sets the flight iterator to point at the first node in adjacency list
        if(list.flightHasNext() == false)
        {
            cur = stack.popOffName();//cur is set to what it already is but the stack is now empty
            cout << "No flight paths available. I'm sorry, Dave." << endl;
            break;
        }
        else
        {
            totalCost = 0;
            int counter = 0;
            totalCost = findTotalCost(totalCost, stack, list, originCity, destinationCity, counter);
            if(totalCost == 0)
            {
                cout << "There are no flights between " << originCity << " and " << destinationCity << endl;
            }
            return true;
        }
    }
    cout << "There are no flights between " << originCity << " and " << destinationCity << endl;

}

int main(int argc, char *argv[])
{
    //-------------------------------------Reading in Flight Data--------------------------------------------//
     ifstream fileReader;
     LinkedList list;
     fileReader.open(argv[1]);
     int size=0;
     int bufferSize = 25;//set to 25 because I don't think cities (with airports) have longer names
     char* buffer = new char[bufferSize];
     fileReader >> size;
     list.setSize(size);
     fileReader.get();//gets the \n
     fileReader.getline(buffer, bufferSize, ','); //get first cityname
     string city;//use a string to better equate (just in case)
     city = buffer;
     list.start(city);//builds the first node of the linked list
     list.reset();//resets the iterator
     fileReader.get(); //gets the space before the city name
     fileReader.getline(buffer, bufferSize, ','); //gets where it flies to
     city = buffer;
     int cost;
     fileReader >> cost;
     list.appendFlights(list.getIndex(), city, cost);//makes a doubly linked list with a flight linked list
     bool flag = false;
     for(int i = 0; i < size-1; ++i)//loop to read in flight data
     {
         flag = false;
         fileReader.get(); //gets the '\n'
         fileReader.getline(buffer, bufferSize, ',');//gets next city
         city = buffer;
         list.reset();//resets iterator to check if a city is already a node
         while(list.hasNext())//iterate through list of origin cities
         {
            if(list.getCurrentData() == city)//if iterator city = read-in city
            {
                flag = true;
                break;
            }
            list.advance();
//            if(list.getCurrentData() == city)
//            {
//                flag = true;
//            }
         }
         if(flag == false)//list.getCurrentData() != city
         {
            list.append(city);//creates and links new node
            //list.advance();//advances iterator
            fileReader.get(); //gets the space before the city name
            fileReader.getline(buffer, bufferSize, ','); //gets destination city
            city = buffer;
            fileReader >> cost;
            list.appendFlights(list.getIndex(), city, cost);//adds a node to flight linked list
         }
         else
         {
            fileReader.get(); //gets the space
            fileReader.getline(buffer,bufferSize, ',');//read in the flight info
            fileReader >> cost;
            city = buffer;
            list.appendFlights(list.getIndex(), city, cost);//add to flight linked list
         }
     }
     //------------------------------------------------------------------------------------------//

     //--------------------------------Reading in User Data--------------------------------------//
     fileReader.close();
     fileReader.open(argv[2]);
     LinkedList flight_path;
     int counter = 0;
     string originCity;
     string destinationCity;
     bool done = false;
     fileReader >> counter;
     fileReader.get();//gets the '\n'
     for(int x = 0; x < counter; ++x)
     {
         done = false;
         fileReader.getline(buffer, bufferSize, ',');
         originCity = buffer;
         fileReader.get();//gets the space
         fileReader.getline(buffer, bufferSize);
         destinationCity = buffer;
         done = backtrack(list, originCity, destinationCity, flight_path, size);
     }

     //---------------------------------------------------------------------------------------------------//

}

