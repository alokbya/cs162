#include "picturePost.h"

PicturePost::PicturePost(const string& author, const string& fileName, const string& caption) : Post(author), fileName(fileName), caption(caption){}

string PicturePost::getPictureFile() const
{
	return fileName;
}

string PicturePost::getPictureCaption() const
{
	return caption;
}

void PicturePost::print() const
{
	Post::print();
	cout << "Picture File: " << fileName << endl
		<< "Picture Caption: " << caption << endl;
}