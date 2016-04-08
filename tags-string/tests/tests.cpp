#include <src/shogun/SGObject.hpp>
#include <iostream>

using namespace shogun;

int main() {

    // SGObject *obj = new SGObject();
    SGObject obj;

    Tag<std::string> name_tag("name");
    std::string s1 = "square";
    obj.set(name_tag, s1);

    Tag<int> length_tag("side");
    obj.set(length_tag, 10);

    std::cout << length_tag.getName() << " of a " << obj.get(name_tag) << " object is : " << obj.get(length_tag) << std::endl;

    // delete(obj);

    return 0;
}
