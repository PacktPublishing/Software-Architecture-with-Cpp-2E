#include <iostream>
#include <memory>
#include <string>
#include <utility>

using Resource = std::string;

void unique_ptr_val(std::unique_ptr<Resource> p) {
  std::cout << "unique_ptr_val: value = " << *p << std::endl;
}

void unique_ptr_ref(std::unique_ptr<Resource>& p) {
  std::cout << "unique_ptr_ref: value = " << *p << std::endl;
}

void unique_ptr_raw(std::unique_ptr<Resource>* p) {
  std::cout << "unique_ptr_raw: value = " << **p << std::endl;
}

void shared_ptr_val(std::shared_ptr<Resource> p) {
  std::cout << "shared_ptr_val: value = " << *p << std::endl;
}

void shared_ptr_ref(std::shared_ptr<Resource>& p) {
  std::cout << "shared_ptr_ref: value = " << *p << std::endl;
}

void shared_ptr_raw(std::shared_ptr<Resource>* p) {
  std::cout << "shared_ptr_raw: value = " << **p << std::endl;
}

void weak_ptr_val(std::weak_ptr<Resource> wp) {
  if (std::shared_ptr sp = wp.lock()) {
    std::cout << "weak_ptr_val: value = " << *sp << std::endl;
  } else {
    std::cout << "weak_ptr_val: expired" << std::endl;
  }
}

void weak_ptr_ref(std::weak_ptr<Resource>& wp) {
  if (std::shared_ptr sp = wp.lock()) {
    std::cout << "weak_ptr_ref (shared_ptr): value = " << *sp << std::endl;
  } else {
    std::cout << "weak_ptr_ref: expired" << std::endl;
  }
}

void weak_ptr_raw(std::weak_ptr<Resource>* wp) {
  if (std::shared_ptr sp = wp->lock()) {
    std::cout << "weak_ptr_ref (shared_ptr): value = " << *sp << std::endl;
  } else {
    std::cout << "weak_ptr_ref: expired" << std::endl;
  }
}

void val(Resource p) { std::cout << "val: value = " << p << std::endl; }

void ref(Resource& p) { std::cout << "ref: value = " << p << std::endl; }

void raw(Resource* p) { std::cout << "raw: value = " << *p << std::endl; }

int main() {
  {
    auto p = std::make_unique<Resource>("candy apple");

    // unique_ptr_val(ptr); // compilation error: deleted copy constructor
    unique_ptr_val(std::move(p));  // not copyable, but movable

    std::cout << "unique_ptr_main: value = " << (p != nullptr ? *p : "null")
              << std::endl;
  }

  {
    auto p = std::make_unique<Resource>("jet town");

    unique_ptr_ref(p);   // conceptual error: exclusive ownership violation
    unique_ptr_raw(&p);  // conceptual error: exclusive ownership violation

    std::cout << "unique_ptr_main: value = " << *p << std::endl;
  }

  {
    auto up = std::make_unique<Resource>("walkman on");
    std::shared_ptr sp = std::move(up);

    shared_ptr_val(sp);

    std::cout << "unique_ptr_main: value = " << (up != nullptr ? *up : "null")
              << std::endl;
    std::cout << "shared_ptr_main: value = " << *sp << std::endl;
  }

  {
    auto p = std::make_shared<Resource>("incognito");

    shared_ptr_ref(p);   // conceptual error: ownership violation
    shared_ptr_raw(&p);  // conceptual error: ownership violation

    std::cout << "shared_ptr_main: value = " << *p << std::endl;
  }

  {
    auto sp = std::make_shared<Resource>("trip");
    std::weak_ptr wp = sp;

    weak_ptr_val(wp);
    weak_ptr_ref(wp);
    weak_ptr_val(wp);

    std::cout << "shared_ptr_main: value = " << *sp << std::endl;

    sp.reset();

    weak_ptr_val(wp);

    std::cout << "shared_ptr_main: value = " << (sp != nullptr ? *sp : "null")
              << std::endl;
  }

  {
    auto p = std::make_unique<Resource>("tonight");

    val(*p.get());  // out of control
    ref(*p.get());  // out of control
    raw(p.get());   // out of control

    std::cout << "unique_ptr_main: value = " << (p != nullptr ? *p : "null")
              << std::endl;
  }
}
