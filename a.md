 * <p>This transaction manager supports nested transactions via JDBC Savepoints.
 * The {@link #setNestedTransactionAllowed "nestedTransactionAllowed"} flag defaults
 * to {@code true}, but nested transactions will just apply to the JDBC
 * Connection, not to the JPA EntityManager and its cached entity objects and related
 * context. You can manually set the flag to {@code false} if you want to disallow nested
 * transactions for JDBC access code which participates in JPA transactions (provided
 * that your JDBC driver supports Savepoints). <i>Note that JPA itself does not support
 * nested transactions! Furthermore, as most JPA providers do not support savepoints,
 * {@code Propagation.NESTED} will not work and will typically
 * result in an exception. Hence, do not expect JPA access code to semantically
 * participate in a nested transaction.</i>