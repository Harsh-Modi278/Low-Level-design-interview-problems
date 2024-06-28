#include "../models/WebPage.hpp"

class ProjectsPage: public WebPage {
public:
    ProjectsPage(Theme* theme, string title): WebPage(theme, title) {};
    string getContent() {
        string s = theme_->getColor();
        s += title_;
        return s;
    }
};