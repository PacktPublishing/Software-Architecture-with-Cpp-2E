module;

export module customer;

export namespace trade_fair {
using CustomerId = int;

CustomerId get_current_customer_id() { return 42; }
} // namespace trade_fair
