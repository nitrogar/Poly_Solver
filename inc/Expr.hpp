#include <cstdlib>
#include <format>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <Logger.hpp>
class Expr : public Logger {
public:
  Expr();
  Expr(std::string &s);
  Expr(const Expr &other);
  // operators override
  Expr operator+(const Expr &poly_other) const;
  Expr operator*(const Expr &poly_other) const;
  Expr operator%(const Expr &poly_other) const;

  Expr operator+(int n) const;
  Expr operator*(int n) const;
  Expr operator%(int n) const;
  std::ostream &operator<<(std::ostream &os) const;
  void assign_value(std::string &s, int value);
  void assign_symbol(std::string s);
  void evaluate();
  std::string to_string();
  std::string get_expr() const;

private:
  // <name, value, valid>
  std::map<std::string, std::pair<int, bool>> expression_values;
  std::string exp;
};
