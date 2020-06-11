#ifndef POST_H
#define POST_H

#include <iostream>
using namespace std;
#include <string>
#include <list>
#include <ctime>

class Post
{
public:
	Post(const string& author);

	string getAuthor() const;
	int	getLikes() const;
	time_t getTimeStamp() const;
	void like();
	void unlike();
	void addComment(const string& comment);
	
	void print() const;

private:
	string			userName;
	time_t			timeStamp;
	int				likes;
	list<string>	comments;
	string			getTimeString() const;
};
#endif