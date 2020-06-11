#ifndef MESSAGE_POST
#define MESSAGE_POST
#include "post.h"

class MessagePost : public Post
{
public:
	MessagePost(const string& author, const string& text);
	string getText() const;
	void print() const;
private:
	string	text;
};

#endif