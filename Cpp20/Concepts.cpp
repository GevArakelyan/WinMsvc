import <type_traits>;

namespace concept_examples01 {
    template<typename T, typename... Ts>
    constexpr bool are_same_v = std::conjunction_v<std::is_same<T, Ts>...>;


    template<typename T, typename...>
    struct first_arg {
        using type = T;
    };


    template<typename... Args>
    using first_arg_t = typename first_arg<Args...>::type;

    template<typename... Args>
    std::enable_if_t<are_same_v<Args...>, first_arg_t<Args...>>
        Add(Args&&... args) noexcept
    {
        return (... + args);
    }

    //------- C++ 20---------------------------------
    template<typename... Args>
    requires are_same_v<Args...>
        auto Add(Args&&... args) noexcept
    {
        return (... + args);
    }
    //--------let's go farther------------------------------------------------
    template<class A, class B>
    concept same_as = std::is_same_v<A, B>;

    template<class... Args>
    concept addable = requires(Args... args)
    {
        (... + args);
        requires are_same_v<Args...>;
        requires sizeof...(Args) > 1;
        { (... + args) } noexcept -> same_as<first_arg_t<Args...>>;
    };

     template<typename... Args>
    requires addable<Args...>
        auto Add(Args&&... args) noexcept
    {
        return (... + args);
    }



    int main() {

        return 0;

    }


}