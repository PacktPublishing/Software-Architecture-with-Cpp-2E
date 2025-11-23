#include <stores/customer.h>
#include <stores/merchant.h>
#include <stores/store.h>

int main() {
  using namespace trade_fair;

  Merchant merchant;
  CustomerId id = get_current_customer_id();
  Store store;
}
