import <type_traits>;


constexpr char kConfig[] = R"(
	components_manager:
		coro_pool:	
# /// [ Sample logging configurator]
	logging-configurator:
		limited-logging-enable: true
		limited-logging-interval: 1s
# /// [ Sample logging configurator]

)";



/**
 * ##Available Options:
 * Name | Descriptin | Default value
 * -----|------------|--------------
 * limmited-logging-enable | set to true
 * @tparam T
 * @tparam U
 * @param a set to true
 * ## Config example:
 * 
 * @snippet Index_sequence.cpp Sample logging configurator
 */
template<class T, size_t N, typename U>
constexpr bool Compare(const T (&a)[N], const U& b)
{
	return [&]<size_t...I>(std::index_sequence<I...>){
		return ((a[I] == b) && ...);
	}(std::make_index_sequence<N>());
}

template<class T, size_t N>
constexpr bool Compare(const T (&a)[N], const T (&b)[N])
{
	return [&]<size_t...I>(std::index_sequence<I...>) { return ((a[I]==b) && ...);}
		(std::make_index_sequence<N>());
}



