//
//  Copyright Christopher Di Bella
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#ifndef CJDB_DETAIL_CONCEPTS_CORE_CONVERTIBLETO_HPP
#define CJDB_DETAIL_CONCEPTS_CORE_CONVERTIBLETO_HPP

#include "cjdb/detail/type_traits/type_traits.hpp"

namespace cjdb {
   /// \see [concept.convertibleto]
   ///
   template<class From, class To>
   concept ConvertibleTo =
      is_convertible_v<From, To> and
      requires(From (&f)()) {
         static_cast<To>(f());
      };
} // namespace cjdb

#endif // CJDB_DETAIL_CONCEPTS_CORE_CONVERTIBLETO_HPP