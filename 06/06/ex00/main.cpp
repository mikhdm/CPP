/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 00:12:36 by rmander           #+#    #+#             */
/*   Updated: 2022/01/12 18:27:40 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <limits>
#include <iostream>
#include <cerrno>

#include <math.h>

void debugtol(long v, std::string const &s, char *end) { 
  std::cout << "strtol: " << std::endl;
  std::cout << "  return: " << v << std::endl;
  std::cout << "  str_end: " << ((*end == '\0') ? '0' : *end) << std::endl;
  std::cout << "  str: " << ((*s.c_str() == '\0') ? '0' : *s.c_str()) << std::endl;
}

void debugtod(double dv, std::string const &ss, char *end) {
  std::cout << "strtod: " << std::endl;
  std::cout << "  return: " << dv << std::endl;
  std::cout << "  str_end: " << ((*end == '\0') ? '0' : *end) << std::endl;
  std::cout << "  str: " << ((*ss.c_str() == '\0') ? '0' : *ss.c_str()) << std::endl;
}  

# define X_EDEFAULT 0

enum Type {
  UNSET = -1,
  CHAR = 0,
  INTEGER = 1,
  FLOAT = 2,
  DOUBLE = 3
};


typedef struct {
  char c;
  float f;
  double d;
  int i;
  Type btype;
} Value;


void initValue(Value* v) {
  v->i = 0;
  v->c = 0;
  v->d = 0;
  v->f = 0;
  v->btype = UNSET;
}

void print(Value* v) {
  std::string const impossible = "impossible";
  std::string const nondisplay = "Non displayable";

  if (v->btype == DOUBLE || v->btype == FLOAT) {
    if (isnan(v->d) || isinf(v->d)) {
      std::cout << "char: " << impossible << std::endl; 
      std::cout << "int: " << impossible << std::endl;
    }
    std::cout << "float: " << v->f << "f" << std::endl;
    std::cout << "double: " << v->d << std::endl;
    return ;
  }
  if (v->btype == UNSET) { 
    std::cout << "char: " << impossible << std::endl; 
    std::cout << "int: " << impossible << std::endl;
    std::cout << "float: " << impossible << std::endl;
    std::cout << "double: " << impossible << std::endl;
    return ;
  }
}

Value detect(std::string const& literal) {
  size_t const size = literal.length();
  char *end = nullptr;
  Value value;
  initValue(&value);

  std::string s = literal;
  long v = std::strtol(s.c_str(), &end, 10);

  if (errno == X_EDEFAULT) {

  }
  
  if (errno == EINVAL) {
    bool charable = (size == 3) && (literal[0] == '\'') && (literal[2] == '\'');
    if (charable) {
      value.btype = CHAR;
      value.c = literal[1];
    }
    else {
      errno = X_EDEFAULT;
      std::string ss = literal;
      double dv = std::strtod(ss.c_str(), &end); 
      
      bool convertible = (ss.length() == 3)
                        || (ss.length() == 4 && (ss[0] == '+' || ss[0] == '-'))
                        || ((ss.length() == 4) && (*end == 'f'))
                        || (ss.length() == 5 && (ss[0] == '+' || ss[0] == '-')
                            && (*end == 'f'));
      bool isnan_ = isnan(dv);
      bool isinf_ = isinf(dv); 
      if (!convertible)
        return (value);

      if (isnan_) {
        value.d = dv; 
        value.f = static_cast<float>(dv);
        value.btype = (*end == 'f') ? FLOAT : DOUBLE;
      }
      else if (isinf_) {
        value.d = dv;
        value.f = static_cast<float>(dv);
        value.btype = (*end == 'f') ? FLOAT : DOUBLE;
      }
    }
  }
  return value;
}

int main(int argc, char **argv) {
  if (argc != 2)
  {
    std::cerr << "Error: invalid number of arguments." << std::endl;
    return (EXIT_FAILURE);
  }
  std::string const literal = argv[1];

  // std::cout << "literal: " << literal << std::endl;

  /* <--- detect literal type */
  Value value = detect(literal);
  print(&value);
  /* ---> */

  /* if (value >= std::numeric_limits<int>::min() */
  /*     && value <= std::numeric_limits<int>::max()) { */
  /* } */

  /* std::cout << static_cast<int>(value) << std::endl; */
  return (EXIT_SUCCESS);
}
