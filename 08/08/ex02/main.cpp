/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 05:07:29 by rmander           #+#    #+#             */
/*   Updated: 2022/01/16 07:12:23 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

#include <iostream>
#include <vector>
#include <list>


int main(void) {

  std::cout << "Subject: " << std::endl;

  {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int> s(mstack);
  }

  std::cout << std::endl << "With std::stack<int>: (backward) " << std::endl;
  {
    std::stack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    while (!mstack.empty()) {
      std::cout << mstack.top() << std::endl;
      mstack.pop();
    }
    std::stack<int> s(mstack);
  }

  std::cout << std::endl << "with std::vector<int>: " << std::endl;

  {
    std::vector<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);
    std::cout << mstack.back() << std::endl;
    mstack.pop_back();
    std::cout << mstack.size() << std::endl;
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    //[...]
    mstack.push_back(0);
    std::vector<int>::iterator it = mstack.begin();
    std::vector<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::vector<int> s(mstack);
  }


  {
    MutantStack<std::string> mstack;
    mstack.push("Brave New World by Aldous Huxley (1932)");
    mstack.push("Crime and Punishment by Fyodor Dostoevsky (1866)");
    mstack.pop();

    std::cout << "mstack 1 top: " << mstack.top() << std::endl;

    MutantStack<std::string> mstack2(mstack);

    std::cout << "mstack 2 top: " << mstack2.top() << std::endl;

    MutantStack<std::string> mstack3;
    mstack3 = mstack2;

    std::cout << "mstack 3 top: " << mstack3.top() << std::endl;

    mstack3.push("Frankenstein by Mary Shelley (1823)");

    std::cout << "mstack 3 top (after push): " << mstack3.top() << std::endl;

    MutantStack<std::string>::const_iterator ib = mstack3.begin();
    MutantStack<std::string>::const_iterator ie = mstack3.end();

    std::cout << "Bookshelf (via const iterator): " << std::endl;
    for (MutantStack<std::string>::const_iterator it = ib; it != ie; ++it) {
      std::cout << "  " << *it << std::endl;
    }

  }
  return 0;
}
