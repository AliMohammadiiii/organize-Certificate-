#include "permit.hpp"


Permit::Permit(string initName, char initSignType, string initPermitName, string initManager, string initCEO, vector < string > init_requirement_list)
{
	name = initName;
	signType = initSignType;
	permitName = initPermitName;
	manager = initManager;
	CEO = initCEO;
	isItConfrim = false;
	numberOfAccept = 0;
	requirement_list = init_requirement_list;
}
void Permit::addPrerequisitesPerimit(Permit* inputPrerequisites)
{
	prerequisites.push_back(inputPrerequisites);
}
void Permit::onEvent(vector < Form* >& forms, vector < Permit* >& permits)
{
	numberOfAccept++;
	if ((numberOfAccept == (requirement_list.size()) && !isItConfrim))
	{
		isItConfrim = true;
		if (prerequisites.size() != 0)
		{
			for (int prerequisites_counter = 0; prerequisites_counter < prerequisites.size(); prerequisites_counter++)
			{
				prerequisites[prerequisites_counter]->onEvent(forms, permits);
			}
		}
		else
		{
			print(forms, permits);
			exit(0);
		}
	}
}
string Permit::get_signature()
{
	if (signType == 'm')
	{
		return manager;
	}
	else if (signType == 'c')
	{
		return CEO;
	}
	else
	{
		return name;
	}
}
string Permit::get_info_permit(vector < Form* >& forms, vector < Permit* >& permits, int align_set)
{
	string info;
	info += shift_line(align_set);
	info += "name: " + permitName + "\n";
	info += shift_line(align_set);
	info += "This permit consists of: {\n";
	for (int requirement_conter = 0; requirement_conter < requirement_list.size(); requirement_conter++)
	{
		info += shift_line(align_set + 1);
		info += "#" + to_string(requirement_conter + 1) + '\n';
		Form* form = NULL;
		form = find_form_by_name(forms, requirement_list[requirement_conter]);
		if (form != NULL)
		{
			info += form->print_file(align_set + 1);
			info += "\n";

		}
		Permit* perimit_address = NULL;
		perimit_address = find_permit_by_name(permits, requirement_list[requirement_conter]);
		if (perimit_address != NULL)
		{
			info += perimit_address->get_info_permit(forms, permits, align_set + 1);
		}
	}
	info += shift_line(align_set);
	info += "}\n";
	info += shift_line(align_set);
	info += "Signature: ";
	info += get_signature() + "\n";
	return info;
}

void  Permit::print(vector < Form* >& forms, vector < Permit* >& permits)
{ 
	cout << get_info_permit(forms, permits, 0);
};

