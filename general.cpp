#include "general.hpp"
string shift_line(int align_set)
{
	string out_txt = "";
	for (int i = 0; i < align_set; i++)
	{
		out_txt += shift_text;
	}
	return out_txt;
}
Permit* find_permit_by_name(vector < Permit* >& permits, string name)
{
	for (int permit_counter = 0; permit_counter < permits.size(); permit_counter++)
	{
		if (permits[permit_counter]->are_you(name))
		{
			return permits[permit_counter];
		}
	}
	return NULL;
}
Form* find_form_by_name(vector < Form* >& forms, string name)
{
	for (int forms_counter = 0; forms_counter < forms.size(); forms_counter++)
	{
		if (forms[forms_counter]->are_you(name))
		{
			return forms[forms_counter];
		}
	}
	return NULL;
}