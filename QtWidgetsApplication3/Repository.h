#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include "Utils.h"
#include "IdGenerator.h"
#include <map>
#include <iostream>
#include <iterator>

template<class T>
class Repository
{
private:
	std::string filename;
	std::map<unsigned int, T*>* map;
	std::map<unsigned int, T*>* LoadFromFile()
	{
		map = new std::map<unsigned int, T*>();
		std::ifstream inf{ filename };
		std::string line;
		int counter = -1;
		while (std::getline(inf, line))
		{
			std::stringstream ss{ line };
			unsigned int id;
			char c;
			ss >> id >> c;
			ss >> line;
			T* v = Utils::ModelFromString<T>(line, ',');
			map->insert(std::pair<unsigned int, T*>(id, v));
		}
		return map;
	}
	void SaveToFile()
	{
		std::ofstream outf{ filename };
		if (!outf)
		{
			std::cerr << "File '" + filename + "' could not be opened for writing" << std::endl;
			return;
		}

		for (std::map<unsigned int, T*>::iterator it = map->begin(); it != map->end(); ++it)
		{
			std::string str = *it->second;
			outf << it->first << "," << str << std::endl;
		}
	}
public:
	Repository(std::string filename)
	{
		this->filename = filename;
		map = LoadFromFile();
	}
	~Repository()
	{
		SaveToFile();
		for (std::map<unsigned int, T*>::iterator it = map->begin(); it != map->end(); ++it)
		{
			delete it->second;
		}
		delete map;
	}
	typename std::map<unsigned int, T*>::iterator GetIteratorBegin()
	{
		return map->begin();
	}
	typename std::map<unsigned int, T*>::iterator GetIteratorEnd()
	{
		return map->end();
	}
	void DeleteElementById(unsigned int id)
	{
		map->erase(map->find(id));
	}
	unsigned int GetIdOfElement(T* elem)
	{
		for (std::map<unsigned int, T*>::iterator it = GetIteratorBegin(); it != GetIteratorEnd(); it++)
		{
			if (it.second == elem)
			{
				return it.first;
			}
		}
		return 0;
	}
	T* GetElementById(unsigned int id)
	{
		return map->find(id)->second;
	}
	void AddElement(T* elem)
	{
		map->insert(std::pair<unsigned int, T*>(IdGenerator::GenerateId(), elem));
	}
};