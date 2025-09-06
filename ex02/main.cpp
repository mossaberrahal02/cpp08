#include "MutantStack.hpp"
#include <string>
#include <vector>

int main()
{
    MutantStack<int> mstack;

    mstack.push(10);
    mstack.push(20);
    mstack.push(30);

    std::cout << "content" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "reverse" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
        std::cout << *rit << " ";
    std::cout << std::endl;

    std::cout << "top " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "top after pop: " << mstack.top() << std::endl;

    std::cout << "\ncopy constructor and assignment operator" << std::endl;
    MutantStack<int> copyStack(mstack);
    MutantStack<int> assignStack;
    assignStack = copyStack;

    std::cout << "copied stack content:" << std::endl;
    for (MutantStack<int>::iterator it = copyStack.begin(); it != copyStack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "assigned stack content:" << std::endl;
    for (MutantStack<int>::iterator it = assignStack.begin(); it != assignStack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "\nconst iteration " << std::endl;
    const MutantStack<int> constStack = assignStack;

    std::cout << "const stack content forward" << std::endl;
    for (MutantStack<int>::const_iterator cit = constStack.begin(); cit != constStack.end(); ++cit)
        std::cout << *cit << " ";
    std::cout << std::endl;

    std::cout << "const stack content reverse" << std::endl;
    for (MutantStack<int>::const_reverse_iterator crit = constStack.rbegin(); crit != constStack.rend(); ++crit)
        std::cout << *crit << " ";
    std::cout << std::endl;

    std::cout << "\ndifferent underlying container std::vector" << std::endl;
    MutantStack<std::string, std::vector<std::string> > stringStack;
    stringStack.push("13");
    stringStack.push("37");
    stringStack.push("wah");

    std::cout << "String stack content:" << std::endl;
    for (MutantStack<std::string, std::vector<std::string> >::iterator it = stringStack.begin(); it != stringStack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}
