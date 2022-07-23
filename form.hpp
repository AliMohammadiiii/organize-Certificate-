#ifndef form_hpp_
#define form_hpp_
#include "general.hpp"
#include"permit.hpp"
class Permit;
class Form
{
public:
	Form(string initializeName, string initializeContent);
	void addPrerequisitesPerimit(Permit* inputPrerequisites);
	void confrim_form(vector < Form* >& forms, vector < Permit* >& permits);
	string print_file(int align_set);
	string get_name();
	bool are_you(string _name);
private:
	string name;
	string content;
	bool isItConfrim;
	vector <Permit*> prerequisites;
};


#endif // !form_hpp_

