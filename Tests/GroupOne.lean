
-- primary_expression
def primary_expr_ident : PrimaryExpr := `[primary_expression| foo]
def primary_expr_num : PrimaryExpr := `[primary_expression| 42]
def primary_expr_str : PrimaryExpr := `[primary_expression| "bar"]

-- postfix_expression
def postfix_expr_idx : PostfixExpr := `[postfix_expression| foo[3]]
def postfix_expr_idx_expr : PostfixExpr := `[postfix_expression| foo[3*5+8 << 2]]
def postfix_expr_call : PostfixExpr := `[postfix_expression| bar()]
def postfix_expr_call_args : PostfixExpr := `[postfix_expression| bar(42, "foo")]
def postfix_expr_attr : PostfixExpr := `[postfix_expression| baz.bar]
def postfix_expr_ptr : PostfixExpr := `[postfix_expression| baz->foo]
def postfix_expr_incr : PostfixExpr := `[postfix_expression| i++]
def postfix_expr_complex_1 : PostfixExpr :=
  `[postfix_expression| linked_list[i++]->child.get_data()]
def postfix_expr_complex_2 : PostfixExpr :=
  `[postfix_expression| arrays[j]->data.push_at_posn(stack.pop(), pos\-\-)]

-- unary_operator
def unary_op : UnaryOp := `[unary_operator| &]
def unary_op : UnaryOp := `[unary_operator| ~]

-- unary_expression
def unary_expr_incr : UnaryExpr := `[unary_expression| ++bar]
def unary_expr_op : UnaryExpr := `[unary_expression| +baz[5]]
def unary_expr_op_cast : UnaryExpr := `[unary_expression| !bools[i++]]
def unary_expr_sizeof : UnaryExpr := `[unary_expression| SIZEOF "bar"]
def unary_expr_complex_1 : UnaryExpr :=
  `[unary_expression| SIZEOF(++arr[42]))]
def unary_expr_complex_2 : UnaryExpr :=
  `[unary_expression| !bar->bool_vals[i++]]

-- cast_expression
def cast_expr_unary1 : CastExpr := `[cast_expression| \-\-foo]
def cast_expr_unary2 : CastExpr := `[cast_expression| *idtf]

-- multiplicative_expression
def multiplicative_expr_mult : MultExpr := `[multiplicative_expression| 3 * 5]
def mult_expr_div : MultExpr := `[multiplicative_expression| i / (j + 7)]
def mult_expr_mod : MultExpr := `[multiplicative_expression| (foo->idx_ptr + bar.idx) % baz[5++]]

-- additive_expression
def add_expr_plus : AddExpr := `[additive_expression| 5 + 8 - 3]
def add_expr_minus : AddExpr := `[additive_expression| 8 - (i >> j)]
def add_expr_complex_1 : AddExpr :=
  `[additive_expression| baz[k] - expr.op[0] * expr.ops[1] * expr.ops[2]]
def add_expr_complex_2 : AddExpr :=
  `[additive_expression| expr->op_ptrs[0] / expr->op_ptrs[1] - strlen("foo")]

-- shift_expression
def shift_expr_left : ShiftExpr := `[shift_expression| 7 << 2 >> 1]
def shift_expr_right : ShiftExpr := `[shift_expression| j >> (6 + i)]
def shift_expr_complex_1 : ShiftExpr :=
  `[shift_expression| ascii("foo"[i]) << max(list_vals) + 3 * j++]
def shift_expr_complex_2 : ShiftExpr :=
  `[shift_expression| vals[j++] * pair->fst >> len(arr) - 10]

-- relational_expression
def rel_expr_lt : RelExpr := `[relational_expression| 3 < 6]
def rel_expr_ge : RelExpr := `[relational_expression| 4 >= k << 2]
def rel_expr_complex_1 : RelExpr :=
  `[relational_expression| stack.pop() * arr[5] > 3 - 4]
def rel_expr_complex_2 : RelExpr :=
  `[relational_expression| i++ <= student->roll_no + student.age]

-- equality_expression
def eq_expr_eq : EqExpr := `[equality_expression| 4 == baz]
def eq_expr_ne : EqExpr := `[equality_expression| &(bar == "foo")]
def eq_expr_complex_1 : EqExpr :=
  `[equality_expression| len("foo") < len("foo2") == baz[i++]->bool]
