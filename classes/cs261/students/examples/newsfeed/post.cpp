#include "post.h"

Post::Post(const string& author) : userName(author), timeStamp(time(nullptr)), likes(0){}

string Post::getAuthor() const
{
	return userName;
}

int Post::getLikes() const
{
	return likes;
}

time_t Post::getTimeStamp() const
{
	return timeStamp;
}

void Post::like()
{
	likes++;
}

void Post::unlike()
{
	if (likes > 0)
		likes--;
}

void Post::addComment(const string& comment)
{
	comments.push_back(comment);
}

void Post::print() const
{
	cout << userName << " posted " << getTimeString() << endl
		<< "--" << likes << " people like this" << "--" << comments.size() << " comment(s)" << endl;
}

string Post::getTimeString() const
{
	time_t	currTime = time(nullptr);
	long	seconds = difftime(currTime, timeStamp);

	long	minutes, hours;
	string	timeString;

	minutes = seconds / 60;
	hours = minutes / 60;
	
	if (hours > 0)
	{
		timeString = to_string(hours) + " hours ago";
	}
	else
	{
		timeString = to_string(minutes) + " minutes ago";
	}
	return timeString;
}