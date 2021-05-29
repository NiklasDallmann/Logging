#ifndef ND_LOGGING_LOGGING_HPP
#define ND_LOGGING_LOGGING_HPP

#include <cstddef>
#include <string>
#include <string_view>

#include <fmt/color.h>
#include <fmt/format.h>
#include <fmt/ostream.h>

namespace nd::logging
{

namespace impl
{

constexpr std::size_t prefixWidth = 9u;

template <typename C>
std::string makePrefixString(const C color, const std::string_view prefix)
{
	return fmt::format(fg(color), "{:<{}}", prefix, impl::prefixWidth);
}

}

template <typename ...Args>
void debug(const std::string_view formatString, Args &&...args)
{
	const std::string string = fmt::format(formatString, args...);

	fmt::print("{:<{}}{}\n", "debug:", impl::prefixWidth, string);
}

template <typename ...Args>
void info(const std::string_view formatString, Args &&...args)
{
	const std::string string = fmt::format(formatString, args...);

	fmt::print("{}{}\n", impl::makePrefixString(fmt::terminal_color::cyan, "info:"), string);
}

template <typename ...Args>
void warn(const std::string_view formatString, Args &&...args)
{
	const std::string string = fmt::format(formatString, args...);

	fmt::print("{}{}\n", impl::makePrefixString(fmt::terminal_color::yellow, "warning:"), string);
}

template <typename ...Args>
void error(const std::string_view formatString, Args &&...args)
{
	const std::string string = fmt::format(formatString, args...);

	fmt::print("{}{}\n", impl::makePrefixString(fmt::terminal_color::red, "error:"), string);
}

}

#endif // ND_LOGGING_LOGGING_HPP
