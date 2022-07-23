#include "form.hpp"
Form::Form(string initializeName, string initializeContent)
{
	name = initializeName;
	content = initializeContent;
	isItConfrim = false;
}
bool Form::are_you(string _name)
{
	if (name == _name)
	{
		return true;
	}
	return false;
}
void Form::addPrerequisitesPerimit(Permit* inputPrerequisites)
{
	prerequisites.push_back(inputPrerequisites);
}
void Form::confrim_form(vector < Form* >& forms, vector < Permit* >& permits)
{
	isItConfrim = true;
	for (int prerequisites_counter = 0; prerequisites_counter < prerequisites.size(); prerequisites_counter++)
	{
		prerequisites[prerequisites_counter]->onEvent(forms, permits);
	}
}
string Form::print_file(int align_set)
{
	string output;
	output = shift_line(align_set);
	output += "Name: ";
	output += name + "\n";
	output += shift_line(align_set);
	output += "Content: ";
	output += content;
	return output;
}
string Form::get_name()
{
	return name;
}
