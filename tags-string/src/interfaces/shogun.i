%module shogun
%include "std_string.i"
%{
#include <src/shogun/SGObject.hpp>
%}

%include <src/shogun/Tag.hpp>
%include <src/shogun/SGObject.hpp>

namespace shogun {
    %template(TagInt) Tag<int>;
    %template(TagFloat) Tag<float>;
    %template(TagString) Tag<std::string>;

    %template(setInt) SGObject::set<int>;
    %template(setFloat) SGObject::set<float>;
    %template(setString) SGObject::set<std::string>;

    %template(getInt) SGObject::get<int>;
    %template(getFloat) SGObject::get<float>;
    %template(getString) SGObject::get<std::string>;
}
