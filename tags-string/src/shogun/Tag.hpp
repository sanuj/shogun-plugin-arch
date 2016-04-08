#ifndef _TAG_H_
#define _TAG_H_

#include <string>

namespace shogun {

    template <class T>
    class Tag
    {
        public:
            Tag(std::string name) : name_(name) { };
            std::string getName() {return name_;};
        private:
            std::string name_;
    };

}

#endif // _TAG_H_
