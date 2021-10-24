#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdio.h>
#include "phonebook.h"
// User class implementation
User::User ()
{
use_phonebook ();
}

void User::use_phonebook ()
{
Phonebook obj;
} 

// Phonebook class implementation
Phonebook::Phonebook ()
{
    int ch;
    do
    {
        system ("clear");
        std::cout << "............................................\n";
        std::cout << "                PHONE BOOK\n";
        std::cout << "--------------------------------------------\n\n";
        std::cout << "::::::::::::::: PROGRAMM MENU :::::::::::::::\n";
        std::cout << "0. Exit\n";
        std::cout << "1. Save New Phone Record\n";
        std::cout << "2. Display All Saved Records\n";
        std::cout << "3. Delete Specific Record\n";
        std::cout << "4. Modify Existing Record\n";
        std::cout << "5. Search Record using Fullname\n";
        std::cout << "Enter Your Choice : ";
        std::cin >> ch;
        system ("clear");
        switch (ch)
        {
        case 1:
        	  AddNumber ();
        	  break;
        case 2:
        	  DisplayRecords ();
        	  break;
        case 3:
        	  deleteRecord ();
        	  break;
        case 4:
        	  modifyRecord ();
        	  break;
        case 5:
        	  search ();
        	  break;
        }
    }
      while (ch);
}

void Phonebook::DisplayRecords () 
{
    std::ifstream fin;
    fin.open ("test.txt", std::ios_base::out | std::ios_base::binary | std::ios_base::app);
    while (!fin.eof ())
    {
        std::string tmp;
        tmp = "";
        std::getline (fin, tmp);
        if (tmp == "")
        {
            continue;
        }
        excvec.push_back (tmp);
    }
    fin.close ();
    std::cout << "\n...............PHONE BOOK RECORD...............\n";
    int count = 1;
    for (int i = 0; i < excvec.size (); i += 3)
    {
        std::cout << ".....The " << "\" ID-> \" " << count <<" Person's info....\n";
        std::cout << "Name       : " << excvec[i] << std::endl;
        std::cout << "Mobile No. : " << excvec[i + 1] << std::endl;
        std::cout << "Address   : " << excvec[i + 2] << std::endl;
        count++;
    } 
    excvec.erase (excvec.begin (), excvec.end ());
    std::cout << "\nReading of Data File Completed......\n";
    std::cout << "If you want to exit please input '0'\n";
    std::cout << "or If you want to jump to 'PROGRAMM MENU' please input any key : ";
    char tmp;
    std::cin >> tmp;
    if (tmp == '0')
    {
        exit (0);
    }
}

void Phonebook::AddNumber () 
{
    std::ofstream fout;
    fout.open ("test.txt", std::ios_base::out | std::ios_base::binary | std::ios_base::app);
    if (fout.is_open ())
    {
        std::cout << "\n...............CREATE NEW PHONE RECORD...............\n\n";
        std::cout << "Enter Record FullName   : ";
        std::cin.ignore ();
        std::getline (std::cin, this->fullname);
        fout << this->fullname;
        fout << "\n";
        std::cout << "Enter Mobile Number : ";
        std::getline (std::cin, this->mobile);
        fout << this->mobile;
        fout << "\n";
        std::cout << "Enter Address  : ";
        std::getline (std::cin, this->address);
        fout << this->address;
        fout << "\n";
        std::cout << std::endl;
        std::cout << "If you want to exit please input '0'\n";
        std::
        	cout <<
        	"or If you want to save changes and jump to 'PROGRAMM MENU' please input any key : ";
        char tmp;
        std::cin >> tmp;
        if (tmp == '0')
        {
            exit (0);
        }
        
    }
      
    else
    {
        std::cout << "Error : File not found!";
    }
    fout.close ();
}

