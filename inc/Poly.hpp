#ifndef POLY_HEADER
#define POLY_HEADER

#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <format>
#include <Logger.hpp>
#include <Expr.hpp>


class Poly : public Logger {

public:
  // n --> polynomial degree.
  Poly();
  Poly(int n);
  Poly( const Poly &other);
  Poly(int n, std::string c);
  Poly inv();
  int degree() const;

  // operators override
  Poly operator+( const Poly &poly_other) const ;
  Poly operator*( const Poly &poly_other) const ;
  Poly operator%( const Poly &poly_other) const;

  Poly operator+( int n) const ;
  Poly operator*( int n) const ;
  Poly operator%( int n) const;

  void assign(int degree, Expr exp);
  void set_degree(int n);
  std::string to_string() const;
  const std::vector<Expr> & get_coeff() const;
private:
  std::vector<Expr> poly_coeff;
};

#endif
