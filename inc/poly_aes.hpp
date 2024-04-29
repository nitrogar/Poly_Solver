#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <format>
class Logger {
public:
  Logger(){};
  template<class... Args>
  void log(Args... msg) const { (std::cout << ... << msg) << std::endl; };

  template <class... Args>
  void panic(Args... msg) const {
    std::cout << "[PANIC!!]" ;
  (std::cout << ... << msg) << std::endl;
    exit(0);
  };
};

class Expr : public Logger {
public:
  Expr();
  Expr(std::string &s);
  Expr( const Expr &other);
  // operators override
  Expr operator+( const Expr &poly_other) const;
  Expr operator*( const Expr &poly_other) const;
  Expr operator%( const Expr &poly_other) const;

  Expr operator+( int n) const ;
  Expr operator*( int n) const ;
  Expr operator%( int n) const ;
  std::ostream &operator<<(std::ostream &os) const ;
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

class Poly : public Logger {

public:
  // n --> polynomial degree.
  Poly();
  Poly(int n);
  Poly( const Poly &other);
  Poly(int n, std::string &c);
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
  std::string to_string();
  const std::vector<Expr> & get_coeff() const;
private:
  std::vector<Expr> poly_coeff;
};
