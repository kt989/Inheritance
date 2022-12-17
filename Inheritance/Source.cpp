//inheritance
#include <iostream>
#include <string>
using namespace std;

#define DELIMITER "\n_________________________________________________________________________________\n\n"

#define HUMAN_TAKE_PARAMETRS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETRS last_name, first_name, age
#define STUDENT_TAKE_PARAMETRS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETRS speciality, group, rating, attendance
#define TEACHER_GIVE_PARAMETRS const std::string& speciality, unsigned int experience



class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
	 
public:
	const std::string& get_last_name() const
	{
		return last_name;
	}
	const std::string& get_first_name() const
	{
		return first_name;
	}
	unsigned int get_age() const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	// Constructors
	Human(HUMAN_TAKE_PARAMETRS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "Destructor:\t" << this << endl;
	}

	// Methods:
	virtual std:: ostream& info(std::ostream& os) const
	{
		
		return os<<last_name << " " << first_name << " " << age << " лет\n";
		
	}
};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age() << endl;
}


class Student : public Human
{
	std::string speciality;
	std::string group;
	double rating; //успеваемость
	double attendance; //посещаемость
public:
	const std::string& get_speciality() const
	{
		return speciality;
	}
	const std::string& get_group() const
	{
		return group;
	}
	double get_rating() const
	{
		return rating;
	}
	double get_attendance() const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
	// Constructors:
	Student(
		HUMAN_TAKE_PARAMETRS,
		STUDENT_TAKE_PARAMETRS
	):Human(HUMAN_GIVE_PARAMETRS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	} 

	//Methods:
	virtual std:: ostream& info(std::ostream& os) const
	{
		return Human::info(os) << speciality<<" " << group<<" " << rating<<" " << attendance<<endl;
	}
};


class Teacher : public Human
{
	std::string speciality;
	unsigned int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience() const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	//Constructors:
	Teacher(
		HUMAN_TAKE_PARAMETRS,
		TEACHER_GIVE_PARAMETRS
	): Human(HUMAN_GIVE_PARAMETRS)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;

	}

	//Methods
	virtual std::ostream& info(std::ostream& os) const override
	{
		return Human::info(os) << speciality << " " << experience;
	}
};



class Graduate : public Student
{
	std::string subject;
public:
	const std::string get_subject()
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}

	// Constructors
	Graduate(
		HUMAN_TAKE_PARAMETRS,
		STUDENT_TAKE_PARAMETRS,
		const std::string& subject
	) :Student(HUMAN_GIVE_PARAMETRS, STUDENT_GIVE_PARAMETRS)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}

	//Methods
	virtual std::ostream& info(std::ostream& os) const //override - класс переопределен
	{
		return  Student::info(os) << subject ;
	}
};

//#define INHERITANCE
#define POLYMORPHISM

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE
	Human human("Montana", "Antonio", 25);
	human.info();

	Student stud("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 80, 90);
	stud.info();

	Teacher white("White", "Walter", 50, "Chemistry", 25);
	white.info();

	Graduate grad("Schrader", "Hank", 48, "Criminalistic", "OBN", 85, 80, "How to catch Heisenberg");
	grad.info();
#endif // INHERITANCE

#ifdef POLYMORPHISM
	/*
	Human* p_human1 = new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 80, 90); //указатель на базовый класс
	//хранящий, адрес объекта Student
	Human* p_human2 = new Teacher("White", "Walter", 50, "Chemistry", 25);
	p_human1->info();
	p_human2->info();
	*/
	
	
	//Generalisation:
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 80, 90),
		new Teacher("White", "Walter", 50, "Chemistry", 25), //UpCast
		new Graduate("Schrader", "Hank", 48, "Criminalistic", "OBN", 85, 80, "How to catch Heisenberg"),
		new Student("Vercetti", "Tomas", 30, "Criminalistic", "Vice", 85, 98),
		new Teacher("Diaz", "Recardo", 50, "Weapons distributiin", 20)
	};
	cout << DELIMITER;
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		//group[i]->info();
		cout << *group[i];
		cout << DELIMITER;
	}
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}

#endif // POLYMORPHISM



}