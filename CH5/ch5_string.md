# A Quick Guide on When to Use `std::string` vs `std::string_view`

This guide is not meant to be comprehensive but is intended to highlight the most common cases:

## Use a `std::string` variable when:

- You need a string that you can modify.
- You need to store user-inputted text.
- You need to store the return value of a function that returns a `std::string`.

## Use a `std::string_view` variable when:

- You need read-only access to part or all of a string that already exists elsewhere and will not be modified or destroyed before use of the `std::string_view` is complete.
- You need a symbolic constant for a C-style string.
- You need to continue viewing the return value of a function that returns a C-style string or a non-dangling `std::string_view`.

## Use a `std::string` function parameter when:

- The function needs to modify the string passed in as an argument without affecting the caller. This is rare.
- You are using a language standard older than C++17.
- You meet the criteria of the pass-by-reference cases covered in lesson 12.5 -- Pass by lvalue reference.

## Use a `std::string_view` function parameter when:

- The function needs a read-only string.

## Use a `std::string` return type when:

- The return value is a `std::string` local variable.
- The return value is a function call or operator that returns a `std::string` by value.
- You meet the criteria of the return-by-reference cases covered in lesson 12.12 -- Return by reference and return by address.

## Use a `std::string_view` return type when:

- The function returns a C-style string literal or local `std::string_view` that has been initialized with a C-style string literal.
- The function returns a `std::string_view` parameter.

## Things to remember about `std::string`:

- Initializing and copying `std::string` is expensive, so avoid this as much as possible.
- Avoid passing `std::string` by value, as this makes a copy.
- If possible, avoid creating short-lived `std::string` objects.
- Modifying a `std::string` will invalidate any views to that string.

## Things to remember about `std::string_view`:

- Because C-style string literals exist for the entire program, it is always okay to set a `std::string_view` to a C-style string literal.
- When a string is destroyed, all views to that string are invalidated.
- Using an invalidated view (other than using assignment to revalidate the view) will cause undefined behavior.
- A `std::string_view` may or may not be null-terminated.
