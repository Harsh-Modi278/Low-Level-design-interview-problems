#include "impl/DarkTheme.cpp"
#include "impl/LightTheme.cpp"
#include "impl/AboutPage.cpp"
#include "impl/ProjectsPage.cpp"

// Consider you have a website with different pages and you are supposed to allow the user to change the theme. 
// What would you do? Create multiple copies of each of the pages for each of the themes 
// or would you just create separate theme and load them based on the user's preferences? 
// Bridge pattern allows you to do the second i.e.

// w.o bridge:
// There're 3 web pages: About, Projects, Careers inheriting from WebPage base class
// without using Bridge pattern, we would have to implement DarkAbout, LightAbout, DarkProjects, LightProjects,....

// with bridge:
// There're two theme classes: Dark and Light extending from Theme interface
// WebPage can have Theme interface ("composition").

// Bridge pattern is about preferring composition over inheritance. 
// Implementation details are pushed from a hierarchy to another object with a separate hierarchy.

int32_t main() {
    Theme* theme = new LightTheme();

    WebPage* aboutPage = new AboutPage(theme, "About");
    WebPage* projectsPage = new ProjectsPage(theme, "Projects");

    cout<<aboutPage->getContent()<<"\n";
    cout<<projectsPage->getContent()<<"\n";
    return 0;
}