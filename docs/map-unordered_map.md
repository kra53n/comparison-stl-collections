# Comparing `map` with `unordered map`

## Individaulity

### Comparison table

type | `map` | `unordered map`
--: | --- | ---
Member types | `key_compare` `reverse_iterator` `const_reverse_iterator` | `key_equal` `local_iterator` `hasher` `const_local_iterator` 
Member classes | `value_compare` | 
Member functions | `key_comp` `rbegincrbegin` `lower_bound` `rendcrend` `upper_bound` `value_comp` | `end(size_type) cend(size_type)` `bucket_size` `max_bucket_count` `reserve` `begin(size_type) cbegin(size_type)` `bucket` `max_load_factor` `key_eq` `bucket_count` `load_factor` `rehash` `hash_function` 
Non-member classes | `operator<` `operator<=` `operator>` `operator>=` `operator<=>` | 

### `map`

#### Member types

- `key_compare`
- `reverse_iterator`
- `const_reverse_iterator`

#### Member classes

- `value_compare`

#### Member functions

- `key_comp`
- `rbegincrbegin`
- `lower_bound`
- `rendcrend`
- `upper_bound`
- `value_comp`

#### Non-memnber functions

- `operator<`
- `operator<=`
- `operator>`
- `operator>=`
- `operator<=>`

### `unordered map`

#### Member types

- `key_equal`
- `local_iterator`
- `hasher`
- `const_local_iterator`

#### Member functions

- `end(size_type) cend(size_type)`
- `bucket_size`
- `max_bucket_count`
- `reserve`
- `begin(size_type) cbegin(size_type)`
- `bucket`
- `max_load_factor`
- `key_eq`
- `bucket_count`
- `load_factor`
- `rehash`
- `hash_function`

## Common

### Member types

- `allocator_type`
- `value_type`
- `const_pointer`
- `key_type`
- `const_reference`
- `size_type`
- `node_type`
- `insert_return_type`
- `const_iterator`
- `difference_type`
- `iterator`
- `reference`
- `mapped_type`
- `pointer`

### Member functions

- `begin cbegin`
- `merge`
- `count`
- `at`
- `emplace`
- `empty`
- `swap`
- `get_allocator`
- `erase`
- `emplace_hint`
- `insert`
- `extract`
- `find`
- `size`
- `try_emplace`
- `insert_or_assign`
- `max_size`
- `contains`
- `(constructor)`
- `end  cend`
- `equal_range`
- `clear`
- `(destructor)`
- `operator[]`
- `operator=`

### Non-member functions

- `operator==`
- `operator!=`
- `std::swap`
- `erase_if`
