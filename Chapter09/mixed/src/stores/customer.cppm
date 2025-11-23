module;

#include "stores/customer.h"

export module customer;

// re-export
export {
  using trade_fair::CustomerId;

  using trade_fair::get_current_customer_id;
}
