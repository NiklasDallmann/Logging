#include <logging.hpp>

int main(int, char **)
{
	nd::logging::debug("Hello World");
	nd::logging::info("Hello World");
	nd::logging::warn("Hello World");
	nd::logging::error("Hello World");

	return 0;
}
