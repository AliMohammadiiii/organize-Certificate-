#ifndef general_hpp_
#define general_hpp_
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
const string shift_text = "    ";
const char delimiter = ',';
#include "form.hpp"
#include "permit.hpp"
class Form;
class Permit;
string shift_line(int align_set);
Permit* find_permit_by_name(vector < Permit* >& permits, string name);
Form* find_form_by_name(vector < Form* >& forms, string name);

#endif // !general_hpp_

