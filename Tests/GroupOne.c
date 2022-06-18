// primary expression
// foo
// 42
// "bar"

// postfix_expression
// foo[3]
// foo[3*5+8 << 2]
// bar()
// bar(42, "foo")
// baz.bar
// baz->foo
// i++
// linked_list[i++]->child.get_data()
// arrays[j]->data.push_at_posn(stack.pop(), pos++)

// unary_operator
// &
// ~

// unary_expression
// ++bar
// +baz[5]
// !bools[i++]
// sizeof "bar"
// sizeof (++arr[42])
// !bar->bool_vals[i++]

// cast_expression
// *idtf

// multiplicative_expression
// 3 * 5
// i / (j + 7)
// (foo->idx_ptr + bar.idx) % baz[5++]

// additive_expression
// 5 + 8 - 3
// 8 - (i >> j)
// baz[k] - expr.op[0] * expr.ops[1] * expr.ops[2]
// expr->op_ptrs[0] / expr->op_ptrs[1] - strlen("foo")

// shift_expression
// 7 << 2 >> 1
// j >> (6 + i)
// ascii("foo"[i]) << max(list_vals) + 3 * j++
// vals[j++] * pair->fst >> len(arr) - 10

// relational_expression
// 3 < 6
// 4 >= k << 2
// stack.pop() * arr[5] > 3 - 4
// i++ <= student->roll_no + student.age

// equality_expression
// 4 == baz
// &(bar == "foo")
// len("foo") < len("foo2") == baz[i++]->bool
// bar != gcd(15, 25) + lcm(4, 12)

// and_expression
// 5 & 6 & 7
// max(len("foo"), len("hello")) & bar[i+j]->baz()
// 5 & stack.pop() > foo.baz(bar)

// exclusive_or_expression
// 8 ^ 5 & 0
// yer[++i] + 5 * baz ^ addr1.house_no % addr2.house_no
// bar / baz[i+j] ^ 5 - i++

// inclusive_or_expression
// 3 | 7 | 3
// foo * bar[i] | queue.pop_back() & 56
// arr[j*k] % baz | &var_ptr ^ foo

// logical_and_expression
// foo & bar & baz
// len(strcat("hello", "world")) == bar & 5 >= foo ^ baz
// 5 != baz & 4 << 2 > bar[foo]->val

// logical_or_expression
// foo || bar || baz
// bar[foo * baz] > 5 || foo ^ baz == 3981
// foo == bar || yer->bar() && baz

// conditional_expression
// foo ? bar : baz
// 5 > bar[baz ^ 2] ? arr[j++] : arr[i++]
// obj->vals[j+i] == obj->stack.pop() ? max(j, i) : len("world")

// assignment_operator
// =
// *=
// >>=
 
// assignment_expression
// j = 5
// arr[bar] = foo->baz() *= 6 ^ 7 >> 2
// person.ss_num /= &ptr = stack.pop()

// argument_expression_list
// 5, 6, i * j
// in_features = 7 | 5, out_features = ~arr[i++], bias=True
// 310 * 6, foo[bar] % baz - 4, named = obj->ptr.attr[sysarg(4)]

// expression
// foo.copy()->bar = 5, baz[7^5] = yer
// books[j]->no_pages %= books[k].year = 1875, flights[i^j] ^= bar[baz].foo("test")