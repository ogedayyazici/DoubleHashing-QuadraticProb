#include "I_hash.h"

void I_hash::Filler() { //Code that initilaizes the table

    for (int i = 0; i < 10; i++) // Adds "N" for the first 10 place to inditace that it is insertible
        hashTable.push_back("N");

    for (int i = 10; i < 40; i++)// Adds "0" for the rest to indicate thats they are not insertibe (until rehashed!)
        hashTable.push_back("0");

    for (int i = 0; i < 40; i++)//Initizalizes the table that we store our keys
        keyTable.push_back(0);

    tableLength = hashTable.size();// calls tablelength function the recalculate the size
}

int I_hash::TableSize() {// The function that calculates the insetible places, 
    int count = 0;       // (the places that are not required to be rehashed before insertion)
    for (int i = 0; i < tableLength; i++)
    {
        if (hashTable[i] == "0") {}
        else {
            count++; //Simply counts anywhere rather than zero (Already occupied and insetible places)
        }
    }
    return count;
}

std::string I_hash::Search(int key) { //Checks for the key in the keyTable and returns the exact value in the hashTable
    for (int i = 0; i < keyTable.size(); i++)
    {
        if (keyTable[i] == key)
            return hashTable[i];
    }
}

void I_hash::Remove(int key) { //Calls the search function, and sets the value needs to be deleted as "N" (To be able to reinsert)
    std::string result = Search(key);
    for (int i = 0; i < hashTable.size(); i++)
    {
        if (hashTable[i] == result) {
            hashTable[i] = "N";
        }
    }
}

int I_hash::Hashing(int key) // Our main hash function that used in both Quadratic Probing and Double Hashing
                             // Double hashing's second function is in its .cpp file.
{
    int result = key % 10;
    return result;
}

void I_hash::Rehash() {     //The function that rehashes 
    int size = TableSize(); 
    int doublesize = 2 * size; //Doubles the size

    for (int i = size; i < doublesize; i++)
    {
        hashTable[i] = "N"; //Indicates as insetible till reaching the new doubled size.
    }
    std::cout << "Rehashing...\n" << std::endl; //Prints warning as rehashed!
}

void I_hash::Print() {      //The function that prints
    for (int i = 0; i < tableLength; i++) {    //Runs one by one up to size
        std::string name = hashTable[i];
        if (name == "N")                      
            std::cout << i << std::endl;      //Prints only the level indicator if its empty
        else if (name == "0") {}              //Does nothing if its not insetible (not rehashed yet)
        else
            std::cout << i << " --> " << name << std::endl; //Prints anything else
    }
}

void I_hash::MenUI() {
    std::cout << "\nALGORITHMS AND DATA STRUCTURES II ASSIGNMENT 3 \n" << std::endl;
    
    std::cout << "Hash Table:\n " << std::endl;
    std::cout << "	1 -> After Adding 4th Element  " << std::endl;
    std::cout << "	2 -> After Adding 5th Element  " << std::endl;
    std::cout << "	3 -> After Adding 9th Element  " << std::endl;
    std::cout << "	4 -> After Adding 10th Element " << std::endl;
    std::cout << "	5 -> After Adding 20th Element " << std::endl;
    std::cout << "	6 -> Removing 4608, 4073, 4229 " << std::endl;
    std::cout << " \t7 -> HashTable after deletion\n" << std::endl;
    std::cin.ignore();
    std::cout << "The sequence will continue on the order. Press enter to continue... " << std::endl;
    std::cin.get();
}