#include <iostream>
using namespace std;
#include "newsFeed.h"

#include <stdlib.h>

void mysleep();
int main()
{
	NewsFeed		newsRoom;
	MessagePost*	mesg;
	PicturePost*	photo;

	mesg = new MessagePost("user1", "got a great idea");
	//Sleep(60000);
	photo = new PicturePost("user2", "got a great picture", "baby laughing");
	newsRoom.addMessagePost(mesg);
	newsRoom.addPicturePost(photo);
	mesg = new MessagePost("user3", "got another great idea");
	//Sleep(60000);
	photo = new PicturePost("user4", "got another great picture", "baby laughing again");
	newsRoom.addMessagePost(mesg);
	newsRoom.addPicturePost(photo);
	//Sleep(65000);
	newsRoom.print();

	system("pause");
	return 0;
}

void mysleep()
{

}
