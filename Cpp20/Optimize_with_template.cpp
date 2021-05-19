#include <type_traits>
#include <algorithm>

namespace MyEnableIfNs
{

    // STRUCT TEMPLATE enable_if
    template <bool _Test, class _Ty = void>
    struct enable_if {}; // no member "type" when !_Test

    template <class _Ty>
    struct enable_if<true, _Ty> { // type is _Ty for _Test
        using type = _Ty;
    };

    template <bool _Test, class _Ty = void>
    using enable_if_t = typename enable_if<_Test, _Ty>::type;


};

/*  The enable_if type can be a return type or the type of
    any part of the function signature
*/


namespace example1 {
    template <class T, size_t N>
    std::enable_if_t<not std::is_trivially_copyable_v<T>, void>
        copy_array(T const (&source)[N], T(&dest)[N])
    {
        std::copy(source, std::end(source), dest);
    }


    template <class T, size_t N>
    std::enable_if_t<std::is_trivially_copyable_v<T>, void>
        copy_array(T const (&source)[N], T(&dest)[N])
    {
        std::memcpy(source, std::end(source), dest);
    }
}


namespace example2 {
    template <class T, size_t N>
    void copy_array(T const (&source)[N], T(&dest)[N], std::enable_if_t<not std::is_trivially_copyable_v<T>, int> = 0)
    {
        std::copy(source, std::end(source), dest);
    }


    template <class T, size_t N>
    std::enable_if_t<std::is_trivially_copyable_v<T>, void>
        copy_array(T const (&source)[N], T(&dest)[N], std::enable_if_t<not std::is_trivially_copyable_v<T>, int> = 0)
    {
        std::memcpy(source, std::end(source), dest);
    }
}

// C++ 17 bring to us if constexpr | this probably has compile throughput advantage

namespace example3 {

    template <class T, size_t N>
    void copy_array(T const (&source)[N], T(&dest)[N])
    {
        if constexpr (std::is_trivially_copyable_v<T>) {
            std::memcpy(source, std::end(source), dest);
        }
        else
        {
            std::copy(source, std::end(source), dest);
        }
    }
}