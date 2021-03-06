// Copyright (c) Christopher Di Bella.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
#ifndef CJDB_CONCEPTS_CALLABLE_STRICTWEAKORDER_HPP
#define CJDB_CONCEPTS_CALLABLE_STRICTWEAKORDER_HPP

#include "cjdb/concepts/callable/relation.hpp"

namespace cjdb {
	/// \brief A `relation` satisfies `strict_weak_order` only if it imposes a strict weak ordering on
	///        its arguments.
	///
	/// The term _strict_ refers to the requirement of an irreflexive relation (`!comp(x, x)` for all
	/// `x`), and the term _weak_ to requirements that are not as strong as those for a total
	/// ordering, but stronger than those for a partial ordering. If we define `equiv(a, b)` as
	/// `!comp(a, b) and !comp(b, a)`, then the requirements are that `comp` and `equiv` both be
	/// transitive relations:
	///   * `comp(a, b) and comp(b, c)` implies `comp(a, c)`
	///   * `equiv(a, b) and equiv(b, c)` implies `equiv(a, c)`
	///
	/// \note Under these conditions, it can be shown that
	///   * `equiv` is an equivalence relation,
	///   * `comp` induces a well-defined relation on the equivalence classes determined by `equiv`,
	///      and
	///   * the induced relation is a strict total ordering.
	///
	/// \see [concept.strictweakorder]
	///
	template<class R, class T, class U>
	concept strict_weak_order = relation<R, T, U>;
	// axiom(R&& r, T&& a, U&& b) {
	//    common_reference_t<remove_reference_t<T> const&, remove_reference_t<U> const&> c;
	//    relation<T, U> comp;
	//
	//    not comp(a, a);
	//    not comp(b, b);
	//
	//    {
	//       [[assert: comp(a, b)]];
	//       [[assert: comp(b, c)]];
	//       -> comp(a, c);
	//    }
	//    {
	//       auto equiv = [&comp](T&& t, U&& u) { return not comp(a, b) and not comp(b, a); };
	//       [[assert: eqiv(a, b)]];
	//       [[assert: eqiv(b, c)]];
	//       -> eqiv(a, c);
	//    }
	// }
} // namespace cjdb

#endif // CJDB_CONCEPTS_CALLABLE_STRICTWEAKORDER_HPP