def eq_expr_complex_2 : EqExpr :=
  `[equality_expression| bar != gcd(15, 25) + lcm(4, 12)]

-- and_expression
def and_expr : AndExpr := `[and_expression| 5 & 6 & 7]
def and_expr_copmlex_1 :=
  `[and_expression| max(len("foo"), len("hello")) & bar[i+j]->baz()]
def and_expr_complex_2 :=
  `[and_expression| 5 & stack.pop() > foo.baz(bar)]

-- exclusive_or_expression
def xor_expr : XOrExpr := `[exclusive_or_expression| 8 ^ 5 & 0]
def xor_expr_complex_1 : XOrExpr :=
  `[exclusive_or_expression| yer[\-\-i] + 5 * baz ^ addr1.house_no % addr2.house_no]
def xor_expr_complex_2 :XOrExpr :=
  `[exclusive_or_expression| bar / baz[i+j] ^ 5 - i++]

-- inclusive_or_expression
def or_expr : IOrExpr := `[inclusive_or_expression| 3 | 7 | 3]
def or_expr_complex_1 : IOrExpr :=
  `[inclusive_or_expression| foo * bar[i] | queue.pop_back() & 56]
def or_expr_complex_2 : IOrExpr :=
  `[inclusive_or_expression| arr[j*k] % baz | &var_ptr ^ foo]

-- logical_and_expression
def land_expr : LAndExpr := `[logical_and_expression| foo & bar & baz]
def land_expr_complex_1 : LAndExpr :=
  `[logical_and_expression| len(strcat("hello", "world")) == bar & 5 >= foo ^ baz]
def land_expr_complex_2 : LAndExpr :=
  `[logical_and_expression| 5 != baz & 4 << 2 > bar[foo]->val]

-- logical_or_expression
def lor_expr : LOrExpr := `[logical_or_expression| foo || bar || baz]
def lor_expr_complex_1 : LOrExpr :=
  `[logical_or_expression| bar[foo * baz] > 5 || foo ^ baz == 3981]
def lor_expr_complex_2 : LOrExpr :=
  `[logical_or_expression| foo == bar || yer->bar() && baz]

-- conditional_expression
def cond_expr_tern : CondExpr := `[conditional_expression| foo ? bar : baz]
def cond_expr_complex_1 : CondExpr :=
  `[conditional_expression| 5 > bar[baz ^ 2] ? arr[j++] : arr[i\-\-]]
def cond_expr_complex_2 : CondExpr :=
  `[conditional_expression| obj->vals[j+i] == obj->stack.pop() ? max(j, i) : len("world")]

-- assignment_operator
def assignment_operator_eq : AssmtOp := `[assignment_operator| =]
def assignment_operator_mul : AssmtOp := `[assignment_operator| *=]
def assignment_operator_right : AssmtOp := `[assignment_operator | >>=]

-- assignment_expression
def assmt_expr : AssmtExpr := `[assignment_expression| j = 5]
def assmt_expr_complex_1 : AssmtExpr :=
  `[assignment_expression| arr[bar] = foo->baz() *= 6 ^ 7 >> 2]
def assmt_expr_complex_2 : AssmtExpr :=
  `[assignment_expression| person.ss_num /= &ptr = stack.pop()]

-- argument_expression_list
def argument_expression_list : ArgExprList := `[argument_expression_list| 5, 6, i * j]
def argument_expression_list_complex_1 : ArgExprList :=
  `[argument_expression_list| in_features = 7 | 5, out_features = ~arr[i++], bias=True]
def argument_expression_list_complex_2 : ArgExprList :=
  `[argument_expression_list| 310 * 6, foo[bar] % baz - 4, named = obj->ptr.attr[sysarg(4)]]

-- expression
def expr_complex_1 : Expr :=
  `[expression| foo.copy()->bar = 5, baz[7^5] = yer]
def expr_complex_2 : Expr :=
  `[expression| books[j]->no_pages %= books[k].year = 1875, flights[i^j] ^= bar[baz].foo("test")]
