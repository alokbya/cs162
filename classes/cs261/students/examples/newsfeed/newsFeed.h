#ifndef NEWSFEED_H
#define NEWSFEED_H

#include "messagePost.h"
#include "picturePost.h"
#include <list>

class NewsFeed
{
public:
	NewsFeed();
	~NewsFeed();
	void addMessagePost(MessagePost* post);
	void addPicturePost(PicturePost* post);
	void print() const;

private:
	list<MessagePost*>  messagePosts;
	list<PicturePost*>	picturePosts;
};

#endif