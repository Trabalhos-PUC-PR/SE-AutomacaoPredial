#include "threadbehavior.h"

extern "C"{
#include "../../common/behavior.h"
}

ThreadBehavior::ThreadBehavior()
{

}

void ThreadBehavior::run(){
    behavior();
}
