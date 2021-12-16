/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:03:59 by rmander           #+#    #+#             */
/*   Updated: 2021/12/16 18:10:08 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

# define ARGC_COUNT 4


static void error(std::string const& message, int code) {
  std::cerr<<message<<std::endl;
  std::exit(code); 
}


static void read(std::string const& filename, std::string& buff) {
  std::ifstream ifs;
  ifs.open(filename, std::ifstream::in);
  if (ifs.fail())
    error("Error reading file", EXIT_FAILURE);

  std::stringstream* ss = new std::stringstream;
  *ss << ifs.rdbuf();
  buff = ss->str();
  delete ss;
  ifs.close();
}


static void replace(std::string const& from, std::string const& to,
              std::string const& filename, std::string& buff) {
  std::ofstream ofs;
  ofs.open(filename + ".replace", std::ofstream::out);
  if (ofs.fail())
    error("Error writing file", EXIT_FAILURE);

  size_t start = 0;
  size_t pos = 0;
  std::string tmp;
  while (true) {
    pos = buff.find(from, start);
    if (pos == std::string::npos)
      break ;
    ofs << buff.substr(start, pos - start);
    ofs << to;
    start = from.length() + pos;
  }
  ofs << buff.substr(start, std::string::npos);
  ofs.close();
}


int main(int argc, char **argv) {
  if (argc != ARGC_COUNT)
    error("Incorrect number of arguments", EXIT_FAILURE);

  std::string infile = argv[1];
  std::string from = argv[2];
  std::string to = argv[3];

  if (infile.empty())
    error("Filename cannot be empty", EXIT_FAILURE);
  if (from.empty() || to.empty())
    error("Patterns cannot be empty", EXIT_FAILURE);

  std::string* buff = new std::string;
  read(infile, *buff);
  replace(from, to, infile, *buff);
  delete buff;
  return (EXIT_SUCCESS);
}
