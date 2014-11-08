#include "linkedlist.h"
//#include "flight.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
     ifstream fileReader;
     LinkedList list;
     fileReader.open(argv[1]);
     int size=0;
     int bufferSize = 20;//set to 20 because I don't think cities (with airports) have longer names
     char* buffer = new char[bufferSize];
     fileReader >> size;
     fileReader.getline(buffer, bufferSize, ','); //get first cityname
     string city;//use a string to better equate (just in case)
     city = buffer;
     list.start(city);//builds the first node of the linked list
     list.reset();//resets the iterator
//     cout << list.getCurrentData();
     fileReader.getline(buffer, bufferSize, ','); //gets where it flies to
     city = buffer;
//     list.setHeadFlightName(city);
     int cost;
     fileReader >> cost;
//     list.setHeadFlightCost(cost);
     list.appendFlights(list.getIndex(), city, cost);//makes a doubly linked list with a flight linked list
     list.setFlightIterator(list.getIndex());//sets the iterator for flights (to print)
//     cout << " flight to " << list.getCurrentFlightCityName() << "for: " << list.getCurrentFlightCost() << endl;
//     cout << "index: " << list.getIndex() << endl;
     bool flag = false;
     for(int i = 0; i < size-1; ++i)//loop to read in flight data
     {
         fileReader.getline(buffer, bufferSize, ',');//gets next city
         city = buffer;
         list.reset();//resets iterator to check if a city is arleady a node
         while(list.hasNext())//iterate through list of origin cities
         {
            if(list.getCurrentData() == city)//if iterator city = read-in city
            {
                flag = true;
                cout << "flag is true" << endl;
                break;
            }
            list.advance();
         }
//         do
//         {
         if(flag == false)//list.getCurrentData() != city
         {
            list.append(city);//creates and links new node
            list.advance();//advances iterator
//            cout << list.getCurrentData();

            fileReader.getline(buffer, bufferSize, ','); //gets destination city
            city = buffer;
            fileReader >> cost;
            list.appendFlights(list.getIndex(), city, cost);//adds a node to flight linked list
            list.setFlightIterator(list.getIndex());//sets flight linked list iterator
//            cout << " with flight to " << list.getCurrentFlightCityName() << "for: " << list.getCurrentFlightCost() << endl;
//            cout << "index: " << list.getIndex();
         }
         else
         {
            fileReader.getline(buffer,bufferSize, ',');//read in the flight info
            fileReader >> cost;
            city = buffer;
            list.appendFlights(list.getIndex(), city, cost);//add to flight linked list
            list.setFlightIterator(list.getIndex());//set to right city's flight linked list
            cout << "with flight to " << list.getCurrentFlightCityName() << "for: " << list.getCurrentFlightCost() << endl;
            cout << "index: " << list.getIndex() << endl;
            break;
         }
     }

//   PsuedoCode:

//   while(!read)
//   {
//       origin_locations.push_back(new Flight(buffer));
//   }

//   for(int i = 0; i < origin_locations.size(); ++i)
//   {
//       map.append(origin_locations.at(i));
//   }

//   while (origin_locations.hasNext())
//   {
//       map.append(origin_locations.getCurrent());

//       origin_locations.advance();
//   }

//   Have a linked list of linked lists and now I want to recurse through it

//   bool backtrack(originList, Flight& end_destination; LinkedList<Flights>& flight_path)
//   {
//       Stack<Flight> stack;
//       flight_path.append(originList.origin);
//       while(originList.hasNext())
//       {
//           stack.push(originList.getCurrent());
//           originList.advance();

//       }

//       while(!stack.empty())
//       {
//           backtrack(FindOrigin(stack.pop()), end_destinatin, flight_path);

//       }

//   }

}
