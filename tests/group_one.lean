-- primary_expression
def primary_expr_ident : PrimaryExpr := [primary_expr| foo]
def primary_expr_num : PrimaryExpr := `[primary_expr| 42]
def primary_expr_str : PrimaryExpr := [primary_expr| "bar"]

-- postfix_expression
def postfix_expr_idx : PostfixExpr := [postfix_expr| foo[3]]
def postfix_expr_idx_expr : PostfixExpr := [postfix_expr| foo[3*5+8 << 2]]
def postfix_expr_call : PostfixExpr := [postfix_expr| bar()]
def postfix_expr_call_args : PostfixExpr := [postfix_expr| bar(42, "foo")]
def postfix_expr_attr : PostfixExpr := [postfix_expr| baz.bar]
def postfix_expr_ptr : PostfixExpr := [postfix_expr| baz->foo]
def postfix_expr_incr : PostfixExpr := [postfix_expr| i++]
def postfix_expr_complex_1 : PostfixExpr :=
  [postfix_expr| linked_list[i++]->child.get_data()]
def postfix_expr_complex_2 : PostfixExpr :=
  [postfix_expr| arrays[j]->data.push_at_posn(stack.pop(), pos\-\-)]

-- unary_operator
def unary_op := UnaryOp := [unary_op| &]
def unary_op := UnaryOp := [unary_op| ~]

-- unary_expression
def unary_expr_incr : UnaryExpr := [unary_expr| ++bar]
def unary_expr_op : UnaryExpr := [unary_expr| +baz[5]]
def unary_expr_op_cast : UnaryExpr := [unary_expr| !bools[i++]]
def unary_expr_sizeof : UnaryExpr := [unary_expr| SIZEOF "bar"]
def unary_expr_complex_1 : UnaryExpr :=
  [unary_expr| SIZEOF(++arr[42]))]
def unary_expr_complex_2 : UnaryExpr :=
  [unary_expr| !bar->bool_vals[i++]]

-- cast_expression
def cast_expr_unary1 : CastExpr := [cast_expr| \-\-foo]
def cast_expr_unary2 : CastExpr := [cast_expr| *idtf]

-- multiplicative_expression
def mult_expr_mult : MultExpr := [mult_expr| 3 * 5]
def mult_expr_div : MultExpr := [mult_expr| i / (j + 7)]
def mult_expr_mod : MultExpr := [mult_expr| (foo->idx_ptr + bar.idx) % baz[5++]]

-- additive_expression
def add_expr_plus : AddExpr := [add_expr| 5 + 8 - 3]
def add_expr_minus : AddExpr := [add_expr| 8 - (i >> j)]
def add_expr_complex_1 : AddExpr :=
  [add_expr| baz[k] - expr.op[0] * expr.ops[1] * expr.ops[2]]
def add_expr_complex_2 : AddExpr :=
  [add_expr| expr->op_ptrs[0] / expr->op_ptrs[1] - strlen("foo")]

-- shift_expression
def shift_expr_left : ShiftExpr := [shift_expr| 7 << 2 >> 1]
def shift_expr_right : ShiftExpr := [shift_expr| j >> (6 + i)]
def shift_expr_complex_1 : ShiftExpr :=
  [shift_expr| ascii("foo"[i]) << max(list_vals) + 3 * j++]
def shift_expr_complex_2 : ShiftExpr :=
  [shift_expr| vals[j++] * pair->fst >> len(arr) - 10]

-- relational_expression
def rel_expr_lt : RelExpr := [rel_expr| 3 < 6]
def rel_expr_ge : RelExpr := [rel_expr| 4 >= k << 2]
def rel_expr_complex_1 : RelExpr :=
  [rel_expr| stack.pop() * arr[5] > 3 - 4]
def rel_expr_complex_2 : RelExpr :=
  [rel_expr| i++ <= student->roll_no + student.age]

-- equality_expression
def eq_expr_eq : EqExpr := [eq_expr| 4 == baz]
def eq_expr_ne : EqExpr := [eq_expr| &(bar == "foo")]
def eq_expr_complex_1 : EqExpr :=
  [eq_expr| len("foo") < len("foo2") == baz[i++]->bool]
def eq_expr_complex_2 : EqExpr :=
  [eq_expr| bar != gcd(15, 25) + lcm(4, 12)]

-- and_expression
def and_expr : AndExpr := [and_expr| 5 & 6 & 7]
def and_expr_copmlex_1 :=
  [and_expr| max(len("foo"), len("hello")) & bar[i+j]->baz()]
def and_expr_complex_2 :=
  [and_expr| 5 & stack.pop() > foo.baz(bar)]

-- exclusive_or_expression
def xor_expr : XOrExpr := [xor_expr| 8 ^ 5 & 0]
def xor_expr_complex_1 : XOrExpr :=
  [xor_expr| yer[\-\-i] + 5 * baz ^ addr1.house_no % addr2.house_no]
def xor_expr_complex_2 :XOrExpr :=
  [xor_expr| bar / baz[i+j] ^ 5 - i++]

-- inclusive_or_expression
def or_expr : OrExpr := [or_expr| 3 | 7 | 3]
def or_expr_complex_1 : OrExpr :=
  [or_expr| foo * bar[i] | queue.pop_back() & 56]
def or_expr_complex_2 : OrExpr :=
  [or_expr| arr[j*k] % baz | &var_ptr ^ foo]

-- logical_and_expression
def land_expr : LAndExpr := [land_expr| foo & bar & baz]
def land_expr_complex_1 : LAndExpr :=
  [land_expr| len(strcat("hello", "world")) == bar & 5 >= foo ^ baz]
def land_expr_complex_2 : LAndExpr :=
  [land_expr| 5 != baz & 4 << 2 > bar[foo]->val]

-- logical_or_expression
def lor_expr : LOrExpr := [lor_expr| foo || bar || baz]
def lor_expr_complex_1 : LOrExpr :=
  [lor_expr| bar[foo * baz] > 5 || foo ^ baz == 3981]
def lor_expr_complex_2 : LOrExpr :=
  [lor_expr| foo == bar || yer->bar() && baz]

-- conditional_expression
def cond_expr_tern : CondExpr := [cond_expr| foo ? bar : baz]
def cond_expr_complex_1 : CondExpr :=
  [cond_expr| 5 > bar[baz ^ 2] ? arr[j++] : arr[i\-\-]]
def cond_expr_complex_2 : CondExpr :=
  [cond_expr| obj->vals[j+i] == obj->stack.pop() ? max(j, i) : len("world")]

-- assignment_operator
def assmt_op_eq : AssmtOp := [assmt_op| =]
def assmt_op_mul : AssmtOp := [assmt_op| *=]
def assmt_op_right : AssmtOp := [assmt_op | >>=]

-- assignment_expression
def assmt_expr : AssmtExpr := [assmt_expr| j = 5]
def assmt_expr_complex_1 : AssmtExpr :=
  [assmt_expr| arr[bar] = foo->baz() *= 6 ^ 7 >> 2]
def assmt_expr_complex_2 : AssmtExpr :=
  [assmt_expr| person.ss_num /= &ptr = stack.pop()]

-- argument_expression_list
def arg_expr_list : ArgExprList := [arg_expr_list| 5, 6, i * j]
def arg_expr_list_complex_1 : ArgExprList :=
  [arg_expr_list| in_features = 7 | 5, out_features = ~arr[i++], bias=True]
def arg_expr_list_complex_2 : ArgExprList :=
  [arg_expr_list| 310 * 6, foo[bar] % baz - 4, named = obj->ptr.attr[sysarg(4)]]

-- expression
def expr_complex_1 : Expr :=
  [expr| foo.copy()->bar = 5, baz[7^5] = yer]
def expr_complex_2 : Expr :=
  [expr| books[j]->no_pages %= books[k].year = 1875, flights[i^j] ^= bar[baz].foo("test")]