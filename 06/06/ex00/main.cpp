/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 00:12:36 by rmander           #+#    #+#             */
/*   Updated: 2022/01/13 22:33:27 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Value.hpp"

#include <limits>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <cctype>
#include <cfloat>

#include <math.h>


// specify all needed type bounds
namespace lim {
  int const imax = std::numeric_limits<int>::max();
  int const imin = std::numeric_limits<int>::min();
  char const cmin = static_cast<char>(std::numeric_limits<unsigned char>::min());
  char const cmax = std::numeric_limits<signed char>::max();
  float const fmin = -std::numeric_limits<float>::max();
  float const fmax = std::numeric_limits<float>::max(); 
  size_t const fprecmax = FLT_DIG;
  size_t const dprecmax = DBL_DIG;
}


static bool printable(char const c) {
  if ((c >= 0 && c <= 31) || c == 127)
    return false;
  return true;
}


static size_t min(size_t l, size_t r) {
  return (l < r) ? l : r;
}


static bool equal(double l, double r) {
  return std::abs(l - r) <= std::numeric_limits<double>::epsilon(); 
}


// Polymorphic function to check integer bounds
static bool bounded(double dv, int min, int max) {
  double const imin = static_cast<double>(min);
  double const imax = static_cast<double>(max);
  return ((dv > imin && !equal(dv, imin)) || equal(dv, imin))
          && ((dv < imax && !equal(dv, imax)) || equal(dv, imax)); 
} 


// Polymorphic function to check char bounds (0 - 127)
static bool bounded(double dv, char min, char max) {
  double const cmin = static_cast<double>(min);
  double const cmax = static_cast<double>(max);
  return ((dv > cmin && !equal(dv, cmin)) || equal(dv, cmin))
          && ((dv < cmax && !equal(dv, cmax)) || equal(dv, cmax)); 
} 


// Polymorphic function to check float bounds
static bool bounded(double dv, float min, float max) {
  double const fmin = static_cast<double>(min);
  double const fmax = static_cast<double>(max);
  return ((dv > fmin && !equal(dv, fmin)) || equal(dv, fmin))
          && ((dv < fmax && !equal(dv, fmax)) || equal(dv, fmax)); 
} 


// Performs check on a string after '.' sign for float / double values
static bool floated(std::string const& residue) {
  if (!residue.empty()) {
    size_t const rsize = residue.length();
    for (size_t i = 0; i < rsize - 1; ++ i) {
      if (!std::isdigit(residue[i]))
        return false;
    }
    if (!std::isdigit(residue[rsize - 1]) && (residue[rsize - 1] != 'f'))
      return false;
  }
  return true;
}


static void init(Value* v) {
  v->i = 0;
  v->c = 0;
  v->d = 0;
  v->f = 0;
  v->state.c = false;
  v->state.f = false;
  v->state.d = false;
  v->state.i = false;
  v->state.fprec = 1;
  v->state.dprec = 1;
  v->btype = UNSET;
}


// Polymorphic function to print char
void print(Value* v, char c) {
  std::cout << "char: ";
  if (v->state.c) {
    if (!printable(c))
      std::cout << "Non displayable" << std::endl;
    else
      std::cout << "'" << c << "'" << std::endl;
  }
  else
    std::cout << "impossible" << std::endl;
} 


// Polymorphic function to print integer
void print(Value* v, int i) {
  std::cout << "int: ";
  if (v->state.i)
    std::cout << i << std::endl;
  else
    std::cout << "impossible" << std::endl;
}


// Polymorphic function to print float
void print(Value* v, float f) {
  std::cout << "float: ";
  if (v->state.f) {
    std::cout << std::fixed
      << std::setprecision(static_cast<int>(v->state.fprec))
      << f << "f" << std::endl;
  }
  else
    std::cout << "impossible" << std::endl;
}


// Polymorphic function to print all
void print(Value* v) {
  std::string const impossible = "impossible";
  switch (v->btype) {
    case CHAR:
      print(v, v->c);
      print(v, v->i);
      std::cout << "float: " << std::fixed
        << std::setprecision(1) << v->f << "f" << std::endl;
      std::cout << "double: " << std::fixed
        << std::setprecision(1) << v->d << std::endl;

      break ;

    case INTEGER:
      print(v, v->c);
      print(v, v->i);
      std::cout << "float: " << std::fixed
        << std::setprecision(1) << v->f << "f" << std::endl;
      std::cout << "double: " << std::fixed
        << std::setprecision(1) << v->d << std::endl;

      break ;

    case FLOAT:
    case DOUBLE:
      print(v, v->c);
      print(v, v->i);
      print(v, v->f);
      std::cout << "double: " << std::fixed
        << std::setprecision(static_cast<int>(v->state.dprec))
        << v->d << std::endl;

      break ;

    default:
      std::cout << "char: " << impossible << std::endl;
      std::cout << "int: " << impossible << std::endl;
      std::cout << "float: " << impossible << std::endl;
      std::cout << "double: " << impossible << std::endl;

      break ;
  }
}


Value detect(std::string const& s, long v) {
  Value value;
  char *end = nullptr;

  init(&value);
  if (errno == EDEFAULT) {
    value.d = static_cast<double>(v);
    value.state.d = true;
    value.f = static_cast<float>(v);
    value.state.f = true;
    value.btype = FLOAT;

    if (v >= lim::imin && v <= lim::imax) {
      value.btype = INTEGER;
      value.i = static_cast<int>(v);
      value.state.i = true;
    }
    if (v >= lim::cmin && v <= lim::cmax) {
      value.c = static_cast<char>(v);
      value.state.c = true;
    }
    return value;
  }
  if (errno == ERANGE) {
    errno = EDEFAULT;
    double dv = std::strtod(s.c_str(), &end);
    if (errno == ERANGE)
      return value;
    value.btype = DOUBLE;
    value.d = dv;
    value.state.d = true;
    if (bounded(dv, lim::fmin, lim::fmax)) {
      value.btype = FLOAT;
      value.f = static_cast<float>(dv);
      value.state.f = true;
    }
    return value;
  }
  return value;
}


Value detect(std::string const& literal, bool einval) {
  Value value;
  char *end = nullptr;
  init(&value);
  size_t const size = literal.length();

  if (!einval)
    return value;

  bool charable = (size == 3) && (literal[0] == '\'') && (literal[2] == '\'');
  // value is a char literal
  if (charable) {
    value.btype = CHAR;
    value.c = literal[1];
    value.i = static_cast<int>(value.c);
    value.f = static_cast<float>(value.c);
    value.d = static_cast<double>(value.c);
    value.state.c = true;
    value.state.i = true;
    value.state.f = true;
    value.state.d = true;
  }
  else {
    errno = EDEFAULT;
    std::string ss = literal;
    double dv = std::strtod(ss.c_str(), &end);
    bool convertible = (ss.length() == 3)
                        || (ss.length() == 4 && (ss[0] == '+' || ss[0] == '-'))
                        || ((ss.length() == 4) && (*end == 'f'))
                        || (ss.length() == 5 && (ss[0] == '+' || ss[0] == '-')
                            && (*end == 'f'));
    if (!convertible)
      return (value);
    if (isnan(dv)) {
      value.d = dv;
      value.f = static_cast<float>(dv);
      value.btype = (*end == 'f') ? FLOAT : DOUBLE;
      value.state.d = true;
      value.state.f = true;
    }
    else if (isinf(dv)) {
      value.d = dv;
      value.f = static_cast<float>(dv);
      value.btype = (*end == 'f') ? FLOAT : DOUBLE;
      value.state.d = true;
      value.state.f = true;
    }
  }
  return value;
}

size_t prec(std::string const& s, bool floated) {
  size_t dot = s.find(".");
  if (dot == std::string::npos) {
    return 0;
  }
  size_t last = floated ? s.find("f") : s.length();
  return s.substr(dot + 1, last - (dot + 1)).length();
}


Value detect(std::string const& literal) {
  Value value;
  char *end = nullptr;
  init(&value);

  std::string s = literal;

  long v = std::strtol(s.c_str(), &end, 10);

  if (errno == EDEFAULT || errno == ERANGE) {
    // value partially converted & we found float or double (ex. 123.0...)
    if (*end && *end == '.') {
      errno = EDEFAULT;

      std::string ss = literal;
      std::string const residue = end + 1;
      //check correct residue of float / double value
      if (!floated(residue))
        return value;

      double dv = std::strtod(ss.c_str(), &end);

      // actual value is float due to 'f' symbol at the end and errno was not set
      if (errno == EDEFAULT && *end == 'f') {
        // out of float bounds, return value as unset
        if (!bounded(dv, lim::fmin, lim::fmax))
          return value;

        // setup precision 
        size_t precision = prec(literal, true);
        value.state.fprec = min(
            (precision > 0) ? precision : value.state.fprec,
            lim::fprecmax);
        value.state.dprec = min(
            (precision > 0) ? precision : value.state.dprec,
            lim::dprecmax);

        // we are inside float bounds and actual value is float (due to 'f' symbol)
        value.btype = FLOAT;
        value.f = static_cast<float>(dv);
        value.state.f = true;

        // we are inside float then inside double bounds too
        value.d = dv;
        value.state.d = true;
        
        // check float is in integer bounds to acquire int
        if (bounded(dv, lim::imin, lim::imax)) {
          value.i = static_cast<int>(dv);
          value.state.i = true;
        }
        // check char bounds as described in a subject
        if (bounded(dv, lim::cmin, lim::cmax)) {
          value.c = static_cast<char>(dv);
          value.state.c = true;
        }
        return value;
      }
      // actual value is double
      if (errno == EDEFAULT && *end == '\0') {
        
        // setup precision 
        size_t precision = prec(literal, false);
        value.state.fprec = min(
            (precision > 0) ? precision : value.state.fprec,
            lim::fprecmax);
        value.state.dprec = min(
            (precision > 0) ? precision : value.state.dprec,
            lim::dprecmax);

        value.btype = DOUBLE;
        value.d = dv;
        value.state.d = true;
        // check double value inside float bounds
        if (bounded(dv, lim::fmin, lim::fmax)) {
          value.f = static_cast<float>(dv);
          value.state.f = true;
        }
        // check double value inside integer bounds
        if (bounded(dv, lim::imin, lim::imax)) {
          value.i = static_cast<int>(dv);
          value.state.i = true;
        }
        // check char bounds as described in a subject
        if (bounded(dv, lim::cmin, lim::cmax)) {
          value.c = static_cast<char>(dv);
          value.state.c = true;
        }
        return value;
      }
      // literal is out of any appropriate bounds so we return unset value
      if (errno == ERANGE)
        return (value);
    }
    // value correctly converted to long or out of bounds with errno = ERANGE 
    if (*end == '\0')
      return detect(literal, v);
  }
  // value is not converted properly and we got text (ex. a, aaa, b123, --123, +++1)
  if (errno == EINVAL)
    return detect(literal, errno == EINVAL); 
  return value;
}


int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Error: invalid number of arguments." << std::endl;
    return (EXIT_FAILURE);
  }
  std::string const literal = argv[1];
  Value value = detect(literal);
  print(&value);
  return (EXIT_SUCCESS);
}
