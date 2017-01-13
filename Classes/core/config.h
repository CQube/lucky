#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <fstream>
#include <sstream>
#include <vector>

class dConf 
{
public:

	static std::string getValueByKey(std::string fname, std::string key)
	{
		std::ifstream in(fname.c_str());
		std::string s, f1, f2, f3;

		s = "";
		while (std::getline(in, s)) {
			std::istringstream iss(s);
			if (iss >> f1 >> f2 >> f3 && f1 == key) {
				s = f3;
				break;
			}
		}
		in.close();
		return s;
	}

	static void setValueByKey(std::string fname, std::string key, std::string newValue)
	{
		std::string f1, f2, f3;
		std::ifstream ifs(fname.c_str());
		std::vector<std::string> Vec;
		while (!ifs.eof()) { std::string s; std::getline(ifs, s); Vec.push_back(s); } //читаем файл в вектор строк
		for (std::vector<std::string>::iterator it = Vec.begin(); it != Vec.end(); ++it) { //меняем нужную строку
			std::istringstream iss(*it);
			if (iss >> f1 >> f2 >> f3 && f1 == key) {
				*it = f1 + " " + f2 + " " + newValue;
				break;
			}
		}
		ifs.close();
		std::ofstream ofs(fname.c_str());
		for (std::vector<std::string>::iterator it = Vec.begin(); it != Vec.end(); ++it) { //пишем вектор в файл
			if (*it == "")						//во избежание пустых строк при перезаписи //костыль?									
				continue;
			ofs << *it << std::endl;
		}
		ofs.close();
	}
	//=================================someConvertors

	static inline bool stringToBool(std::string const& s)//convert string to bool
	{ 
		if (s == "0")
			return false;
		else
			return true;
	}

	static inline const char * const boolToString(bool b)//convert bool to string
	{
		return b ? "1" : "0";
	}

}; //end namespace dConf
#endif _CONFIG_H_