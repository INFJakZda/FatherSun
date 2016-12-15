//#include <fmt/format.h>

#include <spdlog/spdlog.h>

int main() {

	fmt::print("hello world\n");
	fmt::print("Mam {} lat\n", 42);

	auto logger = spdlog::stdout_logger_mt("FatherSun", true);

	logger->set_level(spdlog::level::debug);
	logger->info("Dzis Tech Day");
	logger->debug("Mówimy o C++");
	logger->error("Mielismy opoznienie");

	return 0;
}