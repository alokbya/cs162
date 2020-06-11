#include "newsFeed.h"

NewsFeed::NewsFeed(){}

NewsFeed::~NewsFeed()
{
	for (auto it = messagePosts.begin(); it != messagePosts.end(); it++)
	{
		delete *it;
	}

	for (auto it = picturePosts.begin(); it != picturePosts.end(); it++)
	{
		delete *it;
	}
}

void NewsFeed::addMessagePost(MessagePost* post)
{
	messagePosts.push_back(post);
}

void NewsFeed::addPicturePost(PicturePost* post)
{
	picturePosts.push_back(post);
}

void NewsFeed::print() const
{
	cout << endl << "Message Posts: " << endl;
	for (auto it = messagePosts.begin(); it != messagePosts.end(); it++)
	{
		(*it)->print();
	}

	cout << endl << "Picture Posts: " << endl;
	for (auto it = picturePosts.begin(); it != picturePosts.end(); it++)
	{
		(*it)->print();
	}
}