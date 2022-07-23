#ifndef interface_hpp_
#define interface_hpp_
#include "general.hpp"
#include "form.hpp"
#include "permit.hpp"
#define CONFIRM "Confirm"
#define FORM_SIGN 'f'
#define PERMIT_SIGN 'p'
class Connector
{
public:
	Connector(){};
	void run();
	void play();
	vector < Form* > forms;
	vector < Permit* > permits;
private:
	void read_form();
	void read_intput();
	void set_prerequisites();
	vector <Form*> find_Permit_form(vector < string > form_name);
	void seperate_string(vector<string>form_name, vector<string>permit_names, string names, vector <string>& requirment_list);
	void read_Permit();

};
#endif // !interface_hpp_
