
#pragma once

#include "DotFrag.h"

namespace ofx { namespace dotfrag {

class Mirror : public Base {

private:
    static const string code;

public:
	Mirror();
    
    ofParameter<bool> horizontal;
	ofParameter<bool> vertical;
};

}} // namespaces end
