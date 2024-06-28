#ifndef _WEBPAGE_H_
#define _WEBPAGE_H_

#include "Theme.hpp"

class WebPage {
protected:
    string title_;
    Theme* theme_;
public:
    WebPage(Theme* theme, string title): theme_(theme), title_(title) {};
    virtual string getContent() = 0;
};

#endif //_WEBPAGE_H_