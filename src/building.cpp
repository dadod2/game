#include "building.h"

building::building(building_props *hp){
    if(hp){
        IN=hp->give_IN();
        next=NULL;
    }
    else{
        IN=0;
        next=NULL;
    }
}

building::building()
{
    IN=0;
    next=NULL;
}

