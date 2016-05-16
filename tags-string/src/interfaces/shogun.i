%module shogun
%include "std_string.i"
%{
#include <src/shogun/SGObject.hpp>
%}

%include <src/shogun/Tag.hpp>
%include <src/shogun/SGObject.hpp>

namespace shogun {
    %template(TagInt) Tag<int>;
    %template(TagString) Tag<std::string>;
    %template(TagFloat) Tag<float>;
}
