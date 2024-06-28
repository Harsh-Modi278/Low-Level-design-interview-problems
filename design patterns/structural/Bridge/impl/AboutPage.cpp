#include "../models/WebPage.hpp"

class AboutPage: public WebPage {
public:
    AboutPage(Theme* theme, string title): WebPage(theme, title) {};
    string getContent() {
        string s = theme_->getColor();
        s += title_;
        return s;
    }
};