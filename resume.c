/*
 * resume.c
 *
 *  Created on: Nov 1, 2017
 *      Author: CarolinaBrager
 */

#include <stdio.h>
#include <time.h>

typedef struct {
	union {
		const char * company;
		const char * school;
		const char * project;
	};
	union {
		const char * location;
		const char * url;
	};
	union {
		const char * title;
		const char * program;
	};

	const char * dates;
	const char * description[];
} applicant;

typedef applicant job;
typedef applicant school;
typedef applicant project;

/* Contact Information */
const char * name  = "Carolina I. Brager";
const char * email = "cbrager@u.rochester.edu";
const char * phone = "(646) 477-2992";

/* Education */
school college = {
	.school        = "University of Rochester",
	.location      = "Rochester, NY",
	.program       = "Bachelor of Science Computer Science",
	.dates         = "Anticipated May 2020",
	.description   = {
		"Minor in Electrical and Computer Engineering",
		"Relevant Coursework: Data Structures and Algorithms, Computation and Formal Systems, Logic\n  Design, Linear Algebra and Differential Equations",
		"Team manager for the women’s ultimate Frisbee team (May 2017 – Current)",
		NULL
	}
};

school highschool = {
	.school        = "Northfield Mount Hermon",
	.location      = "Mount Hermon",
	.program       = "High School",
	.dates         = "September 2012 - May 2016",
	.description   = {
		"Cum Laude Society (Top 20 percent of the class)",
		"Three times on the Dean’s List: Academic High Honors (No grade lower than an A-) or Academic\n  Honors (Average of B+ with no grade lower than a B) for both semesters of a calendar year",
		"Dwight Lyman Moody Effort Award: Outstanding effort in all areas of school life",
		"Captain of the varsity ultimate team and the junior varsity ice hockey team",
		NULL
	}
};

school * schools[] = {
	&college,
	&highschool,
	NULL
};

/* Experience */

job REU = {
	.company       = "University of Connecticut",
	.location      = "Storrs, CT",
	.title         = "Researcher, Research Experience for Undergraduates",
	.dates         = "June - August 2017",
	.description   = {
		"Created a Python script to improve efficiency in the Voting Technology and Research Center.",
		"Designed the script to assist with the assembly of a file used with another piece of software in the\n  lab.",
		"Wrote a research paper describing the research performed and its applications.",
		NULL
	}
};

job BTcamps = {
	.company       = "Beth Tfiloh Summer Camp",
	.location      = "Reisterstown, MD",
	.title         = "Counselor",
	.dates         = "June - August 2015 and 2014",
	.description   = {
		"Supervised a group of approximately 20 campers and ensured their safety.",
		"Worked in a team of counselors to plan the daily schedule for camp activities.",
		"Helped the campers learn to have constructive conversation when they were frustrated, angry, or in\n  conflict with others.",
		NULL
	}
};

job * jobs[] = {
	&REU,
	&BTcamps,
	NULL
};

/* Personal Projects */
project fingerTwister = {
	.project       = "Finger Twister",
	.url           = "https://github.com/carolina-brager/FingeringDots",
	.dates         = "February 2017 - Current",
	.description   = {
		"Created an iPhone application to learn the basics of Swift and application development.",
		"Currently working on debugging the application and formatting it for all phone sizes.",
		NULL
	}
};

project onlineResume = {
	.project      = "Online Resume",
	.url          = "https://github.com/carolina-brager/Git-practice",
	.dates        = "August 2017",
	.description  = {
		"Created an online resume to practice HTML and CSS.",
		"Created a git repository for the files used in the online resume to develop knowledge of git and the\n  command line.",
		NULL
	}
};

project * projects[] = {
	&fingerTwister,
	&onlineResume,
	NULL
};



void print_resume(applicant *source) {

	printf("%s at %s - %s\n",source->title,source->company,source->location);

	printf("%s\n",source->dates);

	const char ** description;
	for (description =source->description; *description; description++) {
		printf("- %s\n", *description);
	}

	puts("");
}

void print_project(applicant *project){
	printf("%s - %s\n", project->company, project->location);

	printf("%s\n", project->dates);

	const char ** description;
	for(description = project->description; *description; description++){
		printf("- %s\n", *description);
	}
	puts("");
}


int main(int argc, char ** argv) {

	school ** s;
	job ** j;
	project ** p;

	printf("%s\n%s\n%s\n\n", name, email, phone);

	puts("Education\n");
	for (s = schools; *s; s++) {
		print_resume(*s);
	}

	puts("Experience\n");
	for (j = jobs; *j; j++) {
		print_resume(*j);
	}

	puts("Personal Projects\n");
	for (p = projects; *p; p++) {
		print_project(*p);
	}

	return 0;
}
