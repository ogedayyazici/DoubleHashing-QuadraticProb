#include "the_double_hashing.h"
#include <iostream>

//Second function going to be used in need during double hashing. 
int the_double_hashing::DoubleHashing(int key)
{
	int result = key % 13;
	return result;
}

//Add function of double hashing, that is working with the principle of sipmly checking if the place is empty or not. 
//(Note: "N" means empty and insertible "0" Means not insertible because it is not rehashed yet!) 
void the_double_hashing::Add(int key, std::string data)
{
    int size = TableSize();
    int result = Hashing(key);
    if (hashTable[result] == "N") {
        hashTable[result] = data;
        keyTable[result] = key;
    }
    else { //If the first function's result place is already occupied
        result = DoubleHashing(key);
        if (hashTable[result] == "N") { //Checks if the place by second function is empty
            hashTable[result] = data;
            keyTable[result] = key;
        }
        else
        {
            result = result + size / 2; //If its still occupied with the second fuction
            hashTable[result] = data; // Insert to the 2nd half of the table
            keyTable[result] = key;
        }
    }
}

void the_double_hashing::DoubleSeq() //The sequence that is expected from us that explained in the PDF
{
    MenUI();

    Filler();

    Add(4218, "Amaranth");
    Add(4011, "Aniseed");
    Add(4229, "ArcticButterbur");
    Add(4066, "BarbadosGooseberry");
    
    std::cout << "After Adding 4th Element:\n" << std::endl;
    
    Print();
    
    std::cout << "\nPress enter to continue... " << std::endl;
    std::cin.get();

    Add(4073, "GardenPea");
    
    std::cout << std::endl;
    std::cout << "After Adding 5th Element:\n" << std::endl;
    
    Rehash(); //REHASH!!
    Print();
    
    std::cout << "\nPress enter to continue... " << std::endl;
    std::cin.get();

    Add(4608, "Cheeseweed");
    Add(3175, "Bean");
    Add(4065, "BlackMustard");
    Add(4550, "BokChoi");

    std::cout << std::endl;
    std::cout << "After Adding 9th Element:\n" << std::endl;
    
    Print();
    
    std::cout << "\nPress enter to continue... " << std::endl;
    std::cin.get();

    Add(4820, "Broccoli");
    
    std::cout << std::endl;
    std::cout << "After Adding 10th Element:\n" << std::endl;
    
    Rehash(); //REHASH!!
    Print();
    
    std::cout << "\nPress enter to continue... " << std::endl;
    std::cin.get();

    Add(4079, "Brussels Sprouts");
    Add(4709, "Canada Violet");
    Add(4299, "Coriander");
    Add(4926, "DragonsHead");
    Add(4093, "Elephant Bush");
    Add(4750, "Grape");
    Add(4028, "GroundIvy");
    Add(4063, "HookersEveningPrimrose");
    Add(4031, "IndianMustard");
    Add(4818, "InterruptedFern");
    
    std::cout << std::endl;
    std::cout << "After Adding 20th Element:\n" << std::endl;
    
    Print();
    
    std::cout << "\nPress enter to continue... " << std::endl;
    std::cin.get();

    //SEARCH CALLS

    std::cout << "Searching 4218:";
    std::cout << Search(4218) << std::endl;
    std::cout << "Searching 4073:";
    std::cout << Search(4073) << std::endl;
    std::cout << "Searching 4229:";
    std::cout << Search(4229) << std::endl;
    std::cout << std::endl;

    std::cout << "Removing 4608, 4073, 4229:";
    Remove(4608);
    Remove(4073);
    Remove(4229);
    std::cout << std::endl;

    std::cout << "Searching 4608:";
    std::cout << Search(4608) << std::endl;
    std::cout << "Searching 4073:";
    std::cout << Search(4073) << std::endl;
    std::cout << "Searching 4229:";
    std::cout << Search(4229) << std::endl;
    std::cout << "\nPress enter to continue... " << std::endl;
    std::cin.get();

    std::cout << std::endl;

    std::cout << "HashTable after deletion:" << std::endl;
    Print();
    std::cout << "\nEnd of the sequence. Press enter to go back... " << std::endl;
    std::cin.ignore();
}
