
#pragma once

#include "DotFrag.h"

namespace ofx { namespace dotfrag {

class Delay : public Base {

private:
    static const string code;
    
public:
    Delay();
    
    ofParameter<float> feedback;
    ofParameter<int>   blendmode;
    
};

}} // end namespaces