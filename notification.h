#ifndef NOTIFICATION
#define NOTIFICATIOn
#include <iostream>
#include <string>
#include <limits.h>
#include <functional>
#include <sys/inotify.h>
#include <sys/epoll.h>


#define BUF_LEN (10 * (sizeof (struct inotify_event) + NAME_MAX +1))


class notify
{

  private:
	  std::string FileName;
	  int inotifyFD;
	  int epollFD;
	  struct inotify_event *Ievent;
	  struct epoll_event    Eevent;
	  std::function<void()> callback = nullptr;
  public:
	 notify(std::string File);
	~notify();
	void RegisterCallback(std::function<void()> func);
	void epolling();


};





#endif


