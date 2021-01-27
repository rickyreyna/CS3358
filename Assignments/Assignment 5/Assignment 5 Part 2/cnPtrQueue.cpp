#include "cnPtrQueue.h"
#include <cassert>
using namespace std;

namespace CS3358_FA2018_A5P2
{

  cnPtrQueue::cnPtrQueue()
      : numItems(0) {}

  cnPtrQueue::size_type cnPtrQueue::size() const
  {
    return numItems;
  }

  void cnPtrQueue::push(CNode* cnPtr)
  {
    inStack.push(cnPtr);
    ++numItems;
  }

  bool cnPtrQueue::empty() const
  {
   return outStack.empty() && inStack.empty();
  }

  void cnPtrQueue::pop()
  {
    assert( !inStack.empty() || !outStack.empty() );

    if(outStack.empty())
    {
      while(!inStack.empty())
     {
        outStack.push(inStack.top());
        inStack.pop();
     }

     }

    outStack.pop();
    --numItems;
}

  CNode* cnPtrQueue::front()
  {
    assert( !inStack.empty() || !outStack.empty() );

    if(outStack.empty())
    {
      while(!inStack.empty())
      {
        outStack.push(inStack.top());
        inStack.pop();
      }
    }

    return outStack.top();
  }

}
