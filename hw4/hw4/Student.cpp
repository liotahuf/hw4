#include <iostream> 
#include <math.h>  
#include "Proj.h"
#include "Student.h"


 Student::Student(pEE_Course* EE_courses_arr, int EE_course_num, pCS_Course* CS_courses_arr, int CS_course_num):
	 EE_course_num(EE_course_num_), CS_course_num(CS_course_num_)
{
	 pEE_Course* pEE_courses_arr = new pEE_Course[MAX_COURSE_NUM];
	 pCS_Course* pCS_courses_arr = new pCS_Course[MAX_COURSE_NUM]; //@@@@@@@@@@@@@@to check if i need to inizialize and if i need constructor and distructor
}
 Student::~Student()
 {
	 delete[] pEE_courses_arr;
	 delete[] pCS_courses_arr;
 }
 
int Student::addEE_Course(EE_Course* p_EE_Course)
{
	if (p_EE_Course == NULL)
	{
		return 0;
	}
	for (int i=0; i < MAX_COURSE_NUM; i++)
	{
		if (pEE_courses_arr[i] == NULL)
		{
			pEE_courses_arr[i] = p_EE_Course;
			return 1;
		}
	}
	return 0;
}


int Student::addCS_Course(CS_Course* p_CS_Course)
{
	if (p_CS_Course == NULL)
	{
		return 0;
	}
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (pCS_courses_arr[i] == NULL)
		{
			pCS_courses_arr[i] = p_CS_Course;
			return 1;
		}
	}
	return 0;

}

int Student::remCourse(int course_num)
{
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (pCS_courses_arr[i]->num_ == course_num)
		{
			delete pCS_courses_arr[i];
			pCS_courses_arr[i] == NULL;
			return 1;
		}

		else if (pEE_courses_arr[i]->num_ == course_num)
		{
			delete pEE_courses_arr[i];
			pEE_courses_arr[i] == NULL;
			return 1;
		}

	}
	return 0;
}

pEE_Course Student::getEE_Course const(int EE_course_num)
{
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (pEE_courses_arr[i]->num_ == EE_course_num)
		{
			return pEE_courses_arr[i];
		}
	}
	return NULL;
}

pCS_Course Student::getCS_Course const(int CS_course_num)
{
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (pCS_courses_arr[i]->num_ == CS_course_num)
		{
			return pCS_courses_arr[i];
		}
	}
	return NULL;
}

int Student::getAvg const()
{
	double sum = 0;
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		sum += pEE_courses_arr[i]->getCourseGrade();
	}
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		sum += pCS_courses_arr[i]->getCourseGrade();
	}
	return round(sum / (EE_course_num + CS_course_num))
}


using namespace std;

void Student::print const()
{
	cout << "SName:" << name_ << endl;
	cout << "SID:" << id_ << endl;
	cout << "Avg.:" << Student.getAvg() << endl;
	cout << "EE:" << endl;

	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (pEE_courses_arr[i] != NULL)
		{
			cout << pEE_courses_arr[i]->num_ << " " << pEE_courses_arr[i]->name_ << " " << pEE_courses_arr[i]->getCourseGrade() << endl;;
		}
	}
	
	cout << "CS courses:" << endl;
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (pCS_courses_arr[i] != NULL)
		{
			cout << pCS_courses_arr[i]->num_ << " " << pCS_courses_arr[i]->name_ << " " << pCS_courses_arr[i]->getCourseGrade() << endl;;
		}
	}
}