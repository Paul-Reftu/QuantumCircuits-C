#ifndef Q_CIRCUIT_H
#define Q_CIRCUIT_H

#include <gsl/gsl_complex_math.h>
#include <gsl/gsl_blas.h>
#include <math.h>

typedef struct q_op{
  gsl_matrix_complex* matrix;
  int qubits;
} q_op;

typedef struct q_state{
  gsl_matrix_complex* vector;
  int qubits;
} q_state;

/**g_state_alloc
  *Allocates a q_state struct.
    *qubits. The number of qubits of the q_state.
  Returns the empty state "state".
*/
q_state* q_state_alloc(int qubits);

/**q_state_calloc
  *Allocates a q_state struct and initialises all entries to zero. Note that this is not a valid quantum state and must be changed.
    *qubits. The number of qubits of the q_state.
  Returns the generated state "state"
*/
q_state* q_state_calloc(int qubits);

/**q_state_free
  *Frees a given q_state.
    *state. The state to free.
*/
void q_state_free(q_state* state);

/**q_state_print
  *Prints a q_state.
    *state. The state to print.
*/
void q_state_print(q_state* state);

/**q_op_alloc
  *Allocates a q_op struct.
    *qubits. The number of qubits that the q_op operates on.
  Returns the generated operator "op"
*/
q_op* q_op_alloc(int qubits);

/**q_op_calloc
  *Allocates a q_op struct and initialises all entries to zero. Note that this is not a valid quantum operator and must be changed.
    *qubits. The number of qubits that the q_op operates on.
  Returns the generated operator "op"
*/
q_op* q_op_calloc(int qubits);

/**q_op_free
  *Frees a given q_op.
    *op. The state to op.
*/
void q_op_free(q_op* op);

/**q_op_print
  *Prints a q_op.
    *op. The op to print.
*/
void q_op_print(q_op* op);

/**apply_qop
  *Applies a q_op operator to a state. The old state is not destroyed and must be freed by the user.
    *op. The q_op to apply.
    *state. The state to apply the q_op to.
  Returns new_state
*/
q_state* apply_qop(q_op* op, q_state* state);

/**q_state_tensor
  *Performs the matrix tensor operation on quantum states a and b. Neither a nor b is destroyed and both must be freed by the user.
    *a. The first q_state.
    *b. The second q_state.
  *Returns the tensor of a and b "new_state".
*/
q_state* q_state_tensor(q_state* a, q_state* b);

/**q_op_tensor
  *Performs the matrix tensor operation on quantum operators a and b. Neither a nor b is destroyed and both must be freed by the user.
    *a. The first q_op.
    *b. The second q_op.
  *Returns the tensor of a and b "new_op".
*/
q_op* q_op_tensor(q_op* a, q_op* b);

#endif
