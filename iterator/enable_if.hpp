namespace ft
{
template <bool Bool, class T = void>
struct enable_if {};

template <class T>
struct enable_if<true, T> { typedef T type; };

struct true_type {
  static const bool valor = true;
  typedef true_type type;
  typedef bool value_type;
};

struct false_type {
  static const bool valor = false;
  typedef false_type type;
  typedef bool value_type;
};

// Gives a bool true if T is integral
template < class T >
struct is_integral : public false_type {};

template <>
struct is_integral<bool> : public true_type {};
template <>
struct is_integral<char> : public true_type {};
template <>
struct is_integral<char16_t> : public true_type {};
template <>
struct is_integral<char32_t> : public true_type {};
template <>
struct is_integral<wchar_t> : public true_type {};
template <>
struct is_integral<signed char> : public true_type {};
template <>
struct is_integral<short int> : public true_type {};
template <>
struct is_integral<int> : public true_type {};
template <>
struct is_integral<long int> : public true_type {};
template <>
struct is_integral<long long int> : public true_type {};
template <>
struct is_integral<unsigned char> : public true_type {};
template <>
struct is_integral<unsigned short int> : public true_type {};
template <>
struct is_integral<unsigned int> : public true_type {};
template <>
struct is_integral<unsigned long int> : public true_type {};
template <>
struct is_integral<unsigned long long int> : public true_type {};

}; // namespace ft