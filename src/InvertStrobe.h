
#pragma once

#include "DotFrag.h"

namespace ofx { namespace dotfrag {

class InvertStrobe : public Base {

private:
    static const std::string code;

public:
	InvertStrobe();
    
    ofParameter<float> pulse;
};

}} // namespaces end
