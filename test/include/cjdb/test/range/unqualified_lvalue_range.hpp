// Copyright (c) Christopher Di Bella.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
#ifndef CJDB_TEST_UNQUALIFIED_LVALUE_RANGE_HPP
#define CJDB_TEST_UNQUALIFIED_LVALUE_RANGE_HPP

#include <array>

namespace cjdb_test {
	class unqualified_lvalue_range {
	public:
		[[nodiscard]] constexpr friend auto begin(unqualified_lvalue_range& x)
		{
			return x.data.begin();
		}

		[[nodiscard]] constexpr friend auto begin(unqualified_lvalue_range const& x) noexcept
		{
			return x.data.begin();
		}

		[[nodiscard]] constexpr friend auto end(unqualified_lvalue_range& x)
		{
			return x.data.end();
		}

		[[nodiscard]] constexpr friend auto end(unqualified_lvalue_range const& x) noexcept
		{
			return x.data.end();
		}

		// NOLINTNEXTLINE(readability-magic-numbers,misc-non-private-member-variables-in-classes)
		std::array<int, 1'000> data{};
	};

	class unqualified_lvalue_range_preferred {
	public:
		[[nodiscard]] constexpr int begin() noexcept
		{ return data.front(); }

		[[nodiscard]] constexpr int begin() const
		{ return data.front(); }

		[[nodiscard]] constexpr int end() noexcept
		{ return data.back(); }

		[[nodiscard]] constexpr int end() const
		{ return data.back(); }

		[[nodiscard]] constexpr friend auto begin(unqualified_lvalue_range_preferred& x)
		{ return x.data.begin(); }

		[[nodiscard]] constexpr friend
		auto begin(unqualified_lvalue_range_preferred const& x) noexcept
		{ return x.data.begin(); }

		[[nodiscard]] constexpr friend auto end(unqualified_lvalue_range_preferred& x)
		{ return x.data.end(); }

		[[nodiscard]] constexpr friend auto end(unqualified_lvalue_range_preferred const& x) noexcept
		{ return x.data.end(); }

		// NOLINTNEXTLINE(readability-magic-numbers,misc-non-private-member-variables-in-classes)
		std::array<int, 1'000> data{};
	};

	class unqualified_lvalue_range_private_members {
	public:
		[[nodiscard]] constexpr friend auto begin(unqualified_lvalue_range_private_members& x)
		{ return x.data.begin(); }

		[[nodiscard]] constexpr friend
		auto begin(unqualified_lvalue_range_private_members const& x) noexcept
		{ return x.data.begin(); }

		[[nodiscard]] constexpr friend auto end(unqualified_lvalue_range_private_members& x)
		{ return x.data.end(); }

		[[nodiscard]] constexpr friend
		auto end(unqualified_lvalue_range_private_members const& x) noexcept
		{ return x.data.end(); }

		// NOLINTNEXTLINE(readability-magic-numbers,misc-non-private-member-variables-in-classes)
		std::array<int, 1'000> data{};
	private:
		[[nodiscard]] constexpr auto begin() noexcept
		{ return data.begin(); }

		[[nodiscard]] constexpr auto begin() const
		{ return data.begin(); }

		[[nodiscard]] constexpr auto end() noexcept
		{ return data.end(); }

		[[nodiscard]] constexpr auto end() const
		{ return data.end(); }
	};
} // namespace cjdb_test

#endif // CJDB_TEST_UNQUALIFIED_LVALUE_RANGE_HPP
