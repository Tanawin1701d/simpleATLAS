#include<map>
#include "sim/sim_object.hh"
#include "params/ATLAS_STRUCTURE.hh"
#include "sim/eventq.hh"


#ifndef __MEM_ATLAS_STRUCTURE_HH__
#define __MEM_ATLAS_STRUCTURE_HH__
namespace gem5{

namespace memory{
typedef float    ATLAS_INDICATOR;
typedef ThreadID ATLAS_ID;

class ATLAS_STRUCTURE : public SimObject{
  private:
    std::map<ATLAS_ID,ATLAS_INDICATOR> FORTUNE_COOKIES;
    std::map<ATLAS_ID,ATLAS_INDICATOR> FORTUNE_TRAINEE;
    EventFunctionWrapper event;
    const ATLAS_INDICATOR alpha  = 0.875;
    int gdgdfgdf = 0;

    const static int nextQuanta = 100000;
  public:
    ATLAS_STRUCTURE(const ATLAS_STRUCTUREParams &);
    ~ATLAS_STRUCTURE();
    void            updateId(ATLAS_ID);
    void            processEvent();
    void            startup();
    ATLAS_INDICATOR getAS(ATLAS_ID);

};

}
}

#endif