#include "messagePost.h"

MessagePost::MessagePost(const string& author, const string& message) : Post(author), text(message){}

string MessagePost::getText() const
{
	return text;
}

void  MessagePost::print() const
{
	Post::print();
	cout << "Message: " << text << endl;
}