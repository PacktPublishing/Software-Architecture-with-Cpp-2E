# Software Architecture with C++, Second Edition

Software Architecture with C++: Designing Robust C++ Systems with Modern Architectural Practices, Second Edition, published by Packt

## Chapter 15: Interservice communication

ℹ️ **Please Note:**
The examples provided below are **purely educational and demonstrative**. They are intentionally isolated from the complexities of real-world development.
Production distributed systems operate under conditions of constant failure. The sections **What is Dual Write?** and
**Pattern Illusion & Dual Write Paradox** are referenced here as examples of the architectural challenges and
paradoxes encountered in practice when simple code meets real infrastructure.

**Do not use the logic from these demo examples to build mission-critical production scenarios.**

### **What is Dual Write?**

**Dual Write** is an architectural **anti-pattern** where an application attempts to update two separate data targets (e.g., a database and a message
broker or external API) without an atomic transaction. A crash or network failure between the writes leaves the system in an inconsistent state.

______________________________________________________________________

### **Pattern Illusion & Dual Write Paradox**

In distributed systems, reliable message delivery and processing, along with distributed transaction consistency,
are achieved through patterns such as Transactional Outbox/Inbox, Idempotency Keys, Retry/Dead Letter Queue (DLQ),
Two-Phase Commit (2PC), and Saga.

However, relying on these patterns as **ad-hoc compensatory re-delivery mechanisms** over non-atomic writes fails
to solve inconsistency — it merely masks it, shifting infrastructure pain into business code while turning system state,
logs, and operational queues into graveyards of broken processes.

If you duplicate orchestrator mechanics (like Temporal, Zeebe, Cadence) by running local retries, auditing state in your own DB,
or triggering workflows inside business transactions, you fall right back into Dual Write. The orchestrator must either be
your **single source of truth** for execution state, or it simply becomes another participant in your Dual Write problem.

Notice that **Outbox and Inbox (via Idempotency Keys) are fundamentally paired**:
Outbox guarantees *at-least-once* delivery on the producer side, while Inbox uses Idempotency Keys to shield the consumer from the duplicate
processing that *at-least-once* delivery inherently creates.

While a retry simply repeats the network call, an Idempotency Key binds the retry to a unique *logical operation* (a business state change),
ensuring that the underlying domain action executes strictly once regardless of transport failures.
Consequently, an idempotency key has to be unique to a business operation, rather than to a request.
