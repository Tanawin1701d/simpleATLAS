#include "Atlas_structure.hh"
#include "base/logging.hh"
#include "base/trace.hh"
#include "debug/ATLAS.hh"


namespace gem5{

namespace memory{





ATLAS_STRUCTURE::~ATLAS_STRUCTURE(){

}

void
ATLAS_STRUCTURE::updateId(ATLAS_ID id){
    if (FORTUNE_TRAINEE.find(id) == FORTUNE_TRAINEE.end()){ // program id isn't initiated
        FORTUNE_TRAINEE.insert({id,1});
            DPRINTF(ATLAS,"ATLAS trainee %d updated to : %f\n", id, 1);
    }else{
        FORTUNE_TRAINEE[id] += 1;
            DPRINTF(ATLAS,"ATLAS trainee %d updated to : %f\n", id, FORTUNE_TRAINEE[id]);
    }
}

void
ATLAS_STRUCTURE::processEvent(){
    
    // dive throught FORTUNE_TRIANEE to update ATAINED SERVICE at FORTUNE_COOKIES 
    for (auto iter = FORTUNE_TRAINEE.begin(); iter != FORTUNE_TRAINEE.end(); iter++){
        ATLAS_ID        id    = iter->first;
        ATLAS_INDICATOR value = iter->second;
                        value = (1-alpha)*value;

        if ( FORTUNE_COOKIES.find(id) == FORTUNE_COOKIES.end()){
            // incase there are no prgram id on FORTUNE_COOKIES
            FORTUNE_COOKIES.insert({id, value});
            DPRINTF(ATLAS," thread: %d  updated to:  %f \n", id, value);
        }else{
            FORTUNE_COOKIES[id] = alpha*FORTUNE_COOKIES[id] + value;
            DPRINTF(ATLAS," thread: %d  updated to:  %f \n", id, alpha*FORTUNE_COOKIES[id] + value);

        }
    }

    FORTUNE_TRAINEE.clear();
    schedule(event, curTick() + nextQuanta);


}

void
ATLAS_STRUCTURE::startup(){
    DPRINTF(ATLAS,"ATLAS structure started");
    schedule(event, nextQuanta);

}

ATLAS_INDICATOR
ATLAS_STRUCTURE::getAS(ATLAS_ID id){
    if (FORTUNE_COOKIES.find(id) == FORTUNE_COOKIES.end()){ // program id isn't initiated
        return 0;
    }

    return FORTUNE_COOKIES[id];

}
                            
ATLAS_STRUCTURE::ATLAS_STRUCTURE(const ATLAS_STRUCTUREParams& params) : 
                    SimObject(params),
                    event([this]{processEvent();}, name() + ".name")
                    {

}


}
}