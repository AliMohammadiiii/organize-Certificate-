#include "interface.hpp"

void Connector::run()
{
	read_intput();
	set_prerequisites();
	string command, form_name;
	Form* form;
	while (cin >> command)
	{
		if (command == CONFIRM)
		{
			cin >> form_name;
			form = find_form_by_name(forms, form_name);
			form->confrim_form(forms, permits);
		}
	}
}
void Connector::read_Permit()
{
	size_t pos = 0;
	string address;
	cin >> address;
	ifstream form_file(address);
	string line, token;
	Permit* permit;
	getline(form_file, line);
	string name, permit_name, requirements, manager, CEO;
	char sign_type;
	int number_permit_input = 6;
	while (getline(form_file, line))
	{
		vector <Form*> need_form;
		vector < string > form_name, permit_names, requirment_list;
		if (line == "")
		{
			break;
		}
		for (int i = 0; i < number_permit_input; i++)
		{
			pos = line.find(delimiter);
			token = line.substr(0, pos);
			line.erase(0, pos + 1);
			switch (i)
			{
			case 0:
				name = token;
				break;
			case 1:
				sign_type = token[0];
				break;
			case 2:
				permit_name = token;
				break;
			case 3:
				requirements = token;
				break;
			case 4:
				manager = token;
				break;
			case 5:
				CEO = token;
				break;
			default:
				break;
			}
		}
		seperate_string(form_name, permit_names, requirements, requirment_list);
		need_form = find_Permit_form(form_name);
		permit = new Permit(name, sign_type, permit_name, manager, CEO, requirment_list);
		permits.push_back(permit);
	}
}
vector <Form*> Connector::find_Permit_form(vector < string > form_name)
{
	vector <Form*> forms_Permit;
	for (int form_counter = 0; form_counter < forms.size(); form_counter++)
	{
		for (int string_counter = 0; string_counter < form_name.size(); string_counter++)
		{
			if (forms[form_counter]->get_name() == form_name[string_counter])
			{
				forms_Permit.push_back(forms[form_counter]);
			}
		}
	}
	return forms_Permit;
}
void Connector::seperate_string(vector<string> form_name, vector<string> permit_names, string names, vector <string>& requirment_list)
{
	char need_delimiter = '-';
	size_t pos = 0;
	string token;
	while ((pos = names.find(need_delimiter)) != string::npos) {
		token = names.substr(0, pos);
		if (token[0] == FORM_SIGN)
		{
			form_name.push_back(token);
			requirment_list.push_back(token);
		}
		else if (token[0] == PERMIT_SIGN)
		{
			permit_names.push_back(token);
			requirment_list.push_back(token);
		}
		names.erase(0, pos + 1);
	}
	if (names[0] == FORM_SIGN)
	{
		form_name.push_back(names);
		requirment_list.push_back(names);
	}
	else if (names[0] == PERMIT_SIGN)
	{
		permit_names.push_back(names);
		requirment_list.push_back(names);
	}

}
void Connector::read_form()
{
	size_t pos = 0;
	string address;
	cin >> address;
	ifstream form_file(address);
	string line, token;
	Form* form;
	getline(form_file, line);
	string name, content;
	while (getline(form_file, line))
	{
		if (line == "")
		{
			break;
		}
		for (int i = 0; i < 2; i++)
		{
			pos = line.find(delimiter);
			token = line.substr(0, pos);
			line.erase(0, pos + 1);
			if (i % 2 == 0)
			{
				name = token;
			}
			else
			{
				content = token;
			}
		}
		form = new Form(name, content);
		forms.push_back(form);
	}
}
void Connector::read_intput()
{
	read_form();
	read_Permit();
}
void Connector::set_prerequisites()
{
	vector < string > requirement_list;
	Permit* perimit_address;
	for (int permit_counter = 0; permit_counter < permits.size(); permit_counter++)
	{
		requirement_list = permits[permit_counter]->get_requirement_list();
		for (int requirement_conter = 0; requirement_conter < requirement_list.size(); requirement_conter++)
		{
			Form* form = NULL;
			form = find_form_by_name(forms, requirement_list[requirement_conter]);
			if (form != NULL)
			{
				form->addPrerequisitesPerimit(permits[permit_counter]);
				continue;
			}
			Permit* perimit_address = NULL;
			perimit_address = find_permit_by_name(permits, requirement_list[requirement_conter]);
			if (perimit_address != NULL)
			{
				perimit_address->addPrerequisitesPerimit(permits[permit_counter]);
				continue;
			}
		}
	}
}