void Phonebook::deleteRecord ()
{
    std::vector < std::string > temp;
    std::ifstream fin;
    std::ofstream fout;
    fout.open ("test.txt", std::ios_base::out | std::ios_base::binary | std::ios_base::app);
    fin.open ("test.txt", std::ios_base::out | std::ios_base::binary | std::ios_base::app);
    while (!fin.eof ())
    {
        std::string tmp;
        tmp = "";
        std::getline (fin, tmp);
        if (tmp == "")
        {
            continue;
        }
        temp.push_back (tmp);
    }
    std::cout << "If you want to delete the contact please enter the ID : ";
    int tempp;
    std::cin >> tempp;
    temp.erase (temp.begin () + (tempp * 3 - 3),temp.begin () + (tempp * 3));
    std::ofstream ofs;
    ofs.open ("test.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close ();
    for (int i = 0; i < temp.size (); ++i)
    {
        fout << temp[i] << " \n";
    } 
    fout.close ();
    fin.close ();
} 
 
void Phonebook::modifyRecord ()
{
    std::vector < std::string > temp;
    std::ifstream fin;
    std::ofstream fout;
    fout.open ("test.txt", std::ios_base::out | std::ios_base::binary | std::ios_base::app);
    fin.open ("test.txt", std::ios_base::out | std::ios_base::binary | std::ios_base::app);
    while (!fin.eof ())
    {
        std::string tmp;
        tmp = "";
        std::getline (fin, tmp);
        if (tmp == "")
        {
            continue;
        }
        temp.push_back (tmp);
    }
    std::cout << "............................................\n";
    std::cout << "                Modify Record\n";
    std::cout << "--------------------------------------------\n\n";
    std::cout << "0. Exit\n";
    std::cout << "1. Change\n";
    std::cout << " Enter Your Choice : ";
    int tmp;
    std::cin >> tmp;
    if (tmp == 0)
    {
        system ("clear");
        exit (0);
    }
    else if (tmp == 1)
    {
        system ("clear");
        std::cout << "Enter the contact ID : ";
        int tmpp;
        std::cin >> tmpp;
        std::cout << " _____This is the old info _____ \n";
        int count{};
        for (auto it = temp.begin () + (tmpp * 3 - 3);it != temp.begin () + (tmpp * 3); ++it)
        {
            count == 0 ? std::cout << " FullName -> " : count == 1 ? std::cout << " Mobile -> " : std::cout << " Addresa -> ";
            std::cout << *it << "\n";
            ++count;
        }
        std::cout << "\nEnter NEW FullName   : ";
        std::cin.ignore ();
        std::getline (std::cin, this->fullname);
        fout << this->fullname;
        fout << "\n";
        std::cout << "Enter NEW Mobile Number : ";
        std::getline (std::cin, this->mobile);
        fout << this->mobile;
        fout << "\n";
        std::cout << "Enter NEW Address  : ";
        std::getline (std::cin, this->address);
        fout << this->address;
        fout << "\n";
        temp.erase (temp.begin () + (tmpp * 3 - 3), temp.begin () + (tmpp * 3));
        std::ofstream ofs;
        ofs.open ("test.txt", std::ofstream::out | std::ofstream::trunc);
        ofs.close ();
        for (int i = 0; i < temp.size (); ++i)
        {
            fout << temp[i] << " \n";
        } 
        fout.close ();
        fin.close ();
        std::cout << std::endl;
        std::cout << "If you want to exit please input '0'\n";
        std::cout <<"or If you want to save changes and jump to 'PROGRAMM MENU' please input any key : ";
        char tmp;
        std::cin >> tmp;
        if (tmp == '0')
        {
            exit (0);
        }
    }
    fout.close ();
}

void Phonebook::search ()
{
    std::cout << "............................................\n";
    std::cout << "                Search Record\n";
    std::cout << "--------------------------------------------\n\n";
    int count{};
    std::vector < std::string > temp;
    std::ifstream fin;
    fin.open ("test.txt",std::ios_base::out | std::ios_base::binary | std::ios_base::app);
    while (!fin.eof ())
    {
        std::string tmp;
        tmp = "";
        std::getline (fin, tmp);
        if (tmp == "")
        {
            continue;
        }
        temp.push_back (tmp);
    }
    std::cout << "Enter the Fullname -> ";
    std::string input;
    std::cin.get ();
    getline (std::cin, input);
    for (auto it = temp.begin (); it != temp.end (); ++it)
    {
        if (input == *it)
        {
            for (auto itt = it; itt != it + 3; ++it)
            {
                if (count > 2)
                {
                    break;
            	}
                count == 0 ? std::cout << " FullName -> " : count ==1 ? std::cout << " Mobile -> " : std::cout << " Address -> ";
                std::cout << *it << "\n";
                ++count;
            }
        break;
        }
    }
    std::cout << std::endl;
    std::cout << "If you want to exit please input '0'\n";
    std::cout << "or If you want to save changes and jump to 'PROGRAMM MENU' please input any key : ";
    char tmp;
    std::cin >> tmp;
    if (tmp == '0')
    {
     exit (0);
    }
}
