#include <iostream>
#include <memory>
#include <string>
#include <utility>

class Resource final {
  std::string m_s;

public:
  explicit Resource(std::string s) : m_s{std::move(s)} {
    std::cout << "Resource constructor " << m_s << '\n';
  }

  ~Resource() { std::cout << "Resource destructor " << m_s << '\n'; }

  // user-defined conversion function
  explicit operator std::string() const { return m_s; }
};

std::ostream &operator<<(std::ostream &os, const Resource &r) {
  os << static_cast<std::string>(r);
  return os;
}

void unique_ptr_val(std::unique_ptr<Resource> p) {
  std::cout << "unique_ptr_val: value = " << *p << std::endl;
}

void unique_ptr_ref(std::unique_ptr<Resource> &p) {
  std::cout << "unique_ptr_ref: value = " << *p << std::endl;
}

void unique_ptr_raw(std::unique_ptr<Resource> *p) {
  std::cout << "unique_ptr_raw: value = " << **p << std::endl;
}

void shared_ptr_val(std::shared_ptr<Resource> p) {
  std::cout << "shared_ptr_val: value = " << *p << std::endl;
}

void shared_ptr_ref(std::shared_ptr<Resource> &p) {
  std::cout << "shared_ptr_ref: value = " << *p << std::endl;
}

void shared_ptr_raw(std::shared_ptr<Resource> *p) {
  std::cout << "shared_ptr_raw: value = " << **p << std::endl;
}

void weak_ptr_val(std::weak_ptr<Resource> wp) {
  if (std::shared_ptr sp = wp.lock()) {
    std::cout << "weak_ptr_val: value = " << *sp << std::endl;
  } else {
    std::cout << "weak_ptr_val: expired" << std::endl;
  }
}

void weak_ptr_ref(std::weak_ptr<Resource> &wp) {
  if (std::shared_ptr sp = wp.lock()) {
    std::cout << "weak_ptr_ref (shared_ptr): value = " << *sp << std::endl;
  } else {
    std::cout << "weak_ptr_ref: expired" << std::endl;
  }
}

void weak_ptr_raw(std::weak_ptr<Resource> *wp) {
  if (std::shared_ptr sp = wp->lock()) {
    std::cout << "weak_ptr_ref (shared_ptr): value = " << *sp << std::endl;
  } else {
    std::cout << "weak_ptr_ref: expired" << std::endl;
  }
}

void val(Resource p) { std::cout << "val: value = " << p << std::endl; }

void ref(Resource &p) { std::cout << "ref: value = " << p << std::endl; }

void raw(Resource *p) { std::cout << "raw: value = " << *p << std::endl; }

int main() {
  {
    auto p = std::make_unique<Resource>("candy apple");

    // unique_ptr_val(ptr); // compilation error: deleted copy constructor
    unique_ptr_val(std::move(p)); // not copyable, but movable

    // the resource is moved and destroyed in unique_ptr_val()
    std::cout << "unique_ptr_main: value = "
              << (p != nullptr ? static_cast<std::string>(*p) : "null")
              << std::endl;
  }

  std::cout << std::endl;

  {
    auto p = std::make_unique<Resource>("jet town");

    // violation: exclusive ownership
    unique_ptr_ref(p);
    unique_ptr_raw(&p);

    // the ownership is not moved
    std::cout << "unique_ptr_main: value = " << *p << std::endl;
  }

  std::cout << std::endl;

  {
    auto up = std::make_unique<Resource>("walkman on");
    std::shared_ptr sp = std::move(up);

    // shared ownership
    shared_ptr_val(sp);

    std::cout << "unique_ptr_main: value = "
              << (up != nullptr ? static_cast<std::string>(*up) : "null")
              << std::endl;
    std::cout << "shared_ptr_main: value = " << *sp << std::endl;
  }

  std::cout << std::endl;

  {
    auto p = std::make_shared<Resource>("playback");

    // no shared ownership
    shared_ptr_ref(p);
    shared_ptr_raw(&p); // little sense

    std::cout << "shared_ptr_main: value = " << *p << std::endl;
  }

  std::cout << std::endl;

  {
    auto sp = std::make_shared<Resource>("synth samurai");
    std::weak_ptr wp = sp;

    weak_ptr_val(wp);
    weak_ptr_ref(wp); // little sense
    weak_ptr_val(wp); // little sense

    std::cout << "shared_ptr_main: value = " << *sp << std::endl;

    sp.reset(); // nullified

    weak_ptr_val(wp);

    std::cout << "shared_ptr_main: value = "
              << (sp != nullptr ? static_cast<std::string>(*sp) : "null")
              << std::endl;
  }

  std::cout << std::endl;

  {
    auto p = std::make_unique<Resource>("tonight");

    // out of control
    val(*p.get());
    ref(*p.get());
    raw(p.get());

    std::cout << "unique_ptr_main: value = "
              << (p != nullptr ? static_cast<std::string>(*p) : "null")
              << std::endl;
  }
}
