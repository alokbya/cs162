#ifndef PICTURE_POST
#define PICTURE_POST

#include "post.h"

class PicturePost : public Post
{
public:
	PicturePost(const string& author, const string& fileName, const string& caption);
	string getPictureFile() const;
	string getPictureCaption() const;
	void print() const;
private:
	string	fileName;
	string	caption;
};

#endif