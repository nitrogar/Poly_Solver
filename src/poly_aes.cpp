#include <algorithm>
#include <format>
#include <iostream>
#include <poly_aes.hpp>
#include <vector>
#include <ranges>
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

Poly::Poly() { log("inside Poly default constructor"); };
Poly::Poly(int n) {
  log("inside Poly int constructor");

  std::string sym{"x"};
  log("using the symbole :" + sym);

  Poly(n, sym);
};

Poly::Poly(int n, std::string &c) {
  poly_coeff.resize(n);
  int counter = 0;
  std::for_each(poly_coeff.begin(), poly_coeff.end(), [&counter, &c](Expr &x) {
    x.assign_symbol(std::format("{}{}", c, counter++));
  });
}

Poly::Poly(const Poly &other) {

  log("inside Poly copy constructor");
  // note to self never ever change how degree() before chaingin this
  for (auto &c : other.get_coeff())
    poly_coeff.push_back(c);
}
Poly Poly::inv() {
  panic("not implemented");
  return *this;
};
int Poly::degree() const { return poly_coeff.size(); };
Poly Poly::operator+(const Poly &poly_other) const {

  auto &small_poly =
      (this->degree() >= poly_other.degree()) ? poly_other : *this;

  auto &big_poly = (this->degree() < poly_other.degree()) ? poly_other : *this;

  Poly x(big_poly);
  std::for_each(small_poly.get_coeff().begin(), small_poly.get_coeff().end(),
                [&x, &small_poly](const Expr &e) {
                  int i = &e - &small_poly.get_coeff()[0];
                  x.assign(i++, x.get_coeff()[i] + small_poly.get_coeff()[i]);
                });

  log(x.to_string());
  return x;
};
Poly Poly::operator*(const Poly &poly_other) const {
  panic("not implemented");
  return Poly();
};
Poly Poly::operator%(const Poly &poly_other) const {
  panic("not implemented");
  return Poly();
};
Poly Poly::operator+(int n) const {
  panic("not implemented");
  return Poly();
};
Poly Poly::operator*(int n) const {
  panic("not implemented");
  return Poly();
};
Poly Poly::operator%(int n) const {
  panic("not implemented");
  return Poly();
};
void Poly::assign(int degree, Expr exp) {
  if (degree > this->degree())
    panic("degree mismatch in assign to ", degree, "with original degree of ",
          this->degree());

  log("changing the term ", degree, "from", poly_coeff[degree].get_expr(),
      "to ", exp.get_expr());
  poly_coeff[degree] = exp;
};
void Poly::set_degree(int degree) { poly_coeff.resize(degree); };
std::string Poly::to_string() {
  std::string s{""};
  for (auto const [n, e] : std::views::enumerate(poly_coeff)){
    auto x = std::format("{}{}^{}", e.get_expr(), "x", n);
    s += x;

    log("x : ", x);
  }
  return s;
};
const std::vector<Expr> &Poly::get_coeff() const { return poly_coeff; };
