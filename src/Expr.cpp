#ifndef EXPR_HEADER
#define EXPR_HEADER

#include <algorithm>
#include <format>
#include <iostream>
#include <vector>
#include <ranges>
#include <Expr.hpp>


Expr::Expr() { std::cout << "inside Expr default constructor" << std::endl; };
Expr::Expr(std::string &s) {
  std::cout << "inside Expr string constructor" << std::endl;
};

Expr::Expr(const Expr &other) {
  std::cout << "inside Expr copy constructor" << std::endl;

  exp = other.get_expr();
};

// operators override
Expr Expr::operator+(const Expr &poly_other) const {
  std::string x = std::format("({} + {})", exp, poly_other.get_expr());
  return Expr(x);
};
Expr Expr::operator*(const Expr &poly_other) const {
  auto x = std::format("({} * {})", exp, poly_other.get_expr());
  return Expr(x);
};
Expr Expr::operator%(const Expr &poly_other) const {
  auto x = std::format("({} % {})", exp, poly_other.get_expr());
  return Expr(x);
};

Expr Expr::operator+(int n) const {
  auto x = std::format("({} % {})", exp, n);
  return Expr(x);
};
Expr Expr::operator*(int n) const {
  auto x = std::format("({} * {})", exp, n);
  return Expr(x);
};
Expr Expr::operator%(int n) const {
  auto x = std::format("({} % {})", exp, n);
  return Expr(x);
};
std::ostream &Expr::operator<<(std::ostream &os) const {
  os << exp;
  return os;
}
void Expr::assign_value(std::string &s, int value){};
void Expr::assign_symbol(std::string s) {
  log(std::format("assigning symbol {} instead of {}", s, exp));
  exp = s;
};
void Expr::evaluate() { panic("not implemented"); };
std::string Expr::get_expr() const { return exp; }
std::string Expr::to_string() { return exp; };


#endif
