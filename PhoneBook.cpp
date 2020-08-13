//
//  PhoneBook.cpp
//  assignment3
//
//  Created by Samriddhi Sangraula on 4/4/20.
//  Copyright © 2020 Samriddhi Sangraula. All rights reserved.
//
# include <iostream>
# include "PhoneBook.h"
# include "PhoneEntry.h"

using namespace std;

//This is the constructor for an empty object. It will initialize all the values for that object

PhoneBook::PhoneBook()
{
    maximumSize = 10;
    numEntries = 0;
    entries = new PhoneEntry[maximumSize];
}

//This is another constructor where the user can specify the number of entries. It will initialze all the values
//for that object

PhoneBook::PhoneBook(unsigned int maxEntries)
{
    maximumSize = maxEntries;
    numEntries = 0;
    entries = new PhoneEntry[maxEntries];
}

//This is the copy constructor that is used in this class

PhoneBook::PhoneBook(const PhoneBook &otherBook)
{
    maximumSize = otherBook.getMaxSize();
    numEntries = otherBook.getSize();
    entries = new PhoneEntry[maximumSize];
    for(unsigned int i = 0; i < numEntries; i++)
    {
        entries[i] = otherBook.entries[i];
    }
}

//This is the destructor. It is used to delete the array after the program ends

PhoneBook::~PhoneBook()
{
    delete [] entries;
    entries = nullptr;
}

//The add member function will fill in the next available PhoneEntry with the passed in name and number

void PhoneBook::add(string name, string number)
{
    if(numEntries < maximumSize)
    {

      entries[numEntries].setName(name);
      entries[numEntries].setNumber(number);

      numEntries++;
    }
}

//The getSize member function returns the size of the current number of entries

unsigned int PhoneBook::getSize() const
{
    return numEntries;
}

//The getMaxSize member function returns the size of the maximum number of entries

unsigned int PhoneBook::getMaxSize() const
{
    return maximumSize;
}

//The removeByName member function will remove the first entry in the phone book it finds that has a name that
//matches the passed parameter. It implements the first option.

void PhoneBook::removeByName(std::string name)
{
    int val = 0;
    for(unsigned int i = 0; i < numEntries; i++)
    {
        if(name == entries[i].getName())
        {
            val = i;
            break;
        }
    }
    if(val != 0)
        entries[val] = entries[val-1];
    numEntries--;
}

//The removeByNumber member function will remove the first entry in the phone book it finds that has a number that
//matches the passed parameter. It implements the first option.

void PhoneBook::removeByNumber(std::string number)
{
    int val = 0;
    for(unsigned int i = 0; i < numEntries; i++)
    {
        if(number == entries[i].getNumber())
        {
            val = i;
            break;
        }
    }
    entries[val] = entries[numEntries-1];
    numEntries--;
}

//The remove member function will remove the first entry in the phone book it finds that has a name and number that
//matches the passed parameter. It implements the first option.

void PhoneBook::remove(const PhoneEntry &entry)
{
    //using option 1
    int val = 0;
    for(int i = 0; i < numEntries; i++)
    {
        if(entry == entries[i])
        {
            val = i;
            break;
        }
    }
    entries[val] = entries[numEntries-1];
    numEntries--;
}


//The phoneEntryAt function will return the current entry at the index passed to the function via the position parameter

const PhoneEntry& PhoneBook::at(int position) const
{
    static PhoneEntry currentEntry;

    //If position > current size return the last valid entry

    if (position > (numEntries - 1))
    {
        currentEntry = entries[numEntries - 1];
    }

    //If position is valid return that entry

    if (position <= (numEntries - 1))
    {
        currentEntry = entries[position];
    }

    return currentEntry;
}

//The operator[] function will return the current entry at the index passed to the function via the position parameter

const PhoneEntry& PhoneBook::operator[](int position) const
{
    //If position > current size return the last valid entry

    if (position > (numEntries - 1))
    {
        return entries[numEntries - 1];
    }

    //If position is valid return that entry

    else
    {
        return entries[position];
    }
}

//The operator= member function makes sure that the left hand side of an assignment does not create a memory leak

const PhoneBook& PhoneBook::operator=(const PhoneBook &rhs)
{

    if(this != &rhs)
    {
        delete [] entries;
        maximumSize = rhs.getMaxSize();
        entries = new PhoneEntry[maximumSize];
        numEntries = rhs.getSize();
        for(unsigned int i = 0; i < numEntries; i++)
        {
            entries[i] = rhs.entries[i];
        }
    }
    return *this;
}

    int PhoneBook::findFirstByName(const std::string &name) const{
        string val;
           for(unsigned int i = 0; i < numEntries; i++)
           {
               if(name == entries[i].getName())
               {
                   return i;
               }
           }
        return -1;
    }
    int PhoneBook::findFirstByNumber(const string &number) const{
        string val;
        //int number1 = atoi(number.c_str());
        //cout << "this is number1 " << number1;
           for(unsigned int i = 0; i < numEntries; i++)
           {
               if(number == (entries[i].getNumber()))
               {
                   return i;
               }
           }
        return -1;
    }
    int PhoneBook::findFirst(const PhoneEntry &entry) const{
        //PhoneEntry pEntry;
        int val = 0;
        for(int i = 0; i < numEntries; i++)
        {
            if(entry == (entries[i]))
            {
                val = i;
                break;
            }
        }
       // return (pEntry.PhoneEntry::operator==(entry));
        return val;
    }
    int PhoneBook::getCapacity() const{
        return maximumSize;
    }
    PhoneEntry& PhoneBook::at(int position){
        PhoneEntry currentEntry1;

        //If position > current size return the last valid entry

        if (position > (numEntries - 1))
        {
            return entries[numEntries - 1];
        }

        //If position is valid return that entry

        else
        {
            return entries[position];
        }


    }
    PhoneEntry& PhoneBook::operator[](int position){

        //If position > current size return the last valid entry

        if (position > (numEntries - 1))
        {
            return entries[numEntries - 1];
        }

        //If position is valid return that entry

        else
        {
            return entries[position];
        }
    }
