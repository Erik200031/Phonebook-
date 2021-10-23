#pragma once
#include <iostream>
#include <vector>
#include <string>
#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_
//class declaration
class User
{
  public:
    User();
    void use_phonebook();
  private:
    std::string fullname;
    int age;
};

class Phonebook
{
  public:
    void DisplayRecords();
    void AddNumber();
    void deleteRecord();
    void modifyRecord();
    void search();
  public:
    Phonebook();
   ~Phonebook(){}
    void set_fname(std::string);
    void set_mobile(std::string);
    void set_addres(std::string);
    std::string get_fname();
    std::string get_mobile();
    std::string get_addres();
  
  private:
    std::string fullname;
  	std::string mobile;
  	std::string address;
    std::vector<std::string> excvec;
   
};

#endif//PHONEBOOK_H_