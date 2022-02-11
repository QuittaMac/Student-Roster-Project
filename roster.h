
class roster {
public:
	Student* classRosterArray[5];
	~roster();
	int index = 0;
	
	void parse(string token);
	
	void add(string xstudentID, string xfirstName, string xlastName, string xemailAddress, int xage, int numDaysToComplete0, int numDaysToComplete1, int numDaysToComplete2, DegreeProgram xdegreeProgram);
	
	void printAll();
	void printinvalidEmails();
	void printAverageDaysInCourse(string GetStudentID);
	void printByDegreeProgram(DegreeProgram xdegreeProgram);
	void remove(string xstudentID);
	
};

