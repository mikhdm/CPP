/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:03:59 by rmander           #+#    #+#             */
/*   Updated: 2021/12/15 20:13:22 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

# define ARGC_COUNT 4

int main(int argc, char **argv) {
  if (argc != ARGC_COUNT)
  {
    std::cerr<<"Incorrect number of arguments"<<std::endl;
    return (EXIT_FAILURE);
  }

  std::string infile = argv[1];
  std::string from = argv[2];
  std::string to = argv[3];
  if (infile.empty())
  {
    std::cerr<<"Filename cannot be empty"<<std::endl;
    return (EXIT_FAILURE);
  }
  if (from.empty() || to.empty())
  {
    std::cerr<<"Patterns cannot be empty"<<std::endl;
    return (EXIT_FAILURE);
  }

  std::ifstream ifs;
  std::ofstream ofs;

  ifs.open(infile, std::ifstream::in);
  if (ifs.fail())
  {
    std::cerr<<"File does not exist"<<std::endl;
    return (EXIT_FAILURE);
  }

  std::stringstream *ss = new std::stringstream;
  std::string* buff = new std::string;
  *ss << ifs.rdbuf();
  *buff = ss->str();
  delete ss;

  size_t pos = buff->find(from);
  ofs.open(infile + ".replace", std::ofstream::out);
  if (pos == std::string::npos)
  {
    ofs << *buff;
    delete buff;
    ifs.close();
    ofs.close();
    return (EXIT_SUCCESS);
  }
  delete buff;
  ofs.close();
  ifs.close();
  return (EXIT_SUCCESS);
}
