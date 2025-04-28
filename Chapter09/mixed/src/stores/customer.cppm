module;

#include "stores/customer.h"

export module customer;

// re-export
export {
  using ::CustomerId;

  using ::get_current_customer_id;
}
