#include <algorithm>
#include <format>
#include <iostream>
#include <ranges>
#include <vector>
#include <Poly.hpp>
Poly::Poly() { log("inside Poly default constructor"); };
Poly::Poly(int n):Poly(n,"x") {
  log("inside Poly int constructor");

  std::string sym{"x"};
  log("using the symbole :" + sym);

};

Poly::Poly(int n, std::string c) {
  poly_coeff.resize(n);
  int counter = 0;
  log("before");
  std::for_each(poly_coeff.begin(), poly_coeff.end(), [&counter, &c](Expr &x) {
    x.assign_symbol(std::format("{}{}", c, counter++));
  });

  for(auto & c: poly_coeff)
    log("final expr : ", c.get_expr());
}

Poly::Poly(const Poly &other) {

  log("inside Poly copy constructor");
  // note to self never ever change how degree() before chaingin this
  for (auto &c : other.get_coeff()) {
    log("inside for loop");
    poly_coeff.push_back(c);

  }
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

  log("adding polynomials :", small_poly.to_string(), " + ", big_poly.to_string());
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
std::string Poly::to_string() const {
  std::string s{""};
  log("inside poly to_string");
  log("size of poly_coeff: ", poly_coeff.size() );
  for (auto const [n, e] : std::views::enumerate(poly_coeff)){
    auto x = std::format("{}{}^{}", e.get_expr(), "x", n);
    s += x;

    log("x : ", x);
  }
  return s;
};
const std::vector<Expr> &Poly::get_coeff() const { log("get_coeff returning: ", poly_coeff.size());return poly_coeff; };
