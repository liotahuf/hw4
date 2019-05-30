#ifndef STUDENT_H
#define STUDENT_H

#define NULL nullptr
typedef EE_Course* pEE_Course;
typedef CS_Course* pCS_Course;

class Student : public Person {
public:
	Student(EE_Course * EE_courses_arr, int EE_course_num, CS_Course * CS_courses_arr, int CS_course_num);
	virtual ~Student();
	int getCourseCnt() const{ return EE_course_num + CS_course_num; }
	int addEE_Course(EE_Course* p_EE_Course);
	int addCS_Course(CS_Course* p_CS_Course);
	int remCourse(int course_num);
	pEE_Course getEE_Course const(int EE_course_num);
	pCS_Course getCS_Course const(int CS_course_num);
	int getAvg const();
	void print const();

private:
	pEE_Course* EE_courses_arr_;
	int EE_course_num_;
	pCS_Course* CS_courses_arr_;
	int CS_course_num_;


}
#endif
