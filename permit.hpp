#ifndef permit_hpp_
#define permit_hpp_
#include "general.hpp"
#include "form.hpp"
class Form;
class Permit
{
public:
	Permit(string initName, char initSignType, string initPermitName, string initManager, string initCEO, vector < string > init_requirement_list);
	void addPrerequisitesPerimit(Permit* inputPrerequisites);
	void onEvent(vector < Form* >& forms, vector < Permit* >& permits);
	string get_info_permit(vector < Form* >& forms, vector < Permit* >& permits, int align_set);
	void print(vector < Form* >& forms, vector < Permit* >& permits);
	vector < string > get_requirement_list() { return requirement_list; }
	bool are_you(string _name) { return permitName == _name; }
private:
	string get_signature();
	string name;
	char signType;
	string permitName;
	vector <Permit*> prerequisites;
	int numberOfAccept;
	vector < string > requirement_list;
	string manager;
	string	CEO;
	bool isItConfrim;
};
#endif // !permit_hpp_
