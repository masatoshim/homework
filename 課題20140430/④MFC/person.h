#pragma once

#define NAME		40									//–¼•¶š”
#define JOB			40									//E‹Æ•¶š”

//ŒÂlî•ñ
class person{
	char name[NAME];
	int age;
	char job[JOB];
public:
	person();
	person(char *n, int a, char *j);
	char *get_name(){ return name; }
	int get_age(){ return age; }
	char *get_job(){ return job; }

	//–¼ŒŸõ
	bool name_judge(char *n);

};



