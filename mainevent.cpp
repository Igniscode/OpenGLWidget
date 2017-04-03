#include "mainevent.h"

MainEvent::MainEvent()
{

}

MainEvent::ApplicationActivated(){
    int _hwidth = GetSystemMetrics(SM_CXSCREEN)/2;
    int _hheight = GetSystemMetrics(SM_CYSCREEN)/2;
    w.resize(_hwidth,_hheight);
    w.move(_hwidth/2,_hheight/2);
}
