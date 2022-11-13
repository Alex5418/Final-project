#include "filereading.h"
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

vector<string> filereading::GetSubstrs(const std::string& str,
                                                char delimiter) {
  size_t last = 0;
  vector<string> substrs;
  for (size_t i = 0; i != str.length(); ++i) {
    if (str.at(i) == delimiter) {
      string substr = str.substr(last, i - last);
      last = i + 1;
      substrs.push_back(substr);
    }
  }
  std::string substr = str.substr(last, str.length() - last);
  substrs.push_back(substr);

  return substrs;
}

void filereading::readairport(string file_airport) {
    ifstream ifs{file_airport};
    for(string line; getline(ifs, line); line = ""){
        vector<std::string> temp = filereading::GetSubstrs(line, ',');
        Airport tem_airport();
        for (size_t i = 0; i < temp.size(); i++) {
            temp[i] = remove_quote(temp[i]);
        }
        if (check_num(temp[0])) {
            tem_airport = stoi(temp[0]);
        }

        airports_vector.push_back(tem_airport);
    }

}
        
void filereading::readairrout(string file_rout) {
    ifstream ifs{file_rout};
    for(string line; getline(ifs, line); line = ""){
        vector<string> rout_temp = filereading::GetSubstrs(line, ',');
        
    }
}

bool filereading::check_num(string var) {
    try {
        double tem = stold(var);
    } catch (...) {
        return false;
    }
    return true;
}

string filereading::remove_quote(string substr) {
    if (substr[0] == '\"' && substr[substr.length() - 1] == '\"') {
        substr.erase(substr.begin());
        substr.erase(substr.end() - 1);
    }
    return substr
}