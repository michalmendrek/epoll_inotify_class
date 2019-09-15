#include <notification.h>
#include <unistd.h>

notify::notify(std::string File)
{
  int err;
  FileName      = File;
  inotifyFD     = inotify_init();
  epollFD       = epoll_create(sizeof(inotifyFD));
  err           = inotify_add_watch(inotifyFD,FileName.c_str(),IN_CLOSE_WRITE);
  Eevent.events = EPOLLIN|EPOLLET;
  err           = epoll_ctl(epollFD, EPOLL_CTL_ADD, inotifyFD, &Eevent);
}


notify::~notify()
{
  close(epollFD);
  close(inotifyFD);
}

void notify::RegisterCallback(std::function<void()> func)
{
  callback=func;

}

void notify::epolling()
{
 int err;
 char buff[BUF_LEN];
 ssize_t numRead;
 char *p;
 err = epoll_wait(epollFD, &Eevent, 100, 1000);
 if(err >0)
 {
 numRead = read(inotifyFD, buff, BUF_LEN);
 if(callback!=nullptr) {callback();}
 for(p = buff; p < buff + numRead;)
   {
    Ievent = (struct inotify_event *) p;
    p+= sizeof(struct inotify_event) + Ievent->len;
    }
 }


}
