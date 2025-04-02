#pragma once

class Consultant;

class PaymentCalculator final {
 public:
  double calculate() const { return {}; }

  void setConsultant(const Consultant &c) { consultant_ = c; }
  void setTaxPercentage(double tax) { taxPercentage_ = tax; }

 private:
  std::reference_wrapper<const Consultant> consultant_;
  double taxPercentage_{};
};
